/*
 * BMP180.c
 *
 *  Created on: Oct 16, 2021
 *      Author: RY
 */

#include "BMP180.h"

void BMP180_Init()
{

	if(HAL_I2C_IsDeviceReady(&hi2c1, BMP180_DEVICE_WRITE_REGISTER_ADRESS, 1, 100000) != HAL_OK)
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);

	BMP180_Get_Calibration_Value();


}

void BMP180_Get_Calibration_Value()
{
	int a = 0;
	uint8_t calibBuff[BMP180_CALIBRAION_VALUE_LENGTH] = {0};

	HAL_I2C_Mem_Read(&hi2c1, BMP180_DEVICE_READ_REGISTER_ADRESS, BMP180_CALIBRATION_START_ADDRESS, 1, calibBuff, BMP180_CALIBRAION_VALUE_LENGTH, 100);

		AC1	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
		AC2	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
		AC3	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
		AC4	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
		AC5	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
		AC6	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
		B1	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
		B2	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
		MB	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
		MC	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
		MD	= (int16_t) ((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;

		if(AC1 == 0x0000 || AC1 == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}

		if(AC2 == 0x0000 || AC2 == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}

		if(AC3 == 0x0000 || AC3 == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}

		if(AC4 == 0x0000 || AC4 == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}
		if(AC5 == 0x0000 || AC5 == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}

		if(AC6 == 0x0000 || AC6 == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}

		if(B1 == 0x0000 || B1 == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}

		if(B2 == 0x0000 || B2 == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}
		if(MB == 0x0000 || MB == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}

		if(MC == 0x0000 || MC == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}

		if(MD == 0x0000 || MD == 0xFFFF)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}



}

void BMP180_Get_temprature(void)
{
	BMP180_Get_Uncompansated_temprature();
	tx1 = (((int32_t)unCompTemparature - (int32_t)AC6) * (int32_t)AC5) / 32768;
	tx2 = ((int32_t)MC * 2048) / (tx1 + (int32_t)MD);

	if(tx1 == 0 && MD == 0)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
		while(1);
	}

	tb5 = tx1 + tx2;
	Temperature = (float)(tb5 + 8) / 16 * 0.1;


}

void BMP180_Get_Uncompansated_temprature(void)
{
	uint8_t	rData[2] = {0};
	uint8_t wData[1];
	wData[0] = 0x2E;

	HAL_I2C_Mem_Write(&hi2c1, BMP180_DEVICE_WRITE_REGISTER_ADRESS, 0xF4, 1, wData, 1, 100000);
	HAL_Delay(5);
	HAL_I2C_Mem_Read(&hi2c1, BMP180_DEVICE_READ_REGISTER_ADRESS, 0xF6, 1, rData, 2, 100000);
	unCompTemparature = (uint16_t)((rData[0] << 8) | rData[1]);

}

void BMP180_Get_Pressure(void)
{
	BMP180_Get_Uncompansated_Pressure();
	pb6 = tb5 - 4000;
	px1 = (pb2 * (pb6 * pb6 / 4096)) / 2048;
	px2 = ac2 * pb6 / 2048;
	px3 = px1 + px2;
	pb3 = (((ac1 * 4 + px3) << (uint8_t)0x03) + 2) / 4;
	px1 = ac3 * pb6 / 8192;
	px2 = (pb1 * (pb6 * pb6 /4096)) / 65536;
	px3 = ((px1 + px2) + 2) /4;
	pb4 = ac4 * (unsigned long)(px3 + 32768) / 32768;
	pb7 = ((unsigned long)unCompPreture - pb3) * (500000 >> (uint8_t)(0x03));


	if(pb7 < 0x80000000)
		presure = (pb7 * 2) / pb4;
	else
		presure = (pb7 / pb4) * 2;

	px1 = (presure / 256) * (presure / 256);
	px1 = (px1 * 3038) / 65536;
	px2 = (-7357 * presure) / 65536;
	presure = presure + (px1 + px2 + 3791) /16; //hpa
	presureATM = presure * 0.00000986923;  //atm



}


void BMP180_Get_Uncompansated_Pressure(void)
{
	uint8_t rData[3] = {0};
	uint8_t wData[1];
	wData[0] = 0x34 | (0x03 << 6);
	HAL_I2C_Mem_Write(&hi2c1, BMP180_DEVICE_WRITE_REGISTER_ADRESS, 0xF4, 1, wData, 1, 100000);
	HAL_Delay(26);

	HAL_I2C_Mem_Read(&hi2c1, BMP180_DEVICE_READ_REGISTER_ADRESS, 0xF6, 1, rData, 3, 100000);
	unCompPreture = (rData[0] << 16 | rData[2] >> (8 - (uint8_t)(0x03)));
}


