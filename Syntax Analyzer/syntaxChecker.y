
%token  AUTO BREAK  CASE CHAR  CONST  CONTINUE  DEFAULT  DO DOUBLE  ELSE ENUM EXTERN FLOAT  FOR GOTO  IF INT LONG REGISTER  RETURN SHORT SIGNED 
%token SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE 

%token IDENTIFIER


%token MINUS_ASSIGN

%token DOUBLE_QUOTE SINGLE_QUOTE
%{
#include <stdio.h>
%}
%%
ED:E {printf("\nARITHMETIC EXPRESSION");
}	
;
E:E'*'E
|E'+'E
|E'/'E
|E'-'E
|E'='E
|E' 'MINUS_ASSIGN' 'E
|'('E')'
|IDENTIFIER
;
%%
void yyerror(){
	printf("\nInvalid Expression");
}
int main(){
	printf("\nEnter Valid Expressiomn : ");
	yyparse();
	return 1;
}

