#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 5

typedef struct s1
{
	int x;
	int y;
}s1;

typedef struct s2
{
	s1 s;
	int z;
}s2;

// Now we can get in s1 from s2

int main()
{
	struct s2 a;
	a.s.x = 5;
	return 0;
}