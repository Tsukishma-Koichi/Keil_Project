#ifndef _MYDMA_H_
#define _MYDMA_H_

#include "stm32f10x.h"

void MyDMA_Init(uint32_t AddrA, uint32_t AddrB, uint16_t Size);
void MyDMA_Transfer(void);

#endif