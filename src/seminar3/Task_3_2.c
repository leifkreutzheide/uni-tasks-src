#include <stdio.h>

int main() {

    int a, b, c;
    char d;
    while(1) {

        top:
        printf("input two intergers, seperated by a comma: a, b : ");
        scanf("%d, %d", &a, &b);
        while (b != 0)
        {
            c = a % b; a = b; b = c;
        }
        printf("ggt = %d\n", a);
        
        printf("type 'y' if you want to test another pair: ");
        scanf(" %c", &d);
        if (d == 'y') {
            goto top;
        } else {
            goto end;
        }
        
        

    }

    end:
    printf("\nsession ended\n");

return 0;
}
