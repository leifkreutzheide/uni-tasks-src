// task: What does the call "a.out this is only a test" accomplish? Interpret the entire output!
/* answer: 



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
