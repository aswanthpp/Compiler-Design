#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#define PARENT_NONE NULL

typedef enum
{
     BOOL_type,
    INT_type,
    FLOAT_type,
     FUNC,
     MAIN,
     PROTO,
} tokenType;

typedef enum
{
    Return_VOID,
    Return_INT,
    Return_FLOAT
    
} tokenReturnType;

typedef enum
{
	CONST_type,
	VAR_type,
	NONE_type
	
} tokenConstType;



struct tokenList
{
    char *name;
    tokenType type;
    tokenReturnType returnType;
    long size;
    char *scope;
    long line;
    long parameter;
    
    struct tokenList *next;
    
};
typedef struct tokenList tokenList;


struct threeAddressCode
{
    char *code;
    int gotoLine;

    struct threeAddressCode *next;
    
};
typedef struct threeAddressCode threeAddressCode;

struct backPatchList 
{
    threeAddressCode   *entry;
    struct backPatchList  *next;

};
typedef struct backPatchList   backPatchList ;


threeAddressCode* appendCode(char *code);
void backpatch(backPatchList * list, int gotoL);
backPatchList* mergelists(backPatchList  * a, backPatchList  * b);
backPatchList* appendToBackPatch(backPatchList  * list, threeAddressCode  * entry);
tokenList* appendToSymbolTable(char *name,tokenType type,tokenReturnType returnType,long size,long line,char *scope,long parameter);
void writeCode(FILE *icgOut);
void writeSymbolTable(FILE *symOut);

tokenList * addSymbolToParameterQueue(tokenList * queue, char *name, tokenType type);


int checkAndGenerateParams(tokenList * queue, char* name ,int parameterCount);

int getFunctionType(char *name);

int getSymbolType(char *name);

char* nextFloatVar();

char* nextIntVar();

char* nextBoolVar();

int nextquad();
  
void addFunction(char *name, unsigned int parameter_count, tokenReturnType  ret_type, int line);

tokenList * lookup(char *name);

extern tokenList *symbolTable;
