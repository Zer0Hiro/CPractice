#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, k;
	char x = '*';
	int h = 10;
	printf("We are drawing Triangle:\n");
	printf("%c\n", x);
	for (i = 1; i < h; i++) {
		printf("%c", x);
		for (k = i - 1; k > 0;k--) {
			printf(" ");
		}
		printf("%c\n", x);
		if (i == h - 1) {
			for (int j = 0;j < h + 1;j++) {
				printf("%c", x);
			}
		}
	}
	//printf("%c%c%c%c%c%c", x, x, x, x, x, x);
	return 0;


}