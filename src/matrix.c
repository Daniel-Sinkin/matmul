#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

size_t matrixIDX(size_t y, size_t x, size_t num_cols) {
    return y * num_cols + x;
}

void matrixPrint(int *matrix, size_t num_rows, size_t num_cols) {
    for (size_t y = 0; y < num_rows; y++) {
        printf("[");
        for (size_t x = 0; x < num_cols; x++) {
            printf("%d", matrix[matrixIDX(y, x, num_cols)]);
            if (x < num_cols - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

void matrixProduct(int *A, size_t A_rows, size_t A_cols, int *B, size_t B_rows, size_t B_cols, int *C) {
    if (A_cols != B_rows) {
        printf("Error: A_cols != B_rows\n");
        return;
    }
    for (size_t y = 0; y < A_rows; y++) {
        for (size_t x = 0; x < B_cols; x++) {
            C[matrixIDX(y, x, B_cols)] = 0;
            for (size_t k = 0; k < A_cols; k++) {
                C[matrixIDX(y, x, B_cols)] += A[matrixIDX(y, k, A_cols)] * B[matrixIDX(k, x, B_cols)];
            }
        }
    }
}

void matrixAdd(int *A, size_t A_rows, size_t A_cols, int *B, size_t B_rows, size_t B_cols, int *C) {
    if (A_rows != B_rows || A_cols != B_cols) {
        printf("Error: Matrix dimensions do not match\n");
        return;
    }
    for (size_t y = 0; y < A_rows; y++) {
        for (size_t x = 0; x < A_cols; x++) {
            C[matrixIDX(y, x, A_cols)] = A[matrixIDX(y, x, A_cols)] + B[matrixIDX(y, x, A_cols)];
        }
    }
}

void matrixTransposeInplace(int *matrix, size_t num_rows, size_t num_cols) {
    int *temp = malloc(num_rows * num_cols * sizeof(int));
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }
    for (size_t y = 0; y < num_rows; y++) {
        for (size_t x = 0; x < num_cols; x++) {
            temp[matrixIDX(x, y, num_rows)] = matrix[matrixIDX(y, x, num_cols)];
        }
    }
    for (size_t y = 0; y < num_rows; y++) {
        for (size_t x = 0; x < num_cols; x++) {
            matrix[matrixIDX(y, x, num_cols)] = temp[matrixIDX(y, x, num_cols)];
        }
    }
    free(temp);
}

bool matrixEqual(int *matrix, size_t num_rows, size_t num_cols, int *expected) {
    for (size_t y = 0; y < num_rows; y++) {
        for (size_t x = 0; x < num_cols; x++) {
            if (matrix[matrixIDX(y, x, num_cols)] != expected[matrixIDX(y, x, num_cols)]) {
                return false;
            }
        }
    }
    return true;
}
