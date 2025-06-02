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
void CreateLink(Node **head, Node **tail, int size, int *numbers);
int RemoveBlock(Node **pos, Node **head, Node **tail, int direction);
int Jumpy(Node **head, Node **tail, int amount);
void JumpDir(Node **pos, int direction);
void FreeAll(Node *head);
void ErrorMsg(char *msg);
void PrintResult(Node *head);


#endif // End of Header
