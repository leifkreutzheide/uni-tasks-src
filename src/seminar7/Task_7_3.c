// task 7.3: Modify this program so that the output is written to a file when a command line argument is given in the call.

// what i did: added output file detection: int output_file_index = -1. if -o flag is found the file is opened for writing



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *prog;

void filecopy(FILE *, FILE *);
FILE *eopen(char *, char *);

int main(int argc, char *argv[]) {
    int i;
    FILE *quelle, *ziel;
    int output_file_index = -1;
    
    prog = argv[0];
    
    // Check if there's an output file specified with -o flag
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_file_index = i + 1;
            break;
        }
    }
    
    // Open output destination (file or stdout)
    if (output_file_index != -1) {
        ziel = eopen(argv[output_file_index], "w");
    } else {
        ziel = stdout;
    }
    
    // If no input files, read from stdin
    if (argc == 1 || (argc == 3 && output_file_index != -1)) {
        filecopy(stdin, ziel);
    } else {
        // Process each input file
        for (i = 1; i < argc; i++) {
            // Skip the -o flag and output filename
            if (i == output_file_index - 1 || i == output_file_index) {
                continue;
            }
            
            quelle = eopen(argv[i], "r");
            filecopy(quelle, ziel);
            fclose(quelle);
        }
    }
    
    // Close output file if we opened one
    if (output_file_index != -1) {
        fclose(ziel);
    }
    
    return 0;
}

void filecopy(FILE *q, FILE *z) {
    int c;
    while ((c = getc(q)) != EOF)
        putc(c, z);
}

FILE *eopen(char *name, char *mode) {
    FILE *fp;
    if ((fp = fopen(name, mode)) == NULL) {
        fprintf(stderr, "\neopen in %s: File %s cannot be opened in mode %s.\n", 
                prog, name, mode);
        exit(1);
    }
    return fp;
}








