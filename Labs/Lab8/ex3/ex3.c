#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4

typedef struct COMPLEX
{
    float real;
    float img;
} Complex;

float CRadius(Complex);
void Error_Msg(char *str);
void InputAndWriteToFile(FILE *f);
int CheckFile(FILE *f, float m);

int main()
{

    FILE *f;
    f = fopen("complex_number.txt", "w+");
    InputAndWriteToFile(f);

    printf("\nThere are %d big numbers\n", CheckFile(f, 4));
    return 0;
}

void Error_Msg(char *str)
{
    printf("\n%s", str);
    exit(1);
}

// This function will count radius number
float CRadius(Complex c)
{
    double r;
    r = sqrt(pow(c.img, 2) + pow(c.real, 2)); // Compute Radius of complex number
    return r;
}

void InputAndWriteToFile(FILE *f)
{
    int i;
    float radius;
    Complex num;
    for (i = 0; i < N; i++)
    {
        if (scanf("%f %f", &num.real, &num.img) != 2)
        {
            Error_Msg("Input Error");
        }
        radius = CRadius(num);

        // Print inside the document
        fprintf(f, "%0.1f %0.1f %0.1f\n", num.real, num.img, radius);
    }
}

int CheckFile(FILE *f, float m)
{
    float temp, garb1, garb2;
    int i, count = 0;
    rewind(f);

    for (i = 0; i < N; i++)
    {
        if (fscanf(f, "%f %f %f", &garb1, &garb2, &temp) == 3)
            if (temp > m)
                count++;
    }
    return count;
}