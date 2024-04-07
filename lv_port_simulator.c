#include "lv_port_simulator.h"
#include "drv_adapter_port.h"
#include "drv_adapter_port_simulator.h"

#include "app_graphics_mem.h"
#include "app_graphics_gpu.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include <SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

uint8_t g_psram_buffer[INTERNAL_PSRAM_SIZE];
uint8_t g_qspi0_flash_buffer[QSPI0_FLASH_SIZE];

void lvgl_port_init(const char *binary_resource_file)
{
    // Use a buffer to mimic PSRAM
    app_graphics_mem_init(g_psram_buffer, INTERNAL_PSRAM_SIZE);

    app_graphics_gpu_sim_init();

    // Use a buffer to mimic QSPI1 Flash
    // Load binary resources to the buffer
    FILE *f = fopen(binary_resource_file, "rb");
    if (f)
    {
        fseek(f, 0, SEEK_END);
        size_t filesize = ftell(f);
        fseek(f, 0, SEEK_SET);
        if (filesize > QSPI0_FLASH_SIZE)
        {
            fprintf(stderr, "\"%s\" is larger than QSPI0 Flash buffer (%d > %d)!\n", binary_resource_file, filesize, QSPI0_FLASH_SIZE);
            filesize = QSPI0_FLASH_SIZE;
        }
        size_t actual_read = fread(g_qspi0_flash_buffer, sizeof(uint8_t), filesize, f);
        if (actual_read != filesize)
        {
            fprintf(stderr, "Failed to read binary resource file \"%s\": %s\n", binary_resource_file, strerror(errno));
        }
        fclose(f);
    }
    else
    {
        fprintf(stderr, "Failed to open binary resource file \"%s\": %s\n", binary_resource_file, strerror(errno));
    }

    drv_adapter_disp_register();
    drv_adapter_touchpad_register();

    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
}

bool lvgl_main_loop(void)
{
    SDL_Event event;
    bool keep_running = true;

    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_ESCAPE:
                        keep_running = false;
                        break;

                    case SDL_SCANCODE_C:
                        if (SDL_GetModState() & KMOD_CTRL)
                        {
                            set_render_screen_mask(!get_render_screen_mask());
                            lv_obj_invalidate(lv_scr_act());
                        }
                        break;

                }
                break;

            case SDL_QUIT:
                keep_running = false;
                break;
        }
    }

    lv_port_indev_poll();
    uint32_t delay = lv_task_handler();
    SDL_Delay(delay);
    return keep_running;
}

void lv_port_res_mode_set(uint8_t mode)
{
    (void)mode;
}
