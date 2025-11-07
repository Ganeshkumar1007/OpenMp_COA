#pragma once
#include <omp.h>
#include <stdio.h>

void ret_et_helloworld_srl() {
	double start, end;
	start = omp_get_wtime();
	/* for (int i = 0; i < 10000; i++) { */
	printf("Hello world serial\n");
	/* } */
	end = omp_get_wtime();
	printf("Serial time taken: %lf\n", end - start);
}

void ret_et_helloworld_prl() {
	double start = omp_get_wtime();
#pragma omp parallel
	printf("Hello world parallel\n");
	double end   = omp_get_wtime();
	printf("Parallel time taken: %lf\n", end - start);
}
