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
// Initialize two vectors of 4 single-precision floating-point numbers
    float32x4_t vecA = {1.0, 2.0, 3.0, 4.0};
    float32x4_t vecB = {5.0, 6.0, 7.0, 8.0};

    // The constant to add, broadcasted to all elements of a NEON vector
    float32x4_t vecC = vdupq_n_f32(10.0);

    // Print vecC
    float vecC_values[4];
    vst1q_f32(vecC_values, vecC);
    printf("vecC Values:\n");
    for (int i = 0; i < 4; ++i) {
        printf("%f\n", vecC_values[i]);
    }

    // Perform fused multiply-add: result2 = (vecA * vecB) + vecC
    float32x4_t result2 = vfmaq_f32(vecC, vecA, vecB);

    // Extract the results and print them
    float results[4];
    vst1q_f32(results, result2);
    
    printf("\nResults of FMA:\n");
    for (int i = 0; i < 4; ++i) {
        printf("%f\n", results[i]);
    }

    return 0;
}