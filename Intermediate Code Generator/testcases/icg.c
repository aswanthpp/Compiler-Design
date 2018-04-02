#include "icg.h"
#include "y.tab.h"

tokenList  *symPtr = NULL;
tokenList  *bufferPtr = NULL;

threeAddressCode   *codePtr = NULL;

extern int yylineno;
extern int yyin;
 
int globalOffset = 0, tempIntCounter = 0,tempFloatCounter= 0,currentLine = -1;

void yyerror() {
    printf("ERROR: %d : Syntactical Error\n",yylineno);
    exit(1);
}

int main(int argc, char **argv) {
    yyin = fopen(argv[1],"r");
    yyparse();
    /*tokenList *p1=symPtr,*p2=symPtr;
    if(p1!=NULL && p2!=NULL){
    while(p1!=NULL){
    	while(p2!=NULL){
    		if(strcmp(p1->name,p2->name)==0 && p1->type==p2->type && strcmp(p1->scope,p2->scope)==0){
    			printf("ERROR: %d : Multiple Declarations of %s in %s scope\n",p1->name,p1->scope);
    			exit(1);
    		}
    		p2=p2->next;
    	}
    	p1=p1->next;
    }
    }*/	
    printf("\n\n\t Parsing Completed\n");
    printf("Three Address Code and Symbol table are generated\n\n");
    FILE *icgPtr= fopen("threeAddressCode.txt","w");
    writeCode(icgPtr);
    FILE *symPtr = fopen("symbolTable.txt", "w");
    writeSymbolTable(symPtr);
    fclose(icgPtr);
    fclose(symPtr);
    printf("\n");
    return(0);
}

static const char* returnTypeToString(tokenReturnType type)
{
    switch(type)
    {
        case Return_VOID:
            return "None";

        case Return_INT:
            return "Int";

        case Return_FLOAT:
            return "Real";
    }
}


static const char* dataTypeToString(tokenType type)
{
    switch(type)
    {
        
        case INT_type:
            return "Int";

        case FLOAT_type:
            return "Real";
       
         case BOOL_type:
          return "Bool";
          
        case FUNC:
            return "Func";
        case PROTO:
            return "Proto";

        case MAIN:
            return "Main";
    }
}

threeAddressCode* appendCode(char *code){

	threeAddressCode *temp = malloc(sizeof(threeAddressCode ));
	
	temp->code=(char *)malloc(sizeof(char)*strlen(code));
	strcpy(temp->code,code);
	temp->gotoLine = -1;
	temp->next = NULL;
	
	
	if(codePtr == NULL){
		codePtr=temp;	
	}
	else{
		threeAddressCode *p=codePtr;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=temp;	
	}
	currentLine++;
	return temp;
}

void backpatch(backPatchList* list, int gotoL){
	if(list == NULL){
		return;
	} else{
		backPatchList* temp;
		while(list){
			if(list->entry != NULL){
				list->entry->gotoLine = gotoL;
			}
			//printf("backpatching: %s",list->entry->code);
			temp = list;
			list = list->next;
			free(temp);
		}
	}
}

backPatchList* mergelists(backPatchList* a, backPatchList* b){
	if(a != NULL && b == NULL){
		return a;
	}
	else if(a == NULL && b != NULL){
		return b;
	}
	else if(a == NULL && b == NULL){
		return NULL;
	}
	else{
		backPatchList* temp = a;
		while(a->next){
			a = a->next;
		}
		a->next = b;
		return temp;
	}
}

backPatchList* appendToBackPatch(backPatchList* p, threeAddressCode* newCode){
	
	if(newCode == NULL){
		return p;
	}
	else if(p == NULL){
		backPatchList* temp = malloc(sizeof(backPatchList));
		temp->entry = newCode;
		temp->next = NULL;
		return temp;
	}
	else{
		backPatchList* temp = malloc(sizeof(backPatchList));
		temp->entry = newCode;
		temp->next=NULL;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next = temp;
		return temp;
	}
}

tokenList* appendToSymbolTable(char *name,tokenType type,tokenReturnType returnType,long size,long line,char *scope,long parameter)
{

    tokenList  *temp = malloc(sizeof(tokenList ));
    
    temp->name         = strdup(name);
    temp->type         = type;
    temp->returnType   = returnType;
    temp->size         = size;
    temp->line         = line;
    temp->scope        = (scope == PARENT_NONE ? NULL : strdup(scope));
    temp->parameter    = parameter;
    temp->next         = NULL;

    if(symPtr==NULL){
    	symPtr=temp;
    }
    else{
    	tokenList  *p = symPtr;
    	while(p->next!=NULL)
    		p=p->next;	
    	p->next=temp;
    }
    return temp;
}


void writeCode(FILE *icgOut)
{
    long icgLineCount  = 0;
    fprintf(icgOut, "\n\t\t\t  Intermediate Code Generated");
    fprintf(icgOut, "\n\t\t\t-------------------------------\n");
    
    if(codePtr==NULL){
    	printf("\nNo code Generated\n");
    }
    else{
        threeAddressCode *p = codePtr;
    	while(p)
    	{
    		if(p->gotoLine == -1){
    			fprintf(icgOut,"%-4lu %s\n",icgLineCount,p->code);
    		}
    		else{
    			fprintf(icgOut,"%-4lu %s %d\n",icgLineCount,p->code,p->gotoLine);
    		}
        	p = p->next;
        	icgLineCount++;
    	}
    }
}



void writeSymbolTable(FILE *symOut)
{
    fprintf(symOut, "\n\t\t\t   Symbol Table");
    fprintf(symOut, "\n\t\t\t------------------\n\n");
    
    if(symPtr == NULL)
    {
        printf("\nSymbol table is empty");
    }
    else{
    	fprintf(symOut,"   Name            DataType      ReturnType      Offset          Scope");  
        fprintf(symOut,"\n------------------------------------------------------------------------\n");
        
        tokenList  *p= symPtr;
        while(p!=NULL)
    	{
        	fprintf(symOut,"%-20s %-14s %-14s %-12lu %-12s\n",
                      
                      p->name,
                      dataTypeToString(p->type),
                      returnTypeToString(p->returnType),
                      p->size,
                      p->scope == NULL ? "None" : p->scope  
                      );
        	      p=p->next;
    	}    
    }
}
void addSymbolToQueue(char *name, tokenType type, unsigned long param_no) {
    tokenList  *temp = malloc(sizeof(tokenList ));
    temp->name         = strdup(name);
    temp->type         = type;
    switch(type){
		case INT_type: temp->size = 4;break;
		case FLOAT_type: temp->size = 8;break;
		case BOOL_type: temp->size = 1;break;
		default: temp->size = 4;
    }
    temp->parameter = param_no;
    temp->next=NULL;
    
    if (bufferPtr == NULL) {
        bufferPtr = temp;
    } else {
        tokenList  *p = bufferPtr;
        while (p->next!=NULL) 
            p=p->next;
        p->next=temp;    
    }
}
void clearQueue() {
    tokenList *temp;
    while(bufferPtr != NULL) {
        temp = bufferPtr;
        bufferPtr = bufferPtr->next;
        free(temp);
    }
}
void addFunctionPrototype(char *name, unsigned int paramCount, tokenReturnType   ret_type){
	
	if(strcmp(name, "main") == 0){
		printf("ERROR: %d : main func cannot declare as prototype\n",yylineno);
		exit(1);
	}
	tokenList  *temp = symPtr;
	while(temp!=NULL){
		if((strcmp(name,temp->name)==0)&&(temp->type==PROTO||temp->type==FUNC)){
			printf("ERROR: %d : Multiple function declaration of %s\n",yylineno,name);
	                exit(1);
		}
		temp=temp->next;
	}
	appendToSymbolTable(name,PROTO,ret_type,0,0,NULL,paramCount);
	
	if(paramCount!=0 && bufferPtr==NULL){
		printf("ERROR: %d : Parameter mismatch of function %s\n",yylineno,name);
	        exit(1);
	}
	else{
		int cnt=1;
		if(bufferPtr!=NULL){
			tokenList *p=bufferPtr;
			while(p!=NULL){
				p->scope=name;
				p->parameter=cnt++;
				appendToSymbolTable(p->name,p->type,p->returnType,p->size,p->line,p->scope,p->parameter);
				p=p->next;
			
			}
			clearQueue();
		}
		
	}
}
tokenList * addSymbolToParameterQueue(tokenList * queue, char *name, tokenType type) {
    tokenList  *symbol = malloc(sizeof(tokenList ));
    symbol->name         = strdup(name);
    symbol->type         = type;
    symbol->next = false;
    if (queue == NULL) {
        return symbol;
    } else {
        tokenList  *entry = queue;
        while (entry->next) {
            entry = entry->next;
        }
        entry->next = symbol;
        return queue;
    }
}
void addFunction(char *name,unsigned int paramCount,tokenReturnType ret_type,int line) {
    tokenList  *symTable = symPtr,*prototype = NULL;
    unsigned int localOffset = 0;
    if(symTable != NULL){
		while(symTable){
			if( symTable->type == PROTO && 0 == strcasecmp(name,symTable->name)){
				prototype = symTable;
				break;
			}
			symTable = symTable->next;
		}
    }
    if(strcmp(name, "main") == 0){
    	if(paramCount != 0){
    		printf("ERROR: %d : main function should not have parameters\n",yylineno);
    		exit(1);
    	}
    	else if(ret_type != Return_INT){
    		printf("ERROR: %d : main function should return integer\n",yylineno);
    		exit(1);
    	}
    	else{
    		
    		tokenList  *symbol = bufferPtr;
                int s = 0;
    		while(symbol){
    			int size = symbol->size;
    			symbol->size = localOffset;
    			localOffset+=size;
    			globalOffset+=size;
                        s+=size;
                        
    			symbol->scope = name;
    			symbol->parameter = 0;
    			appendToSymbolTable(symbol->name,symbol->type,symbol->returnType,symbol->size,symbol->line,symbol->scope,symbol->parameter);
    			symbol=symbol->next;
    		}
        	tokenList  *newEntry= appendToSymbolTable(name,MAIN,ret_type,s,line,NULL,0);
        	clearQueue();
    		
    	}
    	
    }
    else if(!prototype){
    	
    	if(bufferPtr == NULL && paramCount != 0){
    		printf("ERROR: %d : Parameter mismatch of function %s\n",yylineno,name);
	        exit(1);
    	}
    	else{
    		int cnt = 1;
                int s = 0;
    		tokenList  *symbol = bufferPtr;
    		while(symbol!=NULL){
    			int size = symbol->size;
    			symbol->size = localOffset;
    			localOffset+=size;
    			globalOffset+=size;
    			s += size;
    			
    			symbol->scope = name;
    			if(paramCount != 0){
    				symbol->parameter=cnt++;
    			}
    			else{
    				symbol->parameter=0;
    			}
    			appendToSymbolTable(symbol->name,symbol->type,symbol->returnType,symbol->size,symbol->line,symbol->scope,symbol->parameter);
    			symbol = symbol->next;
    		}
    	    tokenList  *newEntry = appendToSymbolTable(name,FUNC,ret_type,s,line,NULL,paramCount);
    	    clearQueue();
    	}
    }
    else{
    	prototype->type = FUNC;
	prototype->line = line;
    	if(bufferPtr == NULL && paramCount != 0){
    		printf("ERROR: %d : Parameter mismatch of function %s\n",yylineno,name);
	        exit(1);
    	}
    	else{
    		if(prototype->parameter != paramCount){
    			printf("ERROR: %d : Parameters are not matching with prototype %s\n",yylineno,name);
	        	exit(1);
    		}
		int s = 0;
    		tokenList  *symbol = symPtr;
    		for(int i = 0;i<paramCount;i++){
    			while(symbol->scope == NULL){
    				symbol=symbol->next;
    				if(strcmp(symbol->scope,name)==0&&symbol->scope != NULL){
    					break;
    				}
    			}
    			if(symbol->type != bufferPtr->type){
        			printf("ERROR: %d : Parameter type mismatch in function %s\n",yylineno,name);
	        		exit(1);
    			}
    			int size = symbol->size;
    			symbol->size = localOffset;
    			localOffset+=size;
    			globalOffset+=size;
    			s+=size;
    			
    			tokenList  *temp = bufferPtr;
    			bufferPtr = bufferPtr->next;
    			free(temp);
    			
			symbol=symbol->next;
    		}
    		tokenList  *queuSymbol = bufferPtr;
    		while(queuSymbol!=NULL){
    			int size = queuSymbol->size;
    			queuSymbol->size = localOffset;
    			localOffset+=size;
    			globalOffset+=size;
                        s+=size;
    			
    			queuSymbol->scope = name;
    			queuSymbol->parameter = 0;
    			appendToSymbolTable(queuSymbol->name,queuSymbol->type,queuSymbol->returnType,queuSymbol->size,queuSymbol->line,
    					queuSymbol->scope,queuSymbol->parameter);
    			queuSymbol = queuSymbol->next;
    		}
                prototype->size = s;
                clearQueue();
    		
    	}
    }

}
char* nextFloatVar(){
    char buffer[10];
    sprintf(buffer,"Tf_%d",++tempFloatCounter);
    addSymbolToQueue(buffer, FLOAT_type, 0);
    return strdup(buffer);
}

char* nextIntVar(){
    char buffer[10];
    sprintf(buffer,"Ti_%d",++tempIntCounter);
    addSymbolToQueue(buffer, INT_type, 0);
    return strdup(buffer);
}
int nextquad(){
	return currentLine + 1;
}
tokenList * getSymbol(char *token){
    tokenList *p = symPtr;
    while(p!=NULL){
	if(p->name!=NULL && strcmp(token, p->name)==0){
	    return p;
	}
	p=p->next;
    }
}
int getSymbolType(char *token) {
    tokenList  *p=bufferPtr;
    while(p!=NULL) {
        if(strcmp(token, p->name)==0)
		return(p->type);
        
    	p=p->next;
    }
    return 0;
}
int getFunctionType(char *token){
	tokenList  *p=symPtr;
	while(p!=NULL){
		if(strcmp(token,p->name)==0 && (p->type==FUNC||p->type==PROTO)){
			return p->returnType;
		}
	}

	return 0;
}
int checkAndGenerateParams(tokenList * queue, char* name ,int parameterCount){
	char buffer[50];
	tokenList  *cur = symPtr;
	while(cur != NULL){
		if((cur->type == FUNC || cur->type == PROTO) && 0 == strcmp(name,cur->name)){
			break;
		}
	}
	if(cur == NULL)
		return -1;
	int foundParams = 0;
	cur = symPtr;
	do{
		while(cur != NULL){
			if(cur->scope != NULL && 0 == strcmp(name,cur->scope) && cur->parameter != 0){
				break;
			}
			cur = cur->next;
		}
		if(cur == NULL || queue == NULL){
			if(parameterCount == 0 && foundParams == 0)
				return 0;
			else
				return -2;
		}
		else if(cur->type != queue->type){
			return -3;
		}
		foundParams++;
		sprintf(buffer,"PARAM %s",queue->name);
		appendCode(buffer);
		cur = cur->next;
		tokenList  *temp = queue;
		queue = queue->next;
		free(temp);
	}while(foundParams != parameterCount);
	return 0;
}


