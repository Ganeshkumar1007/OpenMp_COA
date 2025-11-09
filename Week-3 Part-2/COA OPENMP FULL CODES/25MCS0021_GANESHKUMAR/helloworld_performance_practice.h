#include <stdio.h>
#include <omp.h>

// Use a large number for a meaningful workload
#define WORKLOAD_SIZE 500000000

double total_serialTime = 0;

void fn_measure_serial_performance()
{
	double start_time = omp_get_wtime();

	// --- Meaningful Serial Workload ---
	for (long i = 0; i < WORKLOAD_SIZE; i++) {
		// Perform a trivial operation
	}
	// ------------------------------------

	double end_time = omp_get_wtime();
	total_serialTime = end_time - start_time;
	printf("Serial Time: %f seconds\n", total_serialTime);
}

void fn_analyze_parallel_performance()
{
	double start_time = omp_get_wtime();
	int thread_count = 1; // Variable to store the actual thread count

#pragma omp parallel
	{
		// Get the number of threads from the master thread
#pragma omp master
		{
			thread_count = omp_get_num_threads();
		}

		// --- Meaningful Parallel Workload ---
		// The loop is automatically divided among the threads
#pragma omp for
		for (long i = 0; i < WORKLOAD_SIZE; i++) {
			// Perform a trivial operation
		}
		// ------------------------------------
	} // Parallel region ends

	double end_time = omp_get_wtime();
	double total_parallel_time = end_time - start_time;
	printf("Parallel Time with %d threads: %f seconds\n\n", thread_count, total_parallel_time);

	// --- Performance Calculation ---
	if (total_parallel_time > 0 && total_serialTime > 0) {
		double speed_up = total_serialTime / total_parallel_time;
		// Use the ACTUAL thread count for efficiency
		double efficiency = (speed_up / thread_count) * 100;

		printf("Speedup: %f\n", speed_up);
		printf("Efficiency: %.2f%%\n", efficiency);
	}
}

