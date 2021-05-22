#include "rubiksService.h"
#include <stdio.h>
#include <stdlib.h>


int getIndex(Rubiks rubiks,T_SIDE side)
{
    for(int i = 0; i < 6; i++)
    {
        if(rubiks.faces[i].side == side)
        {
            return i;
        }
    }
    return -1;
}

Rubiks turnFace(Rubiks rubiks, T_SIDE side, int turns)
{
    int frontIndex = getIndex(rubiks,FRONT);
    int rightIndex = getIndex(rubiks,RIGHT);
    int leftIndex = getIndex(rubiks,LEFT);
    int upIndex = getIndex(rubiks,UP);
    int downIndex = getIndex(rubiks,DOWN);
    int backIndex = getIndex(rubiks,BACK);

    Cell tmpCell1;
    Cell tmpCell2;
    Cell tmpCell3;

    switch(side)
    {
    case FRONT:
        for( int i = 0; i < turns; i++)
        {
            tmpCell1 = rubiks.faces[upIndex].cells[2][0];
            tmpCell2 = rubiks.faces[upIndex].cells[2][1];
            tmpCell3 = rubiks.faces[upIndex].cells[2][2];
            rubiks.faces[upIndex].cells[2][0] = rubiks.faces[rightIndex].cells[0][0];
            rubiks.faces[upIndex].cells[2][1] = rubiks.faces[rightIndex].cells[1][0];
            rubiks.faces[upIndex].cells[2][2] = rubiks.faces[rightIndex].cells[2][0];
            rubiks.faces[rightIndex].cells[0][0] = rubiks.faces[downIndex].cells[0][2];
            rubiks.faces[rightIndex].cells[1][0] = rubiks.faces[downIndex].cells[0][1];
            rubiks.faces[rightIndex].cells[2][0] = rubiks.faces[downIndex].cells[0][0];
            rubiks.faces[downIndex].cells[0][2] = rubiks.faces[leftIndex].cells[2][2];
            rubiks.faces[downIndex].cells[0][1] = rubiks.faces[leftIndex].cells[1][2];
            rubiks.faces[downIndex].cells[0][0] = rubiks.faces[leftIndex].cells[0][2];
            rubiks.faces[leftIndex].cells[2][2] = tmpCell1;
            rubiks.faces[leftIndex].cells[1][2] = tmpCell2;
            rubiks.faces[leftIndex].cells[0][2] = tmpCell3;
            rubiks.faces[frontIndex] = rotateFaceCells(rubiks.faces[frontIndex], 1);
            printf("Turned front for %d/%d turns. \n",i+1,turns);

        }
        return rubiks;
    case RIGHT:
        for( int i = 0; i < turns; i++)
        {
            tmpCell1 = rubiks.faces[upIndex].cells[2][2];
            tmpCell2 = rubiks.faces[upIndex].cells[1][2];
            tmpCell3 = rubiks.faces[upIndex].cells[0][2];
            rubiks.faces[upIndex].cells[2][2] = rubiks.faces[backIndex].cells[0][0];
            rubiks.faces[upIndex].cells[1][2] = rubiks.faces[backIndex].cells[1][0];
            rubiks.faces[upIndex].cells[0][2] = rubiks.faces[backIndex].cells[2][0];
            rubiks.faces[backIndex].cells[0][0] = rubiks.faces[downIndex].cells[2][2];
            rubiks.faces[backIndex].cells[1][0] = rubiks.faces[downIndex].cells[1][2];
            rubiks.faces[backIndex].cells[2][0] = rubiks.faces[downIndex].cells[0][2];
            rubiks.faces[downIndex].cells[2][2] = rubiks.faces[frontIndex].cells[2][2];
            rubiks.faces[downIndex].cells[1][2] = rubiks.faces[frontIndex].cells[1][2];
            rubiks.faces[downIndex].cells[0][2] = rubiks.faces[frontIndex].cells[0][2];
            rubiks.faces[frontIndex].cells[2][2] = tmpCell1;
            rubiks.faces[frontIndex].cells[1][2] = tmpCell2;
            rubiks.faces[frontIndex].cells[0][2] = tmpCell3;
            rubiks.faces[rightIndex] = rotateFaceCells(rubiks.faces[rightIndex], 1);

            printf("Turned right for %d/%d turns. \n",i+1,turns);

        }
        return rubiks;
    case LEFT:
        for( int i = 0; i < turns; i++)
        {
            tmpCell1 = rubiks.faces[upIndex].cells[0][0];
            tmpCell2 = rubiks.faces[upIndex].cells[1][0];
            tmpCell3 = rubiks.faces[upIndex].cells[2][0];
            rubiks.faces[upIndex].cells[0][0] = rubiks.faces[frontIndex].cells[0][0];
            rubiks.faces[upIndex].cells[1][0] = rubiks.faces[frontIndex].cells[1][0];
            rubiks.faces[upIndex].cells[2][0] = rubiks.faces[frontIndex].cells[2][0];
            rubiks.faces[frontIndex].cells[0][0] = rubiks.faces[downIndex].cells[0][0];
            rubiks.faces[frontIndex].cells[1][0] = rubiks.faces[downIndex].cells[1][0];
            rubiks.faces[frontIndex].cells[2][0] = rubiks.faces[downIndex].cells[2][0];
            rubiks.faces[downIndex].cells[0][0] = rubiks.faces[backIndex].cells[0][2];
            rubiks.faces[downIndex].cells[1][0] = rubiks.faces[backIndex].cells[1][2];
            rubiks.faces[downIndex].cells[2][0] = rubiks.faces[backIndex].cells[2][2];
            rubiks.faces[backIndex].cells[0][2] = tmpCell1;
            rubiks.faces[backIndex].cells[1][2] = tmpCell2;
            rubiks.faces[backIndex].cells[2][2] = tmpCell3;
            rubiks.faces[leftIndex] = rotateFaceCells(rubiks.faces[leftIndex], 1);

            printf("Turned left for %d/%d turns. \n",i+1,turns);

        }
        return rubiks;
    case BACK:
        for( int i = 0; i < turns; i++)
        {
            tmpCell1 = rubiks.faces[upIndex].cells[0][2];
            tmpCell2 = rubiks.faces[upIndex].cells[0][1];
            tmpCell3 = rubiks.faces[upIndex].cells[0][0];
            rubiks.faces[upIndex].cells[0][2] = rubiks.faces[leftIndex].cells[0][0];
            rubiks.faces[upIndex].cells[0][1] = rubiks.faces[leftIndex].cells[1][0];
            rubiks.faces[upIndex].cells[0][0] = rubiks.faces[leftIndex].cells[2][0];
            rubiks.faces[leftIndex].cells[0][0] = rubiks.faces[downIndex].cells[2][0];
            rubiks.faces[leftIndex].cells[1][0] = rubiks.faces[downIndex].cells[2][1];
            rubiks.faces[leftIndex].cells[2][0] = rubiks.faces[downIndex].cells[2][2];
            rubiks.faces[downIndex].cells[2][0] = rubiks.faces[rightIndex].cells[2][2];
            rubiks.faces[downIndex].cells[2][1] = rubiks.faces[rightIndex].cells[1][2];
            rubiks.faces[downIndex].cells[2][2] = rubiks.faces[rightIndex].cells[0][2];
            rubiks.faces[rightIndex].cells[2][2] = tmpCell1;
            rubiks.faces[rightIndex].cells[1][2] = tmpCell2;
            rubiks.faces[rightIndex].cells[0][2] = tmpCell3;
            rubiks.faces[backIndex] = rotateFaceCells(rubiks.faces[backIndex], 1);

            printf("Turned back for %d/%d turns. \n",i+1,turns);

        }
        return rubiks;
    case UP:
        for( int i = 0; i < turns; i++)
        {
            tmpCell1 = rubiks.faces[backIndex].cells[0][2];
            tmpCell2 = rubiks.faces[backIndex].cells[0][1];
            tmpCell3 = rubiks.faces[backIndex].cells[0][0];
            rubiks.faces[backIndex].cells[0][2] = rubiks.faces[rightIndex].cells[0][2];
            rubiks.faces[backIndex].cells[0][1] = rubiks.faces[rightIndex].cells[0][1];
            rubiks.faces[backIndex].cells[0][0] = rubiks.faces[rightIndex].cells[0][0];
            rubiks.faces[rightIndex].cells[0][2] = rubiks.faces[frontIndex].cells[0][2];
            rubiks.faces[rightIndex].cells[0][1] = rubiks.faces[frontIndex].cells[0][1];
            rubiks.faces[rightIndex].cells[0][0] = rubiks.faces[frontIndex].cells[0][0];
            rubiks.faces[frontIndex].cells[0][2] = rubiks.faces[leftIndex].cells[0][2];
            rubiks.faces[frontIndex].cells[0][1] = rubiks.faces[leftIndex].cells[0][1];
            rubiks.faces[frontIndex].cells[0][0] = rubiks.faces[leftIndex].cells[0][0];
            rubiks.faces[leftIndex].cells[0][2] = tmpCell1;
            rubiks.faces[leftIndex].cells[0][1] = tmpCell2;
            rubiks.faces[leftIndex].cells[0][0] = tmpCell3;
            rubiks.faces[upIndex] = rotateFaceCells(rubiks.faces[upIndex], 1);

            printf("Turned up for %d/%d turns. \n",i+1,turns);

        }
        return rubiks;
    case DOWN:
        for( int i = 0; i < turns; i++)
        {
            tmpCell1 = rubiks.faces[frontIndex].cells[2][0];
            tmpCell2 = rubiks.faces[frontIndex].cells[2][1];
            tmpCell3 = rubiks.faces[frontIndex].cells[2][2];
            rubiks.faces[frontIndex].cells[2][0] = rubiks.faces[rightIndex].cells[2][0];
            rubiks.faces[frontIndex].cells[2][1] = rubiks.faces[rightIndex].cells[2][1];
            rubiks.faces[frontIndex].cells[2][2] = rubiks.faces[rightIndex].cells[2][2];
            rubiks.faces[rightIndex].cells[2][0] = rubiks.faces[backIndex].cells[2][0];
            rubiks.faces[rightIndex].cells[2][1] = rubiks.faces[backIndex].cells[2][1];
            rubiks.faces[rightIndex].cells[2][2] = rubiks.faces[backIndex].cells[2][2];
            rubiks.faces[backIndex].cells[2][0] = rubiks.faces[leftIndex].cells[2][0];
            rubiks.faces[backIndex].cells[2][1] = rubiks.faces[leftIndex].cells[2][1];
            rubiks.faces[backIndex].cells[2][2] = rubiks.faces[leftIndex].cells[2][2];
            rubiks.faces[leftIndex].cells[2][0] = tmpCell1;
            rubiks.faces[leftIndex].cells[2][1] = tmpCell2;
            rubiks.faces[leftIndex].cells[2][2] = tmpCell3;
            rubiks.faces[downIndex] = rotateFaceCells(rubiks.faces[downIndex], 1);

            printf("Turned down for %d/%d turns. \n",i+1,turns);

        }
        return rubiks;
    default:
        return rubiks;
    }
}

Face rotateFaceCells(Face face, int turns)
{
    for( int i = 0; i < turns; i++)
    {
        Cell tmpCell1 = face.cells[0][0];
        Cell tmpCell2 = face.cells[0][1];
        face.cells[0][0] = face.cells[0][2];
        face.cells[0][1] = face.cells[1][2];
        face.cells[0][2] = face.cells[2][2];
        face.cells[1][2] = face.cells[2][1];
        face.cells[2][2] = face.cells[2][0];
        face.cells[2][1] = face.cells[1][0];
        face.cells[2][0] = tmpCell1;
        face.cells[1][0] = tmpCell2;
    }
    return face;
}

Rubiks scrambleRubiks(Rubiks rubiks, int moves)
{
    for(int i = 0; i < moves; i++)
    {
        rubiks = turnFace(rubiks, rand() % 6, 1);
    }
    return rubiks;
}

Rubiks horizontalRotation(Rubiks rubiks, int turns)
{
    int frontIndex = 0;
    int rightIndex = 0;
    int leftIndex = 0;
    int backIndex = 0;
    int upIndex = 0;
    int downIndex = 0;
    for( int i = 0 ; i < turns; i++)
    {
        frontIndex = getIndex(rubiks,FRONT);
        rightIndex = getIndex(rubiks,RIGHT);
        leftIndex = getIndex(rubiks,LEFT);
        backIndex = getIndex(rubiks,BACK);
        upIndex = getIndex(rubiks,UP);
        downIndex = getIndex(rubiks,DOWN);
        rubiks.faces[upIndex] = rotateFaceCells(rubiks.faces[upIndex],1);
        rubiks.faces[downIndex] = rotateFaceCells(rubiks.faces[downIndex],3);
        rubiks.faces[frontIndex].side=RIGHT;
        rubiks.faces[leftIndex].side=FRONT;
        rubiks.faces[backIndex].side=LEFT;
        rubiks.faces[rightIndex].side=BACK;

        printf("Rotate right for %d/%d turns. \n", i+1, turns);
    }
    return rubiks;
}

Rubiks verticalRotation(Rubiks rubiks, int turns)
{
    int frontIndex = 0;
    int rightIndex = 0;
    int leftIndex = 0;
    int backIndex = 0;
    int upIndex = 0;
    int downIndex = 0;
    for( int i = 0 ; i < turns; i++)
    {
        frontIndex = getIndex(rubiks,FRONT);
        rightIndex = getIndex(rubiks,RIGHT);
        leftIndex = getIndex(rubiks,LEFT);
        backIndex = getIndex(rubiks,BACK);
        upIndex = getIndex(rubiks,UP);
        downIndex = getIndex(rubiks,DOWN);
        rubiks.faces[rightIndex] = rotateFaceCells(rubiks.faces[rightIndex],3);
        rubiks.faces[leftIndex] = rotateFaceCells(rubiks.faces[leftIndex],1);
        rubiks.faces[upIndex] = rotateFaceCells(rubiks.faces[upIndex],2);
        rubiks.faces[frontIndex].side=UP;
        rubiks.faces[downIndex].side=FRONT;
        rubiks.faces[backIndex].side=DOWN;
        rubiks.faces[upIndex].side=BACK;
        printf("Rotate rubiks up for %d/%d turns. \n",i+1,turns);
    }
    return rubiks;
}

Rubiks moveFaceFromMenu(Rubiks rubiks, T_SIDE side, int orientation)
{
    int turns = 1;
    if(orientation == 1)
    {
        turns = 3;
    }
    return turnFace(rubiks, side, turns);

}

Rubiks rotateRubiksFromMenu(Rubiks rubiks, int side, int orientation)
{
    int turns = 1;
    if(orientation == 2)
    {
        turns = 3;
    }
    if(side == 1)
    {
        return verticalRotation(rubiks, turns);
    } else {
        return horizontalRotation(rubiks, turns);
    }
}


