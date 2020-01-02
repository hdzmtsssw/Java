/*********************************************************************************************
* File£º	8led.c
* Author:	embest	
* Desc£º	8-segment digit LED control functions
* History:	
*********************************************************************************************/
#include "44b.h"
#include "44blib.h"
#include "def.h"
#include "iic.h"

/*------------------------------------------------------------------------------------------*/
/*	 								global variables					 				    */
/*------------------------------------------------------------------------------------------*/
int f_nKeyPress;
extern unsigned char 	f_szDigital[];

/*------------------------------------------------------------------------------------------*/
/*	 								function declare						 				    */
/*------------------------------------------------------------------------------------------*/
int keyboard_test(void);
void __irq keyboard_int(void);
UINT8T key_set(UINT8T ucChar);
char get_keyboard_char(int nHandleInt);

/*********************************************************************************************
* name:		keyboard_test
* func:		test 8led
* para:		none
* ret:		none
* modify:
* comment:		
********************************************************************************************/
int keyboard_test(void)
{
	int i, nTmp,end;
	UINT8T ucChar;
	
	iic_init();
	
	// initiaze the 8led-function first of ZLG7290 (more to see ZLG7290.pdf)
	// precent the invalid sign generated while keyboard-function
	for(i=0; i<8; i++)
		iic_write(0x70, 0x10+i, 0xFF); 
		
	iic_write(0x70, 0x10+3, f_szDigital[6]); // display 6 only

	// set EINT2 interrupt handler
    pISR_EINT2 = (int)keyboard_int;

	i = 8;
	uart_printf("\n");
	for(;;)
	{
	    f_nKeyPress = 0;
		rINTMSK = rINTMSK & (~(BIT_GLOBAL|BIT_EINT2));		// enable EINT2 int
		while(f_nKeyPress == 0);
		iic_read(0x70, 0x1, &ucChar);
		ucChar = key_set(ucChar);			// key map for EduKitII

		nTmp = f_szDigital[ucChar];
		switch(ucChar)
		{
		case '*': nTmp = 0x90;		break;
		case '+': nTmp = 0x92;		break;
		case '-': nTmp = 0x02;		break;
		default:
			break;
		}
		delay(5);
		led8_disp(i,i,nTmp);
		iic_init();
		if(i-- == 5) i = 8;
		
		if(ucChar < 10) ucChar += 0x30;
		else if(ucChar < 16) ucChar += 0x37;
		
		if(ucChar < 255){
		uart_printf(" press key %c\n\r",ucChar);
			end=(int)ucChar-48;
			return end;
		}	
			
				
		if(ucChar == 0xFF)
		{
			uart_printf(" press key FUN (exit now)\n\r");
			return 0;
		}
	}
    
}

/*********************************************************************************************
* name:		get_keyboard_char
* func:		
* para:		Keyboard interrupt handler (name)
* ret:		a key: press a valid key 
* 			0    : no key press
* modify:
* comment:		
*********************************************************************************************/
char get_keyboard_char(int nHandleInt)
{
	UINT8T	ucChar;

    pISR_EINT2 = (int)nHandleInt;
	
	iic_init();
	rI_ISPC = BIT_EINT2;
	rINTMSK &=  ~(BIT_GLOBAL|BIT_EINT2);		// enable EINT2 int
	while(f_nKeyPress == 0);
	//if(f_nKeyPress)
	{
		f_nKeyPress = 0;
		iic_read(0x70, 0x1, &ucChar);
		return(key_set(ucChar));					// key map for EduKitII
	}
	//else return 0;
}

/*********************************************************************************************
* name:		key_set
* func:		keyboard setting
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
UINT8T key_set(UINT8T ucChar)
{
	switch(ucChar)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
				ucChar-=1; break;
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
				ucChar-=4; break;
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
				ucChar-=7; break;
		case 25: ucChar = 0xF; break;
		case 26: ucChar = '+'; break;
		case 27: ucChar = '-'; break;
		case 28: ucChar = '*'; break;
		case 29: ucChar = 0xFF; break;
		default: ucChar = 0xFE;
	}
	return ucChar;
}

/*********************************************************************************************
* name:		keyboard_int
* func:		keyboard interrupt handler
* para:		none
* ret:		none
* modify:
* comment:		
********************************************************************************************/
void __irq keyboard_int(void)
{
	
    rI_ISPC = BIT_EINT2;
    f_nKeyPress = 1;
}
