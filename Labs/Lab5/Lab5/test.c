#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void test(int* a);

int main()
{
	char a[2] = { 'A','B' };
	printf("%c", *a);
	test(a);
	return 0;
}

void test(char* a)
{
	char* p;
	printf("%c", *a);
	p = a;
	*p = 'Z';
	printf("\n%c\n", *p);
	printf("%c", a);
}