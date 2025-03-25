#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//a^x = b
int main()
{
	float a, b;
	printf("Given the equation a^x = b\n");
	printf("Enter a and b, respectievly please: ");
	scanf("%f %f", &a, &b);
	double x = log(b)/log(a);
	printf("x is: %g", x);
	return 0;
}