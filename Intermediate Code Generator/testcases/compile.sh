#!/bin/sh
lex lexicalAnalyzer.l
yacc -d syntaxChecker.y
gcc lex.yy.c y.tab.c icg.c -w -g
./a.out case5.c
rm y.tab.c y.tab.h lex.yy.c
