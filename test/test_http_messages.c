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

int test_http_request_teardown(void)
{
    return 0;
}
