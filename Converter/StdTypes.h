typedef unsigned char   u8;
typedef signed char     s8;
typedef    char         c8;

typedef unsigned int    u16;
typedef signed int      s16;

typedef unsigned long   u32;
typedef signed long     s32;

typedef enum{
	FALSE=0X55,  //0b01010101
	TRUE=0XAA   //0b10101010
	}bool_t;

#define  NULLPTR     ((void*)0)

typedef enum{
	OK,                   //Make OK=0 because any error except (OK) doesn't equal 0
	NOK,
	NULL_PTR,
	OUT_OF_RANG,          // IF YOU PASS an element out of array
	BUSY
	}error_t;