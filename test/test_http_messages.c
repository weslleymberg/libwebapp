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
    set_http_request_method(request, "GET");
    CU_ASSERT(strcmp(request->method, "GET") == 0);
}

void test_http_request_path(void)
{
    HTTPRequest* request;
    request = new_http_request();
    set_http_request_path(request, "/path_to_resource");
    CU_ASSERT(strcmp(request->path, "/path_to_resource") == 0);
}

void test_http_request_httpversion(void)
{
    HTTPRequest* request;
    request = new_http_request();
    set_http_request_httpversion(request, "HTTP/1.1");
    CU_ASSERT(strcmp(request->httpversion, "HTTP/1.1") == 0);
}

int test_http_request_teardown(void)
{
    return 0;
}
