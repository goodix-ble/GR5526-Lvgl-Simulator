#ifndef __APP_RTC_H__
#define __APP_RTC_H__

#include <stdint.h>

typedef struct
{
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t date;
    uint8_t mon;
    uint8_t year;
    uint8_t week;
    uint16_t ms;
} app_rtc_time_t;

uint16_t app_rtc_get_time(app_rtc_time_t *p_time);

#endif // __APP_RTC_H__