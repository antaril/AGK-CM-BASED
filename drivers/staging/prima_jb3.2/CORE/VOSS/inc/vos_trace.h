/*
<<<<<<< HEAD
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
/*
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

<<<<<<< HEAD

=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#if !defined( __VOS_TRACE_H )
#define __VOS_TRACE_H

/**=========================================================================
  
  \file  vos_trace.h
  
  \brief virtual Operating System Servies (vOS)
               
   Trace, logging, and debugging definitions and APIs
  
<<<<<<< HEAD
=======
   Copyright 2008 (c) Qualcomm, Incorporated.  All Rights Reserved.
   
   Qualcomm Confidential and Proprietary.
  
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
  ========================================================================*/

/* $Header$ */

/*--------------------------------------------------------------------------
  Include Files
  ------------------------------------------------------------------------*/
#include  <vos_types.h>  // For VOS_MODULE_ID...
#include  <stdarg.h>       // For va_list...
<<<<<<< HEAD
#include  <vos_status.h>
#include  <i_vos_types.h>
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

/*-------------------------------------------------------------------------- 
  Type declarations 
  ------------------------------------------------------------------------*/

typedef enum 
{
   // NONE means NO traces will be logged.  This value is in place for the 
   // vos_trace_setlevel() to allow the user to turn off all traces.
   VOS_TRACE_LEVEL_NONE = 0,
   
   // the following trace levels are the ones that 'callers' of VOS_TRACE()
   // can specify in for the VOS_TRACE_LEVEL parameter.  Traces are classified
   // by severity (FATAL being more serious than INFO for example).   
   VOS_TRACE_LEVEL_FATAL,
   VOS_TRACE_LEVEL_ERROR, 
   VOS_TRACE_LEVEL_WARN,  
   VOS_TRACE_LEVEL_INFO,
   VOS_TRACE_LEVEL_INFO_HIGH,
   VOS_TRACE_LEVEL_INFO_MED,
   VOS_TRACE_LEVEL_INFO_LOW,
<<<<<<< HEAD
   VOS_TRACE_LEVEL_DEBUG,
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

   // ALL means all trace levels will be active.  This value is in place for the 
   // vos_trace_setlevel() to allow the user to turn ON all traces.
   VOS_TRACE_LEVEL_ALL, 

   
   // not a real level.  Used to identify the maximum number of 
   // VOS_TRACE_LEVELs defined.
   VOS_TRACE_LEVEL_MAX   
    
} VOS_TRACE_LEVEL;

/*-------------------------------------------------------------------------- 
  Preprocessor definitions and constants
  ------------------------------------------------------------------------*/
#define ASSERT_BUFFER_SIZE ( 512 )

// below definition is obsolete and is no longer being used in BMP and WM
// TODO: remove this once this is not used on Android
#define VOS_ENABLE_TRACING 
<<<<<<< HEAD
#define WCONN_TRACE_KMSG_LOG_BUFF
#define MAX_VOS_TRACE_RECORDS 4000
#define INVALID_VOS_TRACE_ADDR 0xffffffff
#define DEFAULT_VOS_TRACE_DUMP_COUNT 0

#include  <i_vos_trace.h>   

#ifdef TRACE_RECORD

#define MTRACE(p) p
#define NO_SESSION 0xFF

#else
#define MTRACE(p) {  }

#endif

/*--------------------------------------------------------------------------
  Structure definition
  ------------------------------------------------------------------------*/
typedef struct  svosTraceRecord
{
    v_U32_t time;
    v_U8_t module;
    v_U8_t code;
    v_U8_t session;
    v_U32_t data;
}tvosTraceRecord, *tpvosTraceRecord;

typedef struct svosTraceData
{
    // MTRACE logs are stored in ring buffer where head represents the position
    // of first record, tail represents the position of last record added till
    // now and num is the count of total record added.
    v_U32_t head;
    v_U32_t tail;
    v_U32_t num;
    v_U16_t numSinceLastDump;

    //Config for controlling the trace
    v_U8_t enable;
    v_U16_t dumpCount; //will dump after number of records reach this number.

}tvosTraceData;


=======

#include  <i_vos_trace.h>   

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
/*------------------------------------------------------------------------- 
  Function declarations and documenation
  ------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
  
  \brief vos_trace_setLevel() - Set the trace level for a particular module
  
  This is an external API that allows trace levels to be set for each module.
  
  \param level - trace level.   A member of the VOS_TRACE_LEVEL 
         enumeration indicating the severity of the condition causing the
         trace message to be issued.   More severe conditions are more 
         likely to be logged.
         
  \return  nothing
    
  \sa
  --------------------------------------------------------------------------*/
void vos_trace_setLevel( VOS_MODULE_ID module, VOS_TRACE_LEVEL level );

/**----------------------------------------------------------------------------
  
  \brief vos_trace_getLevel() - Get the trace level
  
  This is an external API that returns a boolean value to signify if a 
  particular trace level is set for the specified module.
  
  \param level - trace level.   A member of the VOS_TRACE_LEVEL enumeration 
                 indicating the severity of the condition causing the trace 
                 message to be issued.
         
                 Note that individual trace levels are the only valid values
                 for this API.  VOS_TRACE_LEVEL_NONE and VOS_TRACE_LEVEL_ALL
                 are not valid input and will return FALSE

  \return  VOS_FALSE - the specified trace level for the specified module is OFF 
    
           VOS_TRUE - the specified trace level for the specified module is ON
    
  \sa vos_trace_setLevel()
  --------------------------------------------------------------------------*/
v_BOOL_t vos_trace_getLevel( VOS_MODULE_ID module, VOS_TRACE_LEVEL level );

<<<<<<< HEAD
#ifdef WCONN_TRACE_KMSG_LOG_BUFF
/*--------------------------------------------------------------------------
 \brief vos_wconn_trace_init(); - Initializing the spinlock,
  Initialization would be called at the time of hdd_driver_init()

 \return - returns None
 --------------------------------------------------------------------------*/
void vos_wconn_trace_init(void);

/*--------------------------------------------------------------------------
 \brief vos_wconn_trace_exit(); - De-Initializing the spinlock,
  De-Initialization would be called at the time of hdd_driver_exit()

 \return - returns None
 --------------------------------------------------------------------------*/
void vos_wconn_trace_exit(void);
#endif

typedef void (*tpvosTraceCb) (void *pMac, tpvosTraceRecord, v_U16_t);
void vos_trace(v_U8_t module, v_U8_t code, v_U8_t session, v_U32_t data);
void vosTraceRegister(VOS_MODULE_ID, tpvosTraceCb);
VOS_STATUS vos_trace_spin_lock_init(void);
void vosTraceInit(void);
void vosTraceEnable(v_U32_t, v_U8_t enable);
void vosTraceDumpAll(void*, v_U8_t, v_U8_t, v_U32_t, v_U32_t);
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#endif
