/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-07-29     RealThread   first version
 */

#include "board.h"

#define DBG_TAG "board"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#ifdef RT_USING_INDEPENDENT_INTERRUPT_MANAGEMENT
#define RT_NVIC_PRO_BITS    __NVIC_PRIO_BITS

rt_base_t rt_hw_interrupt_disable(void)
{
    rt_base_t level = __get_BASEPRI();
    __set_BASEPRI(RT_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - RT_NVIC_PRO_BITS));

    __ISB();
    __DSB();

    return level;
}

void rt_hw_interrupt_enable(rt_base_t level)
{
    __set_BASEPRI(level);
}
#endif /* RT_USING_INDEPENDENT_INTERRUPT_MANAGEMENT */

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
    return;
}

void usb_dc_low_level_init(uint8_t busid)
{
    RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USBPHYC;
    PeriphClkInit.UsbPhycClockSelection = RCC_USBPHYCCLKSOURCE_HSE;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
        Error_Handler();
    }
    HAL_PWREx_EnableUSBVoltageDetector();
    __HAL_RCC_USB_OTG_HS_CLK_ENABLE()
    ;
    __HAL_RCC_USBPHYC_CLK_ENABLE()
    ;
    HAL_NVIC_SetPriority(OTG_HS_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(OTG_HS_IRQn);
}

void OTG_HS_IRQHandler(void)
{
    extern void USBD_IRQHandler(uint8_t busid);
    USBD_IRQHandler(0);
}

int usbd_init(void)
{
    extern void hid_mouse_init(uint8_t busid, uintptr_t reg_base);
    hid_mouse_init(0, USB_OTG_HS_PERIPH_BASE);
    return 0;
}

INIT_APP_EXPORT(usbd_init);
