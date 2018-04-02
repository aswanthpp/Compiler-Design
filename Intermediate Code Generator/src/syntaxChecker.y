%{
#include "icg.h"


extern int yylineno;
extern char *yytext;

int paramCount;
char icgQuad[50];
int funcLineNumber = 0;

%}

%token VOID INT FLOAT CONSTANT IDENTIFIER
%token IF ELSE RETURN DO WHILE FOR
%token INC_OP DEC_OP U_PLUS U_MINUS  
%token EQUAL NOT_EQUAL GREATER_OR_EQUAL LESS_OR_EQUAL SHIFTLEFT LOG_AND LOG_OR

%right '='
%left LOG_OR    
%left LOG_AND
%left '<' '>' LESS_OR_EQUAL GREATER_OR_EQUAL
%left EQUAL NOT_EQUAL
%left SHIFTLEFT
%left '+' '-'
%left '*' '/' '%'
%right U_PLUS U_MINUS '!'
%left INC_OP DEC_OP

%union
{
    char         	*str;
    int           	integer;
    float         	real;
    int           	type;
	struct
	{
	    char                 	*value;
	    int   			type;
	    int				cType;
	    struct BackpatchList* 	trueList;
	    struct BackpatchList* 	falseList;
	} expr;
	struct
	{
	  struct BackpatchList* 	nextList;
	} stmt;
	struct
	{
	  int				quad;
	  struct BackpatchList* 	nextList;
	} mark;
	struct
	{
	    int				count;
	    struct tokenList * 	queue;
	} exp_list;
}

%type <str> id IDENTIFIER
%type <type> declaration var_type
%type <expr> expression assignment CONSTANT
%type <stmt> statement statement_list matched_statement unmatched_statement program function_body function
%type <exp_list> exp_list
%type <mark> marker jump_marker
%start program_head

%%

program_head
    : program
	{
	    tokenList * mainFunc = getSymbol("main");
	    if(mainFunc == NULL){
		printf("ERROR: Main function not found!\n");
		yyerror();
	    }
	    backpatch($1.nextList,mainFunc->line+1);
	}
    ;

program
    : jump_marker function
        {

	    $$.nextList = $1.nextList;
            backpatch($2.nextList, nextquad());

        }
    | program function
        {

	    $$.nextList = $1.nextList;
            backpatch($2.nextList, nextquad());

        }
    ;
						


function
    : var_type id '(' parameter_list ')' ';'
        {

            addFunctionPrototype($2, paramCount, $1);
            paramCount = 0;
            $$.nextList = NULL;
        }
    | var_type id '(' parameter_list ')' function_body
        {

            addFunction($2, paramCount, $1, funcLineNumber);
            paramCount = 0;
	    funcLineNumber = nextquad();
            $$.nextList = $6.nextList;
        }
    ;

function_body
    : '{' statement_list  '}'
        {

            $$.nextList = $2.nextList;
        }
    | '{' declaration_list statement_list '}'
        {

            $$.nextList = $3.nextList;
        }
    ;

declaration_list
    : declaration ';'
        {

        }
    | declaration_list declaration ';'
        {

        }
    ;

declaration
    : INT id
        {
            $$ = INT_type;
            addSymbolToQueue($2, INT_type, 0);

        }
    | FLOAT id
        {
            $$ = FLOAT_type;
            addSymbolToQueue($2, FLOAT_type, 0);

        }
    | declaration ',' id
        {
            if(INT_type == $1) {
                addSymbolToQueue($3, INT_type, 0);
            } else if(FLOAT_type == $1) {
                addSymbolToQueue($3, FLOAT_type, 0);
            }

        }
    ;

parameter_list
    : INT id
        {
            paramCount++;
            addSymbolToQueue($2, INT_type, paramCount);

        }
    | FLOAT id
        {
            paramCount++;
            addSymbolToQueue($2, FLOAT_type, paramCount);

        }
    | parameter_list ',' INT id
        {
            paramCount++;
            addSymbolToQueue($4, INT_type, paramCount);

        }
    | parameter_list ',' FLOAT id
        {
            paramCount++;
            addSymbolToQueue($4, FLOAT_type, paramCount);

        }
    | VOID
        {

        }
    |
        {

        }
    ;

var_type
    : VOID
        {
            $$ = Return_VOID;

        }
    | INT
        {
            $$ = Return_INT;

        }
   
    | FLOAT
        {
            $$ = Return_FLOAT;

        }
    ;

statement_list
    : statement
        {

            $$.nextList = $1.nextList;

        }
    | statement_list marker statement
        {

	    backpatch($1.nextList,$2.quad);
	    $$.nextList = $3.nextList;

        }
    ;

statement
    : matched_statement
        {

	    $$.nextList = $1.nextList;

        }
    | unmatched_statement
        {

	    $$.nextList = $1.nextList;

        }
    ;

matched_statement
    : IF '(' assignment ')' marker matched_statement jump_marker ELSE marker matched_statement
        {

	    backpatch($3.trueList,$5.quad);
	    backpatch($3.falseList,$9.quad);
	    $$.nextList = mergelists($7.nextList,$10.nextList);
	    $$.nextList = mergelists($$.nextList,$6.nextList);

        }
    | assignment ';'
        {

       
	    $$.nextList = NULL;

	}
    | RETURN ';'
        {


	    $$.nextList = NULL;
	    sprintf(icgQuad,"RETURN");
	    appendCode(icgQuad);

        }
    | RETURN assignment ';'
        {


	    $$.nextList = NULL;
            sprintf(icgQuad,"RETURN %s",$2.value);
	    appendCode(icgQuad);

        }
    | WHILE marker '(' assignment ')' marker matched_statement jump_marker
        {

	    backpatch($4.trueList,$6.quad);
	    $$.nextList = $4.falseList;
	    backpatch($7.nextList,$2.quad);
	    backpatch($8.nextList,$2.quad);

        }
    | DO marker statement WHILE '(' marker assignment ')' ';'
        {
	    backpatch($3.nextList,$6.quad);
	    backpatch($7.trueList,$2.quad);
	    $$.nextList = $7.falseList;
        }
    | FOR '(' assignment ';' marker assignment ';' marker assignment jump_marker ')' marker matched_statement jump_marker
        {

            if(BOOL_type == $3.type || BOOL_type == $9.type) {
                printf("error, no boolean statements allowed as 1st or 3rd assignment in for loop\n");
                yyerror();
            }
            if(BOOL_type != $6.type) {
                printf("error, 2nd argument of for loop must be boolean\n");
                yyerror();
            }
            backpatch($3.trueList, $5.quad);
            backpatch($13.nextList, $8.quad);
            backpatch($14.nextList, $8.quad);
            $$.nextList = $6.falseList;
            backpatch($6.trueList, $12.quad);
            backpatch($9.trueList, $5.quad);
            backpatch($10.nextList, $5.quad);

        }
    | '{' statement_list '}'
        {

	    $$.nextList = $2.nextList;

        }
    | '{' '}'
        {	    

	    $$.nextList = NULL;

        }
    ;

unmatched_statement
    : IF '(' assignment ')' marker statement
        {

	    backpatch($3.trueList,$5.quad);
	    $$.nextList = mergelists($3.falseList,$6.nextList);

        }
    | WHILE marker '(' assignment ')' marker unmatched_statement jump_marker
        {

	    backpatch($4.trueList,$6.quad);
	    $$.nextList = $4.falseList;
	    backpatch($7.nextList,$2.quad);
	    backpatch($8.nextList,$2.quad);

        }
    | FOR '(' assignment ';' marker assignment ';' marker assignment jump_marker ')' marker unmatched_statement jump_marker
        {

            if(BOOL_type == $3.type || BOOL_type == $9.type) {
                printf("error, no boolean statements allowed as 1st or 3rd assignment in for loop\n");
                yyerror();
            }
            if(BOOL_type != $6.type) {
                printf("error, 2nd argument of for loop must be boolean\n");
                yyerror();
            }
            backpatch($3.trueList, $5.quad);
            backpatch($13.nextList, $8.quad);
            backpatch($14.nextList, $8.quad);
            $$.nextList = $6.falseList;
            backpatch($6.trueList, $12.quad);
            backpatch($9.trueList, $5.quad);
            backpatch($10.nextList, $5.quad);

        }

    | IF '(' assignment ')' marker matched_statement jump_marker ELSE marker unmatched_statement
        {

	    backpatch($3.trueList,$5.quad);
	    backpatch($3.falseList,$9.quad);
	    $$.nextList = mergelists($7.nextList,$10.nextList);
	    $$.nextList = mergelists($$.nextList,$6.nextList);

        }
    ;

assignment
    : expression
        {

            $$=$1;
        }
    | id '=' expression
        {
            int destType = getSymbolType($1);
        	if(destType == 0){
        		printf("ERROR: Not in scope");
        	}
            if(destType != $3.type) {
                printf("Type error on line: %d\n", yylineno);
                yyerror();
            }

            sprintf(icgQuad,"%s := %s",$1,$3.value);
            appendCode(icgQuad);
            $$.type = destType;
            $$.trueList = $3.trueList;
            $$.cType = VAR_type;
            $$.value = $1;
        }
    ;

expression
    : INC_OP expression
        {

	    if($2.type != INT_type){
		    printf("ERROR: Increment not allowed for types different than Integer.\n");
		    yyerror();
	    }
	    //Create a variable if needed
	    if($2.cType != VAR_type){
		    char *var = nextIntVar();
		    sprintf(icgQuad,"%s := %s",var,$2.value);
		    appendCode(icgQuad);
		    free($2.value);
		    $2.value = var;
		    $2.type = INT_type;
		    $2.cType = VAR_type;
	    }
            sprintf(icgQuad,"%s := %s + 1",$2.value,$2.value);
            appendCode(icgQuad);
            //Set the attributes
            $$ = $2;
            $$.trueList = NULL;
            $$.falseList = NULL;

        }
    | DEC_OP expression
        {

	    if($2.type != INT_type){
		    printf("ERROR: Decrement not allowed for types different than Integer.\n");
		    yyerror();
	    }
	    //Create a variable if needed
	    if($2.cType != VAR_type){
		    char *var = nextIntVar();
		    sprintf(icgQuad,"%s := %s",var,$2.value);
		appendCode(icgQuad);
		    free($2.value);
		    $2.value = var;
		    $2.type = INT_type;
		    $2.cType = VAR_type;
	    }
            sprintf(icgQuad,"%s := %s - 1",$2.value,$2.value);
            appendCode(icgQuad);
            //Set the attributes
            $$ = $2;
            $$.trueList = NULL;
            $$.falseList = NULL;

        }
    | expression LOG_OR marker expression
        {
            if(BOOL_type != $1.type) {
                sprintf(icgQuad, "IF (%s <> 0) GOTO", $1.value);
                $1.trueList = appendToBackPatch(NULL, appendCode(icgQuad));
                sprintf(icgQuad, "GOTO");
                $1.falseList = appendToBackPatch(NULL, appendCode(icgQuad));
            }
            if(BOOL_type != $4.type) {
                sprintf(icgQuad, "IF (%s <> 0) GOTO", $4.value);
                $4.trueList = appendToBackPatch(NULL, appendCode(icgQuad));
                sprintf(icgQuad, "GOTO");
                $4.falseList = appendToBackPatch(NULL, appendCode(icgQuad));
            }
            $$.trueList = mergelists($1.trueList, $4.trueList);
            backpatch($1.falseList, $3.quad);
            $$.falseList = $4.falseList;
            $$.type = BOOL_type;
	}
    | expression LOG_AND marker expression
        {
            if(BOOL_type != $1.type) {
                sprintf(icgQuad, "IF (%s <> 0) GOTO", $1.value);
                $1.trueList = appendToBackPatch(NULL, appendCode(icgQuad));
                sprintf(icgQuad, "GOTO");
                $1.falseList = appendToBackPatch(NULL, appendCode(icgQuad));
            }
            if(BOOL_type != $4.type) {
                sprintf(icgQuad, "IF (%s <> 0) GOTO", $4.value);
                $4.trueList = appendToBackPatch(NULL, appendCode(icgQuad));
                sprintf(icgQuad, "GOTO");
                $4.falseList = appendToBackPatch(NULL, appendCode(icgQuad));
            }
            $$.falseList = mergelists($1.falseList, $4.falseList);
            backpatch($1.trueList, $3.quad);
            $$.trueList = $4.trueList;
            $$.type = BOOL_type;
	 }
    | expression NOT_EQUAL expression
        {

	    if($1.type != INT_type && $1.type != FLOAT_type){
		printf("ERROR: Only Integer, Float and Bool values allowed in comparsions.\n");
		yyerror();
	    }
            sprintf(icgQuad,"IF (%s <> %s) GOTO",$1.value,$3.value);
	    $$.trueList = appendToBackPatch(NULL, appendCode(icgQuad));
            sprintf(icgQuad,"GOTO");
	    $$.falseList = appendToBackPatch(NULL, appendCode(icgQuad));
	    $$.value = "TrueFalse Only!";
	    $$.type = BOOL_type;
	    $$.cType = NONE_type;

        }
    | expression EQUAL expression
        {

	    if($1.type != INT_type && $1.type != FLOAT_type){
		printf("ERROR: Only Integer, Float and Bool values allowed in comparsions.\n");
		yyerror();
	    }
            sprintf(icgQuad,"IF (%s = %s) GOTO",$1.value,$3.value);
	    $$.trueList = appendToBackPatch(NULL, appendCode(icgQuad));
            sprintf(icgQuad,"GOTO");
	    $$.falseList = appendToBackPatch(NULL, appendCode(icgQuad));
        if(BOOL_type == $1.type) {
            $$.trueList = mergelists($$.trueList, $1.trueList);
            $$.falseList = mergelists($$.falseList, $1.falseList);
        }
        if(BOOL_type == $3.type) {
            $$.trueList = mergelists($$.trueList, $3.trueList);
            $$.falseList = mergelists($$.falseList, $3.falseList);
        }
	    $$.value = "TrueFalse Only!";
	    $$.type = BOOL_type;
	    $$.cType = NONE_type;

        }
    | expression GREATER_OR_EQUAL expression
        {

	    if($1.type != INT_type && $1.type != FLOAT_type){
		printf("ERROR: Only Integer, Float and Bool values allowed in comparsions.\n");
		yyerror();
	    }
            sprintf(icgQuad,"IF (%s >= %s) GOTO",$1.value,$3.value);
	    $$.trueList = appendToBackPatch(NULL, appendCode(icgQuad));
            sprintf(icgQuad,"GOTO");
	    $$.falseList = appendToBackPatch(NULL, appendCode(icgQuad));
	    $$.value = "TrueFalse Only!";
	    $$.type = BOOL_type;
	    $$.cType = NONE_type;

        }
    | expression LESS_OR_EQUAL expression
        {

	    if($1.type != INT_type && $1.type != FLOAT_type){
		printf("ERROR: Only Integer, Float and Bool values allowed in comparsions.\n");
		yyerror();
	    }
	    sprintf(icgQuad,"IF (%s <= %s) GOTO",$1.value,$3.value);
	    $$.trueList = appendToBackPatch(NULL, appendCode(icgQuad));
	    sprintf(icgQuad,"GOTO");
	    $$.falseList = appendToBackPatch(NULL, appendCode(icgQuad));
	    $$.value = "TrueFalse Only!";
	    $$.type = BOOL_type;
	    $$.cType = NONE_type;

        }
    | expression '>' expression
        {

	    if($1.type != INT_type && $1.type != FLOAT_type){
		printf("ERROR: Only Integer, Float and Bool values allowed in comparsions.\n");
		yyerror();
	    }
	    sprintf(icgQuad,"IF (%s > %s) GOTO",$1.value,$3.value);
	    $$.trueList = appendToBackPatch(NULL, appendCode(icgQuad));
	    sprintf(icgQuad,"GOTO");
	    $$.falseList = appendToBackPatch(NULL, appendCode(icgQuad));
	    $$.value = "TrueFalse Only!";
	    $$.type = BOOL_type;
	    $$.cType = NONE_type;

        }
    | expression '<' expression
        {

	    if($1.type != INT_type && $1.type != FLOAT_type){
		printf("ERROR: Only Integer, Float and Bool values allowed in comparsions.\n");
		yyerror();
	    }
	    sprintf(icgQuad,"IF (%s < %s) GOTO",$1.value,$3.value);
	    $$.trueList = appendToBackPatch(NULL, appendCode(icgQuad));
	    sprintf(icgQuad,"GOTO");
	    $$.falseList = appendToBackPatch(NULL, appendCode(icgQuad));
	    $$.value = "TrueFalse Only!";
	    $$.type = BOOL_type;
	    $$.cType = NONE_type;

        }
   
    | expression '+' expression
        {

	    if($1.type != INT_type && $1.type!= FLOAT_type &&  $3.type != INT_type && $3.type != FLOAT_type){
		printf("ERROR: Only integer and float values allowed when adding numbers.\n");
		yyerror();
	    }
	    int type = 0;
	    if($1.type == $3.type){
		type = $1.type;
	    }
	    else{
		type = FLOAT_type;
	    }
	    
	    char* var = NULL;
            switch(type){
            	case INT_type: var = nextIntVar();break;
            	case FLOAT_type:var = nextFloatVar();break;
            }
            char buffer[50];
            sprintf(icgQuad,"%s := %s + %s",var,$1.value,$3.value);
            appendCode(icgQuad);
            $$.value = var;
            $$.type = type;
            $$.cType = VAR_type;
	    $$.trueList = NULL;
	    $$.falseList = NULL;

        }
    | expression '-' expression
        {

	    if($1.type != INT_type && $1.type!= FLOAT_type &&  $3.type != INT_type && $3.type != FLOAT_type){
		printf("ERROR: Only integer and float values allowed when substracting numbers.\n");
		yyerror();
	    }
	    int type = 0;
	    if($1.type == $3.type){
		type = $1.type;
	    }
	    else{
		type = FLOAT_type;
	    }
	    
	    char* var = NULL;
            switch(type){
            	case INT_type: var = nextIntVar();break;
            	case FLOAT_type:var = nextFloatVar();break;
            }
            char buffer[50];
            sprintf(icgQuad,"%s := %s - %s",var,$1.value,$3.value);
            appendCode(icgQuad);
            $$.value = var;
            $$.type = type;
            $$.cType = VAR_type;
	    $$.trueList = NULL;
	    $$.falseList = NULL;

        }
    | expression '*' expression
        {

	    if($1.type != INT_type && $1.type!= FLOAT_type &&  $3.type != INT_type && $3.type != FLOAT_type){
		printf("ERROR: Only integer and float values allowed when multiplicating numbers.\n");
		yyerror();
	    }
	    int type = 0;
	    if($1.type == $3.type){
		type = $1.type;
	    }
	    else{
		type = FLOAT_type;
	    }
	    
	    char* var = NULL;
            switch(type){
            	case INT_type: var = nextIntVar();break;
            	case FLOAT_type:var = nextFloatVar();break;
            }
            char buffer[50];
            sprintf(icgQuad,"%s := %s * %s",var,$1.value,$3.value);
            appendCode(icgQuad);
            $$.value = var;
            $$.type = type;
            $$.cType = VAR_type;
	    $$.trueList = NULL;
	    $$.falseList = NULL;

        }
    | expression '/' expression
        {

	    if($1.type != INT_type && $1.type!= FLOAT_type &&  $3.type != INT_type && $3.type != FLOAT_type){
		printf("ERROR: Only integer and float values allowed when dividing numbers.\n");
		yyerror();
	    }
	    int type = 0;
	    if($1.type == $3.type){
		type = $1.type;
	    }
	    else{
		type = FLOAT_type;
	    }
	    
	    char* var = NULL;
            switch(type){
            	case INT_type: var = nextIntVar();break;
            	case FLOAT_type:var = nextFloatVar();break;
            }
            char buffer[50];
            sprintf(icgQuad,"%s := %s / %s",var,$1.value,$3.value);
            appendCode(icgQuad);
            $$.value = var;
            $$.type = type;
            $$.cType = VAR_type;
	    $$.trueList = NULL;
	    $$.falseList = NULL;

        }
    | expression '%' expression
        {

	    if($1.type != INT_type && $1.type!= FLOAT_type &&  $3.type != INT_type && $3.type != FLOAT_type){
		printf("ERROR: Only integer and float values allowed when caluclating mod.\n");
		yyerror();
	    }
	    int type = 0;
	    if($1.type == $3.type){
		type = $1.type;
	    }
	    else{
		type = FLOAT_type;
	    }
	    
	    char* var = NULL;
            switch(type){
            	case INT_type: var = nextIntVar();break;
            	case FLOAT_type:var = nextFloatVar();break;
            }
            char buffer[50];
            sprintf(icgQuad,"%s := %s \% %s",var,$1.value,$3.value);
            appendCode(icgQuad);
            $$.value = var;
            $$.type = type;
            $$.cType = VAR_type;
	    $$.trueList = NULL;
	    $$.falseList = NULL;

        }
    | '!' expression
        {

	    if($2.type != BOOL_type){
		if($2.type != INT_type && $2.type != FLOAT_type){
		    printf("ERROR: Only Bool, Int and Float allowed in logical expressions!\n");
		    yyerror();
		}
		sprintf(icgQuad,"IF (%s <> 0) GOTO",$2.value);
		$$.falseList = appendToBackPatch(NULL,appendCode(icgQuad));
		sprintf(icgQuad,"GOTO",$2.value);
		$$.trueList = appendToBackPatch(NULL,appendCode (icgQuad));
	    }
	    else{
	      $$ = $2;
	      $$.trueList = $2.falseList;
	      $$.falseList = $2.trueList;
	    }

	}
    | U_PLUS expression
        {
            if(INT_type != $2.type && FLOAT_type != $2.type) {
                yyerror();
            }
            $$ = $2;
        }
    | U_MINUS expression
        {
            $$ = $2;
            if(INT_type == $2.type) {
                $$.value = nextIntVar();
            } else if (FLOAT_type == $2.type) {
                $$.value = nextFloatVar();
            } else {
                yyerror();
            }
            sprintf(icgQuad, "%s := -%s", $$.value, $2.value);
            appendCode (icgQuad);
       }
    | CONSTANT
        {

            $$.value = strdup(yytext);
            $$.trueList = NULL;
	    $$.falseList = NULL;

            
        }
    | '(' expression ')'
        {

	    $$ = $2;

        }
    | id '(' exp_list ')' ';'
        {

            int varType = getFunctionType($1);
            if(varType == 0){
            	printf("ERROR: Function %s not defined!\n",$1);
		yyerror();
            }
            char* var = NULL;
            switch(varType){
            case Return_INT:
                var = nextIntVar();
                $$.type = INT_type;
                break;
            case Return_FLOAT:
                var = nextFloatVar();
                $$.type = FLOAT_type;
                break;
            }
	    $$.value = var;
	    $$.cType = VAR_type;
	    checkAndGenerateParams($3.queue,$1,$3.count);
            sprintf(icgQuad,"%s := CALL %s, %d",var,$1,$3.count);
            appendCode (icgQuad);

        }
    | id '('  ')' ';'
        {

            int varType = getFunctionType($1);
            if(varType == 0){
            	printf("ERROR: Function %s not defined!\n",$1);
		yyerror();
            }
            char* var = NULL;
            switch(varType){
             case Return_INT:
                var = nextIntVar;
                $$.type = INT_type;
                break;
            case Return_FLOAT:
                var = nextFloatVar;
                $$.type = FLOAT_type;
                break;
           
            }
	    $$.value = var;
	    $$.cType = VAR_type;
	    checkAndGenerateParams(NULL,$1,0);
            sprintf(icgQuad,"%s := CALL %s, %d",var,$1,0);
            appendCode (icgQuad);

        }
    | id
        {

	    int varType = getSymbolType($1);
            if(varType == 0){
            	printf("ERROR: Variable %s not in scope!\n",$1);
		yyerror();
            }
	    $$.value = $1;
	    $$.type = varType;
	    $$.cType = VAR_type;

        }
    ;

exp_list
    : expression
        {

	    if($1.type != INT_type && $1.type != FLOAT_type){
		printf("ERROR: Only Integer and Float are allowed as parameter types.\n");
		yyerror();
	    }
	    $$.queue = addSymbolToParameterQueue(NULL,$1.value,$1.type);
	    $$.count = 1;

        }
    | exp_list ',' expression
        {

	      if($3.type != INT_type && $3.type != FLOAT_type){
		  printf("ERROR: Only Integer and Float are allowed as parameter types.\n");
		  yyerror();
	      }
	      $$.queue = addSymbolToParameterQueue($1.queue,$3.value,$3.type);
	      $$.count = $1.count + 1;

        }
    ;

id
    : IDENTIFIER
        {

            $$ = strdup(yytext);
        }
    ;
marker
	: {	

	      $$.quad = nextquad();

	};
jump_marker
	: {

	      $$.quad = nextquad();
	      sprintf(icgQuad,"GOTO");
	      $$.nextList = appendToBackPatch(NULL, appendCode (icgQuad));

   };
%%
