#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Error_Msg(char *str);
void NewInput(FILE *old, FILE *new);

int main()
{

    FILE *in, *out;

    if ((in = fopen("Students.txt", "r")) == NULL)
        Error_Msg("The input file is wrong");
    if ((out = fopen("StudentsNew.txt", "w")) == NULL)
        Error_Msg("The output file is wrong");

    // Append all relevant info to new doc
    NewInput(in,out);
    
    fclose(in);
    fclose(out);
    return 0;
}

// Thif function will print error message and stop program
// Input will be printed as error
void Error_Msg(char *str)
{
    printf("\n%s", str);
    exit(1);
}

// This function will print inside new document only information about specific group
void NewInput(FILE *old, FILE *new)
{
    char tempName[7], tempGroup[5], tempGrade[4]; // Will store the name until Group checked
    int num;
    fseek(old, 0, 0);               // Put pointer to starter position
    while(fgets(tempName, 7, old) != NULL)
    {
        num = 0; // Reset Number
        fgets(tempGroup, 5, old); // Get temp Group
        fgets(tempGrade,4,old); // Get first temp Grade
        num += atoi(tempGrade);
        fgets(tempGrade,4,old); // Get second temp Grade
        num += atoi(tempGrade);
        
        if(strcmp(tempGroup,"Comp") == 0)
        {
            fprintf(new,"%s %0.2f\n", tempName, (float)num/2);
        }
    }
}