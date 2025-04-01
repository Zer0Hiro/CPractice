#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 1, b = 2, * p1, * p2;
	p1 = &a;
	b = *p1;
	p2 = &b;
	a = a + *p1;
	*p1 = *p2;
	printf("%d", *p1);
	return 0;
}