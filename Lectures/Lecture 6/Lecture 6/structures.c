#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Creates structure
struct structName
{
	int name1;
	float name2; // Doesn't take any memory
	// can't be equal to smth like: int name1 = 4;
	char name3;
}; // Always before main function

//Example
struct Person
{
	char name[10];
	int age;
	char address[20];
};


int main()
{
	//Now we can use struct items
	struct Person a,b; //Creates structure of type Person with name
	a.age = 10; // Also can be (&a) -> age
	scanf("%s", a.name);

	struct Person* p; // Can also get pointer
	p = &b; // Now P has adress of a in structure;
	p -> age = 13; // Now we can use pointer to send new data to struct
	// Also can be (*p).age = 25 same type shit
	return 0;
}