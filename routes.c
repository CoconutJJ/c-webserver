#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#include "request.h"
ROUTE_LIST _routes;

int route_sz = 0;

void createRoute(HTTP_REQUEST_METHOD method, URL url, ROUTE handler)
{
    if (route_sz == 0) {
        _routes = malloc(sizeof(ROUTE_DEF));
        _routes->method = method;
        _routes->handler = handler;
        _routes->url = url;
    } else {
        _routes = realloc(_routes, ++route_sz);
        _routes[route_sz - 1].method    = method;
        _routes[route_sz - 1].handler   = handler;
        _routes[route_sz - 1].url       = url;
    }
}


void _serveRoute(HTTP_REQUEST * req) {

    
    for (int i = 0; i < route_sz; i++) {
        if (strcmp(_routes[i].url, req->url) == 0 && _routes[i].method == req->method) {
            _routes[i].handler(req);
        }
    }
}

void serveRoute(HTTP_REQUEST * req) {
    _serveRoute(req);
}