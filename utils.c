#include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
#include "utils.h"
void tokenize(char * str, char * buf[], int n, char * delim) {
    
    char * tok = strtok(str, delim);
    int ntoks = 0;
    while (tok != NULL) {

        if (ntoks == n)
            break;
        
        buf[ntoks++] = tok;

        tok = strtok(NULL, delim);
    }


}

// int main (int argc, char ** argv) {

//     char p[] = "Hello my name is David";

//     char *buf[5];

//     tokenize(p, buf, 5, " ");

//     for (int i = 0; i < 5; i++) {
//         printf("%s\n", buf[i]);
//     }

// }