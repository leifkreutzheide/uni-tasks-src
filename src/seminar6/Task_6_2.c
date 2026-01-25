#include <stdio.h>
#include <stdlib.h>

#define ZZ 8 /* field array size */

int z;
int FIELD[ZZ][ZZ];  /* Field */
int a[] = {-2, 1, -1, -2, -2, -1, 1, 2};   /* coordinates of Jumper moves */
int b[] = {-1, 2, 2, 1, -1, -2, -2, -1};
int x1, y1;

int try(int x, int y);
void Print();
int isKnightMove(int x1, int y1, int x2, int y2);

int main() {
    z = 4;
    while (1) {
        printf("Rows: ");
        scanf("%d", &z);
        
        if (z <= 1 || z > ZZ)
            exit(0);
        
        int i, j;
        for (i = 0; i < z; i++)
            for (j = 0; j < z; j++)
                FIELD[i][j] = 0;
        
        printf("Initial values x1 y1 = ");
        scanf("%d %d", &x1, &y1);
        
        FIELD[x1-1][y1-1] = 1;
        
        if (try(x1-1, y1-1))
            Print();
        else
            printf("\nNo Cyclic Solution Found\n");
    }
}

int isKnightMove(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

int try(int x, int y) {
    int k, q, u, v;
    
    for (k = q = 0; q == 0 && k < 8; k++) {
        u = x + a[k];
        v = y + b[k];
        
        if (0 <= u && u < z && 0 <= v && v < z && FIELD[u][v] == 0) {
            FIELD[u][v] = FIELD[x][y] + 1;
            
            if (FIELD[u][v] == z*z) {
                /* Check if we can jump back to starting position (cyclic tour) */
                if (isKnightMove(u, v, x1-1, y1-1))
                    q = 1;
                else
                    FIELD[u][v] = 0;  /* Not cyclic, backtrack */
            }
            else {
                if ((q = try(u, v)) == 0)
                    FIELD[u][v] = 0;
            }
        }
    }
    return(q);
}

void Print() {
    int i, j;
    printf("\nCyclic Knight's Tour Solution:\n");
    
    for (i = 0; i < z; i++) {
        for (j = 0; j < z; j++)
            printf("%3d", FIELD[i][j]);
        printf("\n");
    }
    printf("\n(Knight can jump from square %d back to square 1)\n", z*z);
}