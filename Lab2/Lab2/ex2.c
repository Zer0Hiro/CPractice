#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float l, h, area;
	printf("Enter a triangle edge and its height respectievly, please: ");
	scanf("%f %f", &l, &h);
	area = 0.5 * l * h;
	printf("\nThe triangle area is %0.3f", area);

}