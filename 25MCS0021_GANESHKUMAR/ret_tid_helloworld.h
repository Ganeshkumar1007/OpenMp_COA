#pragma once
#include <stdio.h>
#include <omp.h>

void ret_tid_helloworld_srl() {
	printf("Hello world serial printed by thread id: %d \n", omp_get_thread_num());
}

void ret_tid_helloworld_prl() {
#pragma omp parallel
	printf("Hello world parallel printed by thread id: %d \n", omp_get_thread_num());
}
