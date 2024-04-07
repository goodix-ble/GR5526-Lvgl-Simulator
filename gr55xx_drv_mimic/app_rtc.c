#include "app_rtc.h"

#include <time.h>

uint16_t app_rtc_get_time(app_rtc_time_t *p_time)
{
    time_t timestamp;
    struct tm *stm;
    time(&timestamp);
    stm = localtime(&timestamp);

    if (p_time)
    {
        p_time->year = stm->tm_year;
        p_time->mon  = stm->tm_mon;
        p_time->date = stm->tm_mday;
        p_time->week = stm->tm_wday;
        p_time->hour = stm->tm_hour;
        p_time->min  = stm->tm_min;
        p_time->sec  = stm->tm_sec;
    }

    return 0;
}
