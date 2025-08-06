#include <stdio.h>

#include <omp.h>



double startTime_serial, endTime_serial;

double total_serial_time = 0;



double startTime_parallel, endTime_parallel;

double total_parallel_time = 0;



void fn_ret_tid_helloworld_srl()

{

	startTime_serial = omp_get_wtime();

	printf("Serial\n");

	endTime_serial = omp_get_wtime();

	total_serial_time = endTime_serial - startTime_serial;

	printf("Total time for serial: %f\n", total_serial_time);

}

void fn_ret_tid_helloworld_prl()

{
	omp_set_num_threads(10);


	startTime_parallel = omp_get_wtime();

#pragma omp parallel

	{

		

		printf("Thread %d is running.\n", omp_get_thread_num());

	}

	endTime_parallel = omp_get_wtime();

	double total_parallel_time = endTime_parallel - startTime_parallel;

	printf("Total time for parallel: %f\n", total_parallel_time);



	double speed_up = total_serial_time / total_parallel_time;



	double efficiency = (speed_up /10)* 100;



	printf("speed up: %f\n", speed_up);

	printf("efficiency: %f\n", efficiency);

}