#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char st[5] = "Hell";
	char *testi = st; 
	printf("%c\n", *testi);
	testi++;
	printf("%c\n",*testi);
	//printf("%d", a[0]);
	return 0;
}
