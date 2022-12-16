/*
 * uart_service.cpp
 *
 *  Created on: 2022. 12. 16.
 *      Author: skagu
 */

#include "console.h"
#include "main.h"

#define NEW_LINE		(0x0d)

uint32_t CON_GetLine(uint8_t* pLine)
{
	uint32_t nLen = 0;
	uint8_t* pBuf = pLine;
	uint8_t nData;
	while(true)
	{
		if(true == HAL_ReceiveUART(&nData))
		{
			if(nData == NEW_LINE)
			{
				*pBuf = 0;	// String End.
				break;
			}
			*pBuf = nData;
			pBuf++;
			nLen++;
		}
	}
	return nLen;
}

void CON_Puts(uint8_t* pLine)
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

void CON_PutsNB()
{

}

bool CON_GetLineNB(uint8_t* pLine)
{

}

void CON_Run()
{

}
