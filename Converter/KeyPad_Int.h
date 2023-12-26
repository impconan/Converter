/*
 * KeyPad_Int.h
 *
 * Created: 10/25/2023 12:09:10 PM
 *  Author: User
 */ 


#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#include "StdTypes.h"
#include "DIO_Int.h"
#include "KeyPad_Cfg.h"

void KEYPAD_Init(void);

u8 KEYPAD_GetKey(void);



#endif /* KEYPAD_INT_H_ */