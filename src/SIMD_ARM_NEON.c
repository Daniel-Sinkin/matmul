#include <stdio.h>
#include <arm_neon.h>

void multiply_arrays(float *a, float *b, float *result, int n) {
    for (int i = 0; i < n; i += 4) {
        float32x4_t va = vld1q_f32(a + i);
        float32x4_t vb = vld1q_f32(b + i);

        float32x4_t vr = vmulq_f32(va, vb);

        vst1q_f32(result + i, vr);
    }
}

int main() {
    printf("Example 1\n");
    const int n = 8;
    float a[n] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    float b[n] = {2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0};
    float result[n];

    multiply_arrays(a, b, result, n);

    for (int i = 0; i < n; i++) {
        printf("%f * %f = %f\n", a[i], b[i], result[i]);
    }

    printf("Example 2\n");    
    float32x4_t vecA = {1.0, 2.0, 3.0, 4.0};
    float32x4_t vecB = {5.0, 6.0, 7.0, 8.0};

    // Broadcasting
    float32x4_t vecC = vdupq_n_f32(10.0);

    float vecC_values[4];
    vst1q_f32(vecC_values, vecC);
    printf("vecC Values:\n");
    for (int i = 0; i < 4; ++i) {
        printf("%f\n", vecC_values[i]);
    }

    // Fused Multiply-add: four (a * b + c) operations in one cycle!
    float32x4_t result2 = vfmaq_f32(vecC, vecA, vecB);

    float results[4];
    vst1q_f32(results, result2);
    
    printf("\nResults of FMA:\n");
    for (int i = 0; i < 4; ++i) {
        printf("%f\n", results[i]);
    }

    return 0;
}