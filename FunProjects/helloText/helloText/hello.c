#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Includes Sleep function
#include <windows.h>  

void TextCreator(char arr[], int size);

int main()
{
	int size = 13;
	char arr[] = "Hello World!";
	TextCreator(arr, size);
	return 110;
}

// This function will create sliding text creator
void TextCreator(char arr[], int size)
{
	int i, ascii = 97;
	char word[13] = { ' ' };
	for (i = 0; i < size-1;)
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
		printf("%s%c\n", word, (char)ascii);
		Sleep(10);
		ascii++;
	}
}


