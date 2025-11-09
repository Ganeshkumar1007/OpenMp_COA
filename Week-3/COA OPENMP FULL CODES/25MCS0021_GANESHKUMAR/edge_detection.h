#include <stdio.h>
#include <omp.h>

#define SIZE 1000
int image[SIZE][SIZE], result[SIZE][SIZE];

void initialize_image() {
    // Fill image matrix with sample values
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            image[i][j] = i + j;
}

void fn_edge_serial() {
    double start, end;
    start = omp_get_wtime();

    for (int i = 1; i < SIZE - 1; i++)
        for (int j = 1; j < SIZE - 1; j++)
            result[i][j] = image[i][j] - image[i - 1][j];

    end = omp_get_wtime();
    printf("Serial edge detection completed.\n");
    printf("Execution Time (Serial): %.6f seconds\n", end - start);
}

void fn_edge_parallel() {
    double start, end;
    start = omp_get_wtime();

#pragma omp parallel for collapse(2)
    for (int i = 1; i < SIZE - 1; i++)
        for (int j = 1; j < SIZE - 1; j++)
            result[i][j] = image[i][j] - image[i - 1][j];

    end = omp_get_wtime();
    printf("Parallel edge detection completed.\n");
    printf("Execution Time (Parallel): %.6f seconds\n", end - start);
}

