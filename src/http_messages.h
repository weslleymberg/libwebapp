#ifndef __HTTP_MESSAGES_H__
#define __HTTP_MESSAGES_H__

typedef struct http_request
{
    char* method;
    char* path;
    char* httpversion;
} HTTPRequest;

HTTPRequest* new_http_request();

void set_http_request_method(HTTPRequest*, char*);
void set_http_request_path(HTTPRequest*, char*);
void set_http_request_httpversion(HTTPRequest*, char*);

#endif
