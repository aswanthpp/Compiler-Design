#!/bin/bash
lex scanner.l
cc lex.yy.c
./a.out
vim table.txt
