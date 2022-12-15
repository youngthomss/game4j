#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct Section section;
typedef struct Section* ptrSection;


struct Section {
    int x;
    int y;
    int terrain;
};



ptrSection creerSection(int x, int y);
