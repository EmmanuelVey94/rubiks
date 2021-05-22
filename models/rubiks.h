#include "face.h"

typedef struct Rubiks
{
    Face faces[6];
} Rubiks;

void initRubiks(Rubiks* rubiks);

void blankRubiks(Rubiks* rubiks);
