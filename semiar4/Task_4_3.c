#include <stdio.h>
#include <ctype.h>

 int main() { 
    int c, key;
    printf("Enter Key: ");
    scanf("%d", &key);

    while ( (c = getchar()) != EOF)
        // if ((c >= 65) & (c <= 90))
    putchar(tolower(c + key));
 }