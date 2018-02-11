%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
struct tokenList
{
	char *token,type[20],line[100];
	struct tokenList *next;
};
typedef struct tokenList tokenList;


extern FILE *yyin;
extern int line;
extern char *tempid;

tokenList *symbolPtr = NULL;
tokenList *constantPtr = NULL;

int errorFlag=0;
void makeList(char *,char,int);
%}

%token  AUTO BREAK  CASE CHAR  CONST  CONTINUE  DEFAULT  DO DOUBLE  ELSE ENUM 
%token EXTERN FLOAT  FOR GOTO  IF INT LONG REGISTER  RETURN SHORT SIGNED 

%token SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE 



%token IDENTIFIER

%token CONSTANT STRING_LITERAL

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
	: IDENTIFIER  { makeList(tempid, 'v', line); }
	| CONSTANT    { makeList(tempid, 'c', line);}
	| STRING_LITERAL  { makeList(tempid, 's', line);}
	| '(' expression ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']' { makeList("[", 'p', line); makeList("]", 'p', line); }
	| postfix_expression '(' ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	| postfix_expression '(' argument_expression_list ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	| postfix_expression '.' IDENTIFIER { makeList(tempid, 'v', line);}
	| postfix_expression PTR_OP IDENTIFIER { makeList(tempid, 'v', line);}
	| postfix_expression INC_OP  { makeList(tempid, 'o', line);}
	| postfix_expression DEC_OP  { makeList(tempid, 'o', line);}
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression { makeList(",",'p', line); }
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression { makeList("++",'o', line); }
	| DEC_OP unary_expression { makeList("--",'o', line); }
	| unary_operator cast_expression
	| SIZEOF unary_expression { makeList("sizeof",'o', line); }
	| SIZEOF '(' type_name ')' { makeList("sizeof",'o', line); } { makeList("(", 'p', line); makeList(")", 'p', line); }
	;

unary_operator
	: '&' { makeList("&",'o', line); }
	| '*' { makeList("*",'o', line); }
	| '+' { makeList("+",'o', line); }
	| '-' { makeList("-",'o', line); }
	| '~' { makeList("~",'o', line); }
	| '!' { makeList("!",'o', line); }
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression { makeList("(", 'p', line); makeList(")", 'p', line); }
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression { makeList("*",'o', line); }
	| multiplicative_expression '/' cast_expression { makeList("/",'o', line); }
	| multiplicative_expression '%' cast_expression { makeList("%",'o', line); }
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression { makeList("+",'o', line); }
	| additive_expression '-' multiplicative_expression { makeList("-",'o', line); }
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression { makeList("<<",'o', line); }
	| shift_expression RIGHT_OP additive_expression { makeList(">>",'o', line); }
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression { makeList("<=",'o', line); }
	| relational_expression GE_OP shift_expression { makeList(">=",'o', line); }
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression { makeList("==",'o', line); }
	| equality_expression NE_OP relational_expression { makeList("!=",'o', line); }
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression { makeList("&", 'o', line);}
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression { makeList("^", 'o', line); }
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression { makeList("|", 'o', line); }
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression { makeList("&&", 'o', line); }
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression { makeList("||", 'o', line); }
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression { makeList("?:",'o', line); }
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '=' { makeList("=",'o', line); }
	| MUL_ASSIGN { makeList("*=",'o', line); }
	| DIV_ASSIGN { makeList("/=",'o', line); }
	| MOD_ASSIGN { makeList("%=",'o', line); }
	| ADD_ASSIGN { makeList("+=",'o', line); }
	| SUB_ASSIGN { makeList("-=",'o', line); }
	| LEFT_ASSIGN { makeList("<<=",'o', line); }
	| RIGHT_ASSIGN { makeList(">==",'o', line); }
	| AND_ASSIGN { makeList("&=",'o', line); }
	| XOR_ASSIGN { makeList("^=",'o', line); }
	| OR_ASSIGN { makeList("|=",'o', line); }
	;

expression
	: assignment_expression
	| expression ',' assignment_expression { makeList(",", 'p', line); }
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';' { makeList(";", 'p', line); }
	| declaration_specifiers init_declarator_list ';' { makeList(";", 'p', line); }
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
	| init_declarator_list ',' init_declarator { makeList(",", 'p', line); }
	;

init_declarator
	: declarator
	| declarator '=' initializer { makeList("=", 'o', line); }
	;

storage_class_specifier
	: TYPEDEF { makeList("typedef", 'k', line);}
	| EXTERN { makeList("extern", 'k', line);}
	| STATIC { makeList("static", 'k', line);}
	| AUTO { makeList("auto", 'k', line);}
	| REGISTER { makeList("register", 'k', line);}
	;

type_specifier
	: VOID { makeList("void", 'k', line);}
	| CHAR { makeList("char", 'k', line);}
	| SHORT { makeList("short", 'k', line);}
	| INT { makeList("int", 'k', line);}
	| LONG { makeList("long", 'k', line);}
	| FLOAT { makeList("float", 'k', line);}
	| DOUBLE { makeList("double", 'k', line);}
	| SIGNED { makeList("signed", 'k', line);}
	| UNSIGNED { makeList("unsigned", 'k', line);}
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
	: STRUCT { makeList("struct", 'k', line);}
	| UNION { makeList("union", 'k', line);}
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' { makeList(";", 'p', line); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator { makeList(",", 'p', line); }
	;

struct_declarator
	: declarator
	| ':' constant_expression { makeList(":", 'p', line); }
	| declarator ':' constant_expression { makeList(":", 'p', line); }
	;

enum_specifier
	: ENUM '{' enumerator_list '}' { makeList("enum", 'k', line);}
	| ENUM IDENTIFIER '{' enumerator_list '}' { makeList("enum", 'k', line); makeList(tempid, 'v', line); }
	| ENUM IDENTIFIER { makeList("enum", 'k', line); makeList(tempid, 'v', line); }
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator { makeList(",", 'p', line); }
	;

enumerator
	: IDENTIFIER { makeList(tempid, 'v', line); }
	| IDENTIFIER '=' constant_expression { makeList("=", 'o', line); makeList("tempid", 'v', line); }
	;

type_qualifier
	: CONST { makeList("const", 'k', line); }
	| VOLATILE { makeList("volatile", 'k', line); }
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER { makeList(tempid, 'v', line); }
	| '(' declarator ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	| direct_declarator '[' constant_expression ']' { makeList("[", 'p', line); makeList("]", 'p', line); }
	| direct_declarator '[' ']' { makeList("[", 'p', line); makeList("]", 'p', line); }
	| direct_declarator '(' parameter_type_list ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	| direct_declarator '(' identifier_list ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	| direct_declarator '(' ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	;

pointer
	: '*' { makeList("*", 'o', line); }
	| '*' type_qualifier_list { makeList("*", 'o', line); }
	| '*' pointer { makeList("*", 'o', line); }
	| '*' type_qualifier_list pointer { makeList("*", 'o', line); }
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS { makeList(",", 'p', line); makeList("::", 'o', line); }
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration { makeList(",", 'p', line); }
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER {makeList(tempid, 'v', line);}
	| identifier_list ',' IDENTIFIER { makeList(tempid, 'v', line); makeList(",", 'p', line); }
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
	: '(' abstract_declarator ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	| '[' ']' { makeList("[", 'p', line); makeList("]", 'p', line); }
	| '[' constant_expression ']' { makeList("[", 'p', line); makeList("]", 'p', line); }
	| direct_abstract_declarator '[' ']' { makeList("[", 'p', line); makeList("]", 'p', line); }
	| direct_abstract_declarator '[' constant_expression ']' { makeList("[", 'p', line); makeList("]", 'p', line); }
	| '(' ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	| '(' parameter_type_list ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	| direct_abstract_declarator '(' ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	| direct_abstract_declarator '(' parameter_type_list ')' { makeList("(", 'p', line); makeList(")", 'p', line); }
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer { makeList(",", 'p', line); }
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
	: IDENTIFIER ':' statement  { makeList(tempid, 'v', line);  }
	| CASE constant_expression ':'  statement { makeList(":", 'p', line); makeList("case", 'k', line);}
	| DEFAULT ':' statement { makeList(":", 'p', line); makeList("default", 'k', line); }
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
	: ';' { makeList(";", 'p', line); }
	| expression ';' { makeList(";", 'p', line); }
	;

selection_statement
	: IF '(' expression ')' statement    %prec LOWER_THAN_ELSE { makeList("if", 'k', line); makeList("(", 'p', line); makeList(")", 'p', line);}
  | IF '(' expression ')' statement ELSE statement { makeList("if", 'k', line);  makeList("else", 'k', line); makeList("(", 'p', line); makeList(")", 'p', line); }
	| SWITCH '(' expression ')' statement { makeList("switch", 'k', line); makeList("(", 'p', line); makeList(")", 'p', line); }
	;

iteration_statement
	: WHILE '(' expression ')' statement  { makeList("while", 'k', line); makeList("(", 'p', line); makeList(")", 'p', line); }
	| DO statement WHILE '(' expression ')' ';' { makeList("do", 'k', line); makeList("while", 'k', line); makeList("(", 'p', line); makeList(")", 'p', line); makeList(";", 'p', line); }
	| FOR '(' expression_statement expression_statement ')' statement  { makeList("for", 'k', line); makeList("(", 'p', line); makeList(")", 'p', line); }
	| FOR '(' expression_statement expression_statement expression ')' statement { makeList("for", 'k', line); makeList("(", 'p', line); makeList(")", 'p', line); }
	;

jump_statement
	: GOTO IDENTIFIER ';' { makeList("goto", 'k', line); makeList(";", 'p', line); makeList(tempid, 'v', line);}
	| CONTINUE ';' { makeList("continue", 'k', line); makeList(";", 'p', line); }
	| BREAK ';'  { makeList("break", 'k', line); makeList(";", 'p', line);}
	| RETURN ';'  { makeList("return", 'k', line); makeList(";", 'p', line);}
	| RETURN expression ';'{ makeList("return", 'k', line); makeList(";", 'p', line);}
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
#include <stdio.h>
extern char yytext[];
extern int column;
char *s;
yyerror(s)
{
	errorFlag=1;
	fflush(stdout);
	printf("\nSyntax error at line: %d \n", line);
}
main(int argc,char **argv){
	if(argc<=1){
		
		printf("Arguments missing ! correct format : ./a.out filename \n");
		return 0;
	}
	yyin=fopen(argv[1],"r");
	yyparse();

	if(!errorFlag){
		
		printf("\n\n\t\t\t\t\tCompilation Successful!\n\n\n");
  		FILE *writeSymbol=fopen("symbolTable.txt","w");
    		fprintf(writeSymbol,"\n\t\t\t\tSymbolTable\n\n\t\tToken\t\t\tType\t\t\t\t\t\t\tLineNumber\n");
  		tokenList *ptr;
  		for(ptr=symbolPtr;ptr!=NULL;ptr=ptr->next){
  			fprintf(writeSymbol,"\n%20s%30.30s%60s",ptr->token,ptr->type,ptr->line);
			printf("\n%20s%30.30s%60s",ptr->token,ptr->type,ptr->line);
		}
		
		FILE *writeConstant=fopen("constantTable.txt","w");
    		fprintf(writeConstant,"\n   \t\t\t\t\t\t\t\tConstant Table \n\n \t\t\t\t\t\tValue\t\t\t\t\t\t\tLine Number\n");
    		for(ptr=constantPtr;ptr!=NULL;ptr=ptr->next)
  		fprintf(writeConstant,"\n%50s%60s",ptr->token,ptr->line);
  	
  	
  		fclose(writeSymbol);
		fclose(writeConstant);
	}
printf("\n");	
}
void makeList(char *sym_name,char sym_type, int linec)
{
	char line[39],linen[19];
  	snprintf(linen, 19, "%d", linec);
	strcpy(line," ");
	strcat(line,linen);
	char type[20];
	switch(sym_type)
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
	if(sym_type == 'c')
	{
    		
    		for(tokenList *p=constantPtr;p!=NULL;p=p->next)
  	 		if(strcmp(p->token,sym_name)==0){
       				strcat(p->line,line);
       				return;
     			}
		tokenList *temp=(tokenList *)malloc(sizeof(tokenList));
		temp->token=(char *)malloc(strlen(sym_name)+1);
		strcpy(temp->token,sym_name);
		strcpy(temp->type,type);
    		strcpy(temp->line,line);
		temp->next=(struct tokenList *)constantPtr;
		constantPtr=temp;
	}
	else
	{
    		for(tokenList *p=symbolPtr;p!=NULL;p=p->next)
  	 		if(strcmp(p->token,sym_name)==0){
       				strcat(p->line,line);
       				return;
     			}
		tokenList *temp=(tokenList *)malloc(sizeof(tokenList));
		temp->token=(char *)malloc(strlen(sym_name)+1);
		strcpy(temp->token,sym_name);
		strcpy(temp->type,type);
    		strcpy(temp->line,line);
		temp->next=(struct tokenList *)symbolPtr;
		symbolPtr=temp;
	}
}

