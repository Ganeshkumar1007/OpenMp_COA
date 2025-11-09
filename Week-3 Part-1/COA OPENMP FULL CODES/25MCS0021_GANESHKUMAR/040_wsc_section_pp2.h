#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define DECK_SIZE 52
#define HALF_DECK 26

void playGame() {
    int deck[DECK_SIZE];
    int player1[HALF_DECK], player2[HALF_DECK];

    // Initialize deck
    for (int i = 0; i < DECK_SIZE; i++)
        deck[i] = i + 1;

    srand(time(NULL));

#pragma omp parallel
    {
        // Single: only one thread prints the message
#pragma omp single
        printf("\n=== Starting the Card Game Simulation ===\n");

        // Parallel for: shuffle deck
#pragma omp for
        for (int i = 0; i < DECK_SIZE; i++) {
            int j = rand() % DECK_SIZE;
            int temp = deck[i];
            deck[i] = deck[j];
            deck[j] = temp;
        }

        // Sections: deal cards concurrently
#pragma omp sections
        {
#pragma omp section
            {
                for (int i = 0; i < HALF_DECK; i++)
                    player1[i] = deck[i];
                printf("Player 1 dealt (Thread %d)\n", omp_get_thread_num());
            }

#pragma omp section
            {
                for (int i = 0; i < HALF_DECK; i++)
                    player2[i] = deck[i + HALF_DECK];
                printf("Player 2 dealt (Thread %d)\n", omp_get_thread_num());
            }
        }
    }

    // Print player cards
    printf("\nPlayer 1's Cards: ");
    for (int i = 0; i < HALF_DECK; i++)
        printf("%d ", player1[i]);

    printf("\nPlayer 2's Cards: ");
    for (int i = 0; i < HALF_DECK; i++)
        printf("%d ", player2[i]);

    printf("\n=== Game Setup Complete ===\n");
}
