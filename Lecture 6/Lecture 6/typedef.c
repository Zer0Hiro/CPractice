#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Person
{
	int age;
	char name[10];
};

typedef struct Person newName; // Old name to new name

// Second way to do that
typedef struct Test
{
	char say[10];
}Test; // Gives new name for struct and allows to get access faster 


int main()
{
	newName a;
	Test b;
}