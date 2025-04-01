#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int i, num, res, count = 0;
	//assign user value to 'num', while defining 'i' & 'count'
	printf("Enter an integer number, please: ");
	scanf("%d", &num);
	res = abs(num);

	if (num == 0)
	{
		printf("Infinity");
		return 0;
	}

	//loop that check all dividers 
	for (i = 1; i < res; i++)
	{
		if ((res % i) == 0)
		{
			count++;
			printf("%d ", i);
		}

	}

	//If number is negative adds additional divider
	if (num < 0)
	{
		count++;
		printf("%d", res);
	}
	//counts all dividers 
	printf("\ncount=%d", count);
	return 0;
}