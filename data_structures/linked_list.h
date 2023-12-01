#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct LinkedList LinkedList;
struct LinkedList {
    void *value;
    LinkedList *next;
};

LinkedList *linked_list_create(void *value) {

}

void linked_list_destroy(LinkedList *list) {

}

void linked_list_append(LinkedList **list, void *value) {

}

void linked_list_prepend(LinkedList **list, void *value) {

}

void linked_list_insert(LinkedList **list, void *value, int index) {

}

void *linked_list_remove(LinkedList **list, int index) {

}

int linked_list_length(LinkedList *list) {

}

void *linked_list_get(LinkedList *list, int index) {

}

void linked_list_set(LinkedList *list, void *value, int index) {

}

void *linked_list_swap(LinkedList *list, void *value, int index) {

}

#endif