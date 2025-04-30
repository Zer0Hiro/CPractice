#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> -
#include <stdlib.h>
#include <string.h> -
#define ROWS 3
#define MAX 5

/*
@File         : q_3.c
@Date         : 16:24 21/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : This program reorders a matrix so that elements that are lesser than 'x' appear before it,
                and elements that are greater appear after it.
*/

void order(int a[][MAX], int rows, int cols, int num);

int main()
{
    int a[ROWS][MAX], num, i, j, x;
    char row_number[7] = { "first" };

    // Instructions + description.
    printf("This program can sorts any given matrix by reordering 'x',"
        "\nso that lesser numbers are below it and greater numbers are above it."
        "\n\nPlease type a whole number you would like to sort by: ");

    // This loop requests and assigns user value to 'x',
    // while prompting user to try again if the said value is invalid.
    while (scanf("%d", &x) != 1)
    {
        rewind(stdin);
        printf("\nInputs may only be whole numbers.. Try again:");

    }
    // No matter what variable I set the user input to, it gets replaces by 0 neigh instantly...
    // I do not know why this happens. This is my "bandaid fix".
    num = x;

    // This loop puts user values into matrix 'a[]'.
    printf("\nNow, input numbers to be put into the matrix.\n");
    for (i = 0; i < ROWS; i++)
    {
        printf("Enter %d numbers for the %s row: ", MAX, row_number);
        for (j = 0; j < MAX; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
            {
                printf("\nPlease make sure to only enter whole numbers..");
                return 1;
            }
        }
        // These update the text.
        strcpy(row_number, "second");
        if (i == 1) strcpy(row_number, "third");
    }

    // These print the matrix pre-reorder.
    printf("\nThe entered matrix is:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (j == 0) printf("[%d", a[i][j]);

            if (j != 0) printf("%d", a[i][j]);

            if (j < MAX - 1)
                printf(", ");
        }
        printf("]\n");
    }

    // This sends matrix 'a[]', 'ROWS', 'MAX' and 'x' to "order" for reorganization.
    order(a, ROWS, MAX, num);

    // These print the matrix post-reorder.
    printf("\nThe newly reordered matrix is:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (j == 0) printf("[%d", a[i][j]);

            if (j != 0) printf("%d", a[i][j]);

            if (j < MAX - 1)
                printf(", ");
        }
        printf("]\n");
    }

    return 0;
}

// This function swaps 'a[][]' elements around in relation to 'x',
// where elements lesser and greater than 'x' are places before and after 'x' respectively.
void order(int a[][MAX], int rows, int cols, int x)
{
    int i, j, i_x = -1, j_x = -1, counter_min = 0;
    int x_flag = 0;
    int new_i, new_j;

    // Initialization of the first and last element in the matrix.
    int* right_p = &a[0][0], * left_p = &a[rows - 1][cols - 1];
    int temp;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            // This locates the first occurrence of 'x' and captures it's coordinates.
            if (a[i][j] == x && x_flag == 0)
            {
                i_x = i;
                j_x = j;
                x_flag = 1;
            }

            // This counts how many numbers there are in the matrix that are lesser than 'x'.
            if (a[i][j] < x)
            {
                counter_min++;
            }
        }
    }
    if (x_flag == 0) {
        printf("\nThe number %d was not found in the matrix.\n", x);
        exit(69);
    }

    // These swap 'x''s position in the matrix with the element that cooresponds to 'counter_min''s slot.
    new_i = counter_min / cols, new_j = counter_min % cols;

    a[i_x][j_x] = a[new_i][new_j];
    a[new_i][new_j] = x;

    // This loop runs through the matrix in relation to 'x''s coordinates until one or both of the pointers meet 'x'.
    while (right_p <= &a[new_i][new_j] && left_p >= &a[new_i][new_j])
    {
        // This loop swaps the values that said pointers point at.
        if (*right_p > x && *left_p < x)
        {
            temp = *right_p;
            *right_p = *left_p;
            *left_p = temp;
        }

        // These advance the pointers post-element swap.
        if (*right_p <= x) right_p++;
        if (*left_p >= x) left_p--;
    }
}