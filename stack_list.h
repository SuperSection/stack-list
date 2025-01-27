#ifndef STACK_LIST_H
#define STACK_LIST_H


#include <stddef.h>
#include <stdbool.h>


// Define a StackList structure
typedef struct {
    void *data;           // Pointer to hold elements
    size_t element_size;  // Size of each element
    size_t size;          // Current number of elements
    size_t capacity;      // Current allocated capacity
} StackList;


// Function declarations
StackList* create_stacklist(size_t element_size);
void destroy_stacklist(StackList *list);
void list_push(StackList *list, const void *element);
void list_pop(StackList *list, void *out_element);
bool list_get(const StackList *list, size_t index, void *out_element);
size_t list_size(const StackList *list);
void list_clear(StackList *list);



#endif
