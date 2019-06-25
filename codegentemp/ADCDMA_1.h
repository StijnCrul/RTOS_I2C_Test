/***************************************************************************//**
* \file ADCDMA_1.h
* \version 2.0
*
*  This file provides constants, parameter values and API definition for the
*  ADCDMA_1 Component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(ADCDMA_1_CH_H)
#define ADCDMA_1_CH_H

#include "cy_device_headers.h"
#include "cyfitter.h"
#include "dma/cy_dma.h"
#include "trigmux/cy_trigmux.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define ADCDMA_1_DW_BLOCK       (0u)
#define ADCDMA_1_DW_CHANNEL     (4u)
#define ADCDMA_1_HW             (DW0)
#define ADCDMA_1_INTR_MASK      (CY_DMA_INTR_MASK)

/* Channel settings */
#define ADCDMA_1_PRIORITY       (3u)
#define ADCDMA_1_DESCRIPTOR_NUM (1u)
#define ADCDMA_1_PREEMPTABLE    (false)
#define ADCDMA_1_BUFFERABLE     (false)

/***************************************
*        Function Prototypes
***************************************/

                void ADCDMA_1_Start(void const * srcAddress, void const * dstAddress);
__STATIC_INLINE void ADCDMA_1_Stop(void);
                void ADCDMA_1_Init(void);
__STATIC_INLINE void ADCDMA_1_ChannelEnable(void);
__STATIC_INLINE void ADCDMA_1_ChannelDisable(void);

__STATIC_INLINE void ADCDMA_1_SetDescriptor       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void ADCDMA_1_SetNextDescriptor   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void ADCDMA_1_SetPriority         (uint32_t priority);
__STATIC_INLINE void ADCDMA_1_SetSrcAddress       (cy_stc_dma_descriptor_t * descriptor, void const * srcAddress);
__STATIC_INLINE void ADCDMA_1_SetDstAddress       (cy_stc_dma_descriptor_t * descriptor, void const * dstAddress);
__STATIC_INLINE void ADCDMA_1_SetXloopDataCount   (cy_stc_dma_descriptor_t * descriptor, uint32_t xCount);
__STATIC_INLINE void ADCDMA_1_SetYloopDataCount   (cy_stc_dma_descriptor_t * descriptor, uint32_t yCount);
__STATIC_INLINE void ADCDMA_1_SetXloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcXincrement);
__STATIC_INLINE void ADCDMA_1_SetXloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstXincrement);
__STATIC_INLINE void ADCDMA_1_SetYloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcYincrement);
__STATIC_INLINE void ADCDMA_1_SetYloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstYincrement);
__STATIC_INLINE void ADCDMA_1_SetInterruptType    (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t interruptType);
__STATIC_INLINE void ADCDMA_1_SetTriggerInType    (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerInType);
__STATIC_INLINE void ADCDMA_1_SetTriggerOutType   (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerOutType);
__STATIC_INLINE void ADCDMA_1_SetDataSize         (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_data_size_t dataSize);
__STATIC_INLINE void ADCDMA_1_SetSrcTransferSize  (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t srcTransferSize);
__STATIC_INLINE void ADCDMA_1_SetDstTransferSize  (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t dstTransferSize);
__STATIC_INLINE void ADCDMA_1_SetRetrigger        (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_retrigger_t retrigger);
__STATIC_INLINE void ADCDMA_1_SetDescriptorType   (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_descriptor_type_t descriptorType);
__STATIC_INLINE void ADCDMA_1_SetChannelState     (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_channel_state_t channelState);

__STATIC_INLINE cy_stc_dma_descriptor_t *   ADCDMA_1_GetDescriptor(void);
__STATIC_INLINE cy_stc_dma_descriptor_t *   ADCDMA_1_GetNextDescriptor(void);
__STATIC_INLINE uint32_t                    ADCDMA_1_GetPriority(void);
__STATIC_INLINE cy_en_dma_intr_cause_t      ADCDMA_1_GetStatus(void);
__STATIC_INLINE cy_en_trigmux_status_t      ADCDMA_1_Trigger(uint32_t cycles);
__STATIC_INLINE void *                      ADCDMA_1_GetSrcAddress       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void *                      ADCDMA_1_GetDstAddress       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE uint32_t                    ADCDMA_1_GetXloopDataCount   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE uint32_t                    ADCDMA_1_GetYloopDataCount   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADCDMA_1_GetXloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADCDMA_1_GetXloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADCDMA_1_GetYloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADCDMA_1_GetYloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    ADCDMA_1_GetInterruptType    (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    ADCDMA_1_GetTriggerInType    (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    ADCDMA_1_GetTriggerOutType   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_data_size_t       ADCDMA_1_GetDataSize         (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_transfer_size_t   ADCDMA_1_GetSrcTransferSize  (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_transfer_size_t   ADCDMA_1_GetDstTransferSize  (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_retrigger_t       ADCDMA_1_GetRetrigger        (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_descriptor_type_t ADCDMA_1_GetDescriptorType   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_channel_state_t   ADCDMA_1_GetChannelState     (cy_stc_dma_descriptor_t const * descriptor);

__STATIC_INLINE uint32_t ADCDMA_1_GetInterruptStatus(void);
__STATIC_INLINE void     ADCDMA_1_ClearInterrupt(void);
__STATIC_INLINE void     ADCDMA_1_SetInterrupt(void);
__STATIC_INLINE uint32_t ADCDMA_1_GetInterruptMask(void);
__STATIC_INLINE void     ADCDMA_1_SetInterruptMask(uint32_t interrupt);
__STATIC_INLINE uint32_t ADCDMA_1_GetInterruptStatusMasked(void);


/***************************************
*    Global Variables
***************************************/
extern uint8_t ADCDMA_1_initVar;

extern const cy_stc_dma_descriptor_config_t ADCDMA_1_Descriptor_1_config;
extern cy_stc_dma_descriptor_t ADCDMA_1_Descriptor_1;



/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: ADCDMA_1_Stop
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Disable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_Stop(void)
{
    Cy_DMA_Channel_Disable(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_1_ChannelEnable
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Enable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_ChannelEnable(void)
{
    Cy_DMA_Channel_Enable(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_1_ChannelDisable
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Disable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_ChannelDisable(void)
{
    Cy_DMA_Channel_Disable(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetDescriptor(cy_stc_dma_descriptor_t const * descriptor)
{
    Cy_DMA_Channel_SetDescriptor(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL, descriptor);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetCurrentDescriptor() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_stc_dma_descriptor_t * ADCDMA_1_GetDescriptor(void)
{
    return(Cy_DMA_Channel_GetCurrentDescriptor(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetNextDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetNextDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetNextDescriptor(cy_stc_dma_descriptor_t const * descriptor)
{
    Cy_DMA_Descriptor_SetNextDescriptor(Cy_DMA_Channel_GetCurrentDescriptor(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL), descriptor);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetNextDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetNextDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_stc_dma_descriptor_t * ADCDMA_1_GetNextDescriptor(void)
{
    return(Cy_DMA_Descriptor_GetNextDescriptor(Cy_DMA_Channel_GetCurrentDescriptor(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL)));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetPriority
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetPriority() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetPriority(uint32_t priority)
{
    Cy_DMA_Channel_SetPriority(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL, priority);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetPriority
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetPriority() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_1_GetPriority(void)
{
    return (Cy_DMA_Channel_GetPriority(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetSrcAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetSrcAddress() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetSrcAddress(cy_stc_dma_descriptor_t * descriptor, void const * srcAddress)
{
    Cy_DMA_Descriptor_SetSrcAddress(descriptor, srcAddress);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetSrcAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetSrcAddress() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void * ADCDMA_1_GetSrcAddress(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetSrcAddress(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetDstAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDstAddress() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetDstAddress(cy_stc_dma_descriptor_t * descriptor, void const * dstAddress)
{
    Cy_DMA_Descriptor_SetDstAddress(descriptor, dstAddress);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetDstAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDestAddr() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void * ADCDMA_1_GetDstAddress(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDstAddress(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetDataSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDataSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetDataSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_data_size_t dataSize)
{
    Cy_DMA_Descriptor_SetDataSize(descriptor, dataSize);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetDataSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDataSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_data_size_t ADCDMA_1_GetDataSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDataSize(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetSrcTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetSrcTransferSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetSrcTransferSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t srcTransferSize)
{
    Cy_DMA_Descriptor_SetSrcTransferSize(descriptor, srcTransferSize);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetSrcTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetSrcTransferSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_transfer_size_t ADCDMA_1_GetSrcTransferSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetSrcTransferSize(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetDstTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDstTransferSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetDstTransferSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t dstTransferSize)
{
    Cy_DMA_Descriptor_SetDstTransferSize(descriptor, dstTransferSize);
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetRetrigger
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetRetrigger() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetRetrigger(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_retrigger_t retrigger)
{
    Cy_DMA_Descriptor_SetRetrigger(descriptor, retrigger);
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetDescriptorType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDescriptorType() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetDescriptorType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_descriptor_type_t descriptorType)
{
    Cy_DMA_Descriptor_SetDescriptorType(descriptor, descriptorType);
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetChannelState
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetChannelState() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetChannelState(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_channel_state_t channelState)
{
    Cy_DMA_Descriptor_SetChannelState(descriptor, channelState);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetDstTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDstTransferSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_transfer_size_t ADCDMA_1_GetDstTransferSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDstTransferSize(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetRetrigger
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetRetrigger() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_retrigger_t ADCDMA_1_GetRetrigger(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetRetrigger(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetDescriptorType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDescriptorType() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_descriptor_type_t ADCDMA_1_GetDescriptorType(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDescriptorType(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetChannelState
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetChannelState() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_channel_state_t ADCDMA_1_GetChannelState(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetChannelState(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetXloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopDataCount() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetXloopDataCount(cy_stc_dma_descriptor_t * descriptor, uint32_t xCount)
{
    Cy_DMA_Descriptor_SetXloopDataCount(descriptor, xCount);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetXloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopDataCount() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_1_GetXloopDataCount(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopDataCount(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetXloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopSrcIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetXloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcXincrement)
{
    Cy_DMA_Descriptor_SetXloopSrcIncrement(descriptor, srcXincrement);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetXloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopSrcIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE int32_t ADCDMA_1_GetXloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopSrcIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetXloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopDstIncrement() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetXloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstXincrement)
{
    Cy_DMA_Descriptor_SetXloopDstIncrement(descriptor, dstXincrement);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetXloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopDstIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE int32_t ADCDMA_1_GetXloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopDstIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetYloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopDataCount() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetYloopDataCount(cy_stc_dma_descriptor_t * descriptor, uint32_t yCount)
{
    Cy_DMA_Descriptor_SetYloopDataCount(descriptor, yCount);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetYloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopDataCount() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_1_GetYloopDataCount(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopDataCount(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetYloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopSrcIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetYloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcYincrement)
{
    Cy_DMA_Descriptor_SetYloopSrcIncrement(descriptor, srcYincrement);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetYloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopSrcIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE int32_t ADCDMA_1_GetYloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopSrcIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetYloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopDstIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetYloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstYincrement)
{
    Cy_DMA_Descriptor_SetYloopDstIncrement(descriptor, dstYincrement);
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetInterruptType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetInterruptType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetInterruptType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t interruptType)
{
    Cy_DMA_Descriptor_SetInterruptType(descriptor, interruptType);
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetTriggerInType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetTriggerInType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetTriggerInType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerInType)
{
    Cy_DMA_Descriptor_SetTriggerInType(descriptor, triggerInType);
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetTriggerOutType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetTriggerOutType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetTriggerOutType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerOutType)
{
    Cy_DMA_Descriptor_SetTriggerOutType(descriptor, triggerOutType);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetYloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopDstIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE int32_t ADCDMA_1_GetYloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopDstIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetInterruptType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetInterruptType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t ADCDMA_1_GetInterruptType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetInterruptType(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetTriggerInType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetTriggerInType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t ADCDMA_1_GetTriggerInType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetTriggerInType(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetTriggerOutType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetTriggerOutType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t ADCDMA_1_GetTriggerOutType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetTriggerOutType(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetInterruptStatus()
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptStatus() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_1_GetInterruptStatus(void)
{
    return (Cy_DMA_Channel_GetInterruptStatus(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetStatus
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetStatus() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_intr_cause_t ADCDMA_1_GetStatus(void)
{
    return (Cy_DMA_Channel_GetStatus(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_1_ClearInterrupt
****************************************************************************//**
* Invokes the Cy_DMA_Channel_ClearInterrupt() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_ClearInterrupt(void)
{
    Cy_DMA_Channel_ClearInterrupt(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetInterrupt
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetInterrupt() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetInterrupt(void)
{
    Cy_DMA_Channel_SetInterrupt(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetInterruptMask
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptMask() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_1_GetInterruptMask(void)
{
    return (Cy_DMA_Channel_GetInterruptMask(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_1_SetInterruptMask
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetInterruptMask() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetInterruptMask(uint32_t interrupt)
{
    Cy_DMA_Channel_SetInterruptMask(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL, interrupt);
}


/*******************************************************************************
* Function Name: ADCDMA_1_GetInterruptStatusMasked
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptStatusMasked() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_1_GetInterruptStatusMasked(void)
{
    return (Cy_DMA_Channel_GetInterruptStatusMasked(ADCDMA_1_HW, ADCDMA_1_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_1_Trigger
****************************************************************************//**
*
* Invokes the Cy_TrigMux_SwTrigger() PDL driver function.
*
* \param cycles
*  The number of "Clk_Peri" cycles during which the trigger remains activated.
*  The valid range of cycles is 1 ... 254.
*  Also there are special values:
*  CY_TRIGGER_INFINITE - trigger remains activated untill user deactivates it by
*  calling this function with CY_TRIGGER_DEACTIVATE parameter.
*  CY_TRIGGER_DEACTIVATE - it is used to deactivate the trigger activated by
*  calling this function with CY_TRIGGER_INFINITE parameter.
*  Note: the DMA is clocked by "Clk_Slow" which can be slower than "Clk_Peri".
* 
* \return A status:
* - CY_TRIGMUX_SUCCESS: The trigger is succesfully activated/deactivated.
* - CY_TRIGMUX_INVALID_STATE: The trigger is already activated/not active.
*
*******************************************************************************/
__STATIC_INLINE cy_en_trigmux_status_t ADCDMA_1_Trigger(uint32_t cycles)
{
    return (Cy_TrigMux_SwTrigger((uint32_t)ADCDMA_1_DW__TR_IN, cycles));
}


#if(CY_DMA_BWC)
/* Definitions to support backward compatibility with the component version 1.0, 
*  they are strongly not recommended to use in new designs */

#define ADCDMA_1_ChEnable                (ADCDMA_1_ChannelEnable)
#define ADCDMA_1_ChDisable               (ADCDMA_1_ChannelDisable)
#define ADCDMA_1_SetDataElementSize      (ADCDMA_1_SetDataSize)
#define ADCDMA_1_GetDataElementSize      (ADCDMA_1_GetDataSize)
#define ADCDMA_1_SetXloopNumDataElements (ADCDMA_1_SetXloopDataCount)
#define ADCDMA_1_GetXloopNumDataElements (ADCDMA_1_GetXloopDataCount)
#define ADCDMA_1_SetYloopNumDataElements (ADCDMA_1_SetYloopDataCount)
#define ADCDMA_1_GetYloopNumDataElements (ADCDMA_1_GetYloopDataCount)
#define ADCDMA_1_SetInterruptMask()      (ADCDMA_1_SetInterruptMask(ADCDMA_1_INTR_MASK))
#define ADCDMA_1_GetInterruptCause       (ADCDMA_1_GetStatus)

#define ADCDMA_1_PREEMTAMBLE             (ADCDMA_1_PREEMPTABLE)
/*******************************************************************************
* Function Name: ADCDMA_1_SetSrcDstTransferWidth
****************************************************************************//**
* This is a legacy API function, it is left here just for backward compatibility
*******************************************************************************/
__STATIC_INLINE void ADCDMA_1_SetSrcDstTransferWidth(cy_stc_dma_descriptor_t * descriptor, uint32_t options)
{
    uint32_t ctlRegVal = descriptor->ctl & ((uint32_t)~(DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Msk | \
            DW_DESCR_STRUCT_DESCR_CTL_DST_TRANSFER_SIZE_Msk));
    
    descriptor->ctl = ctlRegVal |
        ((options << DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Pos) &
        (DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Msk | DW_DESCR_STRUCT_DESCR_CTL_DST_TRANSFER_SIZE_Msk));
}


/*******************************************************************************
* Function Name: DMA_1_GetSrcDstTransferWidth
****************************************************************************//**
* This is a legacy API function, it is left here just for backward compatibility
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_1_GetSrcDstTransferWidth(cy_stc_dma_descriptor_t const * descriptor)
{
    uint32_t ctlRegVal = descriptor->ctl & (DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Msk |
        DW_DESCR_STRUCT_DESCR_CTL_DST_TRANSFER_SIZE_Msk);
    
    return(ctlRegVal >> DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Pos);
}

#endif /* CY_DMA_BWC */


#if defined(__cplusplus)
}
#endif

#endif/* (ADCDMA_1_CH_H) */

/* [] END OF FILE */
