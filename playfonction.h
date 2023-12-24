// playfonction.h
#ifndef PLAYFONCTION_H
#define PLAYFONCTION_H

#include "types.h"  // Inclut les structures Grid et autres types nécessaires

// Déclare la fonction pour effectuer un mouvement sur la grille
int makeMove(Grid *grid, int x, int y);

// Déclare la fonction pour gérer le mouvement de l'ordinateur
void computerMove(Grid *grid);

// Déclare la fonction pour jouer une partie
void playGame(Grid *playerGrid, Grid *computerGrid);

#endif // PLAYFONCTION_H
