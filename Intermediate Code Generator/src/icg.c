#include "icg.h"
#include "y.tab.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>



CodeLineEntry *codeLines = NULL;
SymbolTableEntry *symbolTable = NULL;

CodeLineEntry *codeLineHead = NULL;

extern int yylineno;
extern int yyin;

int currentLine = -1;

void yyerror() {
    printf("ERROR\n");
}

int main(int argc, char **argv) {
    yyin = fopen(argv[1],"r");
    yyparse();
    FILE *symPtr = fopen("symbolTable.txt", "w");
    printSymbolTable(symPtr);
    FILE *codePtr=fopen("icgCode.txt","w");
    printCode(codePtr);
    fclose(symPtr);
    fclose(codePtr);
    return(0);
}


CodeLineEntry *genquad(char *code){
	// make new code line entry 
	// append it to codeLines pointer and return it
}

void backpatch(BackpatchList* list, int gotoL){
	// back patch line number gotoL with the list 
}


BackpatchList* addToList(BackpatchList* list, CodeLineEntry* entry){
	// appending new code line entry to the back patch list
}

SymbolTableEntry* addSymbol(const char *name,TOKEN_TYPE type,TOKEN_DATA_TYPE internalType,unsigned long line,char *parent,unsigned long parameter)
{
    //adding symbol to the symbol table pointer symbolTable
}

bool writeCode(FILE *outputFile)
{  // write three address code in 
}
bool writeSymbolTable(FILE *outputFile)
{   // writre symbol Table
}


