#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

int main()
{
	int x = 1;
	//Pointer sign -> (*)
	int* p1;
	// & gives adress in memory
	p1 = &x;
	//Will print adress of x in memory
	printf("%d\n",p1);
	//You can also get data using (*) before pointer:
	printf("%d\n", *p1);
	//You can also change value of x using pointer:
	*p1 = 8;
	printf("%d", x);
	return 0;

}