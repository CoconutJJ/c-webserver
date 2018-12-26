#include <stdlib.h>
#include <string.h>
#include "../types/types.h"
#include "../headers/header.h"


HTTP_RESPONSE * createHTTPResponse() {
    HTTP_RESPONSE * new = malloc(sizeof(HTTP_RESPONSE));
    new->header_count = 0;
    new->body = NULL;
    new->headers = NULL;
    new->status = 0;
    new->status_message = NULL;
}


void setResponseHeader(HTTP_RESPONSE * rep, const char * key, const char * value) {
    
    HTTP_HEADER * new = createHeader(key, value);
    
    addHeader(rep->headers, new);
    
}