/**
 ****************************************************************************************************
 * @file        stmflash.h
 * @author      ALIENTEK
 * @brief       stmflash code
 * @license     Copyright (C) 2012-2024, ALIENTEK
 ****************************************************************************************************
 * @attention
 *
 * platform     : ALIENTEK M100-STM32F103 board
 * website      : www.alientek.com
 * forum        : www.openedv.com/forum.php
 *
 * change logs  ：
 * version      data         notes
 * V1.0         20240409     the first version
 *
 ****************************************************************************************************
 */

#ifndef __STMFLASH_H
#define __STMFLASH_H

#include "main.h"


uint32_t stmflash_read_word(uint32_t addr);
void stmflash_read(uint32_t addr, uint32_t *buf, uint32_t length);
void stmflash_write_nocheck(uint32_t addr, uint32_t *buf, uint16_t length);
void stmflash_write(uint32_t addr, uint32_t *buf, uint16_t length);
void test_write(uint32_t waddr, uint16_t wdata);

#endif
