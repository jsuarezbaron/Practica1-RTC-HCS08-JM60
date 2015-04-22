/*
 * realtimec.h
 *
 *  Created on: Apr 19, 2015
 *      Author: William Gómez O
 */

#ifndef REALTIMEC_H_
#define REALTIMEC_H_

void RealTimeClock_Init(void);
void RealTimeClock_Read(void);

#define RTC           0x68  // 1101000
#define NUMOFDATS     48


#endif /* REALTIMEC_H_ */
