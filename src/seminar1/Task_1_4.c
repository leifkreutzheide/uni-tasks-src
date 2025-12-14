 #include <stdio.h>
 #include <stdlib.h>

int main(void) {

    int value;

    printf("Type a character:");
    value = getchar() != EOF;                                       // value is 0 if user has pressed CTR+Z, otherwise value is true bzw. 1.

    printf("\ngetchar() != EOF has the value: %d\n", value); 
    printf("EOF itself has the value: %d\n", EOF);                  //EOF == -1

    return 0;
}
