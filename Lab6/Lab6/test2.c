#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NUMELEMS 7
#define R "\033[0m"
#define GREEN "\033[38;2;0;255;0m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define UNDERLINE "\033[4m"


char* findMin(char** arrP, int arrSize);

int main()
{
    char* a[] = { "Amos","Nir","Alona","Yosef","alice","Amina","bob" };
    int i;

    printf(UNDERLINE LIGHT_BLUE "Question 4\n\n" R);

    for (i = 0; i < NUMELEMS; i++)
        printf("%s\n", a[i]);
    printf(GREEN "\n%s\n" R, findMin(a, NUMELEMS));

    return 0;
}

// This function finds the lexicographically smallest element in any 'NUMELEMS' sized array.
char* findMin(char** arrP, int arrSize)
{
    int i;
    char* temp;

    // This loop uses "strcmp" to evaluate the current smallest element against the rest of the array.
    for (i = 0, temp = *arrP; i < arrSize; i++)
    {
        if (strcmp(temp, arrP[i]) > 0) temp = arrP[i];
    }
    return temp;
}
