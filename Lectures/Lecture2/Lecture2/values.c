#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void counter();

//GLOBAL VALUE


//LOCAL VALUE

//STATIC VALUE
// Initialized only once when func called first time

void counter() {
    static int count = 0;  // Initialized once
    count++;
    printf("%d\n", count);
}

int main() {
    counter();  // Output: 1
    counter();  // Output: 2
    counter();  // Output: 3
    return 0;
}
