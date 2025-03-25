#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch;
	printf("Enter an English lower case letter, please: ");
	scanf("%c", &ch);
	printf("The ascii code of '%c' is %d.\n",ch,ch);
	printf("The ascii code of '%c' is %d.", (int)ch-32, (int)ch - 32);
	return 0;
}