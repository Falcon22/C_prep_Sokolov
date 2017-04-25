#include "stack.h"
#include <stdlib.h>

Stack* create_stack() {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    if (new_stack == NULL)
        return new_stack;
    
    new_stack->tail = NULL;
    new_stack->size = 0;
    return new_stack;
}

void push(Stack* ps, void* value, size_t size) {
    Element* new_element = (Element*)malloc(sizeof(Element));
    if (new_element == NULL)
        return;
    
    new_element->data = (char *)malloc(size);
    
    for (int i = 0; i < size; i++)
        *((char*) new_element->data + i) = *((char*) value + i);
    
    new_element->prev = ps->tail;
    ps->tail = new_element;
    ps->size++;
}

void* pop(Stack* ps, size_t size) {
    if (ps->size == 0)
        return NULL;
    Element* temporaly = ps->tail;

    void* c = malloc(size);
    
    for (int i = 0; i < size; i++)
        *((char*) c + i) = *((char*) temporaly->data + i);
    
    ps->tail = ps->tail->prev;
    free(temporaly->data);
    free(temporaly);
    ps->size--;
    return c;
}

void* get_top(Stack* ps) {
    if (ps->size != 0)
        return ps->tail->data; else
            return 0;
}

void delete_stack(Stack* ps) {
    if (ps == NULL)
        return;
    
    if (ps->size == 0) {
        free(ps);
        return;
    }
    
    Element* temporal = ps->tail;
    Element* prev = NULL;
    
    while (temporal != NULL) {
        free(temporal->data);
        prev = temporal->prev;
        free(temporal);
        temporal = prev;
    }
        
    free(ps);
}