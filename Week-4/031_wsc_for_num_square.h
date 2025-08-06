#include <stdio.h>
#include <omp.h>

#define N 12  // Unified size for both serial and parallel parts

double Et_start_srl, Et_stop_srl, Et_total_srl;
double Et_start_prl, Et_stop_prl, Et_total_prl;
double speedup, efficiency;

// Serial: Initialize Array
void fn_initializearray(int a[]) {
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;
    }
}

// Serial: Compute Squares
void fn_computeSquares_srl(int a[], int square[]) {
    printf("\n\n--- Serial Execution ---\n");
    for (int i = 0; i < N; i++) {
        square[i] = a[i] * a[i];  // Corrected to actual square
        printf("Square of a[%d] : %d ^ 2 = %d\n", i, a[i], square[i]);
    }
}

// Serial: Display Result
void fn_displayResult(int square[]) {
    printf("\n\nSquared Result (Serial): \n");
    for (int i = 0; i < N; i++) {
        printf("Squared[%d] = %d\n", i, square[i]);
    }
}

// Parallel: Initialize Array
void fn_initializearray_prl(int a[]) {
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;
    }
}

// Parallel: Compute Squares with OpenMP
void fn_computeSquares_prl(int a[], int square[]) {
    printf("\n--- Parallel Execution ---\n");

#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        square[i] = a[i] * a[i];  // Corrected to actual square
        printf("Thread %d: a[%d] = %d, Square = %d\n", omp_get_thread_num(), i, a[i], square[i]);
    }
}

// Parallel: Display Result
void fn_displayResult_prl(int square[]) {
    printf("\n\nSquared Result (Parallel): \n");
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        printf("Squared[%d] = %d printed by Thread Number : %d\n", i, square[i], omp_get_thread_num());
    }
}

// Serial function
int fn_num_square_srl() {
    int a[N], square[N];
    fn_initializearray(a);
    fn_computeSquares_srl(a, square);
    fn_displayResult(square);
    return 0;
}

// Parallel function
int fn_num_square_prl() {
    int a[N], square[N];
    fn_initializearray_prl(a);
    fn_computeSquares_prl(a, square);
    fn_displayResult_prl(square);
    return 0;
}




void fn_num_square_speedup_efficiency() {

    //-----------------Serial---------------------//

    Et_start_srl = omp_get_wtime();
    fn_num_square_srl();
    Et_stop_srl = omp_get_wtime();

    Et_total_srl = Et_stop_srl - Et_start_srl;

    printf("\nTotal time for serial Execution is : %f\n", Et_total_srl);


    //-----------------Parallel-------------------//

    Et_start_prl = omp_get_wtime();
    fn_num_square_prl();
    Et_stop_prl = omp_get_wtime();

    Et_total_prl = Et_stop_prl - Et_start_prl;

    printf("\nTotal time for parallel Execution is : %f\n", Et_total_prl);


    //-----------------Speedup---------------------//

    speedup = (Et_total_srl / Et_total_prl);
    printf("\nSpeedup is : %f\n", speedup);


    //-----------------Efficiency---------------------//

    int no_of_cores = omp_get_max_threads();
    efficiency = ((speedup / no_of_cores) * 100);
    printf("Efficiency = %f \n", efficiency);

}//end of fn_num_square_speedup
