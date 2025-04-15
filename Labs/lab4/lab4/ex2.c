#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int InputThree(int*, int*, int*);
void SortTwo(int*, int*);
void SortThree(int*, int*, int*);

int main()
{
	int a, b, c;
	while (InputThree(&a,&b,&c) != 0)
	{
		SortThree(&a, &b, &c);
		printf("%d %d %d", a, b, c);
	}
}

// This function gets 3 numbers
int InputThree(int* p1, int* p2, int* p3)
{
	int check = 1;
	printf("\nInput 3 numbers: ");
	if (scanf("%d %d %d", p1, p2, p3) != 3) check = 0;
	return check; // 1 == True , 0 == False
}

// This function will sort 2 numbers p2 will be bigest and p1 smallest number
void SortTwo(int* p1, int* p2)
{
	int temp = *p2;
	if (*p1 > *p2)
	{
		*p2 = *p1;
		*p1 = temp;
	}
}

// This function will sort all 3 numbers from lowest to biggest 
void SortThree(int* q1, int* q2, int* q3)
{
	SortTwo(q1, q2);
	SortTwo(q1, q3);
	SortTwo(q2, q3);
}