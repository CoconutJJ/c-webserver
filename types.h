#ifndef TYPES_H
#define TYPES_H
/**
 * HTTP Method Enumerations
 */
typedef enum _http HTTP;

/**
 * HTTP REQUEST METHOD
 * An integer denoting the method type
 */
typedef int HTTP_REQUEST_METHOD;

/**
 * HTTP REQUEST Structure
 */
typedef struct _http_request HTTP_REQUEST;

/**
 * Route Definition and Handler
 */
typedef struct _route_def ROUTE_DEF;

typedef struct _http_header HTTP_HEADER;

/**
 * URL string
 */
typedef char* URL;

/**
 * ROUTE function pointer
 */
typedef char* (*ROUTE)(HTTP_REQUEST*);

typedef ROUTE_DEF* ROUTE_LIST;

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

    HTTP_HEADER* headers;

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

typedef struct _http_header {
    char* title;
    char* value;

    HTTP_HEADER* _next;
    HTTP_HEADER* _prev;

} HTTP_HEADER;

#endif