/*******************************************************************************
* File Name: ADCSOCCounter.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the ADCSOCCounter
*  component
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADCSOCCounter.h"

/** Indicates whether or not the ADCSOCCounter has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  ADCSOCCounter_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the ADCSOCCounter_Start() routine.
*/
uint8_t ADCSOCCounter_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated ADCSOCCounter_Init() function.
*/ 
cy_stc_tcpwm_counter_config_t const ADCSOCCounter_config =
{
        .period = 3UL,
        .clockPrescaler = 0UL,
        .runMode = 1UL,
        .countDirection = 0UL,
        .compareOrCapture = 0UL,
        .compare0 = 3UL,
        .compare1 = 16384UL,
        .enableCompareSwap = false,
        .interruptSources = 1UL,
        .captureInputMode = 3UL,
        .captureInput = CY_TCPWM_INPUT_CREATOR,
        .reloadInputMode = 0UL,
        .reloadInput = CY_TCPWM_INPUT_CREATOR,
        .startInputMode = 3UL,
        .startInput = CY_TCPWM_INPUT_CREATOR,
        .stopInputMode = 3UL,
        .stopInput = CY_TCPWM_INPUT_CREATOR,
        .countInputMode = 3UL,
        .countInput = CY_TCPWM_INPUT_CREATOR,
};


/*******************************************************************************
* Function Name: ADCSOCCounter_Start
****************************************************************************//**
*
*  Calls the ADCSOCCounter_Init() when called the first time and enables 
*  the ADCSOCCounter. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref ADCSOCCounter_initVar
*
*******************************************************************************/
void ADCSOCCounter_Start(void)
{
    if (0U == ADCSOCCounter_initVar)
    {
        (void)Cy_TCPWM_Counter_Init(ADCSOCCounter_HW, ADCSOCCounter_CNT_NUM, &ADCSOCCounter_config); 

        ADCSOCCounter_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(ADCSOCCounter_HW, ADCSOCCounter_CNT_MASK);
    
    #if (ADCSOCCounter_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(ADCSOCCounter_HW, ADCSOCCounter_CNT_MASK);
    #endif /* (ADCSOCCounter_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
