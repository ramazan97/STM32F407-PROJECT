/*
 * BMP180.h
 *
 *  Created on: Oct 16, 2021
 *      Author: RY
 */

#ifndef SRC_BMP180_H_
#define SRC_BMP180_H_

#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

// BMP180 DEVİCE ADRESS
#define BMP180_DEVICE_WRITE_REGISTER_ADRESS 0XEE
#define BMP180_DEVICE_READ_REGISTER_ADRESS 0XEF

//bmp180 calibration adress
#define BMP180_CALIBRATION_START_ADDRESS 0xAA

//BMP180 CALİBRATİON VALUE LENGTH
#define BMP180_CALIBRAION_VALUE_LENGTH 22


// CALİRATİON DEĞERLERİ
int16_t	AC1;
int16_t	AC2;
int16_t	AC3;
int16_t	AC4;
int16_t	AC5;
int16_t	AC6;
int16_t	B1;
int16_t	B2;
int16_t	MB;
int16_t	MC;
int16_t	MD;

//temparature values
int16_t unCompTemparature;
float Temperature;
int32_t tx1, tx2, tb5;

//parametre values
int16_t unCompPreture;
float presure, presureATM;
int32_t px2, px1, px3, pb3, pb4, pb6, pb7, ac1, ac2, ac3, ac4, pb1, pb2;

void BMP180_Init(void);
void BMP180_GetCalibration(void);
void BMP180_Get_Calibration_Value(void);
void BMP180_Get_Uncompansated_Pressure(void);
void BMP180_Get_Pressure(void);
void BMP180_Get_Uncompansated_temprature(void);
void BMP180_Get_temprature(void);


#endif /* SRC_BMP180_H_ */
