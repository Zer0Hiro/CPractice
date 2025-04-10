#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 20

int digitizer(char arr[]);

int main()
{
	char message[] = "";
	
	printf("Enter you number (Using words)\nBetween zero - one billion (not included)\n(For example: three hundred)\nInput:");
	fgets(message, SIZE, stdin);
	printf("The number is: %d", digitizer(message));
	return 1;
}

// This function transform words to number
int digitizer(char arr[])
{
	char* units_words[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char* teens_words[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char* tens_words[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char* format_words[] = { "hundred", "thousand", "million"};
	int* units[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* teens[] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	int* tens[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int* format[] = { 100, 1000, 1000000 };
	char *words[SIZE];
	int i = 0, k, j;

	// Allow to split string to parts
	char* word_token = strtok(arr, " ");
	while (word_token != NULL)
	{
		// Stores each word
		words[i++] = word_token;
		// Gets next word from input
		word_token = strtok(NULL, " ");
	}

	for (k = 0; k < SIZE ;)
	{
		for(j = 0; j< 10; )
	}
	return 0;

	
}