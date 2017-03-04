#ifndef CI_H
#define CI_H

#include <stdio.h>
#include "list.h"

typedef struct Teacher Teacher;
typedef struct Student Student;


List * CI_stringToList(const char * str);
char * CI_listToString(List * list, char * buffer);
void CI_Teacher_setList(Teacher * self, List * head);
List * CI_minScoreFromTwoTeachers(Teacher * first, Teacher * second, int N);

Student * Student_newFromString(char str[][30]);
Student * Student_copy(Student * toCopy);
void Student_free(void ** self);

char * Student_toString(Student * self, char * buffer);

const char * Student_getName(Student * self);
const char * Student_getSurname(Student * self);
int Student_getAge(Student * self);
float Student_getScore(Student * self);

Teacher * Teacher_new(const char * surname);
void Teacher_free(Teacher ** self);

List * Teacher_getList(Teacher * self);

#endif
