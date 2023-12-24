// types.h
#ifndef TYPES_H
#define TYPES_H

#define NB_BOATS_PER_PLAYER 5  // Define the number of boats per player
typedef enum {
    WATER,      // Case contains only water
    WATER_SHOT, // Case contains water and a shot
    BOAT,       // Case contains a boat
    WRECK       // Case contains a boat and a shot
} CaseType;

typedef struct {
    int size;     // Size of the boat
    int xRef, yRef; // Reference points
    char Or;      // Orientation of the boat ('H' for horizontal, 'V' for vertical)
} BoatDesc;       // Boat description

typedef struct {
    CaseType **grid;  // Double pointer for the matrix
    int size;         // Size of the grid
} Grid;              // Game grid

#endif

