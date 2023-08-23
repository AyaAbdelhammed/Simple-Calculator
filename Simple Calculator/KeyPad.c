#include "KeyPad.h"

const uint8 symbol[ROWS][COLS] = {
                                  {'1','2','3','+'},
                                  {'4','5','6','-'},
                                  {'7','8','9','='},
                                  {'*','0','#','D'}

};


void keypadInit(void){
    DIO_Init();
}

char keypadGetKey(void){
    int i, j;
    while(1){
        for(i = 0; i < ROWS; i++){
            DIO_WritePort(DIO_PortC, (1u<<(i+4)));
            delay_us(2);
            for(j = 0; j < COLS; j++){
                if((DIO_ReadPort(DIO_PortE) & 0x1E) & (1u<<j+1)){
                    return symbol[j][i];
                }
            }
        }
    }
}
