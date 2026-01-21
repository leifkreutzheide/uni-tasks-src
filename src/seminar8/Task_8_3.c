/*
 ============================================================================
 Name        : task_8_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* ====== Definition des Datentyps rat ====== */
struct rational {
    int num;   /* numerator (Zähler) */
    int den;   /* denominator (Nenner) */
};
typedef struct rational rat;

/* ====== Funktionsprototypen ====== */
rat makerat(int, int);
rat simplify(rat);
rat sumrat(rat, rat);
rat diffrat(rat, rat);
rat prodrat(rat, rat);
rat quotrat(rat, rat);
void ratprint(rat);
int gcd(int, int);

/* ====== Hauptprogramm ====== */
int main(void) {
    rat a, b, r;

    a = makerat(3, 4);   /* 3/4 */
    b = makerat(5, 6);   /* 5/6 */

    printf("a = "); ratprint(a);
    printf("b = "); ratprint(b);

    printf("\n--- Grundrechenarten mit rationalen Zahlen ---\n");
    printf("a + b = "); ratprint(sumrat(a, b));
    printf("a - b = "); ratprint(diffrat(a, b));
    printf("a * b = "); ratprint(prodrat(a, b));
    printf("a / b = "); ratprint(quotrat(a, b));

    return 0;
}

/* ====== Hilfsfunktionen ====== */

/* Erzeugt einen Bruch (und kürzt ihn direkt) */
rat makerat(int n, int d) {
    rat r;
    if (d == 0) {
        fprintf(stderr, "Fehler: Nenner darf nicht 0 sein!\n");
        exit(EXIT_FAILURE);
    } else {
        r.num = n;
        r.den = d;
        r = simplify(r);
    }
    return r;
}

/* Kürzt einen Bruch mithilfe des größten gemeinsamen Teilers */
rat simplify(rat r) {
    int g = gcd(r.num, r.den);
    if (g != 0) {
        r.num /= g;
        r.den /= g;
    }
    if (r.den < 0) { /* negatives Vorzeichen immer im Zähler */
        r.num = -r.num;
        r.den = -r.den;
    }
    return r;
}

/* Berechnung des größten gemeinsamen Teilers (Euklidischer Algorithmus) */
int gcd(int a, int b) {
    if (b == 0) return a > 0 ? a : -a;
    return gcd(b, a % b);
}

/* Addition: a/b + c/d = (ad + bc) / bd */
rat sumrat(rat x, rat y) {
    rat r;
    r.num = x.num * y.den + y.num * x.den;
    r.den = x.den * y.den;
    return simplify(r);
}

/* Subtraktion: a/b - c/d = (ad - bc) / bd */
rat diffrat(rat x, rat y) {
    rat r;
    r.num = x.num * y.den - y.num * x.den;
    r.den = x.den * y.den;
    return simplify(r);
}

/* Multiplikation: a/b * c/d = (ac) / (bd) */
rat prodrat(rat x, rat y) {
    rat r;
    r.num = x.num * y.num;
    r.den = x.den * y.den;
    return simplify(r);
}

/* Division: (a/b) ÷ (c/d) = (a*d) / (b*c) */
rat quotrat(rat x, rat y) {
    rat r;
    r.num = x.num * y.den;
    r.den = x.den * y.num;
    return simplify(r);
}

/* Ausgabe in schöner Bruchform */
void ratprint(rat r) {
    if (r.den == 1)
        printf("%d\n", r.num);
    else
        printf("%d/%d\n", r.num, r.den);
}

