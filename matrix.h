#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
typedef struct Matrix {
    unsigned row_ind;
    unsigned col_ind;
    double value;
} Matrix;

Matrix* create_matrix_from_file(FILE* file);
Matrix* create_matrix(int row, int col);
Matrix* matrix_multiplication(Matrix* matrix1, Matrix* matrix2);
void free_matrix(Matrix* matrix);
void print_matrix(Matrix* matrix);
double get_elem(Matrix* matrix, int row, int col);
void set_elem(Matrix* matrix, int row, int col, double val);
int get_count_not_null(FILE* file);
int get_rows(Matrix* matrix);
int get_cols(Matrix* matrix);

#endif //_MATRIX_H_
