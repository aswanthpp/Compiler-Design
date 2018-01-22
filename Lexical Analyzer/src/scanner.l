%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int var=0,i,nc=0,cLine=0,flag=0;
int lineNumber=1;
int cBrac=0;

FILE *symbol,*constants;
char *comment,*inputFile, s_comment[1000];

void insertToTable(char *yytext,char type);
void displayComment(char *yytext);
void storeSingleLineComment(char *yytext);

struct Node {
	char *tname;
	int av;
	struct Node *next;
}*head=NULL;

%}

digit  [0-9]
letter  [a-zA-Z]
keyword	"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"
datatype "int"|"char"|"void"
sign "signed"|"unsigned"
modifiers "long"|"short"
relational >|<|<=|>=|!=|==
logical \&|\^|\~
arithmatic \+|\-|\*|\/|\%
puncuator \(|\)|\[|\]|\;|\,|\:|\.
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

^#([-a-zA-Z0-9.]|{relational}|{whitespace})* insertToTable(yytext,'d'); //preprocessor directive rule

{keyword} insertToTable(yytext,'k');
{sign}?{whitespace}{modifiers}?{whitespace}{datatype} insertToTable(yytext,'k'); //keyword rule

^{datatype}{whitespace}*{identifier}\(.*\)  {	int i,j=0;char temp1[50]={'\0'}, temp2[50]={'\0'};
												for(i=0;yytext[i]!=' ';i++)
												{
													temp1[i] = yytext[i];
												}
												
												insertToTable(temp1,'k');
												for(;yytext[i]!='(';i++){
													temp2[j]=yytext[i];
													j++;
												}

												insertToTable(temp2,'j');  //procedure rule
											}
											
{identifier}\[{digit}*\] {	int i,j=0;char temp[50]={'\0'};
							
							for(i=0;yytext[i]!='[';i++)
							{
								temp[j] = yytext[i];
								j++;
							}

								insertToTable(temp,'a'); // array rule
						}
						
\*{identifier} {	int i,j=0;char temp[50]={'\0'};
					for(i=1;yytext[i]!='\0';i++)
					{
						temp[j++] = yytext[i];
					}
						insertToTable(temp,'q'); // pointer rule
				}
				
{identifier} insertToTable(yytext,'i'); // variable rule
{digit}+({letter}|{digit})+|"_" { printf("%s : %d : Invalid Identifier\n",inputFile,lineNumber); } // invalid identifier

                                        
{relational} insertToTable(yytext,'r'); //operator rules
{logical} insertToTable(yytext,'l');
{arithmatic} insertToTable(yytext,'o');
{assignment} insertToTable(yytext,'e');
{puncuator} insertToTable(yytext,'p');

{digit}+ insertToTable(yytext,'c'); //integer constants rule 
\"(.)*\" insertToTable(yytext,'s'); //string constants rule
L?\"(\\.|[^\\"])*	{
				if(nc<=0) //invalid String
				printf("%s : %d : String does not End\n",inputFile,lineNumber);	
			}
[-+]?{digit}*\.?{digit}+([eE][-+]?{digit}+)? insertToTable(yytext,'f');  // float constant rule
\'({letter}|{digit})\' {	char temp[50]={'\0'};
							temp[0] = yytext[1];
							insertToTable(temp,'z');  // character constant rule
						}

{quote} ;
{whitespace} ;
{newline} lineNumber++;

"{"  { 	cBrac++;
	insertToTable(yytext,'p');
	 }

"}"  {	cBrac--;
	insertToTable(yytext,'p');
	 }

{singlelinecomment} {storeSingleLineComment(yytext);}

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

	symbol=fopen("symbolTable.txt","w"); //File to write symbol table
	fprintf(symbol,"\n Symbol Table:\n \t\tLexeme\t\t\t\tType\t\t\tAttribute Value\t\t\tLine Number\n");

	constants=fopen("constantTable.txt","w"); // File to write constant table
	fprintf(constants,"\n Constants Table:\n \t\tLexeme\t\t\tType\t\t\tAttribute Value\t\t\tLine Number\n");

	yyout=fopen("parsedTable.txt","w"); // File to write all token in source program
	fprintf(yyout,"\n Table:\n \t\tLexeme\t\t\tToken\t\t\t\tAttribute Value\t\t\tLine Number\n");

	yylex();
	
    	if(nc!=0)
    		printf("%s : %d : Comment Does Not End\n",inputFile,lineNumber);
    		
    	if(cBrac!=0)
    		printf("%s : %d : Unbalanced Parenthesis\n",inputFile,lineNumber);
    
    	fprintf(yyout,"\n");
    	if(flag==1)
    	{
			cLine = 0;
			fprintf(yyout,"\n\nComment (%d lines):\n",cLine);
			printf("%s : %d : Nested Comment\n",inputFile,lineNumber);
    	}
    	else
    	{
	    	int i;
			fprintf(yyout,"\n\nMultiLineComment (%d lines):",cLine);
			fputs(comment,yyout);
			fprintf(yyout,"\n\nSingleLineComment :\n");
			fputs(s_comment,yyout);
	   	}
    
	fclose(yyout);
	fclose(symbol);
	fclose(constants);	
}

void storeSingleLineComment(char *yytext)
{
	int len = strlen(yytext);
	int i, j=0;
	char *temp;
	temp = (char*)malloc((len+1)*sizeof(char));
	for(i=2;yytext[i]!='\0';i++)
	{
		temp[j++] = yytext[i];
	}
	strcat(temp,"\n");
	strcat(s_comment,temp);
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

        case 'k': strcpy(token,"Keyword");break;
         
        case 'j': strcpy(token,"Procedure");break;              
       
        case 'a': strcpy(token,"Array");break;

		case 'q' : strcpy(token,"Pointer");break;
        
        case 'i': strcpy(token,"Identifier");break;
	 	
		case 'r': strcpy(token,"Relational Op");break;

        case 'p': strcpy(token,"Punctuator");break;
       	
       	case 'o': strcpy(token,"Arithmetic Op");break;   
        
        case 'c': strcpy(token,"Integer Constant");break;

        case 'f': strcpy(token,"Float Constant");break;

        case 'z': strcpy(token,"Character Constant");break;                                
      	
      	case 'e': strcpy(token,"Assignment Op");break;
      	
      	case 'l': strcpy(token,"Logical Op");break;	
    	
    	case 's': strcpy(token,"String Literal");break;
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

	if(type =='i' || type == 'a' || type == 'q' || type=='j')
	{	
		fprintf(symbol,"\n%20s%30s%30d%35d",yytext,token,i,lineNumber);
	}
	switch(type)
	{		
		case 'c' : fprintf(constants,"\n%20s%20s%30d%35d",yytext,"int",i,lineNumber);
				    break;

		case 'f' : fprintf(constants,"\n%20s%20s%30d%35d",yytext,"float",i,lineNumber);
				    break;

		case 'z' : fprintf(constants,"\n%20s%20s%30d%35d",yytext,"char",i,lineNumber);
				    break;
	}

   	fprintf(yyout,"\n%20s%30s%30d%35d",yytext,token,i,lineNumber);
}
                                                                                                    
int yywrap()
{
 return(1);
}
