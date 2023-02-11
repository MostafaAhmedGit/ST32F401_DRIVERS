/*
 * Bitmath.h
 *
 *  Created on: Dec 7, 2022
 *      Author: JUMBO
 */

#ifndef BITMATH_H_
#define BITMATH_H_

#define SET_BIT(REG,Bit)					(REG)|=(1<<Bit)

#define CLR_BIT(REG,Bit)					(REG)&=~(1<<Bit)

#define TGL_BIT(REG,Bit)					(REG)^=(1<<Bit)

#define GET_BIT(REG,Bit)					((REG)&(1<<Bit))!=0

#define SET_HIG_NIB(REG)					(REG)|=0xF0

#define SET_LOW_NIB(REG)					(REG)|=0x0F

#define CLR_HIG_NIB(REG)					(REG)&=0xFF

//#define GET_HIG_NIB(REG)					(REG)<<4 & 0xF0

#define CLR_REG(REG)							(REG)&=0

#define ASSIGN_REG(REG,Value)					(REG) = (REG&0) | (Value)

#define GET_HIG_NIB(REG)					(REG)&(0xF0)

#define GET_LOW_NIB(REG)					(REG)&(0x0F)
	
#define SHIFT_RIGHT(REG,Value)					(REG)>>(Value)

#define SHIFT_LEFT(REG,Value)					(REG)<<(Value)

#define CIR_SHIFT_RIGHT(REG,Value)  				(REG) = ((REG<<Value)|(REG>>(sizeof(REG)-Value)))

#define CIR_SHIFT_LEFT(REG,Bit)					(REG) = ((REG>>Value)|(REG<<(sizeof(REG)-Value)))





#endif /* BITMATH_H_ */
