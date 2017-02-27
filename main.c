//
//  main.c
//  homework1
//
//  Created by Falcon on 24.02.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    if (argc != 3) {
        printf("Illegal number of arguments\n");
        return EXIT_FAILURE;
    }
    
    const char *substring = argv[1];
    if (!substring) {
        printf("Incorrect substring\n");
        return EXIT_FAILURE;
    }
    
    FILE *file_handle = fopen(argv[2], "r");
    if(!file_handle)
    {
        printf("Open failed\n");
        return EXIT_FAILURE;
    }
    
    
    
    return 0;
}
