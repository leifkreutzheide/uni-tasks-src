#include <stdio.h>

int main() {
    int c, i, nwhite, nother, totalLetters, ndigit[10];
    nwhite = nother = totalLetters = 0;

    for (i = 0; i < 10; i++ ) ndigit[i] = 0;

    while ( ( c = getchar() ) != EOF ) {
        switch (c) {

        // numbers
        case '0': 
        case '1': 
        case '2': 
        case '3': 
        case '4': 
        case '5': 
        case '6': 
        case '7': 
        case '8': 
        case '9':  ndigit[c-'0']++; // ndigit[c-'0'] = ndigit[7]
        break;

        // letters
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z': totalLetters ++;
        break;

        // other
        case ' ': 
        case '\n': 
        case '\t': nwhite++;
        break;

        // default
        default: nother++; break;
        }
    }

    printf("Digits =");
    for (i = 0; i < 10; i++) printf("the digit %d appears %d times\n", i, ndigit[i]);
    printf("white space = %d\n", nwhite);
    printf("letters a-z appear %d times in total\n", totalLetters);

return 0;
}