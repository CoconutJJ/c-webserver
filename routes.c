#include "types.h"
#include <stdio.h>
#include <stdlib.h>


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


void _serveRoute(URL url) {
    for (int i = 0; i < route_sz; i++) {
        
    }
}
