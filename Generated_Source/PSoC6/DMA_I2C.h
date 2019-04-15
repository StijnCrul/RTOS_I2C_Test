/***************************************************************************//**
* \file DMA_I2C.h
* \version 2.0
*
*  This file provides constants, parameter values and API definition for the
*  DMA_I2C Component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(DMA_I2C_CH_H)
#define DMA_I2C_CH_H

#include "cy_device_headers.h"
#include "cyfitter.h"
#include "dma/cy_dma.h"
#include "trigmux/cy_trigmux.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define DMA_I2C_DW_BLOCK       (0u)
#define DMA_I2C_DW_CHANNEL     (0u)
#define DMA_I2C_HW             (DW0)
#define DMA_I2C_INTR_MASK      (CY_DMA_INTR_MASK)

/* Channel settings */
#define DMA_I2C_PRIORITY       (3u)
#define DMA_I2C_DESCRIPTOR_NUM (1u)
#define DMA_I2C_PREEMPTABLE    (false)
#define DMA_I2C_BUFFERABLE     (false)

/***************************************
*        Function Prototypes
***************************************/

                void DMA_I2C_Start(void const * srcAddress, void const * dstAddress);
__STATIC_INLINE void DMA_I2C_Stop(void);
                void DMA_I2C_Init(void);
__STATIC_INLINE void DMA_I2C_ChannelEnable(void);
__STATIC_INLINE void DMA_I2C_ChannelDisable(void);

__STATIC_INLINE void DMA_I2C_SetDescriptor       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void DMA_I2C_SetNextDescriptor   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void DMA_I2C_SetPriority         (uint32_t priority);
__STATIC_INLINE void DMA_I2C_SetSrcAddress       (cy_stc_dma_descriptor_t * descriptor, void const * srcAddress);
__STATIC_INLINE void DMA_I2C_SetDstAddress       (cy_stc_dma_descriptor_t * descriptor, void const * dstAddress);
__STATIC_INLINE void DMA_I2C_SetXloopDataCount   (cy_stc_dma_descriptor_t * descriptor, uint32_t xCount);
__STATIC_INLINE void DMA_I2C_SetYloopDataCount   (cy_stc_dma_descriptor_t * descriptor, uint32_t yCount);
__STATIC_INLINE void DMA_I2C_SetXloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcXincrement);
__STATIC_INLINE void DMA_I2C_SetXloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstXincrement);
__STATIC_INLINE void DMA_I2C_SetYloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcYincrement);
__STATIC_INLINE void DMA_I2C_SetYloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstYincrement);
__STATIC_INLINE void DMA_I2C_SetInterruptType    (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t interruptType);
__STATIC_INLINE void DMA_I2C_SetTriggerInType    (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerInType);
__STATIC_INLINE void DMA_I2C_SetTriggerOutType   (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerOutType);
__STATIC_INLINE void DMA_I2C_SetDataSize         (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_data_size_t dataSize);
__STATIC_INLINE void DMA_I2C_SetSrcTransferSize  (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t srcTransferSize);
__STATIC_INLINE void DMA_I2C_SetDstTransferSize  (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t dstTransferSize);
__STATIC_INLINE void DMA_I2C_SetRetrigger        (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_retrigger_t retrigger);
__STATIC_INLINE void DMA_I2C_SetDescriptorType   (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_descriptor_type_t descriptorType);
__STATIC_INLINE void DMA_I2C_SetChannelState     (cy_stc_dma_descriptor_t * descriptor, cy_en_dma_channel_state_t channelState);

__STATIC_INLINE cy_stc_dma_descriptor_t *   DMA_I2C_GetDescriptor(void);
__STATIC_INLINE cy_stc_dma_descriptor_t *   DMA_I2C_GetNextDescriptor(void);
__STATIC_INLINE uint32_t                    DMA_I2C_GetPriority(void);
__STATIC_INLINE cy_en_dma_intr_cause_t      DMA_I2C_GetStatus(void);
__STATIC_INLINE cy_en_trigmux_status_t      DMA_I2C_Trigger(uint32_t cycles);
__STATIC_INLINE void *                      DMA_I2C_GetSrcAddress       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE void *                      DMA_I2C_GetDstAddress       (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE uint32_t                    DMA_I2C_GetXloopDataCount   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE uint32_t                    DMA_I2C_GetYloopDataCount   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     DMA_I2C_GetXloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     DMA_I2C_GetXloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     DMA_I2C_GetYloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE int32_t                     DMA_I2C_GetYloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    DMA_I2C_GetInterruptType    (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    DMA_I2C_GetTriggerInType    (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_trigger_type_t    DMA_I2C_GetTriggerOutType   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_data_size_t       DMA_I2C_GetDataSize         (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_transfer_size_t   DMA_I2C_GetSrcTransferSize  (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_transfer_size_t   DMA_I2C_GetDstTransferSize  (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_retrigger_t       DMA_I2C_GetRetrigger        (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_descriptor_type_t DMA_I2C_GetDescriptorType   (cy_stc_dma_descriptor_t const * descriptor);
__STATIC_INLINE cy_en_dma_channel_state_t   DMA_I2C_GetChannelState     (cy_stc_dma_descriptor_t const * descriptor);

__STATIC_INLINE uint32_t DMA_I2C_GetInterruptStatus(void);
__STATIC_INLINE void     DMA_I2C_ClearInterrupt(void);
__STATIC_INLINE void     DMA_I2C_SetInterrupt(void);
__STATIC_INLINE uint32_t DMA_I2C_GetInterruptMask(void);
__STATIC_INLINE void     DMA_I2C_SetInterruptMask(uint32_t interrupt);
__STATIC_INLINE uint32_t DMA_I2C_GetInterruptStatusMasked(void);


/***************************************
*    Global Variables
***************************************/
extern uint8_t DMA_I2C_initVar;

extern const cy_stc_dma_descriptor_config_t DMA_I2C_Descriptor_1_config;
extern cy_stc_dma_descriptor_t DMA_I2C_Descriptor_1;



/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: DMA_I2C_Stop
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Disable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_Stop(void)
{
    Cy_DMA_Channel_Disable(DMA_I2C_HW, DMA_I2C_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: DMA_I2C_ChannelEnable
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Enable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_ChannelEnable(void)
{
    Cy_DMA_Channel_Enable(DMA_I2C_HW, DMA_I2C_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: DMA_I2C_ChannelDisable
****************************************************************************//**
* Invokes the Cy_DMA_Channel_Disable() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_ChannelDisable(void)
{
    Cy_DMA_Channel_Disable(DMA_I2C_HW, DMA_I2C_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: DMA_I2C_SetDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetDescriptor(cy_stc_dma_descriptor_t const * descriptor)
{
    Cy_DMA_Channel_SetDescriptor(DMA_I2C_HW, DMA_I2C_DW_CHANNEL, descriptor);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetCurrentDescriptor() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_stc_dma_descriptor_t * DMA_I2C_GetDescriptor(void)
{
    return(Cy_DMA_Channel_GetCurrentDescriptor(DMA_I2C_HW, DMA_I2C_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetNextDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetNextDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetNextDescriptor(cy_stc_dma_descriptor_t const * descriptor)
{
    Cy_DMA_Descriptor_SetNextDescriptor(Cy_DMA_Channel_GetCurrentDescriptor(DMA_I2C_HW, DMA_I2C_DW_CHANNEL), descriptor);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetNextDescriptor
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetNextDescriptor() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_stc_dma_descriptor_t * DMA_I2C_GetNextDescriptor(void)
{
    return(Cy_DMA_Descriptor_GetNextDescriptor(Cy_DMA_Channel_GetCurrentDescriptor(DMA_I2C_HW, DMA_I2C_DW_CHANNEL)));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetPriority
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetPriority() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetPriority(uint32_t priority)
{
    Cy_DMA_Channel_SetPriority(DMA_I2C_HW, DMA_I2C_DW_CHANNEL, priority);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetPriority
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetPriority() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE uint32_t DMA_I2C_GetPriority(void)
{
    return (Cy_DMA_Channel_GetPriority(DMA_I2C_HW, DMA_I2C_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetSrcAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetSrcAddress() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetSrcAddress(cy_stc_dma_descriptor_t * descriptor, void const * srcAddress)
{
    Cy_DMA_Descriptor_SetSrcAddress(descriptor, srcAddress);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetSrcAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetSrcAddress() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void * DMA_I2C_GetSrcAddress(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetSrcAddress(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetDstAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDstAddress() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetDstAddress(cy_stc_dma_descriptor_t * descriptor, void const * dstAddress)
{
    Cy_DMA_Descriptor_SetDstAddress(descriptor, dstAddress);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetDstAddress
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDestAddr() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void * DMA_I2C_GetDstAddress(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDstAddress(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetDataSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDataSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetDataSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_data_size_t dataSize)
{
    Cy_DMA_Descriptor_SetDataSize(descriptor, dataSize);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetDataSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDataSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_data_size_t DMA_I2C_GetDataSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDataSize(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetSrcTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetSrcTransferSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetSrcTransferSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t srcTransferSize)
{
    Cy_DMA_Descriptor_SetSrcTransferSize(descriptor, srcTransferSize);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetSrcTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetSrcTransferSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_transfer_size_t DMA_I2C_GetSrcTransferSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetSrcTransferSize(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetDstTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDstTransferSize() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetDstTransferSize(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_transfer_size_t dstTransferSize)
{
    Cy_DMA_Descriptor_SetDstTransferSize(descriptor, dstTransferSize);
}


/*******************************************************************************
* Function Name: DMA_I2C_SetRetrigger
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetRetrigger() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetRetrigger(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_retrigger_t retrigger)
{
    Cy_DMA_Descriptor_SetRetrigger(descriptor, retrigger);
}


/*******************************************************************************
* Function Name: DMA_I2C_SetDescriptorType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetDescriptorType() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetDescriptorType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_descriptor_type_t descriptorType)
{
    Cy_DMA_Descriptor_SetDescriptorType(descriptor, descriptorType);
}


/*******************************************************************************
* Function Name: DMA_I2C_SetChannelState
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetChannelState() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetChannelState(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_channel_state_t channelState)
{
    Cy_DMA_Descriptor_SetChannelState(descriptor, channelState);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetDstTransferSize
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDstTransferSize() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE cy_en_dma_transfer_size_t DMA_I2C_GetDstTransferSize(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDstTransferSize(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_GetRetrigger
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetRetrigger() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_retrigger_t DMA_I2C_GetRetrigger(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetRetrigger(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_GetDescriptorType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetDescriptorType() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_descriptor_type_t DMA_I2C_GetDescriptorType(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetDescriptorType(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_GetChannelState
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetChannelState() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE cy_en_dma_channel_state_t DMA_I2C_GetChannelState(cy_stc_dma_descriptor_t const * descriptor)
{
    return(Cy_DMA_Descriptor_GetChannelState(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetXloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopDataCount() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetXloopDataCount(cy_stc_dma_descriptor_t * descriptor, uint32_t xCount)
{
    Cy_DMA_Descriptor_SetXloopDataCount(descriptor, xCount);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetXloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopDataCount() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE uint32_t DMA_I2C_GetXloopDataCount(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopDataCount(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetXloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopSrcIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetXloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcXincrement)
{
    Cy_DMA_Descriptor_SetXloopSrcIncrement(descriptor, srcXincrement);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetXloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopSrcIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE int32_t DMA_I2C_GetXloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopSrcIncrement(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetXloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetXloopDstIncrement() PDL driver function. 
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetXloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstXincrement)
{
    Cy_DMA_Descriptor_SetXloopDstIncrement(descriptor, dstXincrement);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetXloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetXloopDstIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE int32_t DMA_I2C_GetXloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetXloopDstIncrement(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetYloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopDataCount() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetYloopDataCount(cy_stc_dma_descriptor_t * descriptor, uint32_t yCount)
{
    Cy_DMA_Descriptor_SetYloopDataCount(descriptor, yCount);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetYloopDataCount
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopDataCount() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE uint32_t DMA_I2C_GetYloopDataCount(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopDataCount(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetYloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopSrcIncrement() PDL driver function.  
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetYloopSrcIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t srcYincrement)
{
    Cy_DMA_Descriptor_SetYloopSrcIncrement(descriptor, srcYincrement);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetYloopSrcIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopSrcIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE int32_t DMA_I2C_GetYloopSrcIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopSrcIncrement(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetYloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetYloopDstIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetYloopDstIncrement(cy_stc_dma_descriptor_t * descriptor, int32_t dstYincrement)
{
    Cy_DMA_Descriptor_SetYloopDstIncrement(descriptor, dstYincrement);
}


/*******************************************************************************
* Function Name: DMA_I2C_SetInterruptType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetInterruptType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetInterruptType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t interruptType)
{
    Cy_DMA_Descriptor_SetInterruptType(descriptor, interruptType);
}


/*******************************************************************************
* Function Name: DMA_I2C_SetTriggerInType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetTriggerInType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetTriggerInType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerInType)
{
    Cy_DMA_Descriptor_SetTriggerInType(descriptor, triggerInType);
}


/*******************************************************************************
* Function Name: DMA_I2C_SetTriggerOutType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_SetTriggerOutType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetTriggerOutType(cy_stc_dma_descriptor_t * descriptor, cy_en_dma_trigger_type_t triggerOutType)
{
    Cy_DMA_Descriptor_SetTriggerOutType(descriptor, triggerOutType);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetYloopDstIncrement
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetYloopDstIncrement() PDL driver function.
*******************************************************************************/
__STATIC_INLINE int32_t DMA_I2C_GetYloopDstIncrement(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetYloopDstIncrement(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_GetInterruptType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetInterruptType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t DMA_I2C_GetInterruptType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetInterruptType(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_GetTriggerInType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetTriggerInType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t DMA_I2C_GetTriggerInType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetTriggerInType(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_GetTriggerOutType
****************************************************************************//**
* Invokes the Cy_DMA_Descriptor_GetTriggerOutType() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_trigger_type_t DMA_I2C_GetTriggerOutType(cy_stc_dma_descriptor_t const * descriptor)
{
    return (Cy_DMA_Descriptor_GetTriggerOutType(descriptor));
}


/*******************************************************************************
* Function Name: DMA_I2C_GetInterruptStatus()
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptStatus() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t DMA_I2C_GetInterruptStatus(void)
{
    return (Cy_DMA_Channel_GetInterruptStatus(DMA_I2C_HW, DMA_I2C_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: DMA_I2C_GetStatus
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetStatus() PDL driver function.
*******************************************************************************/
__STATIC_INLINE cy_en_dma_intr_cause_t DMA_I2C_GetStatus(void)
{
    return (Cy_DMA_Channel_GetStatus(DMA_I2C_HW, DMA_I2C_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: DMA_I2C_ClearInterrupt
****************************************************************************//**
* Invokes the Cy_DMA_Channel_ClearInterrupt() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_ClearInterrupt(void)
{
    Cy_DMA_Channel_ClearInterrupt(DMA_I2C_HW, DMA_I2C_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: DMA_I2C_SetInterrupt
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetInterrupt() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetInterrupt(void)
{
    Cy_DMA_Channel_SetInterrupt(DMA_I2C_HW, DMA_I2C_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetInterruptMask
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptMask() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t DMA_I2C_GetInterruptMask(void)
{
    return (Cy_DMA_Channel_GetInterruptMask(DMA_I2C_HW, DMA_I2C_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: DMA_I2C_SetInterruptMask
****************************************************************************//**
* Invokes the Cy_DMA_Channel_SetInterruptMask() PDL driver function.
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetInterruptMask(uint32_t interrupt)
{
    Cy_DMA_Channel_SetInterruptMask(DMA_I2C_HW, DMA_I2C_DW_CHANNEL, interrupt);
}


/*******************************************************************************
* Function Name: DMA_I2C_GetInterruptStatusMasked
****************************************************************************//**
* Invokes the Cy_DMA_Channel_GetInterruptStatusMasked() PDL driver function.
*******************************************************************************/
__STATIC_INLINE uint32_t DMA_I2C_GetInterruptStatusMasked(void)
{
    return (Cy_DMA_Channel_GetInterruptStatusMasked(DMA_I2C_HW, DMA_I2C_DW_CHANNEL));
}


/*******************************************************************************
* Function Name: DMA_I2C_Trigger
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
__STATIC_INLINE cy_en_trigmux_status_t DMA_I2C_Trigger(uint32_t cycles)
{
    return (Cy_TrigMux_SwTrigger((uint32_t)DMA_I2C_DW__TR_IN, cycles));
}


#if(CY_DMA_BWC)
/* Definitions to support backward compatibility with the component version 1.0, 
*  they are strongly not recommended to use in new designs */

#define DMA_I2C_ChEnable                (DMA_I2C_ChannelEnable)
#define DMA_I2C_ChDisable               (DMA_I2C_ChannelDisable)
#define DMA_I2C_SetDataElementSize      (DMA_I2C_SetDataSize)
#define DMA_I2C_GetDataElementSize      (DMA_I2C_GetDataSize)
#define DMA_I2C_SetXloopNumDataElements (DMA_I2C_SetXloopDataCount)
#define DMA_I2C_GetXloopNumDataElements (DMA_I2C_GetXloopDataCount)
#define DMA_I2C_SetYloopNumDataElements (DMA_I2C_SetYloopDataCount)
#define DMA_I2C_GetYloopNumDataElements (DMA_I2C_GetYloopDataCount)
#define DMA_I2C_SetInterruptMask()      (DMA_I2C_SetInterruptMask(DMA_I2C_INTR_MASK))
#define DMA_I2C_GetInterruptCause       (DMA_I2C_GetStatus)

#define DMA_I2C_PREEMTAMBLE             (DMA_I2C_PREEMPTABLE)
/*******************************************************************************
* Function Name: DMA_I2C_SetSrcDstTransferWidth
****************************************************************************//**
* This is a legacy API function, it is left here just for backward compatibility
*******************************************************************************/
__STATIC_INLINE void DMA_I2C_SetSrcDstTransferWidth(cy_stc_dma_descriptor_t * descriptor, uint32_t options)
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
__STATIC_INLINE uint32_t DMA_I2C_GetSrcDstTransferWidth(cy_stc_dma_descriptor_t const * descriptor)
{
    uint32_t ctlRegVal = descriptor->ctl & (DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Msk |
        DW_DESCR_STRUCT_DESCR_CTL_DST_TRANSFER_SIZE_Msk);
    
    return(ctlRegVal >> DW_DESCR_STRUCT_DESCR_CTL_SRC_TRANSFER_SIZE_Pos);
}

#endif /* CY_DMA_BWC */


#if defined(__cplusplus)
}
#endif

#endif/* (DMA_I2C_CH_H) */

/* [] END OF FILE */
