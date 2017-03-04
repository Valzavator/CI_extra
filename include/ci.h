#ifndef CI_H
#define CI_H

#include <stdio.h>

typedef struct Teacher Teacher;
typedef struct Student Student;
typedef struct ListNode ListNode;
typedef struct List List;

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

List * List_new(void);
void List_free(List ** self);

ListNode * ListNode_new(void * data);
void ListNode_free(ListNode ** self);

void List_addFirst(List * self, void * data);
void List_addLast(List * self, void * data);
int List_insert(List * self, int position, void * data);

void List_removeFirst(List * self);
void List_removeLast(List * self);
void List_removeAt(List * self, int position);
void List_removeNode(List * self, ListNode * toRemove);
ListNode * List_elementAt(List * self, int position);

void * List_get(ListNode * self);
int List_count(List * self);
List * List_copy(List * toCopy);

ListNode * List_minScore(List * self);

void List_clear(List * self);

void List_print(List * self);

#endif
