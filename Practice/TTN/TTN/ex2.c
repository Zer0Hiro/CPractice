#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void changeBetween(char* str1);

int main()
{
	char str[10];
	fgets(str, 10, stdin);
	changeBetween(str);
	printf("%s", str);
	return 1;
}

void changeBetween(char* st1)
{
	int i, count = 0;

	
	for (i = 0; st1[i] != "\0"; i++)
	{
		if (st1[i] >= 'A' && st1[i] <= 'Z')
		{
			count++;
			if (count == 2) break;
		}
		else
		{
			if (count == 1) st1[i] = st1[i] - ('a' - 'A');
		}
		

	}
}