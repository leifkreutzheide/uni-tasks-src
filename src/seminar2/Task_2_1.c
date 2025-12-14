#include <stdio.h> 

// use all: +, -, !, ++, -, *, &, sizeof, <, >, <=, >=, <<, >>, conditional operator ?,  

int main()
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p; 

    a = b = 7;
    c = a*b; // c = 49
    printf("\n%d\n", c);
    printf("%d\n", (c - a));

    if (c != 49) {
        printf("c =/= 49\n");
    } else {
        printf("c = 49!\n");
    }

    while (c < 55)
    {
        printf("%d, ", c);
        c++;
    }

    printf("\n");

    while (c >= 49)
    {
        printf("%d, ", c);
        c--;
    }
    
    d = 49;
    printf("\n");

    if (d &= c == 49)
    {
        printf("d = c = 49\n");
    } else {printf("d =/= c =/= 49, most likely because c = %d\n", c);
    } 

    e = 3, f = 4;
    g = (e <= f) ? 40 : 50;
    printf("%d\n", g);
    

    h = 9, i = 14;  // 9 = 1001, 14 = 1110
    printf("%d\n", h & i);  // 1 where all bits are 1
    printf("%d\n", h | i);  // 1 where either bit 1 is  (ODER)
    printf("%d\n", h ^ i);  // 1 where only one 1 is (XOR)
    printf("%d\n", h << 1); // most significant bit moved one place left
    printf("%d\n", h >> 1); // least sign. bit moved one place right (the outer ones get moved)
    
    


    printf("\n");
    return 0;
}


