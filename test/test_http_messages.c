#include <CUnit/CUnit.h>
#include <string.h>
#include "test_http_messages.h"
#include "../src/http_messages.h"

int test_http_request_setup(void)
{
    return 0;
}

void test_http_request_method(void)
{
    HTTPRequest* request;
    request = new_http_request();
    http_request_set_method(request, "GET");
    CU_ASSERT(strcmp(request->method, "GET") == 0);
}

void test_http_request_path(void)
{
    HTTPRequest* request;
    request = new_http_request();
    http_request_set_path(request, "/path_to_resource");
    CU_ASSERT(strcmp(request->path, "/path_to_resource") == 0);
}

void test_http_request_httpversion(void)
{
    HTTPRequest* request;
    request = new_http_request();
    http_request_set_httpversion(request, "HTTP/1.1");
    CU_ASSERT(strcmp(request->httpversion, "HTTP/1.1") == 0);
}

void test_http_request_attributes(void)
{
    HTTPRequest* request;
    char* host;
    request = new_http_request();
    http_request_set_attribute(request, "Host", "www.example.com");
    host = http_request_get_attribute(request, "Host");
    CU_ASSERT(strcmp(host, "www.example.com") == 0);
}

void test_http_request_parse(void)
{
    char request_text[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    HTTPRequest* request;
    char* host;
    request = parse_http_request(request_text);
    CU_ASSERT(strcmp(request->method, "GET") == 0);
    CU_ASSERT(strcmp(request->path, "/") == 0);
    CU_ASSERT(strcmp(request->httpversion, "HTTP/1.1") == 0);
    host = http_request_get_attribute(request, "Host");
    CU_ASSERT(strcmp(host, "www.example.com") == 0);
}

int test_http_request_teardown(void)
{
    return 0;
}
