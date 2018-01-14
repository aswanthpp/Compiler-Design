%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int found=0,var_cnt=0,i,nestedComment=0,cBrac=0,cLine=0,flag=0;
char *comment;
void write_OP(char *yytext, char type);
void disp_comment(char *yytext);

%}

dig  [0-9]
letter  [a-zA-Z]
keyword "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"main"|"printf"|"register"|"return"|"scanf"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"
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
%x DETECT_COMMENT

%%

^#([-a-zA-Z0-9.]|{relop}|{ws})* write_OP(yytext,'d');
{keyword} {
		if(nestedComment<=0)
			write_OP(yytext,'k');
		}
{letter}({letter}|{dig})* write_OP(yytext,'i');
{dig}+({letter}|{dig})+ printf("ERROR : Invalid Identifier");
{relop} write_OP(yytext,'r');
{punc} write_OP(yytext,'p');
{op} write_OP(yytext,'o');
{dig} write_OP(yytext,'c');
{eq} write_OP(yytext,'e');
{lop} write_OP(yytext,'l');
{quote} ;
{ws} ;
{newline} ;
{comm} ;

{comstart}          {  
                        BEGIN(DETECT_COMMENT);
                        nestedComment++;
                        cLine++;
                        disp_comment("\n\t");
                    }

<DETECT_COMMENT>{comstart} { 
                            nestedComment++;
                            if(nestedComment>1)
                            {
                                printf("ERROR: Nested Comment\n");
                                flag = 1;
                            }
                         }

<DETECT_COMMENT>{comend} {
                            if(nestedComment>0)
                                nestedComment--;
                            else
                            printf("ERROR: */ found before /*\n");
                            
                            if(nestedComment==0)
                            BEGIN(INITIAL);
                    }

<DETECT_COMMENT>\n   {  
                 cLine++;
                 disp_comment("\n");
                }

<DETECT_COMMENT>. {disp_comment(yytext);}
%%

int main()
{
	comment = (char*)malloc(100*sizeof(char));
	yyin=fopen("input.c","r");
	yyout=fopen("table.txt","w");
	fprintf(yyout,"\n Symbol Table:\n \t\tLexeme\t\t\t\t\t\t\t\t\tToken\n");
	yylex();

    if(nestedComment!=0)
    printf("ERROR: Comment does not end\n");
    
    if(cBrac!=0)
    printf("ERROR: Bracket mismatch\n");
    
    fprintf(yyout,"\n");
    if(flag==1)
    {
        cLine = 0;
        fprintf(yyout,"\n\nComment (%d lines):\n",cLine);
        fprintf(yyout,"ERROR: Nested Comment");
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
    int l1 = strlen(yytext);
    char token[40];
    switch(type)
    {
	case 'i':
            strcpy(token,"Identifier");
            break;      
	case 'c':
            strcpy(token,"Constant");
            break;
	case 'e':
            strcpy(token,"Assignment Op");
            break;
    case 'p':
            strcpy(token,"Punctuator");
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
    case 'k':
            strcpy(token,"Keyword");
            break;
    case 's':
            strcpy(token,"String Literal");
            break;
	case 'd':
            strcpy(token,"Preprocessor Statement");
            break;
    }

   fprintf(yyout,"\n%20s%30s",yytext,token);
  
}
                                                                                                    
int yywrap()
{
 return(1);
}

