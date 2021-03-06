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

#ifndef __VOSS_WRAPPER_H
#define __VOSS_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================
  @file VossWrapper.h

<<<<<<< HEAD
  @brief This header file contains the various structure definitions and
=======
  @brief This header file contains the various structure definitions and 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
  function prototypes for the RTOS abstraction layer, implemented for VOSS

  Copyright (c) 2008 QUALCOMM Incorporated.
  All Rights Reserved.
  Qualcomm Confidential and Proprietary
===========================================================================*/

<<<<<<< HEAD
/*===========================================================================

                       EDIT HISTORY FOR FILE


  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


  $Header:$ $DateTime: $ $Author: $


  when        who    what, where, why
=======
/*=========================================================================== 
    
                       EDIT HISTORY FOR FILE 
   
   
  This section contains comments describing changes made to the module. 
  Notice that changes are listed in reverse chronological order. 
   
   
  $Header:$ $DateTime: $ $Author: $ 
   
   
  when        who    what, where, why 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
  --------    ---    --------------------------------------------------------
  12/15/08    sho    Resolved warnings and errors from AMSS compiler when
                     this is ported to WM
  11/20/08    sho    Renamed this to VossWrapper.h; remove all dependencies
                     on WM platform and allow this to work on all VOSS enabled
                     platforms
<<<<<<< HEAD
  06/24/08    tbh    Modified the file to remove the dependecy on HDD files as
                     part of Gen6 bring up process.
  10/29/02 Neelay Das Created file.

===========================================================================*/
=======
  06/24/08    tbh    Modified the file to remove the dependecy on HDD files as 
                     part of Gen6 bring up process. 
  10/29/02 Neelay Das Created file. 
     
===========================================================================*/ 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

/*---------------------------------------------------------------------------
 * Include Files
 * ------------------------------------------------------------------------*/

#include "sirTypes.h"
#include "sirParams.h"
#include "sysDef.h"
<<<<<<< HEAD
=======
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
#include "halDataStruct.h"
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#include "aniDbgTest.h"
#include "vos_timer.h"
#include "palApi.h"
#include "vos_types.h"
<<<<<<< HEAD
#include "vos_trace.h"
#include "vos_memory.h"
=======
#ifdef FEATURE_WLAN_INTEGRATED_SOC
#include "vos_trace.h"
#include "vos_memory.h"
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

/* Interlocked Compare Exchange related definitions */



/* Define basic constants for the ThreadX kernel.  */

#define TX_NO_WAIT          0
#define TX_WAIT_FOREVER     0xFFFFFFFFUL
#define TX_AUTO_ACTIVATE    1
#define TX_NO_ACTIVATE      0



/* API return values.  */
#define TX_SUCCESS          0x00
#define TX_QUEUE_FULL    0x01
// ...
#define TX_NO_INSTANCE      0x0D
// ...
#define TX_TIMER_ERROR      0x15
#define TX_TICK_ERROR       0x16
// ...


#ifndef true
#define true                1
#endif

#ifndef false
#define false               0
#endif

/* Following macro specifies the number of milliseconds which constitute 1 ThreadX timer tick. Used
   for mimicking the ThreadX timer behaviour on VOSS. */
// Use the same MACRO used by firmware modules to calculate TICKs from mSec
// Mismatch would cause worng timer value to be programmed
#define TX_MSECS_IN_1_TICK  SYS_TICK_DUR_MS

// Signature with which the TX_TIMER struct is initialized, when the timer is created
#define TX_AIRGO_TMR_SIGNATURE   0xDEADBEEF

<<<<<<< HEAD
=======

/* Just #define out the thread and queue specific threadX calls, since the plan is to keep
   the Windows port of the MAC non-threaded */

#define  tx_thread_create(a, b, c, d, e, f, g, h, i)
#define  tx_thread_delete(a)
#define  tx_thread_resume(a)

// Please note that for the Windows implementation for this routine the time is specified in terms of
// microseconds and not timer ticks. Also, the DDK recommends that this routine should not be called with
// sleep durations of more than 50 usecs.
#define  tx_thread_sleep(uSecs)

#define  tx_thread_suspend(a)
#define  tx_thread_terminate(a)
#define  tx_thread_identify() NULL

#define  tx_queue_create(a, b, c, d, e) TX_SUCCESS
#define  tx_queue_delete(a) TX_SUCCESS
#define  tx_queue_get_ptr(a)    TX_SUCCESS
#define  tx_queue_flush(a)  TX_SUCCESS
#define  tx_queue_receive(a, b, c)  TX_SUCCESS
#define  tx_queue_send(a, b, c) TX_SUCCESS

#define  tx_disable_intr()
#define  tx_enable_intr() 


#define TX_DISABLE_INTR tx_disable_intr()
#define TX_ENABLE_INTR  tx_enable_intr()

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#ifdef TIMER_MANAGER
#define  tx_timer_create(a, b, c, d, e, f, g)   tx_timer_create_intern_debug((v_PVOID_t)pMac, a, b, c, d, e, f, g, __FILE__, __LINE__)
#else
#define  tx_timer_create(a, b, c, d, e, f, g)   tx_timer_create_intern((v_PVOID_t)pMac, a, b, c, d, e, f, g)
#endif

<<<<<<< HEAD
=======

/*-------------------------------------------------------------------------*/
/*  ThreadX structures are not mapped to Windows structures for the        */
/*  following reasons:                                                     */
/*      - Windows structures are written in C and they are not C++ aware.  */
/*      - There should not be any dependency between MAC FW include tree   */
/*        and Windows include tree.                                        */
/*                                                                         */
/*  Instead, ThreadX structures are defined here as void*.  This will be   */
/*  used by the wrapper functions to save the pointer of the actual Windows*/
/*  structure.  Windows structure is allocated in ?                        */
/*-------------------------------------------------------------------------*/

typedef v_PVOID_t TX_THREAD;
typedef v_PVOID_t TX_QUEUE;
typedef v_PVOID_t TX_MUTEX;

/*--------------------------------------------------------------------*/
/* Semaphore structure                                                */
/* This structure is used to mimic the binary semaphore functionality */
/* available on ThreadX.                                              */
/*--------------------------------------------------------------------*/
typedef v_SLONG_t TX_SEMAPHORE;

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
/*--------------------------------------------------------------------*/
/* Timer structure                                                    */
/* This structure is used to implement ThreadX timer facility.  Just  */
/* like ThreadX, timer expiration handler executes at the highest     */
/* possible priority level, i.e. DISPATCH_LEVEL.                      */
/*--------------------------------------------------------------------*/
typedef struct TX_TIMER_STRUCT
{
#ifdef WLAN_DEBUG
#define TIMER_MAX_NAME_LEN 50
    char timerName[TIMER_MAX_NAME_LEN];
#endif
    v_ULONG_t  tmrSignature;
    v_VOID_t   (*pExpireFunc)(v_PVOID_t, tANI_U32);
    tANI_U32   expireInput;
    v_ULONG_t  initScheduleTimeInMsecs;
    v_ULONG_t  rescheduleTimeInMsecs;
    vos_timer_t vosTimer;

    // Pointer to the MAC global structure, which stores the context for the NIC,
    // for which this timer is supposed to operate.
    v_PVOID_t  pMac;
    tANI_U8 sessionId;

} TX_TIMER;

#define TX_TIMER_VALID(timer) (timer.pMac != 0)

<<<<<<< HEAD
=======
typedef struct sAniSirTxWrapper
{
    // Back pointer to the pAdapter structure, needed for some of the internal routines
    v_PVOID_t  pAdapter;

} tAniSirTxWrapper, *tpAniSirTxWrapper;



>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
extern v_ULONG_t tx_time_get(v_VOID_t);
extern v_UINT_t  tx_timer_activate(TX_TIMER*);
extern v_UINT_t  tx_timer_change(TX_TIMER*, v_ULONG_t, v_ULONG_t);
extern v_UINT_t  tx_timer_change_context(TX_TIMER*, tANI_U32);
#ifdef TIMER_MANAGER
<<<<<<< HEAD
extern v_UINT_t  tx_timer_create_intern_debug(v_PVOID_t, TX_TIMER*, char *, v_VOID_t(*)(v_PVOID_t, tANI_U32),
=======
extern v_UINT_t  tx_timer_create_intern_debug(v_PVOID_t, TX_TIMER*, char *, v_VOID_t(*)(v_PVOID_t, tANI_U32), 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               tANI_U32, v_ULONG_t, v_ULONG_t, v_ULONG_t, char* fileName, v_U32_t lineNum );
#else
extern v_UINT_t  tx_timer_create_intern(v_PVOID_t, TX_TIMER*, char *, v_VOID_t(*)(v_PVOID_t, tANI_U32), tANI_U32, v_ULONG_t, v_ULONG_t, v_ULONG_t);
#endif
extern v_UINT_t  tx_timer_deactivate(TX_TIMER*);
extern v_UINT_t  tx_timer_delete(TX_TIMER*);
extern v_BOOL_t  tx_timer_running(TX_TIMER*);

<<<<<<< HEAD
=======


// Routines needed to initialize and cleanup the Windows wrapper
extern v_VOID_t tx_voss_wrapper_init(v_PVOID_t, v_PVOID_t);

#define schAddDphActivityQueueWin( a, b, c )

// Debug display related globals
extern v_ULONG_t gDbgLevel;
extern v_ULONG_t gDbgMask;
extern int gHalBufCnt;

/* forward declaration From HDDUtil.h used by some internal files */

extern v_U64_t utilGetCurrentTime(void);


>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#ifdef __cplusplus
}
#endif


#endif



