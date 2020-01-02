/*********************************************************************************************
* File:		44blib.c
* Author:	embest
* Desc:		s3c44b0 function library 
* History:	
*********************************************************************************************/
#include <stdarg.h>
#include "44b.h"
#include "44blib.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include<stdio.h>
/*------------------------------------------------------------------------------------------*/
/*	 								constant define						 				    */
/*------------------------------------------------------------------------------------------*/
void (*run)(void) = (void (*)(void))0x0;
void uhal_init_interrupts(void)	;
/*------------------------------------------------------------------------------------------*/
/*	 								global variable						 				    */
/*------------------------------------------------------------------------------------------*/
static int f_nDelayLoopCount = 400;
static int f_nWhichUart = 0;
int f_nDownloadAddr = 0x0C000000;

					//----------------------------------------------------------//
					//							SYSTEM							//
					//----------------------------------------------------------//
					
/*********************************************************************************************
* name:		delay
* func:		delay time
* para:		nTime -- input, nTime=0: nAdjust the delay function by WatchDog timer.
*						    nTime>0: the number of loop time, 100us resolution.
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void delay(int nTime)
{
	int nAdjust;
	int i;

	nAdjust = 0;

	if(nTime == 0)
	{
		nTime = 200;
		nAdjust = 1;
		f_nDelayLoopCount = 400;
		rWTCON = ((MCLK/1000000-1)<<8)|(2<<3);			// 1M/64, Watch-dog, nRESET, interrupt disable
		rWTDAT = 0xffff;
		rWTCNT = 0xffff;	 
		rWTCON = ((MCLK/1000000-1)<<8)|(2<<3)|(1<<5); 	// 1M/64, Watch-dog enable, nRESET, interrupt disable
	}

	for(; nTime>0; nTime--)
	{
		for(i=0; i<f_nDelayLoopCount; i++)
			;
	}

	if(nAdjust==1)
	{
		rWTCON = ((MCLK/1000000-1)<<8)|(2<<3);
		i = 0xffff-rWTCNT;   							// 1count/16us?????????
		f_nDelayLoopCount = 8000000/(i*64);				// 400*100/(i*64/200)
	}
}


					//----------------------------------------------------------//
					//							PORTS							//
					//----------------------------------------------------------//
					
/*********************************************************************************************
* name:		port_init
* func:		initialize io port for Embest teach kit ii
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void port_init(void)
{
	// CAUTION:Follow the configuration order for setting the ports. 
	// 1) setting value 
	// 2) setting control register 
	// 3) configure pull-up resistor.  

	//16bit data bus configuration  

	// PORT A GROUP
	// 	9	8	7	6	5	4	3	2	1	0
	// 	A24	A23	A22	A21	A20	A19	A18	A17	A16	A0
	//	0	1	1	1	1	1	1	1	1	1
	rPCONA = 0x1ff;	

	// PORT B GROUP
	// 	10		9		8		7		6		5		4		3		2		1		0
	//	/CS5	/CS4	/CS3	/CS2	/CS1	GPB5	GPB4	/SRAS	/SCAS	SCLK	SCKE
	//	EXT		NIC		USB		IDE		SMC		NC		NC		Sdram	Sdram	Sdram	Sdram
	//	?		?		?		?		?		Out		Out		?		?		?		?
	//  1 		1   	1   	1    	1    	0       0     	1    	1    	1   	1	
	rPCONB = 0x1cf;
	rPDATB = 0x7ff&~(1<<10);				
    
	// PORT C GROUP, BUSWIDTH=16
	//  15		14		13		12		11		10		9		8		7		6		5		4		3		2		1		0
	//	NC		NC		Uart1	Uart1	NC		NC		NC		NC		NC		NC		NC		NC		out		out		out		out
	//	?		?		?		?		?		?		?		?		?		?		?		?		*		*		*		*																													*						
	//	00		00		11		11		00		00		01		01		00		00		00		00		01		01		01		01
	rPDATC = 0xfc00;
	rPCONC = 0x0FF5FF55;	
//	rPCONC = 0x0ff0ff55;	// EduKit-II
//	rPCONC = 0x0ff0ffff;	// S3CEV40
	rPUPC  = 0x30ff;										// PULL UP RESISTOR should be enabled to I/O

	// PORT D GROUP
	// 	BIT7	6		5		4		3		2		1		0
	//	VF		OUT		VLINE	VCLK	VD3		VD2		VD1		VD0
	//	10		01		10		10		10		10		10		10
	rPDATD = 0xbf;
	rPCOND = 0x9aaa;	
	rPUPD  = 0x0;
	// These pins must be set only after CPU's internal LCD controller is enable
	
	// PORT E GROUP 
	// 	8		7		6		5		4		3			2		1		0
	// 	CODECLK	Out		Out		Out		TOUT1	Out(Beep)	RXD0	TXD0	?
	//  *		*		*		*				*			*		*
	// 	10		01		01		01		10		01			10		10		00
	rPDATE = 0x1ff;
	rPCONE = 0x25668;	
	rPUPE  = 0x6;
	
	// PORT F GROUP
	// 	8		7		6		5		 4		3		2		1		0
	// 	IISCLK	IISDI	IISDO	IISLRCK	Out		Out		Input	IICSDA	IICSCL
	//	*		*		*		*		*		*		*		*		*
	// 	100		100		100		100		01		01		00		10		10
	rPDATF = 0xe7;
	rPCONF = 0x24914A;										// PF3:LED4 PF4:LED3 PF2:nWait
//	rPCONF = 0x252A; //S3CEV40
	rPUPF  = 0x0;

	// PORT G GROUP
	// 	7		6		5		4		3		2		1		0
	// 	INT7	INT6	INT5	INT4	INT3	INT2	INT1	INT0
	//	S3		S4		S5		S6		NIC				IDE		USB
	//											*
	//	11      11      11      11      11      11      11      11
	rPDATG = 0xff;
	rPCONG = 0xffff;
	rPUPG  = 0x0;											// should be enabled  
	rSPUCR = 0x7;  											// D15-D0 pull-up disable

	// Non Cache area
	//rNCACHBE0 = ((NON_CACHE_END>>12)<<16) | (NON_CACHE_START>>12); 
	rNCACHBE0 = 0xc0002000;
	// Low level default
	rEXTINT = 0x0;
}

void beep(int BeepStatus)
{
	if (BeepStatus==0)
		rPDATE=rPDATE|0x8;
	else
		rPDATE=rPDATE&0x1f7;

}

					//----------------------------------------------------------//
					//							UART							//
					//----------------------------------------------------------//
					
/*********************************************************************************************
* name:		uart_init
* func:		initialize uart channel
* para:		nMainClk	-- 	input, 
*							nBaud, 
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uart_init(int nMainClk, int nBaud)
{
    int i;

    if(nMainClk==0)
		nMainClk=MCLK;

    rUFCON0=0x0;     								//FIFO disable
    rUFCON1=0x0;
    rUMCON0=0x0;
    rUMCON1=0x0;

	//UART0
    rULCON0	 = 0x3;     							// Normal, No parity, 1 stop, 8 bit
    rUCON0	 = 0x245;   	 						// rx=edge, tx=level, disable timeout int., enable rx error int., normal,interrupt or polling
    rUBRDIV0 = ((int)(nMainClk/16./nBaud + 0.5) -1);

	//UART1
    rULCON1  = 0x3;
    rUCON1   = 0x245;
    rUBRDIV1 = ((int)(nMainClk/16./nBaud + 0.5) -1);

    for(i=0; i<100; i++) 
    	;
}

/*********************************************************************************************
* name:		uart_change_baud
* func:		Change uart baud rate
* para:		nChannel	-- 	input, UART0 or UART1
*			nBaud		--	input, baud rate
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uart_change_baud(int nChannel, int nBaud)
{
    if (nChannel == UART0)
	    rUBRDIV0=( (int)(MCLK/16./nBaud + 0.5) -1 );
    
    if (nChannel == UART1)
	    rUBRDIV1=( (int)(MCLK/16./nBaud + 0.5) -1 );
}

/*********************************************************************************************
* name:		uart_select
* func:		change uart channel
* para:		nChannel	-- 	input, UART0 or UART1
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uart_select(int nChannel)
{
    f_nWhichUart=nChannel;
}

/*********************************************************************************************
* name:		uart_txempty
* func:		Empty uart channel
* para:		nChannel	-- 	input, UART0 or UART1
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uart_txempty(int nChannel)
{
    if(nChannel == 0)
		while(!(rUTRSTAT0 & 0x4)); 						// wait until tx shifter is empty.
    else
    	while(!(rUTRSTAT1 & 0x4)); 						// wait until tx shifter is empty.
}

/*********************************************************************************************
* name:		uart_getch
* func:		Get a character from the uart
* para:		none
* ret:		get a char from uart channel
* modify:
* comment:		
*********************************************************************************************/
char uart_getch(void)
{
    if(f_nWhichUart==0)
    {	    
		while(!(rUTRSTAT0 & 0x1)); 						// Receive data read
		return RdURXH0();
    }
    else
    {
		while(!(rUTRSTAT1 & 0x1)); 						// Receive data ready
		return	rURXH1;
    }
}

/*********************************************************************************************
* name:		uart_getkey
* func:		Get a character from the uart
* para:		none
* ret:		get a char from uart channel
* modify:
* comment:		
*********************************************************************************************/
char uart_getkey(void)
{
    if(f_nWhichUart==0)
    {	    
		if(rUTRSTAT0 & 0x1)    //Receive data ready
    	    return RdURXH0();
		else
		    return 0;
    }
    else
    {
		if(rUTRSTAT1 & 0x1)    //Receive data ready
		    return rURXH1;
		else
		    return 0;
    }
}

/*********************************************************************************************
* name:		uart_getString
* func:		Get string from uart channel and store the result to input address (*pString)
* para:		pString	-- 	input, string
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uart_getstring(char *pString)
{
	char *pString2 = pString;
	char c;
	while((c = uart_getch())!= '\r')
    {
		if(c == '\b')
		{
		    if(	(int)pString2 < (int)pString )
		    {
				uart_printf("\b \b");
				pString--;
		    }
		}
		else // store and echo on uart channel
		{
		    *pString ++= c;
		    uart_sendbyte(c);
		}
    }
    *pString = '\0';
    uart_sendbyte('\n');
}

/*********************************************************************************************
* name:		uart_getintnum
* func:		Get a numerical (Dec - default or Hex fromat) from the uart, with or without a signed
* para:		none
* ret:		nResult: the valid number which user input from uart
* 					-- Dec format number (default)
* 					-- Hex format number ('H/h' suffix or '0x' ahead)
* modify:
* comment:		
*********************************************************************************************/
int uart_getintnum(void)
{
	char	pStr[30];
	char	*pString =  pStr;
	int		nLastIndex;
	int		nBase    =  10;
	int		nMinus   =  0;
	int		nResult  =  0;
	int		i;
	
	uart_getstring(pString);
	
	if(pString[0] == '-')
	{
		nMinus = 1;
		pString++ ;
	}
	
	// if '0x' ahead
	if(pString[0] == '0' && (pString[1] == 'x' || pString[1] == 'X'))
	{
		nBase = 16;
		pString += 2;
	}
	
	// if 'H' or 'h' suffix
	nLastIndex = strlen(pString)-1;
	if( pString[nLastIndex] == 'h' || pString[nLastIndex] == 'H' )
	{
		nBase = 16;
		pString[nLastIndex] = 0;
		nLastIndex--;
	}

	// without ahead or suffix -- default numerical 
	if(nBase == 10)
	{
		nResult = atoi(pString);
		nResult = nMinus ? (-1*nResult) : nResult;
	}
	else // Hex numerical
	{
		for(i = 0;i <= nLastIndex;i++ )
		{
			if(isalpha(pString[i]))
			{
				if(isupper(pString[i]))
					nResult = (nResult<<4) + pString[i]-'A' + 10;
				else
				    nResult = (nResult<<4) + pString[i]-'a' + 10;
			}
			else
			{
				nResult = (nResult<<4) + pString[i]-'0';
			}
		}
		nResult = nMinus ? (-1*nResult) : nResult;
	}
	return nResult;
}

/*********************************************************************************************
* name:		uart_sendbyte
* func:		Send one byte to uart channel
* para:		nData	-- 	input, byte
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uart_sendbyte(int nData)
{
	if(f_nWhichUart == 0)
    {
		if(nData == '\n')
		{
		    while(!(rUTRSTAT0 & 0x2));
		    delay(10);									// because the slow response of hyper_terminal 
		    WrUTXH0('\r');
		}
		while(!(rUTRSTAT0 & 0x2)); 						// Wait until THR is empty.
		delay(10);
		WrUTXH0(nData);
   	}
	else
    {
		if(nData=='\n')
		{
			while(!(rUTRSTAT1 & 0x2));
			delay(10);									// because the slow response of hyper_terminal 
			rUTXH1 = '\r';
		}
		while(!(rUTRSTAT1 & 0x2));  					// Wait until THR is empty.
		delay(10);
		rUTXH1 = nData;
    }	
}		

/*********************************************************************************************
* name:		uart_sendstring
* func:		Send string to uart channel
* para:		pString	-- 	input, string
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uart_sendstring(char *pString)
{
    while(*pString)
    {
		uart_sendbyte(*pString++);
	}
}

/*********************************************************************************************
* name:		uart_printf
* func:		print format string
* para:		fmt	-- 	input,  
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void uart_printf(char *fmt,...)
{
    va_list 	ap;
    char 		szString[256];

    va_start(ap, fmt);
    vsprintf(szString, fmt, ap);
    uart_sendstring(szString);
    va_end(ap);
}

					//----------------------------------------------------------//
					//							Timer							//
					//----------------------------------------------------------//
					
/*********************************************************************************************
* name:		timer_start
* func:		start timer
* para:		nDivider	-- 	input, 0:16us,1:32us 2:64us 3:128us
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void timer_start(int nDivider)
{
    rWTCON = ((MCLK/1000000-1)<<8) | (nDivider<<3);
    rWTDAT = 0xffff;
    rWTCNT = 0xffff;   

    // 1/16/(65+1), nRESET, interrupt disable
    rWTCON = ((MCLK/1000000-1)<<8) | (nDivider<<3) | (1<<5);	
}

/*********************************************************************************************
* name:		timer_stop
* func:		stop timer
* para:		none
* ret:			--	int, timer count
* modify:
* comment:		
*********************************************************************************************/
int timer_stop(void)
{
    rWTCON = ((MCLK/1000000-1)<<8);
    return (0xffff-rWTCNT);
}


					//----------------------------------------------------------//
					//							General Library					//
					//----------------------------------------------------------//
					
/*********************************************************************************************
* name:		cache_flush
* func:		flush cache
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void cache_flush(void)
{
    int nSaveSyscfg;
    int i;
    
    nSaveSyscfg = rSYSCFG;
    rSYSCFG = SYSCFG_0KB; 		      
    for(i=0x10004000; i<0x10004800; i+=16)    
    {					   
		*((int*)i)=0x0;		   
    }
    rSYSCFG = nSaveSyscfg; 			    
}

/*********************************************************************************************
* name:		sys_init
* func:		Initilaize interrupt, port and UART
* para:		none
* ret:		none
* modify:
* comment:		
*********************************************************************************************/
void sys_init()
{
	// Using 8KB Cache
	rSYSCFG = CACHECFG;   							

	// Initial 44B0X's I/O port
	port_init();									

	// Initilaize interrupt
	uhal_init_interrupts();

    // Initilaize external interrupt
	rEXTINT = 0x22222222;                  			// Level mode
	rEXTINTPND = 0xf;								// Clear EXTINTPND reg
	
	// Initial delay time
    delay(0);
//	beep(1);
	delay(1000);
//	beep(0);

	// Initial Serial port 1
	uart_init(0,115200);
	uart_printf("\nboot success...\n");

}
