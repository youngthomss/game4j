#pragma once
#include <stdlib.h>

typedef struct Position* ptrPosition;
typedef struct Position position;


struct Position {
    int row;
    int col;
};

ptrPosition creerPosition();