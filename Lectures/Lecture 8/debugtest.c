#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f = fopen("test.txt", "w+");
    char text[100];
    fprintf(f, "Hello World\n");
    fscanf(f, "%c", &text);
    printf("%c", text);
    return 1;
}
