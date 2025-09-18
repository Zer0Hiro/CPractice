#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch = '@';
    for(int i= 0; i < 10; i++)
    {
        printf("%c\n",ch+i);
    }

    return 0;
}