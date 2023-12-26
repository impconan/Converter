#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "KeyPad_Int.h"
#include "Convert.h"
#define F_CPU  8000000
#include <util/delay.h>




int main(void)
{
	DIO_Init();
	MOTOR_Init();
	MOVE_Init();
	LCD_Init();
	KEYPAD_Init();
	
	
	
	
	u8 k,k1,num=0,num_total=0,num_test=0,rem1=0,rem2=0,c=0,c2=0,flag2=0,system;
	Choice_t choice=CHOICE_NONE;
	math_operation_t flag=DEFAULT_FLAG;
	Hex_Digit_t hex=HEX_NONE;
	s8 i=0,y=1;
	u8 hexarray[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	
	LCD_SetCursor(1,5);
	LCD_WriteString("Converter");
	LCD_SetCursor(2,1);
	LCD_WriteString("   Eng:ABO BAKR");
	_delay_ms(2000);
	LCD_Clear();
	


	
	     
		
		
LCD_Clear();
LCD_SetCursor(1,3);
LCD_WriteString("Convert From");
LCD_SetCursor(2,1);
LCD_WriteString("1-B   2-D   3-H");		
	
	
 c=0;
    while (1)
	{
		
		k=KEYPAD_GetKey();
		if (k!=NO_KEY)
		{
			if (choice==CHOICE_NONE)
			{
				
				if (k=='1')
				{
					system=1;
				}
				else if (k=='2')
				{
					system=2;
				}
				else if (k=='3')
				{
					system=3;
				}
                
               // system=k;

				choice=CHOICE_1;
				LCD_Clear();
				LCD_SetCursor(1,3);
				LCD_WriteString("Convert To");
				LCD_SetCursor(2,1);
				LCD_WriteString("1-B   2-D   3-H");
				
			}
			else if (choice==CHOICE_1)
			{
				
				if (k=='1')
				{
					flag=B_FLAG;
				}
				else if (k=='2')
				{
					flag=D_FLAG;
				}
				else if (k=='3')
				{
					flag=H_FLAG;
				}
				 if (system==1&&flag==B_FLAG)
				 {
					 LCD_Clear();
					 LCD_SetCursor(1,1);
					 LCD_WriteString("B:");
					 LCD_SetCursor(2,1);
					 LCD_WriteString("B:");
				 }
				 else if (system==1&&flag==D_FLAG)
				 {
					 LCD_Clear();
					 LCD_SetCursor(1,1);
					 LCD_WriteString("B:");
					 LCD_SetCursor(2,1);
					 LCD_WriteString("D:");
				 }
				 else if (system==1&&flag==H_FLAG)
				 {
					 LCD_Clear();
					 LCD_SetCursor(1,1);
					 LCD_WriteString("B:");
					 LCD_SetCursor(2,1);
					 LCD_WriteString("H:");
				 }
				 
				 else if (system==2&&flag==B_FLAG)
				 {
					 LCD_Clear();
					 LCD_SetCursor(1,1);
					 LCD_WriteString("D:");
					 LCD_SetCursor(2,1);
					 LCD_WriteString("B:");
				 }
				 else if (system==2&&flag==D_FLAG)
				 {
					 LCD_Clear();
					 LCD_SetCursor(1,1);
					 LCD_WriteString("D:");
					 LCD_SetCursor(2,1);
					 LCD_WriteString("D:");
				 }
				 else if (system==2&&flag==H_FLAG)
				 {
					 LCD_Clear();
					 LCD_SetCursor(1,1);
					 LCD_WriteString("D:");
					 LCD_SetCursor(2,1);
					 LCD_WriteString("H:");
				 }
				 
				 else if (system==3&&flag==B_FLAG)
				 {
					 LCD_Clear();
					 LCD_SetCursor(1,1);
					 LCD_WriteString("H:");
					 LCD_SetCursor(2,1);
					 LCD_WriteString("B:");
					 LCD_SetCursor(1,3);
					 LCD_WriteString("00");
				 }
				 else if (system==3&&flag==D_FLAG)
				 {
					 LCD_Clear();
					 LCD_SetCursor(1,1);
					 LCD_WriteString("H:");
					 LCD_SetCursor(2,1);
					 LCD_WriteString("D:");
					 LCD_SetCursor(1,3);
					 LCD_WriteString("00");
				 }
				 else if (system==3&&flag==H_FLAG)
				 {
					 LCD_Clear();
					 LCD_SetCursor(1,1);
					 LCD_WriteString("H:");
					 LCD_SetCursor(2,1);
					 LCD_WriteString("H:");
					 LCD_SetCursor(1,3);
					 LCD_WriteString("00");
				 }
				choice=CHOICE_DONE;
			}
		
			
			
			else if (system==1&&choice==CHOICE_DONE&&k>='0'&&k<='1')
			{
				if (flag2==1)
				{
					LCD_ClearCursor(1,3,c2);
					flag2=0;
					c=0;
				}
					LCD_SetCursor(1,c+3);
					LCD_WriteChar(k);
					c++;
				
				num=num*2+k-'0';
				hex=HEX_2;
			}
			else if (system==2&&choice==CHOICE_DONE&&k>='0'&&k<='9')
			{
				if (flag2==1)
				{
					LCD_ClearCursor(1,3,c2);
					flag2=0;
					c=0;
				}
				LCD_SetCursor(1,c+3);
				LCD_WriteChar(k);
				c++;
				num=num*10+k-'0';
				hex=HEX_2;
			}
			
			else if (system==3&&choice==CHOICE_DONE&&hex!=HEX_2&&k!='c')
			{
				if (flag2==1)
				{
					 LCD_SetCursor(1,3);
					 LCD_WriteString("00");
					 flag2=0;
					 c=0;
				}
						if (hex==HEX_NONE)
						{
							LCD_SetCursor(1,4);
							if (k=='+')
							{
								i++;
								if (i>15)
								{
									i=0;
								}
								LCD_WriteChar(hexarray[i]);
							}
							else if (k=='-')
							{
								i--;
								if (i<0)
								{
									i=15;
								}
								LCD_WriteChar(hexarray[i]);
								
							}
							else if (k=='=')
							{
								rem1=i%16;
								i=0;
								hex=HEX_1;
								LCD_SetCursor(1,3);
							}
							
							
							
							
						}
							
						else if (hex==HEX_1)
						{
							LCD_SetCursor(1,3);
							if (k=='+')
							{
								i++;
								if (i>15)
								{
									i=0;
								}
								LCD_WriteChar(hexarray[i]);
							}
							else if (k=='-')
							{
								i--;
								if (i<0)
								{
									i=15;
								}
								LCD_WriteChar(hexarray[i]);
								
							}
							else if (k=='=')
							{
								rem2=(i%16)*16;
								num=rem1+rem2;
								hex=HEX_2;
							}
						}

					
			}	
				
				
			
			else if (k=='='&&choice==CHOICE_DONE&&hex==HEX_2)
			{
				flag2=1;
				num_test=num;
				for (c2=0;num_test>0;c2++)
				{
					num_test=num_test/10;
				}
				LCD_SetCursor(2,3);
				LCD_WriteString("          ");
				LCD_SetCursor(2,3);
				switch(flag)
				{
					case B_FLAG:
					//num_total=num;
					LCD_WriteBinary(num);
					num=0;
					break;
					case D_FLAG:
					//num_total=num;
					LCD_WriteNumber(num);
					num=0;
					break;
					case H_FLAG:
					LCD_SetCursor(2,3);
					LCD_WriteHex2(num);
					num=0x00;
					break;
				}
				hex=HEX_NONE;
				
				
			}
			else if (k=='c')
			{
				LCD_Clear();
				LCD_Clear();
				LCD_SetCursor(1,3);
				LCD_WriteString("Convert From");
				LCD_SetCursor(2,1);
				LCD_WriteString("1-B   2-D   3-H");
				choice=CHOICE_NONE;
				flag=DEFAULT_FLAG;
				hex=HEX_NONE;
			}
			
			
		}
		
		
	}
	
}