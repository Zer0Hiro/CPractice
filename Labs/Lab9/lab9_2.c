#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 256

typedef struct
{
	char code[10];
	char *name;
} Book;

typedef struct
{
	char name[MAX];
	int size;
	Book *shelf;
} Library;

int input_book(Book *B, FILE *in);
void input_library(Library *L, FILE *in);
void output_book(Book *B, FILE *out);
void output_library(Library *L, FILE *out);
void Error_Msg(char *errorMsg);

int main()
{
	FILE *in, *out;
	Library Libr;
	int i;

	// Open Files
	if ((in = fopen("input.txt", "r")) == NULL)
		Error_Msg("The input file is wrong");
	if ((out = fopen("output.txt", "w")) == NULL)
		Error_Msg("The output file is wrong");

	// Copy all info
	input_library(&Libr, in);
	fclose(in);

	// Paste all relevant info
	output_library(&Libr, out);
	fclose(out);

	// Free memory end of program
	for (i = 0; i < Libr.size; i++)
	{
		free(Libr.shelf[i].name);
	}
	free(Libr.shelf);
	
	return 0;
}

// This function will create shelf with books in Library
void input_library(Library *L, FILE *in)
{
	int i, j;

	// Get Name and amount of library respectievly
	if (fscanf(in, "%s %d", L->name, &L->size) != 2)
		Error_Msg("Input Error");

	// Allocate space for shelf in Library
	if ((L->shelf = (Book *)malloc(sizeof(Book) * L->size)) == NULL)
	{
		Error_Msg("Memory Error");
	}

	// Fill with books
	for (i = 0; i < L->size; i++)
	{
		// If not enough space in memory
		if (input_book(&L->shelf[i], in) == 0)
		{
			// Free memory from books
			for (j = 0; j < i; j++)
			{
				free(L->shelf[j].name);
			}
			// Free memory from shelf blocks
			free(L->shelf);
			Error_Msg("Memory error");
		}
	}

}

// This funciton will add book to shelf of library
int input_book(Book *B, FILE *in)
{
	char tempName[99];
	// Get Code and Name of the book respectievly
	if (fscanf(in, "%s %s", B->code, tempName) != 2)
		return 0;

	// Allocate memmory for name
	if ((B->name = (char *)malloc(strlen(tempName) + 1)) == NULL)
		return 0;

	// Copy name to allocated memory
	strcpy(B->name, tempName);
	return 1;
}

void output_library(Library *L, FILE *out)
{
	int i;
	// Print name of Library
	fprintf(out,"%s\n", L->name);


	// Print books
	for(i = 0; i < L->size; i++)
	{
		output_book(&L->shelf[i], out);
	}
}

// This function will print book and credentials inside doc
void output_book(Book *B, FILE *out)
{
	// Print Code and Book inside doc
	fprintf(out, "%-10s %s\n", B->code, B->name);
}

// This function will write error that you specify
void Error_Msg(char *errorMsg)
{
	printf("\n%s\n", errorMsg);
	exit(1);
}