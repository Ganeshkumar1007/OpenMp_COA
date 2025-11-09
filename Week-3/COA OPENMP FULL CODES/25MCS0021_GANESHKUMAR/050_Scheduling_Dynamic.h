#include<stdio.h>
#include<omp.h>
void fn_default_Dynamic_Scheduling()
{
    int i;
    int n = 16;
    // Set number of threads to 4
    omp_set_num_threads(4);
    printf("Dynamic Scheduling Example:\n");
#pragma omp parallel for schedule(dynamic)
    for (i = 0; i < n; i++) {
        int tid = omp_get_thread_num();
        printf("Iteration %d handled by thread %d\n", i, tid);
    }
}
void fn_dynamic_01()
{
    int i;
    int n = 16;
    // Set number of threads to 4
    omp_set_num_threads(4);
    printf("Dynamic Scheduling Example:\n");
#pragma omp parallel for schedule(dynamic,1)
    for (i = 0; i < n; i++) {
        int tid = omp_get_thread_num();
        printf("Iteration %d handled by thread %d\n", i, tid);
    }
}
void fn_dynamic_02()
{
    int i;
    int n = 16;
    // Set number of threads to 4
    omp_set_num_threads(4);
    printf("Dynamic Scheduling Example:\n");
#pragma omp parallel for schedule(dynamic,2)
    for (i = 0; i < n; i++) {
        int tid = omp_get_thread_num();
        printf("Iteration %d handled by thread %d\n", i, tid);
    }
}
