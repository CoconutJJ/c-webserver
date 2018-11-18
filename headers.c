#include <string.h>
#include "types.h"
#define HTTP_NEWLINE "\r\n"



HTTP_HEADER * createHeaderList(int n) {

    
    
}

HTTP_REQUEST * __parseRequestHeaders(char * request) {

    // parse the token
    char * tok = strtok(request, HTTP_NEWLINE);
    
    char * method = strchr(tok, ' ');


    

    while (tok != NULL) {

        char * colon_ptr = strchr(tok, ':');

        *colon_ptr = '\0';

        tok = strtok(NULL, "\r\n");
    }
}
