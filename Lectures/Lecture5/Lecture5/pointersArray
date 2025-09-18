#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Includes memory allocation
#include <stdlib.h>

int main()
{
    // You can create array of pointer using malloc
    int **p;
    int n = 7; // Size of array
    p = (int **)malloc(n * sizeof(int *));
    //------ all part of malloc
    
    //You can use this array to get even more arrays inside
    int k = 5;
    p[0] = (int*)malloc(k*sizeof(int)); 
}