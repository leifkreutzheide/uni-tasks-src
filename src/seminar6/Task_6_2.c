// Goal: no goal in cxx labs
// what i did: fixed the code

#include <stdio.h>

typedef enum {left, middle, right} tower;
int main() {

    int discnumber;
    void move();
    while (1) {

        printf("\ndiscnumber (Exit with 0): ");
        scanf("%d", &discnumber);
        if (discnumber <= 0) break;
        printf ("%d, %s\n",discnumber,"Discs need the following moves:");
        move (discnumber, left, middle, right);
}

}
void move (int amount, tower from, tower withhelp, tower to) {
    void move_disc();
    if ( amount == 1 ) {
        move_disc (from, to);
    } else {
        move ( amount- 1, from, to, withhelp);
        move_disc ( from, to );
        move ( amount- 1, withhelp, from, to);
}
}


void move_disc ( tower from, tower to ) {

    void print_tower();
    printf ("Disc from ");
    print_tower (from);
    printf (" to ");
    print_tower (to);
    printf ("\n");
}

void print_tower ( tower which ) {
    switch (which) {
    case left : printf ("LEFT "); break;
    case middle : printf ("MIDDLE "); break;
    case right : printf ("RIGHT"); break;
}
}