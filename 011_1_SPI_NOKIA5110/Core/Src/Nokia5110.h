/*
 * Nokia5110.h
 *
 *  Created on: Oct 19, 2021
 *      Author: RY
 */

#ifndef SRC_NOKIA5110_H_
#define SRC_NOKIA5110_H_

#include "stm32f4xx_hal.h"

#include <stdbool.h>

extern SPI_HandleTypeDef hspi2;
extern DMA_HandleTypeDef hdma_spi2_tx;

uint8_t fremeBuff[504];

bool Nokia5110_Init(void);
void Nokia5110_Reset(void);
bool Nokia5110_Update(void);
void Nokia5110_clear(void);
void Nokia5110_BufferWrite(uint8_t* data, uint16_t length);
bool Nokia5110_Write(uint8_t data, uint8_t mode);
void Nokia5110_BufferWrite(uint8_t* data, uint16_t length);
void Nokia5110_SetPixel(uint8_t x, uint8_t y, bool set);

#endif /* SRC_NOKIA5110_H_ */
