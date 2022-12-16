
#include "main.h"
#include "console.h"
#include "led.h"

#include "appMain.h"
/*
 * appMain.cpp
 *
 *  Created on: Dec 9, 2022
 */


void CLI_Run();

void appMain()
{
	// Init : 생략.

	CON_Puts((uint8_t*)"Start\n");
	uint32_t nTick = HAL_GetTick();
	while(true)
	{
		CLI_Run();
		LED_Run();
	}
}
