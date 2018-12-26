
#include <stdlib.h>
#include <string.h>
#include "../types/types.h"


/**
 * Create a HTTP header.
 */
HTTP_HEADER * createHeader(const char * key, const char * value) {

    HTTP_HEADER * new = malloc(sizeof(HTTP_HEADER));

    new->key = malloc(strlen(key) + 1);
    new->value = malloc(strlen(value) + 1);

    strcpy(new->key, key);
    strcpy(new->value, value);

    return new;
}

void addHeader(HTTP_HEADER * head, HTTP_HEADER * newp) {
    
    while(head->_next != NULL) head = head->_next;
    head->_next = newp;
    newp->_prev = head;
}





