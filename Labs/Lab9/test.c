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
} Libr;

int main()
{
   char tempName[99];

   Book *B;
   FILE *in;
   
   in = fopen("input.txt","rt");


	fscanf(in, "%s", &B->code);	 // Get Code of the book
	fscanf(in, "%s", &tempName); // Get Name of the book
	if((B->name = (char *)malloc(strlen(tempName))) == NULL)
	{
		free(B->name);
		//Error_Msg("Memory Allocation error");
	}
	strcpy(B->name, tempName);
   printf("%s", B->name);
}