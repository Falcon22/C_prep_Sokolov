#ifndef stack_h
#define stack_h

#include <stdio.h>

typedef struct Element {
    void* data;
    struct Element* prev;
} Element;

typedef struct Stack {
    Element* tail;
    int size;
} Stack;

Stack* create_stack();
void push(Stack* ps, void* value, size_t size);
void* pop(Stack* ps, size_t size);
void* get_top(Stack* ps);
void delete_stack(Stack* ps);

#endif //_STACK_H_