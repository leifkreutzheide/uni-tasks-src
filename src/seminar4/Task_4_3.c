#include <stdio.h>
#include <ctype.h>

 int main() { 
    int c, key;
    printf("Enter Key: ");
    scanf("%d", &key);

    while ( (c = getchar()) != EOF)
   
    putchar(tolower(c + key));
 }
