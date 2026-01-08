// task 7.3: Modify this program so that the output is written to a file when a command line argument is given in the call.

// what i did: 

#include <stdio.h>
#include <stdlib.h>

char *prog;

int main(int argc, char *argv[] ) {

    int i; FILE *quelle, *eopen(char *, char *);
    void filecopy (FILE *, FILE *);
    prog = argv[0];
    if (argc == 1) filecopy(stdin, stdout);
    else {
        for ( i = 1; i < argc; i++)
        {
            quelle = eopen(argv[i], "r");
            filecopy(quelle, stdout);
            fclose(quelle);
        }
        exit (0);
    }
}

void filecopy(FILE *q, FILE *z) {
    int c;
    while ((c = getc(q)) != EOF)
    putc(c,z);
}

FILE *eopen(char *name, char *mode) {
    FILE *fp;
    if ((fp = fopen(name, mode)) == NULL)
    {
        fprintf(stderr, "\neopen in %s: FIle %s cant be opened in mode %s.\n", prog, name, mode);
        exit(1);
    }
    return fp;

}




























