#include "rubiks.h"

void initRubiks(Rubiks *rubiks){
    for(int i = 0; i < 6 ; i++){
        initFace(&(rubiks->faces[i]),i,i);
    }
}

void blankRubiks(Rubiks *rubiks){
    for(int i = 0; i < 6 ; i++){
        initFace(&(rubiks->faces[i]),i,LG);
    }
}

