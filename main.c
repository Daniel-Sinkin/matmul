#include <stdio.h>
#include <stdlib.h>

const size_t M_ROWS = 2;
const size_t M_COLS = 3;
const size_t M_SIZE = M_ROWS * M_COLS;

void printMatrix(int *matrix, size_t num_rows, size_t num_cols) {
    printf("Matrix:\n");

    for (size_t y = 0; y < num_rows; y++) {
        printf("[");

        for (size_t x = 0; x < num_cols; x++) {
            printf("%d", matrix[y * num_cols + x]);

            if (x < num_cols - 1) {
                printf(", ");
            }
        }

        printf("]\n");
    }
}

int main() {
    printf("Hello, World!\n");

    int32_t M[M_SIZE] = {1, 2, 3, 6, 7, 8};

    printMatrix(M, M_ROWS, M_COLS);
    printf("\n");
    printMatrix(M, M_COLS, M_ROWS);

    return 0;
}