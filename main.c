#include "lv_port_simulator.h"
#include "lv_layout_router.h"

#include "mock_data.h"

#include <stdio.h>
#include <stdbool.h>

#ifndef DEFAULT_BINARY_RESOURCE_FILE_PATH
#define DEFAULT_BINARY_RESOURCE_FILE_PATH "/foo/bar"
#endif // DEFAULT_BINARY_RESOURCE_FILE_PATH

static void lvgl_env_init(const char *binary_resource_file);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    char *binary_resource_file = DEFAULT_BINARY_RESOURCE_FILE_PATH;
    if (argc >= 2)
    {
        binary_resource_file = argv[1];
    }

    mock_data_init_pre_gui();

    lvgl_env_init(binary_resource_file);
    lv_layout_router_init();

    mock_data_init_post_gui();

    bool running = true;

    while (running)
    {
        running = lvgl_main_loop();
    }

    return 0;
}

static void lvgl_env_init(const char *binary_resource_file)
{
    lvgl_port_init(binary_resource_file);
}
