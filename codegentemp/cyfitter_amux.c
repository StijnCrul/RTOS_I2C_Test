/*******************************************************************************
* File Name: cyfitter_amux.c
* 
* PSoC Creator  4.2
*
* Description:
* APIs for analog mux channel switching
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cyfitter_cfg.h"
#include "cydevice_trm.h"
#include <string.h>

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
    #define CYPACKED 
    #define CYPACKED_ATTR __attribute__ ((packed))
    #define CYALIGNED __attribute__ ((aligned))
    #define CY_CFG_UNUSED __attribute__ ((unused))
    #ifndef CY_CFG_SECTION
        #define CY_CFG_SECTION __attribute__ ((section(".psocinit")))
    #endif
    
    #if defined(__ARMCC_VERSION)
        #define CY_CFG_MEMORY_BARRIER() __memory_changed()
    #else
        #define CY_CFG_MEMORY_BARRIER() __sync_synchronize()
    #endif
    
#elif defined(__ICCARM__)
    #include <intrinsics.h>

    #define CYPACKED __packed
    #define CYPACKED_ATTR 
    #define CYALIGNED _Pragma("data_alignment=4")
    #define CY_CFG_UNUSED _Pragma("diag_suppress=Pe177")
    #define CY_CFG_SECTION _Pragma("location=\".psocinit\"")
    
    #define CY_CFG_MEMORY_BARRIER() __DMB()
    
#else
    #error Unsupported toolchain
#endif

#ifndef CYCODE
    #define CYCODE
#endif
#ifndef CYDATA
    #define CYDATA
#endif
#ifndef CYFAR
    #define CYFAR
#endif
#ifndef CYXDATA
    #define CYXDATA
#endif


CY_CFG_UNUSED
static void CYMEMZERO(void *s, size_t n);
CY_CFG_UNUSED
static void CYMEMZERO(void *s, size_t n)
{
	(void)memset(s, 0, n);
}
CY_CFG_UNUSED
static void CYCONFIGCPY(void *dest, const void *src, size_t n);
CY_CFG_UNUSED
static void CYCONFIGCPY(void *dest, const void *src, size_t n)
{
	(void)memcpy(dest, src, n);
}
CY_CFG_UNUSED
static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n);
CY_CFG_UNUSED
static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n)
{
	(void)memcpy(dest, src, n);
}


#define CY_AMUX_UNUSED CYREG_CPUSS_CM0_STATUS
int8 AMuxSeq_curChannel = -1;

void AMuxSeq_DisconnectAll(void)
{
	AMuxSeq_curChannel = -1;
	CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH_CLEAR0, (0x01u));
	CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH_CLEAR0, (0x02u));
	CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH_CLEAR0, (0x04u));
	CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH_CLEAR0, (0x08u));
}

void AMuxSeq_Next(void)
{
	AMuxSeq_curChannel++;
	switch (AMuxSeq_curChannel)
	{
	case 5: /* to force jump table (not executed) */
		AMuxSeq_curChannel = 5;
	case 6: /* to force jump table (not executed) */
		AMuxSeq_curChannel = 6;
	case 7: /* to force jump table (not executed) */
		AMuxSeq_curChannel = 7;
	case 4:
	default:
		AMuxSeq_curChannel = 0;
	case 0:
		CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH_CLEAR0, (0x08u));
		CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH0, (0x01u));
		break;
	case 1:
		CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH_CLEAR0, (0x01u));
		CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH0, (0x02u));
		break;
	case 2:
		CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH_CLEAR0, (0x02u));
		CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH0, (0x04u));
		break;
	case 3:
		CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH_CLEAR0, (0x04u));
		CY_SET_REG32((void CYXDATA *)CYREG_SAR_MUX_SWITCH0, (0x08u));
		break;
	}
}


