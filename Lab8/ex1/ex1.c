#include <stdio.h>
#include <stdlib.h>

typedef struct Person
{
    char ID[10];
    char F_name[11];
    char L_name[16];
    int Age;
    char Addr[51];
} Person;

void Error_Msg(char *);

int main()
{
    Person temp;
    FILE *in, *out;

    in = fopen("the_first.txt", "r");
    if (in == NULL)
    {
        Error_Msg("File Error");
    }
    out = fopen("the_second.txt", "w");
    if (in == NULL)
    {
        Error_Msg("File Error");
    }
    // Add all options to struct
    fscanf(in, "%s", temp.ID);
    fscanf(in, "%s", temp.F_name);
    fscanf(in, "%s", temp.L_name);
    fscanf(in, "%d", &temp.Age);
    fscanf(in, "%s", temp.Addr);

    // Insert it to new document
    fprintf(out, "ID:%s\n", temp.ID);
    fprintf(out, "Full name:%s ", temp.F_name);
    fprintf(out, "%s\n", temp.L_name);
    fprintf(out, "Age:%d\n", temp.Age);
    fprintf(out, "Adress:%s", temp.Addr);

    // Close and save file
    fclose(out);
    return 0;
}

void Error_Msg(char *msg)
{
    printf("\n%s", msg);
    exit(1); /*Exit() closes any open files in the program*/
}