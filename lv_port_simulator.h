#ifndef __LV_PORT_SIMULATOR_H__
#define __LV_PORT_SIMULATOR_H__

#include <stdbool.h>

#define INTERNAL_PSRAM_SIZE (8 * 1024 * 1024)
#define QSPI0_FLASH_SIZE (8 * 1024 * 1024)

void lvgl_port_init(const char *binary_resource_file);

void lvgl_port_deinit(void);

bool lvgl_main_loop(void);

#endif // __LV_PORT_SIMULATOR_H__