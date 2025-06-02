#ifndef FUNC_UTILS_H
#define FUNC_UTILS_H

// Include + Define
#include <stdlib.h>
#include <stdio.h>
#define N 10

// Structs 
typedef struct node
{
    int num;
    struct node *next;
    struct node *prev;
} Node;

// Functions
void CreateLink(Node**, Node**, int, int*);
void FreeAll(Node*);
int Jumpy(Node**, Node**, int);
void ErrorMsg(char*);
int RemoveBlock(Node**, Node**, Node**, int);
void JumpDir(Node**, int);
void PrintResult(Node*);

#endif // End of Header
