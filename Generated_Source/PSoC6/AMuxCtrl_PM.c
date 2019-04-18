/*******************************************************************************
* File Name: AMuxCtrl_PM.c
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

#include "AMuxCtrl.h"

/* Check for removal by optimization */
#if !defined(AMuxCtrl_Sync_ctrl_reg__REMOVED)

static AMuxCtrl_BACKUP_STRUCT  AMuxCtrl_backup = {0u};

    
/*******************************************************************************
* Function Name: AMuxCtrl_SaveConfig
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
void AMuxCtrl_SaveConfig(void) 
{
    AMuxCtrl_backup.controlState = AMuxCtrl_Control;
}


/*******************************************************************************
* Function Name: AMuxCtrl_RestoreConfig
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
void AMuxCtrl_RestoreConfig(void) 
{
     AMuxCtrl_Control = AMuxCtrl_backup.controlState;
}


/*******************************************************************************
* Function Name: AMuxCtrl_Sleep
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
void AMuxCtrl_Sleep(void) 
{
    AMuxCtrl_SaveConfig();
}


/*******************************************************************************
* Function Name: AMuxCtrl_Wakeup
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
void AMuxCtrl_Wakeup(void)  
{
    AMuxCtrl_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
