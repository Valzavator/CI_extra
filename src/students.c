#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <students.h>
#include <stdbool.h>

#define throw(MSG) assert(0 && MSG);

struct Teacher {
    char surname[20];
    List * students;
    char subject[20];
};

struct Student {
    char name[20];
    char surname[20];
    int age;
    float score;
};

void Teacher_setList(Teacher * self, List * head) {
    self->students = head;
}

List * Teacher_getListOfMinScore(Teacher * first, Teacher * second, int N) {
    List * listMinScore = List_new();
    List * generalList = List_merge(Teacher_getList(first), Teacher_getList(second));
    int limits = List_count(generalList);
    while (List_count(listMinScore) < N && List_count(listMinScore) != limits) {
        ListNode * min = List_minScore(generalList);
        List_addLast(listMinScore,Student_copy(List_get(min)));
        List_removeNode(generalList, min);
    }
    List_clear(generalList);
    return listMinScore;
}

Student * Student_newFromString(char str[4][30]) {
    Student * self = (Student *) malloc(sizeof(Student));
    strcpy(self->name, str[0]);
    strcpy(self->surname, str[1]);
    self->age = atoi(str[2]);
    self->score = atof(str[3]);
    return self;
}

Student * Student_copy(Student * toCopy) {
    Student * self = (Student *) malloc(sizeof(Student));
    strcpy(self->name, toCopy->name);
    strcpy(self->surname, toCopy->surname);
    self->age = toCopy->age;
    self->score = toCopy->score;
    return self;
}

void Student_free(void ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

char * Student_toString(Student * self, char * buffer) {
    sprintf(buffer, "%s, %s, %i, %.1f%c", self->name, self->surname, self->age, self->score, '\0');
    return(buffer);
}

const char * Student_getName(Student * self) {
    return self->name;
}

const char * Student_getSurname(Student * self) {
    return self->surname;
}

int Student_getAge(Student * self) {
    return self->age;
}

float Student_getScore(Student * self) {
    return self->score;
}

Teacher * Teacher_new(const char * surname, const char * subject) {
    Teacher * self = (Teacher *) malloc(sizeof(Teacher));
    strcpy(self->surname, surname);
    strcpy(self->subject, subject);
    self->students = NULL;
    return self;
}

void Teacher_free(Teacher ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

List * Teacher_getList(Teacher * self) {
    return self->students;
}

