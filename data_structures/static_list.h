/*
    AUTHOR: Gabriel Leite Bessa
    GITHUB: https://github.com/glbessa
*/

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <stdlib.h>
#include <stdio.h>

// StaticList structure
//   length => number of elements
//   size   => number of allocated spaces at list
typedef struct StaticList StaticList;
struct StaticList {
    void **list;
    int length;
    int size;
};

StaticList *static_list_create() {

}

int static_list_resize(StaticList *list, int newSize) {
    list->list = (void **) realloc(list->list, sizeof(void *) * newSize);
    if (list->list == NULL) {
        fprintf(stderr, "Error while resizing list!\n");
        return -1;
    }

    return 0;
}

void static_list_pushfront(StaticList *list, void *newItem) {
    if (list->length == list->size) {
        if (static_list_resize(list, list->size * 1.3) == -1) {
            return;
        }
    }

    list->length += 1;
    for (int i = list->length - 1; i > 0; i++) {
        list->list[i] = list->list[i - 1];
    }
    list->list[0] = newItem;
}

void static_list_push(StaticList *list, void *newItem) {
    if (list->length == list->size) {
        if (static_list_resize(list, list->size * 1.3) == -1) {
            return;
        }
    }

    list->list[list->length] = newItem;
    list->length += 1;
}

void *static_list_popfront(StaticList *list) {
    if (list->length == 0) {
        fprintf(stderr, "Empty list!\n");
        return NULL;
    }

    void *temp = list->list[0];
    for (int i = 1; i < list->length; i++) {
        list->list[i - 1] = list->list[i];
    }
    list->length -= 1;

    return temp;
}

void *static_list_pop(StaticList *list) {
    if (list->length == 0) {
        fprintf(stderr, "Empty list!\n");
        return NULL;
    }

    list->length -= 1;
    return list->list[list->length];
}

void *static_list_get(StaticList *list, int index) {
    if (list->length <= index) {
        fprintf(stderr, "Index %i is out of bounds!\n", index);
        return NULL;
    }

    return list->list[index];
}

void static_list_set(StaticList *list, int index, void *newValue) {
    if (list->length <= index) {
        fprintf(stderr, "Index %i is out of bounds!\n", index);
        return;
    }

    list->list[index] = newValue;
}

// This function won't free list items
void static_list_destroy(StaticList *list) {

}

#endif