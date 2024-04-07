#ifndef __GR55XX_H__
#define __GR55XX_H__

#include <stdint.h>
#include "lv_port_simulator.h"

extern uint8_t g_psram_buffer[INTERNAL_PSRAM_SIZE];

#define OSPI0_XIP_BASE ((uint32_t)(g_psram_buffer))

#endif // __GR55XX_H__