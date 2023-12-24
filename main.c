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
#define NB_BOATS_PER_PLAYER 5  // Define the number of boats per player


int main() {
    srand(time(NULL));

    Grid playerGrid = createGrid(10);
    Grid computerGrid = createGrid(10);
    printf(CYAN "Welcome to Battleship!\n\n" RESET_COLOR
       GREEN "Objective:" RESET_COLOR " You and the computer have hidden grids with ships. The first to sink all enemy ships wins!\n\n"
       "Before you start:\n"
       "- You'll place several ships of varying sizes on your grid.\n"
       "- Position your ships by specifying the coordinates and orientation (horizontal or vertical).\n"
       "- Make sure ships don't overlap and are within the grid bounds.\n\n"
       "Grid Symbols:"  "\n"
       BLUE "'o'" RESET_COLOR " Water - No shots here.\n"
       RED "'o'" RESET_COLOR " Miss - You've shot here, but no ship was hit.\n"
       GREEN "'B'" RESET_COLOR " Ship (your grid only) - Location of your ships.\n"
       RED "'X'" RESET_COLOR " Hit - One of your shots has hit an enemy ship.\n\n"
       "During the game:\n"
       "- Enter coordinates (x y) to fire, e.g., '3 5'.\n"
       "- The game will update you after each turn. Pay attention to the grid to plan your next move.\n\n"
       "Good luck, and may the best strategist win!\n");

    int boatSizes[NB_BOATS_PER_PLAYER] = {2, 3, 3, 4, 5};

    // Player places boats
    printf("Player, place your boats:\n");
    placeBoatsManually(&playerGrid, boatSizes, NB_BOATS_PER_PLAYER);

    // Computer places boats randomly
    for (int i = 0; i < NB_BOATS_PER_PLAYER; i++) {
        while (!placeBoatOnGrid(&computerGrid, &(BoatDesc){boatSizes[i], rand() % computerGrid.size, rand() % computerGrid.size, (rand() % 2) ? 'H' : 'V'})) {}
    }
    printGrid(&computerGrid);
    
    printf("Welcome to Battleship!\n");

    // Play the game
    playGame(&playerGrid, &computerGrid);

    // Free memory and clean up resources
    freeGrid(&playerGrid);
    freeGrid(&computerGrid);

    return 0;
}
