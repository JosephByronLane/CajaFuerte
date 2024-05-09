#ifndef _LibDisplay_H_
#define _LibDisplay_H_
    
#include <cytypes.h>
    
extern void prenderCero(void);
extern void prenderUno(void);
extern void prenderDos(void);
extern void apagar(void);
extern void prenderNum(char n);
extern void prenderNumInt(int n);
extern void prenderLado(int n);
extern void displayString(char *inputString, float delayTime);
extern void dinamicallyDisplayString(char inputString[]);
#endif
