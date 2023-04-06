
/*************************************************************
 *
 * Filename: NVIC.h
 * Description: Header (interface) file of the NVIC driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/

#ifndef NVIC_H_
#define NVIC_H_


#include "Stdtypes.h"

typedef enum
{
	NVIC_enuOK,
	NVIC_enuNOK,
	NVIC_enuNULLPOINTER
}NVIC_enuErrorStatus;


typedef enum
{
	NVIC_IRQ_0,
	NVIC_IRQ_1,
	NVIC_IRQ_2,
	NVIC_IRQ_3,
	NVIC_IRQ_4,
	NVIC_IRQ_5,
	NVIC_IRQ_6,
	NVIC_IRQ_7,
	NVIC_IRQ_8,
	NVIC_IRQ_10,
	NVIC_IRQ_11,
	NVIC_IRQ_12,
	NVIC_IRQ_13,
	NVIC_IRQ_14,
	NVIC_IRQ_15,
	NVIC_IRQ_16,
	NVIC_IRQ_17,
	NVIC_IRQ_18,
	NVIC_IRQ_19,
	NVIC_IRQ_20,
	NVIC_IRQ_21,
	NVIC_IRQ_22,
	NVIC_IRQ_23,
	NVIC_IRQ_24,
	NVIC_IRQ_25,
	NVIC_IRQ_26,
	NVIC_IRQ_27,
	NVIC_IRQ_28,
	NVIC_IRQ_29,
	NVIC_IRQ_30,
	NVIC_IRQ_31,
	NVIC_IRQ_32,
	NVIC_IRQ_33,
	NVIC_IRQ_34,
	NVIC_IRQ_35,
	NVIC_IRQ_36,
	NVIC_IRQ_37,
	NVIC_IRQ_38,
	NVIC_IRQ_39,
	NVIC_IRQ_40,
	NVIC_IRQ_41,
	NVIC_IRQ_42,
	NVIC_IRQ_43,
	NVIC_IRQ_44,
	NVIC_IRQ_45,
	NVIC_IRQ_46,
	NVIC_IRQ_47,
	NVIC_IRQ_48,
	NVIC_IRQ_49,
	NVIC_IRQ_50,
	NVIC_IRQ_51,
	NVIC_IRQ_52,
	NVIC_IRQ_53,
	NVIC_IRQ_54,
	NVIC_IRQ_55,
	NVIC_IRQ_56,
	NVIC_IRQ_57,
	NVIC_IRQ_58,
	NVIC_IRQ_59,
	NVIC_IRQ_60,
	NVIC_IRQ_61,
	NVIC_IRQ_62,
	NVIC_IRQ_63,
	NVIC_IRQ_64,
	NVIC_IRQ_65,
	NVIC_IRQ_66,
	NVIC_IRQ_67,
	NVIC_IRQ_68,
	NVIC_IRQ_69,
	NVIC_IRQ_70,
	NVIC_IRQ_71,
	NVIC_IRQ_72,
	NVIC_IRQ_73,
	NVIC_IRQ_74,
	NVIC_IRQ_75,
	NVIC_IRQ_76,
	NVIC_IRQ_77,
	NVIC_IRQ_78,
	NVIC_IRQ_79,
	NVIC_IRQ_80,
	NVIC_IRQ_81,
	NVIC_IRQ_82,
	NVIC_IRQ_83,
	NVIC_IRQ_84,
	NVIC_IRQ_85,
	NVIC_IRQ_86,
	NVIC_IRQ_87,
	NVIC_IRQ_88,
	NVIC_IRQ_89,
	NVIC_IRQ_90,
	NVIC_IRQ_91,
	NVIC_IRQ_92,
	NVIC_IRQ_93,
	NVIC_IRQ_94,
	NVIC_IRQ_95,
	NVIC_IRQ_96,
	NVIC_IRQ_97,
	NVIC_IRQ_98,
	NVIC_IRQ_99,
	NVIC_IRQ_100,
	NVIC_IRQ_101,
	NVIC_IRQ_102,
	NVIC_IRQ_103,
	NVIC_IRQ_104,
	NVIC_IRQ_105,
	NVIC_IRQ_106,
	NVIC_IRQ_107,
	NVIC_IRQ_108,
	NVIC_IRQ_109,
	NVIC_IRQ_110,
	NVIC_IRQ_111,
	NVIC_IRQ_112,
	NVIC_IRQ_113,
	NVIC_IRQ_114,
	NVIC_IRQ_115,
	NVIC_IRQ_116,
	NVIC_IRQ_117,
	NVIC_IRQ_118,
	NVIC_IRQ_119,
	NVIC_IRQ_120,
	NVIC_IRQ_121,
	NVIC_IRQ_122,
	NVIC_IRQ_123,
	NVIC_IRQ_124,
	NVIC_IRQ_125,
	NVIC_IRQ_126,
	NVIC_IRQ_127,
	NVIC_IRQ_128,
	NVIC_IRQ_129,
	NVIC_IRQ_130,
	NVIC_IRQ_131,
	NVIC_IRQ_132,
	NVIC_IRQ_133,
	NVIC_IRQ_134,
	NVIC_IRQ_135,
	NVIC_IRQ_136,
	NVIC_IRQ_137,
	NVIC_IRQ_138,
	NVIC_IRQ_139,
	NVIC_IRQ_140,
	NVIC_IRQ_141,
	NVIC_IRQ_142,
	NVIC_IRQ_143,
	NVIC_IRQ_144,
	NVIC_IRQ_145,
	NVIC_IRQ_146,
	NVIC_IRQ_147,
	NVIC_IRQ_148,
	NVIC_IRQ_149,
	NVIC_IRQ_150,
	NVIC_IRQ_151,
	NVIC_IRQ_152,
	NVIC_IRQ_153,
	NVIC_IRQ_154,
	NVIC_IRQ_155,
	NVIC_IRQ_156,
	NVIC_IRQ_157,
	NVIC_IRQ_158,
	NVIC_IRQ_159,
	NVIC_IRQ_160,
	NVIC_IRQ_161,
	NVIC_IRQ_162,
	NVIC_IRQ_163,
	NVIC_IRQ_164,
	NVIC_IRQ_165,
	NVIC_IRQ_166,
	NVIC_IRQ_167,
	NVIC_IRQ_168,
	NVIC_IRQ_169,
	NVIC_IRQ_170,
	NVIC_IRQ_171,
	NVIC_IRQ_172,
	NVIC_IRQ_173,
	NVIC_IRQ_174,
	NVIC_IRQ_175,
	NVIC_IRQ_176,
	NVIC_IRQ_177,
	NVIC_IRQ_178,
	NVIC_IRQ_179,
	NVIC_IRQ_180,
	NVIC_IRQ_181,
	NVIC_IRQ_182,
	NVIC_IRQ_183,
	NVIC_IRQ_184,
	NVIC_IRQ_185,
	NVIC_IRQ_186,
	NVIC_IRQ_187,
	NVIC_IRQ_188,
	NVIC_IRQ_189,
	NVIC_IRQ_190,
	NVIC_IRQ_191,
	NVIC_IRQ_192,
	NVIC_IRQ_193,
	NVIC_IRQ_194,
	NVIC_IRQ_195,
	NVIC_IRQ_196,
	NVIC_IRQ_197,
	NVIC_IRQ_198,
	NVIC_IRQ_199,
	NVIC_IRQ_200,
	NVIC_IRQ_201,
	NVIC_IRQ_202,
	NVIC_IRQ_203,
	NVIC_IRQ_204,
	NVIC_IRQ_205,
	NVIC_IRQ_206,
	NVIC_IRQ_207,
	NVIC_IRQ_208,
	NVIC_IRQ_209,
	NVIC_IRQ_210,
	NVIC_IRQ_211,
	NVIC_IRQ_212,
	NVIC_IRQ_213,
	NVIC_IRQ_214,
	NVIC_IRQ_215,
	NVIC_IRQ_216,
	NVIC_IRQ_217,
	NVIC_IRQ_218,
	NVIC_IRQ_219,
	NVIC_IRQ_220,
	NVIC_IRQ_221,
	NVIC_IRQ_222,
	NVIC_IRQ_223,
	NVIC_IRQ_224,
	NVIC_IRQ_225,
	NVIC_IRQ_226,
	NVIC_IRQ_227,
	NVIC_IRQ_228,
	NVIC_IRQ_229,
	NVIC_IRQ_230,
	NVIC_IRQ_231,
	NVIC_IRQ_232,
	NVIC_IRQ_233,
	NVIC_IRQ_234,
	NVIC_IRQ_235,
	NVIC_IRQ_236,
	NVIC_IRQ_237,
	NVIC_IRQ_238,
	NVIC_IRQ_239
}IRQn_type;






typedef struct
{
	u32 NVIC_ISER[8];

// ISER ADDRESS 	- ICER ADDRESS     SPACE TO NEXT ADDRESS   , Divide by 4 as the space between each struct element
		//  (0x180) - (0x11C)		 = (0x64) -----> Decimal = (100) ----> Decimal = 100/4 = 25 to reach to 11C

	u32 RESERVED_1[24];


	u32 NVIC_ICER[8];

	u32 RESERVED_2[24];

	u32 NVIC_ISPR[8];

	u32 RESERVED_3[24];

	u32 NVIC_ICPR[8];

	u32 RESERVED_4[24];

	u32 volatile NVIC_IABR[8];

	u32 RESERVED_5[56];

	u32 NVIC_IPR[60];

//	u32 NVIC_STIR[];
}NVIC_REG_t;


#define NVIC ((NVIC_REG_t*)0xE000E100)


/************************************************************************/
/*
	Name:					NVIC_enuEnableIRQ

	Input: 			of Type Enum and its one of the Interrupt Requests that can Interrupt

	Return: 				Error Status

	Output:				Enables the Interrupt
*/
/************************************************************************/
NVIC_enuErrorStatus NVIC_enuEnableIRQ(IRQn_type IRQn);



/************************************************************************/
/*
	Name:					NVIC_enuDisableIRQ

	Input: 			of Type Enum and its one of the Interrupt Requests that can Interrupt

	Return: 				Error Status

	Output:				Disables the Interrupt
*/
/************************************************************************/

NVIC_enuErrorStatus NVIC_enuDisableIRQ(IRQn_type IRQn);
NVIC_enuErrorStatus NVIC_enuSetPendingIRQ(IRQn_type IRQn);
NVIC_enuErrorStatus NVIC_enuClearPendingIRQ(IRQn_type IRQn);
NVIC_enuErrorStatus NVIC_enuGetPendingIRQ(IRQn_type IRQn);
NVIC_enuErrorStatus NVIC_enuGetActive(IRQn_type IRQn,u32 *Cpy_u32GetActiveIRQ);
NVIC_enuErrorStatus NVIC_enuSetPriority(IRQn_type IRQn,u32 Priority);
NVIC_enuErrorStatus NVIC_enuGetPriority(IRQn_type IRQn);
NVIC_enuErrorStatus NVIC_enuResetSystem();


#endif
