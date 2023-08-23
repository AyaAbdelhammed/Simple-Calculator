#ifndef DIO_H__
#define DIO_H__
////////////////////////////////////////////////////
#include "tm4c123gh6pm.h"
#include "Bit_Math.h"
#include "types.h"
#include "DIO_Types.h"

#define PORTA_INPUT_PULL_RESIST GPIO_PORTA_PDR_R  //or GPIO_PORTA_PUR_R
#define PORTB_INPUT_PULL_RESIST GPIO_PORTB_PDR_R  //or GPIO_PORTB_PUR_R
#define PORTC_INPUT_PULL_RESIST GPIO_PORTC_PDR_R  //or GPIO_PORTC_PUR_R
#define PORTD_INPUT_PULL_RESIST GPIO_PORTD_PDR_R  //or GPIO_PORTD_PUR_R
#define PORTE_INPUT_PULL_RESIST GPIO_PORTE_PDR_R  //or GPIO_PORTE_PUR_R
#define PORTF_INPUT_PULL_RESIST GPIO_PORTF_PUR_R  //or GPIO_PORTF_PUR_R

void DIO_Init(void);
void DIO_WritePort(DIO_PortTypes portx , uint32 data);
void DIO_WritePin(DIO_PortTypes portx, uint8 binNumber, STD_Level level);
void DIO_WritePinBitBanding(DIO_PortTypes portx, uint8 binNumber, STD_Level level);
void DIO_WritePin_Port(unsigned int data);
uint8 DIO_ReadPin(DIO_PortTypes portx, uint8 binNumber);
uint8 DIO_ReadPinBitBanding(DIO_PortTypes portx, uint8 binNumber);
uint8 DIO_ReadPort(DIO_PortTypes portx);
void DIO_ChangePinDir(DIO_PortTypes portx, uint8 binNumber, DIO_DIR dir);



#endif
