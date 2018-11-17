
#include "types.h"

/**
 * HTTP Request Method Constants
 */
typedef enum _http {
    POST = 0b000001,
    GET = 0b000010,
    PUT = 0b000100,
    DELETE = 0b001000,
    PATCH = 0b010000,
    HEAD = 0b100000,

} HTTP;

/**
 * HTTP URL Structure
 */
typedef struct _http_url {

    char* scheme;
    char* domian;
    char* pathname;
    char* querystring;

} HTTP_URL;


/**
 * HTTP REQUEST
 * Client Request Structure
 */
typedef struct _http_request {

    HTTP method;
    
    URL url;

    char* body;
    char* params;
    char* query;

} HTTP_REQUEST;

/**
 * ROUTE DEF.
 * Structure representing a single route
 */
typedef struct _route_def {
    HTTP_REQUEST_METHOD method;
    ROUTE handler;
    URL url;
} ROUTE_DEF;
