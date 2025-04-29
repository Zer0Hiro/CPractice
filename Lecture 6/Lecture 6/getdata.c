#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 5

typedef struct student
{
	char first_name[8];
	char last_name[8];
	int marks[3]; 
}student;

void get_data(student* arr, int size);
void print_average(student* p, int size);

int main()
{
	student array[NUM]; 
	get_data(array, NUM); // Get all data 
	print_average(array, NUM); //Will print the average mark of person
	return 0;
}

void get_data(student* arr, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		printf(" \n please enter data for student’s name\n");
		scanf("%s%s", arr[i].first_name, arr[i].last_name); // Get name and last name
		printf("\n please enter data for 3 marks\n");
		
		// Get all marks
		for (j = 0; j < 3; j++)
			scanf("%d", &arr[i].marks[j]);
	}
}

void print_average(student* p, int size)
{
	int i, j, sum;
	for (i = 0; i < size; i++, p++)
	{
		for (j = 0, sum = 0; j < 3; j++) 
			sum += p->marks[j];
		printf("\n The average mark of %s %s is %f",
			p->first_name, p->last_name, (float)sum / 3);
	}
}