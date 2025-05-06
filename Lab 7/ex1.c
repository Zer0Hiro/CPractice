#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float x, y;
} point;

typedef struct
{
    point c;
    float r;
} circle;

int position(point X, circle CIRC);

int main()
{
    point A;
    circle C1;
    // Get coordinates of the point
    printf("Enter the coordinates of your point:");
    if (scanf("%f %f", &A.x, &A.y) != 2)
    {
        printf("Error");
        return 1;
    }

    // Get Radius and coords of center of circle
    printf("Enter the radius and the center of your circle:");
    if (scanf("%f %f %f", &C1.r, &C1.c.x, &C1.c.y) != 3)
    {
        printf("Error");
        return 1;
    }
    // Will print if the point inside or outside
    if (position(A, C1))
        printf("The point is included in the circle");
    else
        printf("The point is not included in the cirlce");
    return 0;
}
// This function will check if the point is inside of the circle
int position(point X, circle CIRC)
{
    // Compute the exact position of point
    double d = sqrt(pow(X.x - CIRC.c.x,2) + pow(X.y - CIRC.c.y,2));
    return d<CIRC.r?1:0;
}