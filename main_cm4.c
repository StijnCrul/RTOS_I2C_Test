/*  ____  ____      _    __  __  ____ ___
 * |  _ \|  _ \    / \  |  \/  |/ ___/ _ \
 * | | | | |_) |  / _ \ | |\/| | |  | | | |
 * | |_| |  _ <  / ___ \| |  | | |__| |_| |
 * |____/|_| \_\/_/   \_\_|  |_|\____\___/
 *                           research group
 *                             dramco.be/
 *
 *  KU Leuven - Technology Campus Gent,
 *  Gebroeders De Smetstraat 1,
 *  B-9000 Gent, Belgium
 *
 *         File: main_cm4.c
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: RTOS test project for testing various implementations of technologies. 
 *  Right now I2C, UART, ADC, Blink and RTOS tasks are implemented.
 */

#include "project.h"
#include "FreeRTOS.h"
#include "task.h"
#include "LSM303DLHC.h"
#include "wait.h"
#include "i2c.h"
#include "blink.h"
#include "analog.h"
#include "serial.h"


// Structure for master transfer configuration
cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg =
{
    .slaveAddress = LSM303_ADDRESS_ACCEL,
    .buffer       = NULL,
    .bufferSize   = 0U,
    .xferPending  = false
};

int main(void)
{
    // Enable global interrupts
    __enable_irq(); 
    
    // Configure communication interfaces
    UART_Start();
    initI2C();
    
    // Initialization of all RTOS tasks
    static PIN pin = {TEST_PIN_PORT, TEST_PIN_NUM, 10000};
    static PIN pin2 = {TEST2_PIN_PORT, TEST2_PIN_NUM, 25000};
    static PIN pin3 = {TEST3_PIN_PORT, TEST3_PIN_NUM, 50000};
    xTaskCreate(BlinkTask, "BlinkTask1", 100, (void*) &pin, 1, NULL);
    xTaskCreate(BlinkTask, "BlinkTask2", 100, (void*) &pin2, 1, NULL);
    xTaskCreate(BlinkTask, "BlinkTask3", 100, (void*) &pin3, 1, NULL);
    xTaskCreate(ADCTask, "ADCTask", 100, NULL, 2, NULL);
    xTaskCreate(UARTTask, "UARTTask", 100, NULL, 5, NULL);
    xTaskCreate(acceleroTask, "acceleroTask", 100, (void*) &masterTransferCfg, 6, NULL);
    vTaskStartScheduler(); 
    
    for(;;);
}

/* [] END OF FILE */
