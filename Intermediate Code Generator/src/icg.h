#include <stdbool.h>
#include <stdio.h>

typedef enum
{
    MAIN,
    FUNC,
    PROTO,
    ARRAY,
} TOKEN_TYPE;

typedef enum
{
    NONE,
    INT,
    FLOAT,
    BIN
    
} TOKEN_DATA_TYPE;

typedef enum
{
	CONSTANT,
	IDENTIFIER,
	NONE
} TOKEN_CONST_TYPE;

struct symbolTableEntry
{
    char                     *name;
    TOKEN_TYPE               type;
    TOKEN_DATA_TYPE           dataType;
    long                      line;
    char                     *parent;
    unsigned long             parameter;
    
    struct symbolTableEntry *next;
    
};
typedef struct symbolTableEntry SymbolTableEntry;

struct icgEntry
{
    char *code;
    
    int gotoL;

    struct icgEntry *next;
    
};
typedef struct icgEntry icgLineEntry;

struct backpatchList
{
    icgLineEntry *entry;

    struct backpatchList *next;

};
typedef struct  backpatchList BackpatchList;

CodeLineEntry *genquad(char *code);

SymbolTableEntry* addSymbol(const char *name,TOKEN_TYPE type,TOKEN_DATA_TYPE internalType,unsigned long line,char *parent,unsigned long parameter);

void backpatch(BackpatchList* list, int gotoL);

BackpatchList* addToList(BackpatchList* list, CodeLineEntry* entry);

bool writeCode(FILE *outputFile);
bool writeSymbolTable(FILE *outputFile);




