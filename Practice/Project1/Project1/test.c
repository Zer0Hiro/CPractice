#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  
#define WIDTH 40
#define HEIGHT 40

typedef struct vector
{
    int x;
    int y;
} v2;

void rotate(float A, v2* vec);
void print_v(char* buf);
void buff_w(char* buf, v2* vec);

// screen size

int main()
{
    int x = 20, y = 0;
    float A = 0;
    v2 vector;
    v2* pvector = &vector;
    vector.x = x;
    vector.y = y;
    while (1)
    {
        A += 0.01;
        char buffer[WIDTH * HEIGHT] = { '.' };
        rotate(A, pvector);
        buff_w(buffer, pvector);
        print_v(buffer);
        Sleep(50);
    }
    return 0;
}

void rotate(float A, v2* vec)
{
    int x1 = (int)(vec->x * cos(A) - vec->y * sin(A));
    int y1 = (int)(vec->x * sin(A) + vec->y * cos(A));
    vec->x = x1;
    vec->y = y1;
}

void buff_w(char* buf, v2* vec)
{
    int pos_x = WIDTH / 2 + vec->x;
    int pos_y = HEIGHT / 2 + vec->y;
    buf[WIDTH * pos_y + pos_x] = '@';
}

void print_v(char* buf)
{
    int i, j;
    system("cls");
    for (j = 0; j < HEIGHT; j++)
    {
        for (i = 0; i < WIDTH; i++)
        {
            int temp = i + j * WIDTH;
            printf("%c\k", buf[temp]);
        }
        printf("\n");
    }
}