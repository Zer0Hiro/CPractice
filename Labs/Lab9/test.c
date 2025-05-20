#include <stdio.h>

int main()
{
   int mask = 1;
   unsigned char x = 102;
   x = x | (mask << sizeof(x)*8 - 1);
   printf("%d", x);
   return x;
}