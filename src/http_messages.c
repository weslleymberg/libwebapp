#include <stdlib.h>
#include <string.h>
#include "http_messages.h"
#include "hash.h"

HTTPRequest* new_http_request()
{
    HTTPRequest* request;
    request = malloc(sizeof(HTTPRequest));
    request->method = malloc(sizeof(char));
    request->path = malloc(sizeof(char));
    request->httpversion = malloc(sizeof(char));
    request->attributes = new_hash();
    return request;
}

void http_request_set_method(HTTPRequest* request, char* method)
{
    strcpy(request->method, method);
}

void http_request_set_path(HTTPRequest* request, char* path)
{
    strcpy(request->path, path);
}

void http_request_set_httpversion(HTTPRequest* request, char* httpversion)
{
    strcpy(request->httpversion, httpversion);
}

void http_request_set_attribute(HTTPRequest* request, char* key, char* value)
{
    hash_set(request->attributes, key, value);
}

char* http_request_get_attribute(HTTPRequest* request, char* key)
{
    return hash_get(request->attributes, key);
}
