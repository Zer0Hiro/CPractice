#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define NUMELEMS 7

char* findMin(char** arrP, int arrSize);


int main()
{
	char* a[] = { "Alona","Nir","Amina","Yosef","alice","Amos","bob" };
	int i;

	for (i = 0; i < NUMELEMS; i++)
		printf("%s\n", a[i]);
	printf("\n%s", findMin(a, NUMELEMS));

	return 0;
}


char* findMin(char** arrP, int arrSize)
{
	int i;
	char* temp;


	for (i = 0, temp = *arrP; i < arrSize; i++)
	{
		if (strcmp(temp, arrP[i]) > 0) temp = arrP[i];
	}
	return temp;
}