%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int var=0,i,nc=0,cBrac=0,cLine=0,flag=0;
int lineNumber=1;
char *inputFile;
char *comment;
void write_OP(char *yytext, char type);
void disp_comment(char *yytext);
struct token
{
	int av;
	char *tname;
	struct token *next;
};
struct token *head=NULL;
%}

dig  [0-9]
letter  [a-zA-Z]
keyword "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"main"|"printf"|"register"|"return"|"scanf"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"
datatype "int"|"char"
sign "signed"|"unsigned"
modifiers "long"|"short"
relop >|<|<=|>=|!=|==
lop \&|\^|\~
punc \(|\)|\[|\]|;|,|\{|\}|\:|\.
op \+|\-|\*|\/|\%
eq =
ws [ \t]+
quote \'|\"|\\
comm (\/\/.*)
comstart (\/\*)
comend (\*\/)
newline "\n"
ident ({letter}({letter}|{dig})*)|"_"({letter}|{dig})+
structure "struct"

%x DETECT_COMMENT

%%

^#([-a-zA-Z0-9.]|{relop}|{ws})* write_OP(yytext,'d');
{keyword} {
		        if(nc<=0)
			write_OP(yytext,'k');
		}
{sign}?{ws}{modifiers}?{ws}"int"|"float" write_OP(yytext,'k');
{ident}\[{dig}*\] write_OP(yytext,'a');
\*{ident} write_OP(yytext,'q');
{ident} write_OP(yytext,'i');
{dig}+({letter}|{dig})+|"_" printf("%s : %d : Invalid Identifier\n",inputFile,lineNumber);
{relop} write_OP(yytext,'r');
{punc} write_OP(yytext,'p');
{op} write_OP(yytext,'o');
{dig} write_OP(yytext,'c');
{eq} write_OP(yytext,'e');
{lop} write_OP(yytext,'l');
\"(.)*\" write_OP(yytext,'s');
{quote} ;
{ws} ;
{newline} lineNumber++;
{comm} ;

{comstart}  {  
                BEGIN(DETECT_COMMENT);
                nc++;
                cLine++;
                disp_comment("\n\t");
            }

<DETECT_COMMENT>{comstart} { 
                            nc++;
                            if(nc>1)
                            {
				printf("%s : %d : Nested Comment\n",inputFile,lineNumber);
                                flag = 1;
                            }
                         }

<DETECT_COMMENT>{comend} {
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
                 disp_comment("\n");
                }

<DETECT_COMMENT>. {disp_comment(yytext);}


%%

int main(int argc,char **argv)
{
	comment = (char*)malloc(100*sizeof(char));
	yyin=fopen(argv[1],"r");
	inputFile=argv[1];
	yyout=fopen("table.txt","w");
	fprintf(yyout,"\n Symbol Table:\n \t\tLexeme\t\t\tToken\t\t\t\t\tAttribute Value\t\t\tLine Number\n");
	yylex();

    if(nc!=0)
    printf("%s : %d : Comment Does Not End\n",inputFile,lineNumber);
    
    if(cBrac!=0)
    printf("%s : %d : Bracket Mismatch\n",inputFile,lineNumber);
    
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

void disp_comment(char *yytext)
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
void write_OP(char *yytext,char type)
{
    int l1 = strlen(yytext), i;
    char token[30];
    struct token *current = NULL, *temp = NULL;

    switch(type)
    {
	case 'a':
		strcpy(token,"Array");
		break;
 
        case 'w':
		strcpy(token,"Structure");
		break;
    	case 'd':
            strcpy(token,"Preprocessor Statement");
            break;

	case 'q' :	
            strcpy(token,"Pointer");
            break;

      case 'k':
            strcpy(token,"Keyword");
            break;

      case 'i':
	      strcpy(token,"Identifier");
	        break;

      case 'p':
            strcpy(token,"Punctuator");
            break;

      case 'e':
            strcpy(token,"Assignment Op");
            break;

      case 'r':
            strcpy(token,"Relational Op");
            break;

      case 'l':
            strcpy(token,"Logical Op");
            break;

      case 'o':
            strcpy(token,"Arithmetic Op");
            break;                              
			
			case 'c':
            strcpy(token,"Constant");
            break;

    	case 's':
            strcpy(token,"String Literal");
            break;
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
	    		/*if(current==NULL)
	    		break;*/
	    }	
	    if(i==var)
	    {    	
	    	temp = (struct token *)malloc(sizeof(struct token));
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

   fprintf(yyout,"\n%20s%30s%30d%35d",yytext,token,i,lineNumber);
}
                                                                                                    
int yywrap()
{
 return(1);
}

