#ifndef __HTTP_MESSAGES_H__
#define __HTTP_MESSAGES_H__

#include "hash.h"

typedef struct http_request
{
    char* method;
    char* path;
    char* httpversion;
    Hash* attributes;
} HTTPRequest;

HTTPRequest* new_http_request();

void http_request_set_method(HTTPRequest*, char*);
void http_request_set_path(HTTPRequest*, char*);
void http_request_set_httpversion(HTTPRequest*, char*);
void http_request_set_attribute(HTTPRequest*, char*, char*);
char* http_request_get_attribute(HTTPRequest*, char*);

#endif
