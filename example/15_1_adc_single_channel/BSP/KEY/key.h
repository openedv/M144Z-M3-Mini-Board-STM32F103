/**
 ****************************************************************************************************
 * @file        key.h
 * @author      ALIENTEK
 * @brief       This file provides the driver for the key
 * @license     Copyright (C) 2020-2032, ALIENTEK
 ****************************************************************************************************
 * @attention
 *
 * platform     : ALIENTEK STM32F103 development board
 * website      : https://www.alientek.com
 * forum        : http://www.openedv.com/forum.php
 *
 * change logs  :
 * version      data        notes
 * V1.0	        20240222    the first version
 *
 ****************************************************************************************************
 */


#ifndef BSP_KEY_KEY_H_
#define BSP_KEY_KEY_H_
#include "main.h"

/* KEY0 and WKUP pin definitions */
#define KEY0        HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)      /* read KEY0 pin */
#define WK_UP       HAL_GPIO_ReadPin(WK_UP_GPIO_Port, WK_UP_Pin)    /* read WKUP pin */

#define KEY0_PRES    1                                              /* KEY0 is pressed */
#define WKUP_PRES    2                                              /* KEY_UP is pressed */


uint8_t key_scan(uint8_t mode);                                     /* key scan function */

#endif                                                              /* BSP_KEY_KEY_H_ */
