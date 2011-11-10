#include <CUnit/CUnit.h>
#include <string.h>
#include "test_http_messages.h"
#include "libwebapp/http_messages.h"

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

int test_http_response_setup(void)
{
    return 0;
}

void test_http_response_httpversion(void)
{
    HTTPResponse* response;
    response = new_http_response();
    http_response_set_httpversion(response, "HTTP/1.1");
    CU_ASSERT(strcmp(response->httpversion, "HTTP/1.1") == 0);
}

void test_http_response_status_code(void)
{
    HTTPResponse* response;
    response = new_http_response();
    http_response_set_status_code(response, "200");
    CU_ASSERT(strcmp(response->status_code, "200") == 0);
}

void test_http_response_message(void)
{
    HTTPResponse* response;
    response = new_http_response();
    http_response_set_message(response, "OK");
    CU_ASSERT(strcmp(response->message, "OK") == 0);
}

void test_http_response_attributes(void)
{
    HTTPResponse* response;
    char* host;
    response = new_http_response();
    http_response_set_attribute(response, "Host", "www.example.com");
    host = http_response_get_attribute(response, "Host");
    CU_ASSERT(strcmp(host, "www.example.com") == 0);
}

void test_http_response_representation(void)
{
    HTTPResponse* response;
    char* response_representation;
    response = new_http_response();
    http_response_set_httpversion(response, "HTTP/1.1");
    http_response_set_status_code(response, "200");
    http_response_set_message(response, "OK");
    http_response_set_attribute(response, "Host", "www.example.com");
    response_representation = http_response_representation(response);
    CU_ASSERT(strcmp(response_representation, "HTTP/1.1 200 \"OK\"\r\nHost: www.example.com\r\n\r\n") == 0);
}

int test_http_response_teardown(void)
{
    return 0;
}
