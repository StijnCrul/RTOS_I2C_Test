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

// Initialization of all RTOS tasks and variables
// Structs for is alive blink
static PIN pin0 = {RED_PIN_PORT, RED_PIN_NUM, 10000};
static PIN pin1 = {BLUE_PIN_PORT, BLUE_PIN_NUM, 25000};
static PIN pin2 = {GREEN_PIN_PORT, GREEN_PIN_NUM, 50000};

// Structs for different ADC channels
static CH channel0 = {O_0_PORT, O_0_NUM, 10, 0};
static CH channel1 = {O_1_PORT, O_1_NUM, 20, 1};
static CH channel2 = {O_2_PORT, O_2_NUM, 30, 2};
static CH channel3 = {O_3_PORT, O_3_NUM, 40, 3};

// Structure for master transfer configuration
cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg ={
    .slaveAddress = LSM303_ADDRESS_ACCEL,
    .buffer       = NULL,
    .bufferSize   = 0U,
    .xferPending  = false
};

int main(void){
    // Enable global interrupts
    __enable_irq(); 
    
    // Configure communication interfaces
    //UART_Start();
    initI2C();
    initADC();
    Cy_TCPWM_Counter_Init(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, &ADCSOCCounter_config);
    Cy_TCPWM_Enable_Multiple(ADCSOCCounter_HW, ADCSOCCounter_CNT_MASK);
    
    // Create all the tasks
    xTaskCreate(BlinkTask, "BlinkTask1", 100, (void*) &pin0, 0, NULL);
    xTaskCreate(BlinkTask, "BlinkTask2", 100, (void*) &pin1, 0, NULL);
    xTaskCreate(BlinkTask, "BlinkTask3", 100, (void*) &pin2, 0, NULL);
    
    //xTaskCreate(ADCTask, "ADCTask", 100, NULL, 2, NULL);  
    //xTaskCreate(UARTTask, "UARTTask", 100, NULL, 5, NULL);
    
    // Reduce priority for lower speeds
    xTaskCreate(ADCSampleTask, "ADCSampleTask0", 100, (void*) &channel0, 5, NULL);
    xTaskCreate(ADCSampleTask, "ADCSampleTask1", 100, (void*) &channel1, 5, NULL);
    xTaskCreate(ADCSampleTask, "ADCSampleTask2", 100, (void*) &channel2, 5, NULL);
    xTaskCreate(ADCSampleTask, "ADCSampleTask3", 100, (void*) &channel3, 5, NULL);
   
    
    xTaskCreate(acceleroTask, "acceleroTask", 100, (void*) &masterTransferCfg, 6, NULL);
    vTaskStartScheduler(); 
    
    for(;;);
}

/* [] END OF FILE */
