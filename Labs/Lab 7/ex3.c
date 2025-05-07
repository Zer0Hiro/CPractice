#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM 3

typedef struct Complex
{
    float real;
    float imagine;
} Complex;

float CRadius(Complex X);
Complex *Cmax(Complex *arr, int size);

int main()
{
    Complex array[NUM], *max;
    int i;

    // Get complex number from user
    printf("Enter %d complex numbers:\n", NUM);
    for (i = 0; i < NUM; i++)
    {
        if (scanf("%f %f", &array[i].real, &array[i].imagine) != 2)
        {
            printf("Wrong input");
            exit(1);
        }
    }

    // Get adress of max number
    max = Cmax(array, NUM);
    
    // Print the final results
    printf("\n\n The max complex number is %0.2f+%0.2fi", max->real, max->imagine);
    printf("\nThe radius of the max number is %0.2f", CRadius(*max));
    
    return 1;
}

// This function will compute radius of complex number
float CRadius(Complex X)
{
    float r;
    r = sqrt(pow(X.real, 2) + pow(X.imagine, 2));

    return r;
}

// This function will find the max number in array
Complex *Cmax(Complex *arr, int size)
{
    int i;
    Complex *max = arr;

    // Find max number by radius
    for (i = 1; i < size; i++)
        if (CRadius(*max) < CRadius(arr[i]))
            max = &arr[i];

    return max;
}