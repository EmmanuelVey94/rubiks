#include "face.h"


void initFace(Face* face, T_SIDE pSide, T_COLOR pColor)
{
    face->side = pSide;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0 ; j < 3; j++)
        {
            initCell(&(face->cells[i][j]),pColor);
        }
    }
};
