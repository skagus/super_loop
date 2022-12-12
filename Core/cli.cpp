/*
 * cli.cpp
 *
 *  Created on: 2022. 12. 12.
 *      Author: skagu
 */

#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "appMain.h"

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



#define LED_PIN	(1 << 11)

void cmdLed(uint32_t argc, uint8_t* argv[])
{
	if(0 == atoi((char*)argv[1]))
	{
		putLine((uint8_t*)"led off\n");
		HAL_OutPort(LED_PIN, true);
	}
	else
	{
		putLine((uint8_t*)"led on\n");
		HAL_OutPort(LED_PIN, false);
	}
}

uint32_t getToken(uint8_t* pInput, uint8_t* argv[])
{
	uint32_t argc = 0;
	char *p = strtok((char*)pInput, " ");
	argv[argc] = (uint8_t*)p;
	while(p != NULL)
	{
		argc++;
	    p = strtok(NULL, " ");
	    argv[argc] = (uint8_t*)p;
	}
	return argc;
}


#define SIZE_BUF	(80)
#define MAX_TOKEN	(8)

uint8_t anLongBuf[SIZE_BUF];
uint8_t* argv[MAX_TOKEN];

void CLI_Run()
{
	getLine(anLongBuf);
	uint32_t argc = getToken(anLongBuf, argv);
	if(0 == argc)
	{
		putLine((uint8_t*)"\n");
		return;
	}
	if(strncmp((char*)argv[0], "led", strlen("led")) == 0)
	{
		cmdLed(argc, argv);
	}
	else if(argc > 0)
	{
		putLine((uint8_t*)"Not supported\n");
		for(uint32_t nCnt = 0; nCnt < argc; nCnt++)
		{
			putLine(argv[nCnt]);
			putLine((uint8_t*)"\n");
		}
	}
}
