#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdbool.h>

size_t matrixIDX(size_t y, size_t x, size_t num_cols);
void matrixPrint(int *matrix, size_t num_rows, size_t num_cols);
void matrixProduct(int *A, size_t A_rows, size_t A_cols, int *B, size_t B_rows, size_t B_cols, int *C);
void matrixAdd(int *A, size_t A_rows, size_t A_cols, int *B, size_t B_rows, size_t B_cols, int *C);
void matrixTransposeInplace(int *matrix, size_t num_rows, size_t num_cols);
bool matrixEqual(int *matrix, size_t num_rows, size_t num_cols, int *expected);

#endif