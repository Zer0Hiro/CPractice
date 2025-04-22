#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 6

int distance(char A[], char B[]);

int main()
{
	int i, strA[N], strB[N];
	
	for (i = 0; i < 2;)
	{

	}
	// Get first string
	printf("Enter the first string: ");
	fgets(strA, N, stdin);
	rewind(stdin);

	// Get second string
	printf("Enter the second string: ");
	fgets(strB, N, stdin);
	
	printf("The distance is: %d",distance(strA, strB));
	return 1;
}


// This function will check if there is a difference between 2 strings and return how many differences was detected
int distance(char A[], char B[])
{
	int i, count = 0;

	// Check if strings have equal length
	if (strlen(A) != strlen(B)) return -1;

	// Count how many chars different at the same spot in both stings
	for (i = 0; i < A[i] != '\0'; i++)
	{
		if (A[i] != B[i]) count++;
	}
	return count;
}