#include "rubiksService.h"
#include <windows.h>
#include <stdio.h>
#include <unistd.h>


void displayClearRubiksAndMenu(Rubiks rubiks)
{
    clearScreen();
    displayHeader();
    displayRubiks(rubiks);
    displayMenu();
}
void displayClearRubiksAndPlayMenu(Rubiks rubiks)
{
    clearScreen();
    displayHeader();
    displayRubiks(rubiks);
    displayPlayMenu();
}

void clearScreen()
{
    system("cls");

}

void displayHeader()
{
    printf("\n\n---------------------------------------------------------------------------------------------------------\n");
    printf("                                  Welcome to the rubiks'cube game !   \n");
    printf("---------------------------------------------------------------------------------------------------------\n\n");
}

void displayMenu()
{
    printf("\n\n---------------------------------------------------------------------------------------------------------\n");
    printf("|   1: Scramble   |   2: Reset   |   3: Blank   |   4: Play   |   5:Fill   |   6: Solve   |   0: Exit   |\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
}
void displayPlayMenu()
{
    printf("\n\n----------------------------------------------------------\n");
    printf("|   1: Turn face   |   2: Rotate rubiks   |   0: Return   |\n");
    printf("-----------------------------------------------------------\n");
}
void displayFaceMenu()
{
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("|   1: FRONT   |   2: BACK   |   3: LEFT   |   4: RIGHT   |   5: UP   |   6: DOWN   |   0: Return   |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
}

void displayOrientationMenu()
{
    printf("----------------------------------------------------------\n");
    printf("|   1: Clockwise   |   2: Anticlockwise  |   0: Return   |\n");
    printf("----------------------------------------------------------\n");
}

void displayRotationMenu()
{
    printf("-------------------------------------------------------\n");
    printf("|   1: Vertical   |   2: Horizontal   |   0: Return   |\n");
    printf("-------------------------------------------------------\n");
}

void displayVerticalRotationWayMenu()
{
    printf("---------------------------------------------------\n");
    printf("|   1: Up Way   |   2: Down Way   |   0: Return   |\n");
    printf("---------------------------------------------------\n");
}

void displayHorizontalRotationWayMenu()
{
    printf("------------------------------------------------------\n");
    printf("|   1: Right Way   |   2: Left Way   |   0: Return   |\n");
    printf("------------------------------------------------------\n");
}




void displayRubiks(Rubiks rubiks)
{
    int frontIndex = getIndex(rubiks,FRONT);
    int rightIndex = getIndex(rubiks,RIGHT);
    int leftIndex = getIndex(rubiks,LEFT);
    int upIndex = getIndex(rubiks,UP);
    int downIndex = getIndex(rubiks,DOWN);
    int backIndex = getIndex(rubiks,BACK);

    displaySideLine(rubiks.faces[upIndex]);
    displayCenterLine(rubiks.faces[leftIndex], rubiks.faces[frontIndex], rubiks.faces[rightIndex], rubiks.faces[backIndex]);
    displaySideLine(rubiks.faces[downIndex]);
}
void displaySideLine(Face up)
{
    for(int i = 0; i < 3; i++)
    {
        printf("\t\t\t\t\t");
        printf("    ");
        for(int j = 0; j < 3; j++)
        {
            displayCell(up.cells[i][j]);
        }
        printf("\n");
    }
}

void displayCenterLine(Face right, Face front, Face left, Face back)
{
    for(int i = 0; i < 3; i++)
    {
        printf("\t\t\t\t\t");
        for(int j = 0; j < 3; j++)
        {
            displayCell(right.cells[i][j]);
        }
        printf("|");

        for(int j = 0; j < 3; j++)
        {
            displayCell(front.cells[i][j]);
        }
        printf("|");

        for(int j = 0; j < 3; j++)
        {
            displayCell(left.cells[i][j]);
        }
        printf("|");

        for(int j = 0; j < 3; j++)
        {
            displayCell(back.cells[i][j]);
        }
        printf("\n");
    }
}
void displayCell(Cell cell)
{
    Color(getColorDisplay(cell.color),0);
    printf("%s", "0");
    Color(15,0);
}

void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


int getColorDisplay(T_COLOR color)
{
    switch (color)
    {
    case R:
        return 4;
    case B:
        return 1;
    case G:
        return 2;
    case W:
        return 15;
    case Y:
        return 14;
    case O:
        return 12;
    case LG:
        return 8;
    default :
        return 8;
    }
}

Rubiks manageGlobalMenuChoice(Rubiks rubiks, char choice)
{
    int randomMoves =1;
    switch(choice)
    {
    case '1':
        printf("Combien de mouvements aleatoires voulez-vous faire pour melanger le rubiks'cube ?\n");
        scanf("%d", &randomMoves);
        return scrambleRubiks(rubiks,randomMoves);
    case '2':
        initRubiks(&rubiks);
        return rubiks;
    case '3':
        blankRubiks(&rubiks);
        return rubiks;
    case '4':
        return managePlaySession(rubiks);
    case '5':
    case '6':
    case '7':
    default:
        return rubiks;

    }
}

Rubiks managePlaySession(Rubiks rubiks)
{
    char choice = 'a';
    do
    {
        choice = 'a';
        displayClearRubiksAndPlayMenu(rubiks);
        scanf( "%c", &choice );
        rubiks = managePlayMenuChoice(rubiks, choice);
    }
    while(choice != '0');
    return rubiks;

}

Rubiks managePlayMenuChoice(Rubiks rubiks, char choice)
{
    int side = 1;
    int orientation = 1;
    switch(choice)
    {
    case '1':
        displayFaceMenu();
        scanf("%d", &side);
        if(side < 1 || side > 6)
        {
            return rubiks;
        }
        displayOrientationMenu();
        scanf("%d", &orientation);
        if(orientation != 1 && orientation != 2 )
        {
            return rubiks;
        }
        return moveFaceFromMenu(rubiks, getSideFromMenu(side),orientation);

    case '2':
        displayRotationMenu();
        scanf("%d", &side);
        if(side == 1)
        {
            displayVerticalRotationWayMenu();
        }
        if(side == 2)
        {
            displayHorizontalRotationWayMenu();
        }
        if(side != 1 && side != 2)
        {
            return rubiks;
        }
        scanf("%d", &orientation);
        if(orientation != 1 && orientation != 2)
        {
            return rubiks;
        }
        return rotateRubiksFromMenu(rubiks, side ,orientation);;
    default:
        return rubiks;

    }
}

T_SIDE getSideFromMenu(int side)
{
    switch(side)
    {
    case 1 :
        return FRONT;
    case 2 :
        return BACK;
    case 3 :
        return LEFT;
    case 4 :
        return RIGHT;
    case 5 :
        return UP;
    case 6 :
        return DOWN;
    default :
        return FRONT;

    }
}


