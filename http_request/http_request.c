#include <stdlib.h>
#include <string.h>
#include "../types/types.h"
#include "../headers/header.h"

void setRequestHeader(HTTP_REQUEST * req,const char * key, const char * value) {

    HTTP_HEADER * new = createHeader(key, value);
    
    //addHeader(rep->headers, new);


}   