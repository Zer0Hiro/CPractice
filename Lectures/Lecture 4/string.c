#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char st[5] = "Hell";
    char *testi = st;
    printf("%c\n", *testi);
    testi++; // Moves one char forward {H e l l o} -> {e l l o}
    printf("%c\n", *testi);
    return 0;
}

// STRCPY - copy string to another array

// STRLEN - check length of string (\0 not included) -> strlen + 1

// STRCAT - adds string from source to destination: "Hello" + "world" = "Helloworld"

/* STRCHR:
char *text = "example";
char *result = strchr(text, 'a');
printf("Found: %s\n", result);  // Will print: "ample"
*/

/* STRSTR
char *text = "The quick brown fox";
char *result = strstr(text, "quick");
printf("Found: %s\n", result);  // Will print: "quick brown fox"
*/ 

// STRCMP - char check
// IF char1 < char2 return <0
// IF char1 > char2 return >0
// IF char1 = char2 return 0


// Counts this way length of string
int my_strlen(char *st)
{
    int count = 0;
    while (*st != '\0')
    {
        count++;
        st++;
        return count;
    }
}

// YOU CAN FIND DIGIT THIS WAY:

int find_first_dig(char *st)
{
    int i;
    for (i = 0; st[i] != '\0'; i++)
    {
        if (isdigit(st[i])) // is digit() uses ctype.h library
            return i;
    }
    return -1; // No digit found
}