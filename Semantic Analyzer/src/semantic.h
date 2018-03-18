struct tokenList
{
	char *token,type[20],line[100];
	struct tokenList *next;
};
typedef struct tokenList tokenList;

tokenList *symbolPtr = NULL;
tokenList *constantPtr = NULL;
char typeBuffer=' ';
char *sourceCode;
int tchk=3;

int semanticErr=0,lineSemanticCount;
int context_check(char *tempToken,int lineCount)
{	tokenList *temp=NULL;
	int flag=0;
	for(tokenList *p=symbolPtr;p!=NULL;p=p->next){		
		if(strcmp(tempToken,p->token)==0){
			temp=p;
			flag=1;
			break;
		}
	}
	if (flag == 0 )
	{
		printf("\n%s : %d :Undeclared variable %s \n",sourceCode,lineCount,temp->token);		
		semanticErr=1;
	}
	else
	{
		makeList(tempToken,'v',lineCount);
		if(strcmp(temp->type,"VOID")==0)
            		return(1);
        	if(strcmp(temp->type,"CHAR")==0)
	    		return(2);
       		if(strcmp(temp->type,"INT")==0)
            		return(3);
        	if(strcmp(temp->type,"FLOAT")==0)
            		return(4);
        }
        
}

void checkType(int value1,int value2,int lineCount)
{	lineSemanticCount=lineCount;
	if(value2 == 0)
		value2 = tchk;
	if(value1!=value2)
	{
		printf("\n%s : %d :Type Mismatch error \n",sourceCode,lineSemanticCount);		
		semanticErr=1;
	}
	tchk=3;
}
void checkDeclaration(char *tokenName,int tokenLine){
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
		if(strcmp(p->token,tokenName)==0){
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
	makeList(tokenName,'v',tokenLine);

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
	
	if(tokenType == 'c')
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
	}
}
