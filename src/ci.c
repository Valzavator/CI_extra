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

struct ListNode {
    void * data;
    ListNode * next;
};

struct List {
    ListNode * head;
};

List * CI_stringToList(const char * str) {
    int i = 0;
    List * list = List_new();
    char buffer[5][30];
    int row = 0, col = 0;
    for (i = 0; i <= strlen(str); i++) {
        char ch = str[i];        
        if ((ch == ';' || ch == '\0') && strlen(buffer[3]) != 0) {
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
        strcat(buffer, "; ");
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
    while ((firstList->head != NULL || secondList != NULL) && count < N && List_count(list) != limits) {
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

void List_removeNode(List * self, ListNode * toRemove) {
    assert(self->head != NULL);
    ListNode * cur = self->head;
    if (Student_getScore(cur->data) == Student_getScore(toRemove->data)) {
        List_removeFirst(self);
        return;
    }
    while (cur->next->next != NULL && Student_getScore(cur->data) == Student_getScore(toRemove->data)) {
        cur = cur->next;
    }
    ListNode * node = cur->next;
    cur->next = node->next;
    ListNode_free(&toRemove);
}

ListNode * List_minScore(List * self) {
    assert(self->head != NULL);
    ListNode * cur = self->head;
    ListNode * min = self->head;
    while (cur != NULL) {
        if (Student_getScore(cur->data) < Student_getScore(min->data)) {
            min = cur;
        }
        cur = cur->next;
    }
    return min;
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

void Student_freeAll(List * self) {
    if (self->head == NULL) throw("NULL reference");
    int i = 0;
    for (i = 0; i < List_count(self); i++) {
        void * cur = List_get(List_elementAt(self, i));
        Student_free(&cur);
    }
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

List * List_new(void) {
    struct List * list = (struct List *)malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}

void List_free(List ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

struct ListNode * ListNode_new(void * data) {
    struct ListNode * node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->data = data;
    return node;
}

void ListNode_free(ListNode ** self) {
    assert(NULL != self);
    Student_free(&(*self)->data);
    free(*self);
    *self = NULL;
}

void List_addFirst(List * self, void * data) {    
    struct ListNode * node = ListNode_new(data);    
    node->next = self->head;
    self->head = node;    
}

void List_addLast(List * self, void * data) {
    struct ListNode * node = ListNode_new(data); 
    if (self->head == NULL) {        
          self->head = node;          
          return;
    }   
    struct ListNode * cur = self->head;
    while (cur->next != NULL) {
          cur = cur->next;
    }
    cur->next = node;
}

int List_insert(List * self, int position, void * data) {
    assert(position >= 0);
    if (position == 0) {
            List_addFirst(self, data);
          return 0;
    }
    struct ListNode * node = ListNode_new(data);
    int i = 0;
    struct ListNode * cur = self->head;
    while (cur->next != NULL && i != position - 1) {
          cur = cur->next;
        i++;
    }
    if (i != position - 1) return 1;
    node->next = cur->next;
    cur->next = node;
    return 0;
}

void List_removeFirst(struct List * self) {
    struct ListNode * node = self->head;
    if (node == NULL) throw("NULL reference");
    self->head = node->next;
    ListNode_free(&node);
}


void List_removeLast(List * self) {
    struct ListNode * cur = self->head;
    if (cur == NULL) throw("NULL reference");
    if (cur->next == NULL) {
          ListNode_free(&cur);
          self->head = NULL;
    }
    while (cur->next->next != NULL) {
          cur = cur->next;
    }
    ListNode_free(&(cur->next));
    cur->next = NULL;
}

void List_removeAt(List * self, int index) {
    assert(index >= 0);
    assert(index < List_count(self));
    if (index == 0) {
        List_removeFirst(self);
        return;
    }
    int i = 0;
    struct ListNode * cur = self->head;
    while (cur->next->next != NULL && i != index - 1) {
        i += 1;
        cur = cur->next;
    }
    if (i != index - 1) throw("Index out of bounds");
    struct ListNode * node = cur->next;
    cur->next = node->next;
    ListNode_free(&node);
}

int List_count(struct List * self) {
    int count = 0;
    struct ListNode * cur = self->head;
    while (cur != NULL) {
          count += 1;
          cur = cur->next;
    }
    return count;
}

struct ListNode * List_elementAt(List * self, int position) {
    assert(position >= 0);
    if (self->head == NULL) throw("list->head = NULL");
    struct ListNode * cur = self->head;
    int count = 0;
    while (cur != NULL && count != position) {
          cur = cur->next;
          count++;
    }
    return cur;
}

List * List_copy(List * toCopy) {
    char buffer[200];
    List * newList = CI_stringToList(CI_listToString(toCopy, buffer));
    return newList;
}

void * List_get(ListNode * self) {
    return self->data;
}

void List_clear(List * self) {
    struct ListNode * cur = self->head;
    while (cur != NULL) {
        struct ListNode * node = cur;
        cur = cur->next; 
        ListNode_free(&node);
    }
    List_free(&self);
}

void List_print(List * self) {
    ListNode * cur = self->head;
    while(cur != NULL) {
        const char * name = Student_getName(cur->data);
        const char * surname = Student_getSurname(cur->data);
        int age = Student_getAge(cur->data);
        float score = Student_getScore(cur->data);
        printf("%s, %s, %i, %.2f\n", name, surname, age, score);
        cur = cur->next;
    }
}

