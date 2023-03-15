/*
 * Bit_Math.h
 *
 *  Created on: Sep 16, 2022
 *      Author: khale
 */

#ifndef COMMON_BIT_MATH_H_
#define COMMON_BIT_MATH_H_

#define Set_Bit(Reg,Bit)      (Reg|=(1<<Bit))
#define Clear_Bit(Reg,Bit)    (Reg&=~(1<<Bit))
#define Toggle_Bit(Reg,Bit)   (Reg^=(1<<Bit))
#define Get_Bit(Reg,Bit)      ((Reg>>Bit)&0x01)

#define _BV(bit) (1 << (bit))
#define _MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))
#define _SFR_MEM_ADDR(sfr) ((uint16_t) &(sfr))
#define _SFR_ADDR(sfr) _SFR_MEM_ADDR(sfr)
#define _SFR_BYTE(sfr) _MMIO_BYTE(_SFR_ADDR(sfr))

#define bit_is_set(sfr, bit) (_SFR_BYTE(sfr) & _BV(bit))
#define bit_is_clear(sfr, bit) (!(_SFR_BYTE(sfr) & _BV(bit)))


#endif /* COMMON_BIT_MATH_H_ */
