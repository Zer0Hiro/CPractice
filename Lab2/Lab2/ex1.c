#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int num;
	printf("Enter number: ");
	//Input for number
	scanf("%d", &num);
	printf("\nNumber\tSquare\tCube\n");
	//Print columns of 4 following numbers
	printf("%6d%6d%8d\n", num, (int)pow(num, 2), (int)pow(num, 3));
	printf("%6d%6d%8d\n", num + 1, (int)pow(num + 1, 2), (int)pow(num + 1, 3));
	printf("%6d%6d%8d\n", num + 2, (int)pow(num + 2, 2), (int)pow(num + 2, 3));
	printf("%6d%6d%8d\n", num + 3, (int)pow(num + 3, 2), (int)pow(num + 3, 3));
	printf("%6d%6d%8d\n", num + 4, (int)pow(num + 4, 2), (int)pow(num + 4, 3));
	return 0;
}