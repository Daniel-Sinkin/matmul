#include <stdio.h>
#include <stdlib.h>
#include "matrix.h" // Include the header file for matrix operations

const size_t M_ROWS = 2;
const size_t M_COLS = 3;
const size_t N_ROWS = 3;
const size_t N_COLS = 3;

int main() {
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
    matrixPrint(M, M_COLS, M_ROWS);
    
    return 0;
}
