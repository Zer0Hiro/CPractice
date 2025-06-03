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
void FreeAll(Node *head);
int Jumpy(Node **head, Node **tail, int amount);
void ErrorMsg(char *msg);
int RemoveBlock(Node **pos, Node **head, Node **tail, int direction);
void JumpDir(Node **pos, int direction);
void PrintResult(Node *head);

#endif // End of Header
