#include "request.h"
#include "types.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HTTP_NEWLINE "\r\n"

HTTP_HEADER* header_list = NULL;
HTTP_HEADER* end = NULL;

void createHeader(char* title, char* value)
{

    HTTP_HEADER* new_header = malloc(sizeof(HTTP_HEADER));

    new_header->title = malloc(strlen(title) + 1);
    strcpy(new_header->title, title);

    new_header->value = malloc(strlen(value) + 1);
    strcpy(new_header->value, value);

    // create the header linked list
    if (header_list == NULL) {
        header_list = new_header;
        end = new_header;
        new_header->_prev = NULL;
        new_header->_next = NULL;
    } else {
        end->_next = new_header;
        new_header->_prev = end;
        new_header->_next = NULL;
        end = new_header;
    }
}

void __destroyHeader(HTTP_HEADER * header) {
    free(header->title);
    free(header->value);
    free(header);
}

HTTP parseMethod(char* method)
{
    HTTP m;
    if (strcmp(method, "POST") == 0) {
        return POST;
    } else if (strcmp(method, "GET") == 0) {
        return GET;
    } else if (strcmp(method, "PUT") == 0) {
        return PUT;
    } else if (strcmp(method, "PATCH") == 0) {
        return PATCH;
    }
}

void __clearHeader()
{
    header_list = NULL;
    end = NULL;
}

char* const getHeader(HTTP_REQUEST* reqst, char* title)
{

    HTTP_HEADER* curr_header = reqst->headers;

    while (strcmp(curr_header->title, title) != 0) {

        curr_header = curr_header->_next;

        if (!curr_header)
            return NULL;
    }

    return curr_header->value;
}

void parseRequestHeaders(HTTP_REQUEST* reqst, const char* request)
{

    char req[strlen(request) + 1];
    strcpy(req, request);

    // parse the token
    char* tok = strtok(req, HTTP_NEWLINE);

    char* toks[3];

    tokenize(tok, toks, 3, " ");

    char* method = toks[0];
    char* url = toks[1];
    char* http = toks[2];

    reqst->method = parseMethod(method);
    reqst->url = url;
    tok = strtok(NULL, HTTP_NEWLINE);

    while (tok != NULL) {

        char* head_toks[2];

        tokenize(tok, head_toks, 2, ":");

        createHeader(head_toks[0], head_toks[1]);

        tok = strtok(NULL, HTTP_NEWLINE);
    }

    reqst->headers = header_list;

    __clearHeader();
}

void destroyHeaderList(HTTP_REQUEST * reqst) {
    HTTP_HEADER * curr_header = reqst->headers;

    while (curr_header->_next) {
        curr_header = curr_header->_next;
        __destroyHeader(curr_header->_prev);
    }
    __destroyHeader(curr_header);
}