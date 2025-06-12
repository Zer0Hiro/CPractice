#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sum_square(int m, int n, float (*f)(int a));
float func1(int x);
float func2(int x);

int main()
{
    printf("The sum of func2: %.5lf\n", sum_square(2, 13, func2));
    printf("The sum of func1: %.5lf\n", sum_square(1, 10000, func1));
}

double sum_square(int m, int n, float (*f)(int a))
{
    int i;
    double count = 0;
    for (i = m; i <= n; i++)
    {
        count += pow(f(i),2);   
    }
    return count;
}

float func1(int x) { return 1.0 / x; }
float func2(int x) { return x / 5.0; }