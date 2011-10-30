#include <CUnit/Basic.h>
#include "test_http_messages.h"
#include "test_hash.h"

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
        (CU_add_test(httprequest_pSuite, "it has a http version", test_http_request_httpversion) == NULL))
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
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
