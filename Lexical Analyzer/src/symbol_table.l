%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int var=0,i,nc=0,cLine=0,flag=0;
int lineNumber=1;

FILE *ptr1,*ptr2;

char *comment,*inputFile;

void insertToTable(char *yytext,char type);
void displayComment(char *yytext);

struct Node {
	char *tname;
	int av;
	struct Node *next;
}*head=NULL;
%}

digit  [0-9]
letter  [a-zA-Z]
keyword	"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"printf"|"register"|"return"|"scanf"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"
datatype "int"|"char"
sign "signed"|"unsigned"
modifiers "long"|"short"
relational >|<|<=|>=|!=|==
logical \&|\^|\~
arithmatic \+|\-|\*|\/|\%
puncuator \(|\)|\[|\]|;|,|\{|\}|\:|\.
assignment =
quote \'|\"|\\
whitespace [ \t]+
newline "\n"
singlelinecomment (\/\/.*)
multilinecommentstart (\/\*)
multilinecommentend (\*\/)
identifier ({letter}({letter}|{digit})*)|"_"({letter}|{digit})+ 

%x DETECT_COMMENT

%%
^#([-a-zA-Z0-9.]|{relational}|{whitespace})* insertToTable(yytext,'d');

{keyword} insertToTable(yytext,'k');
{sign}?{whitespace}{modifiers}?{whitespace}{datatype} insertToTable(yytext,'k');

{identifier}\[{digit}*\] insertToTable(yytext,'a');
\*{identifier} insertToTable(yytext,'q');
{identifier} insertToTable(yytext,'i');
{digit}+({letter}|{digit})+|"_" { printf("%s : %d : Invalid Identifier\n",inputFile,lineNumber); }

{relational} insertToTable(yytext,'r');
{logical} insertToTable(yytext,'l');
{arithmatic} insertToTable(yytext,'o');
{assignment} insertToTable(yytext,'e');
{puncuator} insertToTable(yytext,'p');

{digit}+ insertToTable(yytext,'c');

\"(.)*\" insertToTable(yytext,'s');
\"(.)*   {printf("%s : %d : String Does Not End\n",inputFile,lineNumber);}
{quote} ;
{whitespace} ;
{newline} lineNumber++;

{singlelinecomment} 

{multilinecommentstart}  {  
                BEGIN(DETECT_COMMENT);
                nc++;
                cLine++;
                displayComment("\n\t");
            }

<DETECT_COMMENT>{multilinecommentstart} { 
                            nc++;
                            if(nc>1)
                            {
				printf("%s : %d : Nested Comment\n",inputFile,lineNumber);
                                flag = 1;
                            }
                         }

<DETECT_COMMENT>{multilinecommentend} {
                            if(nc>0)
                                nc--;
                            else
			    printf("%s : %d : */ found before /*\n",inputFile,lineNumber);
                            
                            if(nc==0)
                            BEGIN(INITIAL);
                    }

<DETECT_COMMENT>\n   {  
                 cLine++;
                 lineNumber++;
                 displayComment("\n");
                }

<DETECT_COMMENT>. {displayComment(yytext);}


%%

int main(int argc,char **argv)
{
	comment = (char*)malloc(100*sizeof(char));
	yyin=fopen(argv[1],"r");
	inputFile=argv[1];

	ptr1=fopen("symbol.txt","w");
	fprintf(ptr1,"\n Symbol Table:\n \t\tLexeme\t\t\tToken\t\t\t\t\tAttribute Value\t\t\tLine Number\n");

	ptr2=fopen("constants.txt","w");
	fprintf(ptr2,"\n Constats Table:\n \t\tLexeme\t\t\tToken\t\t\t\t\tAttribute Value\t\t\tLine Number\n");

	yyout=fopen("table.txt","w");
	fprintf(yyout,"\n Table:\n \t\tLexeme\t\t\tToken\t\t\t\t\tAttribute Value\t\t\tLine Number\n");

	yylex();
	
    	if(nc!=0)
    		printf("%s : %d : Comment Does Not End\n",inputFile,lineNumber);
    
    
    	fprintf(yyout,"\n");
    	if(flag==1)
    	{
		cLine = 0;
		fprintf(yyout,"\n\nComment (%d lines):\n",cLine);
		printf("%s : %d : Nested Comment\n",inputFile,lineNumber);
    	}
    	else
    	{
		fprintf(yyout,"\n\nComment (%d lines):",cLine);
		fputs(comment,yyout);
   	}
    
	fclose(yyout);	
}

void displayComment(char *yytext)
{
    int l1, l2;
    char *temp;

    l1 = strlen(comment);
    l2 = strlen(yytext);
    temp = (char*)malloc((l1+1)*sizeof(char));
    strcpy(temp,comment);
    comment = (char*)malloc((l1+l2+1)*sizeof(char));
    strcat(temp,yytext);
    strcpy(comment,temp);
}
void insertToTable(char *yytext,char type)
{
    int l1 = strlen(yytext), i;
    char token[30];
    struct Node *current = NULL, *temp = NULL;

    switch(type)
    {
	case 'd': strcpy(token,"Preprocessor Statement");break;

        case 'k':strcpy(token,"Keyword");break;
                       
        case 'a':strcpy(token,"Array");break;

	case 'q' :strcpy(token,"Pointer");break;
        
        case 'i':strcpy(token,"Identifier");break;
	 	
	case 'r':strcpy(token,"Relational Op");break;

        case 'p':strcpy(token,"Punctuator");break;
       	
       	case 'o':strcpy(token,"Arithmetic Op");break;   
        
        case 'c':strcpy(token,"Constant");break;                                
      	
      	case 'e':strcpy(token,"Assignment Op");break;
      	
      	case 'l':strcpy(token,"Logical Op");break;	
    	
    	case 's':strcpy(token,"String Literal");break;
    }

    if(nc<=0)
    {
	    current = head;
	    for(i=0;i<var;i++)
	    {    	
	    	if(strcmp(current->tname,yytext)==0)
	    		{
	    			break;
	    		}
	    		current = current->next;
	    }

	    if(i==var)
	    {    	
	    	temp = (struct Node *)malloc(sizeof(struct Node));
	    	temp->av = i;
	    	temp->tname = (char *)malloc(sizeof(char)*(l1+1));
	    	strcpy(temp->tname,yytext);
	    	temp->next = NULL;

	    	if(head==NULL)
	    	{    		
	    		head = temp;
	    	}
	    	else
	    	{
	    		current = head;
	    		while(current->next!=NULL)
	    		{
	    			current = current->next;
	    		}    
		    	current->next = temp;
		}
		   	
    		var++;	
	    }
    }

	if(type =='i' || type == 'a' || type == 'q'){
		fprintf(ptr1,"\n%20s%30s%30d%35d",yytext,token,i,lineNumber);
	}
	if(type =='c'){
		fprintf(ptr2,"\n%20s%30s%30d%35d",yytext,token,i,lineNumber);
		
	}
   fprintf(yyout,"\n%20s%30s%30d%35d",yytext,token,i,lineNumber);
}
                                                                                                    
int yywrap()
{
 return(1);
}


 




