/***************************************************************************//**
* \file ADCDMA_3.c
* \version 2.0
*
*  This file provides the source code to the API for the
*  ADCDMA_3 component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADCDMA_3.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* Generated code */
const cy_stc_dma_descriptor_config_t ADCDMA_3_Descriptor_1_config =
{
    .retrigger       = CY_DMA_RETRIG_IM,
    .interruptType   = CY_DMA_1ELEMENT,
    .triggerOutType  = CY_DMA_1ELEMENT,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_WORD,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_1D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 0L,
    .dstXincrement   = 1L,
    .xCount          = 4UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 0L,
    .yCount          = 1UL,
    .nextDescriptor  = &ADCDMA_3_Descriptor_1
};

cy_stc_dma_descriptor_t ADCDMA_3_Descriptor_1 =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};


/** ADCDMA_3_initVar indicates whether the ADCDMA_3 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time ADCDMA_3_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the ADCDMA_3_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  ADCDMA_3_Init() function can be called before the 
*  ADCDMA_3_Start() or ADCDMA_3_ChEnable() function.
*/
uint8 ADCDMA_3_initVar = 0u;


/*******************************************************************************
* Function Name: ADCDMA_3_Start
****************************************************************************//**
*
* Based on the settings for descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init(). Enables the ADCDMA_3 block using the DMA_Chnl_Enable().
*  
*******************************************************************************/
void ADCDMA_3_Start(void const * srcAddress, void const * dstAddress)
{
    if (0U == ADCDMA_3_initVar)
    {
        ADCDMA_3_Init();
        ADCDMA_3_initVar = 1u;
    }
    
    Cy_DMA_Descriptor_SetSrcAddress(&ADCDMA_3_Descriptor_1, srcAddress);
    Cy_DMA_Descriptor_SetDstAddress(&ADCDMA_3_Descriptor_1, dstAddress);
    Cy_DMA_Channel_Enable(ADCDMA_3_HW, ADCDMA_3_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_3_Init
****************************************************************************//**
*
* Based on the settings for the descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init().
*  
*******************************************************************************/
void ADCDMA_3_Init(void)
{
    cy_stc_dma_channel_config_t channelConfig;

    /* Init all descriptors */
    (void)Cy_DMA_Descriptor_Init(&ADCDMA_3_Descriptor_1, &ADCDMA_3_Descriptor_1_config);


    channelConfig.descriptor  = &ADCDMA_3_Descriptor_1;
    channelConfig.preemptable = ADCDMA_3_PREEMPTABLE;
    channelConfig.priority    = ADCDMA_3_PRIORITY;
    channelConfig.enable      = false;
    channelConfig.bufferable  = ADCDMA_3_BUFFERABLE;

    (void)Cy_DMA_Channel_Init(ADCDMA_3_HW, ADCDMA_3_DW_CHANNEL, &channelConfig);

    Cy_DMA_Enable(ADCDMA_3_HW);
}


#if defined(__cplusplus)
}
#endif

/* [] END OF FILE */
