#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const size_t M_ROWS = 2;
const size_t M_COLS = 3;

const size_t N_ROWS = 3;
const size_t N_COLS = 3;

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

void matrixTransposeInplace(int *matrix, size_t num_rows, size_t num_cols) {
    int *temp = malloc(num_rows * num_cols * sizeof(int));
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
            size_t index = matrixIDX(y, x, num_cols);
            if (matrix[index] != expected[index]) {
                printf("%d != %d\n", matrix[index], expected[index]);
                return false;
            }
        }
    }
    return true;
}

int main() {
    printf("Hello, World!\n");

    int32_t M[M_ROWS * M_COLS] = {
        1, 2, 3,
        6, 7, 8,
    };
    int32_t N[N_ROWS * N_COLS] = {
        1, 2, -1,
        3, 4, -2,
        5, 6, -3,
    };
    int32_t MxN[M_ROWS * N_COLS];

    printf("M:\n");
    matrixPrint(M, M_ROWS, M_COLS);
    printf("\n");
    printf("M Reshaped:\n");
    matrixPrint(M, M_COLS, M_ROWS);
    printf("\n");
    printf("N:\n");
    matrixPrint(N, N_ROWS, N_COLS);

    matrixProduct(M, M_ROWS, M_COLS, N, N_ROWS, N_COLS, MxN);
    printf("M x N:\n");
    matrixPrint(MxN, M_ROWS, N_COLS);

    int32_t MxN_expected[M_ROWS * N_COLS] = {
        22, 28, -14,
        67, 88, -44,
    };

    if (matrixEqual(MxN, M_ROWS, N_COLS, MxN_expected)) {
        printf("MxN is as expected\n");
    } else {
        printf("MxN is not as expected\n");
    }

    printf("M^T:\n");
    matrixTransposeInplace(M, M_ROWS, M_COLS);
    matrixPrint(M, M_ROWS, M_COLS);

    return 0;
}