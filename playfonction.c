#include <stdio.h>
#include <stdlib.h>
#include "playfonction.h"
#include "grid.h"
#include "boats.h"
#include "types.h"

/**
 * @brief The function take a shoot in the coordinates x and y in a grid and verify if the shoot become a water shot or a wreck depending on whether the shot happened on a boat or in the water.
 *
 * @param grid.
 * @param x The abscissa.
 * @param y The ordinate.
 *
 * @return The structure of the new boat.
 *
 */
int makeMove(Grid *grid, int x, int y) {
    // Check if coordinates are within the grid boundaries
    if (x >= 0 && x < grid->size && y >= 0 && y < grid->size) {
        // Check if the cell already has a shot (hit or miss)
        if (grid->grid[x][y] == WATER_SHOT || grid->grid[x][y] == WRECK) {
            printf("You've already shot here. Choose different coordinates.\n");
            return -1;  // Indicate invalid move (previously shot here)
        }

        // If the cell contains a boat, mark it as wrecked and return a hit (1)
        if (grid->grid[x][y] == BOAT) {
            grid->grid[x][y] = WRECK;
            return 1;
        } else if (grid->grid[x][y] == WATER) {
            // If the cell is water, mark it as a missed shot
            grid->grid[x][y] = WATER_SHOT;
        }
    } else {
        // Coordinates are out of the grid's bounds
        printf("Invalid coordinates. Please choose within the grid.\n");
        return -1;  // Indicate invalid move (out of bounds)
    }

    return 0;  // Indicate a miss (0) if none of the above conditions are met
}

// Function to play the game

void computerMove(Grid *grid) {
    int x, y;
    do {
        x = rand() % grid->size;  // Random x coordinate
        y = rand() % grid->size;  // Random y coordinate
    } while (grid->grid[x][y] == WATER_SHOT || grid->grid[x][y] == WRECK);  // Ensure it's a new move
    
    printf("Computer attacks (%d, %d)...\n", x + 1, y + 1);
    makeMove(grid, x, y);  // Make the move
}


void playGame(Grid *playerGrid, Grid *computerGrid) {
    int x, y, moveResult;
    int playerTurn = 1;  // Start with the player's turn

    // Game loop
    while (isThereABoat(playerGrid) && isThereABoat(computerGrid)) {
        if (playerTurn) {  // Si c'est au tour du joueur
            do {
                printf("Your turn! Enter coordinates to attack (x y): ");
                scanf("%d %d", &x, &y);

                

                // Adjust for 0-based indexing
                x--;
                y--;
                moveResult = makeMove(computerGrid, x, y);

                if (moveResult == -1) {  // Si le mouvement est invalide ou déjà effectué
                    printf("Invalid move or you've already shot there. Try again.\n");
                }

                // Vider le buffer d'entrée si nécessaire
                

            } while (moveResult != 1 && moveResult != 0);  // Continue jusqu'à ce qu'un coup valide soit effectué

            printGridForShot(computerGrid);
        } else {  // Si c'est au tour de l'ordinateur
            computerMove(playerGrid);
            printGridForShotOfComputer(playerGrid);  // Affiche la grille du joueur pour montrer où l'ordinateur a frappé
        }
        playerTurn = !playerTurn;  // Switch turns
    }

    // Determine and print the winner
    if (isThereABoat(computerGrid) == 0) {  // Vérifier si tous les bateaux ont été coulés
        printf("Congratulations! You've sunk all the enemy's boats!\n");
    } else {
        printf("Sorry, the computer has sunk all your boats. Better luck next time!\n");
    }
}


