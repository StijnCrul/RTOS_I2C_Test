/***************************************************************************//**
* \file ADCDMA_0.h
* \version 2.0
*
*  This file provides constants, parameter values and API definition for the
*  ADCDMA_0 Component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(ADCDMA_0_CH_H)
#define ADCDMA_0_CH_H

#include "cy_device_headers.h"
#include "cyfitter.h"
#include "dma/cy_dma.h"
#include "trigmux/cy_trigmux.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define ADCDMA_0_DW_BLOCK       (0u)
#define ADCDMA_0_DW_CHANNEL     (1u)
#define ADCDMA_0_HW             (DW0)
#define ADCDMA_0_INTR_MASK      (CY_DMA_INTR_MASK)

/* Channel settings */
#define ADCDMA_0_PRIORITY       (3u)
#define ADCDMA_0_DESCRIPTOR_NUM (1u)
#define ADCDMA_0_PREEMPTABLE    (false)
#define ADCDMA_0_BUFFERABLE     (false)

/***************************************
*        Function Prototypes
***************************************/

                void ADCDMA_0_Start(void const * srcAddress, void const * dstAddress);
__STATIC_INLINE void ADCDMA_0_Stop(void);
                void ADCDMA_0_Init(void);
__STATIC_INLINE void ADCDMA_0_ChannelEnable(void);
__STATIC_INLINE void ADCDMA_0_ChannelDisable(void);

__STATIC_INLINE void ADCDMA_0_SetDescriptor       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void ADCDMA_0_SetNextDescriptor   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void ADCDMA_0_SetPriority         (uint32_t priority);
__STATIC_INLINE void ADCDMA_0_SetSrcAddress       (cy_stc_dma_descriptor_t * descriptor, void const * srcAddress);
__STATIC_INLINE void ADCDMA_0_SetDstAddress       (cy_stc_dma_descriptor_t * descriptor, void const * dstAddress);
__STATIC_INLINE void ADCDMA_0_SetXloopDataCount   (cy_stc_dma_descriptor_t * descriptor, uint32_t xCount);
__STATIC_INLINE void ADCDMA_0_SetYloopDataCount   (cy_stc_dma_descriptor_t * descriptor, uint32_t yCount);
__STATIC_INLINE void ADCDMA_0_SetXloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcXincrement);
__STATIC_INLINE void ADCDMA_0_SetXloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstXincrement);
__STATIC_INLINE void ADCDMA_0_SetYloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcYincrement);
__STATIC_INLINE void ADCDMA_0_SetYloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstYincrement);
__STATIC_INLINE void ADCDMA_0_SetInterruptType    (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t interruptType);
__STATIC_INLINE void ADCDMA_0_SetTriggerInType    (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerInType);
__STATIC_INLINE void ADCDMA_0_SetTriggerOutType   (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerOutType);
__STATIC_INLINE void ADCDMA_0_SetDataSize         (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_data_size_t dataSize);
__STATIC_INLINE void ADCDMA_0_SetSrcTransferSize  (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t srcTransferSize);
__STATIC_INLINE void ADCDMA_0_SetDstTransferSize  (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t dstTransferSize);
__STATIC_INLINE void ADCDMA_0_SetRetrigger        (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_retrigger_t retrigger);
__STATIC_INLINE void ADCDMA_0_SetDescriptorType   (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_descriptor_type_t descriptorType);
__STATIC_INLINE void ADCDMA_0_SetChannelState     (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_channel_state_t channelState);

__STATIC_INLINE cy_stc_dma_descriptor_t *   ADCDMA_0_GetDescriptor(void);
__STATIC_INLINE cy_stc_dma_descriptor_t *   ADCDMA_0_GetNextDescriptor(void);
__STATIC_INLINE uint32_t                    ADCDMA_0_GetPriority(void);
__STATIC_INLINE cy_en_dma_intr_cause_t      ADCDMA_0_GetStatus(void);
__STATIC_INLINE cy_en_trigmux_status_t      ADCDMA_0_Trigger(uint32_t cycles);
__STATIC_INLINE void *                      ADCDMA_0_GetSrcAddress       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void *                      ADCDMA_0_GetDstAddress       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE uint32_t                    ADCDMA_0_GetXloopDataCount   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE uint32_t                    ADCDMA_0_GetYloopDataCount   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADCDMA_0_GetXloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADCDMA_0_GetXloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADCDMA_0_GetYloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     ADCDMA_0_GetYloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    ADCDMA_0_GetInterruptType    (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    ADCDMA_0_GetTriggerInType    (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    ADCDMA_0_GetTriggerOutType   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_data_size_t       ADCDMA_0_GetDataSize         (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_transfer_size_t   ADCDMA_0_GetSrcTransferSize  (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_transfer_size_t   ADCDMA_0_GetDstTransferSize  (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_retrigger_t       ADCDMA_0_GetRetrigger        (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_descriptor_type_t ADCDMA_0_GetDescriptorType   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_channel_state_t   ADCDMA_0_GetChannelState     (cy_stc_dma_descriptor_t const * descriptor);

__STATIC_INLINE uint32_t ADCDMA_0_GetInterruptStatus(void);
__STATIC_INLINE void     ADCDMA_0_ClearInterrupt(void);
__STATIC_INLINE void     ADCDMA_0_SetInterrupt(void);
__STATIC_INLINE uint32_t ADCDMA_0_GetInterruptMask(void);
__STATIC_INLINE void     ADCDMA_0_SetInterruptMask(uint32_t interrupt);
__STATIC_INLINE uint32_t ADCDMA_0_GetInterruptStatusMasked(void);


/***************************************
*    Global Variables
***************************************/
extern uint8_t ADCDMA_0_initVar;

extern const cy_stc_dma_descriptor_config_t ADCDMA_0_Descriptor_1_config;
extern cy_stc_dma_descriptor_t ADCDMA_0_Descriptor_1;



/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: ADCDMA_0_Stop
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Disable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_Stop(void)
{
    Cy_DMA_Channel_Disable(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_0_ChannelEnable
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Enable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_ChannelEnable(void)
{
    Cy_DMA_Channel_Enable(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_0_ChannelDisable
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Disable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_ChannelDisable(void)
{
    Cy_DMA_Channel_Disable(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetDescriptor(cy_stc_dma_descriptor_t const * descriptor)
{
    Cy_DMA_Channel_SetDescriptor(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL, descriptor);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetCurrentDescriptor() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_stc_dma_descriptor_t * ADCDMA_0_GetDescriptor(void)
{
    return(Cy_DMA_Channel_GetCurrentDescriptor(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetNextDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetNextDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetNextDescriptor(cy_stc_dma_descriptor_t const * descriptor)
{
    Cy_DMA_Descriptor_SetNextDescriptor(Cy_DMA_Channel_GetCurrentDescriptor(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL), descriptor);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetNextDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetNextDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_stc_dma_descriptor_t * ADCDMA_0_GetNextDescriptor(void)
{
    return(Cy_DMA_Descriptor_GetNextDescriptor(Cy_DMA_Channel_GetCurrentDescriptor(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL)));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetPriority
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetPriority() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetPriority(uint32_t priority)
{
    Cy_DMA_Channel_SetPriority(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL, priority);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetPriority
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetPriority() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_0_GetPriority(void)
{
    return (Cy_DMA_Channel_GetPriority(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetSrcAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetSrcAddress() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetSrcAddress(cy_stc_dma_descriptor_t * descriptor, void const * srcAddress)
{
    Cy_DMA_Descriptor_SetSrcAddress(descriptor, srcAddress);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetSrcAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetSrcAddress() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void * ADCDMA_0_GetSrcAddress(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetSrcAddress(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetDstAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDstAddress() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetDstAddress(cy_stc_dma_descriptor_t * descriptor, void const * dstAddress)
{
    Cy_DMA_Descriptor_SetDstAddress(descriptor, dstAddress);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetDstAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDestAddr() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void * ADCDMA_0_GetDstAddress(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDstAddress(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetDataSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDataSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetDataSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_data_size_t dataSize)
{
    Cy_DMA_Descriptor_SetDataSize(descriptor, dataSize);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetDataSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDataSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_data_size_t ADCDMA_0_GetDataSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDataSize(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetSrcTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetSrcTransferSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetSrcTransferSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t srcTransferSize)
{
    Cy_DMA_Descriptor_SetSrcTransferSize(descriptor, srcTransferSize);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetSrcTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetSrcTransferSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_transfer_size_t ADCDMA_0_GetSrcTransferSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetSrcTransferSize(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetDstTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDstTransferSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetDstTransferSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t dstTransferSize)
{
    Cy_DMA_Descriptor_SetDstTransferSize(descriptor, dstTransferSize);
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetRetrigger
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetRetrigger() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetRetrigger(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_retrigger_t retrigger)
{
    Cy_DMA_Descriptor_SetRetrigger(descriptor, retrigger);
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetDescriptorType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDescriptorType() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetDescriptorType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_descriptor_type_t descriptorType)
{
    Cy_DMA_Descriptor_SetDescriptorType(descriptor, descriptorType);
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetChannelState
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetChannelState() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetChannelState(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_channel_state_t channelState)
{
    Cy_DMA_Descriptor_SetChannelState(descriptor, channelState);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetDstTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDstTransferSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_transfer_size_t ADCDMA_0_GetDstTransferSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDstTransferSize(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetRetrigger
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetRetrigger() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_retrigger_t ADCDMA_0_GetRetrigger(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetRetrigger(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetDescriptorType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDescriptorType() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_descriptor_type_t ADCDMA_0_GetDescriptorType(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDescriptorType(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetChannelState
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetChannelState() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_channel_state_t ADCDMA_0_GetChannelState(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetChannelState(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetXloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopDataCount() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetXloopDataCount(cy_stc_dma_descriptor_t * descriptor, uint32_t xCount)
{
    Cy_DMA_Descriptor_SetXloopDataCount(descriptor, xCount);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetXloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopDataCount() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_0_GetXloopDataCount(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopDataCount(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetXloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopSrcIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetXloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcXincrement)
{
    Cy_DMA_Descriptor_SetXloopSrcIncrement(descriptor, srcXincrement);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetXloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopSrcIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE int32_t ADCDMA_0_GetXloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopSrcIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetXloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopDstIncrement() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetXloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstXincrement)
{
    Cy_DMA_Descriptor_SetXloopDstIncrement(descriptor, dstXincrement);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetXloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopDstIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE int32_t ADCDMA_0_GetXloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopDstIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetYloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopDataCount() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetYloopDataCount(cy_stc_dma_descriptor_t * descriptor, uint32_t yCount)
{
    Cy_DMA_Descriptor_SetYloopDataCount(descriptor, yCount);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetYloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopDataCount() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_0_GetYloopDataCount(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopDataCount(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetYloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopSrcIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetYloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcYincrement)
{
    Cy_DMA_Descriptor_SetYloopSrcIncrement(descriptor, srcYincrement);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetYloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopSrcIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE int32_t ADCDMA_0_GetYloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopSrcIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetYloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopDstIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetYloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstYincrement)
{
    Cy_DMA_Descriptor_SetYloopDstIncrement(descriptor, dstYincrement);
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetInterruptType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetInterruptType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetInterruptType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t interruptType)
{
    Cy_DMA_Descriptor_SetInterruptType(descriptor, interruptType);
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetTriggerInType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetTriggerInType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetTriggerInType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerInType)
{
    Cy_DMA_Descriptor_SetTriggerInType(descriptor, triggerInType);
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetTriggerOutType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetTriggerOutType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetTriggerOutType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerOutType)
{
    Cy_DMA_Descriptor_SetTriggerOutType(descriptor, triggerOutType);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetYloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopDstIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE int32_t ADCDMA_0_GetYloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopDstIncrement(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetInterruptType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetInterruptType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t ADCDMA_0_GetInterruptType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetInterruptType(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetTriggerInType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetTriggerInType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t ADCDMA_0_GetTriggerInType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetTriggerInType(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetTriggerOutType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetTriggerOutType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t ADCDMA_0_GetTriggerOutType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetTriggerOutType(descriptor));
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetInterruptStatus()
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptStatus() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_0_GetInterruptStatus(void)
{
    return (Cy_DMA_Channel_GetInterruptStatus(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetStatus
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetStatus() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_intr_cause_t ADCDMA_0_GetStatus(void)
{
    return (Cy_DMA_Channel_GetStatus(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_0_ClearInterrupt
****************************************************************************//**
* Invokes the Cy_DMA_Channel_ClearInterrupt() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_ClearInterrupt(void)
{
    Cy_DMA_Channel_ClearInterrupt(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetInterrupt
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetInterrupt() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetInterrupt(void)
{
    Cy_DMA_Channel_SetInterrupt(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetInterruptMask
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptMask() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_0_GetInterruptMask(void)
{
    return (Cy_DMA_Channel_GetInterruptMask(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_0_SetInterruptMask
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetInterruptMask() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetInterruptMask(uint32_t interrupt)
{
    Cy_DMA_Channel_SetInterruptMask(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL, interrupt);
}


/*******************************************************************************
* Function Name: ADCDMA_0_GetInterruptStatusMasked
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptStatusMasked() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t ADCDMA_0_GetInterruptStatusMasked(void)
{
    return (Cy_DMA_Channel_GetInterruptStatusMasked(ADCDMA_0_HW, ADCDMA_0_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: ADCDMA_0_Trigger
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
__STATIC_INLINE cy_en_trigmux_status_t ADCDMA_0_Trigger(uint32_t cycles)
{
    return (Cy_TrigMux_SwTrigger((uint32_t)ADCDMA_0_DW__TR_IN, cycles));
}


#if(CY_DMA_BWC)
/* Definitions to support backward compatibility with the component version 1.0, 
*  they are strongly not recommended to use in new designs */

#define ADCDMA_0_ChEnable                (ADCDMA_0_ChannelEnable)
#define ADCDMA_0_ChDisable               (ADCDMA_0_ChannelDisable)
#define ADCDMA_0_SetDataElementSize      (ADCDMA_0_SetDataSize)
#define ADCDMA_0_GetDataElementSize      (ADCDMA_0_GetDataSize)
#define ADCDMA_0_SetXloopNumDataElements (ADCDMA_0_SetXloopDataCount)
#define ADCDMA_0_GetXloopNumDataElements (ADCDMA_0_GetXloopDataCount)
#define ADCDMA_0_SetYloopNumDataElements (ADCDMA_0_SetYloopDataCount)
#define ADCDMA_0_GetYloopNumDataElements (ADCDMA_0_GetYloopDataCount)
#define ADCDMA_0_SetInterruptMask()      (ADCDMA_0_SetInterruptMask(ADCDMA_0_INTR_MASK))
#define ADCDMA_0_GetInterruptCause       (ADCDMA_0_GetStatus)

#define ADCDMA_0_PREEMTAMBLE             (ADCDMA_0_PREEMPTABLE)
/*******************************************************************************
* Function Name: ADCDMA_0_SetSrcDstTransferWidth
****************************************************************************//**
* This is a legacy API function, it is left here just for backward compatibility
*******************************************************************************/
__STATIC_INLINE void ADCDMA_0_SetSrcDstTransferWidth(cy_stc_dma_descriptor_t * descriptor, uint32_t options)
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
__STATIC_INLINE uint32_t ADCDMA_0_GetSrcDstTransferWidth(cy_stc_dma_descriptor_t const * descriptor)
{
    uint32_t ctlRegVal = descriptor->ctl & (DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Msk |
        DW_DESCR_STRUCT_DESCR_CTL_DST_TRANSFER_SIZE_Msk);
    
    return(ctlRegVal >> DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Pos);
}

#endif /* CY_DMA_BWC */


#if defined(__cplusplus)
}
#endif

#endif/* (ADCDMA_0_CH_H) */

/* [] END OF FILE */
