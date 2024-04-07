cmake_minimum_required(VERSION 3.15)

project(GR5526LVGLSimulator)

set(CMAKE_C_STANDARD 99)

if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
endif()

# Specify platform and toolchain
if(MSVC)
    set(PLAT_DIR "windows-x86-msvc")
elseif(MINGW)
    set(PLAT_DIR "windows-x86-mingw")
elseif(UNIX)
    set(PLAT_DIR "linux-x86-gcc")
endif()

# Add simulator executable
add_executable(
    GR5526LVGLSimulator
    "main.c"
    "drv_adapter_port_simulator.c"
    "lv_port_simulator.c"
    "gr55xx_drv_mimic/app_rtc.c"
    "gr55xx_drv_mimic/app_graphics_gpu.c"
    "gr55xx_drv_mimic/rom_symbol.c"
    "../Src/lvgl_user_layout/lv_layout_heartrate_chart.c"
    "../Src/lvgl_user_layout/lv_layout_heartrate_statics.c"
    "../Src/lvgl_user_layout/lv_layout_router.c"
    "../Src/lvgl_user_layout/lv_layout_router.h"
    "../Src/lvgl_user_layout/lv_layout_spo2.c"
    "../Src/lvgl_user_layout/lv_layout_stress_chart.c"
    "../Src/lvgl_user_layout/lv_layout_stress_statics.c"
    "../Src/lvgl_user_layout/layout_applist/lv_layout_app_dialer.c"
    "../Src/lvgl_user_layout/layout_applist/lv_layout_app_grid.c"
    "../Src/lvgl_user_layout/layout_applist/lv_layout_app_list.c"
    "../Src/lvgl_user_layout/layout_applist/lv_layout_app_menu.c"
    "../Src/lvgl_user_layout/layout_applist/lv_layout_app_menu.h"
    "../Src/lvgl_user_layout/layout_card/lv_card_day_activity_statics_layout.c"
    "../Src/lvgl_user_layout/layout_card/lv_card_layout_heartrate.c"
    "../Src/lvgl_user_layout/layout_card/lv_card_layout_sleep.c"
    "../Src/lvgl_user_layout/layout_card/lv_card_layout_stress.c"
    "../Src/lvgl_user_layout/layout_card/lv_card_layout_weather.c"
    "../Src/lvgl_user_layout/layout_card/lv_card_list_entry_layout.c"
    "../Src/lvgl_user_layout/layout_card/lv_card_notification_layout.c"
    "../Src/lvgl_user_layout/layout_card/lv_card_status_layout.c"
    "../Src/lvgl_user_layout/layout_card/lv_card_watchface_vivid_clock_layout.c"
    "../Src/lvgl_user_layout/layout_setting/lv_layout_settings_cardflow_style_config.c"
    "../Src/lvgl_user_layout/layout_setting/lv_layout_settings_list_style_config.c"
    "../Src/lvgl_user_layout/layout_setting/lv_layout_settings_power_off.c"
    "../Src/lvgl_user_layout/layout_setting/lv_layout_settings_slide_effect_config.c"
    "../Src/lvgl_user_layout/layout_setting/lv_layout_settings.c"
    "../Src/app/ux_logic/lv_clock_hands_draw.c"
    "../Src/app/ux_logic/mock_data.c"
    "../Src/app/ux_logic/notification_center.c"
    "../Src/lvgl_user_img/lv_img_dsc_list.c"
    "../../../../../external/lvgl_8.3.1/src/font/lv_font_montserrat_20.c"
    "../Src/lvgl_user_font/lv_font_montserrat_26.c"
    "../../../../../external/lvgl_8.3.1/src/font/lv_font_montserrat_30.c"
    "../../../../../external/lvgl_8.3.1/src/font/lv_font_montserrat_36.c"
    "../Src/lvgl_user_font/lv_font_montserrat_48.c"
    "../Src/lvgl_user_font/lv_font_montserrat_48_gdx.c"
    "../Src/lvgl_user_font/lv_font_msyh_26_gr552x.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_disp.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_event.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_group.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_indev.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_indev_scroll.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_obj.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_obj_class.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_obj_draw.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_obj_pos.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_obj_scroll.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_obj_style.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_obj_style_gen.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_obj_tree.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_refr.c"
    "../../../../../external/lvgl_8.3.1/src/core/lv_theme.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_draw.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_draw_arc.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_draw_img.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_draw_label.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_draw_layer.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_draw_line.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_draw_mask.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_draw_rect.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_draw_transform.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_draw_triangle.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_img_buf.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_img_cache.c"
    "../../../../../external/lvgl_8.3.1/src/draw/lv_img_decoder.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_arc.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_blend.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_dither.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_gradient.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_img.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_layer.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_letter.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_line.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_polygon.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_rect.c"
    "../../../../../external/lvgl_8.3.1/src/draw/sw/lv_draw_sw_transform.c"
    "../../../../../external/lvgl_8.3.1/src/draw/gr5526_gpu/lv_gpu_gr5526.c"
    "../../../../../external/lvgl_8.3.1/src/extra/layouts/flex/lv_flex.c"
    "../../../../../external/lvgl_8.3.1/src/extra/layouts/grid/lv_grid.c"
    "../../../../../external/lvgl_8.3.1/src/extra/themes/basic/lv_theme_basic.c"
    "../../../../../external/lvgl_8.3.1/src/extra/themes/default/lv_theme_default.c"
    "../../../../../external/lvgl_8.3.1/src/extra/themes/mono/lv_theme_mono.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/animimg/lv_animimg.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/calendar/lv_calendar.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/calendar/lv_calendar_header_arrow.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/calendar/lv_calendar_header_dropdown.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/chart/lv_chart.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/colorwheel/lv_colorwheel.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/imgbtn/lv_imgbtn.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/keyboard/lv_keyboard.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/led/lv_led.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/list/lv_list.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/menu/lv_menu.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/meter/lv_meter.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/msgbox/lv_msgbox.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/span/lv_span.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/spinbox/lv_spinbox.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/spinner/lv_spinner.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/tabview/lv_tabview.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/tileview/lv_tileview.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/tileview/lv_fast_tileview.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/win/lv_win.c"
    "../../../../../external/lvgl_8.3.1/src/extra/lv_extra.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/goodix/tileview/lv_wms_tileview.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/goodix/tileview/lv_wms_surface_flinger.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/goodix/anim/lv_enhanced_anim.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/goodix/gpu_enhanced_menu/lv_enhanced_grid.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/goodix/gpu_enhanced_menu/lv_enhanced_list.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/goodix/gpu_scrollbar/lv_enhanced_scrollbar.c"
    "../../../../../external/lvgl_8.3.1/src/extra/themes/simplify/lv_theme_simplify.c"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/goodix/gpu_enhanced_menu/lv_circular_list.c"
    "../../../../../external/lvgl_8.3.1/src/font/lv_font.c"
    "../../../../../external/lvgl_8.3.1/src/font/lv_font_fmt_txt.c"
    "../../../../../external/lvgl_8.3.1/src/font/lv_font_loader.c"
    "../../../../../external/lvgl_8.3.1/src/hal/lv_hal_disp.c"
    "../../../../../external/lvgl_8.3.1/src/hal/lv_hal_indev.c"
    "../../../../../external/lvgl_8.3.1/src/hal/lv_hal_tick.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_anim.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_anim_timeline.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_area.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_async.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_bidi.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_color.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_fs.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_gc.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_ll.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_log.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_lru.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_math.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_mem.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_printf.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_style.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_style_gen.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_templ.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_timer.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_tlsf.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_txt.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_txt_ap.c"
    "../../../../../external/lvgl_8.3.1/src/misc/lv_utils.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_arc.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_bar.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_btn.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_btnmatrix.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_canvas.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_checkbox.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_dropdown.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_img.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_label.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_line.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_objx_templ.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_roller.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_slider.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_switch.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_table.c"
    "../../../../../external/lvgl_8.3.1/src/widgets/lv_textarea.c"
    "../../../../../components/graphics/lvgl_port/lv_port_disp/lv_port_disp.c"
    "../../../../../components/graphics/lvgl_port/lv_port_indev/lv_port_indev.c"
    "../../../../../components/graphics/lvgl_port/drv_adapter/drv_adapter_display.c"
    "../../../../../components/graphics/lvgl_port/drv_adapter/drv_adapter_norflash.c"
    "../../../../../components/graphics/lvgl_port/drv_adapter/drv_adapter_touchpad.c"
    "../../../../../components/graphics/lvgl_port/drv_adapter/drv_adapter_display.c"
    "../../../../../components/libraries/app_graphics_mem/app_graphics_mem.c"
)

target_include_directories(
    GR5526LVGLSimulator
    PRIVATE
    "."
    "gr55xx_drv_mimic"
    "../Src/lvgl_user_font"
    "../Src/lvgl_user_font"
    "../Src/lvgl_user_img"
    "../Src/lvgl_user_layout"
    "../Src/lvgl_user_layout/layout_applist"
    "../Src/lvgl_user_layout/layout_card"
    "../Src/lvgl_user_layout/layout_setting"
    "../Src/app/ux_logic/"
    "../Src/config"
    "../../../../../components/libraries/app_graphics_mem"
    "../../../../../external/lvgl_8.3.1/src"
    "../../../../../external/lvgl_8.3.1/src/core"
    "../../../../../external/lvgl_8.3.1/src/draw"
    "../../../../../external/lvgl_8.3.1/src/extra"
    "../../../../../external/lvgl_8.3.1/src/extra/layouts"
    "../../../../../external/lvgl_8.3.1/src/extra/layouts/flex"
    "../../../../../external/lvgl_8.3.1/src/extra/layouts/grid"
    "../../../../../external/lvgl_8.3.1/src/extra/libs"
    "../../../../../external/lvgl_8.3.1/src/extra/libs/bmp"
    "../../../../../external/lvgl_8.3.1/src/extra/libs/freetype"
    "../../../../../external/lvgl_8.3.1/src/extra/libs/fsdrv"
    "../../../../../external/lvgl_8.3.1/src/extra/libs/gif"
    "../../../../../external/lvgl_8.3.1/src/extra/libs/png"
    "../../../../../external/lvgl_8.3.1/src/extra/libs/qrcode"
    "../../../../../external/lvgl_8.3.1/src/extra/libs/rlottie"
    "../../../../../external/lvgl_8.3.1/src/extra/libs/sjpg"
    "../../../../../external/lvgl_8.3.1/src/extra/others"
    "../../../../../external/lvgl_8.3.1/src/extra/others/snapshot"
    "../../../../../external/lvgl_8.3.1/src/extra/themes"
    "../../../../../external/lvgl_8.3.1/src/extra/themes/basic"
    "../../../../../external/lvgl_8.3.1/src/extra/themes/default"
    "../../../../../external/lvgl_8.3.1/src/extra/themes/mono"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/animimg"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/calendar"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/chart"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/colorwheel"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/imgbtn"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/keyboard"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/led"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/list"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/meter"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/msgbox"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/span"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/spinbox"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/spinner"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/tabview"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/tileview"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/win"
    "../../../../../external/lvgl_8.3.1/src/font"
    "../../../../../external/lvgl_8.3.1/src/misc"
    "../../../../../external/lvgl_8.3.1/src/widgets"
    "../../../../../external/lvgl_8.3.1/src/hal"
    "../../../../../external/lvgl_8.3.1/src/gpu"
    "../../../../../external/lvgl_8.3.1/src/gpu/goodix"
    "../../../../../external/lvgl_8.3.1"
    "../../../../../external/lvgl_8.3.1/src/widgets_gdx/anim_ex"
    "../../../../../external/lvgl_8.3.1/src/widgets_gdx/surface_flinger"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/goodix/tileview"
    "../../../../../external/lvgl_8.3.1/src/gpu/gr552x/porting"
    "../../../../../external/lvgl_8.3.1/src/draw/sw"
    "../../../../../external/lvgl_8.3.1/src/draw/gr5526_gpu"
    "../../../../../external/lvgl_8.3.1/src/extra/widgets/goodix/gpu_enhanced_menu"
    "../../../../../components/graphics/gfx/common/"
    "../../../../../components/graphics/gfx/common/mem"
    "../../../../../components/graphics/gfx/configure"
    "../../../../../components/graphics/gfx/include"
    "../../../../../components/graphics/gfx/include/tsi"
    "../../../../../components/graphics/gfx/include/tsi/common"
    "../../../../../components/graphics/gfx/include/tsi/hal_gdc"
    "../../../../../components/graphics/gfx/include/tsi/hal_gfx"
    "../../../../../components/graphics/gfx/hal_gdc"
    "../../../../../components/graphics/gfx/hal_gfx"
    "../../../../../components/graphics/gfx/porting"
    "../../../../../components/graphics/lvgl_port/lv_port_disp"
    "../../../../../components/graphics/lvgl_port/drv_adapter"
    "../../../../../components/graphics/lvgl_port/lv_port_indev"
    "../../../../../components/graphics/lvgl_port/lv_port_gr5526"
)

# Global definitions from MDK project
target_compile_definitions(GR5526LVGLSimulator PRIVATE LVGL_FRAMEBUFFER_SIZE=16 USE_OSAL)

# Acquire binary resource file path
# External Flash is simulated as a binary file copied into a pre-allocated buffer
file(REAL_PATH "${CMAKE_CURRENT_LIST_DIR}/../Image_Resource/0x0000_2023-06-06_17-38-37.bin" default_binary_resource_file)
target_compile_definitions(GR5526LVGLSimulator PRIVATE DEFAULT_BINARY_RESOURCE_FILE_PATH="${default_binary_resource_file}")

# Add simulator dependencies. These libraries are software-emulated GR5526 GPU
target_link_directories(GR5526LVGLSimulator PRIVATE "${CMAKE_CURRENT_LIST_DIR}/gr5526_sim_lib/${PLAT_DIR}")
target_link_libraries(
    GR5526LVGLSimulator
    PRIVATE
    graphics_lvgl_v831_lib_sim
    graphics_sdk_sim
)

# Add SDL2 dependencies. SDL2 is for basic window creation and mouse/keyboard IO handling
target_include_directories(GR5526LVGLSimulator PRIVATE "${CMAKE_CURRENT_LIST_DIR}/SDL2/include")
target_link_directories(GR5526LVGLSimulator PRIVATE "${CMAKE_CURRENT_LIST_DIR}/SDL2/lib/${PLAT_DIR}")
target_link_libraries(
    GR5526LVGLSimulator
    PRIVATE
    SDL2
    SDL2main
)

# Add math library dependency if using GCC
if(CMAKE_COMPILER_IS_GNUCC)
    target_link_libraries(
    GR5526LVGLSimulator
    PRIVATE
    m
)
endif()

# Copy SDL2.dll or libSDL2.so to output directory after build
if(WIN32)
set(SDL2_SHARED_LIB "SDL2.dll")
else()
set(SDL2_SHARED_LIB "libSDL2.so")
endif()

add_custom_command(
    TARGET GR5526LVGLSimulator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_LIST_DIR}/SDL2/lib/${PLAT_DIR}/${SDL2_SHARED_LIB}"
    $<TARGET_FILE_DIR:GR5526LVGLSimulator>
)

# Some platform-specific parameters
if(MSVC)
    target_compile_options(
        GR5526LVGLSimulator
        PRIVATE
        "/utf-8"           # add UTF-8 support
        "/FI attr_macro.h" # Force include a header file to handle all unsupported __attribute__
    )
    # Weak symbol in library
    target_link_options(
        GR5526LVGLSimulator
        PRIVATE
        "/ALTERNATENAME:_lv_port_get_current_cl=__lv_port_get_current_cl_internal"
        "/ALTERNATENAME:_lv_port_get_fb_format=__lv_port_get_fb_format_internal"
        "/ALTERNATENAME:_lv_port_set_fb_format=__lv_port_set_fb_format_internal"
        "/ALTERNATENAME:_lv_port_gpu_fill_bg=__lv_port_gpu_fill_bg_internal"
    )
elseif(MINGW)
    target_sources(GR5526LVGLSimulator PRIVATE "gr55xx_drv_mimic/lv_gpu_draw_utils.c")
endif()
