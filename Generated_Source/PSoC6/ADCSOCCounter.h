/*******************************************************************************
* File Name: ADCSOCCounter.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the ADCSOCCounter
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(ADCSOCCounter_CY_TCPWM_COUNTER_PDL_H)
#define ADCSOCCounter_CY_TCPWM_COUNTER_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_counter.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  ADCSOCCounter_initVar;
extern cy_stc_tcpwm_counter_config_t const ADCSOCCounter_config;
/** @} group_globals */


/***************************************
*  Conditional Compilation Parameters
***************************************/

#define ADCSOCCounter_INIT_COMPARE_OR_CAPTURE    (0UL)


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void ADCSOCCounter_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t ADCSOCCounter_Init(cy_stc_tcpwm_counter_config_t const *config);
__STATIC_INLINE void ADCSOCCounter_DeInit(void);
__STATIC_INLINE void ADCSOCCounter_Enable(void);
__STATIC_INLINE void ADCSOCCounter_Disable(void);
__STATIC_INLINE uint32_t ADCSOCCounter_GetStatus(void);

#if(CY_TCPWM_COUNTER_MODE_CAPTURE == ADCSOCCounter_INIT_COMPARE_OR_CAPTURE)
    __STATIC_INLINE uint32_t ADCSOCCounter_GetCapture(void);
    __STATIC_INLINE uint32_t ADCSOCCounter_GetCaptureBuf(void);
#else
    __STATIC_INLINE void ADCSOCCounter_SetCompare0(uint32_t compare0);
    __STATIC_INLINE uint32_t ADCSOCCounter_GetCompare0(void);
    __STATIC_INLINE void ADCSOCCounter_SetCompare1(uint32_t compare1);
    __STATIC_INLINE uint32_t ADCSOCCounter_GetCompare1(void);
    __STATIC_INLINE void ADCSOCCounter_EnableCompareSwap(bool enable);
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == ADCSOCCounter_INIT_COMPARE_OR_CAPTURE) */

__STATIC_INLINE void ADCSOCCounter_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t ADCSOCCounter_GetCounter(void);
__STATIC_INLINE void ADCSOCCounter_SetPeriod(uint32_t period);
__STATIC_INLINE uint32_t ADCSOCCounter_GetPeriod(void);
__STATIC_INLINE void ADCSOCCounter_TriggerStart(void);
__STATIC_INLINE void ADCSOCCounter_TriggerReload(void);
__STATIC_INLINE void ADCSOCCounter_TriggerStop(void);
__STATIC_INLINE void ADCSOCCounter_TriggerCapture(void);
__STATIC_INLINE uint32_t ADCSOCCounter_GetInterruptStatus(void);
__STATIC_INLINE void ADCSOCCounter_ClearInterrupt(uint32_t source);
__STATIC_INLINE void ADCSOCCounter_SetInterrupt(uint32_t source);
__STATIC_INLINE void ADCSOCCounter_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t ADCSOCCounter_GetInterruptMask(void);
__STATIC_INLINE uint32_t ADCSOCCounter_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define ADCSOCCounter_HW                 (ADCSOCCounter_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define ADCSOCCounter_CNT_HW             (ADCSOCCounter_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define ADCSOCCounter_CNT_NUM            (ADCSOCCounter_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define ADCSOCCounter_CNT_MASK           (1UL << ADCSOCCounter_CNT_NUM)
/** @} group_macros */

#define ADCSOCCounter_INPUT_MODE_MASK    (0x3U)
#define ADCSOCCounter_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: ADCSOCCounter_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t ADCSOCCounter_Init(cy_stc_tcpwm_counter_config_t const *config)
{
    return(Cy_TCPWM_Counter_Init(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: ADCSOCCounter_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_DeInit(void)                   
{
    Cy_TCPWM_Counter_DeInit(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, &ADCSOCCounter_config);
}

/*******************************************************************************
* Function Name: ADCSOCCounter_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(ADCSOCCounter_HW, ADCSOCCounter_CNT_MASK);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(ADCSOCCounter_HW, ADCSOCCounter_CNT_MASK);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ADCSOCCounter_GetStatus(void)                
{
    return(Cy_TCPWM_Counter_GetStatus(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM));
}


#if(CY_TCPWM_COUNTER_MODE_CAPTURE == ADCSOCCounter_INIT_COMPARE_OR_CAPTURE)
    /*******************************************************************************
    * Function Name: ADCSOCCounter_GetCapture
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCapture() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t ADCSOCCounter_GetCapture(void)               
    {
        return(Cy_TCPWM_Counter_GetCapture(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: ADCSOCCounter_GetCaptureBuf
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCaptureBuf() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t ADCSOCCounter_GetCaptureBuf(void)            
    {
        return(Cy_TCPWM_Counter_GetCaptureBuf(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM));
    }
#else
    /*******************************************************************************
    * Function Name: ADCSOCCounter_SetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void ADCSOCCounter_SetCompare0(uint32_t compare0)      
    {
        Cy_TCPWM_Counter_SetCompare0(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, compare0);
    }


    /*******************************************************************************
    * Function Name: ADCSOCCounter_GetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t ADCSOCCounter_GetCompare0(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare0(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: ADCSOCCounter_SetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void ADCSOCCounter_SetCompare1(uint32_t compare1)      
    {
        Cy_TCPWM_Counter_SetCompare1(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, compare1);
    }


    /*******************************************************************************
    * Function Name: ADCSOCCounter_GetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t ADCSOCCounter_GetCompare1(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare1(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: ADCSOCCounter_EnableCompareSwap
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_EnableCompareSwap() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void ADCSOCCounter_EnableCompareSwap(bool enable)  
    {
        Cy_TCPWM_Counter_EnableCompareSwap(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, enable);
    }
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == ADCSOCCounter_INIT_COMPARE_OR_CAPTURE) */


/*******************************************************************************
* Function Name: ADCSOCCounter_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_SetCounter(uint32_t count)          
{
    Cy_TCPWM_Counter_SetCounter(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ADCSOCCounter_GetCounter(void)               
{
    return(Cy_TCPWM_Counter_GetCounter(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM));
}


/*******************************************************************************
* Function Name: ADCSOCCounter_SetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_SetPeriod(uint32_t period)          
{
    Cy_TCPWM_Counter_SetPeriod(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, period);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_GetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ADCSOCCounter_GetPeriod(void)                
{
    return(Cy_TCPWM_Counter_GetPeriod(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM));
}


/*******************************************************************************
* Function Name: ADCSOCCounter_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(ADCSOCCounter_HW, ADCSOCCounter_CNT_MASK);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(ADCSOCCounter_HW, ADCSOCCounter_CNT_MASK);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_TriggerStop
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_TriggerStop(void)
{
    Cy_TCPWM_TriggerStopOrKill(ADCSOCCounter_HW, ADCSOCCounter_CNT_MASK);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_TriggerCapture
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_TriggerCapture(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(ADCSOCCounter_HW, ADCSOCCounter_CNT_MASK);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ADCSOCCounter_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM));
}


/*******************************************************************************
* Function Name: ADCSOCCounter_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ADCSOCCounter_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: ADCSOCCounter_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ADCSOCCounter_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM));
}


/*******************************************************************************
* Function Name: ADCSOCCounter_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ADCSOCCounter_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM));
}

#endif /* ADCSOCCounter_CY_TCPWM_COUNTER_PDL_H */


/* [] END OF FILE */
