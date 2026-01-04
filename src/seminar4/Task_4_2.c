
#define abs(A) ( (A) < 0 ?-(A) : (A) ) // "function" per definition
#define DELTA 1.0e-16
#include <stdio.h>


double squareroot(double n) {  
    double x = n, old_x = 0;
    if (n <= 0) return 0;
    while ( abs(x- old_x) > DELTA ) {
        old_x = x;
        x = (n/x + x)/2;
    }
    return x;
}

int main() {
    int i;
    double squareroot();
    for (i=-2; i < 10; i++) { 
       if (i < 0) printf("%d not computable due to negative \n", i); 
       else printf( "%d --> %10.16f\n", i, squareroot( (double)i ) ); 
    }
}
