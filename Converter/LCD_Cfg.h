


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/*Choose: _8_BIT or _4_BIT */                
#define LCD_MODE   _4_BIT     


#define RS   PINA1
#define EN   PINA2

/*FOR _4_BIT MODE*/
#define D7   PINA6       
#define D6   PINA5
#define D5   PINA4
#define D4   PINA3

/*FOR _8_BIT MODE*/
#define LCD_PORT  PA  








#endif /* LCD_CFG_H_ */