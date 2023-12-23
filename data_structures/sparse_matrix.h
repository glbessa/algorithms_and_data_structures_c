#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <stdlib.h>

SparseMatrix *sparse_matrix_create() {

}

void sparse_matrix_destroy(SparseMatrix *sm) {

}

float sparse_matrix_get_element(SparseMatrix *sm, int line, int column) {

}

void sparse_matrix_set_element(SparseMatrix *sm, int line, int column, float value) {

}

SparseMatrix *sparse_matrix_add(SparseMatrix *sm1, SparseMatrix *sm2) {

}

SparseMatrix *sparse_matrix_subtract(SparseMatrix *sm1, SparseMatrix *sm2) {

}

SparseMatrix *sparse_matrix_multiply(SparseMatrix *sm1, SparseMatrix *sm2) {

}

SparseMatrix *sparse_matrix_mat_multiply(SparseMatrix *sm1, SparseMatrix *sm2) {

}

SparseMatrix *sparse_matrix_divide(SparseMatrix *sm1, SparseMatrix *sm2) {
    
}

#endif
