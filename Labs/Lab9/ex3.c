#include <stdio.h>

int Bit_Count(unsigned int x);
void Bin_Print(unsigned int x);

int main()
{
    unsigned int x;

    printf("Enter a number");
    scanf("%d", &x);
    printf("There are %d bits equal to one in %d\n", Bit_Count(x), x);
    printf("The binary representation of %d is ", x);
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
    int size = sizeof(unsigned int)*8;
    for(i = size; i < sizeof(unsigned int)*8; i--)
    {
        mask << i // moving it left
    }

}