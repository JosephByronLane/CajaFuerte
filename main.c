
#include "project.h"
#include "LibDisplay.h"
#include "LibKeypad.h"
#include <string.h>
#include <stdlib.h>
#include "PasswordActions.h"
#include "LED_Actions.h"
#include <stdbool.h>


int main(void)
{
    CyGlobalIntEnable;
    startkeypad();
    for(;;)
    {        
        int length = getCurrentPasswordLength();
        char inputString[100];
        strncpy(inputString, getDisplayPassword(), sizeof(inputString) - 1);
        inputString[sizeof(inputString) - 1] = '\0';

        char displayBuffer[2] = " ";

        if (length >= 2) {
            makeLEDWhite();
            displayBuffer[0] = inputString[length - 2];
            displayBuffer[1] = inputString[length - 1];
        } else if (length == 1) {
            makeLEDBlue();
            displayBuffer[1] = inputString[0];
            displayBuffer[0] = ' ';
        }

        prenderNum(displayBuffer[0]); 
        prenderLado(2);    
        CyDelay(10);
        prenderNum(displayBuffer[1]);
        prenderLado(1); 
        CyDelay(10);

    }
}

