#include <stdio.h>

int main() {
    int c, nl = 1;

    printf("/*...*/ %4c", ' ');
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            printf("/*...*/ %4c", ' ');
        } else putchar(c);
    }
}