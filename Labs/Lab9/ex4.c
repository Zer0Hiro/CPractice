#include <stdio.h>

void BinPrint(unsigned char ch);
unsigned char check_ms(unsigned char ch);
unsigned char change_bit(unsigned char ch, int pos);

int main()
{
    unsigned char num1 = 102, num2 = 58;
    int n;

    printf("\nThe first part :");
    printf("\nThe number is %d   ", num1);
    BinPrint(num1);
    num1 = check_ms(num1);
    printf("\nThe new number is: %d   ", num1);
    BinPrint(num1);

    printf("\n\nThe second part :");
    printf("\nThe number is %d   ", num2);
    BinPrint(num2);
    printf("\nEnter a number of the bit to change(1-8)");
    scanf("%d", &n);
    num2 = change_bit(num2, n);
    printf("\nThe new number is: %d   ", num2);
    BinPrint(num2);
    return 0;
}

void BinPrint(unsigned char ch)
{
    int i;
    unsigned int mask = 1;
    int size = sizeof(ch) * 8;
    for (i = size - 1; i >= 0; i--)
    {
        printf("%d", (ch >> i) & mask); // will move number and not mask
    }
}

// This function will return number with MSB activated
unsigned char check_ms(unsigned char ch)
{
    int mask = 1;
    return ch | (mask << sizeof(ch) * 8 - 1);
}

// This function will activate/deactivate specific number
unsigned char change_bit(unsigned char ch, int pos)
{
    int mask = 1;
    return ch ^ (mask << sizeof(ch) * 8 - (pos));
}