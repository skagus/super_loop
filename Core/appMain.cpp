
#include "main.h"
#include "appMain.h"
/*
 * appMain.cpp
 *
 *  Created on: Dec 9, 2022
 */


void CLI_Run();

void putLine(uint8_t* pLine)
{
	uint8_t* pBuf = pLine;
	while(0 != *pBuf)
	{
		if(HAL_TransferUART(*pBuf))
		{
			pBuf++;
		}
	}
}


void appMain()
{
	// Init : 생략.

	putLine((uint8_t*)"Start\n");
	uint32_t nTick = HAL_GetTick();
	while(true)
	{
//		HAL_OutPort(LED_PIN, bOn);
		CLI_Run();
	}
}
