#include <stdio.h>

int main() {

    int a, b, c, i;
    char d;

    top:
    printf("Determine all prime numbers up to: ");
    scanf("%d", &a);

    for (b = 2; b <= a; b++) {

        int isPrime = 1;

        for (i = 2; i * i <= b; i++) {
            if (b % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printf("%d ", b);
        }
    }

    printf("\n");

    printf("type 'y' if you want to determine more primes: ");
    scanf(" %c", &d);

    if (d == 'y') goto top;

end:
    printf("\nsession ended\n");
    return 0;
}
