#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct Section section;
typedef struct Arrete arrete;
typedef struct Section* ptrSection;
typedef struct Arrete* ptrArrete;

struct Section {
    int x;
    int y;
    int terrain;
    ptrArrete arretes[];
};

struct Arrete {
    ptrSection section; 
    int distance;
};


ptrSection creerSection(int x, int y);
ptrArrete creerArrete(ptrSection sections, int distance);