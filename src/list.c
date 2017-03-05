#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <list.h>
#include <students.h>
#include <csv.h>

#define throw(MSG) assert(0 && MSG);

struct ListNode {
    void * data;
    ListNode * next;
};

struct List {
    ListNode * head;
};

List * List_new(void) {
    List * list = (List *)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void List_free(List ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

ListNode * ListNode_new(void * data) {
    ListNode * node = (ListNode *) malloc(sizeof(ListNode));
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
    ListNode * node = ListNode_new(data);    
    node->next = self->head;
    self->head = node;    
}

void List_addLast(List * self, void * data) {
    ListNode * node = ListNode_new(data); 
    if (self->head == NULL) {        
          self->head = node;          
          return;
    }   
    ListNode * cur = self->head;
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
    ListNode * node = ListNode_new(data);
    int i = 0;
    ListNode * cur = self->head;
    while (cur->next != NULL && i != position - 1) {
          cur = cur->next;
        i++;
    }
    if (i != position - 1) return 1;
    node->next = cur->next;
    cur->next = node;
    return 0;
}

void List_removeFirst(List * self) {
    ListNode * node = self->head;
    if (node == NULL) throw("NULL reference");
    self->head = node->next;
    ListNode_free(&node);
}


void List_removeLast(List * self) {
    ListNode * cur = self->head;
    if (cur == NULL) throw("NULL reference");
    if (cur->next == NULL) {
          ListNode_free(&cur);
          self->head = NULL;
          return;
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
    ListNode * cur = self->head;
    while (cur->next->next != NULL && i != index - 1) {
        i += 1;
        cur = cur->next;
    }
    if (i != index - 1) throw("Index out of bounds");
    ListNode * node = cur->next;
    cur->next = node->next;
    ListNode_free(&node);
}

int List_count(List * self) {
    int count = 0;
    ListNode * cur = self->head;
    while (cur != NULL) {
          count += 1;
          cur = cur->next;
    }
    return count;
}

ListNode * List_elementAt(List * self, int position) {
    assert(position >= 0);
    if (self->head == NULL) throw("list->head = NULL");
    ListNode * cur = self->head;
    int count = 0;
    while (cur != NULL && count != position) {
          cur = cur->next;
          count++;
    }
    return cur;
}

List * List_copy(List * toCopy) {
    char * string = CSV_fromList(toCopy);
    List * newList = CSV_toList(string);
    free(string);
    return newList;
}

void List_removeNode(List * self, ListNode * toRemove) {
    assert(self->head != NULL);
    ListNode * cur = self->head;
    if (Student_getScore(cur->data) - Student_getScore(toRemove->data) < 0.1) {
        List_removeFirst(self);
        return;
    }
    while (cur->next->next != NULL && !(Student_getScore(cur->next->data) - Student_getScore(toRemove->data) < 0.1)) {
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

List * List_merge(List * firstList, List * secondList) {
    if (firstList->head == NULL && secondList->head == NULL) return List_new();
    if (firstList->head == NULL) return secondList;
    if (secondList->head == NULL) return firstList;
    List * begin = List_copy(firstList);
    List * end = List_copy(secondList);
    ListNode * node = List_elementAt(begin, List_count(begin) - 1);
    node->next = end->head;
    List_free(&end);
    return begin;
}

void * List_get(ListNode * self) {
    return self->data;
}

void List_clear(List * self) {
    ListNode * cur = self->head;
    while (cur != NULL) {
        ListNode * node = cur;
        cur = cur->next; 
        ListNode_free(&node);
    }
    List_free(&self);
}