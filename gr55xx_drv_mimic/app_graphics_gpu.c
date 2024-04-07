#include "hal_gfx_cmdlist.h"
#include "hal_gfx_graphics.h"
#include "app_graphics_gpu.h"

#include <stdio.h>

void app_graphics_gpu_sim_init(void)
{
    hal_gfx_init();
}

hal_gfx_cmdlist_t hal_gfx_cl_le_create(void)
{
    return hal_gfx_cl_create();
}

void hal_gfx_cl_le_destroy(hal_gfx_cmdlist_t *cl)
{
    return hal_gfx_cl_destroy(cl);
}

int hal_gfx_mutex_lock(int mutex_id)
{
    return 0;
}

int hal_gfx_mutex_unlock(int mutex_id)
{
    return 0;
}

// Following for test only, please remove before release
#include "graphics_sys_defs.h"
#include "hal_gfx_error.h"
#include "hal_gfx_error_intern.h"

#ifdef USE_TSI_MALLOC
#include "tsi_malloc.h"
#endif

static hal_gfx_ringbuffer_t g_nema_rb = {{0}};
static uint8_t s_graphics_memory_buffer[VMEM_SIZE];

int32_t hal_gfx_sys_init(void)
{
    int32_t ret = 0;

#ifdef USE_TSI_MALLOC
    // Map and initialize Graphics Memory
    tsi_malloc_init((void *)VMEM_BASEADDR, VMEM_BASEADDR, VMEM_SIZE, 1);
#endif

    g_nema_rb.bo = hal_gfx_buffer_create(HAL_GFX_RING_BUFFER_SIZE);
    hal_gfx_buffer_map(&g_nema_rb.bo);

    // ret = hal_gfx_rb_init(&g_nema_rb, 1);

    return ret;
}

void *hal_gfx_buffer_map(hal_gfx_buffer_t *bo)
{
    if (bo == NULL)
    {
        hal_gfx_set_error(HAL_GFX_ERR_INVALID_BO);
        return NULL;
    }
    return bo->base_virt;
}

void hal_gfx_buffer_unmap(hal_gfx_buffer_t *bo)
{
}

// uint32_t hal_gfx_reg_read(uint32_t reg)
// {
//     return 0;
// }

// void hal_gfx_reg_write(uint32_t reg, uint32_t value)
// {
//     printf("Write 0x%08x to offset 0x%x\n", value, reg);
// }


void hal_gfx_buffer_flush(hal_gfx_buffer_t *bo)
{
}

void hal_gfx_buffer_destroy(hal_gfx_buffer_t *bo)
{
    if (bo == NULL)
    {
        hal_gfx_set_error(HAL_GFX_ERR_INVALID_BO);
        return;
    }
    hal_gfx_mutex_lock(MUTEX_MALLOC);

#ifdef USE_TSI_MALLOC
    tsi_free(bo->base_virt);
#else
    free(bo->base_virt);
#endif

    bo->base_virt = (void *)NULL;
    bo->base_phys = 0;
    bo->size = 0;
    bo->fd = -1;

    hal_gfx_mutex_unlock(MUTEX_MALLOC);
}

void *hal_gfx_host_malloc(size_t size)
{
    hal_gfx_mutex_lock(MUTEX_MALLOC);

#ifdef USE_TSI_MALLOC
    void *ptr = tsi_malloc(size);
#else
    void *ptr = malloc(size);
#endif

    hal_gfx_mutex_unlock(MUTEX_MALLOC);
    return ptr;
}

void hal_gfx_host_free(void *ptr)
{
    hal_gfx_mutex_lock(MUTEX_MALLOC);

#ifdef USE_TSI_MALLOC
    tsi_free(ptr);
#else
    free(ptr);
#endif

    hal_gfx_mutex_unlock(MUTEX_MALLOC);
}

hal_gfx_buffer_t hal_gfx_buffer_create_pool(int pool, int size)
{
    return hal_gfx_buffer_create(size);
}


hal_gfx_buffer_t hal_gfx_buffer_create(int size)
{
    hal_gfx_mutex_lock(MUTEX_MALLOC);

    hal_gfx_buffer_t bo;
#ifdef USE_TSI_MALLOC
    bo.base_virt = tsi_malloc((size_t)size);
#else
    bo.base_virt = malloc((size_t)size);
#endif

    bo.base_phys = (uintptr_t)(bo.base_virt);
    bo.size = size;
    bo.fd = 0;

    hal_gfx_mutex_unlock(MUTEX_MALLOC);
    return bo;
}

int hal_gfx_wait_irq_cl(int cl_id)
{
    return 0;
}
