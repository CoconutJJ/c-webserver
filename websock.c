#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

typedef enum _http HTTP;
/**
 * HTTP REQUEST METHOD
 * An integer denoting the method type
 */
typedef int HTTP_REQUEST_METHOD;

typedef struct _http_request HTTP_REQUEST;

typedef struct _route_def ROUTE_DEF;

typedef char* URL;

/**
 * 
 */
typedef char* (*ROUTE)(HTTP_REQUEST*);

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

typedef struct _http_url {

    

} HTTP_URL;

/**
 * HTTP REQUEST
 * Client Request Structure
 */
typedef struct _http_request {

    HTTP method;
    char* body;
    char* params;
    char* query;

} HTTP_REQUEST;

typedef struct _route_def {
    HTTP_REQUEST_METHOD method;
    ROUTE handler;
    URL url;
} ROUTE_DEF;

typedef ROUTE_DEF* ROUTE_LIST;



ROUTE_LIST _routes;

int route_sz = 0;

void __init_serv(int PORT, char* (*onRecv)(char* response, int* sz))
{

    // create a socket
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (bind(sfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) != 0) {
        perror("bind");
    }

    listen(sfd, 10);

    int cfd;
    char* buf;
    while (1) {

        cfd = accept(sfd, NULL, NULL);

        int curr_buf_sz = 100;
        int bytesread;
        int increment = 100;

        buf = malloc(curr_buf_sz * sizeof(char));

        while ((bytesread = read(cfd, buf, increment - 1)) == increment - 1) {

            buf = realloc(buf, curr_buf_sz + increment);
            buf = buf + increment;
        }

        buf = realloc(buf, curr_buf_sz = curr_buf_sz - increment + bytesread + 1);
        buf[curr_buf_sz - 1] = '\0';

        int response_sz;

        char* response = (*onRecv)(buf, &response_sz);

        write(cfd, response, response_sz);

        free(response);

        close(cfd);
    }
}

char* __onRequest(char* response, int* sz)
{
    
    free(response);
}   

void httpCreateServer(int PORT) { 
    __init_serv(PORT, __onRequest); 


}

void createRoute(HTTP_REQUEST_METHOD method, URL url, ROUTE handler)
{
    if (route_sz == 0) {
        _routes = malloc(sizeof(ROUTE_DEF));
        _routes->method = method;
        _routes->handler = handler;
    } else {
        _routes = realloc(_routes, ++route_sz);
        _routes[route_sz - 1].method = method;
    }
}

void serveRoute()
