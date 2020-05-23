/*
 * Timer.h
 *
 *  Created on: May 14, 2020
 *      Author: Jesus Rodriguez
 */

#ifndef TIMER_H_
#define TIMER_H_

static int interrupt_counts;

void Setting_up_Timer0_A(void);
void Setting_up_PWM(void);
void Pulse(int ms, int state, int bit);

#endif /* TIMER_H_ */
