#ifndef STUDENTS_H
#define STUDENTS_H

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

typedef struct Teacher Teacher;
typedef struct Student Student;

void Teacher_setList(Teacher * self, List * head);
List * Teacher_getListOfMinScore(Teacher * first, Teacher * second, int N);

Student * Student_newFromString(char str[][30]);
Student * Student_copy(Student * toCopy);
void Student_free(void ** self);

char * Student_toString(Student * self, char * buffer);

const char * Student_getName(Student * self);
const char * Student_getSurname(Student * self);
int Student_getAge(Student * self);
float Student_getScore(Student * self);

Teacher * Teacher_new(const char * surname, const char * subject);
void Teacher_free(Teacher ** self);

List * Teacher_getList(Teacher * self);


#endif
