#include "drv_adapter_port.h"
#include "lv_conf.h"
#include "hal_gdc.h"

#include "drv_adapter_port_simulator.h"

#include <SDL.h>

#define ACQUIRE_RENDERER(dev)                                \
    SDL_Renderer *renderer = (SDL_Renderer *)dev->user_data; \
    SDL_assert(renderer)

static void disp_drv_init(disp_drv_t *dev);
static void disp_drv_deinit(disp_drv_t *dev);
static void disp_drv_set_show_area(disp_drv_t *dev, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
static void disp_drv_flush(disp_drv_t *dev, void *buff, uint32_t buff_format, uint16_t w, uint16_t h);
static void disp_drv_wait_te(disp_drv_t *dev);
static void disp_drv_wait_to_flush(disp_drv_t *dev);
static void disp_drv_on(disp_drv_t *dev, bool on);
static void disp_drv_set_brightness(disp_drv_t *dev, uint32_t percent);
static void disp_drv_sleep(disp_drv_t *dev);
static void disp_drv_wakeup(disp_drv_t *dev);

static bool tp_drv_init(touchpad_drv_t *dev);
static bool tp_drv_deinit(touchpad_drv_t *dev);
static bool tp_drv_read_pointer(touchpad_drv_t *dev, int16_t *x, int16_t *y);
static bool tp_drv_sleep(touchpad_drv_t *dev);
static bool tp_drv_wakeup(touchpad_drv_t *dev);

static void render_screen_mask(SDL_Renderer *renderer);

static SDL_Rect s_clip_area;
static bool s_screen_mask_enabled = true;

void drv_adapter_disp_register()
{
    disp_drv_t dev = {
        .disp_drv_init = disp_drv_init,
        .disp_drv_deinit = disp_drv_deinit,
        .disp_drv_set_show_area = disp_drv_set_show_area,
        .disp_drv_flush = disp_drv_flush,
        .disp_drv_wait_te = disp_drv_wait_te,
        .disp_drv_on = disp_drv_on,
        .disp_drv_set_brightness = disp_drv_set_brightness,
        .disp_drv_wait_to_flush = disp_drv_wait_to_flush,
        .disp_drv_sleep = disp_drv_sleep,
        .disp_drv_wakeup = disp_drv_wakeup,
    };

    drv_adapter_disp_reg(0, &dev);
}

void drv_adapter_touchpad_register()
{
    touchpad_drv_t dev = {
        .touchpad_drv_init = tp_drv_init,
        .touchpad_drv_deinit = tp_drv_deinit,
        .touchpad_drv_read_pointer = tp_drv_read_pointer,
        .touchpad_drv_sleep = tp_drv_sleep,
        .touchpad_drv_wakeup = tp_drv_wakeup,
    };

    drv_adapter_touchpad_reg(&dev);
}

void set_render_screen_mask(bool enabled)
{
    s_screen_mask_enabled = enabled;
}

bool get_render_screen_mask(void)
{
    return s_screen_mask_enabled;
}

static void disp_drv_init(disp_drv_t *dev)
{
    // Create SDL window
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("LVGL Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DISP_HOR_RES, DISP_VER_RES, 0);
    SDL_assert(window);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_assert(renderer);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    dev->user_data = (void *)renderer;
}

static void disp_drv_deinit(disp_drv_t *dev)
{
    (void)dev;
}

static void disp_drv_set_show_area(disp_drv_t *dev, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    ACQUIRE_RENDERER(dev);
    s_clip_area.x = x1;
    s_clip_area.y = y1;
    s_clip_area.w = x2 - x1 + 1;
    s_clip_area.h = y2 - y1 + 1;
    SDL_RenderSetClipRect(renderer, &s_clip_area);
}

static void disp_drv_flush(disp_drv_t *dev, void *buff, uint32_t buff_format, uint16_t w, uint16_t h)
{
    ACQUIRE_RENDERER(dev);
    Uint32 surf_format = SDL_PIXELFORMAT_RGB565;
    int surf_depth = 16;
    if (buff_format == HAL_GDC_RGBA8888)
    {
        surf_format = SDL_PIXELFORMAT_RGBA8888;
        surf_depth = 32;
    }

    SDL_Surface *surf = SDL_CreateRGBSurfaceWithFormatFrom(buff, w, h, surf_depth, w * (surf_depth >> 3), surf_format);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_Rect dst = {
        .x = s_clip_area.x,
        .y = s_clip_area.y,
        .w = w,
        .h = h,
    };
    SDL_RenderCopy(renderer, tex, NULL, &dst);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);

    if (s_screen_mask_enabled)
    {
        render_screen_mask(renderer);
    }

    SDL_RenderPresent(renderer);

}

static void disp_drv_wait_te(disp_drv_t *dev)
{
    (void)dev;
}

static void disp_drv_wait_to_flush(disp_drv_t *dev)
{
    // Maybe some delay for framerate limitation?
    (void)dev;
}

static void disp_drv_on(disp_drv_t *dev, bool on)
{
    (void)dev;
    (void)on;
}

static void disp_drv_set_brightness(disp_drv_t *dev, uint32_t percent)
{
    (void)dev;
    (void)percent;
}

static void disp_drv_sleep(disp_drv_t *dev)
{
    (void)dev;
}

static void disp_drv_wakeup(disp_drv_t *dev)
{
    (void)dev;
}

static bool tp_drv_init(touchpad_drv_t *dev)
{
    (void)dev;
    return true;
}

static bool tp_drv_deinit(touchpad_drv_t *dev)
{
    (void)dev;
    return true;
}

static bool tp_drv_read_pointer(touchpad_drv_t *dev, int16_t *x, int16_t *y)
{
    int mouse_x;
    int mouse_y;
    Uint32 btn = SDL_GetMouseState(&mouse_x, &mouse_y);
    bool mouse_down = (btn & SDL_BUTTON_LMASK) ? true : false;

    if (mouse_x < 0 || mouse_x > DISP_HOR_RES)
    {
        mouse_down = false;
    }
    else if (mouse_y < 0 || mouse_y > DISP_VER_RES)
    {
        mouse_down = false;
    }

    if (mouse_down)
    {
        *x = (int16_t)mouse_x;
        *y = (int16_t)mouse_y;
    }

    return mouse_down;
}

static bool tp_drv_sleep(touchpad_drv_t *dev)
{
    (void)dev;
    return true;
}

static bool tp_drv_wakeup(touchpad_drv_t *dev)
{
    (void)dev;
    return true;
}

void render_screen_mask(SDL_Renderer * renderer)
{
    // Draw a circular screen mask using Bresenham's Algo
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);

    const int radius = DISP_HOR_RES / 2;
    int x0 = DISP_HOR_RES / 2;
    int y0 = DISP_VER_RES / 2;
    int x = radius;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
        SDL_RenderDrawLine(renderer, x0 + x, y0 + y, DISP_HOR_RES, y0 + y);
        SDL_RenderDrawLine(renderer, x0 + y, y0 + x, DISP_HOR_RES, y0 + x);
        SDL_RenderDrawLine(renderer, x0 + y, y0 - x, DISP_HOR_RES, y0 - x);
        SDL_RenderDrawLine(renderer, x0 + x, y0 - y, DISP_HOR_RES, y0 - y);
        SDL_RenderDrawLine(renderer, x0 - y, y0 + x, 0, y0 + x);
        SDL_RenderDrawLine(renderer, x0 - x, y0 + y, 0, y0 + y);
        SDL_RenderDrawLine(renderer, x0 - x, y0 - y, 0, y0 - y);
        SDL_RenderDrawLine(renderer, x0 - y, y0 - x, 0, y0 - x);

        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}
