#ifndef KEYPAD_H__
#define KEYPAD_H__

#include "Dio.h"
#include "Delay.h"
#include "types.h"

#define INT_MODE

#define ROWS  (4u)
#define COLS  (4u)


void keypadInit(void);
char keypadGetKey(void);

#ifdef INT_MODE

void keypadIntEn(void);
void keypadIntGetKey(void);
void keypadHandler(void);

#endif



#endif
