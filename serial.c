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

/* 
* Name: UARTTask
* Description: UART RTOS tasks that prints something at a set interval of time
*
* Arguments:    none
* Output:       none
*/
void UARTTask(){
    TickType_t xLastWakeTime ;
    const TickType_t xFrequency = 1000;
    xLastWakeTime = xTaskGetTickCount();    
    for(;;){
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
        printf("I am alive\r\n");
    }
}    

void configureUARTDMA(){
    cy_en_dma_status_t dma_init_status;
	cy_stc_dma_channel_config_t channelConfig;	
    
    // Initialize descriptor 1
    dma_init_status = Cy_DMA_Descriptor_Init(&UARTDMA_Descriptor_1, &UARTDMA_Descriptor_1_config);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Initialize the DMA channel 
    channelConfig.descriptor  = &UARTDMA_Descriptor_1;
    channelConfig.preemptable = UARTDMA_PREEMPTABLE;
    channelConfig.priority    = UARTDMA_PRIORITY;
    channelConfig.enable      = false;
    dma_init_status = Cy_DMA_Channel_Init(UARTDMA_HW, UARTDMA_DW_CHANNEL, &channelConfig);
	if(dma_init_status!=CY_DMA_SUCCESS){
        handle_error();
    }
    
    // Set source and destination address for DMA transfer
    Cy_DMA_Descriptor_SetSrcAddress(&UARTDMA_Descriptor_1, buffer0); //hardcoded buffer 0 for now (make it work?)
    Cy_DMA_Descriptor_SetDstAddress(&UARTDMA_Descriptor_1, (uint32_t *) &UART_HW->TX_FIFO_WR);
    
    // Enable DMA interrupt
    Cy_SysInt_Init(&UART_DMA_INT_cfg, &UARTDMAComplete);
    NVIC_EnableIRQ(UART_DMA_INT_cfg.intrSrc);
    Cy_DMA_Channel_SetInterruptMask(UARTDMA_HW, UARTDMA_DW_CHANNEL, CY_DMA_INTR_MASK);
    
    Cy_DMA_Channel_Enable(UARTDMA_HW, UARTDMA_DW_CHANNEL);
    Cy_DMA_Enable(ADCDMA_0_HW);

}

void UARTDMAComplete(){
    Cy_DMA_Channel_ClearInterrupt(UARTDMA_HW, UARTDMA_DW_CHANNEL);
}

/* 
* Name: handle_error
* Description: Disables interrupts and halts the CPU when an error occurs. Todo: do something better
*
* Arguments:    none
* Output:       none
*/
void handle_serial_error(void){    
     // Disable all interrupts
    __disable_irq();
	
    // Do something better
    while(1u) {}
}