#include "section.h"


ptrSection creerSection(int x, int y) {
    int size = sizeof(section);
    ptrSection c = malloc(size);
    c -> x = x;
    c -> y = y;

    return c;
}
