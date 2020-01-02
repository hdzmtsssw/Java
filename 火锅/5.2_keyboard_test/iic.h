/*********************************************************************************************
* File£º	IIC.H
* Author:	embest	
* Desc£º	IIC header file
* History:	
*********************************************************************************************/

#ifndef __IIC_H__
#define __IIC_H__

void __irq iic_int(void);
void iic_init(void);
void iic_write(UINT32T unSlaveAddr, UINT32T unAddr, UINT8T ucData);
void iic_read(UINT32T unSlaveAddr, UINT32T unAddr, UINT8T *pData);
void led8_test(void);
void led8_disp_mem(int nMemory, int nLen, int nDirection);
void led8_disp(char cWhichS,char cWhichE,char uChar);
#endif /*__IIC_H__*/
