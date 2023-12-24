 
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
/**
 * @brief Create boats.
 *
 * @param size The size of the boat.
 * @param xRef The abscissa
 * @param yRef The ordinate
 * @param orientation 
 *
 * @return The structure of the new boat.
 *
 */

BoatDesc createBoat(int size, int xRef, int yRef, char orientation) {
    BoatDesc newBoat;
    newBoat.size = size; // 
    newBoat.xRef = xRef;  // emplacement X of boat 
    newBoat.yRef = yRef; // emplacement Y of boat
    newBoat.Or = orientation; // h
    return newBoat;
}


/**
 * @brief Place boats on the grid.
 *
 * @param grid 
 * @param boat 
 *
 * @return 0 if it failed to place and 1 if it placed.
 *
 */
int placeBoatOnGrid(Grid *grid, BoatDesc *boat) {
    // Iterate over each part of the boat to check if it can be placed
    for (int i = 0; i < boat->size; i++) {
        // Determine coordinates for this part of the boat
        int x = boat->xRef + (boat->Or == 'H' ? i : 0);
        int y = boat->yRef + (boat->Or == 'V' ? i : 0);
        // Check if the part is outside the grid or not in water
        if (x < 0 || x >= grid->size || y < 0 || y >= grid->size || grid->grid[x][y] != WATER) {
            return 0;  // Fail to place the boat
        }
    }
 // Place the boat on the grid
    for (int i = 0; i < boat->size; i++) {
        int x = boat->xRef + (boat->Or == 'H' ? i : 0);
        int y = boat->yRef + (boat->Or == 'V' ? i : 0);
        grid->grid[x][y] = BOAT;  // Mark as boat
    }
    return 1;  // Success
}

/**
 * @brief Place boats manually.
 *
 * @param grid 
 * @param boatSizes 
 * @param numBoats
 *
 * @note Use the input of the user and call placeBoatOnGrid to place the boat
 *
 */
void placeBoatsManually(Grid *grid, int boatSizes[], int numBoats) {
    int x, y;
    char orientation;

    for (int i = 0; i < numBoats; i++) {
        printGrid(grid);
        printf("Place your boat of size %d (Enter x y orientation[H/V]): ", boatSizes[i]);
        scanf("%d %d %c", &x, &y, &orientation);
        x--; y--; // Adjust for 0-based indexing
        BoatDesc boat = createBoat(boatSizes[i], x, y, orientation);
        
        while (!placeBoatOnGrid(grid, &boat)) {
            printGrid(grid);
            printf("Invalid placement. Try again: ");
            scanf("%d %d %c", &x, &y, &orientation);
            x--; y--; // Adjust for 0-based indexing
            boat = createBoat(boatSizes[i], x, y, orientation);
        }
    }
    printGrid(grid);
}
