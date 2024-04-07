#include <stdio.h>
#include <assert.h>

void assert_err(const char *condition, const char *file, int line)
{
    printf("[ASSERTION] file:%s, line:%d, expr:%s\n", file, line, condition);
    assert(0);
}

void assert_param(int param0, int param1, const char *file, int line)
{
    printf("[ASSERTION] file:%s, line:%d, param0: 0x%08x, param1: 0x%08x\n", file, line, param0, param1);
    assert(0);
}

void assert_warn(int param0, int param1, const char *file, int line)
{
    printf("[WARNING] file:%s, line:%d, param0: 0x%08x, param1: 0x%08x\n", file, line, param0, param1);
}

void app_log_flush(void)
{
}