#ifndef _EX3
#define _EX3

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int *Array;
    int size;
    int count;
} Stack, *PStack;

void InitStack(PStack s, int size);
void Push(PStack s, int new_elem);
int Pop(PStack s, int *del_value);

#endif