#include <stdio.h>
#include <ctype.h>

 int main() { 
    int c, key, normalized;
    printf("Enter Key: ");
    scanf("%d", &key);
    

    // normalises a given range 

    normalized = ((key % 26) + 26) % 26;

    while ( (c = getchar()) != EOF)
    putchar(tolower(c +normalized));
 }

