/*
 * uart_service.cpp
 *
 *  Created on: 2022. 12. 16.
 *      Author: skagu
 */

#include "console.h"
#include "main.h"

#define NEW_LINE		(0x0d)


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

bool CON_GetLineNB(uint8_t* pBuf, uint32_t* pnLen)
{
	uint8_t nData;
	if(true == HAL_ReceiveUART(&nData))
	{
		if(nData == NEW_LINE)
		{
			pBuf[*pnLen] = 0;	// String End.
			return true;
		}
		pBuf[*pnLen] = nData;
		(*pnLen)++;
	}
	return false;
}


uint8_t* gpRxLine;
uint32_t gnLen;
ConCbf gpfDone;
bool gbRun;

bool CON_ReqGetLine(uint8_t* pLine, ConCbf pfDone)
{
	if(true == gbRun)
	{
		return false;
	}
	gpfDone = pfDone;
	gpRxLine = pLine;
	gbRun = true;
	gnLen = 0;
	return true;
}

void CON_Run()
{
	if(gbRun)
	{
		uint8_t nData;
		if(true == HAL_ReceiveUART(&nData))
		{
			if(nData == NEW_LINE)
			{
				gpRxLine[gnLen] = 0;	// String End.
				gpfDone(gpRxLine, gnLen);
				gbRun = false;
			}
			gpRxLine[gnLen] = nData;
			(gnLen)++;
		}
	}
}
