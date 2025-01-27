# StackList Implementation
A generic stack-based list implementation in C that allows storing elements of any data type.


## Features
- Generic data type support through void pointers.
- But list can only store one specific type of data at a time.
- Dynamic memory management
- Stack operations (push, pop)
- List operations (get element at index)
- Memory safety with proper cleanup functions


## Core Operations

### Creation and Destruction
- `create_stacklist(size_t element_size)`: Creates a new stack list for elements of specified size
- `destroy_stacklist(StackList *list)`: Properly frees all allocated memory

### Stack Operations
- `list_push(StackList *list, void *element)`: Adds an element to the top of the stack
- `list_pop(StackList *list, void *out_element)`: Removes and returns the top element
- `list_clear(StackList *list)`: Removes all elements from the list

### Utility Operations
- `list_size(StackList *list)`: Returns the current number of elements
- `list_get(StackList *list, size_t index, void *out_element)`: Retrieves element at specified index


## Usage Example

```c
// Create a stack list for integers
StackList *int_list = create_stacklist(sizeof(int));

// Push elements
int value = 42;
list_push(int_list, &value);

// Get element at index
int retrieved;
list_get(int_list, 0, &retrieved);

// Pop element
int popped;
list_pop(int_list, &popped);

// Clean up
list_clear(int_list);
destroy_stacklist(int_list);
```
