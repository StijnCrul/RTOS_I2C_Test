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
 *         File: LSM303DLHC.h
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: LSM303DLHC library for PSOC6
 */

#include "project.h"
#include "LSM303DLHC.h"
#include "i2c.h"
#include "FreeRTOS.h"
#include "task.h"

/* 
* Name: initAccel 
* Description: Setup up the accelerometer by writing to CTRL_REG1_A
*
* Arguments:    cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg = psoc I2C settings
*               uint8_t mask = bits for the control register of the lsm303dlhc. Page 24 of datasheet
* Output:       uint8_t status
*/
uint8_t initAccel(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg, uint8_t mask){
    uint8_t status = TRANSFER_ERROR; 
    uint8_t msg[WRITE_PACKET_SIZE] = {LSM303_REGISTER_ACCEL_CTRL_REG1_A, mask};
    
    status = WriteCommandPacketToI2C(masterTransferCfg, LSM303_ADDRESS_ACCEL, msg, 2);
    
    return status;
}

/* 
* Function: readAccel  
* Description: Read values from accelerometer after it has been setup
*
* Arguments:  cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg = psoc I2C settings
* Output:     uint8_t status
*/
uint8_t readAccel(cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg){
    uint8_t status = TRANSFER_ERROR;
    uint8_t msg[WRITE_PACKET_SIZE];
    msg[0] = (LSM303_REGISTER_ACCEL_OUT_X_L_A | (1 << 7));
    
    if(TRANSFER_CMPLT == WriteCommandPacketToI2C(masterTransferCfg, LSM303_ADDRESS_ACCEL, msg, 1)){
        status = ReadStatusPacketFromI2C(masterTransferCfg, LSM303_ADDRESS_ACCEL, 6);
        // todo: Do something with read data
    }
    
    return status;
}

/* 
* Function: acceleroTask  
* Description: start up a task to read out the accelerometer at a set interval
*
* Arguments:  void *masterTransfer
* Output:     none
*/
void acceleroTask(void *masterTransfer){
    
    cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg;
    
    masterTransferCfg = *(cy_stc_scb_i2c_master_xfer_config_t *) masterTransfer;
    
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 1000;
      
    xLastWakeTime = xTaskGetTickCount();    
    
    if (TRANSFER_CMPLT == initAccel(masterTransferCfg, 0x97)){
        for(;;){
            vTaskDelayUntil(&xLastWakeTime, xFrequency);
            if(TRANSFER_CMPLT == readAccel(masterTransferCfg)){
                //Todo do something with accelerometer data
                //accelData.x = (float)((int16_t)((masterTransferCfg.buffer[1] << 8) | masterTransferCfg.buffer[0]) >> 4)*LSM303ACCEL_MG_LSB*GRAVITY_STANDARD;
                //accelData.y = (float)((int16_t)((masterTransferCfg.buffer[3] << 8) | masterTransferCfg.buffer[2]) >> 4)*LSM303ACCEL_MG_LSB*GRAVITY_STANDARD;
                //accelData.z = (float)((int16_t)((masterTransferCfg.buffer[5] << 8) | masterTransferCfg.buffer[4]) >> 4)*LSM303ACCEL_MG_LSB*GRAVITY_STANDARD;
            }
        }
    }
}