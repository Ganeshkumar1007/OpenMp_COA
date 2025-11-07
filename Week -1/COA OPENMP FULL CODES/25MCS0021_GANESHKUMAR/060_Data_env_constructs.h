#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Function to perform vector addition
void fn_work(float* a, float* b, float* c, int N) {
    float x, y;
    int i;

#pragma omp parallel for private(x, y) shared(a, b, c)
    for (i = 0; i < N; i++) {
        x = a[i];
        y = b[i];
        c[i] = x + y;
    }
}

// User-defined function to replace main
void fn_run_vector_addition() {
    int N = 10;
    float a[10], b[10], c[10];

    // Initialize input arrays
    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }

    // Call the work function
    fn_work(a, b, c, N);

    // Print the result
    printf("Result of vector addition:\n");
    for (int i = 0; i < N; i++) {
        printf("c[%d] = %.2f\n", i, c[i]);
    }
}

// Actual call fn_run_vector_addition() from main function