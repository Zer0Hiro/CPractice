#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Includes Sleep function
#include <windows.h>  
// Includes console clear function
#include <stdlib.h>



void TextCreator(char arr[], int);

int main()
{
	char arr[100];
	printf("Enter the string (not more than 100 symbols)");
	fgets(arr, 100, stdin);
	//printf("%d", sizeof(arr));
	TextCreator(arr, strlen(arr));
	return 110;
}

// This function will create sliding text creator
void TextCreator(char arr[], int size)
{
	int i, ascii = 97;
	char word[100] = { ' ' };
	for (i = 0; i < size;)
	{	
		// ascii = 97 - 122 , 65 - 90 , 32 - 64 
		if (arr[i] == (char)ascii)
		{
			word[i] = (char)ascii;
			i++;
			ascii = 97;
		}
		if (ascii == 122 || ascii == 90 || ascii == 64)
		{
			switch (ascii)
			{
			case 122:
				ascii = 64;
				break;
			case 90:
				ascii = 31;
				break;
			case 64:
				printf("Error");
				break;
			default:
				printf("Error");
				break;
			}
		}
		//system("cls");
		if (i != size) printf("%s%c\n", word, (char)ascii);
		else break;
		Sleep(10);
		ascii++;
	}
}


