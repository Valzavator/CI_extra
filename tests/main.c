#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include <csv.h>
#include <students.h>
#include <list.h>


///////////////////////////////////////////////
//       tests for functions of task         //
//////////////////////////////////////////////

START_TEST (CSVToList_string_headOfList);
{
    char str[] = "Vasya, Petrenko,19, 4.1\nPaul, Kozlov, 20, 3.7";
    List * list = CSV_toList(str);
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
    char firstString[] = ",,,";
    char secondString[] = "Igor, Teterev\nIgor, Teterev,,2";
    char thirdString[] = "\n";    
    char fourthStrung[] = "Max, Klimko, one, two\nIgor, Teterev, 2,\n";
    List * list = CSV_toList(firstString);
    ck_assert_int_eq(List_count(list), 0);
    List_clear(list);
    list = CSV_toList(secondString);
    ck_assert_int_eq(List_count(list), 0);
    list = CSV_toList(thirdString);
    ck_assert_int_eq(List_count(list), 0);    
    list = CSV_toList(fourthStrung);
    ck_assert_int_eq(List_count(list), 0);   
    List_clear(list);    
}
END_TEST

START_TEST(listToCSV_list_string)
{
    char str[] = "Vasya, Petrenko, 19, 4.1\nPaul, Kozlov, 20, 3.7";
    List * list = CSV_toList(str);
    char * stringCSV = CSV_fromList(list);
    char correctString[] = "Vasya, Petrenko, 19, 4.1\nPaul, Kozlov, 20, 3.7";
    ck_assert_str_eq(stringCSV, correctString);
    List_clear(list);
    free(stringCSV);
}
END_TEST

START_TEST(listToCSV_emptyList_emptyString)
{
    List * list = List_new();
    char * stringCSV = CSV_fromList(list);
    int length = strlen(stringCSV);
    ck_assert_int_eq(length, 0);
    List_clear(list);
    free(stringCSV);
}
END_TEST

START_TEST(setList_teacher_teachetGetList) 
{
    Teacher * self = Teacher_new("Valentina", "Mathemetics");
    char str[] = "Vasya, Petrenko, 19, 4.1\nPaul, Kozlov, 20, 3.7";
    List * list = CSV_toList(str);
    Teacher_setList(self, list);
    List * listTeacher = Teacher_getList(self);
    ck_assert_ptr_eq(list, listTeacher);
    List_clear(list);
    Teacher_free(&self);
}
END_TEST

START_TEST(getListOfMinScore_twoTeachersAndN_ListNStudents)
{
    char firstStr[] = "Vasya, Petrenko, 19, 4.1\nPaul, Kozlov, 20, 3.7";
    char secondStr[] = "Ann, Kilich, 20, 4.7\nPetro, Spivak, 21, 3.9";
    List * firstList = CSV_toList(firstStr);
    List * secondList = CSV_toList(secondStr);
    Teacher * firstTeacher = Teacher_new("Vasya", "Math");
    Teacher * secondTeacher = Teacher_new("Petya", "Chemistry");
    Teacher_setList(firstTeacher, firstList);
    Teacher_setList(secondTeacher, secondList);
    List * listMinScore = Teacher_getListOfMinScore(firstTeacher, secondTeacher, 3);
    int countNode = 3;

    ck_assert_int_eq(List_count(listMinScore), countNode);

    float minValue = Student_getScore(List_get(List_elementAt(listMinScore, 0)));
    float averageValue = Student_getScore(List_get(List_elementAt(listMinScore, 1)));
    float maxValue = Student_getScore(List_get(List_elementAt(listMinScore, 2)));
    
    ck_assert_float_eq(minValue, 3.7);
    ck_assert_float_eq(averageValue, 3.9);
    ck_assert_float_eq(maxValue, 4.1);

    List_clear(listMinScore);
    List_clear(firstList);
    List_clear(secondList);
    Teacher_free(&firstTeacher);
    Teacher_free(&secondTeacher);
}
END_TEST

START_TEST(getListOfMinScore_twoTeachersAndN_NULL)
{
    char firstStr[] = "";
    char secondStr[] = "";
    List * firstList = CSV_toList(firstStr);
    List * secondList = CSV_toList(secondStr);
    Teacher * firstTeacher = Teacher_new("Vasya", "Math");
    Teacher * secondTeacher = Teacher_new("Petya", "Chemistry");
    Teacher_setList(firstTeacher, firstList);
    Teacher_setList(secondTeacher, secondList);
    List * listMinScore = Teacher_getListOfMinScore(firstTeacher, secondTeacher, 3);
    int countNode = 0;

    ck_assert_int_eq(List_count(listMinScore), countNode);
    
    List_clear(listMinScore);
    List_clear(firstList);
    List_clear(secondList);
    Teacher_free(&firstTeacher);
    Teacher_free(&secondTeacher);
}
END_TEST

///////////////////////////////////////////////
//          tests for list.h                 //
//////////////////////////////////////////////

START_TEST(new_void_headOfList) 
{
    List * head = List_new();
    ck_assert_ptr_ne(head, NULL);
    List_free(&head);
}
END_TEST

START_TEST(free_list_freeMemory) 
{
    List * head = List_new();
    ck_assert_ptr_ne(head, NULL);
    List_free(&head);
    ck_assert_ptr_eq(head, NULL);    
}
END_TEST

START_TEST(addFirst_listANDdata_addNodeToHead) 
{
    List * head = List_new();
    int * one = malloc(sizeof(int));
    int * two = malloc(sizeof(int));
    *one = 1;
    *two = 2;
    ck_assert_int_eq(List_count(head), 0);
    List_addFirst(head, one);
    ck_assert_int_eq(List_count(head), 1);
    List_addFirst(head, two);
    ck_assert_int_eq(*((int *) List_get(List_elementAt(head, 0))), *two);
    List_clear(head);
}
END_TEST

START_TEST(insert_listANDpositionANDdata_addNodeToPosition) 
{
    List * head = List_new();
    int * one = malloc(sizeof(int));
    int * two = malloc(sizeof(int));
    int * three = malloc(sizeof(int));
    *one = 1;
    *two = 2;
    * three = 3;
    List_addFirst(head, one);
    List_insert(head, 0, two); 
    ck_assert_int_eq(List_count(head), 2);
    ck_assert_int_eq(*((int *) List_get(List_elementAt(head, 0))), *two);
    List_insert(head, 2, three); 
    ck_assert_int_eq(List_count(head), 3);
    ck_assert_int_eq(*((int *) List_get(List_elementAt(head, 2))), *three);
    List_clear(head);
}
END_TEST

START_TEST(removeLast_list_removeLastNode) 
{
    List * head = List_new();
    int * one = malloc(sizeof(int));
    int * two = malloc(sizeof(int));
    int * three = malloc(sizeof(int));
    *one = 1;
    *two = 2;
    * three = 3;
    List_addFirst(head, three);
    List_addFirst(head, two);
    List_addFirst(head, one);
    ck_assert_int_eq(List_count(head), 3);
    List_removeLast(head);
    ck_assert_int_eq(List_count(head), 2);
    ck_assert_int_eq(*((int *) List_get(List_elementAt(head, 1))), *two);    
    List_clear(head);
}
END_TEST


Suite *test_suite() {
    Suite *s = suite_create("CI_extra");
    TCase *tc_CI;
    TCase *tc_list;
    tc_CI = tcase_create("mainFunction");
    tc_list = tcase_create("list");

    tcase_add_test(tc_CI, CSVToList_string_headOfList);
    tcase_add_test(tc_CI, CSVToList_string_EmptyList);
    tcase_add_test(tc_CI, listToCSV_list_string);
    tcase_add_test(tc_CI, listToCSV_emptyList_emptyString);
    tcase_add_test(tc_CI, setList_teacher_teachetGetList);
    tcase_add_test(tc_CI, getListOfMinScore_twoTeachersAndN_ListNStudents);
    tcase_add_test(tc_CI, getListOfMinScore_twoTeachersAndN_NULL);

    tcase_add_test(tc_list, new_void_headOfList);
    tcase_add_test(tc_list, addFirst_listANDdata_addNodeToHead);
    tcase_add_test(tc_list, insert_listANDpositionANDdata_addNodeToPosition);
    tcase_add_test(tc_list, free_list_freeMemory);
    tcase_add_test(tc_list, removeLast_list_removeLastNode);

    suite_add_tcase(s, tc_CI);
    suite_add_tcase(s, tc_list);
    
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
