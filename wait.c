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
 *         File: wait.c
 *      Created: 2019-04-11
 *       Author: Stijn Crul
 *      Version: 0.1
 *
 *  Description: wait library for PSOC6
 */

#include "wait.h"
#include "project.h"


/* 
* Name: WaitOneUnit
* Description: Makes the the CPU wait for a numer of time units
*
* Arguments:    uint32_t *timeout
* Output:       bool status
*/
bool WaitOneUnit(uint32_t *timeout){
    uint32_t status = false;

    // If the timeout equal to 0. Ignore the timeout
    if (*timeout > 0UL){
        Cy_SysLib_DelayUs(CY_SCB_WAIT_1_UNIT);
        --(*timeout);

        if (0UL == *timeout){
            status = true;
        }
    }
    return (status);
}

