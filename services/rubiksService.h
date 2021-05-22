#include "displayService.h"

int getIndex(Rubiks rubiks,T_SIDE side);

Rubiks turnFace(Rubiks rubiks, T_SIDE side, int turns);

Face rotateFaceCells(Face face, int turns);

Rubiks scrambleRubiks(Rubiks rubiks, int moves);

Rubiks horizontalRotation(Rubiks rubiks, int turns);

Rubiks verticalRotation(Rubiks rubiks, int turns);

Rubiks moveFaceFromMenu(Rubiks rubiks, T_SIDE side, int orientation);

Rubiks rotateRubiksFromMenu(Rubiks rubiks, int side, int orientation);
