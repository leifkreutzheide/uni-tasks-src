#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
int trim( char s[]);

int main() {

    int len;
    int max;
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest read line so far */
    max = 0;

    while ( (len = getLine(line, MAXLINE)) > 0) {

        trim(line);
        if (strlen(line) > 0) printf("%s",line);

    }
    return 0;
}


int getLine(char line[], int maxline) {             /* getLine reads one line to s[] and returns the lenght of it */
    int c, i;

    for ( i=0; i < maxline-1 && (c=getchar()) != EOF && c != '\n'; ++i) /* ---> */ line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i; //returns length of the line
}


int trim( char s[]) {                            /* trim: removes blanks, tabs, newlines at the end of a line */

    int n;
    for ( n = strlen(s)-1; n >= 0; n--)
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        break;
    s[n+1] = '\n';
    s[n+2] = '\0';
    return n;
}