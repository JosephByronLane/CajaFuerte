#include "project.h"
#include "project.h"
#include "LibDisplay.h"
#include "LibKeypad.h"
#include <string.h>
#include <stdlib.h>

void displayString(char *inputString, float delayTime) {
    int originalLength = strlen(inputString);
    

    char* strintToDisplay;

    if(originalLength > 2) {
        strintToDisplay = (char*)malloc(originalLength + 3); 

        strintToDisplay[0] = ' ';
        strcpy(strintToDisplay + 1, inputString);
        strcat(strintToDisplay, "  "); 
    } else {
        strintToDisplay = (char*)malloc(originalLength); 

        strcpy(strintToDisplay, inputString);
    }         
    
    int wordlength = strlen(strintToDisplay);
    
    if(originalLength<2){                
        wordlength++; 
    }
    for (int i = 0; i < wordlength-1; ++i) {
        for (int j = 0; j < delayTime/10; j++){
            prenderNum(strintToDisplay[i]);
            prenderLado(2);
            CyDelay(10);
            if(originalLength>1){                
                prenderNum(strintToDisplay[i+1]);
                prenderLado(1);
                CyDelay(10);  
            }
            }
        }   
      free(strintToDisplay);
}

void prenderNumInt(int n){
    switch(n){
        case 0:
            vec_1_Write(0x3F);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
        case 1:
            vec_1_Write(0x06);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
        case 2:
            vec_1_Write(0x1B);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 3:
            vec_1_Write(0x0F);
            vec_2_Write(0x0);
            vec_3_Write(0x1);
        break;
        case 4:
            vec_1_Write(0x26);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 5:
            vec_1_Write(0x2D);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 6:
            vec_1_Write(0x1F);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 7:
            vec_1_Write(0x07);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
        case 8:
            vec_1_Write(0xBF);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
         case 9:
            vec_1_Write(0x27);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
            
        case '0':
            vec_1_Write(0x3F);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
 

        default:break;
    }
}
void prenderNum(char n){
    switch(n){

                 case '1':
            vec_1_Write(0x06);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
        case '2':
            vec_1_Write(0x1B);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case '3':
            vec_1_Write(0x0F);
            vec_2_Write(0x0);
            vec_3_Write(0x1);
        break;
        case '4':
            vec_1_Write(0x26);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case '5':
            vec_1_Write(0x2D);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case '6':
            vec_1_Write(0x1F);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case '7':
            vec_1_Write(0x07);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
        case '8':
            vec_1_Write(0xBF);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
         case '9':
            vec_1_Write(0x27);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;  
            
        case 'A':
            vec_1_Write(0x37);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 'B':
            vec_1_Write(0x3C);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 'C':
            vec_1_Write(0x39);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
        case 'D':
            vec_1_Write(0x1E);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 'E':
            vec_1_Write(0x39);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 'F':
            vec_1_Write(0x31);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 'G':
            vec_1_Write(0x3D);
            vec_2_Write(0x0);
            vec_3_Write(0x1);
        break;
        case 'H':
            vec_1_Write(0x36);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 'I':
            vec_1_Write(0x09);
            vec_2_Write(0x1);
            vec_3_Write(0x4);
        break;
        case 'J':
            vec_1_Write(0x1E);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
        case 'K':
            vec_1_Write(0x00);
            vec_2_Write(0x3);
            vec_3_Write(0xC);
        break;
        case 'L':
            vec_1_Write(0x38);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
        case 'M':
            vec_1_Write(0x76);
            vec_2_Write(0x2);
            vec_3_Write(0x0);
        break;
        case 'N':
            vec_1_Write(0x76);
            vec_2_Write(0x0);
            vec_3_Write(0x8);
        break;
        case 'O':
            vec_1_Write(0x3F);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
        case 'P':
            vec_1_Write(0x33);
            vec_2_Write(0x4);
            vec_3_Write(0x1);
        break;
        case 'Q':
            vec_1_Write(0x3f);
            vec_2_Write(0x0);
            vec_3_Write(0x8);            
        break;
        case 'R':
            vec_1_Write(0x33);
            vec_2_Write(0x4);
            vec_3_Write(0x9);            
        break;
        case 'S':
            vec_1_Write(0x2d);
            vec_2_Write(0x4);
            vec_3_Write(0x1);            
        break;
        case 'T':
            vec_1_Write(0x01);
            vec_2_Write(0x1);
            vec_3_Write(0x4);            
        break;
        case 'U':
            vec_1_Write(0x3E);
            vec_2_Write(0x0);
            vec_3_Write(0x0);            
        break;
        case 'V':
            vec_1_Write(0x30);
            vec_2_Write(0x2);
            vec_3_Write(0x2);            
        break;
        case 'W':
            vec_1_Write(0x36);
            vec_2_Write(0x0);
            vec_3_Write(0xA);            
        break;
        case 'X':
            vec_1_Write(0x40);
            vec_2_Write(0x2);
            vec_3_Write(0xA);            
        break;
        case 'Y':
            vec_1_Write(0x40);
            vec_2_Write(0x2);
            vec_3_Write(0x4);            
        break;
        case 'Z':
            vec_1_Write(0x09);
            vec_2_Write(0x2);
            vec_3_Write(0x2);            
        break;
        case ' ':
            vec_1_Write(0x0);
            vec_2_Write(0x0);
            vec_3_Write(0x0);
        break;
        case 't':
            vec_1_Write(0b1111111);
            vec_2_Write(0b111);
            vec_3_Write(0b1111);
        break;
         case '*':
            vec_1_Write(0x40);
            vec_2_Write(0x7);
            vec_3_Write(0xF);
        break;
        default:break;
    }
}

void prenderLado(int n){
    switch(n){
        case 0:
            cat_Write(0x3);
        break;
        case 1:
            cat_Write(0x2);
        break;
        case 2:
            cat_Write(0x1);
        break;
        case 3:
            cat_Write(0x0);
        break;
            
        default:break;
    }
}

void apagar(void){
    cat_Write(0x3);
}