%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
#include "semantic.h"



extern FILE *yyin;
extern int lineCount;
extern char *tablePtr;
extern char *tablePtr;
extern int nestedCommentCount;
extern int commentFlag;
extern int arrayIndexErr;




char *sourceCode=NULL;
int errorFlag=0;
void makeList(char *,char,int);
%}

%token  AUTO BREAK  CASE CHAR  CONST  CONTINUE  DEFAULT  DO DOUBLE  ELSE ENUM 
%token EXTERN FLOAT  FOR GOTO  IF INT LONG REGISTER  RETURN SHORT SIGNED 

%token SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE 



%token IDENTIFIER

%token CONSTANT FLCONSTANT STRING_LITERAL

%token ELLIPSIS

%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start translation_unit

%%

primary_expression
	: IDENTIFIER  		{ $$=checkScope(tablePtr,lineCount); }
	| FLCONSTANT 		{tempCheckType=4;}
	| CONSTANT    		{ addConstant(tablePtr, lineCount);}
	| STRING_LITERAL  	{ makeList(tablePtr, 's', lineCount);}
	| '(' expression ')' 	{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); $$=$2; }
	;

postfix_expression
	: primary_expression   {$$=$1;}
	| postfix_expression '[' expression ']' 		{ makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
	| postfix_expression '(' ')' 				{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| postfix_expression '(' argument_expression_list ')' 	{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| postfix_expression '.' IDENTIFIER 			{ makeList(tablePtr, 'v', lineCount);}
	| postfix_expression PTR_OP IDENTIFIER 			{ makeList(tablePtr, 'v', lineCount);}
	| postfix_expression INC_OP  				{ makeList(tablePtr, 'o', lineCount);}
	| postfix_expression DEC_OP  				{ makeList(tablePtr, 'o', lineCount);}
	;

argument_expression_list
	: assignment_expression {$$=$1;}
	| argument_expression_list ',' assignment_expression { makeList(",",'p', lineCount); }
	;

unary_expression
	: postfix_expression {$$=$1;}
	| INC_OP unary_expression 	{ makeList("++",'o', lineCount); }
	| DEC_OP unary_expression 	{ makeList("--",'o', lineCount); }
	| unary_operator cast_expression
	| SIZEOF unary_expression 	{ makeList("sizeof",'o', lineCount); }
	| SIZEOF '(' type_name ')' 	{ makeList("sizeof",'o', lineCount); } 
					{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	;

unary_operator
	: '&' { makeList("&",'o', lineCount); }
	| '*' { makeList("*",'o', lineCount); }
	| '+' { makeList("+",'o', lineCount); }
	| '-' { makeList("-",'o', lineCount); }
	| '~' { makeList("~",'o', lineCount); }
	| '!' { makeList("!",'o', lineCount); }
	;

cast_expression
	: unary_expression   {$$=$1;}
	| '(' type_name ')' cast_expression { makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	;

multiplicative_expression
	: cast_expression {$$=$1;}
	| multiplicative_expression '*' cast_expression { makeList("*",'o', lineCount); }
	| multiplicative_expression '/' cast_expression { makeList("/",'o', lineCount); }
	| multiplicative_expression '%' cast_expression { makeList("%",'o', lineCount); }
	;

additive_expression
	: multiplicative_expression {$$=$1;}
	| additive_expression '+' multiplicative_expression { makeList("+",'o', lineCount); }
	| additive_expression '-' multiplicative_expression { makeList("-",'o', lineCount); }
	;

shift_expression
	: additive_expression {$$=$1;}
	| shift_expression LEFT_OP additive_expression 	{ makeList("<<",'o', lineCount); }
	| shift_expression RIGHT_OP additive_expression { makeList(">>",'o', lineCount); }
	;

relational_expression
	: shift_expression {$$=$1;}
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression { makeList("<=",'o', lineCount); }
	| relational_expression GE_OP shift_expression { makeList(">=",'o', lineCount); }
	;

equality_expression
	: relational_expression {$$=$1;}
	| equality_expression EQ_OP relational_expression { makeList("==",'o', lineCount); }
	| equality_expression NE_OP relational_expression { makeList("!=",'o', lineCount); }
	;

and_expression
	: equality_expression {$$=$1;}
	| and_expression '&' equality_expression 	{ makeList("&", 'o', lineCount);}
	;

exclusive_or_expression
	: and_expression {$$=$1;}
	| exclusive_or_expression '^' and_expression 	{ makeList("^", 'o', lineCount); }
	;

inclusive_or_expression
	: exclusive_or_expression {$$=$1;}
	| inclusive_or_expression '|' exclusive_or_expression { makeList("|", 'o', lineCount); }
	;

logical_and_expression
	: inclusive_or_expression {$$=$1;}
	| logical_and_expression AND_OP inclusive_or_expression { makeList("&&", 'o', lineCount); }
	;

logical_or_expression
	: logical_and_expression {$$=$1;}
	| logical_or_expression OR_OP logical_and_expression { makeList("||", 'o', lineCount); }
	;

conditional_expression
	: logical_or_expression {$$=$1;}
	| logical_or_expression '?' expression ':' conditional_expression { makeList("?:",'o', lineCount); }
	;

assignment_expression
	: conditional_expression {$$=$1;}
	| unary_expression assignment_operator assignment_expression {$$=$3; checkType($1,$3,lineCount);}
	;

assignment_operator
	: '=' 		{ makeList("=",'o', lineCount); }
	| MUL_ASSIGN 	{ makeList("*=",'o', lineCount); }
	| DIV_ASSIGN 	{ makeList("/=",'o', lineCount); }
	| MOD_ASSIGN 	{ makeList("%=",'o', lineCount); }
	| ADD_ASSIGN 	{ makeList("+=",'o', lineCount); }
	| SUB_ASSIGN 	{ makeList("-=",'o', lineCount); }
	| LEFT_ASSIGN 	{ makeList("<<=",'o', lineCount); }
	| RIGHT_ASSIGN 	{ makeList(">==",'o', lineCount); }
	| AND_ASSIGN 	{ makeList("&=",'o', lineCount); }
	| XOR_ASSIGN 	{ makeList("^=",'o', lineCount); }
	| OR_ASSIGN 	{ makeList("|=",'o', lineCount); }
	;

expression
	: assignment_expression {$$=$1;}
	| expression ',' assignment_expression { makeList(",", 'p', lineCount); }
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';' 			  { makeList(";", 'p', lineCount);typeBuffer=' '; }
	| declaration_specifiers init_declarator_list ';' { makeList(";", 'p', lineCount); typeBuffer=' ';}
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator { makeList(",", 'p', lineCount); }
	;

init_declarator
	: declarator
	| declarator '=' initializer { makeList("=", 'o', lineCount); }
	;

storage_class_specifier
	: TYPEDEF 	{ makeList("typedef", 'k', lineCount);}
	| EXTERN 	{ makeList("extern", 'k', lineCount);}
	| STATIC 	{ makeList("static", 'k', lineCount);}
	| AUTO 		{ makeList("auto", 'k', lineCount);}
	| REGISTER 	{ makeList("register", 'k', lineCount);}
	;

type_specifier
	: VOID 		{ makeList("void", 'k', lineCount);typeBuffer='v';}
	| CHAR 		{ makeList("char", 'k', lineCount); typeBuffer='c';}
	| SHORT 	{ makeList("short", 'k', lineCount);}
	| INT 		{ makeList("int", 'k', lineCount); typeBuffer='i';}
	| LONG 		{ makeList("long", 'k', lineCount);}
	| FLOAT 	{ makeList("float", 'k', lineCount);	typeBuffer='f';}
	| DOUBLE 	{ makeList("double", 'k', lineCount);}
	| SIGNED 	{ makeList("signed", 'k', lineCount);}
	| UNSIGNED 	{ makeList("unsigned", 'k', lineCount);}
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT 	{ makeList("struct", 'k', lineCount);}
	| UNION 	{ makeList("union", 'k', lineCount);}
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' { makeList(";", 'p', lineCount); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator { makeList(",", 'p', lineCount); }
	;

struct_declarator
	: declarator
	| ':' constant_expression 		{ makeList(":", 'p', lineCount); }
	| declarator ':' constant_expression 	{ makeList(":", 'p', lineCount); }
	;

enum_specifier
	: ENUM '{' enumerator_list '}' 			{ makeList("enum", 'k', lineCount);}
	| ENUM IDENTIFIER '{' enumerator_list '}' 	{ makeList("enum", 'k', lineCount); makeList(tablePtr, 'v', lineCount); }
	| ENUM IDENTIFIER 				{ makeList("enum", 'k', lineCount); makeList(tablePtr, 'v', lineCount); }
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator { makeList(",", 'p', lineCount); }
	;

enumerator
	: IDENTIFIER 				{ makeList(tablePtr, 'v', lineCount); }
	| IDENTIFIER '=' constant_expression 	{ makeList("=", 'o', lineCount); makeList("tablePtr", 'v', lineCount); }
	;

type_qualifier
	: CONST 	{ makeList("const", 'k', lineCount); }
	| VOLATILE 	{ makeList("volatile", 'k', lineCount); }
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER 						{  checkDeclaration(tablePtr,lineCount,scopeCount);}
	| '(' declarator ')' 					{  makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| direct_declarator '[' constant_expression ']' 	{ makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
	| direct_declarator '[' ']' 				{ makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
	| direct_declarator '(' parameter_type_list ')' 	{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| direct_declarator '(' identifier_list ')' 		{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| direct_declarator '(' ')' 				{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	;

pointer
	: '*' 					{ makeList("*", 'o', lineCount); }
	| '*' type_qualifier_list 		{ makeList("*", 'o', lineCount); }
	| '*' pointer 				{ makeList("*", 'o', lineCount); }
	| '*' type_qualifier_list pointer 	{ makeList("*", 'o', lineCount); }
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS 		{ makeList(",", 'p', lineCount); makeList("::", 'o', lineCount); }
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration { makeList(",", 'p', lineCount); }
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER 				{ checkDeclaration(tablePtr,lineCount,scopeCount);}
	| identifier_list ',' IDENTIFIER 	{ checkDeclaration(tablePtr,lineCount,scopeCount);makeList(",", 'p', lineCount); }
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' 					{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| '[' ']' 							{ makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
	| '[' constant_expression ']' 					{ makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
	| direct_abstract_declarator '[' ']' 				{ makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
	| direct_abstract_declarator '[' constant_expression ']' 	{ makeList("[", 'p', lineCount); makeList("]", 'p', lineCount); }
	| '(' ')' 							{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| '(' parameter_type_list ')' 					{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| direct_abstract_declarator '(' ')' 				{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| direct_abstract_declarator '(' parameter_type_list ')' 	{ makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	;

initializer
	: assignment_expression {$$=$1;}
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer { makeList(",", 'p', lineCount); }
	;

statement
	: labeled_statement
	| compound_statement                  
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement  			{ makeList(tablePtr, 'v', lineCount);  }
	| CASE constant_expression ':'  statement 	{ makeList(":", 'p', lineCount); makeList("case", 'k', lineCount);}
	| DEFAULT ':' statement 			{ makeList(":", 'p', lineCount); makeList("default", 'k', lineCount); }
	;

compound_statement
	: '{' '}' 				  	
	| '{' statement_list '}'              		
	| '{' declaration_list '}'			
	| '{' declaration_list statement_list '}' 	
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';' 				{ makeList(";", 'p', lineCount); }
	| expression ';' 	        { makeList(";", 'p', lineCount); }
	;

selection_statement
	: IF '(' expression ')' statement %prec LOWER_THAN_ELSE 
				{ makeList("if", 'k', lineCount); makeList("(", 'p', lineCount); makeList(")", 'p', lineCount);}
  	| IF '(' expression ')' statement ELSE statement 
  				{ makeList("if", 'k', lineCount);  makeList("else", 'k', lineCount); makeList("(", 'p', lineCount); 					  makeList(")", 'p', lineCount); 
  				}
	| SWITCH '(' expression ')' statement 
				{ makeList("switch", 'k', lineCount); makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	;

iteration_statement
	: WHILE '(' expression ')' statement  
			{ makeList("while", 'k', lineCount); makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| DO statement WHILE '(' expression ')' ';' 
			{ makeList("do", 'k', lineCount); makeList("while", 'k', lineCount); makeList("(", 'p', lineCount);         				  makeList(")", 'p', lineCount); makeList(";", 'p', lineCount); 
			}
	| FOR '(' expression_statement expression_statement ')' statement  
			{ makeList("for", 'k', lineCount); makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	| FOR '(' expression_statement expression_statement expression ')' statement 
			{ makeList("for", 'k', lineCount); makeList("(", 'p', lineCount); makeList(")", 'p', lineCount); }
	;

jump_statement
	: GOTO IDENTIFIER ';' 	{ makeList("goto", 'k', lineCount); makeList(";", 'p', lineCount); makeList(tablePtr, 'v', lineCount);}
	| CONTINUE ';' 		{ makeList("continue", 'k', lineCount); makeList(";", 'p', lineCount); }
	| BREAK ';'  		{ makeList("break", 'k', lineCount); makeList(";", 'p', lineCount);}
	| RETURN ';'  		{ makeList("return", 'k', lineCount); makeList(";", 'p', lineCount);}
	| RETURN expression ';'	{ makeList("return", 'k', lineCount); makeList(";", 'p', lineCount);}
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition	
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement  
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%
void yyerror()
{
	errorFlag=1;
	fflush(stdout);
	printf("\n%s : %d :Syntax error \n",sourceCode,lineCount);
}
void main(int argc,char **argv){
	if(argc<=1){
		
		printf("Invalid ,Expected Format : ./a.out <\"sourceCode\"> \n");
		return 0;
	}
	
	yyin=fopen(argv[1],"r");
	sourceCode=(char *)malloc(strlen(argv[1])*sizeof(char));
	sourceCode=argv[1];
	yyparse();
	
	if(nestedCommentCount!=0){
		errorFlag=1;
    		printf("%s : %d : Comment Does Not End\n",sourceCode,lineCount);
    		
	}
	if(commentFlag==1){
		errorFlag=1;
		printf("%s : %d : Nested Comment\n",sourceCode,lineCount);
    	}
	
		
	
	if(!errorFlag  && !semanticErr  && arrayIndexErr!=1){
		
		printf("\n\n\t\t%s Parsing Completed\n\n",sourceCode);
		
		
	
		FILE *writeParsed=fopen("parsedTable.txt","w");
    		fprintf(writeParsed,"\n\t\t\t\tParsed Table\n\n\t\tToken\t\t\t\t\t\tType\t\t\t\t\t\t\tLine Number\n");
      		for(tokenList *ptr=parsedPtr;ptr!=NULL;ptr=ptr->next){
  			fprintf(writeParsed,"\n%20s%30.30s%60s",ptr->token,ptr->type,ptr->line);
		}
  		FILE *writeSymbol=fopen("symbolTable.txt","w");
    		fprintf(writeSymbol,"\n\t\t\t\tSymbolTable\n\n\t\tToken\t\t\t\tType\t\tLine Number\t\t\t\tScope\t\tFunction Number\n");
      		for(tokenList *ptr=symbolPtr;ptr!=NULL;ptr=ptr->next){
  			fprintf(writeSymbol,"\n%20s%30.30s%30s%30s\t%d\t%d",ptr->token,ptr->type,ptr->line,ptr->scope,ptr->scopeValue,ptr->funcCount+1);
		}
		
		FILE *writeConstant=fopen("constantTable.txt","w");
    		fprintf(writeConstant,"\n   \t\t\t\t\t\t\t\tConstant Table \n\n \t\t\t\t\t\tValue\t\t\t\t\t\t\tLine Number\n");
    		for(tokenList *ptr=constantPtr;ptr!=NULL;ptr=ptr->next)
  		fprintf(writeConstant,"\n%50s%60s",ptr->token,ptr->line);
  	
  	
  		fclose(writeSymbol);
		fclose(writeConstant);
		fclose(writeParsed);
	}
printf("\n\n");	
}


