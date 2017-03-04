#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <check.h>
#include <ci.h>
#include <assert.h>

START_TEST (stringToList_string_headOfList);
{
    char str[2][100] = {"qwe, asda,18, 2.3", "zxc, ppkm, 20, 4.3"};
    List * list = CI_stringToList(str, 2);
    int countNode = 2;
    ck_assert_int_eq(List_count(list), countNode);
    List_clear(list);
}
END_TEST

START_TEST (qwe);
{
    int i = 3;
    ck_assert_int_eq(i, 0);
}
END_TEST

Suite *test_suite() {
    Suite *s = suite_create("ci.h");
    TCase *tc_ProgLang;

    tc_ProgLang = tcase_create("TestCase");

    
    tcase_add_test(tc_ProgLang, stringToList_string_headOfList);
    tcase_add_test(tc_ProgLang, qwe);
    suite_add_tcase(s, tc_ProgLang);

    return s;
}

int main() {
    Suite *s = test_suite();
    SRunner *sr = srunner_create(s);
    srunner_set_fork_status(sr, CK_NOFORK);


    srunner_run_all(sr, CK_VERBOSE);

    int num_tests_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return num_tests_failed;
}
