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
 *         File: analog.h
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: ADC library for reading the ADC on a PSOC 6 development kit using an RTOS task
 */
#ifndef __ANALOG__
#define __ANALOG__
    
#include "project.h"
#include "FreeRTOS.h"
#include "task.h"
    
    // Struct for passing measurment variables to the RTOS task.
    typedef struct {
        GPIO_PRT_Type* port;
        unsigned int pin;
        TickType_t timing;
        uint8_t channel;
    } CH;
    
    // VARIABLES
    static int16_t result;
    static uint8_t dataReady;
    
    // PROTOTYPING
    void initADC();
    void ADCTask();
    void ADCSampleTask(void * pvPin);
    void ADCDMAInit(void);
    void ADC_ISR_Callback(void);
    
    
#endif
    