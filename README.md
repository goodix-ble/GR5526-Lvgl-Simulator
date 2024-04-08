# GR5526 LVGL Simulator

[English](./README_en.md) | [中文](./README.md)



## 简介

**GR5526 LVGL Simulator**是一个专为GR5526 BLE SoC构建的LVGL模拟器，基于跨平台的[SDL2](https://www.libsdl.org/)构建。



## 亮点

 - 对GR5526 GPU功能与LVGL移植的像素级模拟

    - GR5526 LVGL Simulator集成了针对GR5526 GPU的软实现，实现了绝大部分功能。

 - 与GR5526 SDK高度兼容，最小限度的平台专用代码

    - GR5526 LVGL Simulator将作为GR5526 SDK的一个外挂组件来工作，对原始SDK几乎没有侵入性修改。



## 支持平台

 - Windows (x86, x64)
 - Linux (x86, x64)

> 为了与SoC兼容性最佳，该模拟器将永远以32位构建。



## 软件要求

 - [GR5526 SDK](https://github.com/goodix-ble/GR5526.SDK) >= 1.0.2
 - [CMake](https://cmake.org/) >= 3.15
 - [Visual Studio](https://visualstudio.microsoft.com/) 2019 or later (在Windows上使用Visual Studio构建时必须)
 - [MinGW-W64](https://www.mingw-w64.org/)  (在Windows上使用MinGW build构建时必须)
    - [Download](https://nchc.dl.sourceforge.net/project/mingw-w64/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/sjlj/x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0.7z)
 - [GCC](https://gcc.gnu.org/) >=10.2.0 (Linux上构建时必须)




## 快速开始

打开命令行并运行以下命令，将`{SDK_Folder}`替换为GR5526 SDK的实际路径：

```bash
# Go to the example project folder
cd {SDK_Folder}/projects/peripheral/graphics/graphics_lvgl_831_gpu_demo

# Clone this project into a folder named simulator. Feel free to change the folder name
git clone https://github.com/goodix-ble/GR5526-Lvgl-Simulator.git simulator

cd simulator
mkdir build
cd build

# 在Linux下
cmake ..

# 在Windows下使用MinGW-W64
cmake .. -G "MinGW Makefiles"

# 在Windows下使用Visual Studio
cmake .. -G "Visual Studio 16 2019" -A Win32

# 构建工程
cmake --build .

# 运行模拟器
./GR5526LVGLSimulator.exe

```

构建过程完成后，将在`build/GR5526LVGLSimulator.exe`文件夹中找到可执行文件（对于 Visual Studio用户，在`build/Debug/GR5526LVGLSimulator.exe`文件夹中）。

如果您使用的是Visual Studio，在执行`cmake ..`后，将在`build`目录中生成名为`GR5526LVGLSimulator.sln`的Visual Studio解决方案文件，用户可以通过打开此文件在Visual Studio IDE中构建和调试。



## 已知问题

1. 使用Visual Studio构建的模拟器时报错: *Debug Error! Run-Time Check Failure #3 - The variable 'transit' is being used without being initialized.*

   这是一个GR5526 SDK的问题。
   Workaround: 找到源文件`external/lvgl_8.3.1/src/extra/widgets/goodix/tileview/lv_wms_surface_flinger.c:158` 并将代码从：

    ```c
    hal_gfx_transition_t transit ;
    ```

    ​	改为

    ```c
    hal_gfx_transition_t transit = HAL_GFX_TRANS_NONE;
    ```



2. 使用Visual Studio构建的模拟器时，无论点击哪个菜单项日志都打印*"MENU" is clicked*。

   这是Visual Studio中不同的默认类型转换行为引起的。
   Workaround: 找到源文件`external/lvgl_8.3.1/src/extra/widgets/goodix/gpu_enhanced_menu/lv_enhanced_list.c:312` 并将代码从:

    ```c
    if ((y_ofs + icon->header.h) < click_pos.y)
    ```

	改为

    ```c
    if ((y_ofs + (lv_coord_t)icon->header.h) < click_pos.y)
    ```


