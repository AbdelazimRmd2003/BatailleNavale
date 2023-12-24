// grid.h
#ifndef GRID_H
#define GRID_H

#include "types.h"  // Inclut les définitions de types nécessaires

// Prototypes des fonctions pour créer, afficher et libérer une grille de jeu
Grid createGrid(int size);
void printGrid(Grid *grid);
void printGridForShot(Grid *grid);
void printGridForShotOfComputer(Grid *grid);
void freeGrid(Grid *board);

#endif // GRID_H
