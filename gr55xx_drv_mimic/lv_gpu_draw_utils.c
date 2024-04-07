#if defined(__MINGW32__) || defined(__MINGW64__)

#include "hal_gfx_core.h"
#include "hal_gfx_graphics.h"
#include "lvgl.h"

#ifndef __WEAK
#define __WEAK __attribute__((weak))
#endif // __WEAK

hal_gfx_cmdlist_t * lv_port_get_current_cl(void) {
    return hal_gfx_cl_get_bound();
}

/*****************************************************************
 * LVGL_FRAMEBUFFER_SIZE value
 *  * 32   : RGBA8888
 *  * 16   : RGB565
 *  * 0xF0 : TSC4
 *  * 0xF1 : TSC6a
 */
uint32_t s_lv_port_fb_format = HAL_GFX_RGBA8888;

__WEAK uint32_t lv_port_get_fb_format(void) {
    return s_lv_port_fb_format;
}

void lv_port_set_fb_format(uint32_t format) {
    s_lv_port_fb_format = format;
}

#if GR552X_GPU_RENDER_SUPPORT > 0u

void lv_port_gpu_fill_bg(uint32_t fb_addr, uint16_t w, uint16_t h, uint32_t cf, uint32_t rgb) {

    uint32_t fb_format ;

    switch(cf) {
        case LV_IMG_CF_GDX_RGB565:      fb_format = HAL_GFX_RGB565;     break;
        case LV_IMG_CF_TRUE_COLOR_ALPHA:
        case LV_IMG_CF_TRUE_COLOR:
        case LV_IMG_CF_GDX_RGBA8888:    fb_format = HAL_GFX_RGBA8888;   break;
        case LV_IMG_CF_GDX_TSC4:        fb_format = HAL_GFX_TSC4;       break;
        case LV_IMG_CF_GDX_TSC6a:       fb_format = HAL_GFX_TSC6A;      break;

        default: return;
    }

    hal_gfx_cmdlist_t cmd = hal_gfx_cl_le_create();
    hal_gfx_cl_bind_circular(&cmd);
    hal_gfx_set_clip(0, 0, w, h);
    hal_gfx_bind_dst_tex(fb_addr, w, h, fb_format, -1);

    hal_gfx_set_blend_fill(HAL_GFX_BL_SRC);
    hal_gfx_fill_rect(0,0,w,h, rgb);

    hal_gfx_cl_submit(&cmd);
    hal_gfx_cl_wait(&cmd);
    hal_gfx_cl_le_destroy(&cmd);
}

#endif

#endif // defined(__MINGW32__) || defined(__MINGW64__)
