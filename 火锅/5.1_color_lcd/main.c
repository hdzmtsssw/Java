/*********************************************************************************************
* File：	main.c
* Author:	embest
* Desc：	c main entry
* History:	
*********************************************************************************************/
#include "44b.h"
#include "44blib.h"
#include "lcd.h"
#include "bmp.h"

extern const UINT8T g_ucBitmap[][76800];
/*------------------------------------------------------------------------------------------*/
/*	 								extern function						 				    */
/*------------------------------------------------------------------------------------------*/
extern void lcd_test(void);

/*------------------------------------------------------------------------------------------*/
/*	 								function declare						 				    */
/*------------------------------------------------------------------------------------------*/
int main(void);
void lcd_test(void);
/*********************************************************************************************
* name:		main
* func:		c code entry
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
int main(void)
{
    sys_init();        /* Initial 44B0X's Interrupt,Port and UART */

	uart_printf("\n\rEmbest EduKit II Evaluation Board");
	uart_printf("\n\rLCD display Test Example(please look at LCD screen)\n");
	
	lcd_test();
	while(1);
}

/*********************************************************************************************
* name:		lcd_test()
* func:		LCD test function
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void lcd_test(void)
{
	int i,flag;
	
	lcd_init();									// initial LCD controller
	lcd_clr();									// clear screen

#ifdef CHINESE_VERSION
	lcd_disp_hz16(10,10,BLUE,"薛燕和李宁");
#else
	lcd_disp_ascii8x16(10,0,BLUE,"薛燕和李宁");
#endif
	lcd_disp_ascii8x16(10,24,(UINT8T)(GREEN-55),"XUST-Student");

	/* draw rectangle pattern */ 
	
	(*(int *)0x1d20020) |= (1 << 6);
	delay(30000);

	while (1)
	{
		flag=keyboard_test();
		switch(flag){
		
			case 0 : {  //长方形
				lcd_draw_line(50,100,50,200,RED,3);
				lcd_draw_line(250,100,250,200,RED,3);
				lcd_draw_line(50,100,250,100,RED,3);
				lcd_draw_line(50,200,250,200,RED,3);
			};break;
			case 1 : {//三角形
				lcd_draw_line(50,50,50,150,RED,2);
				lcd_draw_line(50,150,150,150,RED,2);
				lcd_draw_line(50,50,150,150,RED,2);
			};break;
			case 2 : {//
				lcd_draw_box(50,50,200,200,GREEN);
				lcd_draw_line(50,50,200,200,RED,1);
				lcd_draw_line(50,200,200,50,RED,1);
			};break;
			case 3 : lcd_clr();break;//清屏
		}
	//	for (i = 0; i < 5; i++)
	//	{
	//		bitmap_view320x240x256((UINT8T*)(g_ucBitmap[i]));
		//	delay(20000);
		//}
	}
}
