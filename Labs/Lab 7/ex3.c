#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Complex
{
    float real;
    float imagine;
} Complex;

float CRadius(Complex X);
Complex *Cmax(Complex *arr, int size);

int main()
{
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
    for( i = 0; i < size; i++)
    {
        if(CRadius)
    }
}