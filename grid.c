#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include "playfonction.h"
#include "boats.h"
#include "types.h"
#define RESET_COLOR "\x1b[0m"
#define BLUE "\x1b[34m"    // Water
#define CYAN "\x1b[36m"    // Missed shot
#define RED "\x1b[31m"     // Hit boat part (Wreck)
#define GREEN "\x1b[32m"   // Boat
#define YELLOW "\x1b[33m"

Grid createGrid(int size) {
    Grid board; 
    board.size = size;
    board.grid = malloc(size * sizeof(CaseType*));

    if (board.grid == NULL) {
        fprintf(stderr, "Memory allocation error for the game grid\n");
        exit(0);
    }

    for (int i = 0; i < size; i++) {
        board.grid[i] = malloc(size * sizeof(CaseType));
        if (board.grid[i] == NULL) {
            fprintf(stderr, "Memory allocation error for a row of the grid\n");
            exit(0);
        }
        for (int j = 0; j < size; j++) {
            board.grid[i][j] = WATER;
        }
    }
    return board;
}





   

// Prints the game grid to the console with row and column indices
void printGrid(Grid *grid) {
    printf("    ");  // Leading spaces for row indices

    // Print column indices
    for (int col = 0; col < grid->size; col++) {
        printf("%d ", col + 1);  // Print column number
    }
    printf("\n");

    for (int y = 0; y < grid->size; y++) {
        printf("%2d  ", y + 1);  // Print row number with spacing for alignment

        // Iterate through each cell of the grid
        for (int x = 0; x < grid->size; x++) {
            // Display character based on cell state with color
            if (grid->grid[x][y] == WATER) {
                printf(BLUE "o " RESET_COLOR);  // 'o' for water
            } else if (grid->grid[x][y] == BOAT) {
                printf(GREEN "B " RESET_COLOR);  // 'B' for boat
            }
            
        }
        printf("\n");  // New line after each row
    }
}

void printGridForShot(Grid *grid) {
    printf("||YOUR ATTACK||\n"); 
    printf("    ");  // Leading spaces for row indices

    // Print column indices

    for (int col = 0; col < grid->size; col++) {
        printf("%d ", col + 1);  // Print column number
    }
    printf("\n");

    for (int y = 0; y < grid->size; y++) {
        printf("%2d  ", y + 1);  // Print row number with spacing for alignment

        // Iterate through each cell of the grid
        for (int x = 0; x < grid->size; x++) {
            // Display character based on cell state with color
            if (grid->grid[x][y] == WATER || grid->grid[x][y] == BOAT) {
                printf(BLUE "o " RESET_COLOR);  // 'o' for water and unrevealed boat
            } else if (grid->grid[x][y] == WATER_SHOT) {
                printf(RED "o " RESET_COLOR);  // '+' for missed shot
            } else if (grid->grid[x][y] == WRECK) {
                printf(RED "X " RESET_COLOR);  // 'X' for hit boat part
            }
        }
        printf("\n");  // New line after each row
    }
}

void printGridForShotOfComputer(Grid *grid) {
    printf("||ATTACK OF COMPUTER||\n"); 
    printf("    ");  // Leading spaces for row indices

    // Print column indices
    for (int col = 0; col < grid->size; col++) {
        printf("%d ", col + 1);  // Print column number
    }
    printf("\n");

    for (int y = 0; y < grid->size; y++) {
        printf("%2d  ", y + 1);  // Print row number with spacing for alignment

        // Iterate through each cell of the grid
        for (int x = 0; x < grid->size; x++) {
            // Display character based on cell state with color
            if (grid->grid[x][y] == WATER) {
                printf(BLUE "o " RESET_COLOR);  // 'o' for water
            } else if (grid->grid[x][y] == WATER_SHOT) {
                printf(RED "o " RESET_COLOR);  // '+' for missed shot
            } else if (grid->grid[x][y] == BOAT) {
                printf(GREEN "B " RESET_COLOR);  // 'B' for boat
            } else if (grid->grid[x][y] == WRECK) {
                printf(RED "X " RESET_COLOR);  // 'X' for hit boat part
            }
        }
        printf("\n");  // New line after each row
    }
}


// Function to free a game grid
void freeGrid(Grid *board) {
    for (int i = 0; i < board->size; i++) {
        free(board->grid[i]);  // Freeing each row
    }
    free(board->grid);        // Freeing the grid
    board->grid = NULL;       // Safety to avoid using after freeing
}


// Function for the computer to make a random move






