#include<stdio.h>
#include"run_time_environment_routines.h"
#include <cstdlib>

int fn_mnudrvprg_021_runtime_routines() {
	int choice;
	while (1) {
		printf("#########################################################################################\n");
		printf("List of OpenMP Runtime Environment Routines:\n");
		printf("0: Exit\n");
		printf("1: omp_set_num_threads\t 2: omp_get_num_threads\t 3: omp_get_max_threads\n");
		printf("4: omp_get_thread_num\t 5: omp_get_num_procs\t 6: omp_in_parallel\n");
		printf("7: omp_set_dynamic\t 8: omp_get_dynamic\t 9: omp_get_cancellation\n");
		printf("10: omp_set_nested\t 11: omp_get_nested\t\t 12: omp_set_schedule\n");
		printf("13: omp_get_schedule\t 14: omp_get_thread_limit\t 15: omp_set_max_active_levels\n");
		printf("16: omp_get_max_active_levels\t 17: omp_get_level\t\t 18: omp_get_ancestor_thread_num\n");
		printf("19: omp_get_team_size\t 20: omp_get_active_level\t 21: omp_in_final\n");
		printf("22: omp_get_proc_bind\t 23: omp_set_default_device\t 24: omp_get_default_device\n");
		printf("25: omp_get_num_devices\t 26: omp_get_num_teams\t 27: omp_get_team_num\n");
		printf("#########################################################################################\n");

		printf("\nEnter your choice: ");

		if (scanf("%d", &choice) != 1) {
			
			while (getchar() != '\n');
			choice = -1; 
		}

		switch (choice) {
		case 0:
			printf("You opted to exit the program.\n");
			exit(0);
		case 1:
			printf("Calling function for omp_set_num_threads:\n");
			fn_rter_omp_set_num_threads();
			break;
		case 2:
			printf("Calling function for omp_get_num_threads:\n");
			fn_rter_omp_get_num_threads();
			break;
		case 3:
			printf("Calling function for omp_get_max_threads:\n");
			fn_rter_omp_get_max_threads();
			break;
		case 4:
			printf("Calling function for omp_get_thread_num:\n");
			fn_rter_omp_get_thread_num();
			break;
		case 5:
			printf("Calling function for omp_get_num_procs:\n");
			fn_rter_omp_get_num_procs();
			break;
		case 6:
			printf("Calling function for omp_in_parallel:\n");
			fn_rter_omp_in_parallel();
			break;
		case 7:
			printf("Calling function for omp_set_dynamic:\n");
			fn_rter_omp_set_dynamic();
			break;
		case 8:
			printf("Calling function for omp_get_dynamic:\n");
			fn_rter_omp_get_dynamic();
			break;
		case 9:
			printf("Calling function for omp_get_cancellation:\n");
			fn_rter_omp_get_cancellation();
			break;
		case 10:
			printf("Calling function for omp_set_nested:\n");
			fn_rter_omp_set_nested();
			break;
		case 11:
			printf("Calling function for omp_get_nested:\n");
			fn_rter_omp_get_nested();
			break;
		case 12:
			printf("Calling function for omp_set_schedule:\n");
			fn_rter_omp_set_schedule();
			break;
		case 13:
			printf("Calling function for omp_get_schedule:\n");
			fn_rter_omp_get_schedule();
			break;
		case 14:
			printf("Calling function for omp_get_thread_limit:\n");
			fn_rter_omp_get_thread_limit();
			break;
		case 15:
			printf("Calling function for omp_set_max_active_levels:\n");
			fn_rter_omp_set_max_active_levels();
			break;
		case 16:
			printf("Calling function for omp_get_max_active_levels:\n");
			fn_rter_omp_get_max_active_levels();
			break;
		case 17:
			printf("Calling function for omp_get_level:\n");
			fn_rter_omp_get_level();
			break;
		case 18:
			printf("Calling function for omp_get_ancestor_thread_num:\n");
			fn_rter_omp_get_ancestor_thread_num();
			break;
		case 19:
			printf("Calling function for omp_get_team_size:\n");
			fn_rter_omp_get_team_size();
			break;
		case 20:
			printf("Calling function for omp_get_active_level:\n");
			fn_rter_omp_get_active_level();
			break;
		case 21:
			printf("Calling function for omp_in_final:\n");
			fn_rter_omp_in_final();
			break;
		case 22:
			printf("Calling function for omp_get_proc_bind:\n");
			fn_rter_omp_get_proc_bind();
			break;
		case 23:
			printf("Calling function for omp_set_default_device:\n");
			fn_rter_omp_set_default_device();
			break;
		case 24:
			printf("Calling function for omp_get_default_device:\n");
			fn_rter_omp_get_default_device();
			break;
		case 25:
			printf("Calling function for omp_get_num_devices:\n");
			fn_rter_omp_get_num_devices();
			break;
		case 26:
			printf("Calling function for omp_get_num_teams:\n");
			fn_rter_omp_get_num_teams();
			break;
		case 27:
			printf("Calling function for omp_get_team_num:\n");
			fn_rter_omp_get_team_num();
			break;
		default:
			printf("You opted for the wrong choice. Please try again.\n");
			break;
		}
		printf("\n");
		
	}
	return 0;
}