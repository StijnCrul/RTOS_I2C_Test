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
 *         File: i2c.c
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: I2C library for PSOC6
 */

#include "i2c.h"
#include "wait.h"
#include "project.h"
#include "cy_scb_i2c.h"

// todo: do better error handling
static void HandleError(void){   
     // Disable all interrupts
    __disable_irq();
    
    // Infinite loop
    while(1u);
}

/* 
* Name: initI2C 
* Description: Initialize the I2C master on the psoc
*
* Arguments:    none
* Output:       none
*/
void initI2C(void){
    // Configure I2C
    cy_en_scb_i2c_status_t initStatus;
    cy_en_sysint_status_t sysStatus;
    uint32_t dataRateSet;
    //Initilaize and enable the I2C in master mode
    initStatus = Cy_SCB_I2C_Init(mI2C_HW, &mI2C_config, &mI2C_context);
    if(initStatus != CY_SCB_I2C_SUCCESS){
        HandleError();
    }
    // Configure desired data rate
    dataRateSet = Cy_SCB_I2C_SetDataRate(mI2C_HW, mI2C_DATA_RATE_HZ, mI2C_CLK_FREQ_HZ);
    // check whether data rate set is not greather then required reate.
    if( dataRateSet > mI2C_DATA_RATE_HZ ){
        HandleError();
    }
    // Hook interrupt service routine
    sysStatus = Cy_SysInt_Init(&mI2C_SCB_IRQ_cfg, &mI2C_Interrupt);
    if(sysStatus != CY_SYSINT_SUCCESS){
        HandleError();
    }
    NVIC_EnableIRQ((IRQn_Type) mI2C_SCB_IRQ_cfg.intrSrc);
    Cy_SCB_I2C_Enable(mI2C_HW);    
}


/* 
* Name: WriteCommandPacketToI2C 
* Description: Write message to a slave device
*
* Arguments:    cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg = psoc I2C settings
*               uint8_taddress = slave device address
*               uint8_t *msg = pointer to array message we want to send
*               uint32_t packet_size = number of bytes to be read
* Output:       uint8_t status
*/
uint8_t WriteCommandPacketToI2C(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg, uint8_t address, uint8_t *msg, uint32_t packet_size){
    uint8_t status = TRANSFER_ERROR;
    cy_en_scb_i2c_status_t  errorStatus;
    
    // If message length is longer than defined write buffer, hang
    if(packet_size > WRITE_PACKET_SIZE){
        //Todo, make better error handling
        HandleError();
    } else {
        /*for(int i = 0; i < length; i++){
            writebuffer[i] = msg[i];
        }*/
        
        // Setup transfer specific parameters
        masterTransferCfg.slaveAddress = address;
        masterTransferCfg.buffer       = msg;
        masterTransferCfg.bufferSize   = packet_size;
    }
  
    // Initiate write transaction
    errorStatus = Cy_SCB_I2C_MasterWrite(mI2C_HW, &masterTransferCfg, &mI2C_context);
    if(errorStatus == CY_SCB_I2C_SUCCESS){
        uint32_t masterStatus;
        bool     timeOutStatus;
        
        // Timeout 1 sec (one unit is us)
        uint32_t timeout = 1000000UL;
        // Wait until master complete read transfer or time out has occured
        do{
            masterStatus  = Cy_SCB_I2C_MasterGetStatus(mI2C_HW, &mI2C_context);
            timeOutStatus = WaitOneUnit(&timeout);
            
        } while ((0UL != (masterStatus & CY_SCB_I2C_MASTER_BUSY)) && (timeOutStatus == false));
        
        if (timeOutStatus){
            // Timeout recovery
            Cy_SCB_I2C_Disable(mI2C_HW, &mI2C_context);
            Cy_SCB_I2C_Enable (mI2C_HW);
        }else{
            if ((0u == (MASTER_ERROR_MASK & masterStatus)) &&
                (packet_size == Cy_SCB_I2C_MasterGetTransferCount(mI2C_HW, &mI2C_context)))
            {
                status = TRANSFER_CMPLT;
            }
        } 
    }
    return (status);
}


/* 
* Name: ReadStatusPacketFromI2C 
* Description: Read request to a slave device
*
* Arguments:    cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg = psoc I2C settings
*               uint8_t address: slave device address
*               uint32_t packet_size= number of bytes to be read
* Output:       uint8_t status
*/
uint8_t ReadStatusPacketFromI2C(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg, uint8_t address, uint32_t packet_size){
    uint8_t status = TRANSFER_ERROR;
    cy_en_scb_i2c_status_t errorStatus;
 
    // Setup transfer specific parameters 
    masterTransferCfg.slaveAddress = address;
    masterTransferCfg.buffer       = readBuffer;
    masterTransferCfg.bufferSize   = packet_size;

    // Initiate read transaction
    errorStatus = Cy_SCB_I2C_MasterRead(mI2C_HW, &masterTransferCfg, &mI2C_context);

    if(errorStatus == CY_SCB_I2C_SUCCESS) {
        uint32_t masterStatus;
        bool     timeOutStatus;
        
        // Timeout 1 sec (one unit is us)
        uint32_t timeout = 1000000UL;
        
        // Wait until master complete read transfer or time out has occured
        do{
            masterStatus  = Cy_SCB_I2C_MasterGetStatus(mI2C_HW, &mI2C_context);
            timeOutStatus = WaitOneUnit(&timeout);
            
        } while ((0UL != (masterStatus & CY_SCB_I2C_MASTER_BUSY)) && (timeOutStatus == false));
        
        if (timeOutStatus){
            // Timeout recovery
            Cy_SCB_I2C_Disable(mI2C_HW, &mI2C_context);
            Cy_SCB_I2C_Enable (mI2C_HW);
        }else{
            // Check transfer status
            if (0u == (MASTER_ERROR_MASK & masterStatus)){
                status = TRANSFER_CMPLT;
            }
        }
    }
    return (status);
}