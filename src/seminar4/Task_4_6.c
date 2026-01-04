#include <stdio.h>

int main() {

    int c;

    while ((c = getchar()) != EOF) {
    if (c == ' ') continue;
    if (c == '\n') continue;
    if (c == '\t') continue;
    putchar(c);
    }
    
    

return 0;   
}
