
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
 * @param a Le premier nombre à ajouter. Cela devrait être un entier positif ou négatif.
 * @param b Le second nombre à ajouter. Comme 'a', cela peut être n'importe quel entier.
 * @return La somme des deux nombres entiers.
 *
 * @note Les utilisateurs de cette fonction doivent s'assurer que la somme ne dépasse pas
 *       les limites d'un entier pour éviter un dépassement.
 * @see soustraction(int, int) pour une opération similaire mais soustractive.
 */

BoatDesc createBoat(int size, int xRef, int yRef, char orientation) {
    BoatDesc newBoat;
    newBoat.size = size; // 
    newBoat.xRef = xRef;  // emplacement X of boat 
    newBoat.yRef = yRef; // emplacement Y of boat
    newBoat.Or = orientation; // h
    return newBoat;
}



// make move sert a lordi et au joueur la difference c 'est qu'il est l' ordi adeja fait ses verification avant
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

// Function to place boats with specified sizes
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
