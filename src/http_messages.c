#include <stdlib.h>
#include <string.h>
#include "http_messages.h"

HTTPRequest* new_http_request()
{
    HTTPRequest* request;
    request = malloc(sizeof(HTTPRequest));
    request->method = malloc(sizeof(char));
    request->path = malloc(sizeof(char));
    request->httpversion = malloc(sizeof(char));
    return request;
}

void set_http_request_method(HTTPRequest* request, char* method)
{
    strcpy(request->method, method);
}

void set_http_request_path(HTTPRequest* request, char* path)
{
    strcpy(request->path, path);
}

void set_http_request_httpversion(HTTPRequest* request, char* httpversion)
{
    strcpy(request->httpversion, httpversion);
}
