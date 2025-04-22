#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	void* p;
	int a;
	float b;
	p = &a;
	// Error because we need to use casting on *p
	// *p = 4;
	*(int*)p = 4;
	// Same with float
	p = &b;
	*(float*)p = 4.5;
}
