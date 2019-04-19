 /* ____  ____      _    __  __  ____ ___
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
 *         File: serial.c
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: UART library for sending messages on a PSOC 6 development kit using an RTOS task
 */    

#include "serial.h"
#include "FreeRTOS.h"
#include "task.h"

void UARTTask(){
    TickType_t xLastWakeTime ;
    const TickType_t xFrequency = 10000;
    xLastWakeTime = xTaskGetTickCount();    
    for(;;){
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
        printf("\r\nI AM ALIVE");
    }
}    

    