#include <assert.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>

static const int N = 512;

#define BLOCK_SIZE 4

float A[N * N];
float B[N * N];
float C[N * N];

float A[N * N] = {
    1, 2, 3, 4,
    5, 6, 7, 8,
    9, 10, 11, 12,
    13, 14, 15, 16
};

float B[N * N] = {
    1, -2, 3, -4,
    5, -6, 7, -8,
    -9, 10, -11, 12,
    -13, -14, 15, -16
};

void matrixPrint(float *matrix, size_t num_rows, size_t num_cols) {
    for (size_t y = 0; y < num_rows; y++) {
        printf("[");
        for (size_t x = 0; x < num_cols; x++) {
            printf("%f", matrix[y * num_cols + x]);
            if (x < num_cols - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

uint64_t nanos() {
    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    return (uint64_t)start.tv_sec * 1e9 + (uint64_t)start.tv_nsec;
}

int main() {
    assert(N % BLOCK_SIZE == 0);

    for(int i = 0; i < N*N; i++) C[i] = 0.0;
    uint64_t start = nanos();

    for(int y = 0; y < N / BLOCK_SIZE; y++) {
        for(int x = 0; x < N / BLOCK_SIZE; x++) {
            for(int r = 0; r < N / BLOCK_SIZE; r++) {
                for(int y_loc = 0; y_loc < BLOCK_SIZE; y_loc++) {
                    for(int x_loc = 0; x_loc < BLOCK_SIZE; x_loc++) {
                        float temp = 0.0;
                        for(int i = 0; i < BLOCK_SIZE; i++) {
                            float a_val = A[(y * BLOCK_SIZE + y_loc) * N + r * BLOCK_SIZE + i];
                            float b_val = B[(r * BLOCK_SIZE + i) * N + x * BLOCK_SIZE + x_loc];
                            temp += a_val * b_val;
                        }
                        C[((y * BLOCK_SIZE + y_loc)*N + x * BLOCK_SIZE + x_loc)] += temp;
                    }
                }
            }
        }
    }

    uint64_t end = nanos();
    printf("A:\n");
    matrixPrint(A, N, N);
    printf("B:\n");
    matrixPrint(B, N, N);
    printf("C:\n");
    matrixPrint(C, N, N);
    
    double gfloppies = (2.0 * N * N * N) * 1e-9;

    double s = (end-start) * 1e-9;

    printf("%f GigaFloppies\n", gfloppies / s);

    return 0;
}
