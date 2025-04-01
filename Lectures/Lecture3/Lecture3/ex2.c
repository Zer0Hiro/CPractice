#define _CRT_SECURE_NO_WARNIGS
#include <stdio.h>

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a = 5, b = 10;
	printf("%d %d\n", a, b);
	swap(&a, &b); //Send adress to func
	printf("%d %d\n", a, b);
	return 0;
}