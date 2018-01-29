%{
#include "y.tab.h"
%}
digit  [0-9]
letter  [a-zA-Z]
%%

"auto" { return AUTO;}
"break" { return BREAK;}
"case" { return CASE;}
"char" {return CHAR;}
"const" { return CONST;}
"continue" { return CONTINUE;}
"default" { return DEFAULT;}
"do" { return DO;}
"double" { return DOUBLE;}
"else" { return ELSE;}
"enum" { return ENUM;}
"extern" { return EXTERN;}
"float" { return FLOAT;}
"for" { return FOR;}
"goto" { return GOTO;}
"if" { return IF;}
"int" { return INT;}
"long" { return LONG;}
"register" { return REGISTER;}
"return" { return RETURN;}
"short" { return SHORT;}
"signed" { return SIGNED;}
"sizeof" { return SIZEOF;}
"static" { return STATIC;}
"struct" { return STRUCT;}
"switch" { return SWITCH;}
"typedef" { return TYPEDEF;}
"union" { return UNION;}
"unsigned" { return UNSIGNED;}
"void" { return VOID;}
"volatile" { return VOLATILE;}
"while" { return WHILE;}

{letter}({letter}|{digit})* {return IDENTIFIER;}


"\-\=" {return MINUS_ASSIGN;}



"\"" {return DOUBLE_QUOTE;}
"\'" {return SINGLE_QUOTE;}

.	{return yytext[0];}
\n	{return 0;}
