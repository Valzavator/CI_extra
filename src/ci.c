#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <ci.h>

#define throw(MSG) assert(0 && MSG);

struct Teacher {
    char surname[20];
    List * students;
};

struct Student {
    char name[20];
    char surname[20];
    int age;
    float score;
};



List * CI_stringToList(const char * str) {
    int i = 0;
    List * list = List_new();
    char buffer[5][30];
    int row = 0, col = 0;
    for (i = 0; i <= strlen(str); i++) {
        char ch = str[i];        
        if ((ch == '\n' || ch == '\0') && strlen(buffer[3]) != 0) {
            List_addLast(list, Student_newFromString(buffer));
            buffer[3][0] = '\0';
            row = 0;
            continue;
        }
        if (ch == ',') {
            row++;
            continue;
        }
        if (isspace(ch)) continue;
        if (isalpha(ch) || isdigit(ch)) {
            while (isalpha(str[i]) || isdigit(str[i]) || str[i] == '.') {
                buffer[row][col] = str[i];
                col++;
                i++;
            }
            buffer[row][col] = '\0';            
            col = 0;
            i--;            
        }
    }
    return list;
}


char * CI_listToString(List * list, char * buffer) {
    char str[100];
    buffer[0] = '\0';
    int i = 0;
    for (i = 0; i < List_count(list); i++) {
        Student_toString(List_get(List_elementAt(list, i)), str);
        strcat(buffer, str);
        strcat(buffer, "\n");
    }
    return buffer; 
}

void CI_Teacher_setList(Teacher * self, List * head) {
    self->students = head;
}

List * CI_minScoreFromTwoTeachers(Teacher * first, Teacher * second, int N) {
    List * list = List_new();
    List * firstList = List_copy(Teacher_getList(first));
    List * secondList = List_copy(Teacher_getList(second));
    int count = 0;
    int index = 1;
    int limits = List_count(firstList) + List_count(secondList);
    while (count < N && List_count(list) != limits) {
        if (N > 1) {
            ListNode * minFirst = List_minScore(firstList);
            ListNode * minSecond = List_minScore(secondList);
            List_addFirst(list,Student_copy(List_get(minFirst)));
            List_insert(list, index, Student_copy(List_get(minSecond)));
            List_removeNode(firstList, minFirst);
            List_removeNode(secondList, minSecond);
            N -=2;        
        } else {
            ListNode * minFirst = List_minScore(firstList);
            List_addFirst(list,Student_copy(List_get(minFirst)));
            List_removeNode(firstList, minFirst);
            N--;
        }
        index++;
    }
    List_clear(firstList);
    List_clear(secondList);
    return list;
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
    sprintf(buffer, "%s, %s, %i, %.2f%c", self->name, self->surname, self->age, self->score, '\0');
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

Teacher * Teacher_new(const char * surname) {
    Teacher * self = (Teacher *) malloc(sizeof(Teacher));
    strcpy(self->surname, surname);
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

