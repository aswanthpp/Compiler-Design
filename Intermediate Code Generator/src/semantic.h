struct tokenList
{
	char *token,type[20],line[100];
	char *scope[20];
	int scopeValue;
	int funcCount;
	struct tokenList *next;
};
typedef struct tokenList tokenList;
struct funcNode{
	char funcName[30];
	int line;
	char funcReturn[20];
	struct  funcNode *next;
};
typedef struct funcNode funcNode;


tokenList *symbolPtr = NULL;
tokenList *constantPtr = NULL;
tokenList *parsedPtr =NULL;
extern int functionCount;
extern int scopeCount;
char typeBuffer=' ';
char *sourceCode;
int tempCheckType=3;

int semanticErr=0,lineSemanticCount;
int checkScope(char *tempToken,int lineCount)
{	tokenList *temp=NULL;
	char type[20];
	int flag=0,tempFlag=0;
	for(tokenList *p=symbolPtr;p!=NULL;p=p->next){
		if(strcmp(tempToken,"printf")==0 ||  strcmp(tempToken,"scanf")==0){
		 	tempFlag=1;		
		 }
		else{		
			if(strcmp(tempToken,p->token)==0){
				strcpy(type,p->type);
				flag=1;
				break;
			}
		}
		
	}
	if (flag == 0 && tempFlag ==0 )
	{
		printf("\n%s : %d :Undeclared variable  \n",sourceCode,lineCount-1);		
		semanticErr=1;
	}
	else
	{
		addSymbol(tempToken,lineCount);
		if(strcmp(type,"VOID")==0)
            		return(1);
        	if(strcmp(type,"CHAR")==0)
	    		return(2);
       		if(strcmp(type,"INT")==0)
            		return(3);
        	if(strcmp(type,"FLOAT")==0)
            		return(4);
        }
        
}

void checkType(int value1,int value2,int lineCount)
{	lineSemanticCount=lineCount;
	if(value2 == 0)
		value2 = tempCheckType;
	if(value1!=value2)
	{
		printf("\n%s : %d :Type Mismatch error \n",sourceCode,lineSemanticCount-1);		
		semanticErr=1;
	}
	tempCheckType=3;
}
void checkDeclaration(char *tokenName,int tokenLine,int scopeVal){
	char type[20];
	char line[39],lineBuffer[19];
  	snprintf(lineBuffer, 19, "%d", tokenLine);
	strcpy(line," ");
	strcat(line,lineBuffer);
	switch(typeBuffer){
		case 'i': strcpy(type,"INT"); break;
		case 'f': strcpy(type,"FLOAT");break;
		case 'v': strcpy(type,"VOID");break;
		case 'c': strcpy(type,"CHAR");break;
		
	}	
	for(tokenList *p=symbolPtr;p!=NULL;p=p->next){
		if(strcmp(p->token,tokenName)==0 && p->scopeValue == scopeCount && p->funcCount == functionCount){
			semanticErr=1;
			if(strcmp(p->type,type)==0){
				printf("\n%s : %d :Multiple Declaration \n",sourceCode,tokenLine);		
       				return;				
			}
			else{
				printf("\n%s : %d :Multiple Declration with Different Type \n",sourceCode,tokenLine);		
				return;			
			}				
		}	
	}
	addSymbol(tokenName,tokenLine,scopeCount);

}
void checkArray(int val,int lineCount){
	if(val<0){
		semanticErr=1;
		printf("\n%s : %d :Array Index error\n",sourceCode,lineCount-1);		
	}
}
void addSymbol(char *tokenName,int tokenLine,int scopeVal){
	char line[39],lineBuffer[19];
  	snprintf(lineBuffer, 19, "%d", tokenLine);
	strcpy(line," ");
	strcat(line,lineBuffer);
	char type[20];
	for(tokenList *p=symbolPtr;p!=NULL;p=p->next)
  	 		if(strcmp(p->token,tokenName)==0 && p->scopeValue == scopeCount && p->funcCount ==functionCount ){
       				strcat(p->line,line);
       				return;
     			}
	tokenList *temp=(tokenList *)malloc(sizeof(tokenList));
	temp->token=(char *)malloc(strlen(tokenName)+1);
	strcpy(temp->token,tokenName);
	switch(typeBuffer){
		case 'i': strcpy(temp->type,"INT"); break;
		case 'f': strcpy(temp->type,"FLOAT");break;
		case 'v': strcpy(temp->type,"VOID");break;
		case 'c': strcpy(temp->type,"CHAR");break;		
	}
	temp->funcCount=functionCount;
	if(scopeCount==0){
		strcpy(temp->scope,"GLOBAL");	
		temp->scopeValue=scopeCount;
		
	}
	else{
		strcpy(temp->scope,"NESTING");
		temp->scopeValue=scopeCount;
	}	
    	strcpy(temp->line,line);
    	temp->next=NULL;
    	tokenList *p=symbolPtr;
    	if(p==NULL){	
    		symbolPtr=temp;
    	}
    	else{
    		while(p->next!=NULL){
    			p=p->next;
    		}
		p->next=temp;
    	}
	

}
void addConstant(char *tokenName,int tokenLine){
	char line[39],lineBuffer[19];	
  	snprintf(lineBuffer, 19, "%d", tokenLine);
	strcpy(line," ");
	strcat(line,lineBuffer);
	for(tokenList *p=constantPtr;p!=NULL;p=p->next)
  	 		if(strcmp(p->token,tokenName)==0){
       				strcat(p->line,line);
       				return;
     			}
		tokenList *temp=(tokenList *)malloc(sizeof(tokenList));
		temp->token=(char *)malloc(strlen(tokenName)+1);
		strcpy(temp->token,tokenName);
    		strcpy(temp->line,line);
    		temp->next=NULL;
    		
    		tokenList *p=constantPtr;
    		if(p==NULL){
    			constantPtr=temp;
    		}
    		else{
    			while(p->next!=NULL){
    				p=p->next;
    			}
    			p->next=temp;
    		}	
    		
	
}
void makeList(char *tokenName,char tokenType, int tokenLine)
{
	char line[39],lineBuffer[19];
	
  	snprintf(lineBuffer, 19, "%d", tokenLine);
	strcpy(line," ");
	strcat(line,lineBuffer);
	char type[20];
	switch(tokenType)
	{
			case 'c':
					strcpy(type,"Constant");
					break;
			case 'v':
					strcpy(type,"Identifier");
					break;
			case 'p':
					strcpy(type,"Punctuator");
					break;
			case 'o':
					strcpy(type,"Operator");
					break;
			case 'k':
					strcpy(type,"Keyword");
					break;
			case 's':
					strcpy(type,"String Literal");
					break;
			case 'd':
					strcpy(type,"Preprocessor Statement");
					break;
	}
	
	
	for(tokenList *p=parsedPtr;p!=NULL;p=p->next)
  	 		if(strcmp(p->token,tokenName)==0){
       				strcat(p->line,line);
       				return;
     			}
		tokenList *temp=(tokenList *)malloc(sizeof(tokenList));
		temp->token=(char *)malloc(strlen(tokenName)+1);
		strcpy(temp->token,tokenName);
		strcpy(temp->type,type);
    		strcpy(temp->line,line);
    		temp->next=NULL;
    		
    		tokenList *p=parsedPtr;
    		if(p==NULL){
    			parsedPtr=temp;
    		}
    		else{
    			while(p->next!=NULL){
    				p=p->next;
    			}
    			p->next=temp;
    		}	
    		
	/*if(tokenType == 'c')
	{
    		
    		for(tokenList *p=constantPtr;p!=NULL;p=p->next)
  	 		if(strcmp(p->token,tokenName)==0){
       				strcat(p->line,line);
       				return;
     			}
		tokenList *temp=(tokenList *)malloc(sizeof(tokenList));
		temp->token=(char *)malloc(strlen(tokenName)+1);
		strcpy(temp->token,tokenName);
		strcpy(temp->type,type);
    		strcpy(temp->line,line);
    		temp->next=NULL;
    		
    		tokenList *p=constantPtr;
    		if(p==NULL){
    			constantPtr=temp;
    		}
    		else{
    			while(p->next!=NULL){
    				p=p->next;
    			}
    			p->next=temp;
    		}	
    		

	}
	if(tokenType=='v')
	{
    		for(tokenList *p=symbolPtr;p!=NULL;p=p->next)
  	 		if(strcmp(p->token,tokenName)==0){
       				strcat(p->line,line);
       				return;
     			}
		tokenList *temp=(tokenList *)malloc(sizeof(tokenList));
		temp->token=(char *)malloc(strlen(tokenName)+1);
		strcpy(temp->token,tokenName);
		switch(typeBuffer){
		case 'i': strcpy(temp->type,"INT"); break;
		case 'f': strcpy(temp->type,"FLOAT");break;
		case 'v' :strcpy(temp->type,"VOID");break;
		case 'c': strcpy(temp->type,"CHAR");break;
		
		}
		
    		strcpy(temp->line,line);
    		temp->next=NULL;
    		tokenList *p=symbolPtr;
    		if(p==NULL){
    			
    			symbolPtr=temp;
    		}
    		else{
    			while(p->next!=NULL){
    				p=p->next;
    			}
    			p->next=temp;
    		}
	}*/
}
