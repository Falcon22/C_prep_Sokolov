//Sokolov Vladislav homework №1 Dop. group #5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        printf("Illegal number of arguments\n");
        return EXIT_FAILURE;
    }
    
    FILE *file = fopen(argv[1], "r");
    if(!file)
    {
        printf("Open failed\n");
        return EXIT_FAILURE;
    }
    
    const char *substring = argv[2];
    if (!substring) {
        printf("Incorrect substring\n");
        return EXIT_FAILURE;
    }
    
    while (!feof(file)) {
        const int bufer_size = 1048576;
        char bufer[bufer_size];
        fgets(bufer, bufer_size, file);
        if (strstr(bufer, substring)!= NULL) {
            printf("%s", bufer);
        }
    }
    
    fclose(file);
    return EXIT_SUCCESS;
}
