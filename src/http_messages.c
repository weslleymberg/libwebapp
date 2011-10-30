#include <stdlib.h>
#include <string.h>
#include "http_messages.h"

HTTPRequest* new_http_request()
{
    HTTPRequest* request;
    request = malloc(sizeof(HTTPRequest));
    request->method = malloc(sizeof(char));
    return request;
}

void set_http_request_method(HTTPRequest* request, char* method)
{
    strcpy(request->method, method);
}
