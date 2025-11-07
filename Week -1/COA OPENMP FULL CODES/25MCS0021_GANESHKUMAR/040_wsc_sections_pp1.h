#pragma once
#include"stdio.h"
#include"omp.h"
#include"040_calculator_functions_pp1.h"
void fn_wsc_sections_pp1_srl() {
	 int a = 5, b = 3, sum, difference;
	 double start_time, end_time;

	 start_time = omp_get_wtime(); //starting time
	 sum = fn_calculator_add(5,3);
	 printf("Addition: %d + %d = %d by thread id: %d\n", a, b, sum, omp_get_thread_num());

	 difference = fn_calculator_subtract(a, b);
	 printf("Subtraction: %d - %d = %d by thread id: %d\n", a, b, difference, omp_get_thread_num());
	 end_time = omp_get_wtime(); //End time

	 printf("Serial Execution Time: %f seconds\n", end_time - start_time);

}

void fn_wsc_sections_pp1_prl() {
	int a = 5, b = 3, sum, difference;
	double start_time, end_time;
	start_time = omp_get_wtime();//start time

#pragma omp parallel sections
	{
#pragma omp section
		{
			sum = fn_calculator_add(5, 3);
			printf("Addition: %d + %d = %d by thread id: %d\n", a, b, sum, omp_get_thread_num());
		}

#pragma omp section
		{
			difference = fn_calculator_subtract(a, b);
			printf("Subtraction: %d - %d = %d by thread id: %d\n", a, b, difference, omp_get_thread_num());
		}
	}
	end_time = omp_get_wtime(); //end time
	printf("Parallel Execution Time: %f seconds\n", end_time - start_time);

}