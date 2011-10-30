#include <CUnit/Basic.h>
#include "test_http_messages.h"

int main()
{
    CU_pSuite pSuite = NULL;
    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();
    pSuite = CU_add_suite("HTTP Request", test_http_request_setup, test_http_request_teardown);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (CU_add_test(pSuite, "it has a method", test_http_request_method) == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
