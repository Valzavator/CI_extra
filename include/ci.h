#ifndef CI_H
#define CI_H

#include <stdio.h>
#include "list.h"
#include <stdbool.h>

typedef struct Teacher Teacher;
typedef struct Student Student;

bool isValid(char buffer[][30]);

List * CI_CSVToList(const char * str);
char * CI_listToCSV(List * list);
void CI_Teacher_setList(Teacher * self, List * head);
List * CI_getListOfMinScore(Teacher * first, Teacher * second, int N);

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
