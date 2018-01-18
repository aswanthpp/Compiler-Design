#!/bin/bash
lex scanner.l
cc lex.yy.c
./a.out input.c
vim table.txt
