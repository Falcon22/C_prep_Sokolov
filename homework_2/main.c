#include "matrix.h"


int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Error in the number of arguments\n");
        return EXIT_FAILURE;
    }
    
    
    FILE *f1, *f2;
    
    f1 = fopen(argv[1], "r");
    if (f1 == NULL) {
        perror("Error first argument");
        return EXIT_FAILURE;
    }
    
    Matrix * m1 = create_matrix_from_file(f1);
    if (m1 == NULL) {
        perror("Error first matrix");
        fclose(f1);
        return EXIT_FAILURE;
    }
    
    if (fclose(f1) == EOF) {
        perror("Error first argument");
        free_matrix(m1);
        return EXIT_FAILURE;
    }
    
    f2 = fopen(argv[2], "r");
    if (f2 == NULL) {
        perror("Error second argument");
        free_matrix(m1);
        return EXIT_FAILURE;
    }
    
    Matrix * m2 = create_matrix_from_file(f2);
    if (m2 == NULL) {
        perror("Error second matrix");
        free_matrix(m1);
        fclose(f2);
        return EXIT_FAILURE;
    }
    
    if (fclose(f2) == EOF) {
        perror("Error second argument");
        free_matrix(m1);
        free_matrix(m2);
        return EXIT_FAILURE;
    }
    
    Matrix * m3 = matrix_multiplication(m1, m2);
    if (m3 == NULL) {
        if (errno) perror("Error third matrix");
        free_matrix(m1);
        free_matrix(m2);
        return EXIT_FAILURE;
    }
    
    free_matrix(m1);
    
    if (errno != 0) {
        perror("Error first matrix");
        free_matrix(m2);
        free_matrix(m3);
        return EXIT_FAILURE;
    }
    
    free_matrix(m2);
    
    if (errno != 0) {
        perror("Error second matrix");
        free_matrix(m3);
        return EXIT_FAILURE;
    }
    
    for (int i = 0; i < get_rows(m3); i++) {
        for (int j = 0; j < get_cols(m3); j++) {
            printf("%d ", (int)get_elem(m3, i, j));
        }
        printf("\n");
    }

    free_matrix(m3);
    
    if (errno != 0) {
        perror("Error third matrix");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
