#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

HTTP_REQUEST* createHTTPRequest()
{
    HTTP_REQUEST* req = malloc(sizeof(HTTP_REQUEST));

    req->method = -1;
    req->url = NULL;
    req->headers = NULL;
    req->body = NULL;
    req->params = NULL;
    req->query = NULL;

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