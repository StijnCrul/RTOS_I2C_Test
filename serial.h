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
 *         File: serial.h
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: UART library for sending messages on a PSOC 6 development kit using an RTOS task
 */
#ifndef __SERIAL__
#define __SERIAL__
    
#include "project.h"
#include "analog.h"
   

    //int32_t buffer0[BUFFER_SIZE];
    // PROTOTYPING
    void UARTTask();
    void configureUARTDMA();
    void UARTDMAComplete();
    void handle_serial_error(void);
    
#endif
    