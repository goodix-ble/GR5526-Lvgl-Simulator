# GR5526 LVGL Simulator

[English](./README_en.md) | [中文](./README.md)

## Introduction

**GR5526 LVGL Simulator** is an LVGL simulator built exactly for GR5526 BLE SoC based on a cross-platform library [SDL2](https://www.libsdl.org/).

## Highlights

 - Pixel-perfect simulation of GR5526's GPU feature as well as LVGL porting

    - GR5526 LVGL Simulator featured a software implementation for GR5526's GPU which implements most of the ability.

 - Maximum compatibility with GR5526 SDK, minimum platform-specific code required

    - GR5526 LVGL Simulator works as an extra components to GR5526 SDK, will have nearly no intrusive modification for the original SDK.

## Supported Platforms

 - Windows (x86, x64)
 - Linux (x86, x64)

> The simulator will be built in 32-bit for best compatibility with SoC.



## Requirements

- [GR5526 SDK](https://github.com/goodix-ble/GR5526.SDK) >= 1.0.2

 - [CMake](https://cmake.org/) >= 3.15

 - [Visual Studio](https://visualstudio.microsoft.com/) 2019 or later (mandatory when build with Visual Studio on Windows)

 - [MinGW-W64](https://www.mingw-w64.org/)  (mandatory when build with MinGW-W64 on Windows)

    - [Download](https://nchc.dl.sourceforge.net/project/mingw-w64/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/sjlj/x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0.7z)

 - [GCC](https://gcc.gnu.org/) >=10.2.0 (for Linux build)

   

## Quick Start

Open up a command line and run following commands. Replace `{SDK_Folder}` with the actual path of the GR5526 SDK.

```bash
# Go to the example project folder
cd {SDK_Folder}/projects/peripheral/graphics/graphics_lvgl_831_gpu_demo

# Clone this project into a folder named simulator. Feel free to change the folder name
git clone https://github.com/goodix-ble/GR5526-Lvgl-Simulator.git simulator

cd simulator
mkdir build
cd build

# For Linux user
cmake ..

# For Windows user who uses MinGW-W64
cmake .. -G "MinGW Makefiles"

# For Windows user who uses Visual Studio
cmake .. -G "Visual Studio 16 2019" -A Win32

# Build the project.
cmake --build .

# Run simulator
./GR5526LVGLSimulator.exe
```

After the build process is complete, there will be a executable file located at `build/GR5526LVGLSimulator.exe` folder (`build/Debug/GR5526LVGLSimulator.exe` For Visual Studio users), and it's it.

If you're using Visual Studio, there will be a Visual Studio solution file named `GR5526LVGLSimulator.sln` in the `build` directory after executing `cmake ..`, and you can build and debug with Visual Studio IDE by opening this file.



## Known Issues

1. Error when using Visual Studio: *Debug Error! Run-Time Check Failure #3 - The variable 'transit' is being used without being initialized.*

    This is an issue with GR5526 SDK.
    Workaround: go to `external/lvgl_8.3.1/src/extra/widgets/goodix/tileview/lv_wms_surface_flinger.c:158` and change the code from:

    ```c
    hal_gfx_transition_t transit ;
    ```

    to

    ```c
    hal_gfx_transition_t transit = HAL_GFX_TRANS_NONE;
    ```



2. Log shows *"MENU" is clicked* no matter which menu item is clicked.

    This is due to different default type casting behavior in Visual Studio.
    Workaround: go to `external/lvgl_8.3.1/src/extra/widgets/goodix/gpu_enhanced_menu/lv_enhanced_list.c:312` and change the code from:

    ```c
    if ((y_ofs + icon->header.h) < click_pos.y)
    ```

    to

    ```c
    if ((y_ofs + (lv_coord_t)icon->header.h) < click_pos.y)
    ```