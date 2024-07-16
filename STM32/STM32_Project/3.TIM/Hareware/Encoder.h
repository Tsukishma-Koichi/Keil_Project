#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "stm32f10x.h"

void Encoder_Init(void);
int16_t Encoder_Get(void);

#endif