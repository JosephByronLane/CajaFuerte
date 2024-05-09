#include "project.h"
#include "LibDisplay.h"
#include "LibKeypad.h"
#include <string.h>
#include <stdlib.h>


void makeLEDWhite(){
    Led_R_Write(0);
    Led_B_Write(0);
}

void makeLEDBlue(){
    Led_R_Write(1);
    Led_B_Write(0);
}

void makeLEDGreen(){
    Led_R_Write(1);
    Led_B_Write(1);        
}

