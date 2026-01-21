// Task: Expand the program so that the strings for the control characters are entered as
// well. (such as LF, EOT, DEL, etc. ).

// how i did it: added a if statement interating through possible control character names found in name[] with a flag.


#include <stdio.h>
#include <ctype.h>
#include <string.h>


// control characters (index matches ASCII value)
char *name[] = { "NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL",
                 "BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI",
                 "DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB",
                 "CAN", "EM","SUB","ESC", "FS", "GS", "RS", "US",
                 "SP" };

char *input = // pointer to string literally stored in "input"
"\n\nInput of single character provides its Ascii value \n\
Input of Control-Char (^Z) provides its Ascii value\n\
Input of multiple number provides its Ascii character\n\
Input of Character with prefix\n\
o, O or 0: octal read character\n\
d or D: decimal read character\n\
x or X: hexadecimal read character\n\
tab or TAB: Ascii-Table output\n\
Exit with Ctrl-C\n";

int main() {
    char s[10];
    int c, d;
    void table();
    
    printf(input);
    
    while (1) {
        printf(": ");
        scanf("%s", s);
        
        if (strcmp(s, "tab") == 0 || strcmp(s, "TAB") == 0) {
            table();
            continue;
        }

            // what i added: 
        int found = 0;
        for (int j = 0; j < 33; j++) {
        if (strcmp(s, name[j]) == 0) {
            c = j;
            found = 1;
            goto controlcharaterwasfound;
    }
}
        
    
        // input pharsing 
        if (strlen(s) == 1) 
            c = s[0];
        else if (s[0] == '^')
            c = s[1] & 0x1f;
        else if (s[0] == 'o' || s[0] == 'O' || s[0] == '0')
            sscanf(&s[1], "%o", &c);
        else if (s[0] == 'd' || s[0] == 'D')
            sscanf(&s[1], "%d", &c);
        else if (isdigit(s[0]))
            sscanf(s, "%d", &c);
        else if (s[0] == 'x' || s[0] == 'X')
            sscanf(&s[1], "%x", &c);
        
        controlcharaterwasfound:
        c &= 0xff;
        
        if (!iscntrl(c) && c != ' ')
            printf("ASCII(%c)=o%o d%d x%x\n", c, c, c, c);
        else if (c == ' ')
            printf("ASCII( )=%s=o%o d%d x%x\n", name[c], c, c, c);
        else if (c != 0x7f)
            printf("ASCII(^%c)=%s=o%o d%d x%x\n", c+0x40, name[c], c, c, c);
        else 
            printf("ASCII(DEL)=o%o d%d x%x\n", c, c, c);
    }
}

void table() {
    int i;
    printf("\n");
    
    for (i = 0; i < 31; i++)
        printf("\t%3d %2x %s\t%3d %2x %c\t%3d %2x %c\t%3d %2x %c\n",
               i, i, name[i], i+32, i+32, i+32, i+64, i+64, i+64, i+96, i+96, i+96);
    
    printf("\t%3d %2x %s\t%3d %2x %c\t%3d %2x %c\t%3d %2x DEL\n",
           i, i, name[i], i+32, i+32, i+32, i+64, i+64, i+64, i+96, i+96);
    
    printf("\n");
}