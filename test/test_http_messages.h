#ifndef __TEST_HTTP_MESSAGES_H__
#define __TEST_HTTP_MESSAGES_H__

int test_http_request_setup(void);

void test_http_request_method(void);
void test_http_request_path(void);
void test_http_request_httpversion(void);

int test_http_request_teardown(void);

#endif
