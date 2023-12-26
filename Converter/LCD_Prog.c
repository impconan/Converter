#include "StdTypes.h"
#include "Utils.h"
#include "string.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "LCD_Cfg.h"
#include "LCD_Private.h"

#define F_CPU  8000000
#include <util/delay.h>


#if LCD_MODE==_8_BIT


static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	
	WriteIns(0X38);
	WriteIns(0X0C); // 0X0E 0X0F Cursor
	WriteIns(0X01); // Clear LCD
	_delay_ms(1);
	WriteIns(0x06);  //DDRAM increment
}

 void WriteData(u8 data)
{
	_delay_ms(50);
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

/************************************************* 4 BIT MODE*************************************************/
#elif LCD_MODE==_4_BIT
static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,GET_BIT(ins,7));
	DIO_WritePin(D6,GET_BIT(ins,6));
	DIO_WritePin(D5,GET_BIT(ins,5));
	DIO_WritePin(D4,GET_BIT(ins,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,GET_BIT(ins,3));
	DIO_WritePin(D6,GET_BIT(ins,2));
	DIO_WritePin(D5,GET_BIT(ins,1));
	DIO_WritePin(D4,GET_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0X02);
	WriteIns(0X28);
	WriteIns(0X0C); // 0X0E 0X0F Cursor
	WriteIns(0X01); // Clear LCD
	_delay_ms(1);
	WriteIns(0x06);  //DDRAM increment
}

 void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,GET_BIT(data,7));
	DIO_WritePin(D6,GET_BIT(data,6));
	DIO_WritePin(D5,GET_BIT(data,5));
	DIO_WritePin(D4,GET_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,GET_BIT(data,3));
	DIO_WritePin(D6,GET_BIT(data,2));
	DIO_WritePin(D5,GET_BIT(data,1));
	DIO_WritePin(D4,GET_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
#endif
/************************************************* 4 BIT MODE*************************************************/
void LCD_WriteChar(c8 ch)
{
	
	WriteData(ch);
}

void LCD_WriteString(c8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		WriteData(str[i]);
	}
}
void LCD_WriteNumber(s32 num)
{
	/*First Solution*/
// 	c8 str[32];
// 	string_IntToString(num,str);  
// 	LCD_WriteString(str);
  /*Second Solution*/
u8 str[16],i=0;
s8 j;
if (num==0)
{
	LCD_WriteChar('0');
	return;
}
if (num<0)
{
	LCD_WriteChar('-');
	num=num*-1;
}
while(num)
{
	str[i]=num%10+'0';
	num=num/10;
	i++;
}

for (j=i-1;j>=0;j--)
{
	LCD_WriteChar(str[j]);
}



}
void LCD_WriteNumber_4D(u16 num)
{
	
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');

}

void LCD_WriteBinary(u8 num)
{
	s8 i;
	//c8 str[32];
	for(i=7;i>=0;i--)
	{
		LCD_WriteChar((GET_BIT(num,i))+'0');
	}
// 	str[8]=0;
// 	//string_reverse(str);
// 	LCD_WriteString(str);
}
void LCD_WriteHex2(u8 num)   //0X45
{
	u8 HN=num>>4;
	u8 LN=num&0x0F;
	
	if (HN<10)
	{
		LCD_WriteChar(HN+'0');
	}
	else
	{
		LCD_WriteChar((HN-10)+'A');
	}
	
	if (LN<10)
	{
		LCD_WriteChar(LN+'0');
	}
	else
	{
		LCD_WriteChar((LN-10)+'A');
	}
	
	
}
void LCD_WriteHex(u8 num)
{
	u8 rem,i;
	c8 str[32];
	for (i=0;num>0;i++)
	{
		rem=num%16;
		if (rem>9)
		{
			str[i]=(rem-10)+'A';
		}
		else
		{
			str[i]=rem+'0';
		}
		
		num=num/16;
	}
	string_reverse(str);
	LCD_WriteString(str);
}
void LCD_Clear(void)
{
	WriteIns(0X01); // Clear LCD
	_delay_ms(1);
}



/*Line 1:2
  Cell 1:16*/
void LCD_SetCursor(u8 line,u8 cell)
{
	if (line==1)
	{
		WriteIns(0x80+(cell-1));
	}
	else if (line==2)
	{
		WriteIns(0x80+0x40+(cell-1));
	}
		
}

void LCD_CreateChar(c8*str,u8 Address)
{
	WriteIns(0x40+Address*8);
	for(u8 i=0;i<8;i++)
	{
		WriteData(str[i]);
	}
	/*LCD_WriteString(str);*/
	WriteIns(0X80);
}

void LCD_SnakeWord(c8*str)
{
	u8 l=string_len(str),i;
	
	for (i=1;i<l;i++)
	{
		LCD_WriteString(str+l-i);
		_delay_ms(400);
		LCD_Clear();
	}
	for (i=2;i<17;i++)
	{
		LCD_SetCursor(1,i);
		LCD_WriteString(str);
		_delay_ms(400);
		LCD_Clear();
	}
	
	for (i=1;i<l;i++)
	{
		LCD_SetCursor(2,1);
		LCD_WriteString(str+l-i);
		_delay_ms(400);
		LCD_Clear();
	}
	for (i=2;i<17;i++)
	{
		
		LCD_SetCursor(2,i);
		LCD_WriteString(str);
		_delay_ms(400);
		LCD_Clear();
	}
	 
}
void LCD_WriteStringCursor(u8 line,u8 cell,u8*str)
{
	LCD_SetCursor(line,cell);
	LCD_WriteString(str);
}
void LCD_ClearCursor(u8 line,u8 cell,u8 No_Cells)
{
	u8 i;
	LCD_SetCursor(line,cell);
	for(i=0;i<No_Cells;i++)
	{
		LCD_WriteString(" ");
	}
	
}