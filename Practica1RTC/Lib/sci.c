/*
 * sci.c
 *
 *  Created on: Apr 19, 2015
 *      Author: William Gómez O
 */
#include "sci.h"
#include "events.h"

void SCI_Init(void) {
  SCI2BDL = 78; // SCI Baud rate = BusClock/16*[SBR12:SBR0] ---> 12Mhz/(16*78) = 9600 bps
  SCI2C2 = (SCI2C2_TE_MASK | SCI2C2_RE_MASK |SCI2C2_RIE_MASK); //Masks defined by mcs908jm60.h
  /* By default M=0 inside(SCIxC1) --> Normal -- Start + 8bits (LSB first) + Stop
  PE Parity Enable 0 --> No hardware parity generation or checking
  PT  Parity Type 0 Even parity */
}

interrupt VectorNumber_Vsci2rx void SCI_ISR(void) {
	SCI2S1;
	valorx=SCI2D;
	EV_INT_SCI=1;
	
}
