#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f_x();

//GLOBAL VALUE


//LOCAL VALUE

//STATIC VALUE
void f_x()
{
	static int cnt = 1;
	printf("%d", cnt);
	cnt = cnt + 1;

}
