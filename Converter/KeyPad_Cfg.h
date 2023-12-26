/*
 * KeyPad_Cfg.h
 *
 * Created: 10/25/2023 12:09:38 PM
 *  Author: User
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define FIRST_OUTPUT  PINB4
#define FIRST_INPUT   PIND2


#define ROW  4
#define COL  4


#define  NO_KEY   'T'


#ifdef KEYPAD_PROG
u8  KeyArray[ROW][COL]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'}
};

#endif













#endif /* KEYPAD_CFG_H_ */