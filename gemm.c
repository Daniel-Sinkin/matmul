#include <assert.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>

static const int N = 1024;

#define BLOCK 32

float A[N * N];
float B[N * N];
float C[N * N];
float vla

uint64_t nanos() {
    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    return (uint64_t)start.tv_sec * 1e9 + (uint64_t)start.tv_nsec;

}

int main() {
    assert(N % BLOCK == 0);

    for (int k = 0; k < N * N; k++) A[k] = rand();
    for (int k = 0; k < N * N; k++) A[k] = rand();

    uint64_t start = nanos();
    for (int by = 0; by < N / BLOCK; by += BLOCK) {
        for (int bx = 0; bx < N / BLOCK; bx += BLOCK) {
            for(int y = by; y < by + BLOCK; y++) {
                for(int x = bx; x < bx + BLOCK; x++) {
                    int sum = 0;
                    for(int k = 0; k < N; k++) {
                        sum += A[y][k] * B[x][k];
                    }
                    C[y][x] += sum;
                }
            }
        }
    }
    
    uint64_t end = nanos();
    double gfloppies = (2.0 * N * N * N) * 1e-9;

    double s = (end-start) * 1e-9;

    printf("%f GigaFloppies\n", gfloppies / s);

    return 0;
}
