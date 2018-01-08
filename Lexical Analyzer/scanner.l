%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int found=0,var_cnt=0,i,nestedComment=0,bracCount=0,lineCount=0,flag=0;
void write_OP(char *yytext,char type);
int c;
struct holder
{
	char *name,token[20];
	int val;
	struct holder *next;
}*st,*head;
%}

D  [0-9]
L  [a-zA-Z]
keyword "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"main"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"
ident [a-z]([a-z][A-Z][0-9])*
relop >|<|<=|>=|!=|==
lop \&|\^|\~
punc \(|\)|\[|\]|;|,|\{|\}|\:|\.
op \+|\-|\*|\/|\%
eq =
ws [ \t]+
quote \'|\"|\\
%%
  /* Rules */
^#([-a-zA-Z0-9.]|{relop}|{ws})* write_OP(yytext,'d');
{keyword} write_OP(yytext,'k');
{ident} write_OP(yytext,'i');
{relop} write_OP(yytext,'r');
{punc} write_OP(yytext,'p');
{op} write_OP(yytext,'o');
{D} write_OP(yytext,'c');
{eq} write_OP(yytext,'e');
{lop} write_OP(yytext,'l');
preproc write_OP(yytext,'d');
{L} c++;
{quote} c++;
{ws} c++;
%%

int main(){
	
	yyin=fopen("input.c","r");
	yyout=fopen("table.txt","w");
	fprintf(yyout,"\n Symbol Table:\n \t\tLexeme\t\t\tToken\n");
	yylex();
	fclose(yyout);
	
}
void write_OP(char *yytext,char type)
{
  

    int len1 = strlen(yytext);
    char token[20];
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
        case 'v':
            strcpy(token,"Variable");
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
   fprintf(yyout,"\n%20s%30.30s",yytext,token);
  
}
                                                                                                    
int yywrap()
{
 return(1);
}

