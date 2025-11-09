#pragma once
#include <stdio.h>
#include <omp.h>


// 1. omp_set_num_threads
void fn_rter_omp_set_num_threads() {
    printf("1. ---- fn_rter_omp_set_num_threads ----\n");
    omp_set_num_threads(4); // Set thread count to 4
#pragma omp parallel
    {
#pragma omp master
        {
            printf("omp_set_num_threads(4) caused this parallel region to have %d threads.\n", omp_get_num_threads());
        }
    }
    printf("\n");
}

// 2. omp_get_num_threads
void fn_rter_omp_get_num_threads() {
    printf("2. ---- fn_rter_omp_get_num_threads ----\n");
#pragma omp parallel
    {
#pragma omp master
        {
            printf("Inside parallel region: omp_get_num_threads() = %d\n", omp_get_num_threads());
        }
    }
    printf("Outside parallel region: omp_get_num_threads() = %d\n", omp_get_num_threads());
    printf("\n");
}

// 3. omp_get_max_threads
void fn_rter_omp_get_max_threads() {
    printf("3. ---- fn_rter_omp_get_max_threads ----\n");
    printf("Max threads available to a parallel region: %d\n", omp_get_max_threads());
    printf("\n");
}

// 4. omp_get_thread_num
void fn_rter_omp_get_thread_num() {
    printf("4. ---- fn_rter_omp_get_thread_num ----\n");
#pragma omp parallel num_threads(3)
    {
        printf("This is thread number: %d\n", omp_get_thread_num());
    }
    printf("\n");
}

// 5. omp_get_num_procs
void fn_rter_omp_get_num_procs() {
    printf("5. ---- fn_rter_omp_get_num_procs ----\n");
    printf("Number of processors available: %d\n", omp_get_num_procs());
    printf("\n");
}

// 6. omp_in_parallel
void fn_rter_omp_in_parallel() {
    printf("6. ---- fn_rter_omp_in_parallel ----\n");
    printf("Checking outside parallel region: omp_in_parallel() = %s\n", omp_in_parallel() ? "true" : "false");
#pragma omp parallel
    {
#pragma omp master
        {
            printf("Checking inside parallel region: omp_in_parallel() = %s\n", omp_in_parallel() ? "true" : "false");
        }
    }
    printf("\n");
}

// 7 & 8. omp_set_dynamic / omp_get_dynamic
void fn_rter_omp_set_dynamic() {
    printf("7. ---- fn_rter_omp_set_dynamic ----\n");
    omp_set_dynamic(1); // Enable dynamic adjustment of threads
    printf("Dynamic threads enabled.\n");
    printf("\n");
}

void fn_rter_omp_get_dynamic() {
    printf("8. ---- fn_rter_omp_get_dynamic ----\n");
    printf("Is dynamic adjustment of threads enabled? %s\n", omp_get_dynamic() ? "Yes" : "No");
    omp_set_dynamic(0); // Disable for predictable behavior in other functions
    printf("Dynamic threads now disabled.\n");
    printf("\n");
}

// 9. omp_get_cancellation
void fn_rter_omp_get_cancellation() {
    printf("9. ---- fn_rter_omp_get_cancellation ----\n");
    printf("Cancellation support is: %s\n", omp_get_cancellation() ? "Enabled" : "Disabled");
    printf("\n");
}

// 10 & 11. omp_set_nested / omp_get_nested (Deprecated but requested)
void fn_rter_omp_set_nested() {
    printf("10. ---- fn_rter_omp_set_nested ----\n");
    omp_set_nested(1);
    printf("Nested parallelism has been enabled.\n");
    printf("\n");
}

void fn_rter_omp_get_nested() {
    printf("11. ---- fn_rter_omp_get_nested ----\n");
    printf("Is nested parallelism enabled? %s\n", omp_get_nested() ? "Yes" : "No");
    printf("\n");
}

// 12 & 13. omp_set_schedule / omp_get_schedule
void fn_rter_omp_set_schedule() {
    printf("12. ---- fn_rter_omp_set_schedule ----\n");
    omp_set_schedule(omp_sched_static, 4);
    printf("Schedule set to static with chunk size 4.\n");
    printf("\n");
}

void fn_rter_omp_get_schedule() {
    printf("13. ---- fn_rter_omp_get_schedule ----\n");
    omp_sched_t kind;
    int chunk_size;
    omp_get_schedule(&kind, &chunk_size);
    printf("Current schedule kind: %d (Static=%d, Dynamic=%d)\n", kind, omp_sched_static, omp_sched_dynamic);
    printf("Current chunk size: %d\n", chunk_size);
    printf("\n");
}

// 14. omp_get_thread_limit
void fn_rter_omp_get_thread_limit() {
    printf("14. ---- fn_rter_omp_get_thread_limit ----\n");
    printf("The maximum number of threads the program can create is: %d\n", omp_get_thread_limit());
    printf("\n");
}

// 15 & 16. omp_set_max_active_levels / omp_get_max_active_levels
void fn_rter_omp_set_max_active_levels() {
    printf("15. ---- fn_rter_omp_set_max_active_levels ----\n");
    omp_set_max_active_levels(2);
    printf("Max active nested parallel levels set to 2.\n");
    printf("\n");
}

void fn_rter_omp_get_max_active_levels() {
    printf("16. ---- fn_rter_omp_get_max_active_levels ----\n");
    printf("Max active nested parallel levels is: %d\n", omp_get_max_active_levels());
    printf("\n");
}

// 17. omp_get_level
void fn_rter_omp_get_level() {
    printf("17. ---- fn_rter_omp_get_level ----\n");
    printf("Outside parallel region, level is: %d\n", omp_get_level());
#pragma omp parallel
    {
#pragma omp master
        printf("Inside 1st parallel region, level is: %d\n", omp_get_level());
#pragma omp parallel
        {
#pragma omp master
            {
                printf("Inside 2nd (nested) parallel region, level is: %d\n", omp_get_level());
            }
        }
    }
    printf("\n");
}

// 18. omp_get_ancestor_thread_num
void fn_rter_omp_get_ancestor_thread_num() {
    printf("18. ---- fn_rter_omp_get_ancestor_thread_num ----\n");
#pragma omp parallel
    {
#pragma omp parallel
        {
#pragma omp master
            {
                printf("Current level: %d, Thread ID: %d\n", omp_get_level(), omp_get_thread_num());
                printf("Ancestor at level 1's ID: %d\n", omp_get_ancestor_thread_num(1));
                printf("Ancestor at level 0's ID: %d\n", omp_get_ancestor_thread_num(0));
            }
        }
    }
    printf("\n");
}

// 19. omp_get_team_size
void fn_rter_omp_get_team_size() {
    printf("19. ---- fn_rter_omp_get_team_size ----\n");
#pragma omp parallel
    {
#pragma omp parallel
        {
#pragma omp master
            {
                printf("At level %d, the team size is: %d\n", omp_get_level(), omp_get_team_size(omp_get_level()));
            }
        }
    }
    printf("\n");
}

// 20. omp_get_active_level
void fn_rter_omp_get_active_level() {
    printf("20. ---- fn_rter_omp_get_active_level ----\n");
#pragma omp parallel
    {
#pragma omp master
        printf("The active parallel level is: %d\n", omp_get_active_level());
    }
    printf("\n");
}

// 21. omp_in_final
void fn_rter_omp_in_final() {
    printf("21. ---- fn_rter_omp_in_final ----\n");
#pragma omp parallel
    {
#pragma omp task final(1)
        {
            printf("Inside final task: omp_in_final() = %s\n", omp_in_final() ? "true" : "false");
        }
    }
    printf("\n");
}

// 22. omp_get_proc_bind
void fn_rter_omp_get_proc_bind() {
    printf("22. ---- fn_rter_omp_get_proc_bind ----\n");
#pragma omp parallel
    {
#pragma omp master
        {
            // Note: Set OMP_PROC_BIND=true/close/spread to see different results.
            int binding = omp_get_proc_bind();
            printf("Processor binding policy for current thread: ");
            switch (binding) {
            case omp_proc_bind_false: printf("False"); break;
            case omp_proc_bind_true: printf("True"); break;
            case omp_proc_bind_master: printf("Master"); break;
            case omp_proc_bind_close: printf("Close"); break;
            case omp_proc_bind_spread: printf("Spread"); break;
            default: printf("Unknown");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// 23 & 24. omp_set_default_device / omp_get_default_device
void fn_rter_omp_set_default_device() {
    printf("23. ---- fn_rter_omp_set_default_device ----\n");
    if (omp_get_num_devices() > 0) {
        omp_set_default_device(0);
        printf("Default device set to 0.\n");
    }
    else {
        printf("No accelerator devices available to set.\n");
    }
    printf("\n");
}

void fn_rter_omp_get_default_device() {
    printf("24. ---- fn_rter_omp_get_default_device ----\n");
    if (omp_get_num_devices() > 0) {
        printf("Current default device is: %d\n", omp_get_default_device());
    }
    else {
        printf("No accelerator devices available.\n");
    }
    printf("\n");
}

// 25. omp_get_num_devices
void fn_rter_omp_get_num_devices() {
    printf("25. ---- fn_rter_omp_get_num_devices ----\n");
    printf("Number of available accelerator devices: %d\n", omp_get_num_devices());
    printf("\n");
}

// 26 & 27. omp_get_num_teams / omp_get_team_num
void fn_rter_omp_get_num_teams() {
    printf("26. ---- fn_rter_omp_get_num_teams ----\n");
#pragma omp teams num_teams(2)
#pragma omp parallel // <-- This line is added
    {
#pragma omp master
        {
            printf("Inside teams region: omp_get_num_teams() = %d\n", omp_get_num_teams());
        }
    }
    printf("\n");
}

void fn_rter_omp_get_team_num() {
    printf("27. ---- fn_rter_omp_get_team_num ----\n");
#pragma omp teams num_teams(3)
#pragma omp parallel // <-- This line is added
    {
#pragma omp master // Use master to have only one thread per team print
        {
            printf("This is team number: %d\n", omp_get_team_num());
        }
    }
    printf("\n");
}