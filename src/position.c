#include "position.h"

ptrPosition creerPosition() {
    int size = sizeof(position);
    ptrPosition p = malloc(size);

    p->row = 0;
    p->col = 0;

    return p;
}