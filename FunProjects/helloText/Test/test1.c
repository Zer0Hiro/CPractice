#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  

typedef struct Database
{
    char* name;
    int* age;
    int* weight;
    int* height;

}Database;

void tablePrint(int len, int widgth);

int main()
{
    int length = 30, choise = 50, widgth = 3;
    int padding;
    char* title = "WELCOME TO THE LIST CREATOR"; 

    padding = (length - strlen(title)) / 2; 
    printf("WELCOME TO THE LIST CREATOR\n");
    for(int i = 0; i < length; i++)
        printf("%c",219);
    scanf("%d", &choise);
    return 1;
}


void tablePrint(int len, int widgth)
{

}