#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// This program is a calculator.
// It can average, multiply, spot the min/max and power.
int main()
{
    // Instructions.
    printf("This is a calculator."
        "\n. ___________________________________________________________________________ ."
        "\n| Please input:    'A\\a'   |     '*'    |       'm\\M'       |   '^'   | 'q\\Q' |"
        "\n| Being.......:   Average  |  Multiple  |  Minimum\\Maximum  |  Power  |  Quit |"
        "\n. ___________________________________________________________________________ .");
    
    int a, b, i = 1;
    char ch;

    // Opens a switch that loops so long as 'ch' isn't 'q' or 'Q'
    while (i != 0) 
    {
        // Requests and assigns user value to 'ch'
        printf("\n\nInput: ");
        rewind(stdin);
        ch = getchar();

    
        // Checks if any of this chars mentioned
        if (ch == 'A' || ch == 'a' || ch == '*' || ch == 'm' || ch == 'M' || ch == '^') 
        {
            printf("Input two whole numbers: ");
            scanf("%d %d", &a, &b);
        }

        // Each case handles simple math/logic for every scenario with accompanying text
        switch(ch) 
        {
        case 'A': case 'a':
            printf("The average of %d and %d is: %g", a, b, (a + b) / 2.0);
            break;

        case '*':
            printf("The multiplication of %d by %d results in: %g", a, b, (float)(a * b));
            break;

        case 'm': 
            printf("The minimum between %d and %d is: %d", a, b, (a < b) ? a : b);
            break;

        case 'M':
            printf("The maximum between %d and %d is: %d", a, b, (a > b) ? a : b);
            break;

        case '^':
            printf("The power of %d and %d is: %g", a, b, pow(a, b));
            break;

        case 'q': case 'Q':
            printf("Finish");
            i = 0;
            break;

        default:
            printf("Error");
            break;
        }
    }
    return 0;
}
