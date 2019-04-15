/*******************************************************************************
* File Name: cyfitter_gpio.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_GPIO_H
#define INCLUDED_CYFITTER_GPIO_H
#include "cy_device_headers.h"

/* A0 */
#define A0_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define A0_0_INBUF_ENABLED 0u
#define A0_0_INIT_DRIVESTATE 1u
#define A0_0_INIT_MUXSEL 0u
#define A0_0_INPUT_SYNC 2u
#define A0_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define A0_0_NUM 0u
#define A0_0_PORT GPIO_PRT10
#define A0_0_SLEWRATE CY_GPIO_SLEW_FAST
#define A0_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define A0_DRIVEMODE CY_GPIO_DM_ANALOG
#define A0_INBUF_ENABLED 0u
#define A0_INIT_DRIVESTATE 1u
#define A0_INIT_MUXSEL 0u
#define A0_INPUT_SYNC 2u
#define A0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define A0_NUM 0u
#define A0_PORT GPIO_PRT10
#define A0_SLEWRATE CY_GPIO_SLEW_FAST
#define A0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* UART_rx */
#define UART_rx_0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define UART_rx_0_INBUF_ENABLED 1u
#define UART_rx_0_INIT_DRIVESTATE 1u
#define UART_rx_0_INIT_MUXSEL 18u
#define UART_rx_0_INPUT_SYNC 2u
#define UART_rx_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_rx_0_NUM 0u
#define UART_rx_0_PORT GPIO_PRT5
#define UART_rx_0_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_rx_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define UART_rx_DRIVEMODE CY_GPIO_DM_HIGHZ
#define UART_rx_INBUF_ENABLED 1u
#define UART_rx_INIT_DRIVESTATE 1u
#define UART_rx_INIT_MUXSEL 18u
#define UART_rx_INPUT_SYNC 2u
#define UART_rx_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_rx_NUM 0u
#define UART_rx_PORT GPIO_PRT5
#define UART_rx_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_rx_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* UART_tx */
#define UART_tx_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define UART_tx_0_INBUF_ENABLED 0u
#define UART_tx_0_INIT_DRIVESTATE 1u
#define UART_tx_0_INIT_MUXSEL 18u
#define UART_tx_0_INPUT_SYNC 2u
#define UART_tx_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_tx_0_NUM 1u
#define UART_tx_0_PORT GPIO_PRT5
#define UART_tx_0_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_tx_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define UART_tx_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define UART_tx_INBUF_ENABLED 0u
#define UART_tx_INIT_DRIVESTATE 1u
#define UART_tx_INIT_MUXSEL 18u
#define UART_tx_INPUT_SYNC 2u
#define UART_tx_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_tx_NUM 1u
#define UART_tx_PORT GPIO_PRT5
#define UART_tx_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_tx_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* TEST_PIN */
#define TEST_PIN_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define TEST_PIN_0_INBUF_ENABLED 0u
#define TEST_PIN_0_INIT_DRIVESTATE 0u
#define TEST_PIN_0_INIT_MUXSEL 0u
#define TEST_PIN_0_INPUT_SYNC 2u
#define TEST_PIN_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define TEST_PIN_0_NUM 3u
#define TEST_PIN_0_PORT GPIO_PRT0
#define TEST_PIN_0_SLEWRATE CY_GPIO_SLEW_FAST
#define TEST_PIN_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define TEST_PIN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define TEST_PIN_INBUF_ENABLED 0u
#define TEST_PIN_INIT_DRIVESTATE 0u
#define TEST_PIN_INIT_MUXSEL 0u
#define TEST_PIN_INPUT_SYNC 2u
#define TEST_PIN_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define TEST_PIN_NUM 3u
#define TEST_PIN_PORT GPIO_PRT0
#define TEST_PIN_SLEWRATE CY_GPIO_SLEW_FAST
#define TEST_PIN_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* mI2C_scl */
#define mI2C_scl_0_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define mI2C_scl_0_INBUF_ENABLED 1u
#define mI2C_scl_0_INIT_DRIVESTATE 1u
#define mI2C_scl_0_INIT_MUXSEL 19u
#define mI2C_scl_0_INPUT_SYNC 2u
#define mI2C_scl_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define mI2C_scl_0_NUM 0u
#define mI2C_scl_0_PORT GPIO_PRT6
#define mI2C_scl_0_SLEWRATE CY_GPIO_SLEW_FAST
#define mI2C_scl_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define mI2C_scl_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define mI2C_scl_INBUF_ENABLED 1u
#define mI2C_scl_INIT_DRIVESTATE 1u
#define mI2C_scl_INIT_MUXSEL 19u
#define mI2C_scl_INPUT_SYNC 2u
#define mI2C_scl_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define mI2C_scl_NUM 0u
#define mI2C_scl_PORT GPIO_PRT6
#define mI2C_scl_SLEWRATE CY_GPIO_SLEW_FAST
#define mI2C_scl_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* mI2C_sda */
#define mI2C_sda_0_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define mI2C_sda_0_INBUF_ENABLED 1u
#define mI2C_sda_0_INIT_DRIVESTATE 1u
#define mI2C_sda_0_INIT_MUXSEL 19u
#define mI2C_sda_0_INPUT_SYNC 2u
#define mI2C_sda_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define mI2C_sda_0_NUM 1u
#define mI2C_sda_0_PORT GPIO_PRT6
#define mI2C_sda_0_SLEWRATE CY_GPIO_SLEW_FAST
#define mI2C_sda_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define mI2C_sda_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define mI2C_sda_INBUF_ENABLED 1u
#define mI2C_sda_INIT_DRIVESTATE 1u
#define mI2C_sda_INIT_MUXSEL 19u
#define mI2C_sda_INPUT_SYNC 2u
#define mI2C_sda_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define mI2C_sda_NUM 1u
#define mI2C_sda_PORT GPIO_PRT6
#define mI2C_sda_SLEWRATE CY_GPIO_SLEW_FAST
#define mI2C_sda_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* TEST2_PIN */
#define TEST2_PIN_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define TEST2_PIN_0_INBUF_ENABLED 0u
#define TEST2_PIN_0_INIT_DRIVESTATE 0u
#define TEST2_PIN_0_INIT_MUXSEL 0u
#define TEST2_PIN_0_INPUT_SYNC 2u
#define TEST2_PIN_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define TEST2_PIN_0_NUM 1u
#define TEST2_PIN_0_PORT GPIO_PRT11
#define TEST2_PIN_0_SLEWRATE CY_GPIO_SLEW_FAST
#define TEST2_PIN_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define TEST2_PIN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define TEST2_PIN_INBUF_ENABLED 0u
#define TEST2_PIN_INIT_DRIVESTATE 0u
#define TEST2_PIN_INIT_MUXSEL 0u
#define TEST2_PIN_INPUT_SYNC 2u
#define TEST2_PIN_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define TEST2_PIN_NUM 1u
#define TEST2_PIN_PORT GPIO_PRT11
#define TEST2_PIN_SLEWRATE CY_GPIO_SLEW_FAST
#define TEST2_PIN_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* TEST3_PIN */
#define TEST3_PIN_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define TEST3_PIN_0_INBUF_ENABLED 0u
#define TEST3_PIN_0_INIT_DRIVESTATE 0u
#define TEST3_PIN_0_INIT_MUXSEL 0u
#define TEST3_PIN_0_INPUT_SYNC 2u
#define TEST3_PIN_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define TEST3_PIN_0_NUM 1u
#define TEST3_PIN_0_PORT GPIO_PRT1
#define TEST3_PIN_0_SLEWRATE CY_GPIO_SLEW_FAST
#define TEST3_PIN_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define TEST3_PIN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define TEST3_PIN_INBUF_ENABLED 0u
#define TEST3_PIN_INIT_DRIVESTATE 0u
#define TEST3_PIN_INIT_MUXSEL 0u
#define TEST3_PIN_INPUT_SYNC 2u
#define TEST3_PIN_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define TEST3_PIN_NUM 1u
#define TEST3_PIN_PORT GPIO_PRT1
#define TEST3_PIN_SLEWRATE CY_GPIO_SLEW_FAST
#define TEST3_PIN_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

#endif /* INCLUDED_CYFITTER_GPIO_H */