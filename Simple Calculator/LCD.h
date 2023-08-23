#ifndef LCD_H_
#define LCD_H_


#include "DIO_Types.h"
#include "DIO.h"
#include "Delay.h"

#define MODE8BIT (0U)
#define MODE4BIT (1U)

#define MYMODE  MODE8BIT

#define LCDPort     DIO_PortB
#define CONTROLPORT DIO_PortF
#define RS          1
#define RW          2
#define EN          3

#define  CLEAR_DISPLAY            ((unsigned char) 0X01 )
#define  HOME_POSITION            ((unsigned char) 0X02 )
#define  SHIFT_CURSOR_LEFT        ((unsigned char) 0X04 )
#define  SHIFT_CURSOR_RIGHT       ((unsigned char) 0X06 )
#define  SHIFT_DISPLAY_LEFT       ((unsigned char) 0X07 )
#define  SHIFT_DISPLAY_RIGHT      ((unsigned char) 0X05 )
#define  DISPLAY_OFF_CURSOR_OFF   ((unsigned char) 0X08 )
#define  DISPLAY_OFF_CURSOR_ON    ((unsigned char) 0X0A )
#define  DISPLAY_ON_CURSOR_OFF    ((unsigned char) 0X0C )
#define  DISPLAY_ON_CURSOR_ON     ((unsigned char) 0X0E )
#define  DISPLAY_ON_CURSOR_BLINK  ((unsigned char) 0X0F )
#define  FUNC_SET_4BIT_1LINE      ((unsigned char) 0X20 )
#define  FUNC_SET_4BIT_2LINE      ((unsigned char) 0X28 )
#define  FUNC_SET_8BIT_1LINE      ((unsigned char) 0X30 )
#define  FUNC_SET_8BIT_2LINE      ((unsigned char) 0X038)
#define  CURSOR_START_1ST_LINE    ((unsigned char) 0X80 )
#define  CURSOR_START_2ND_LINE    ((unsigned char) 0XC0 )



void LCD_Cmd(char cmd); // command to LCD
void LCD_Clear(void); // clear LCD
void LCD_Init(void); // initalize LCD
void LCD_Char(char data); // send character to LCD
void LCD_String(uint8 *data); // send string to LCD
void LCD_GoToString(uint8 line, uint8 pos, uint8 string[]); // send string at certain place
void LCD_Write_Int(int num); // write int to LCD
void LCD_GoTo(int line, int pos);


#endif 
