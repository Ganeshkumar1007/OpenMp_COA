#include<stdio.h>

#include "ret_et_helloworld.h"
#include "ret_tid_helloworld.h"
#include <cstdlib>

int fn_mnudrvprg_020_runtime_environment_routines() {

	int choice;
	while (1) {
		printf("#########################################################################################\n");
		printf("List of choice\n");
		printf("0:Exit\t 1.Execution time of serial Program\t 2. Execution time of parallel Program\t 3.Thread id of serial Program\t 4.Thread id of parallel Program\n");
		printf("#########################################################################################\n");

		printf("Enter your choice\n");
		scanf_s("%d", &choice);
		switch (choice) {
		case 0:
		{
			printf("You opted to exit program");
			exit(0);
		}
		case 1:
		{
			printf("This is ouput of Execution time of serial Program\n");
			ret_et_helloworld_srl();
			break;
		}
		case 2:
		{
			printf("This is ouput of Execution time of parallel Program\n");
			ret_et_helloworld_prl();
			break;
		}
		case 3:
		{
			printf("This is ouput of Thread id of serial Program\n");
			ret_tid_helloworld_srl();
			break;
		}
		case 4:
		{
			printf("This is ouput of Thread id of parallel Program\n");
			ret_tid_helloworld_prl();
			break;
		}
		default:
		{
			printf("Opted wrong choice\n");
			break;
		}
		}
	}
	return 0;
}