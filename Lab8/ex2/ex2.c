#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int grades[3];
} student;

void Error_Msg(char *);
int InputData(student **, FILE *);
void OutputData(int, student *, FILE *);

int main()
{
    FILE *fp;
    student *arr;
    int size;

    if ((fp = fopen("Students.txt", "r")) == NULL)
        Error_Msg("The input file is wrong");
    size = InputData(&arr, fp);
    fclose(fp);
    if ((fp = fopen("Students.txt", "w")) == NULL)
    {
        free(arr);
        Error_Msg("The output file is wrong");
    }
    OutputData(size, arr, fp);
    fclose(fp);

    return 0;
}

int InputData(student **p_array, FILE *fp)
{
    student *arr, *temp;
    int i = 1;

    arr = (student *)malloc(sizeof(student));

    while (fscanf(fp, "%s %d %d %d", arr[i - 1].name, &arr[i - 1].grades[0], &arr[i - 1].grades[1], &arr[i - 1].grades[2]) != EOF)
    {
        i++;
        temp = (student *)realloc(arr, i * sizeof(student));
        if (temp == NULL)
        {
            free(temp);
            Error_Msg("Memory error");
        }
        arr = temp;
    }

    *p_array = arr;

    return i; /*return the number of students*/
}

void OutputData(int arr_size, student *arr, FILE *fp)
{
    int i, j;
    int biggest = 0;
    for (i = 0; i < arr_size; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i].grades[j] > arr[i].grades[biggest])
                biggest = j;
        }
        fprintf(fp, "%s %d\n", arr[i].name, arr[biggest].grades);
    }
}

void Error_Msg(char *msg)
{
    printf("\n%s", msg);
    exit(1);
}