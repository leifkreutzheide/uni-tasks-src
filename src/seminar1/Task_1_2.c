#include <stdio.h>

 int main(){

    int fahr; 
    float celsius;
    int lower, upper, step;

    lower=0; 
    upper=200;
    step= 20; 
    fahr= lower;

/*printf("\n");
printf("%d\t %d",fahr,celsius);
printf("\n");
printf("%5d %20dnn",fahr,celsius);
printf("\n");
printf("%-5d %20dnn",fahr,celsius);
printf("\n");
printf("%3d %6dnn",fahr,celsius);
*/


while(fahr<=upper){ 

    celsius = (5.0f / 9.0f) * (fahr - 32);
    printf("%d\t %.4f\n", fahr, celsius);
    fahr = fahr + step;

}

printf("\n");


 }
 
