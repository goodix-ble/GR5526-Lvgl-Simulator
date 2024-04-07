#ifndef __OSAL_H__
#define __OSAL_H__

#include <stdlib.h>
#include <SDL.h>

#define osal_heap_malloc(size) malloc(size)
#define osal_heap_free(ptr) free(ptr)

#define osal_enter_critical()
#define osal_exit_critical()

#define osal_task_get_tick_count() SDL_GetTicks()

#endif // __OSAL_H__