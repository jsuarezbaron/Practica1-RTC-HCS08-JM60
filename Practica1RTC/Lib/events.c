/*
 * events.c
 *
 *  Created on: Apr 19, 2015
 *      Author: William Gómez O
 */
#include "events.h"
#include "realtimec.h"
#include "driver_i2c.h"
#include "lcd.h"
#include "sci.h"
byte countr=0;


void Process_Events(void){
	if(EV_INT_TPM){
		EV_INT_TPM=0;
		
		RealTimeClock_Read();
			
		
	}
	if(EV_INT_SCI){
		EV_INT_SCI=0;
		
		countr++;
		
		if(countr==2)
		{
			RTC_CH = (valorx&0b10000000)>>7;
			RTC_UNI_SEG = (valorx&0b00001111); 
			RTC_DEC_SEG = (valorx&0b01110000)>>4; 	    
		}
		if(countr==3)
		{
			RTC_UNI_MIN = (valorx&0b00001111); //
			RTC_DEC_MIN = (valorx&0b01110000)>>4; 
		}
		if(countr==4)
		{
			RTC_12_24 = (valorx&0b01000000)>>6; //Bit que indica el formato
			RTC_UNI_HOUR24 = (valorx&0b00001111); //Unidades de las horas
			RTC_DEC_HOUR24 = (valorx&0b00110000)>>4;
		}
		if(countr==5)
		{
			 RTC_DIASEM = (valorx&0b00000111);
		}
		if(countr==6)
		{
			 RTC_UNI_DIA = (valorx&0b00001111);//Unidades del día del mes 0-9
			 RTC_DEC_DIA = (valorx&0b00110000)>>4;
		}
		if(countr==7)
		{
			RTC_UNI_MES = (valorx&0b00001111);
			RTC_DEC_MES = (valorx&0b00010000)>>4;
		}
		if(countr==8)
		{
			RTC_UNI_YEA = (valorx&0b00001111);
			RTC_DEC_YEA = (valorx&0b11110000)>>4;
			countr=0;
			if (Write_Data_RTC_I2C(RTC, (unsigned char *)&_var_rtc, 7, 0x00) == FALSE)
			{
			  
			  //Error
			}
				    
		}

		while(SCI2S1_TDRE == 0);
		SCI2D = 1;
		
	}
}

