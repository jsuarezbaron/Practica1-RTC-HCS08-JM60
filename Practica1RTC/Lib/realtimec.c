/*
 * realtimec.c
 *
 *  Created on: Apr 19, 2015
 *      Author: William Gómez O
 */
#include "realtimec.h"
#include "driver_i2c.h"
#include "lcd.h"
#include "general.h"
#include "events.h"

#define FIRST_CHAR_DATE     8 
#define SEG_WAIT  5

byte ValuesToRead[NUMOFDATS];
const byte lcdMsg1[] = "RTC con Serial";
const byte lcdMsg5[] = "Fecha:  __/__/__";
const byte lcdMsg6[] = "Hora:   __:__:__";

const byte lcdMsg3[] = "Practica 1: RTC, LCD, Serial";
const byte lcdMsg4[] = "Error";
const byte lcdMsgRTCError[] = "RTC Error";
const byte mdia1[] = "Lunes";
const byte mdia2[] = "Martes";
const byte mdia3[] = "Miercoles";
const byte mdia4[] = "Jueves";
const byte mdia5[] = "Viernes";
const byte mdia6[] = "Sabado";
const byte mdia7[] = "Domingo";


void RealTimeClock_Read(void)
{
	if (Read_Data_RTC_I2C(RTC, (unsigned char *)&_var_rtc, 7, 0x00) == FALSE)
	{
		LCDWriteMsg(0,lcdMsg5,0);
		LCDWriteMsg(LCD_USE_SECOND_LINE,lcdMsg6,0);
	}
	else
	{
		LCDClearLine(LCD_USE_SECOND_LINE, 0);
		switch(RTC_DIASEM){
		case 1:
			LCDWriteMsg(LCD_USE_SECOND_LINE+FIRST_CHAR_DATE,mdia1,0);
			break;
		case 2:
			LCDWriteMsg(LCD_USE_SECOND_LINE+FIRST_CHAR_DATE,mdia2,0);
			break;
		case 3:
			LCDWriteMsg(LCD_USE_SECOND_LINE+FIRST_CHAR_DATE,mdia3,0);
			break;
		case 4:
			LCDWriteMsg(LCD_USE_SECOND_LINE+FIRST_CHAR_DATE,mdia4,0);
			break;
		case 5:
			LCDWriteMsg(LCD_USE_SECOND_LINE+FIRST_CHAR_DATE,mdia5,0);
			break;
		case 6:
			LCDWriteMsg(LCD_USE_SECOND_LINE+FIRST_CHAR_DATE,mdia6,0);
			break;
		case 7:
			LCDWriteMsg(LCD_USE_SECOND_LINE+FIRST_CHAR_DATE,mdia7,0);
			break;
		default:
			break;
		}
		ValuesToRead[0] = RTC_DEC_DIA | 0x30;
		ValuesToRead[1] = RTC_UNI_DIA | 0x30;
		ValuesToRead[2] = '/';
		ValuesToRead[3] = RTC_DEC_MES | 0x30;
		ValuesToRead[4] = RTC_UNI_MES | 0x30;
		ValuesToRead[5] = '/';
		ValuesToRead[6] = RTC_DEC_YEA | 0x30;
		ValuesToRead[7] = RTC_UNI_YEA | 0x30;
		ValuesToRead[8] = '\0';
		LCDWriteMsg(LCD_USE_TIRTH_LINE+FIRST_CHAR_DATE,ValuesToRead,0);
		
		ValuesToRead[0] = RTC_DEC_HOUR24 | 0x30;
		ValuesToRead[1] = RTC_UNI_HOUR24 | 0x30;
		ValuesToRead[2] = ':';
		ValuesToRead[3] = RTC_DEC_MIN | 0x30;
		ValuesToRead[4] = RTC_UNI_MIN | 0x30;
		ValuesToRead[5] = ':';
		ValuesToRead[6] = RTC_DEC_SEG | 0x30;
		ValuesToRead[7] = RTC_UNI_SEG | 0x30;
		ValuesToRead[8] = '\0';
		LCDWriteMsg(LCD_USE_FOURTH_LINE+FIRST_CHAR_DATE,ValuesToRead,0);
	}          
}

void RealTimeClock_Init(void){
		LCDWriteCenterMsg(0,lcdMsg1,0);
		
		while(count!=5){
			WAIT;
			count++;
		}
		LCD_Clear();
		
		
	/***********************CONFIGURACIÓN RTC*******************************/
	    RTC_CH = 0; //Habilita el oscilador
	    //Segundos
	    RTC_UNI_SEG = 0; //Unidades de los segundos en BCD de 0-9
	    RTC_DEC_SEG = 5; //Decenas de los segundos en BCD de 0-9
	    //Minutos
	    RTC_UNI_MIN = 9; //
	    RTC_DEC_MIN = 5; //
	    //Horas
	    RTC_12_24 = RTC_FORMAT_24H; //Bit que indica el formato
	    RTC_UNI_HOUR24 = 3; //Unidades de las horas
	    RTC_DEC_HOUR24 = 2; //Decenas de las horas, son 1 ó 2, que se controla con la unión
	    //Días de la semana, de 0 a 7
	    RTC_DIASEM = 1;
	    //Fecha
	    	//Día
	    RTC_UNI_DIA = 9;//Unidades del día del mes 0-9
	    RTC_DEC_DIA = 2;//Decenas del día del mes 0-3
	    	//Mes
	    RTC_UNI_MES = 2;
	    RTC_DEC_MES = 0;
	    	//Año
	    RTC_UNI_YEA = 1;
	    RTC_DEC_YEA = 0;
	    if (Write_Data_RTC_I2C(RTC, (unsigned char *)&_var_rtc, 7, 0x00) == FALSE)
	    {
	      LCDWriteMsg(LCD_USE_SECOND_LINE,lcdMsgRTCError,0);
	      //Error
	    }
	    else
	    {
			LCDWriteMsg(0,lcdMsg3,0);
			//LCDWriteMsg(LCD_USE_FOURTH_LINE,lcdMsg4,0);
			LCDWriteMsg(LCD_USE_TIRTH_LINE,lcdMsg5,0);
			LCDWriteMsg(LCD_USE_FOURTH_LINE,lcdMsg6,0);
	    }
}

