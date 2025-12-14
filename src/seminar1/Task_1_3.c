#include <stdio.h>
#include <stdlib.h>

 int main() {
    
    int fahr;
    int celsius;

    while (celsius <= 100)
    {
        fahr = celsius*1.8 + 32;
        printf("if celsius is %d, then fahreheit will be %d\n", celsius, fahr);
        celsius = celsius + 20;
    }
    
    fahr = 0;
    celsius = 0;
    printf("\n");

    for (celsius = 0; celsius <= 100; celsius = celsius + 20)
    {
        fahr = celsius*1.8 + 32;
        printf("if celsius is %d, then fahreheit will be %d\n", celsius, fahr);
    }
    
    
        
 }