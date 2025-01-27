#include "stack_list.h"
#include <stdio.h>


int main() {
    // Create a StackList for integers
    StackList *int_list = create_stacklist(sizeof(int));


    // Push elements into the list
    for (int i = 0; i < 10; i++) {
      list_push(int_list, &i);
    }

    list_push(int_list, &(int){13});
    list_push(int_list, &(int){50});
    list_push(int_list, &(int){15});


    // Print elements
    printf("Elements in the list: ");
    for (size_t i = 0; i < list_size(int_list); i++) {
        int value;
        list_get(int_list, i, &value);
        printf("%d ", value);
    }
    printf("\n");


    // Pop an element
    int popped;
    list_pop(int_list, &popped);
    printf("Popped element: %d\n", popped);
    list_pop(int_list, &popped);
    printf("Popped element: %d\n", popped);
    list_pop(int_list, &popped);
    printf("Popped element: %d\n", popped);


    // Clear the list
    list_clear(int_list);
    printf("List size after clearing: %zu\n", list_size(int_list));

    // Destroy the list
    destroy_stacklist(int_list);

    return 0;
}
