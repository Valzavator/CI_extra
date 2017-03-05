#include <stdio.h>
#include <stdlib.h>
#include <students.h>
#include <string.h>
#include <csv.h>

int main(void) {
    char secondString[] = "Igor, Teterev";
    List *list = CSV_toList(secondString);
    List_print(list);
    List_clear(list);
    char str1[] = "first, qwe,18, 2.3\nsecond, qwe, 20, 4.3\n third, qwe, 22, 3.3";
    char str2[] = "FIRST, qwe,18, 1.1\nSECOND, qwe, 20, 3.1\n THIRD, qwe, 22, 2.1";
    List * list1 = CSV_toList(str1);
    List * list2 = CSV_toList(str2);
    Teacher * first = Teacher_new("Vasya", "Math");
    Teacher * second = Teacher_new("Petya", "Chemistry");
    Teacher_setList(first, list1);
    Teacher_setList(second, list2);
    List_print(list1);
    puts("");
    List_print(list2);
    puts("");    
    List * new = Teacher_getListOfMinScore(first, second,10 );
    List_print(new);
    puts("");
    List_clear(list1);
    List_clear(list2);
    List_clear(new);    
    Teacher_free(&first);
    Teacher_free(&second);
    return EXIT_SUCCESS;
}