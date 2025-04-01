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

void f(char tav, int num)
{
	int i,k;
	for (i = num; i > 0; i--)
	{
		for (k = num; k > 0; k--)
		{
			putchar(tav);
		}
		num--;
		printf("\n");
	}
}