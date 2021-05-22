#include "../models/rubiks.h"

void displayClearRubiksAndMenu(Rubiks rubiks);
void displayClearRubiksAndPlayMenu(Rubiks rubiks);
void displayRubiks(Rubiks Rubiks);
void displaySideLine(Face side);
void displayCenterLine(Face right, Face front, Face left, Face back);
void displayCell(Cell cell);

void displayHeader();
void clearScreen();
void displayMenu();
void displayPlayMenu();
void displayFaceMenu();
void displayRotationMenu();
void displayOrientationMenu();
void displayRotationMenu();
void displayHorizontalRotationWayMenu();
void displayVerticalRotationWayMenu();


void Color(int couleurDuTexte,int couleurDeFond);
int getColorDisplay(T_COLOR color);
T_SIDE getSideFromMenu(int side);
Rubiks manageGlobalMenuChoice(Rubiks rubiks, char choice);
Rubiks managePlayMenuChoice(Rubiks rubiks, char choice);
Rubiks managePlaySession(Rubiks rubiks);




