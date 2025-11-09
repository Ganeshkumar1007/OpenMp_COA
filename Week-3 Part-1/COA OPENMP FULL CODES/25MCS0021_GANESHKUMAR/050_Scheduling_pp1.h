#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define NUM_ORDERS 20
#define NUM_THREADS 4

// Function to simulate order preparation
void simulate_preparation(int order_time) {
    double start = omp_get_wtime();
    while (omp_get_wtime() - start < order_time * 0.1); // simulate delay
}

// Static scheduling
void process_static() {
    int order_times[NUM_ORDERS];
    double start_time, end_time;
    int i;

    srand(time(NULL));
    for (i = 0; i < NUM_ORDERS; i++)
        order_times[i] = rand() % 10 + 1;

    omp_set_num_threads(NUM_THREADS);
    printf("\n===============================\n");
    printf("Scheduling Type: Static\n");
    printf("===============================\n");

    start_time = omp_get_wtime();

#pragma omp parallel for schedule(static,2)
    for (i = 0; i < NUM_ORDERS; i++) {
        int tid = omp_get_thread_num();
        simulate_preparation(order_times[i]);
#pragma omp critical
        {
            printf("Order %2d (Prep Time: %2d) handled by Thread %d\n",
                i + 1, order_times[i], tid);
        }
    }

    end_time = omp_get_wtime();
    printf("Execution Time (Static): %.4f seconds\n", end_time - start_time);
}

// Dynamic scheduling
void process_dynamic() {
    int order_times[NUM_ORDERS];
    double start_time, end_time;
    int i;

    srand(time(NULL) + 1);
    for (i = 0; i < NUM_ORDERS; i++)
        order_times[i] = rand() % 10 + 1;

    omp_set_num_threads(NUM_THREADS);
    printf("\n===============================\n");
    printf("Scheduling Type: Dynamic\n");
    printf("===============================\n");

    start_time = omp_get_wtime();

#pragma omp parallel for schedule(dynamic,2)
    for (i = 0; i < NUM_ORDERS; i++) {
        int tid = omp_get_thread_num();
        simulate_preparation(order_times[i]);
#pragma omp critical
        {
            printf("Order %2d (Prep Time: %2d) handled by Thread %d\n",
                i + 1, order_times[i], tid);
        }
    }

    end_time = omp_get_wtime();
    printf("Execution Time (Dynamic): %.4f seconds\n", end_time - start_time);
}

// Guided scheduling
void process_guided() {
    int order_times[NUM_ORDERS];
    double start_time, end_time;
    int i;

    srand(time(NULL) + 2);
    for (i = 0; i < NUM_ORDERS; i++)
        order_times[i] = rand() % 10 + 1;

    omp_set_num_threads(NUM_THREADS);
    printf("\n===============================\n");
    printf("Scheduling Type: Guided\n");
    printf("===============================\n");

    start_time = omp_get_wtime();

#pragma omp parallel for schedule(guided,2)
    for (i = 0; i < NUM_ORDERS; i++) {
        int tid = omp_get_thread_num();
        simulate_preparation(order_times[i]);
#pragma omp critical
        {
            printf("Order %2d (Prep Time: %2d) handled by Thread %d\n",
                i + 1, order_times[i], tid);
        }
    }

    end_time = omp_get_wtime();
    printf("Execution Time (Guided): %.4f seconds\n", end_time - start_time);
}

