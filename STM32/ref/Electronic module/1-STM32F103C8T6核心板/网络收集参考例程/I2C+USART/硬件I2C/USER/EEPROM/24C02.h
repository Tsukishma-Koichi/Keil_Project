/****************************************Copyright (c)**************************************************                         
**
**                                 http://www.powermcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			24C02.h
** Descriptions:		24C02 操作函数库 
**
**------------------------------------------------------------------------------------------------------
** Created by:			AVRman
** Created date:		2010-10-29
** Version:				1.0
** Descriptions:		The original version
**
**------------------------------------------------------------------------------------------------------
** Modified by:			
** Modified date:	
** Version:
** Descriptions:		
********************************************************************************************************/
#ifndef __24C02_H
#define __24C02_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
					  
/* Private define ------------------------------------------------------------*/
#define AT24C01A		/* 24C01A,I2C时序和往后的24C02一样 */
//#define AT24C01		/* 24C01,I2C的时序和普通的有点不同 */

#define ADDR_24LC02		0xA0
#define I2C_PAGESIZE	4		/* 24C01/01A页缓冲是4个 */

/* Private function prototypes -----------------------------------------------*/
void I2C_Configuration(void);
uint8_t I2C_Read(I2C_TypeDef *I2Cx,uint8_t I2C_Addr,uint8_t addr,uint8_t *buf,uint16_t num);
uint8_t I2C_Write(I2C_TypeDef *I2Cx,uint8_t I2C_Addr,uint8_t addr,uint8_t *buf,uint16_t num);

#endif 

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

