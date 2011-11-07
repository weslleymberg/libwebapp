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
HTTPRequest* parse_http_request(char*);

typedef struct http_response
{
    char* httpversion;
    char* status_code;
    char* message;
    Hash* attributes;
} HTTPResponse;

HTTPResponse* new_http_response();

void http_response_set_httpversion(HTTPResponse*, char*);
void http_response_set_status_code(HTTPResponse*, char*);
void http_response_set_message(HTTPResponse*, char*);
void http_response_set_attribute(HTTPResponse*, char*, char*);
char* http_response_get_attribute(HTTPResponse*, char*);
char* http_response_representation(HTTPResponse*);

#endif
