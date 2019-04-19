/*******************************************************************************
* File Name: ADCCtrl_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "ADCCtrl.h"

/* Check for removal by optimization */
#if !defined(ADCCtrl_Sync_ctrl_reg__REMOVED)

static ADCCtrl_BACKUP_STRUCT  ADCCtrl_backup = {0u};

    
/*******************************************************************************
* Function Name: ADCCtrl_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ADCCtrl_SaveConfig(void) 
{
    ADCCtrl_backup.controlState = ADCCtrl_Control;
}


/*******************************************************************************
* Function Name: ADCCtrl_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void ADCCtrl_RestoreConfig(void) 
{
     ADCCtrl_Control = ADCCtrl_backup.controlState;
}


/*******************************************************************************
* Function Name: ADCCtrl_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ADCCtrl_Sleep(void) 
{
    ADCCtrl_SaveConfig();
}


/*******************************************************************************
* Function Name: ADCCtrl_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ADCCtrl_Wakeup(void)  
{
    ADCCtrl_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
