/*
 * LCD_Int.h
 *
 * Created: 10/22/2023 9:14:34 PM
 *  Author: User
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_


//extern const u8 customChar[][8];

void LCD_Init(void);

void LCD_WriteChar(c8 ch);
void LCD_WriteString(c8*str);

void LCD_WriteNumber(s32 num);
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);

void LCD_Clear(void);     
void LCD_SnakeWord(c8*str);            

                 /*line 1,2-cell 1:16*/					   
void LCD_SetCursor(u8 line,u8 cell);


void LCD_WriteNumber_4D(u16 num);
void LCD_CreateChar(c8*str,u8 Address);

void LCD_WriteStringCursor(u8 line,u8 cell,u8*str);
void LCD_ClearCursor(u8 line,u8 cell,u8 No_Cells);



#endif /* LCD_INT_H_ */