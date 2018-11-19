#ifndef HEADER_H
#define HEADER_H
#include "request.h"
#include "types.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HTTP_NEWLINE "\r\n"

HTTP_HEADER* header_list = NULL;
HTTP_HEADER* end = NULL;

void createHeader(char* title, char* value);

void __destroyHeader(HTTP_HEADER* header);

HTTP parseMethod(char* method);

void __clearHeader();

char* const getHeader(HTTP_REQUEST* reqst, char* title);

void parseRequestHeaders(HTTP_REQUEST* reqst, const char* request);

void destroyHeaderList(HTTP_REQUEST* reqst);

#endif