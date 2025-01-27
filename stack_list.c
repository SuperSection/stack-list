#include "stack_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define INITIAL_CAPACITY 4


// Create a new StackList
StackList* create_stacklist(size_t element_size) {
    StackList *list = (StackList*)malloc(sizeof(StackList));
    if (!list) {
        fprintf(stderr, "Failed to allocate memory for StackList\n");
        exit(EXIT_FAILURE);
    }
    list->data = malloc(element_size * INITIAL_CAPACITY);
    if (!list->data) {
        fprintf(stderr, "Failed to allocate memory for StackList data\n");
        free(list);
        exit(EXIT_FAILURE);
    }
    list->element_size = element_size;
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}


// Destroy the StackList
void destroy_stacklist(StackList *list) {
    if (list) {
        free(list->data);
        free(list);
    }
}


// Push an element to the StackList
void list_push(StackList *list, const void *element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, list->element_size * list->capacity);
        if (!list->data) {
            fprintf(stderr, "Failed to reallocate memory for StackList data\n");
            exit(EXIT_FAILURE);
        }
    }
    memcpy((char*)list->data + (list->size * list->element_size), element, list->element_size);
    list->size++;
}


// Pop an element from the StackList
void list_pop(StackList *list, void *out_element) {
    if (list->size == 0) {
        fprintf(stderr, "StackList is empty, cannot pop\n");
        return;
    }
    list->size--;
    if (out_element) {
        memcpy(out_element, (char*)list->data + (list->size * list->element_size), list->element_size);
    }
}


// Get an element at a specific index
bool list_get(const StackList *list, size_t index, void *out_element) {
    if (index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        return false;
    }
    memcpy(out_element, (char*)list->data + (index * list->element_size), list->element_size);
    return true;
}


// Get the current size of the StackList
size_t list_size(const StackList *list) {
    return list->size;
}


// Clear all elements in the StackList
void list_clear(StackList *list) {
    list->size = 0;
}
