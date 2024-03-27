#include <stdio.h>
#include <arm_neon.h>

void multiply_arrays(float *a, float *b, float *result, int n) {
    for (int i = 0; i < n; i += 4) {
        // Load 4 elements from each array into NEON vectors
        float32x4_t va = vld1q_f32(a + i);
        float32x4_t vb = vld1q_f32(b + i);

        // Perform element-wise multiplication
        float32x4_t vr = vmulq_f32(va, vb);

        // Store the result back into the result array
        vst1q_f32(result + i, vr);
    }
}

int main() {
    const int n = 8;
    float a[n] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    float b[n] = {2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0};
    float result[n];

    multiply_arrays(a, b, result, n);

    for (int i = 0; i < n; i++) {
        printf("%f * %f = %f\n", a[i], b[i], result[i]);
    }

    return 0;
}