#ifndef __TEST_HTTP_MESSAGES_H__
#define __TEST_HTTP_MESSAGES_H__

int test_http_request_setup(void);

void test_http_request_method(void);
void test_http_request_path(void);
void test_http_request_httpversion(void);
void test_http_request_attributes(void);
void test_http_request_parse(void);

int test_http_request_teardown(void);

int test_http_response_setup(void);

void test_http_response_httpversion(void);
void test_http_response_status_code(void);
void test_http_response_message(void);
void test_http_response_attributes(void);
void test_http_response_representation(void);

int test_http_response_teardown(void);

#endif
