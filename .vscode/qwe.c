#include <stdio.h>
#include <stdlib.h>
#include <ci.h>


int main(void) {
    char str1[][100] = { "first, qwe,18, 2.3", "second, qwe, 20, 4.3" ,"third, qwe, 22, 3.3"};
    char str2[][100] = {"FIRST, qwe,18, 1.1", "SECOND, qwe, 20, 3.1", " THIRD, qwe, 22, 2.1"};
    List * list1 = CI_stringToList(str1, 3);
    List * list2 = CI_stringToList(str2, 3);
    Teacher * first = Teacher_new("Vasya");
    Teacher * second = Teacher_new("Petya");
    CI_Teacher_setList(first, list1);
    CI_Teacher_setList(second, list2);
    List_print(list1);
    puts("");
    List_print(list2);
    puts("");    
    List * new = CI_minScoreFromTwoTeachers(first, second, 10);
    List_print(new);
    List_clear(list1);
    List_clear(list2);
    List_clear(new);    
    Teacher_free(&first);
    Teacher_free(&second);
    return EXIT_SUCCESS;
}

