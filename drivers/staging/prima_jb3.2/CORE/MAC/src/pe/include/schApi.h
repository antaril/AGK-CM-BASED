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

/*
 *
 * Airgo Networks, Inc proprietary. All rights reserved.
 * Author:      Sandesh Goel
 * Date:        02/25/02
 * History:-
 * Date            Modified by    Modification Information
 * --------------------------------------------------------------------
 *
 */

#ifndef __SCH_API_H__
#define __SCH_API_H__

#include "sirCommon.h"
#include "sirMacProtDef.h"

#include "aniGlobal.h"

/// Send start scan response message
extern void schSendStartScanRsp(tpAniSirGlobal pMac);

<<<<<<< HEAD
=======
/// Set init time params
extern void schSetInitParams(tpAniSirGlobal pMac);

/// Set qos default params
extern void schUpdateQosInfo(tpAniSirGlobal pMac);

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
// update only the broadcast qos params
extern void schQosUpdateBroadcast(tpAniSirGlobal pMac, tpPESession psessionEntry);

// fill in the default local edca parameter into gLimEdcaParams[]
extern void schSetDefaultEdcaParams(tpAniSirGlobal pMac, tpPESession psessionE);

// update only local qos params
extern void schQosUpdateLocal(tpAniSirGlobal pMac, tpPESession psessionEntry);

// update the edca profile parameters
extern void schEdcaProfileUpdate(tpAniSirGlobal pMac, tpPESession psessionEntry);

<<<<<<< HEAD
=======
/// Check for RR timer expiry
extern void schCheckRRTimerExpiry(tpAniSirGlobal pMac);

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
/// Set the fixed fields in a beacon frame
extern tSirRetStatus schSetFixedBeaconFields(tpAniSirGlobal pMac,tpPESession psessionEntry);

/// Initializations
extern void schInitialize(tpAniSirGlobal pMac);

/// Initialize globals
extern void schInitGlobals(tpAniSirGlobal pMac);

/// Initialize CF Poll template
extern void schInitializeCfPollTemplate(tpAniSirGlobal pMac);

/// Initialize CF End template
extern void schInitializeCfEndTemplate(tpAniSirGlobal pMac);

<<<<<<< HEAD
/// Process the scheduler messages
extern void schProcessMessage(tpAniSirGlobal pMac,tpSirMsgQ pSchMsg);

=======
/// Process the transmit activity queue
extern void schProcessTxActivityQueue(tpAniSirGlobal pMac);

/// Add to the DPH activity queue
extern void schAddDphActivityQueue(tpAniSirGlobal pMac, tANI_U16, tANI_U8);

/// Add to the TX IN (DPH) activity queue
extern void schAddTxInActivityQueue(tpAniSirGlobal pMac, void *ptr);

/// Process the scheduler message queue
extern void schProcessMessageQueue(tpAniSirGlobal pMac);

/// Process the scheduler messages
extern void schProcessMessage(tpAniSirGlobal pMac,tpSirMsgQ pSchMsg);

/// Process the DPH activity queue
extern void schProcessDphActivityQueue(tpAniSirGlobal pMac);

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
/// The beacon Indication handler function
extern void schProcessPreBeaconInd(tpAniSirGlobal pMac, tpSirMsgQ limMsg);

/// Post a message to the scheduler message queue
extern tSirRetStatus schPostMessage(tpAniSirGlobal pMac, tpSirMsgQ pMsg);

<<<<<<< HEAD
=======
#if (WNI_POLARIS_FW_PRODUCT == AP)
/// The scheduling interrupt handler
extern void schSchedulingInterruptHandler(tpAniSirGlobal pMac);

/// The scheduling end interrupt function
extern void schSchedulingEndInterruptHandler(tpAniSirGlobal pMac);

/// Function used by other Sirius modules to read CFPcount
extern tANI_U8 schGetCFPCount(tpAniSirGlobal pMac);

/// Function used by other Sirius modules to read CFPDuration remaining
extern tANI_U16 schGetCFPDurRemaining(tpAniSirGlobal pMac);

#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

extern void schBeaconProcess(tpAniSirGlobal pMac, tANI_U8 *pRxPacketInfo, tpPESession psessionEntry);
extern tSirRetStatus schBeaconEdcaProcess(tpAniSirGlobal pMac, tSirMacEdcaParamSetIE *edca, tpPESession psessionEntry);


#define SCH_RR_TIMEOUT                   (SCH_RR_TIMEOUT_MS / SYS_TICK_DUR_MS)

void schSetBeaconInterval(tpAniSirGlobal pMac,tpPESession psessionEntry);

tSirRetStatus schSendBeaconReq( tpAniSirGlobal, tANI_U8 *, tANI_U16, tpPESession psessionEntry );

<<<<<<< HEAD
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
void limUpdateProbeRspTemplateIeBitmapBeacon1(tpAniSirGlobal,tDot11fBeacon1*,tANI_U32*,tDot11fProbeResponse*);
void limUpdateProbeRspTemplateIeBitmapBeacon2(tpAniSirGlobal,tDot11fBeacon2*,tANI_U32*,tDot11fProbeResponse*);
void SetProbeRspIeBitmap(tANI_U32*,tANI_U32);
tANI_U32 limSendProbeRspTemplateToHal(tpAniSirGlobal,tpPESession,
                                    tANI_U32*);
<<<<<<< HEAD
=======
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


#endif
