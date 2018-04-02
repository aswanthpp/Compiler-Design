%option noyywrap
%option nomain
%option yylineno


%{
#include "icg.h"
#include "y.tab.h"

// unary plus and minus can only appear at line beginnings and after opening paranthesises or *,/,%
int f=0;
%}

NEWLINE (\n|\n\l|\r\n)
WHITESPACE (" "|\t)
SINGLELINE_COMMENT ("//".*{NEWLINE})
MULTILINE_COMMENT ("/*".*"*/")
PREPROCESSOR ("#".*{NEWLINE})
INTEGER (0|[1-9][0-9]*)
FLOAT (0\.0|[1-9][0-9]*\.[0-9]+)
IDENTIFIER ([a-zA-Z_][a-zA-Z0-9_]*)
LIBFUNC   "printf"|"scanf"

%%

({NEWLINE}+|{WHITESPACE}+) {}
({SINGLELINE_COMMENT}|{MULTILINE_COMMENT}) {}
{PREPROCESSOR} {}

^("+"|"-") {
   		if('+' == yytext[0]) {
        		return(U_PLUS);
    		} else {
        		return(U_MINUS);
    		}
    		f = 0;
	}
("("|")"|"{"|"}"|"<"|">"|"="|";"|","|"!") 	{f = 1;return(yytext[0]);}

("/"|"*"|"%") 					{f = 1;return(yytext[0]);}
("+"|"-") {
    		if(f==1) {
        		if('+' == yytext[0]) {
            		return(U_PLUS);
        	} 
        	else {
            		return(U_MINUS);
        	}
        	f = 0;
    		} else {
        		return(yytext[0]);
    		}
	}

"void" 						{return(VOID);}
"int" 						{return(INT);}
"float" 					{return(FLOAT);}
"constant" 					{return(CONSTANT);}
"if" 						{return(IF);}
"else" 						{return(ELSE);}
"return" 					{return(RETURN);}
"do" 						{return(DO);}
"while" 					{return(WHILE);}
"for" 						{return(FOR);}
"++" 						{return(INC_OP);}
"--" 						{return(DEC_OP);}
"==" 						{return(EQUAL);}
"!=" 						{return(NOT_EQUAL);}
">=" 						{return(GREATER_OR_EQUAL);}
"<=" 						{return(LESS_OR_EQUAL);}
"<<" 						{return(SHIFTLEFT);}
"&&" 						{return(LOG_AND);}
"||" 						{return(LOG_OR);}
{LIBFUNC}\(.*\)\;  				{//printf("LEXER: found Library function %s\n",yytext);
						 //printf("\nLEXER : excluding meaning given during linking\n");
						}

{INTEGER} {
    		yylval.expr.value = strdup(yytext);
    		yylval.expr.cType = CONST_type;
    		yylval.expr.type = INT_type;
    		f = 0;
    		return(CONSTANT);
	}
{FLOAT} {
    		yylval.expr.value = strdup(yytext);
    		yylval.expr.cType = CONST_type;
    		yylval.expr.type = FLOAT_type;
    		f = 0;
    		return(CONSTANT);
	}
{IDENTIFIER} {
    		yylval.str = malloc(strlen(yytext)*sizeof(char)+1);
    		strcpy(yylval.str, yytext);
    		f = 0;
    		return(IDENTIFIER);
	}

%%
