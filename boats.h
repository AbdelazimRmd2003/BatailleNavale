// boats.h
#ifndef BOATS_H
#define BOATS_H

#include "types.h"  // Inclut les structures Grid et BoatDesc

BoatDesc createBoat(int size, int xRef, int yRef, char orientation);
int placeBoatOnGrid(Grid *grid, BoatDesc *boat);
void placeBoatsManually(Grid *grid, int boatSizes[], int numBoats);
int isThereABoat(Grid *grid);

#endif // BOATS_H
