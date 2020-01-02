/*********************************************************************************************
* File£º	option.H
* Author:	embest	
* Desc£º	Samsung 44B0X CPU optional define
* History:	
*********************************************************************************************/
#ifndef __OPTION_H__
#define __OPTION_H__

#define FIN   8000000
#define MCLK 64000000
#define PLLON 1

#if (MCLK==64000000)
#define PLL_M (0x38)
#define PLL_P (0x2)
#define PLL_S (0x1)

#elif (MCLK==60000000)
#define PLL_M (0x34)
#define PLL_P (0x3)
#define PLL_S (0x1)

#elif (MCLK==40000000)
#define PLL_M (0x48)
#define PLL_P (0x3)
#define PLL_S (0x2)

#elif (MCLK==20000000)
#define PLL_M (0x48)
#define PLL_P (0x3)
#define PLL_S (0x3)
#endif

#define WRBUFOPT 	(0x8)   						// write_buf_on

//#define SYSCFG_8KB  (0x6)
#define SYSCFG_0KB 	(0x0|WRBUFOPT)
#define SYSCFG_4KB 	(0x2|WRBUFOPT)
#define SYSCFG_8KB 	(0x6|WRBUFOPT)

#define CACHECFG    SYSCFG_8KB

#define NON_CACHE_START		(0x2000000)
#define NON_CACHE_END 		(0xc000000)

#define _RAM_STARTADDRESS 	0xc000000
#define _ISR_STARTADDRESS 	0xc7fff00     //GCS6:16M bit DRAM/SDRAM

#endif /*__OPTION_H__*/
