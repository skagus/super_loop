/*
 * cli.cpp
 *
 *  Created on: 2022. 12. 12.
 *      Author: skagu
 */

#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "console.h"
#include "appMain.h"
#include "led.h"


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
uint32_t gnLen;

uint8_t* argv[MAX_TOKEN];

void CLI_Run()
{
	if(CON_GetLineNB(anLongBuf, &gnLen))
	{
		gnLen = 0;
		uint32_t argc = getToken(anLongBuf, argv);
		if(0 == argc)
		{
			CON_Puts((uint8_t*)"\n");
			return;
		}
		if(strncmp((char*)argv[0], "led", strlen("led")) == 0)
		{
			LED_Cli(argc, argv);
		}
		else if(argc > 0)
		{
			CON_Puts((uint8_t*)"Not supported\n");
			for(uint32_t nCnt = 0; nCnt < argc; nCnt++)
			{
				CON_Puts(argv[nCnt]);
				CON_Puts((uint8_t*)"\n");
			}
		}
	}
}
