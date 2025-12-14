#include <stdio.h>

int main() {

    int c;

    while ((c = getchar()) != EOF) {
    if (c == ' ') continue;
    if (c == '\n') continue;
    putchar(c);
    }
    
    

return 0;   
}