#include "DIO.h"
#include "types.h"
#include "DIO_Types.h"
///////////////////////////////////////////////////////////////
const DIO_PinCFG pinCFG[]={
                           //portA
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           //portB
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           //portC
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           //portD
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           //portE
                           {Input,HIGH},
                           {Input,HIGH},
                           {Input,HIGH},
                           {Input,HIGH},
                           {Input,HIGH},
                           {Input,HIGH},
                           {Input,HIGH},
                           {Input,HIGH},
                           //portF
                           {Input,HIGH},//
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH},
                           {Input,HIGH},//
                           {Output,HIGH},
                           {Output,HIGH},
                           {Output,HIGH}
};
//////////////////////////////////////////////////////////////
void DIO_Init(void){
    uint32 channelpos;
    uint32 portx;
    uint8 count = 0;
    for(count = DIO_ChannelA0; count<PinCount ;count++){
        channelpos = (count % 8);
        portx = (count/8);
        Set_Bit(SYSCTL_RCGCGPIO_R,portx);
        while((Get_Bit(SYSCTL_PRGPIO_R,portx)) == 0x00);

        switch(portx){
        case DIO_PortA:
            GPIO_PORTA_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                Set_Bit(GPIO_PORTA_CR_R, channelpos);
                Set_Bit(GPIO_PORTA_DIR_R, channelpos);
                Set_Bit(GPIO_PORTA_DEN_R, channelpos);
            }else{
                Set_Bit(GPIO_PORTA_CR_R, channelpos);
                Clear_Bit(GPIO_PORTA_DIR_R, channelpos);
                Set_Bit(GPIO_PORTA_DEN_R, channelpos);
                Set_Bit(PORTA_INPUT_PULL_RESIST, channelpos);
            }
            break;

        case DIO_PortB:
            GPIO_PORTB_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                Set_Bit(GPIO_PORTB_CR_R, channelpos);
                Set_Bit(GPIO_PORTB_DIR_R, channelpos);
                Set_Bit(GPIO_PORTB_DEN_R, channelpos);
            }else{
                Set_Bit(GPIO_PORTB_CR_R, channelpos);
                Clear_Bit(GPIO_PORTB_DIR_R, channelpos);
                Set_Bit(GPIO_PORTB_DEN_R, channelpos);
                Set_Bit(PORTB_INPUT_PULL_RESIST, channelpos);
            }
            break;

        case DIO_PortC:
            GPIO_PORTC_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                Set_Bit(GPIO_PORTC_CR_R, channelpos);
                Set_Bit(GPIO_PORTC_DIR_R, channelpos);
                Set_Bit(GPIO_PORTC_DEN_R, channelpos);
            }else{
                Set_Bit(GPIO_PORTC_CR_R, channelpos);
                Clear_Bit(GPIO_PORTC_DIR_R, channelpos);
                Set_Bit(GPIO_PORTC_DEN_R, channelpos);
                Set_Bit(PORTC_INPUT_PULL_RESIST, channelpos);
            }
            break;

        case DIO_PortD:
            GPIO_PORTD_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                Set_Bit(GPIO_PORTD_CR_R, channelpos);
                Set_Bit(GPIO_PORTD_DIR_R, channelpos);
                Set_Bit(GPIO_PORTD_DEN_R, channelpos);
            }else{
                Set_Bit(GPIO_PORTD_CR_R, channelpos);
                Clear_Bit(GPIO_PORTD_DIR_R, channelpos);
                Set_Bit(GPIO_PORTD_DEN_R, channelpos);
                Set_Bit(PORTD_INPUT_PULL_RESIST, channelpos);
            }
            break;

        case DIO_PortE:
            GPIO_PORTE_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                Set_Bit(GPIO_PORTE_CR_R, channelpos);
                Set_Bit(GPIO_PORTE_DIR_R, channelpos);
                Set_Bit(GPIO_PORTE_DEN_R, channelpos);
            }else{
                Set_Bit(GPIO_PORTE_CR_R, channelpos);
                Clear_Bit(GPIO_PORTE_DIR_R, channelpos);
                Set_Bit(GPIO_PORTE_DEN_R, channelpos);
                Set_Bit(PORTE_INPUT_PULL_RESIST, channelpos);
            }
            break;

        case DIO_PortF:
            GPIO_PORTF_LOCK_R = 0x4C4F434B;
            if(pinCFG[count].PinDir == Output){
                Set_Bit(GPIO_PORTF_CR_R, channelpos);
                Set_Bit(GPIO_PORTF_DIR_R, channelpos);
                Set_Bit(GPIO_PORTF_DEN_R, channelpos);
            }else{
                Set_Bit(GPIO_PORTF_CR_R, channelpos);
                Clear_Bit(GPIO_PORTF_DIR_R, channelpos);
                Set_Bit(GPIO_PORTF_DEN_R, channelpos);
                Set_Bit(PORTF_INPUT_PULL_RESIST, channelpos);
            }

            break;
        }
    }
}
/////////////////////////////////////////////////////////////

void DIO_WritePort(DIO_PortTypes portx , uint32 data){
    switch(portx){
    case DIO_PortA:
        GPIO_PORTA_DATA_R = data;
        break;
    case DIO_PortB:
        GPIO_PORTB_DATA_R = data;
        break;
    case DIO_PortC:
        GPIO_PORTC_DATA_R = data;
        break;
    case DIO_PortD:
        GPIO_PORTD_DATA_R = data;
        break;
    case DIO_PortE:
        GPIO_PORTE_DATA_R = data;
        break;
    case DIO_PortF:
        GPIO_PORTF_DATA_R = data;
        break;
    }
}
void DIO_WritePin(DIO_PortTypes portx, uint8 binNumber, STD_Level level){
    switch(portx){
    case DIO_PortA:
        if(level == HIGH){
            Set_Bit(GPIO_PORTA_DATA_R, binNumber);
        }
        else{
            Clear_Bit(GPIO_PORTA_DATA_R, binNumber);
        }
        break;
    case DIO_PortB:
        if(level == HIGH){
            Set_Bit(GPIO_PORTB_DATA_R, binNumber);
        }
        else{
            Clear_Bit(GPIO_PORTB_DATA_R, binNumber);
        }
        break;
    case DIO_PortC:
        if(level == HIGH){
            Set_Bit(GPIO_PORTC_DATA_R, binNumber);
        }
        else{
            Clear_Bit(GPIO_PORTC_DATA_R, binNumber);
        }
        break;
    case DIO_PortD:
        if(level == HIGH){
            Set_Bit(GPIO_PORTD_DATA_R, binNumber);
        }
        else{
            Clear_Bit(GPIO_PORTD_DATA_R, binNumber);
        }
        break;
    case DIO_PortE:
        if(level == HIGH){
            Set_Bit(GPIO_PORTE_DATA_R, binNumber);
        }
        else{
            Clear_Bit(GPIO_PORTE_DATA_R, binNumber);
        }
        break;
    case DIO_PortF:
        if(level == HIGH){
            Set_Bit(GPIO_PORTF_DATA_R, binNumber);
        }
        else{
            Clear_Bit(GPIO_PORTF_DATA_R, binNumber);
        }
        break;
    }
}

uint8 DIO_ReadPin(DIO_PortTypes portx, uint8 binNumber){
    uint8 value = 0;
    switch(portx){
    case DIO_PortA:
        value = Get_Bit(GPIO_PORTA_DATA_R, binNumber);
        break;
    case DIO_PortB:
        value = Get_Bit(GPIO_PORTB_DATA_R, binNumber);
        break;
    case DIO_PortC:
        value = Get_Bit(GPIO_PORTC_DATA_R, binNumber);
        break;
    case DIO_PortD:
        value = Get_Bit(GPIO_PORTD_DATA_R, binNumber);
        break;
    case DIO_PortE:
        value = Get_Bit(GPIO_PORTE_DATA_R, binNumber);
        break;
    case DIO_PortF:
        value = Get_Bit(GPIO_PORTF_DATA_R, binNumber);
        break;
    }
    return value;
}

uint8 DIO_ReadPort(DIO_PortTypes portx){
    uint8 data = 0;
    switch(portx){
    case DIO_PortA:
        data = GPIO_PORTA_DATA_R;
        break;
    case DIO_PortB:
        data = GPIO_PORTB_DATA_R;
        break;
    case DIO_PortC:
        data = GPIO_PORTC_DATA_R;
        break;
    case DIO_PortD:
        data = GPIO_PORTD_DATA_R;
        break;
    case DIO_PortE:
        data = GPIO_PORTE_DATA_R;
        break;
    case DIO_PortF:
        data = GPIO_PORTF_DATA_R;
        break;
    }
    return data;
}


void DIO_WritePinBitBanding(DIO_PortTypes portx, uint8 binNumber, STD_Level level){
    switch(portx){
    case DIO_PortA:
        GPIO_PORTA_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    case DIO_PortB:
        GPIO_PORTB_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    case DIO_PortC:
        GPIO_PORTC_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    case DIO_PortD:
        GPIO_PORTD_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    case DIO_PortE:
        GPIO_PORTE_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    case DIO_PortF:
        GPIO_PORTF_DATA_BITS_R[1<<binNumber] = (level<<binNumber);
        break;
    }
}

uint8 DIO_ReadPinBitBanding(DIO_PortTypes portx, uint8 binNumber){
    uint8 data = 0;
    switch(portx){
    case DIO_PortA:
        data = Get_Bit(GPIO_PORTA_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    case DIO_PortB:
        data = Get_Bit(GPIO_PORTB_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    case DIO_PortC:
        data = Get_Bit(GPIO_PORTC_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    case DIO_PortD:
        data = Get_Bit(GPIO_PORTD_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    case DIO_PortE:
        data = Get_Bit(GPIO_PORTE_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    case DIO_PortF:
        data = Get_Bit(GPIO_PORTF_DATA_BITS_R[1<<binNumber], binNumber);
        break;
    }
    return data;
}

void DIO_ChangePinDir(DIO_PortTypes portx, uint8 binNumber, DIO_DIR dir){
    switch(portx){
    case DIO_PortA:
        if(dir == Input){
            Clear_Bit(GPIO_PORTA_DIR_R, binNumber);
        }else{
            Set_Bit(GPIO_PORTA_DIR_R, binNumber);
        }
        break;
    case DIO_PortB:
        if(dir == Input){
            Clear_Bit(GPIO_PORTB_DIR_R, binNumber);
        }else{
            Set_Bit(GPIO_PORTB_DIR_R, binNumber);
        }
        break;
    case DIO_PortC:
        if(dir == Input){
            Clear_Bit(GPIO_PORTC_DIR_R, binNumber);
        }else{
            Set_Bit(GPIO_PORTC_DIR_R, binNumber);
        }
        break;
    case DIO_PortD:
        if(dir == Input){
            Clear_Bit(GPIO_PORTD_DIR_R, binNumber);
        }else{
            Set_Bit(GPIO_PORTD_DIR_R, binNumber);
        }
        break;
    case DIO_PortE:
        if(dir == Input){
            Clear_Bit(GPIO_PORTE_DIR_R, binNumber);
        }else{
            Set_Bit(GPIO_PORTE_DIR_R, binNumber);
        }
        break;
    case DIO_PortF:
        if(dir == Input){
            Clear_Bit(GPIO_PORTF_DIR_R, binNumber);
        }else{
            Set_Bit(GPIO_PORTF_DIR_R, binNumber);
        }
        break;
    }
}









