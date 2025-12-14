#include <stdio.h>

//function prototypes

int power(int base, int n);
int fact(int y);
int base = 2;

// main 

int main() {
    int i;
    for (i = 0; i < 10; i++) printf("%d %d %d\n", i, power(base, i), fact(i));
    return 0;
}

//  functions

int power(int base, int n) {
    if (n < 0) return -1;
    int i, p = 1;
    for (i = n; i > 0; i--) p = p * base;
    return p;
}

int fact(int y) {
    if (y < 0) return -1;
    int result = 1;
    while (y != 0) result *= y--;
    return result;
}
