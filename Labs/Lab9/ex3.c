#include <stdio.h>

int Bit_Count(unsigned int x);
void Bin_Print(unsigned int x);

int main()
{
    unsigned int x;

    printf("Enter a number");
    scanf("%d", &x);
    printf("There are %d bits equal to one in %u\n", Bit_Count(x), x);
    printf("The binary representation of %u is ", x);
    Bin_Print(x);

    return 0;
}

// This function will count how many active bits in specific number
int Bit_Count(unsigned int x)
{
    int count = 0;
    int mask = 1;
    while (x != 0)
    {
        x & mask ? count++ : count; // Check if there is active bit
        x >>= 1;
    }
    return count;
}

// This function will print number in bits
void Bin_Print(unsigned int x)
{
    int i;
    unsigned int mask = 1;
    int size = sizeof(x) * 8;
    for (i = size - 1; i >= 0; i--)
    {
        printf("%d", (x >> i) & mask); // will move number and not mask
    }
}