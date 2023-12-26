/*
 * DIO_Private.h
 *
 * Created: 10/18/2023 5:34:28 PM
 *  Author: User
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

extern const DIO_PinStatus_t DIO_PinsStatusArr[TOTAL_PINS];     //CONST to put array in (.rodata) and safe places in (RAM)

static void DIO_InitPin(DIO_Pin_t pin,DIO_PinStatus_t status);     



#endif /* DIO_PRIVATE_H_ */