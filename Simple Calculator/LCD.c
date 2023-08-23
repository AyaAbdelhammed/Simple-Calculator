#include "LCD.h"


void LCD_Cmd(char cmd){
#if MYMODE == MODE8BIT
    DIO_WritePort(LCDPort, cmd);
    DIO_WritePin(CONTROLPORT, RS, LOW);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_us(40);
    DIO_WritePin(CONTROLPORT, EN, LOW);
#elif MYMODE == MODE4BIT
    DIO_WritePort(LCDPort, (DIO_ReadPort(LCDPort) & 0x0F) | (cmd & 0xF0));
    DIO_WritePin(CONTROLPORT, RS, LOW);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_us(40);
    DIO_WritePin(CONTROLPORT, EN, LOW);
    DIO_WritePort(LCDPort, (DIO_ReadPort(LCDPort) & 0x0F) | (cmd << 4));
    DIO_WritePin(CONTROLPORT, RS, LOW);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_us(40);
    DIO_WritePin(CONTROLPORT, EN, LOW);
#endif
}

void LCD_Clear(void){
    LCD_Cmd(CLEAR_DISPLAY);
}

void LCD_Init(void){
    DIO_Init();


    //    DIO_WritePin(CONTROLPORT, RS, HIGH);
    //    DIO_WritePin(CONTROLPORT, RW, HIGH);
    //    DIO_WritePin(CONTROLPORT, EN, HIGH);

#if MYMODE == MODE8BIT
	delay_ms(40);
	LCD_Cmd(0x38);
	delay_us(50);
	LCD_Cmd(0x0E);
	delay_us(50);
	LCD_Cmd(0x01);
	delay_ms(2);
	LCD_Cmd(0x0F);
	delay_us(4);
	LCD_Cmd(0x02);
#elif MYMODE == MODE4BIT
    LCD_Cmd(0x02);
    LCD_Cmd(FUNC_SET_4BIT_2LINE);
    delay_us(5);
    LCD_Cmd(FUNC_SET_4BIT_2LINE);
    delay_us(100);
    LCD_Cmd(FUNC_SET_4BIT_2LINE);
#endif
}

void LCD_Char(char data){
#if MYMODE == MODE8BIT
    DIO_WritePort(LCDPort, data);
    DIO_WritePin(CONTROLPORT, RS, HIGH);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_ms(10);
    DIO_WritePin(CONTROLPORT, EN, LOW);
    delay_ms(10);
#elif MYMODE == MODE4BIT
    DIO_WritePort(LCDPort, (DIO_ReadPort(LCDPort) & 0x0F) | (data & 0xF0));
    DIO_WritePin(CONTROLPORT, RS, HIGH);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_ms(10);
    DIO_WritePin(CONTROLPORT, EN, LOW);
    DIO_WritePort(LCDPort, (DIO_ReadPort(LCDPort) & 0x0F) | (data << 4));
    DIO_WritePin(CONTROLPORT, RS, HIGH);
    DIO_WritePin(CONTROLPORT, RW, LOW);
    DIO_WritePin(CONTROLPORT, EN, HIGH);
    delay_ms(10);
    DIO_WritePin(CONTROLPORT, EN, LOW);

#endif

}

void LCD_String(uint8* data){
    int i = 0;
    while(data[i] != '\0'){
        LCD_Char(data[i]);
        i++;
        delay_ms(10);
    }
}

void LCD_GoToString(uint8 line, uint8 pos, uint8 string[]){
    delay_ms(20);
    uint8 cmd;
    switch(line){
    case 1:
        cmd = 0x80 | (pos & 0x0F);
        LCD_Cmd(cmd);
        break;
    case 2:
        cmd = 0xC0 | (pos & 0x0F);
        LCD_Cmd(cmd);
        break;
    }
    LCD_String(string);
}

void LCD_Write_Int(int num){
    //LCD_Clear();
    int j;
    char i = 0;
    char str[32];
    while(num != 0){
        str[i] = num % 10;
        num = num/10;
        i++;
    }
    for(j = i-1; j >=0 ; j--)
        LCD_Char('0' + str[j]);
}

void LCD_GoTo(int line, int pos){
    if(line == 1){
        LCD_Cmd(CURSOR_START_1ST_LINE+pos);
    }else if(line == 2){
        LCD_Cmd(CURSOR_START_2ND_LINE+pos);
    }
}
