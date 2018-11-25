
typedef struct _http_response HTTP_RESPONSE;
typedef struct _http_request HTTP_REQUEST;
typedef struct _http_header HTTP_HEADER;
typedef enum _http_method HTTP_METHOD;

typedef struct _http_response
{
    char *body;
    char *status_message; // Response message (OK, Not Modified, etc..)

    HTTP_HEADER *headers; // Response headers list
    int header_count; // Number of headers
    int status; // Response status (200, 301, etc..)

} HTTP_RESPONSE;

typedef struct _http_request
{

} HTTP_REQUEST;

typedef struct _http_header
{
    char * key;
    char * value;
    HTTP_HEADER * _next;
    HTTP_HEADER * _prev;

} HTTP_HEADER;

typedef enum _http_method
{

} HTTP_METHOD;
