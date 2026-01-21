/*
 ============================================================================
 Name        : task_8_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h> /* MATHE LIB HINZUFÜGEN SONST FUNTIONIERT SQRT NICHT */

struct complex { double r; double i; };

typedef struct complex cpx;
cpx makecpx(double, double);
cpx sum(cpx, cpx);
cpx diff(cpx, cpx); /* new */
cpx quotient(cpx, cpx); /* new */
cpx product(cpx, cpx);
cpx power(cpx, int);
double absolute(cpx);
void compprint(cpx);

int main() { /* calculates the power of complex numbers */
	int k;
	cpx basis, result, a, b;
	basis = makecpx(1,1);

	for (k=0; k < 10; ++k) {
		result = power( basis, k );
		printf("%2d ", k );
		compprint(result);
	}

	/* --- Zusätzliche Anwendungen --- */
		printf("\nWeitere Operationen:\n");
		a = makecpx(3, 4);
		b = makecpx(1, -2);

		printf("a = "); compprint(a);
		printf("b = "); compprint(b);

		printf("\n a + b = "); compprint(sum(a, b));
		printf("a - b = "); compprint(diff(a, b));
		printf("a * b = "); compprint(product(a, b));
		printf("a / b = "); compprint(quotient(a, b));
		printf("|a| = %5.2f\n", absolute(a));
		printf("|b| = %5.2f\n", absolute(b));

return 0;

}

cpx makecpx(double r, double i) { /* makes complex number */
	cpx tmp; /* Real Part r, Imaginary Part i */
	tmp.r = r; tmp.i = i;
	return tmp;
}

cpx sum(cpx a, cpx b) { /* Sum of two complex numbers */
	a.r += b.r;
	a.i += b.i;
	return a;
}

cpx power( cpx basis, int expo) { /* basis power exponent, basis complex */
	cpx u = {1, 0};
	while (expo > 0) {
		if (expo % 2) {
			expo--;
			u = product(basis, u);
		}
		else {
			expo /= 2;
			basis = product(basis, basis);
		}
	}
	return u;
}

cpx product(cpx x, cpx y) {/* Product of two complex numbers */
	cpx u;
	u.r = x.r * y.r - x.i * y.i;
	u.i = x.r * y.i + x.i * y.r;
	return u;
}

/* Zusätzliche Funktionen */

/* Subtraktion */
cpx diff(cpx a, cpx b) {
	a.r -= b.r;
	a.i -= b.i;
	return a;
}

/* Division */
cpx quotient(cpx a, cpx b) {
	cpx u;
	double denom = b.r * b.r + b.i * b.i;
	u.r = (a.r * b.r + a.i * b.i) / denom;
	u.i = (a.i * b.r - a.r * b.i) / denom;
	return u;
}

/* Betrag */
double absolute(cpx z) {
	return sqrt(z.r * z.r + z.i * z.i);
}

void compprint(cpx z) { /* prints complex number */
	if (z.r != 0 && z.i != 0)
		printf("%5.2f + %5.2f * i\n", z.r, z.i);
	else if (z.r == 0 && z.i != 0)
		printf("%13.2f * i\n", z.i);
	else if (z.r != 0 && z.i == 0)
		printf("%5.2f\n", z.r);
	else printf("0\n");
}
