#include "project.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LibDisplay.h"
#include "LED_Actions.h"
#include "PasswordActions.h"
volatile char keyPressed;

CY_ISR(Keypad_ISR){       
    
    Row_ClearInterrupt();
    int aux = Row_Read();
        
    bool validkey;
    int i,j;
    for( i=0, j=0;i<255; ++i){
        if(aux == 0xE || aux == 0xD || aux == 0xB || aux == 0x7){
            j++;            
            if (j == 100){validkey = true; break;}            
        }
        else{j=0; return;}
            
    }
    if(validkey == true){
        makeLEDWhite();
        Columns_1_Write(0b01);
        Columns_2_Write(0b11);
        
        
        if(Row_Read() == 0xE) {
            keyPressed = '1';            
        } else if (Row_Read() == 0xD) {
            keyPressed = '4';
        } else if(Row_Read() == 0xB) {
            keyPressed = '7';
        } else if(Row_Read() == 0x7) {            
            resetPassword();            
            Columns_1_Write(0b00);
            Columns_2_Write(0b00);
            return ;
        }

        Columns_1_Write(0b10);

        if(Row_Read() == 0xE) {
            keyPressed = '2';
        } else if (Row_Read() == 0xD) {
            keyPressed = '5';
        } else if(Row_Read() == 0xB) {
            keyPressed = '8';
        } else if(Row_Read() == 0x7) {
            keyPressed = '0';
        }

        Columns_1_Write(0b11);
        Columns_2_Write(0b01);

        if(Row_Read() == 0xE) {
            keyPressed = '3';
        } else if (Row_Read() == 0xD) {
            keyPressed = '6';
        } else if(Row_Read() == 0xB) {
            keyPressed = '9';
        } else if(Row_Read() == 0x7) {
            //nothing
        }

        Columns_2_Write(0b10);

        if(Row_Read() == 0xE) {
            checkPassword();            
            resetPassword();            
            Columns_1_Write(0b00);
            Columns_2_Write(0b00);
            return ;
        } else if (Row_Read() == 0xD) {
            //move servo that we don't have
        } else if(Row_Read() == 0xB) {
            changePasswordCensoring();
        } else if(Row_Read() == 0x7) {
            setNewPassword();
            resetPassword();
            Columns_1_Write(0b00);
            Columns_2_Write(0b00);            
            return ;
        }

        addToPasswords(keyPressed);
     
        
    }    
    Columns_1_Write(0b00);
    Columns_2_Write(0b00);   

}

void startkeypad(){
   
    Keypad_ISR_StartEx(Keypad_ISR);
    Columns_1_Write(0b00);
    Columns_2_Write(0b00);
    Keypad_ISR_Enable();   
}
