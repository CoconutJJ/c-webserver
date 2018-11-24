#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include "types.h"
#include "request.h"
#include "headers.h" 
#include "routes.h"
void __init_serv(int PORT, char* (*onRecv)(char* response, int* sz))
{

    // create a socket
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    // attempt to bind port
    if (bind(sfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) != 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    listen(sfd, 10);

    int cfd;
    
    char* buf;

    while (1) {
        // accept a connection
        cfd = accept(sfd, NULL, NULL);

        // initialize buffer size to 100 bytes
        int curr_buf_sz = 100;

        // store the number of bytes read
        int bytesread;

        // increment delta
        int increment = 100;

        // create a buffer of size curr_buf_sz
        buf = malloc(curr_buf_sz * sizeof(char));
        
        char * next = &buf[0];
        // read until the number of bytes left is less than the given read amount
        while ((bytesread = read(cfd, next, increment - 1)) == increment - 1) {

            buf = realloc(buf, curr_buf_sz = curr_buf_sz + increment);
            next = next + increment;
        }
        // remove the extra space at the end
        buf = realloc(buf, curr_buf_sz = curr_buf_sz - increment + bytesread + 1);
        
        buf[curr_buf_sz - 1] = '\0';

        int response_sz;
        
        char* response = (*onRecv)(buf, &response_sz);

        write(cfd, response, response_sz);

        free(response);

        close(cfd);
    }
}

char* __onRequest(char* request, int* sz)
{
    HTTP_REQUEST * new_req = createHTTPRequest();
    parseRequestHeaders(new_req, request);
    serveRoute(new_req);
    
}

void httpCreateServer(int PORT)
{
    __init_serv(PORT, __onRequest);
}


int main(int argc, char ** argv) {
    
}
