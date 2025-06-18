#ifndef _EX1
#define _EX1

#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int num;
    struct Item *next;
} Item;

typedef struct Stack
{
    Item* head;
    int size; 
} Stack, *PStack;

void Push(PStack s, int new_elem);
int Pop(PStack s, int *del_value);
void PrintPush(PStack s);
void FreeStack(PStack s);

#endif