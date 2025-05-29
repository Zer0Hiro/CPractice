#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char code[11];
    char *name;
    char Dep[4];
    int marks[3];
    float avg;
    struct node *next;
} std;

void Error_Msg(char *str);
std *FromFileToList(FILE *in);
std *Delete_Stud(std *toDel, std *head);
std *DeleteList(std *head);
void PrintList(std *head);
std *FindMax(std *head);

int main()
{
    int i;
    FILE *f;
    std *Head = NULL, *temp;

    if ((f = fopen("List1.txt", "rt")) == NULL)
        Error_Msg("input error");
    Head = FromFileToList(f);
    if (Head == NULL)
        Error_Msg("The input file is empty");

    fclose(f);
    printf("\nThe list is:");
    PrintList(Head);

    temp = FindMax(Head);
    printf("\n\nthe student with max average:\n");
    printf("%s %s %s", temp->code, temp->name, temp->Dep);
    for (i = 0; i < 3; i++)
        printf(" %d", temp->marks[i]);

    printf("\n\nThe list after change:");
    Head = Delete_Stud(FindMax(Head), Head);
    PrintList(Head);
    Head = DeleteList(Head); /*Head = NULL */
    return 0;
}

void Error_Msg(char *str)
{
    printf("\n%s", str);
    exit(1);
}

std *FromFileToList(FILE *in)
{
    // Create Nodes
    std *head = NULL, *temp;
    char tempName[257];
    int i, j;
    float count;

    // Check length of document
    fseek(in, 0, 2);
    i = ftell(in);
    fseek(in, 0, 0);

    // Check if there is any ID left
    while (ftell(in) != i)
    {
        temp = (std *)malloc(sizeof(std));
        if (temp == NULL)
        {
            DeleteList(head);
            Error_Msg("Memmory allocation error");
        }

        // Get all data for node
        fscanf(in, "%s %s %s", temp->code, tempName, temp->Dep);
        for (j = 0; j < 3; j++)
            fscanf(in, "%d", &temp->marks[j]);
        // Allocate memory for name
        temp->name = (char *)malloc(strlen(tempName) + 1);
        if (temp->name == NULL)
        {
            free(temp);
            DeleteList(head);
            Error_Msg("Memory allocation error");
        }
        strcpy(temp->name, tempName);

        // Count average
        count = 0;
        for (j = 0; j < 3; j++)
        {
            count += temp->marks[j];
        }
        temp->avg = count / j;

        // Return head to list
        temp->next = head;
        head = temp;
    }
    return head;
}

// This function will print list
void PrintList(std *head)
{
    int i;
    while (head != NULL)
    {
        // Print info about student
        printf("\n%s %s %s", head->code, head->name, head->Dep);
        for (i = 0; i < 3; i++)
            printf(" %d", head->marks[i]);
        // Move to the next node
        head = head->next;
    }
}

// This function will find node with biggest average grade
std *FindMax(std *head)
{
    std *temp = NULL;
    float best = 0;

    while (head != NULL)
    {
        // Check if new best grade
        if (head->avg > best)
        {
            best = head->avg;
            temp = head;
        }
        head = head->next;
    }
    return temp;
}

// This function will delete specific node in list
std *Delete_Stud(std *toDel, std *head)
{
    // Get temp previous and next node
    std *prev = NULL, *curr = head;

    while (curr != NULL)
    {
        if (curr == toDel)
        {
            // Check if its the start of the list or not
            if (prev == NULL)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr->name);
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

// This function will free all allocated memory
std *DeleteList(std *head)
{
    std *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->name);
        free(temp);
    }
    return head;
}