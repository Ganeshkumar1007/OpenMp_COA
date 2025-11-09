#include<stdio.h>
#include "helloworld_prl.h"
#include <cstdlib>
#include "helloworld_serial.h"
#include "helloworld_parallel.h"

int fn_mnudrvprg_010_parallel_construct() {

	int choice;
	while(1){
		printf("#########################################################################################\n");
		printf("List of choice\n");
		printf("0:Exit\t 1: Hello World serial Program output\t 2: Hello World Parallel Program output\n");
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
				printf("This is ouput of Hello World serial Program\n");
				fn_helloworld_serial();
				break;
			}
			case 2:
			{
				printf("This is ouput of Hello World parallel Program\n");
				fn_helloworld_parallel();
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