#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int i, num,count=0;
	printf("Enter an integer number, please: ");
	scanf("%d", &num);
	num = abs(num);
	if (num == 0)
	{
		printf("Infinity");
		return 0;
	}
	for (i = 1; i < num; i++)
	{
		if ((num % i) == 0)
		{
			count++;
			printf("%d ", i);
		}
			
	}
	printf("\ncount=%d", count);
	return 0;
}