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
    
    // CONSTANTS
    #define BUFFER_SIZE 1024
    
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
    
    int32_t buffer0[BUFFER_SIZE];
    int32_t buffer1[BUFFER_SIZE];
    int32_t buffer2[BUFFER_SIZE];
    int32_t buffer3[BUFFER_SIZE];
    
    // PROTOTYPING
    void initADC();
    void ADCTask();
    void ADCSampleTask(void * pvPin);
    void ADCDMAInit(void);
    void ADC_ISR_Callback(void);
    
    // DMA prototypes
    void configureDMA0();
    void ADCDMA0Complete();
    void configureDMA1();
    void ADCDMA1Complete();
    void configureDMA2();
    void ADCDMA2Complete();
    void configureDMA3();
    void ADCDMA3Complete();
    
    
    // Error function: do something better
    void handle_error(void);
    
    
#endif
    