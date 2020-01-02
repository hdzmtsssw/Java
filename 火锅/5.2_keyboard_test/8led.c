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
/*	 								global variables						 				    */
/*------------------------------------------------------------------------------------------*/
/*
		  __7___
		 |      |
		2|      |6
		 |--1---|
		3|      |5
		 |__4___|.0
		 
	data [7 6 5 4 3 2 1 0]
*/
unsigned char f_szDigital[] ={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6,// 0 ~ 9
                              0xEE,0xFF,0x9C,0xFD,0x9E,0x8E,// A 8. C 0. E F
                              0x1,0x2,0x0,0x92,0x90};// , - close Èý ¶þ

/*------------------------------------------------------------------------------------------*/
/*	 								function declare						 				    */
/*------------------------------------------------------------------------------------------*/
void led8_test(void);
void led8_disp_mem(int nMemory, int nLen, int nDirection);
void led8_disp(char cWhichS,char cWhichE,char uChar);

/*********************************************************************************************
* name:		led8_test
* func:		test 8led
* para:		none
* ret:		none
* modify:
* comment:		
********************************************************************************************/
void led8_test(void)
{
	int i, j, k;
	
	iic_init();
	for(;;)
	{
		for(j=0; j<10; j++)
		{
			for(i=0; i<8; i++)
			{
				k = 9-(i+j)%10;
				iic_write(0x70, 0x10+i, f_szDigital[k]);
			}
			delay(1000);
		}
	}
}

/*********************************************************************************************
* name:		led8_disp
* func:		
* para:		cWhichS		-- input, the start 8-led to display
* 			cWhichE		-- input, the end 8-led to display
* 			uChar		-- input, display to 8-led
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void led8_disp(char cWhichS,char cWhichE,char uChar)
{
	int i;
	
	iic_init();
    for(i=cWhichS-1;i<=cWhichE-1;i++)
		iic_write(0x70, 0x10+i, uChar);
	delay(100);
}

/*********************************************************************************************
* name:		led8_disp_mem
* func:		
* para:		nMemory		-- input, memory start address
* 			nLen		-- input, the number of memory
* 			nDirection	-- input, 0:scroll right to left 1:scroll left to right
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
#define ValidChar(uChar) \
			{\
				uChar = (uChar < '0')|(uChar > 'F') ? '0'+17 : uChar;/* default as - */\
				uChar -= 0x30;\
				if(uChar>='A') uChar -= 7;\
			}
void led8_disp_mem(int nMemory, int nLen, int nDirection)
{
	int i,j; 
	char uChar;
	char* pPtMemory;
	
	pPtMemory = (char* )nMemory;
	
	if(nDirection)
	{
		for(i=nLen-1;i>=0;i--)
		{
			if(i<4)
			{
				uChar = *(pPtMemory+i);
				ValidChar(uChar);
				led8_disp(4-i,4-i,f_szDigital[uChar]);
			}
			else if(i < 8)
			{
				uChar = *(pPtMemory+i);
				ValidChar(uChar);
				led8_disp(12-i,12-i,f_szDigital[uChar]);
			}
			else
			{
				for(j=1;j<=4;j++)
				{
					uChar = *(pPtMemory+i-8+j-nDirection);
					ValidChar(uChar);
					led8_disp(5-j,5-j,f_szDigital[uChar]);
					delay(20);
				}
				delay(200);
				for(j=5;j<=8;j++)
				{
					uChar = *(pPtMemory+i-8+j-nDirection);
					ValidChar(uChar);
					led8_disp(13-j,13-j,f_szDigital[uChar]);
					delay(20);
				}
			}
			delay(20);
		}
		return;
	}
	
	for(i=0;i<nLen;i++)
	{
		if(i<4)
		{
			uChar = *(pPtMemory+i);
			ValidChar(uChar);
			led8_disp(4-i,4-i,f_szDigital[uChar]);
		}
		else if(i < 8)
		{
			uChar = *(pPtMemory+i);
			ValidChar(uChar);
			led8_disp(12-i,12-i,f_szDigital[uChar]);
		}
		else
		{
			for(j=1;j<=4;j++)
			{
				uChar = *(pPtMemory+i-8+j-nDirection);
				ValidChar(uChar);
				led8_disp(5-j,5-j,f_szDigital[uChar]);
				delay(20);
			}
			delay(200);
			for(j=5;j<=8;j++)
			{
				uChar = *(pPtMemory+i-8+j-nDirection);
				ValidChar(uChar);
				led8_disp(13-j,13-j,f_szDigital[uChar]);
				delay(20);
			}
		}
		delay(20);
	}
}
