#ifndef __GR55XX_HAL_H__
#define __GR55XX_HAL_H__

#include "gr55xx.h"

#include <stdint.h>

extern uint8_t g_qspi0_flash_buffer[];

#define QSPI0_XIP_BASE g_qspi0_flash_buffer

#endif // __GR55XX_HAL_H__