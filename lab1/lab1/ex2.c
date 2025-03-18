#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i,k;
	char x =  '*';
	
	printf("We are drawing Triangle:\n");

	for (i = 0; i < 5; i++){
		if (i > 0) {
			printf("%c", x);
			for (k = i - 1; k > 0;k--) {
				printf(" ");
			}
		}
		printf("%c\n", x);
			
	}
	printf("%c%c%c%c%c%c", x, x, x, x, x, x);
	return 0;
}