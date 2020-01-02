/*********************************************************************************************
* File:		uhal.c
* Author:	embest
* Desc:		
* History:	
*********************************************************************************************/
#include "uhal.h"
#include "44b.h"
#include "44blib.h"

/*------------------------------------------------------------------------------------------*/
/*	 								constant define					 				    	*/
/*------------------------------------------------------------------------------------------*/
#define	OS_TICK		1000							//  1/1000 sec
#define OS_CLOCK	(165*(1000/OS_TICK))

/*------------------------------------------------------------------------------------------*/
/*	 								function declare					 				    */
/*------------------------------------------------------------------------------------------*/
void breakpoint(void);
void debug_undef(void);
void debug_swi(void);
void debug_abort(void);
void debug_fiq(void);

/*********************************************************************************************
* name:		uhal_init_interrupts
* func:		Initialze interrupts.
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uhal_init_interrupts(void)
{
    rINTCON	= 0x1;	  								// Vectored mode, IRQ disable, FIQ disable    
    rINTMOD	= 0x0;	  								// All=IRQ mode
    rINTMSK	= 0x07FFFFFF;	  						// All interrupt is masked.
    rI_ISPC = 0xffffffff;							// Clear all interrupt pend

	// Set interrupt vector routine
//	pISR_RESET				//reserved
	pISR_UNDEF		= (unsigned) debug_undef;
	pISR_SWI		= (unsigned) debug_swi;
	pISR_PABORT		= (unsigned) debug_abort;
	pISR_DABORT		= (unsigned) debug_abort;
	pISR_RESERVED	= (unsigned) breakpoint;		// not used
//	pISR_IRQ		= (unsigned) 0;					// reserved
	pISR_FIQ		= (unsigned) debug_fiq;
	
	pISR_ADC		= (unsigned) breakpoint;
	pISR_RTC		= (unsigned) breakpoint;
	pISR_UTXD1		= (unsigned) breakpoint;
	pISR_UTXD0		= (unsigned) breakpoint;
	pISR_SIO		= (unsigned) breakpoint;
	pISR_IIC		= (unsigned) breakpoint;
	pISR_URXD1		= (unsigned) breakpoint;
	pISR_URXD0		= (unsigned) breakpoint;
	pISR_TIMER5		= (unsigned) breakpoint;
	pISR_TIMER4		= (unsigned) breakpoint;
	pISR_TIMER3		= (unsigned) breakpoint;
	pISR_TIMER2		= (unsigned) breakpoint;
	pISR_TIMER1		= (unsigned) breakpoint;
	pISR_TIMER0		= (unsigned) breakpoint;
	pISR_UERR01		= (unsigned) breakpoint;
	pISR_WDT		= (unsigned) breakpoint;
	pISR_BDMA1		= (unsigned) breakpoint;
	pISR_BDMA0		= (unsigned) breakpoint;
	pISR_ZDMA1		= (unsigned) breakpoint;
	pISR_ZDMA0		= (unsigned) breakpoint;
	pISR_TICK		= (unsigned) breakpoint;
	pISR_EINT4567	= (unsigned) breakpoint;
	pISR_EINT3		= (unsigned) breakpoint;
	pISR_EINT2		= (unsigned) breakpoint;
	pISR_EINT1		= (unsigned) breakpoint;
	pISR_EINT0		= (unsigned) breakpoint;
	pISR_TIMER0		= (unsigned) breakpoint;
}

/*********************************************************************************************
* name:		uhal_register_irq
* func:		
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
#define IRQBASE       _ISR_STARTADDRESS+4*8
#define IRQVECTOR(x)  (IRQBASE + ((unsigned int)x)*4)
void uhal_register_irq(NON_VECTOR_HANDLER IrqSrc, void* pIRQService)
{
  *(unsigned *)(IRQVECTOR(IrqSrc)) = (unsigned)pIRQService;
}

/*********************************************************************************************
* name:		uhal_enable_int
* func:		
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uhal_enable_int(unsigned ISPC_BIT)
{
	rINTMSK &= ~(ISPC_BIT | BIT_GLOBAL);
}

/*********************************************************************************************
* name:		uhal_init_interrupts
* func:		Initialize timer that is used OS.
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uhal_init_timers(void)
{
	rTCFG0 = 0x00000064;  							// dead zone=0, pre0= 100
	rTCFG1 = 0x00000001;  							// all interrupt, mux0= 1/4
	rTCNTB0= OS_CLOCK;     							// set T0 count
    rTCON  = 0x00000002;   							// update T0
    rINTPND= 0x00002000; 							// T0 interrupt clear
	rTCON  = 0x00000009;   							// T0,auto reload and start
}

/*********************************************************************************************
* name:		breakpoint
* func:		exception dealing, beep and light the LEDs
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void breakpoint(void)
{
	rPCONB = 0x1cf;											// PB4:LED1 PB5:LED2
	rPCONF = 0x24914A;										// PF3:LED4 PF4:LED3 PF2:nWait
	rPCONE = 0x25468;										// PE3:BUZZER	

	timer_start(1);											// reset, nDivider=0:16us,1:32us 2:64us 3:128us
	for(;;)
	{
		rPDATE = rPDATE|0xF;								// close beep
		rPDATB = rPDATB|0xFF;								// close LED 1,2 (D1204,D1205)
		rPDATF = rPDATF|0xFF;								// close LED 3,4 (D1206,D1207)
		delay(500);

		rPDATB = rPDATB&0x4F;								// LED 1,2 (D1204,D1205) on
		rPDATF = rPDATF&0xE7;								// LED 3,4 (D1206,D1207) on
		rPDATE = rPDATE&0xF7;								// Beep
		delay(10000);
	}
}

void debug_undef(void)
{
	uart_sendstring("!!!Enter UNDEFINED.\r\n");	
	breakpoint();
}

void debug_swi(void)
{
	uart_sendstring("!!!Enter SWI.\r\n");	
	breakpoint();
}

void debug_abort(void)
{
	uart_sendstring("!!!Enter ABORT\r\n");	
	breakpoint();
}

void debug_fiq(void)
{
	uart_sendstring("!!!Enter FIQ.\r\n");	
	breakpoint();
}


