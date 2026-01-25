#include <stdio.h>


int main() {

    int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double doublenum[7] = {1.23, 2.34, 3.45, 4.56, 5.67, 6.78, 7.89};
    int i;
    double *pointerA;
    int *pointerB;

    printf("\n%d, %d\n", num[1], doublenum[6]);

    for(i = 0; i <= 9; i++) printf("\nindex %d of array num has the value %d and the adress %d\n", i, num[i], &num[i]);
    printf("%d, %d, %d\n", pointerB, &pointerB, *pointerB);

    int *p1 = &num[7];
    int *p2 = &num[2]; 
    int diff;
    diff = p1 - p2;
    printf("diff = %d", diff);


    return 0;


}


