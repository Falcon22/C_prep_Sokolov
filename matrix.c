#include "matrix.h"
#include <stdlib.h>
 
Matrix* create_matrix_from_file(FILE* file) {
    unsigned rows_n, cols_n;
    
    if (fscanf(file, "%d\n%d", &rows_n, &cols_n) != 2) {
        return NULL;
    }
    
    Matrix *matrix = create_matrix(rows_n, cols_n);
    if (matrix == NULL)
        return matrix;
    
    double value;
    
    for (int i = 0; i < rows_n; i++) {
        for (int j = 0; j < cols_n; j++) {
            if (fscanf(file, "%lf", &value) != 1)  {
                free_matrix(matrix);
                return NULL;
            }
            if (value) set_elem(matrix, i, j, value);
            
       }
    }
    return matrix;
}

Matrix* create_matrix(int row, int col) {
    Matrix *matrix = malloc(sizeof(Matrix) * (row * col + 1));
    
    if (matrix != NULL) {
    matrix[0].row_ind = row; //number of rows
    matrix[0].col_ind = col; //number of cols
    matrix[0].value = 0; //number of elements
    
    matrix[1].row_ind = 0;
    matrix[1].col_ind = 0;
    matrix[1].value = 0;
    }
    
    return matrix;
    
}

Matrix* matrix_multiplication(Matrix* matrix1, Matrix* matrix2) {
    if (get_cols(matrix1) != get_rows(matrix2)) {
        printf("Error: the number of сolumns of the first matrix and the number of rows of the second matrix are not equal");
        return NULL;
    }
    
    Matrix* matrix3 = create_matrix(matrix1[0].row_ind, matrix2[0].col_ind);
    if (matrix3 == NULL) return matrix3;
    
    int s;
    for (int i = 0; i < get_rows(matrix1); i++) {
        for (int j = 0; j < get_cols(matrix2); j++) {
            s = 0;
            for (int k = 0; k < get_cols(matrix1); k++) {
                s += get_elem(matrix1, i, k) * get_elem(matrix2, k, j);
            }
            set_elem(matrix3, i, j, s);
        }
    }
    
    return matrix3;
}

void free_matrix(Matrix* matrix) {
    free(matrix);
}



double get_elem(Matrix* matrix, int row, int col){
        int i = 1;
        if ((row > get_rows(matrix)) || (col > get_cols(matrix))) return -1;
            while (matrix[i].value != 0) {
                if (matrix[i].row_ind > row) break;
                if ((matrix[i].row_ind == row) && (matrix[i].col_ind == col))
                    return matrix[i].value;
                i++;
            }
    return 0;
}
 


 
void set_elem(Matrix* matrix, int row, int col, double val) {
    int i = 1;
    int n = matrix[0].value; //number of elements
    int ind = 1;
    
    if (matrix[n].row_ind == row && matrix[n].col_ind == col) {
        matrix[n].value = val;
        ind = 0;
    }
    
   if ((matrix[n].row_ind < row) || ((matrix[n].row_ind == row) && (matrix[n].col_ind < col))) {
        matrix[0].value++;
        n++;
        matrix[n].row_ind = row;
        matrix[n].col_ind = col;
        matrix[n].value = val;
        ind = 0;
    }

    if (ind)
        {
        while (((matrix[i].row_ind < row) || ((matrix[i].row_ind == row) && (matrix[i].col_ind <= col))) && (matrix[i].value)) {
            if ((matrix[i].row_ind == row) && (matrix[i].col_ind == col)) {
                if (val) {
                    matrix[i].value = val;
                    ind = 0;
                } else {
                    while (matrix[i].value) {
                        matrix[0].value--;
                        matrix[i] = matrix[i + 1];
                        i++;
                    }
                }
            }
            i++;
        }
    }
    
    if (ind) {
        if (matrix[i].value) {
            int j = i + 1;
            while (matrix[j].value) {
                j++;
            }
            
            while (j != (i + 1)) {
                matrix[j] = matrix[j - 1];
                j--;
            }
        }   matrix[0].value++;
            matrix[i].row_ind = row;
            matrix[i].col_ind = col;
            matrix[i].value = val;
    }
        
}



int get_rows(Matrix* matrix) {
    return matrix[0].row_ind;
}
                                                 
int get_cols(Matrix* matrix) {
    return matrix[0].col_ind;
}


