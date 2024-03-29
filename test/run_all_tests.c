#include <CUnit/Basic.h>
#include "test_http_messages.h"
#include "test_hash.h"
#include "test_iterator.h"

int main()
{
    CU_pSuite httprequest_pSuite = NULL;
    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();
    httprequest_pSuite = CU_add_suite("HTTP Request", test_http_request_setup, test_http_request_teardown);
    if (httprequest_pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if ((CU_add_test(httprequest_pSuite, "it has a method", test_http_request_method) == NULL) ||
        (CU_add_test(httprequest_pSuite, "it has a path", test_http_request_path) == NULL) ||
        (CU_add_test(httprequest_pSuite, "it has a http version", test_http_request_httpversion) == NULL) ||
        (CU_add_test(httprequest_pSuite, "it has attributes", test_http_request_attributes) == NULL) ||
        (CU_add_test(httprequest_pSuite, "it can be a result of a parser", test_http_request_parse) == NULL))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    httprequest_pSuite = CU_add_suite("HTTP Response", test_http_response_setup, test_http_response_teardown);
    if (httprequest_pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if ((CU_add_test(httprequest_pSuite, "it has a http version", test_http_response_httpversion) == NULL) ||
        (CU_add_test(httprequest_pSuite, "it has a status code", test_http_response_status_code) == NULL) ||
        (CU_add_test(httprequest_pSuite, "it has a message", test_http_response_message) == NULL) ||
        (CU_add_test(httprequest_pSuite, "it has attributes", test_http_response_attributes) == NULL) ||
        (CU_add_test(httprequest_pSuite, "it can generate a string", test_http_response_representation) == NULL))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_pSuite hash_pSuite = NULL;
    hash_pSuite = CU_add_suite("Hash", test_hash_setup, test_hash_teardown);
    if (hash_pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if ((CU_add_test(hash_pSuite, "it creates an item using set method", test_hash_create_item) == NULL) ||
        (CU_add_test(hash_pSuite, "it sets an item if the key already exists", test_hash_set_item) == NULL) ||
        (CU_add_test(hash_pSuite, "it returns a value matched to a key", test_hash_get_value) == NULL))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_pSuite iterator_pSuite = NULL;
    iterator_pSuite = CU_add_suite("Iterator", test_iterator_setup, test_iterator_teardown);
    if (iterator_pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if ((CU_add_test(iterator_pSuite, "it returns the next part of a string", test_iterator_next) == NULL) ||
        (CU_add_test(iterator_pSuite, "it can return the next line of a string", test_iterator_next_line) == NULL) ||
        (CU_add_test(iterator_pSuite, "it can return the next word of a string", test_iterator_next_word) == NULL))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
