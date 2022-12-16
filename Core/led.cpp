/*
 * led.cpp
 *
 *  Created on: 2022. 12. 16.
 *      Author: skagu
 */
#include <stdlib.h>
#include "main.h"
#include "console.h"
#include "led.h"

#define LED_PIN			(1 << 11)
#define BLINK_PRIOD		(100)

static uint32_t gnPrvTick;
static bool gbOn;
static bool gbBlink;

void LED_Run()
{
	if(gbBlink)
	{
		uint32_t nCurTick = HAL_GetTick();
		if(nCurTick - gnPrvTick >= BLINK_PRIOD)
		{
			HAL_OutPort(LED_PIN, gbOn);
			gbOn = !gbOn;
			gnPrvTick = nCurTick;
		}
	}
}

void LED_SetOp(LedOp eOp)
{
	gbBlink = false;
	switch(eOp)
	{
		case LED_OFF:
		{
			CON_Puts((uint8_t*)"led off\n");
			HAL_OutPort(LED_PIN, true);
			break;
		}
		case LED_ON:
		{
			CON_Puts((uint8_t*)"led on\n");
			HAL_OutPort(LED_PIN, false);
			break;
		}
		case LED_BLINK:
		{
			CON_Puts((uint8_t*)"led blink\n");
			gbBlink = true;
			break;
		}
		default:
		{
			CON_Puts((uint8_t*)"Wrong LED OP\n");
			break;
		}
	}
}



void LED_Cli(uint32_t argc, uint8_t* argv[])
{
	uint32_t nOp = atoi((char*)argv[1]);
	LED_SetOp((LedOp)nOp);
}
