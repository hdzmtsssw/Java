/*********************************************************************************************
* File£º	uhal.H
* Author:	Embest	
* Desc£º	
* History:	
*********************************************************************************************/
#ifndef __UHAL_H__
#define __UHAL_H__

void uhal_init_interrupts(void);
void BreakPoint(void);
void uart_printf(char *fmt,...);
void uart_getstring(char *pString);
char uart_getkey(void);
char uart_getch(void);
#endif	// __UHAL_H__
