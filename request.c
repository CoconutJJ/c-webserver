#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HTTP_REQUEST* createHTTPRequest()
{
    HTTP_REQUEST* req = malloc(sizeof(HTTP_REQUEST));

    // req->method = method;

    // req->url = malloc(strlen(url) + 1);

    // strcpy(req->url, url);

    return req;
}

void setRequestURL(HTTP_REQUEST * reqst, URL url) {
    reqst->url = malloc(strlen(url) + 1);
    strcpy(reqst->url, url);
}

void destroyHTTPRequest(HTTP_REQUEST * req) {

    free(req->url);
    free(req);
}