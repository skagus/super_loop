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

#define LED_PIN	(1 << 11)


void LED_Run()
{
	static uint32_t nPrvTick = HAL_GetTick();
	static bool bOn = false;
	uint32_t nCurTick = HAL_GetTick();
	if(nCurTick - nPrvTick >= 1000)
	{
		HAL_OutPort(LED_PIN, bOn);
		bOn = !bOn;
		nPrvTick = nCurTick;
	}
}

void LED_SetOp(LedOp eOp)
{
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
			//???
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
	switch(nOp)
	{
		case 0:
		{
			LED_SetOp(LED_OFF);
			break;
		}
		case 1:
		{
			LED_SetOp(LED_ON);
			break;
		}
		default:
		{
			CON_Puts((uint8_t*)"Not supported LED OP\n");
			break;
		}
	}
}
