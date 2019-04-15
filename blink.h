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
 *         File: blink.h
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: Blink library for addressing the LEDs on a PSOC 6 development kit using an RTOS task
 */
#ifndef __BLINK__
#define __BLINK__
    
#include "project.h"
#include "FreeRTOS.h"
#include "task.h"
    
    // Pin declaration and its timing for RTOS task
    typedef struct {
        GPIO_PRT_Type* port;
        unsigned int pin;
        TickType_t timing;
    } PIN;
    
    // Prototyping
    void BlinkTask(void * pvPin);
    
#endif
