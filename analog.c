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
 *         File: analog.c
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: ADC library for reading the ADC on a PSOC 6 development kit using an RTOS task
 */

#include "analog.h"
#include "FreeRTOS.h"
#include "task.h"

/*
* Initialize ADC things
*/
void initADC(){
    ADC_Start();
    ADC_IRQ_Enable();
}

/* 
* create a task where the data from the ADC (in free running mode) is processed 
*/
void ADCTask(){
    // Variables for creating a periodic function using delayUntil
    TickType_t xLastWakeTime ;
    const TickType_t xFrequency = 10000;
    
    int16_t newReading = 0;

    ADC_StartConvert();

    xLastWakeTime = xTaskGetTickCount();    
    for(;;){
        // Wait for the next cycle determined by xFrequency
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
        if(dataReady != 0){
            dataReady = 0;
            newReading = result;
            // todo: Process newReading
        }
    }
}

/* 
* create a task where the data from the ADC is sampled by the RTOS, set timing and a pin for measurements
*/
void ADCSampleTask(void * pvChannel){
    CH *pxChannel = (CH*) pvChannel;
    
    // Variables for creating a periodic function using delayUntil
    TickType_t xLastWakeTime ;
    const TickType_t xFrequency = pxChannel->timing;
    
    float32_t newReading = 51;
    int harhar = 0;

    GPIO_PRT_Type* port = pxChannel->port;
    unsigned int pin = pxChannel->pin;
    uint8_t channel = pxChannel->channel; 
    
    
    xLastWakeTime = xTaskGetTickCount();    
    for(;;){
        // Wait for the next cycle determined by xFrequency
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
        
        Cy_GPIO_Write(port, pin, 1);
        AMuxCtrl_Write(channel | 0x4);   //or with 4 to trigger the ADC
        Cy_GPIO_Write(port, pin, 0);
        
        //newReading = ADC_CountsTo_mVolts(0, ADC_GetResult16(0));
        //harhar = 0;
    }
}

void ADCDMAInit(void){
    //todo
}

void ADC_ISR_Callback(void){
    dataReady = 1;
    result = ADC_GetResult16(0);
}

    