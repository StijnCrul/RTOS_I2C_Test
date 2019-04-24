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
 *         File: blink.c
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: Blink library for addressing the LEDs on a PSOC 6 development kit using an RTOS task
 */

#include "blink.h"

/* 
* Name: BlinkTask
* Description: create a task where to toggle a GPIO pin periodically
*
* Arguments:    PIN pvPin (with pvPin->port pvPin->pin, pvPin->timing)
* Output:       none
*/
void BlinkTask(void * pvPin){
    
    PIN *pxPin = (PIN*) pvPin;
    
    // Variables for creating a periodic function using delayUntil
    TickType_t xLastWakeTime ;
    const TickType_t xFrequency = pxPin->timing;
    
    // Variables for measuring how many ticks this function takes
    TickType_t xTime1, xTime2, xExecutionTime;
    
    short value = 0;
    
    xLastWakeTime = xTaskGetTickCount();
    
    for(;;){
        // Wait for the next cycle determined by xFrequency
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
        
        // Toggle the led and measure execution time
        //xTime1 = xTaskGetTickCount();
        value ^= 1;
        Cy_GPIO_Write(pxPin->port, pxPin->pin, value);
        //xTime2 = xTaskGetTickCount();
        //xExecutionTime = xTime2 - xTime1;
        //ShowTicks(xExecutionTime);
    }
}

/* [] END OF FILE */
