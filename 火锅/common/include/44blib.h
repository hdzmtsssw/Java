/*********************************************************************************************
* File£º	44BLIB.H
* Author:	embest	
* Desc£º	Samsung 44B0X CPU function declare and common define
* History:	
*********************************************************************************************/

#ifndef __44BLIB_H__
#define __44BLIB_H__

#define min(x1,x2) 	((x1<x2)? x1:x2)
#define max(x1,x2) 	((x1>x2)? x1:x2)

#define NULL 0

#define ENTER_PWDN(clkcon) ((void (*)(int))0xe0)(clkcon)

typedef enum {
  HandlerADC,
  HandlerRTC,
  HandlerUTXD1,
  HandlerUTXD0,
  HandlerSIO,
  HandlerIIC,
  HandlerURXD1,
  HandlerURXD0,
  HandlerTIMER5,
  HandlerTIMER4,
  HandlerTIMER3,
  HandlerTIMER2,
  HandlerTIMER1,
  HandlerTIMER0,
  HandlerUERR01,
  HandlerWDT   ,
  HandlerBDMA1 ,
  HandlerBDMA0 ,
  HandlerZDMA1 ,
  HandlerZDMA0 ,
  HandlerTICK  ,
  HandlerEINT4567,
  HandlerEINT3 ,
  HandlerEINT2 ,
  HandlerEINT1 ,
  HandlerEINT0 ,
  HandlerMax
} NON_VECTOR_HANDLER;

/*------------------------------------------------------------------------------------------*/
/*	 								function declare						 				*/
/*------------------------------------------------------------------------------------------*/
void delay(int time); 								// Watchdog Timer is used.
void port_init(void);
void cache_flush(void);
void uart_init(int nMainClk, int nBaud);
void uart_select(int nChannel);
void uart_txempty(int nChannel);
char uart_getch(void);
char uart_getkey(void);
void uart_sendbyte(int nData);
void uart_sendstring(char *pString);
void uart_printf(char *fmt,...);
void timer_start(int nDivider); 					// Watchdog Timer is used.
int  timer_stop(void);          					// Watchdog Timer is used.
void sys_init(void);                     //Interrupt,Port and UART

#endif /* __44BLIB_H__ */
