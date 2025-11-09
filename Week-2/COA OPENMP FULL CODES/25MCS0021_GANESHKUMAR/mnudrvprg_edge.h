#pragma once
#include <stdio.h>
#include "edge_detection.h"

int fn_mnudrvprg_edge() {
    int choice;
    initialize_image();  // Initialize image data before processing

    while (1) {
        printf("\nList of choices\n");
        printf("1 - Serial Edge Detection\t2 - Parallel Edge Detection\t0 - Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 0:
            printf("Exiting program.\n");
            return 0;

        case 1:
            fn_edge_serial();
            break;

        case 2:
            fn_edge_parallel();
            break;

        default:
            printf("Invalid choice!\n");
        }
    }
}

