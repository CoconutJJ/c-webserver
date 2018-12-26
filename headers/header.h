#ifndef HEADER_H
#define HEADER_H
#include "../types/types.h"

HTTP_HEADER *createHeader(const char *key, const char *value);
void addHeader(HTTP_HEADER *head, HTTP_HEADER *newp);

#endif