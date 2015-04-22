/*
 * events.h
 *
 *  Created on: Apr 19, 2015
 *      Author: William Gómez O
 */
#ifndef EVENTS_H_
#define EVENTS_H_

#include "derivative.h"


typedef union
{
  unsigned char Byte;
  struct 
  {
    unsigned char flag0   :1;
    unsigned char flag1   :1;
    unsigned char flag2   :1;
    unsigned char flag3   :1;
    unsigned char flag4   :1;
    unsigned char flag5   :1;
    unsigned char flag6   :1;
    unsigned char flag7   :1;
  }Bits; 
}STR_FLAGS;

extern byte count;

extern volatile STR_FLAGS _INT_EVENTS;




// Definition of bits for indicating interrupt events.
#define INT_EVENTS _INT_EVENTS.Byte
#define EV_INT_TPM _INT_EVENTS.Bits.flag0
#define EV_INT_SCI _INT_EVENTS.Bits.flag1


void Process_Events(void);


#endif /* EVENTS_H_ */
