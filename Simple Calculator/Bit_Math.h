#ifndef BIT_MATH_
#define BIT_MATH_
////////////////////////////////////////////////////////////////////////////

#define Set_Bit(Reg, Bit) (Reg |= (1<<Bit))
#define Clear_Bit(Reg, Bit) (Reg &=~ (1<<Bit))
#define Toggle_Bit(Reg, Bit) (Reg ^= (1<<Bit))
#define Get_Bit(Reg, Bit) ((Reg >> Bit)&1)



#endif
