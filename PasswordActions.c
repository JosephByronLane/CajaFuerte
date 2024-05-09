#include "project.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LibDisplay.h"
#include "LED_Actions.h"

int currentPasswordLength = 0; 

char initialPassword[] = "1234";
char displayPassword[100]; 
char actualPassword[100];
bool passwordCensoring = true;

void addToPasswords(char charatoadd){        
    if (currentPasswordLength < 99) { 
        actualPassword[currentPasswordLength] = charatoadd;
        if(passwordCensoring){displayPassword[currentPasswordLength] = '*';} else{displayPassword[currentPasswordLength] = charatoadd;};        
        currentPasswordLength++;
        actualPassword[currentPasswordLength] = '\0';
        displayPassword[currentPasswordLength] = '\0';
        CyDelay(500);

    }         
}

char* getDisplayPassword() {
    return displayPassword;
}

char* getActualPassword() {
    return actualPassword;
}

int getCurrentPasswordLength(){
    return currentPasswordLength;
}

void resetPassword(){
    makeLEDBlue();
    displayPassword[0] = '\0';
    actualPassword[0] = '\0';    
    currentPasswordLength = 0;
    displayString("RESET RESET RESET", 50);
    makeLEDWhite();
}

void checkPassword(){
    if (strcmp(initialPassword, actualPassword) == 0) {
        // Passwords match
        makeLEDGreen();
        displayString("YES YES YES YES YES", 50);
    } else {
        // Passwords do not match
        makeLEDBlue();
        displayString("NO NO NO NO NO",50);
    }
    makeLEDWhite();
}

void setNewPassword(){
    strcpy(initialPassword, actualPassword);     
    displayString("SET NEW PASSWORD", 100);
}

void changePasswordCensoring(){
    if(passwordCensoring){
        passwordCensoring=false;
    }
    else{
        passwordCensoring=true;
    }
    
    displayString("CHANGING MODE", 50);
    resetPassword();
}
