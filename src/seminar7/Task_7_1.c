// task: What does the call "a.out this is only a test" accomplish? Interpret the entire output!
/* answer: 

The command runs the program a.out with 5 arguments:

argc = 6 (program name + 5 words)
argv[0] = "a.out"
argv[1] = "this"
argv[2] = "is"
argv[3] = "only"
argv[4] = "a"
argv[5] = "test"

The command line splits the input by spaces. So the program receives each word as a separate string in the argv array.

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    printf("\nargc = %d\n");
    for ( i = 0; i < argc; i++)
    {
        printf("\nargv[%d] = %s\n", i, argv[i]);
    }
    
 return 0;
}
