
#include "main.h"
/*
 * appMain.cpp
 *
 *  Created on: Dec 9, 2022
 */

#define NEW_LINE		(0x0d)

uint32_t getLine(uint8_t* pLine)
{
	uint32_t nLen = 0;
	uint8_t* pBuf = pLine;
	uint8_t nData;
	while(true)
	{
		if(true == HAL_ReceiveUART(&nData))
		{
			*pBuf = nData;
			pBuf++;
			nLen++;
			if(nData == NEW_LINE)
			{
				*pBuf = 0;	// String End.
				break;
			}
		}
	}
	return nLen;
}

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

#define SIZE_BUF	(80)
void appMain()
{
	// Init : 생략.

	uint8_t anLongBuf[SIZE_BUF];
	while(true)
	{
		getLine(anLongBuf);
		putLine(anLongBuf);
	}
}
