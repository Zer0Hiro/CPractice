#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f(char, int);

int main()
{
    int n;
    char ch;
    printf("Enter a character an integer, please: ");
    scanf("%c %d", &ch, &n);
    f(ch, n);
    return 0;
}

// Draws the triangle
void f(char tav, int num)
{
    int k;
    for (; num > 0; num--)
    {
        for (k = num; k > 0; k--)
        {
            putchar(tav);
        }
        printf("\n");
    }
}