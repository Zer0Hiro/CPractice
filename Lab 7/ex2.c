#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud
{
    char *name;
    int marks[4];
    float avg;
} student;

student *Create_Class(int);
void Avg_Mark(student *);
void Print_One(student *);

int main()
{
    int size, i;
    student *arr;
    printf("\nEnter the number of students:");
    scanf("%d", &size);
    arr = Create_Class(size);
    return 0;
}

student *Create_Class(int size)
{
    char str[50];
    int i, j;

    student *clp = (student *)malloc(sizeof(student) * size);
    if (clp == NULL)
    {
        printf("Not enough memory\n");
        exit(-1);
    }

    // Fill student array
    for (i = 0; i < size; i++)
    {
        // Get name of student
        printf("Enter name of student: ");
        scanf("%s", str);
        clp[i].name = (char *)malloc(strlen(str) + 1);
        if (clp[i].name == NULL)
        {
            printf("Not enought memory\n");
            for (j = 0; j < i; j++)
                ;
            free(clp[j].name);
            free(clp);
            exit(-1);
        }
        strcpy(clp[i].name, str);

        // Get grades of the student
        printf("Enter the 4 grades of student: ");
        for (j = 0; j < 4;)
        {

            if (scanf("%d", clp[i].marks[j]) != 1)
            {
                printf("Wrong input try again");
                j = 0;
                break;
            }
            i++;
        }

        // Compute Average number 
        Avg_Mark(clp);
    }

    return clp;
}

void Avg_Mark(student *s)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        s->avg += s->marks[i];
        s->avg /= 4;
    }
}

void Print_One(student *s)
{
    printf("The average of %s is %.1f", s->name, s->avg);
}
