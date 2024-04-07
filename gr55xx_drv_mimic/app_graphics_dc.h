#ifndef __APP_GRAPHICS_DC_H__
#define __APP_GRAPHICS_DC_H__

#include "gr55xx.h"
#include "hal_gdc.h"

/**
  * @brief Define the data format for frame buffer of DC
  */
typedef enum {
    GDC_DATA_FORMAT_RGB565      = HAL_GDC_RGB565,    /**< FrameBuffer is RGA565,   16bit, no Alpha  */
    GDC_DATA_FORMAT_RGB24       = HAL_GDC_RGB24,     /**< FrameBuffer is RGA24,    24bit, no Alpha  */
    GDC_DATA_FORMAT_RGBA8888    = HAL_GDC_RGBA8888,  /**< FrameBuffer is RGBA8888, 32bit with Alpha */
    GDC_DATA_FORMAT_ABGR8888    = HAL_GDC_ABGR8888,  /**< FrameBuffer is ABGR8888, 32bit with Alpha */
    GDC_DATA_FORMAT_ARGB8888    = HAL_GDC_ARGB8888,  /**< FrameBuffer is ARGB8888, 32bit with Alpha */
    GDC_DATA_FORMAT_BGRA8888    = HAL_GDC_BGRA8888,  /**< FrameBuffer is BGRA8888, 32bit with Alpha */
    GDC_DATA_FORMAT_TSC4        = HAL_GDC_TSC4,      /**< FrameBuffer is RGB565 compressed by TSC4  */
    GDC_DATA_FORMAT_TSC6        = HAL_GDC_TSC6,      /**< FrameBuffer is *888 compressed by TSC6  */
    GDC_DATA_FORMAT_TSC6A       = HAL_GDC_TSC6A,     /**< FrameBuffer is *8888 compressed by TSC6A  */
} graphics_dc_data_format_e;


#endif // __APP_GRAPHICS_DC_H__