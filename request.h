#include "types.h"

HTTP_REQUEST* createHTTPRequest();

void setRequestURL(HTTP_REQUEST * reqst, URL url);
void destroyHTTPRequest(HTTP_REQUEST * req);