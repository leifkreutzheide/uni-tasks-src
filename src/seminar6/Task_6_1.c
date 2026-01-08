// goal: print ALL outputs and print exact positions of all outputs
// what i did: i changed the code to do that. got rid of the q exit flags 

#include <stdio.h>

#define ZZ 20 /* number of rows and columns */
int max, QUEEN[ZZ], ROW[ZZ], DIA0[2*ZZ-1], DIA1[2*ZZ-1];

int try(int i) {
    int j, k, l;
    for (j = 0; j < max; j++) {
        if (ROW[j] == 0 && DIA0[i+j] == 0 && DIA1[i-j+max-1] == 0) {
            QUEEN[i] = j+1;
            ROW[j] = DIA0[i+j] = DIA1[i-j+max-1] = 1;
            
            if (i == max-1) {
                for (k = 0; k < max; k++) {
                    for (l = 0; l < max; l++) {
                        printf(QUEEN[k] == l+1 ? "* " : ". ");
                    }
                    printf("\n");
                }
                printf("\n");
            } else {
                try(i+1);
            }
            
            ROW[j] = DIA0[i+j] = DIA1[i-j+max-1] = 0;
        }
    }
    return 0;
}

int main() {
    int i;
    printf("Which number ( < %d) ? ", ZZ);
    scanf("%d", &max);
    try(0);
    return 0;
}



