
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*


%{

#include <stdio.h>
#include "y.tab.h"
int line=1;
char *tempid;
void addToken(char*);
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




"auto"			{  return(AUTO); }
"break"			{   return(BREAK); }
"case"			{   return(CASE); }
"char"			{  return(CHAR); }
"const"			{  return(CONST); }
"continue"		{  return(CONTINUE); }
"default"		{  return(DEFAULT); }
"do"			{  return(DO); }
"double"		{  return(DOUBLE); }
"else"			{  return(ELSE); }
"enum"			{  return(ENUM); }
"extern"		{  return(EXTERN); }
"float"			{  return(FLOAT); }
"for"			{  return(FOR); }
"goto"			{  return(GOTO); }
"if"			{  return(IF); }
"int"			{  return(INT); }
"long"			{  return(LONG); }
"register"		{  return(REGISTER); }
"return"		{  return(RETURN); }
"short"			{  return(SHORT); }
"signed"		{  return(SIGNED); }
"sizeof"		{  return(SIZEOF); }
"static"		{  return(STATIC); }
"struct"		{  return(STRUCT); }
"switch"		{  return(SWITCH); }
"typedef"		{  return(TYPEDEF); }
"union"			{   return(UNION); }
"unsigned"		{   return(UNSIGNED); }
"void"			{   return(VOID); }
"volatile"		{   return(VOLATILE); }
"while"			{   return(WHILE); }

{L}({L}|{D})*		{  addToken(yytext); return(IDENTIFIER); }

0[xX]{H}+{IS}?		{  addToken(yytext); return(CONSTANT); }
0{D}+{IS}?		{  addToken(yytext); return(CONSTANT); }
{H}+{IS}?		{  addToken(yytext); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{  addToken(yytext); return(CONSTANT); }

{D}+{E}{FS}?		{  addToken(yytext); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{  addToken(yytext); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{  addToken(yytext); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{  addToken(yytext); return(STRING_LITERAL); }

"..."			{  return(ELLIPSIS); }
">>="			{  return(RIGHT_ASSIGN); }
"<<="			{  return(LEFT_ASSIGN); }
"+="			{  return(ADD_ASSIGN); }
"-="			{  return(SUB_ASSIGN); }
"*="			{  return(MUL_ASSIGN); }
"/="			{  return(DIV_ASSIGN); }
"%="			{  return(MOD_ASSIGN); }
"&="			{  return(AND_ASSIGN); }
"^="			{  return(XOR_ASSIGN); }
"|="			{  return(OR_ASSIGN); }
">>"			{  return(RIGHT_OP); }
"<<"			{  return(LEFT_OP); }
"++"			{  return(INC_OP); }
"--"			{  return(DEC_OP); }
"->"			{  return(PTR_OP); }
"&&"			{  return(AND_OP); }
"||"			{  return(OR_OP); }
"<="			{  return(LE_OP); }
">="			{  return(GE_OP); }
"=="			{  return(EQ_OP); }
"!="			{  return(NE_OP); }
";"			{  return(';'); }
("{"|"<%")		{  makeList("{",'p',line); return('{'); }
("}"|"%>")		{  makeList("}",'p',line); return('}'); }
","			{  return(','); }
":"			{  return(':'); }
"="			{  return('='); }
"("			{  return('('); }
")"			{  return(')'); }
("["|"<:")		{  return('['); }
("]"|":>")		{  return(']'); }
"."			{  return('.'); }
"&"			{  return('&'); }
"!"			{  return('!'); }
"~"			{  return('~'); }
"-"			{  return('-'); }
"+"			{  return('+'); }
"*"			{  return('*'); }
"/"			{  return('/'); }
"%"			{  return('%'); }
"<"			{  return('<'); }
">"			{  return('>'); }
"^"			{  return('^'); }
"|"			{  return('|'); }
"?"			{  return('?'); }


"#include"(.)*"\n"	{ line++; }
"#define"(.)*"\n"	{ line++; }

[ ]			{}
[\t\v\f]		{}
[\n]			{line++;}
.			{ }

%%
yywrap()
{
	return(1);
}

void addToken(char *yytext)
{
  int len = strlen(yytext);
  tempid = (char*)malloc((len+1)*sizeof(char));
  strcpy(tempid, yytext);
}

