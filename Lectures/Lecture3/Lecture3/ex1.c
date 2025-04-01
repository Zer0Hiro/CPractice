#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

int main()
{
	int a = 4, x, * p_a;
	p_a = &a;
	//X will get a value from A:
	x = *p_a;
	//A will get a new value => a = 2:
	*p_a = x / 2;
	// a = a + 1:
	*p_a = *p_a + 1;
	return 0;
}