#include "side_enum.h"
#include "cell.h"

typedef struct Face
{
    Cell cells[3][3];
    T_SIDE side;
} Face;

void initFace(Face* face, T_SIDE pSide, T_COLOR pColor);
