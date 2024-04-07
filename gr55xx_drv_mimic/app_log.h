#ifndef __APP_LOG_H__
#define __APP_LOG_H__

#include <stdio.h>

#define APP_LOG_ERROR(...) printf("[APP_ERR]: " __VA_ARGS__)
#define APP_LOG_WARNING(...) printf("[APP_WARN]: " __VA_ARGS__)
#define APP_LOG_INFO(...) printf("[APP_INFO]: " __VA_ARGS__)
#define APP_LOG_DEBUG(...) printf("[APP_DBG]: " __VA_ARGS__)

#endif // __APP_LOG_H__