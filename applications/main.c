/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-02     RT-Thread    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"

#define LED_PIN GET_PIN(O, 5)

#define THREAD_STACK_SIZE 1024
#define THREAD_PRIORITY   20
#define THREAD_TIMESLICE  5

static rt_thread_t hid_thread = RT_NULL;

static void hid_mouse_thread_entry(void *parameter)
{
    rt_kprintf("USB HID Mouse thread started\n");
    while (1)
    {
        extern void hid_mouse_test(uint8_t busid);
        hid_mouse_test(0);
    }
}

int main(void)
{
    hid_thread = rt_thread_create("hid_mouse", hid_mouse_thread_entry,
    RT_NULL, THREAD_STACK_SIZE, THREAD_PRIORITY, THREAD_TIMESLICE);
    if (hid_thread != RT_NULL)
    {
        rt_thread_startup(hid_thread);
    }
    rt_uint32_t count = 1;

    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);

    while (count++)
    {
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
    }
    return RT_EOK;
}

#include "stm32h7rsxx.h"
static int vtor_config(void)
{
    /* Vector Table Relocation in Internal XSPI2_BASE */
    SCB->VTOR = XSPI2_BASE;
    return 0;
}
INIT_BOARD_EXPORT(vtor_config);

