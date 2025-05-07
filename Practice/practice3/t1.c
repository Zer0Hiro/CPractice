#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pointer;
    pointer = fopen("test.txt", "w+");
    char input[10] = {'1', '2', '3', '4', '5', '6', '7', '9'};
    fputs(input, pointer);
    fseek(pointer, 0, 2);
    int test = ftell(pointer);
    printf("%d", test);
    fputs("Hello, world!\n", stdout);
    return 0;
}