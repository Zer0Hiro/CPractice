#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int i=1,a,b;
	char ex;
	while (i != 0)
	{
		printf("Input Char:");
		rewind(stdin);
		scanf("%c", &ex);
		switch(ex)
		{
		case 'a': case 'A':
			printf("Enter 2 numbers");
			scanf("%d %d", &a, &b);
			printf("Average of numbers %d and %d is %f\n", a, b, (float)((a + b) / 2));
			break;
		case '*':
			printf("Enter 2 numbers");
			scanf("%d %d", &a, &b);
			printf("Multiply of numbers %d and %d is %f\n", a, b, (float)(a * b));
			break;
		case 'm':
			printf("Enter 2 numbers");
			scanf("%d %d", &a, &b);
			printf("smallest of numbers %d and %d is %d\n", a, b, (a>b)?b:a);
			break;
		case '^':
			printf("Enter 2 numbers");
			scanf("%d %d", &a, &b);
			printf("^ of numbers %d and %d is %f\n", a, b, pow(a,b));
			break;
		case 'q': case 'Q':
			printf("Finish");
			i = 0;
			break;
		default:
			printf("Error");
			break;
		}
	}
}