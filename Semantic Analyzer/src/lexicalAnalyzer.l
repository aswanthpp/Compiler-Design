%{
#include <stdio.h>
#include "y.tab.h"
int lineCount=1;
int nestedCommentCount=0;
int commentFlag=0;
char *tablePtr;
void addToken(char*);
%}

digit			[0-9]
letter			[a-zA-Z_]
hex			[a-fA-F0-9]
E			[Ee][+-]?{digit}+
FS			(f|F|l|letter)
IS			(u|U|l|letter)*

singlelineComment (\/\/.*)
multilineCommentStart (\/\*)
multilineCommentEnd (\*\/)
%x DETECT_COMMENT

%%


{singlelineComment}      		{ lineCount++; }

{multilineCommentStart}            	{ BEGIN(DETECT_COMMENT);
					  nestedCommentCount++; 
					}
					
<DETECT_COMMENT>{multilineCommentStart} { nestedCommentCount++;
					  if(nestedCommentCount>1)
					  	commentFlag = 1;
					}
					
<DETECT_COMMENT>{multilineCommentEnd} 	{ BEGIN(INITIAL); lineCount++;
						 if(nestedCommentCount>0)
                                			nestedCommentCount--;
                            			if(nestedCommentCount==0)
                            				BEGIN(INITIAL);
                    			}
                    			
<DETECT_COMMENT>\n 		{lineCount++;}
<DETECT_COMMENT>. 		{}




"auto"			{  return(AUTO); }
"break"			{  return(BREAK); }
"case"			{  return(CASE); }
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
"union"			{  return(UNION); }
"unsigned"		{  return(UNSIGNED); }
"void"			{  return(VOID); }
"volatile"		{  return(VOLATILE); }
"while"			{  return(WHILE); }

{letter}({letter}|{digit})*		{  addToken(yytext); return(IDENTIFIER); }
{letter}?\"(\\.|[^\\"])*\"		{  addToken(yytext); return(STRING_LITERAL); }

0[xX]{hex}+{IS}?			{  addToken(yytext); return(CONSTANT); }
0{digit}+{IS}?				{  addToken(yytext); return(CONSTANT); }
{hex}+{IS}?				{  addToken(yytext); return(CONSTANT); }
{letter}?'(\\.|[^\\'])+'		{  addToken(yytext); return(CONSTANT); }
{digit}+{E}{FS}?			{  addToken(yytext); return(CONSTANT); }
{digit}*"."{digit}+({E})?{FS}?		{  addToken(yytext); return(CONSTANT); }
{digit}+"."{digit}*({E})?{FS}?		{  addToken(yytext); return(CONSTANT); }

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
("{"|"<%")		{  makeList("{",'p',lineCount); return('{'); }
("}"|"%>")		{  makeList("}",'p',lineCount); return('}'); }
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


"#include"(.)*"\n"	{ lineCount++; }
"#define"(.)*"\n"	{ lineCount++; }

[ ]			{}
[\t\v\f]		{}
[\n]			{lineCount++;}
.			{ }

%%
yywrap()
{
	return(1);
}

void addToken(char *yytext)
{
  int len = strlen(yytext);
  tablePtr = (char*)malloc((len+1)*sizeof(char));
  strcpy(tablePtr, yytext);
}

