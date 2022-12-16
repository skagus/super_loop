/*
 * console.h
 *
 *  Created on: 2022. 12. 16.
 *      Author: skagu
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <stdint.h>

void CON_Puts(uint8_t* pLine);
uint32_t CON_GetLine(uint8_t* pLine);

void CON_PutsNB();
bool CON_GetLineNB(uint8_t* pLine);

void CON_Run();

#endif /* CONSOLE_H_ */
