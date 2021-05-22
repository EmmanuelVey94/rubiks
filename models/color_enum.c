#include "color_enum.h"

const char* getColorName(T_COLOR color){
    switch (color)
   {
      case R: return "R";
      case B: return "B";
      case G: return "G";
      case W: return "W";
      case Y: return "Y";
      case O: return "O";
      case LG: return "LG";
      default : return "Error while getting color enum name, unknown value";
    }
}



