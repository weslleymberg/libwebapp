#ifndef __HTTP_MESSAGES_H__
#define __HTTP_MESSAGES_H__

typedef struct http_request
{
    char* method;
} HTTPRequest;

HTTPRequest* new_http_request();

void set_http_request_method(HTTPRequest*, char*);

#endif
