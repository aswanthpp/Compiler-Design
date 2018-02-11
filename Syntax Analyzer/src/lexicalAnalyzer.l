
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*


%{

#include <stdio.h>
#include "y.tab.h"
int cnt=1;
int line=1;
char *tempid;
void insert(char*);
%}
comment (\/\/.*)
comstr (\/\*)
comend (\*\/)
%x C_COMMENT

%%


{comment}      		{ line++;}
{comstr}            	{ BEGIN(C_COMMENT); }
<C_COMMENT>{comend} 	{ BEGIN(INITIAL); line++; }
<C_COMMENT>\n 		{line++;}
<C_COMMENT>. 		{}




"auto"			{ cnt+=yyleng; return(AUTO); }
"break"			{ cnt+=yyleng;  return(BREAK); }
"case"			{ cnt+=yyleng;  return(CASE); }
"char"			{ cnt+=yyleng; return(CHAR); }
"const"			{ cnt+=yyleng; return(CONST); }
"continue"		{ cnt+=yyleng; return(CONTINUE); }
"default"		{ cnt+=yyleng; return(DEFAULT); }
"do"			{ cnt+=yyleng; return(DO); }
"double"		{ cnt+=yyleng; return(DOUBLE); }
"else"			{ cnt+=yyleng; return(ELSE); }
"enum"			{ cnt+=yyleng; return(ENUM); }
"extern"		{ cnt+=yyleng; return(EXTERN); }
"float"			{ cnt+=yyleng; return(FLOAT); }
"for"			{ cnt+=yyleng; return(FOR); }
"goto"			{ cnt+=yyleng; return(GOTO); }
"if"			{ cnt+=yyleng; return(IF); }
"int"			{ cnt+=yyleng; return(INT); }
"long"			{ cnt+=yyleng; return(LONG); }
"register"		{ cnt+=yyleng; return(REGISTER); }
"return"		{ cnt+=yyleng; return(RETURN); }
"short"			{ cnt+=yyleng; return(SHORT); }
"signed"		{ cnt+=yyleng; return(SIGNED); }
"sizeof"		{ cnt+=yyleng; return(SIZEOF); }
"static"		{ cnt+=yyleng; return(STATIC); }
"struct"		{ cnt+=yyleng; return(STRUCT); }
"switch"		{ cnt+=yyleng; return(SWITCH); }
"typedef"		{ cnt+=yyleng; return(TYPEDEF); }
"union"			{ cnt+=yyleng;  return(UNION); }
"unsigned"		{ cnt+=yyleng;  return(UNSIGNED); }
"void"			{ cnt+=yyleng;  return(VOID); }
"volatile"		{ cnt+=yyleng;  return(VOLATILE); }
"while"			{ cnt+=yyleng;  return(WHILE); }

{L}({L}|{D})*		{ cnt+=yyleng; insert(yytext); return(IDENTIFIER); }

0[xX]{H}+{IS}?		{ cnt+=yyleng; insert(yytext); return(CONSTANT); }
0{D}+{IS}?		{ cnt+=yyleng; insert(yytext); return(CONSTANT); }
{H}+{IS}?		{ cnt+=yyleng; insert(yytext); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ cnt+=yyleng; insert(yytext); return(CONSTANT); }

{D}+{E}{FS}?		{ cnt+=yyleng; insert(yytext); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ cnt+=yyleng; insert(yytext); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ cnt+=yyleng; insert(yytext); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ cnt+=yyleng; insert(yytext); return(STRING_LITERAL); }

"..."			{ cnt+=yyleng; return(ELLIPSIS); }
">>="			{ cnt+=yyleng; return(RIGHT_ASSIGN); }
"<<="			{ cnt+=yyleng; return(LEFT_ASSIGN); }
"+="			{ cnt+=yyleng; return(ADD_ASSIGN); }
"-="			{ cnt+=yyleng; return(SUB_ASSIGN); }
"*="			{ cnt+=yyleng; return(MUL_ASSIGN); }
"/="			{ cnt+=yyleng; return(DIV_ASSIGN); }
"%="			{ cnt+=yyleng; return(MOD_ASSIGN); }
"&="			{ cnt+=yyleng; return(AND_ASSIGN); }
"^="			{ cnt+=yyleng; return(XOR_ASSIGN); }
"|="			{ cnt+=yyleng; return(OR_ASSIGN); }
">>"			{ cnt+=yyleng; return(RIGHT_OP); }
"<<"			{ cnt+=yyleng; return(LEFT_OP); }
"++"			{ cnt+=yyleng; return(INC_OP); }
"--"			{ cnt+=yyleng; return(DEC_OP); }
"->"			{ cnt+=yyleng; return(PTR_OP); }
"&&"			{ cnt+=yyleng; return(AND_OP); }
"||"			{ cnt+=yyleng; return(OR_OP); }
"<="			{ cnt+=yyleng; return(LE_OP); }
">="			{ cnt+=yyleng; return(GE_OP); }
"=="			{ cnt+=yyleng; return(EQ_OP); }
"!="			{ cnt+=yyleng; return(NE_OP); }
";"			{ cnt+=yyleng; return(';'); }
("{"|"<%")		{ cnt+=yyleng; makeList("{",'p',line); return('{'); }
("}"|"%>")		{ cnt+=yyleng; makeList("}",'p',line); return('}'); }
","			{ cnt+=yyleng; return(','); }
":"			{ cnt+=yyleng; return(':'); }
"="			{ cnt+=yyleng; return('='); }
"("			{ cnt+=yyleng; return('('); }
")"			{ cnt+=yyleng; return(')'); }
("["|"<:")		{ cnt+=yyleng; return('['); }
("]"|":>")		{ cnt+=yyleng; return(']'); }
"."			{ cnt+=yyleng; return('.'); }
"&"			{ cnt+=yyleng; return('&'); }
"!"			{ cnt+=yyleng; return('!'); }
"~"			{ cnt+=yyleng; return('~'); }
"-"			{ cnt+=yyleng; return('-'); }
"+"			{ cnt+=yyleng; return('+'); }
"*"			{ cnt+=yyleng; return('*'); }
"/"			{ cnt+=yyleng; return('/'); }
"%"			{ cnt+=yyleng; return('%'); }
"<"			{ cnt+=yyleng; return('<'); }
">"			{ cnt+=yyleng; return('>'); }
"^"			{ cnt+=yyleng; return('^'); }
"|"			{ cnt+=yyleng; return('|'); }
"?"			{ cnt+=yyleng; return('?'); }


"#include"(.)*"\n"	{ cnt=0;line++; }
"#define"(.)*"\n"	{ cnt=0;line++; }

[ ]			{cnt+=yyleng;}
[\t\v\f]		{ cnt+=yyleng; }
[\n]			{line++;cnt=1;}
.			{ }

%%
yywrap()
{
	return(1);
}

void insert(char *yytext)
{
  int len = strlen(yytext);
  tempid = (char*)malloc((len+1)*sizeof(char));
  strcpy(tempid, yytext);
}

