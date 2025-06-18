#ifndef _EX2
#define _EX2

#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int num;
    struct Item *next;
} Item;

typedef struct Que
{
    Item *head, *tail;
    int size;
} Queue, *PQue;

void Enqueue(PQue Q, int new_elem);
int Dequeue(PQue Q, int *del_value);
void FreeQueue(PQue Q);
void PrintQueue(PQue Q);

#endif
