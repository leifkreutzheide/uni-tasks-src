// Task: Task 7.2: Test the perror() error message assuming that the file to be opened is not readable
// or writeable. (Change with the Unix command chmod.)

// result: the perror() messages provide diagnostic information about why the program failed and 
// turns failure codes into readable (for humans) messages.


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

     int c;
     FILE *source, *target, *eopen();
     source = eopen(argv[1], "r");
     target = eopen(argv[2], "w");

     while ( (c = getc(source)) != EOF ) /* do this: */ putc(c, target);
    
    fclose(source);
    fclose(target);
 }

 /* opening File with error handling */
 FILE *eopen(char *name, char *mode) {
 FILE *fp;
 if ( (fp = fopen(name,mode)) == NULL) {
        perror(name); /* Library function delivers error diagnosis */
        exit(1);
    }
         return fp;
    }