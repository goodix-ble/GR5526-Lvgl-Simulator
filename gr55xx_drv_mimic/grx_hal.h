#ifndef __GRX_HAL_H__
#define __GRX_HAL_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define GLOBAL_EXCEPTION_DISABLE()
#define GLOBAL_EXCEPTION_ENABLE()

#ifndef __MODULE__
#define __MODULE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif // __MODULE__

#endif // __GRX_HAL_H__