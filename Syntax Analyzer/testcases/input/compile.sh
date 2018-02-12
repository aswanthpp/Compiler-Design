#!/bin/sh
lex lexicalAnalyzer.l
yacc -d syntaxChecker.y
gcc lex.yy.c y.tab.c -w -g
./a.out case1.c
rm y.tab.c y.tab.h lex.yy.c
