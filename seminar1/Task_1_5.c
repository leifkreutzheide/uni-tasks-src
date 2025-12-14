#include <stdio.h>
#include <stdlib.h>

int main() {
    
int c;
int spaces = 0;

while ( (c = getchar()) != EOF ) { //while there are still charaters and the file/input hasnt ended 

        if ( c == ' ') {
            printf("\n");
    } else {
        putchar(c);
    }

}

return 0;

}