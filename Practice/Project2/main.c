#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char *name;
    long id;
    float grade;
    char applied[5];
    char hw_grade;
} Student;

typedef struct
{
    Student *students;
    int population;
} University;

int Menu(int flag);
void AddStudent(University *uni, FILE *in); // Option 1
void printHW(University *uni, FILE *out);   // Option 2
void printFG(University *uni, FILE *out);   // Option 3
void printNOHW(University *uni, FILE *out); // Option 4
int changeData(University *uni, FILE *out); // Option 5
void EOP(University *uni);                  // Option 6
void StudentHW(University *uni);
void printIN(University *uni, FILE *out, int i);
void Error_Msg(char *error);

int main()
{
    FILE *input, *output;
    University database, *pdatabase = &database;
    int inputR = 0;
    char choice;
    // Open Input file
    if ((input = fopen("input.txt", "r")) == NULL)
        Error_Msg("The input file is wrong");

    // Menu choices
    while (1)
    {
        choice = Menu(inputR);
        switch (choice)
        {
        case '1':
            AddStudent(pdatabase, input);
            if ((output = fopen("output.txt", "w")) == NULL)
            {
                EOP(pdatabase); // Free buffered memory
                Error_Msg("The output file is wrong");
            }
            fprintf(output, "Input accepted");
            inputR = 1;
            break;
        case '2':
            fprintf(output, "\nOPTION 2\n");
            printHW(pdatabase, output);
            break;
        case '3':
            fprintf(output, "\nOPTION 3\n");
            printFG(pdatabase, output);
            break;
        case '4':
            fprintf(output, "\nOPTION4\n\nNO HW SUBMISSIONS");
            printNOHW(pdatabase, output);
            break;
        case '5':
            fprintf(output, "\nOPTION 5\n");
            changeData(pdatabase, output);
            break;
        case '6':
            EOP(pdatabase);
            exit(1);
        default:
            printf("Wrong Input, please try Again");
            break;
        }
    }
}

// This function send error message and close the program
void Error_Msg(char *error)
{
    printf("\n%s", error);
    exit(-1);
}

// This function prints menu of tools
int Menu(int flag)
{
    char ch;
    // Clear console
    system("cls");
    printf("Welcome to student database!\n");
    if (flag != 1)
    {
        printf("\nATTENTION!!!\nYou have to buffer all information from document to system!\nPRESS 1 to proceed");
        while ((ch = getch()) != '1' && ch != '6')
        {
            printf("\nYou can't continue without buffering document first!\n");
            printf("If you want to exit PRESS 6");
        }
        return ch;
    }
    printf("Choose one of the options:\n");
    printf("Option2\nOption3\n");
    printf("Option4\nOption5\nOption6");
    while ((ch = getch()) == '1')
    {
        printf("You can't use this option again");
    }
    return ch;
}

// This function adds student to database
void AddStudent(University *uni, FILE *in)
{
    int i;
    int pos;

    char tempName[99];
    Student *temp;
    uni->population = 0;
    uni->students = NULL;

    while (fscanf(in, "%s", tempName) != -1)
    {
        // Count students
        uni->population++;
        pos = uni->population - 1;

        // Allocate memory for additional student
        temp = (Student *)realloc(uni->students, sizeof(Student) * uni->population);
        if (temp == NULL)
        {
            for (i = 0; i < uni->population; i++)
            {
                free(uni->students[i].name);
            }
            free(uni->students);
            Error_Msg("Memory Error");
        }
        uni->students = temp;

        // Allocate memory for name
        uni->students[pos].name = (char *)malloc(strlen(tempName) + 1);
        if (uni->students[pos].name == NULL)
        {
            for (i = 0; i < uni->population; i++)
            {
                free(uni->students[i].name);
            }
            free(uni->students);
            Error_Msg("Memory Error");
        }
        strcpy(uni->students[pos].name, tempName);

        // Copy all relevant info (id/grade/applied)
        fscanf(in, "%ld %f %s", &uni->students[pos].id, &uni->students[pos].grade, &uni->students[pos].applied[i]);
    }
}

// This function checks how many hw he applied
void StudentHW(University *uni)
{
    int i, j, count;
    // Student array loop
    for (j = 0; j < uni->population; j++)
    {
        uni->students[j].hw_grade = '0';
        count = 0;
        // Applied array loop
        for (i = 0; i < 5; i++)
        {
            if (uni->students[j].applied[i] == '1')
                count++;

            if (count >= 3)
            {
                uni->students[j].hw_grade = '1';
                break;
            }
        }
    }
}

// This function prints student data to doc + HWgrade
void printHW(University *uni, FILE *out)
{
    int i;
    StudentHW(uni); // count HW grades

    for (i = 1; i <= uni->population; i++)
    {
        printIN(uni, out, i);
    }
}

// This function prints student data to doc + FinalGrade
void printFG(University *uni, FILE *out)
{
    int i;
    float fgrade;

    StudentHW(uni); // count HW grades

    // Print Before
    fprintf(out, "\nBEFORE:");
    printHW(uni, out);

    // After
    fprintf(out, "\nAFTER:");
    for (i = 1; i <= uni->population; i++)
    {
        fgrade = uni->students[i - 1].grade;

        // compute fgrade
        if (uni->students[i - 1].hw_grade == '1')
        {
            if (uni->students[i - 1].grade >= 55)
                fgrade = 15 + 0.85 * (uni->students[i - 1].grade);
        }
        else
        {
            if (uni->students[i - 1].grade >= 55)
                fgrade = 0.85 * (uni->students[i - 1].grade);
        }

        printIN(uni, out, i);
        fprintf(out, " final: %0.2f", fgrade);
    }
}

// This function prints main info of student
void printIN(University *uni, FILE *out, int i)
{
    fprintf(out, "\nStudent %d: ", i);
    fprintf(out, "%s %ld ", uni->students[i - 1].name, uni->students[i - 1].id);
    fprintf(out, "%0.2f %c", uni->students[i - 1].grade, uni->students[i - 1].hw_grade);
}

// This function prints students that didn't apply hw
void printNOHW(University *uni, FILE *out)
{
    int i;
    StudentHW(uni);

    // Check who has no hw_grade
    for (i = 0; i < uni->population; i++)
    {
        if (uni->students[i].hw_grade == '0')
        {
            fprintf(out, "\nStudent %d: ", i + 1);
            fprintf(out, "%s %ld", uni->students[i].name, uni->students[i].id);
        }
    }
}

// This function changes data of chosen student
int changeData(University *uni, FILE *out)
{
    char name[99];
    int hw_num, grade, i, flag;

    printf("\nEnter Name of the student, hw number and grade: ");
    if (scanf("%s %d %d", &name, &hw_num, &grade) != 3)
    {
        fprintf(out, "\nWrong data input\n");
        return -1;
    }

    // Check which student has name from input
    for (i = 0; i < uni->population; i++)
    {
        if (strcmp(name, uni->students[i].name) == 0)
        {
            uni->students[i].applied[hw_num - 1] = grade;
            return 1;
        }
    }
    fprintf(out, "\nName is not found\n");
    return -1;
}

// This function will close program
void EOP(University *uni)
{
    int i;

    // Free memory from names of students
    for (i = 0; i < uni->population; i++)
    {
        free(uni->students[i].name);
    }
    free(uni->students);
}