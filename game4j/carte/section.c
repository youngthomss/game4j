#include "section.h"


ptrSection creerSection(int x, int y) {
    int size = sizeof(section);
    ptrSection c = malloc(size);
    c -> x = x;
    c -> y = y;

    return c;
}


ptrArrete creerArrete(ptrSection sections, int distance) {
    int size = sizeof(arrete);
    ptrArrete arrete = malloc(size);
    arrete->section = sections;
    arrete->distance = distance;
}
