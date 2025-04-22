#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 100

void replaceSubstring(char* str, char* substr);
void replaceEnter(char* str);

int main()
{
	char str[N], substr[N];

	// Will check if str and substr is not empty
	while (1)
	{
		// Get text 
		printf("Enter text: ");
		fgets(str, N, stdin);
		// Replace enter if used to \0
		replaceEnter(str);
		if (*str == '\0') break;

		// Get substring
		printf("Enter substring: ");
		fgets(substr, N, stdin);
		// Replace enter if used to \0
		replaceEnter(substr);
		if (*substr == '\0') break;
	
		// Call replace func and print result
		replaceSubstring(str, substr);
		printf("%s\n", str);
	}
	printf("Finish");
	return 0;
}

// This function will replace Enter to \0 if enter was used
void replaceEnter(char* str)
{
	int len;

	// check length of string
	len = strlen(str);
	// Replace \n to \0
	if (str[len - 1] == '\n') str[len - 1] = '\0';
}


// This function will replace each part of the string 
// Each part of the string that equal to substring will become upper letters
void replaceSubstring(char* str, char* substr)
{
	int i = 0, j = 0, len, sublen;
	char* pos;
	len = strlen(str);
	sublen = strlen(substr);

	for (i; i < len-1; i++)
	{
		pos = strstr(str, substr);
		if (pos != NULL)
		{
			for (j; j < sublen; j++)
			{
				*pos -= 32;
				pos++;
			}
			j = 0;
		}
	}
}