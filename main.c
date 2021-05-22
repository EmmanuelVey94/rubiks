#include <stdio.h>
#include <stdlib.h>
#include "services/rubiksService.h"

int main()
{
    char choice = 'a';
    Rubiks rubiks;
    initRubiks(&rubiks);
    do
    {
        choice = 'a';
        displayClearRubiksAndMenu(rubiks);
        scanf( "%c", &choice );
        rubiks = manageGlobalMenuChoice(rubiks, choice);
    }
    while(choice != '0');
    return 0;
}



