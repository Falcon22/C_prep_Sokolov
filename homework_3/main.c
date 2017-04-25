#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include "stack.h"



int main(int argc, const char * argv[]) {
   if (argc != 2) {
        printf("Error in the number of arguments\n");
        return EXIT_FAILURE;
    }
    
    
    FILE *file;
    
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error first argument");
        return EXIT_FAILURE;
    }
    

    Stack* ps = create_stack();
    if (ps == NULL) {
        perror("Error");
        fclose(file);
        return EXIT_FAILURE;
    }
   
    int ind = 1;
    
    char c1 = ' ';
    while (!feof(file)) {
        c1 = fgetc(file);
        if ((c1 == '(') || (c1 == '{') || (c1 == '['))
            push(ps, &c1, sizeof(char));
        if ((c1 == ')') || (c1 == '}') || (c1 == ']')) {
            char* c2 = (char*)pop(ps, sizeof(char*));
            if (c2 == NULL) {
                ind = 0;
                break;
            }
            if ((c1 != (*c2 + 1)) && (c1 != (*c2 + 2))) {
                ind = 0;
                break;
            }
            free(c2);
        }
    }
    
    if (ps->size != 0)
        ind = 0;
    
    
    fclose(file);
    
    delete_stack(ps);
    
    if (ind)
        printf("Correct\n");
    else
        printf("Incorrect\n");
        
    return EXIT_SUCCESS;
}
