/*
 * led.h
 *
 *  Created on: 2022. 12. 16.
 *      Author: skagu
 */

#ifndef LED_H_
#define LED_H_
#include <stdint.h>

enum LedOp
{
	LED_OFF,
	LED_ON,
	LED_BLINK,
	NUM_LED_OP,
};

void LED_Run();
void LED_SetOp(LedOp eOp);
void LED_Cli(uint32_t argc, uint8_t* argv[]);


#endif /* LED_H_ */
