#include <stdio.h>
#include <stdlib.h>

#include <check.h>
#include <ci.h>

START_TEST (CSVToList_string_headOfList);
{
    char str[] = "Vasya, Petrenko,19, 4.1\nPaul, Kozlov, 20, 3.7";
    List * list = CI_CSVToList(str);
    int countNode = 2;
    ck_assert_int_eq(List_count(list), countNode);
    
    const char * name = Student_getName(List_get(List_elementAt(list, 0)));
    const char * surname = Student_getSurname(List_get(List_elementAt(list, 0)));
    int age = Student_getAge(List_get(List_elementAt(list, 0)));
    float score = Student_getScore(List_get(List_elementAt(list, 0)));
    
    ck_assert_str_eq(name, "Vasya");
    ck_assert_str_eq(surname, "Petrenko");
    ck_assert_int_eq(age, 19);
    ck_assert_float_eq(score, 4.1);
    
    name = Student_getName(List_get(List_elementAt(list, 1)));
    surname = Student_getSurname(List_get(List_elementAt(list, 1)));
    age = Student_getAge(List_get(List_elementAt(list, 1)));
    score = Student_getScore(List_get(List_elementAt(list, 1)));
    
    ck_assert_str_eq(name, "Paul");
    ck_assert_str_eq(surname, "Kozlov");
    ck_assert_int_eq(age, 20);
    ck_assert_float_eq(score, 3.7);

    List_clear(list);
}
END_TEST

START_TEST(CSVToList_string_EmptyList)
{
    char firstString[] = "";
    char secondString[] = "Igor, Teterev";
    List * list = CI_CSVToList(firstString);
    ck_assert_int_eq(List_count(list), 0);
    List_clear(list);
    list = CI_CSVToList(secondString);
    ck_assert_int_eq(List_count(list), 0);
    List_clear(list);    
}
END_TEST

START_TEST(listToCSV_list_string)
{
    char str[] = "Vasya, Petrenko, 19, 4.1\nPaul, Kozlov, 20, 3.7";
    List * list = CI_CSVToList(str);
    char * stringCSV = CI_listToCSV(list);
    char correctString[] = "Vasya, Petrenko, 19, 4.1\nPaul, Kozlov, 20, 3.7";
    int a = strlen(stringCSV), b = strlen(correctString);
    puts("");
    puts(stringCSV);
    puts(correctString);
    ck_assert_int_eq(a,b);
    ck_assert_str_eq(stringCSV, correctString);
    List_clear(list);
    free(stringCSV);
}
END_TEST

Suite *test_suite() {
    Suite *s = suite_create("ci.h");
    TCase *tc_CI;
    tc_CI = tcase_create("TestCase");

    tcase_add_test(tc_CI, CSVToList_string_headOfList);
    tcase_add_test(tc_CI, CSVToList_string_EmptyList);
    tcase_add_test(tc_CI, listToCSV_list_string);

    suite_add_tcase(s, tc_CI);
    return s;
}

int main(void) {
    Suite *s = test_suite();
    SRunner *sr = srunner_create(s);
    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_VERBOSE);

    int num_tests_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return num_tests_failed;
}
