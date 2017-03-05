#ifndef LIST_H
#define LIST_H

typedef struct ListNode ListNode;
typedef struct List List;


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

int List_count(List * self);
List * List_copy(List * toCopy);

ListNode * List_minScore(List * self);
List * List_merge(List * firstList, List * secondList);

void * List_get(ListNode * self);

void List_clear(List * self);

#endif