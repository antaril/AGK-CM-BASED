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
 * Airgo Networks, Inc proprietary. All rights reserved.
 * This file limProcessSmeReqMessages.cc contains the code
 * for processing SME request messages.
 * Author:        Chandra Modumudi
 * Date:          02/11/02
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 *
 */

#include "palTypes.h"
#include "wniApi.h"
<<<<<<< HEAD
#include "wniCfgSta.h"
=======
#ifdef ANI_PRODUCT_TYPE_AP
#include "wniCfgAp.h"
#else
#include "wniCfgSta.h"
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#include "cfgApi.h"
#include "sirApi.h"
#include "schApi.h"
#include "utilsApi.h"
#include "limTypes.h"
#include "limUtils.h"
#include "limAssocUtils.h"
#include "limSecurityUtils.h"
#include "limSerDesUtils.h"
#include "limSmeReqUtils.h"
#include "limIbssPeerMgmt.h"
#include "limAdmitControl.h"
#include "dphHashTable.h"
#include "limSendMessages.h"
#include "limApi.h"
#include "wmmApsd.h"

<<<<<<< HEAD
#include "sapApi.h"
=======
#ifdef WLAN_SOFTAP_FEATURE
#include "sapApi.h"
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

#if defined WLAN_FEATURE_VOWIFI
#include "rrmApi.h"
#endif
#if defined FEATURE_WLAN_CCX
#include "ccxApi.h"
#endif

#if defined WLAN_FEATURE_VOWIFI_11R
#include <limFT.h>
#endif

#ifdef FEATURE_WLAN_CCX
/* These are the min/max tx power (non virtual rates) range
   supported by prima hardware */
<<<<<<< HEAD
#define MIN_TX_PWR_CAP    8
#define MAX_TX_PWR_CAP    22

#endif

/* This overhead is time for sending NOA start to host in case of GO/sending NULL data & receiving ACK 
 * in case of P2P Client and starting actual scanning with init scan req/rsp plus in case of concurrency,
 * taking care of sending null data and receiving ACK to/from AP/Also SetChannel with calibration is taking
 * around 7ms .
 */
#define SCAN_MESSAGING_OVERHEAD             20      // in msecs
#define JOIN_NOA_DURATION                   2000    // in msecs
#define OEM_DATA_NOA_DURATION               60      // in msecs
#define DEFAULT_PASSIVE_MAX_CHANNEL_TIME    110     // in msecs

#define CONV_MS_TO_US 1024 //conversion factor from ms to us
=======
#define MIN_TX_PWR_CAP    12
#define MAX_TX_PWR_CAP    19

#endif

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

// SME REQ processing function templates
static void __limProcessSmeStartReq(tpAniSirGlobal, tANI_U32 *);
static tANI_BOOLEAN __limProcessSmeSysReadyInd(tpAniSirGlobal, tANI_U32 *);
static tANI_BOOLEAN __limProcessSmeStartBssReq(tpAniSirGlobal, tpSirMsgQ pMsg);
static void __limProcessSmeScanReq(tpAniSirGlobal, tANI_U32 *);
static void __limProcessSmeJoinReq(tpAniSirGlobal, tANI_U32 *);
static void __limProcessSmeReassocReq(tpAniSirGlobal, tANI_U32 *);
static void __limProcessSmeDisassocReq(tpAniSirGlobal, tANI_U32 *);
static void __limProcessSmeDisassocCnf(tpAniSirGlobal, tANI_U32 *);
static void __limProcessSmeDeauthReq(tpAniSirGlobal, tANI_U32 *);
static void __limProcessSmeSetContextReq(tpAniSirGlobal, tANI_U32 *);
static tANI_BOOLEAN __limProcessSmeStopBssReq(tpAniSirGlobal, tpSirMsgQ pMsg);

<<<<<<< HEAD
void __limProcessSmeAssocCnfNew(tpAniSirGlobal, tANI_U32, tANI_U32 *);

extern void peRegisterTLHandle(tpAniSirGlobal pMac);


=======
#if 0
  static void __limProcessSmeAuthReq(tpAniSirGlobal, tANI_U32 *);
  static void __limProcessSmePromiscuousReq(tpAniSirGlobal, tANI_U32 *);
#endif

#ifdef ANI_PRODUCT_TYPE_AP
static void __limProcessSmeAssocCnf(tpAniSirGlobal, tANI_U32, tANI_U32 *);
#endif
void __limProcessSmeAssocCnfNew(tpAniSirGlobal, tANI_U32, tANI_U32 *);

#ifdef VOSS_ENABLED
extern void peRegisterTLHandle(tpAniSirGlobal pMac);
#endif

#ifdef WLAN_FEATURE_P2P
extern int limProcessRemainOnChnlReq(tpAniSirGlobal pMac, tANI_U32 *pMsg);
#endif

#ifdef ANI_PRODUCT_TYPE_CLIENT
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#ifdef BACKGROUND_SCAN_ENABLED

// start the background scan timers if it hasn't already started
static void
__limBackgroundScanInitiate(tpAniSirGlobal pMac)
{
    if (pMac->lim.gLimBackgroundScanStarted)
        return;

    //make sure timer is created first
    if (TX_TIMER_VALID(pMac->lim.limTimers.gLimBackgroundScanTimer))
    {
        limDeactivateAndChangeTimer(pMac, eLIM_BACKGROUND_SCAN_TIMER);
     MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, NO_SESSION, eLIM_BACKGROUND_SCAN_TIMER));
        if (tx_timer_activate(&pMac->lim.limTimers.gLimBackgroundScanTimer) != TX_SUCCESS)
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("could not activate background scan timer"));
=======
            limLog(pMac, LOGP, FL("could not activate background scan timer\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        pMac->lim.gLimBackgroundScanStarted   = true;
        pMac->lim.gLimBackgroundScanChannelId = 0;
    }
}

#endif // BACKGROUND_SCAN_ENABLED
<<<<<<< HEAD
=======
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

// determine if a fresh scan request must be issued or not
/*
* PE will do fresh scan, if all of the active sessions are in good state (Link Est or BSS Started)
* If one of the sessions is not in one of the above states, then PE does not do fresh scan
* If no session exists (scanning very first time), then PE will always do fresh scan if SME
* asks it to do that.
*/
static tANI_U8
__limFreshScanReqd(tpAniSirGlobal pMac, tANI_U8 returnFreshResults)
{

    tANI_U8 validState = TRUE;
    int i;

    if(pMac->lim.gLimSmeState != eLIM_SME_IDLE_STATE)
    {
        return FALSE;
    }
    for(i =0; i < pMac->lim.maxBssId; i++)
    {

        if(pMac->lim.gpSession[i].valid == TRUE)
        {
            if(!( ( (  (pMac->lim.gpSession[i].bssType == eSIR_INFRASTRUCTURE_MODE) ||
                        (pMac->lim.gpSession[i].limSystemRole == eLIM_BT_AMP_STA_ROLE))&&
                       (pMac->lim.gpSession[i].limSmeState == eLIM_SME_LINK_EST_STATE) )||
                  
                  (    ( (pMac->lim.gpSession[i].bssType == eSIR_IBSS_MODE)||
                           (pMac->lim.gpSession[i].limSystemRole == eLIM_BT_AMP_AP_ROLE)||
                           (pMac->lim.gpSession[i].limSystemRole == eLIM_BT_AMP_STA_ROLE) )&&
                       (pMac->lim.gpSession[i].limSmeState == eLIM_SME_NORMAL_STATE) )
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_P2P
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               ||  ( ( ( (pMac->lim.gpSession[i].bssType == eSIR_INFRA_AP_MODE) 
                      && ( pMac->lim.gpSession[i].pePersona == VOS_P2P_GO_MODE) )
                    || (pMac->lim.gpSession[i].limSystemRole == eLIM_AP_ROLE) )
                  && (pMac->lim.gpSession[i].limSmeState == eLIM_SME_NORMAL_STATE) )
<<<<<<< HEAD
=======
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
             ))
                {
                validState = FALSE;
                break;
              }
            
        }
    }
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("FreshScanReqd: %d "), validState);)
=======
    PELOG1(limLog(pMac, LOG1, FL("FreshScanReqd: %d \n"), validState);)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

   if( (validState) && (returnFreshResults & SIR_BG_SCAN_RETURN_FRESH_RESULTS))
    return TRUE;

    return FALSE;
}

<<<<<<< HEAD
=======
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)
static tANI_BOOLEAN __limProcessSmeSwitchChlReq(tpAniSirGlobal, tpSirMsgQ pMsg);
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


/**
 * __limIsSmeAssocCnfValid()
 *
 *FUNCTION:
 * This function is called by limProcessLmmMessages() upon
 * receiving SME_ASSOC_CNF.
 *
 *LOGIC:
 * Message validity checks are performed in this function
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMeasReq  Pointer to Received ASSOC_CNF message
 * @return true      When received SME_ASSOC_CNF is formatted
 *                   correctly
 *         false     otherwise
 */

inline static tANI_U8
__limIsSmeAssocCnfValid(tpSirSmeAssocCnf pAssocCnf)
{
    if (limIsGroupAddr(pAssocCnf->peerMacAddr))
        return false;
    else
        return true;
} /*** end __limIsSmeAssocCnfValid() ***/


/**
 * __limGetSmeJoinReqSizeForAlloc()
 *
 *FUNCTION:
 * This function is called in various places to get IE length
 * from tSirBssDescription structure
 * number being scanned.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param     pBssDescr
 * @return    Total IE length
 */

static tANI_U16
__limGetSmeJoinReqSizeForAlloc(tANI_U8 *pBuf)
{
    tANI_U16 len = 0;

    if (!pBuf)
        return len;

    pBuf += sizeof(tANI_U16);
    len = limGetU16( pBuf );
    return (len + sizeof( tANI_U16 ));
} /*** end __limGetSmeJoinReqSizeForAlloc() ***/


/**----------------------------------------------------------------
\fn     __limIsDeferedMsgForLearn

\brief  Has role only if 11h is enabled. Not used on STA side.
        Defers the message if SME is in learn state and brings
        the LIM back to normal mode.

\param  pMac
\param  pMsg - Pointer to message posted from SME to LIM.
\return TRUE - If defered
        FALSE - Otherwise
------------------------------------------------------------------*/
static tANI_BOOLEAN
__limIsDeferedMsgForLearn(tpAniSirGlobal pMac, tpSirMsgQ pMsg)
{
    if (limIsSystemInScanState(pMac))
    {
        if (limDeferMsg(pMac, pMsg) != TX_SUCCESS)
        {
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("Could not defer Msg = %d"), pMsg->type);)
            return eANI_BOOLEAN_FALSE;
        }
        PELOG1(limLog(pMac, LOG1, FL("Defer the message, in learn mode type = %d"),
=======
            PELOGE(limLog(pMac, LOGE, FL("Could not defer Msg = %d\n"), pMsg->type);)
            return eANI_BOOLEAN_FALSE;
        }
        PELOG1(limLog(pMac, LOG1, FL("Defer the message, in learn mode type = %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                                                                 pMsg->type);)

        /** Send finish scan req to HAL only if LIM is not waiting for any response
         * from HAL like init scan rsp, start scan rsp etc.
         */        
        if (GET_LIM_PROCESS_DEFD_MESGS(pMac))
        {
            //Set the resume channel to Any valid channel (invalid). 
            //This will instruct HAL to set it to any previous valid channel.
            peSetResumeChannel(pMac, 0, 0);
            limSendHalFinishScanReq(pMac, eLIM_HAL_FINISH_LEARN_WAIT_STATE);
        }

        return eANI_BOOLEAN_TRUE;
    }
    return eANI_BOOLEAN_FALSE;
}

/**----------------------------------------------------------------
\fn     __limIsDeferedMsgForRadar

\brief  Has role only if 11h is enabled. Not used on STA side.
        Defers the message if radar is detected.

\param  pMac
\param  pMsg - Pointer to message posted from SME to LIM.
\return TRUE - If defered
        FALSE - Otherwise
------------------------------------------------------------------*/
static tANI_BOOLEAN
__limIsDeferedMsgForRadar(tpAniSirGlobal pMac, tpSirMsgQ pMsg)
{
    /** fRadarDetCurOperChan will be set only if we detect radar in current
     * operating channel and System Role == AP ROLE */
    //TODO: Need to take care radar detection.
    //if (LIM_IS_RADAR_DETECTED(pMac))
    if( 0 )
    {
        if (limDeferMsg(pMac, pMsg) != TX_SUCCESS)
        {
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("Could not defer Msg = %d"), pMsg->type);)
            return eANI_BOOLEAN_FALSE;
        }
        PELOG1(limLog(pMac, LOG1, FL("Defer the message, in learn mode type = %d"),
=======
            PELOGE(limLog(pMac, LOGE, FL("Could not defer Msg = %d\n"), pMsg->type);)
            return eANI_BOOLEAN_FALSE;
        }
        PELOG1(limLog(pMac, LOG1, FL("Defer the message, in learn mode type = %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                                                                 pMsg->type);)
        return eANI_BOOLEAN_TRUE;
    }
    return eANI_BOOLEAN_FALSE;
}


/**
 * __limProcessSmeStartReq()
 *
 *FUNCTION:
 * This function is called to process SME_START_REQ message
 * from HDD or upper layer application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limProcessSmeStartReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirResultCodes  retCode = eSIR_SME_SUCCESS;
    tANI_U8          smesessionId;
    tANI_U16         smetransactionId;
    

<<<<<<< HEAD
   PELOG1(limLog(pMac, LOG1, FL("Received START_REQ"));)
=======
   PELOG1(limLog(pMac, LOG1, FL("Received START_REQ\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    limGetSessionInfo(pMac,(tANI_U8 *)pMsgBuf,&smesessionId,&smetransactionId);
    
    if (pMac->lim.gLimSmeState == eLIM_SME_OFFLINE_STATE)
    {
        pMac->lim.gLimSmeState = eLIM_SME_IDLE_STATE;
        
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, NO_SESSION, pMac->lim.gLimSmeState));
        
        /// By default do not return after first scan match
        pMac->lim.gLimReturnAfterFirstMatch = 0;

        /// Initialize MLM state machine
        limInitMlm(pMac);

        /// By default return unique scan results
        pMac->lim.gLimReturnUniqueResults = true;
        pMac->lim.gLimSmeScanResultLength = 0;
<<<<<<< HEAD
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
        pMac->lim.gLimSmeLfrScanResultLength = 0;
#endif

=======

#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        if (((tSirSmeStartReq *) pMsgBuf)->sendNewBssInd)
        {
            /*
                     * Need to indicate new BSSs found during background scanning to
                     * host. Update this parameter at CFG
                     */
            if (cfgSetInt(pMac, WNI_CFG_NEW_BSS_FOUND_IND, ((tSirSmeStartReq *) pMsgBuf)->sendNewBssInd)
                != eSIR_SUCCESS)
            {
<<<<<<< HEAD
                limLog(pMac, LOGP, FL("could not set NEIGHBOR_BSS_IND at CFG"));
                retCode = eSIR_SME_UNEXPECTED_REQ_RESULT_CODE;
            }
        }
=======
                limLog(pMac, LOGP, FL("could not set NEIGHBOR_BSS_IND at CFG\n"));
                retCode = eSIR_SME_UNEXPECTED_REQ_RESULT_CODE;
            }
        }
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }
    else
    {
        /**
         * Should not have received eWNI_SME_START_REQ in states
         * other than OFFLINE. Return response to host and
         * log error
         */
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Invalid SME_START_REQ received in SME state %X"),pMac->lim.gLimSmeState );
=======
        limLog(pMac, LOGE, FL("Invalid SME_START_REQ received in SME state %X\n"),pMac->lim.gLimSmeState );
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limPrintSmeState(pMac, LOGE, pMac->lim.gLimSmeState);
        retCode = eSIR_SME_UNEXPECTED_REQ_RESULT_CODE;
    }
    limSendSmeRsp(pMac, eWNI_SME_START_RSP, retCode,smesessionId,smetransactionId);
} /*** end __limProcessSmeStartReq() ***/


/** -------------------------------------------------------------
\fn __limProcessSmeSysReadyInd
\brief handles the notification from HDD. PE just forwards this message to HAL.
\param   tpAniSirGlobal pMac
\param   tANI_U32* pMsgBuf
\return  TRUE-Posting to HAL failed, so PE will consume the buffer. 
\        FALSE-Posting to HAL successful, so HAL will consume the buffer.
  -------------------------------------------------------------*/
static tANI_BOOLEAN
__limProcessSmeSysReadyInd(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirMsgQ msg;
    
    msg.type = WDA_SYS_READY_IND;
    msg.reserved = 0;
    msg.bodyptr =  pMsgBuf;
    msg.bodyval = 0;

<<<<<<< HEAD
    if (pMac->gDriverType != eDRIVER_TYPE_MFG)
    {
        peRegisterTLHandle(pMac);
    }
    PELOGW(limLog(pMac, LOGW, FL("sending WDA_SYS_READY_IND msg to HAL"));)
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, msg.type));

    if (eSIR_SUCCESS != wdaPostCtrlMsg(pMac, &msg))
    {
        limLog(pMac, LOGP, FL("wdaPostCtrlMsg failed"));
=======
#ifdef VOSS_ENABLED
    if(pMac->gDriverType != eDRIVER_TYPE_MFG)
    {
    peRegisterTLHandle(pMac);
    }
#endif
    PELOGW(limLog(pMac, LOGW, FL("sending WDA_SYS_READY_IND msg to HAL\n"));)
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, msg.type));

    if(eSIR_SUCCESS != wdaPostCtrlMsg(pMac, &msg))
    {
        limLog(pMac, LOGP, FL("wdaPostCtrlMsg failed\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return eANI_BOOLEAN_TRUE;
    }
    return eANI_BOOLEAN_FALSE;
}

#ifdef WLAN_FEATURE_11AC

tANI_U32 limGetCenterChannel(tpAniSirGlobal pMac,tANI_U8 primarychanNum,ePhyChanBondState secondaryChanOffset, tANI_U8 chanWidth)
{
    if (chanWidth == WNI_CFG_VHT_CHANNEL_WIDTH_80MHZ)
    {
        switch(secondaryChanOffset)
        {
            case PHY_QUADRUPLE_CHANNEL_20MHZ_CENTERED_40MHZ_CENTERED:
                return primarychanNum;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_LOW_40MHZ_CENTERED:
               return primarychanNum + 2;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_HIGH_40MHZ_CENTERED:
               return primarychanNum - 2;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_LOW_40MHZ_LOW:
               return primarychanNum + 6;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_HIGH_40MHZ_LOW:
               return primarychanNum + 2;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_LOW_40MHZ_HIGH:
               return primarychanNum - 2;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_HIGH_40MHZ_HIGH:
               return primarychanNum - 6;
            default :
               return eSIR_CFG_INVALID_ID;
        }
    }
    else if (chanWidth == WNI_CFG_VHT_CHANNEL_WIDTH_20_40MHZ)
    {
        switch(secondaryChanOffset)
        {
            case PHY_DOUBLE_CHANNEL_LOW_PRIMARY:
                return primarychanNum + 2;
            case PHY_DOUBLE_CHANNEL_HIGH_PRIMARY:
                return primarychanNum - 2;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_CENTERED_40MHZ_CENTERED:
                return primarychanNum;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_LOW_40MHZ_CENTERED:
               return primarychanNum + 2;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_HIGH_40MHZ_CENTERED:
               return primarychanNum - 2;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_LOW_40MHZ_LOW:
               return primarychanNum + 2;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_HIGH_40MHZ_LOW:
               return primarychanNum - 2;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_LOW_40MHZ_HIGH:
               return primarychanNum + 2;
            case PHY_QUADRUPLE_CHANNEL_20MHZ_HIGH_40MHZ_HIGH:
               return primarychanNum - 2;
            default :
               return eSIR_CFG_INVALID_ID;
        }
    }
    return primarychanNum;
}

#endif
/**
 * __limHandleSmeStartBssRequest()
 *
 *FUNCTION:
 * This function is called to process SME_START_BSS_REQ message
 * from HDD or upper layer application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limHandleSmeStartBssRequest(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tANI_U16                size;
    tANI_U32                val = 0;
    tSirRetStatus           retStatus;
    tSirMacChanNum          channelNumber;
<<<<<<< HEAD
    tLimMlmStartReq         *pMlmStartReq = NULL;
    tpSirSmeStartBssReq     pSmeStartBssReq = NULL;
=======
    tLimMlmStartReq         *pMlmStartReq;
    tpSirSmeStartBssReq     pSmeStartBssReq;                //Local variable for Start BSS Req.. Added For BT-AMP Support 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    tSirResultCodes         retCode = eSIR_SME_SUCCESS;
    tANI_U32                autoGenBssId = FALSE;           //Flag Used in case of IBSS to Auto generate BSSID.
    tANI_U8                 sessionId;
    tpPESession             psessionEntry = NULL;
    tANI_U8                 smesessionId;
    tANI_U16                smetransactionId;

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    //Since the session is not created yet, sending NULL. The response should have the correct state.
    limDiagEventReport(pMac, WLAN_PE_DIAG_START_BSS_REQ_EVENT, NULL, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("Received START_BSS_REQ"));)
=======
    PELOG1(limLog(pMac, LOG1, FL("Received START_BSS_REQ\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    /* Global Sme state and mlm states are not defined yet , for BT-AMP Suppoprt . TO BE DONE */
    if ( (pMac->lim.gLimSmeState == eLIM_SME_OFFLINE_STATE) ||
         (pMac->lim.gLimSmeState == eLIM_SME_IDLE_STATE))
    {
        size = sizeof(tSirSmeStartBssReq) + SIR_MAC_MAX_IE_LENGTH;

<<<<<<< HEAD

        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSmeStartBssReq, size))
        {
            PELOGE(limLog(pMac, LOGE, FL("palAllocateMemory failed for pMac->lim.gpLimStartBssReq"));)
=======
#ifdef ANI_PRODUCT_TYPE_AP
        size + = ANI_WDS_INFO_MAX_LENGTH;
#endif

        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSmeStartBssReq, size))
        {
            PELOGE(limLog(pMac, LOGE, FL("palAllocateMemory failed for pMac->lim.gpLimStartBssReq\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            /// Send failure response to host
            retCode = eSIR_SME_RESOURCES_UNAVAILABLE;
            goto end;
        }
        
        (void) palZeroMemory(pMac->hHdd, (void *)pSmeStartBssReq, size);
        
        if ((limStartBssReqSerDes(pMac, pSmeStartBssReq, (tANI_U8 *) pMsgBuf) == eSIR_FAILURE) ||
                (!limIsSmeStartBssReqValid(pMac, pSmeStartBssReq)))
        {
<<<<<<< HEAD
            PELOGW(limLog(pMac, LOGW, FL("Received invalid eWNI_SME_START_BSS_REQ"));)
=======
            PELOGW(limLog(pMac, LOGW, FL("Received invalid eWNI_SME_START_BSS_REQ\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retCode = eSIR_SME_INVALID_PARAMETERS;
            goto free;
        }
#if 0   
       PELOG3(limLog(pMac, LOG3,
<<<<<<< HEAD
           FL("Parsed START_BSS_REQ fields are bssType=%d, channelId=%d"),
=======
           FL("Parsed START_BSS_REQ fields are bssType=%d, channelId=%d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           pMac->lim.gpLimStartBssReq->bssType, pMac->lim.gpLimStartBssReq->channelId);)
#endif 

        /* This is the place where PE is going to create a session.
         * If session is not existed , then create a new session */
        if((psessionEntry = peFindSessionByBssid(pMac,pSmeStartBssReq->bssId,&sessionId)) != NULL)
        {
<<<<<<< HEAD
            limLog(pMac, LOGW, FL("Session Already exists for given BSSID"));
=======
            limLog(pMac, LOGW, FL("Session Already exists for given BSSID\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retCode = eSIR_SME_BSS_ALREADY_STARTED_OR_JOINED;
            psessionEntry = NULL;
            goto free;
        }
        else
        {
            if((psessionEntry = peCreateSession(pMac,pSmeStartBssReq->bssId,&sessionId, pMac->lim.maxStation)) == NULL)
            {
<<<<<<< HEAD
                limLog(pMac, LOGW, FL("Session Can not be created "));
=======
                limLog(pMac, LOGW, FL("Session Can not be created \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                retCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                goto free;
            }

        }
     
        /* Store the session related parameters in newly created session */
        psessionEntry->pLimStartBssReq = pSmeStartBssReq;

        /* Store PE sessionId in session Table  */
        psessionEntry->peSessionId = sessionId;

        /* Store SME session Id in sessionTable */
        psessionEntry->smeSessionId = pSmeStartBssReq->sessionId;

        psessionEntry->transactionId = pSmeStartBssReq->transactionId;
                     
        sirCopyMacAddr(psessionEntry->selfMacAddr,pSmeStartBssReq->selfMacAddr);
        
        /* Copy SSID to session table */
        palCopyMemory( pMac->hHdd, (tANI_U8 *)&psessionEntry->ssId,
                     (tANI_U8 *)&pSmeStartBssReq->ssId,
                      (pSmeStartBssReq->ssId.length + 1));
        
       
        
        psessionEntry->bssType = pSmeStartBssReq->bssType;
        
        psessionEntry->nwType = pSmeStartBssReq->nwType;
        
        psessionEntry->beaconParams.beaconInterval = pSmeStartBssReq->beaconInterval;

        /* Store the channel number in session Table */
        psessionEntry->currentOperChannel = pSmeStartBssReq->channelId;

        /*Store Persona */
        psessionEntry->pePersona = pSmeStartBssReq->bssPersona;
        VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,FL("PE PERSONA=%d"),
            psessionEntry->pePersona);

        /*Update the phymode*/
        psessionEntry->gLimPhyMode = pSmeStartBssReq->nwType;

        psessionEntry->maxTxPower = cfgGetRegulatoryMaxTransmitPower( pMac, 
            psessionEntry->currentOperChannel );
        /* Store the dot 11 mode in to the session Table*/

        psessionEntry->dot11mode = pSmeStartBssReq->dot11mode;
        psessionEntry->htCapability = IS_DOT11_MODE_HT(psessionEntry->dot11mode);
#ifdef WLAN_FEATURE_11AC
        psessionEntry->vhtCapability = IS_DOT11_MODE_VHT(psessionEntry->dot11mode);
        VOS_TRACE(VOS_MODULE_ID_PE,VOS_TRACE_LEVEL_INFO,
            FL("*****psessionEntry->vhtCapability = %d"),psessionEntry->vhtCapability);
#endif
<<<<<<< HEAD

        psessionEntry->txLdpcIniFeatureEnabled = 
                                    pSmeStartBssReq->txLdpcIniFeatureEnabled;

=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        palCopyMemory(pMac->hHdd, (void*)&psessionEntry->rateSet,
            (void*)&pSmeStartBssReq->operationalRateSet,
            sizeof(tSirMacRateSet));
        palCopyMemory(pMac->hHdd, (void*)&psessionEntry->extRateSet,
            (void*)&pSmeStartBssReq->extendedRateSet,
            sizeof(tSirMacRateSet));

        switch(pSmeStartBssReq->bssType)
        {
<<<<<<< HEAD
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            case eSIR_INFRA_AP_MODE:
                 psessionEntry->limSystemRole = eLIM_AP_ROLE;
                 psessionEntry->privacy = pSmeStartBssReq->privacy;
                 psessionEntry->fwdWPSPBCProbeReq = pSmeStartBssReq->fwdWPSPBCProbeReq;
                 psessionEntry->authType = pSmeStartBssReq->authType;
                 /* Store the DTIM period */
                 psessionEntry->dtimPeriod = (tANI_U8)pSmeStartBssReq->dtimPeriod;
                 /*Enable/disable UAPSD*/
                 psessionEntry->apUapsdEnable = pSmeStartBssReq->apUapsdEnable;
                 if (psessionEntry->pePersona == VOS_P2P_GO_MODE)
                 {
                     psessionEntry->proxyProbeRspEn = 0;
                 }
                 else
                 {
                     /* To detect PBC overlap in SAP WPS mode, Host handles
                      * Probe Requests.
                      */
                     if(SAP_WPS_DISABLED == pSmeStartBssReq->wps_state)
                     {
                         psessionEntry->proxyProbeRspEn = 1;
                     }
                     else
                     {
                         psessionEntry->proxyProbeRspEn = 0;
                     }
                 }
                 psessionEntry->ssidHidden = pSmeStartBssReq->ssidHidden;
                 psessionEntry->wps_state = pSmeStartBssReq->wps_state;
<<<<<<< HEAD
                 psessionEntry->shortSlotTimeSupported = limGetShortSlotFromPhyMode(pMac, psessionEntry, psessionEntry->gLimPhyMode);
                 break;
=======
                 break;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            case eSIR_IBSS_MODE:
                 psessionEntry->limSystemRole = eLIM_STA_IN_IBSS_ROLE;
                 break;

            case eSIR_BTAMP_AP_MODE:
                 psessionEntry->limSystemRole = eLIM_BT_AMP_AP_ROLE;
                 break;

            case eSIR_BTAMP_STA_MODE:
                 psessionEntry->limSystemRole = eLIM_BT_AMP_STA_ROLE;
                 break;

                 /* There is one more mode called auto mode. which is used no where */

                 //FORBUILD -TEMPFIX.. HOW TO use AUTO MODE?????


            default:
                                   //not used anywhere...used in scan function
                 break;
        }

        // BT-AMP: Allocate memory for the array of parsed (Re)Assoc request structure
        if ( (pSmeStartBssReq->bssType == eSIR_BTAMP_AP_MODE)
<<<<<<< HEAD
        || (pSmeStartBssReq->bssType == eSIR_INFRA_AP_MODE)
=======
#ifdef WLAN_SOFTAP_FEATURE
        || (pSmeStartBssReq->bssType == eSIR_INFRA_AP_MODE)
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        )
        {
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&psessionEntry->parsedAssocReq,
                                                          (psessionEntry->dph.dphHashTable.size * sizeof(tpSirAssocReq)) ))
            {
<<<<<<< HEAD
                limLog(pMac, LOGW, FL("palAllocateMemory() failed"));
=======
                limLog(pMac, LOGW, FL("palAllocateMemory() failed\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                retCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                goto free;
            }
            palZeroMemory(pMac->hHdd, psessionEntry->parsedAssocReq, (psessionEntry->dph.dphHashTable.size * sizeof(tpSirAssocReq)) );
        }

        /* Channel Bonding is not addressd yet for BT-AMP Support.. sunit will address channel bonding   */
        if (pSmeStartBssReq->channelId)
        {
            channelNumber = pSmeStartBssReq->channelId;
            psessionEntry->htSupportedChannelWidthSet = (pSmeStartBssReq->cbMode)?1:0; // This is already merged value of peer and self - done by csr in csrGetCBModeFromIes
            psessionEntry->htRecommendedTxWidthSet = psessionEntry->htSupportedChannelWidthSet;
            psessionEntry->htSecondaryChannelOffset = pSmeStartBssReq->cbMode;
            VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,
                      FL("cbMode %u"), pSmeStartBssReq->cbMode);
#ifdef WLAN_FEATURE_11AC
            if(psessionEntry->vhtCapability)
            {
                tANI_U32 centerChan;
                tANI_U32 chanWidth;

                if (wlan_cfgGetInt(pMac, WNI_CFG_VHT_CHANNEL_WIDTH,
                          &chanWidth) != eSIR_SUCCESS)
                {
                    limLog(pMac, LOGP,
<<<<<<< HEAD
                      FL("Unable to retrieve Channel Width from CFG"));
=======
                      FL("Unable to retrieve Channel Width from CFG\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                }

                if(chanWidth == eHT_CHANNEL_WIDTH_20MHZ || chanWidth == eHT_CHANNEL_WIDTH_40MHZ)
                {
                    if (cfgSetInt(pMac, WNI_CFG_VHT_CHANNEL_WIDTH, WNI_CFG_VHT_CHANNEL_WIDTH_20_40MHZ)
                                                                     != eSIR_SUCCESS)
                    {
<<<<<<< HEAD
                        limLog(pMac, LOGP, FL("could not set  WNI_CFG_CHANNEL_BONDING_MODE at CFG"));
=======
                        limLog(pMac, LOGP, FL("could not set  WNI_CFG_CHANNEL_BONDING_MODE at CFG\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                        retCode = eSIR_LOGP_EXCEPTION;
                         goto free;
                    }
                }
                if (chanWidth == eHT_CHANNEL_WIDTH_80MHZ)
                {
                    if (cfgSetInt(pMac, WNI_CFG_VHT_CHANNEL_WIDTH, WNI_CFG_VHT_CHANNEL_WIDTH_80MHZ)
                                                                     != eSIR_SUCCESS)
                    {
<<<<<<< HEAD
                        limLog(pMac, LOGP, FL("could not set  WNI_CFG_CHANNEL_BONDING_MODE at CFG"));
=======
                        limLog(pMac, LOGP, FL("could not set  WNI_CFG_CHANNEL_BONDING_MODE at CFG\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                        retCode = eSIR_LOGP_EXCEPTION;
                         goto free;
                    }

                    centerChan = limGetCenterChannel(pMac,channelNumber,pSmeStartBssReq->cbMode,WNI_CFG_VHT_CHANNEL_WIDTH_80MHZ);
                    if(centerChan != eSIR_CFG_INVALID_ID)
                    {
<<<<<<< HEAD
                        limLog(pMac, LOGW, FL("***Center Channel for 80MHZ channel width = %ld"),centerChan);
                        psessionEntry->apCenterChan = centerChan;
                        if (cfgSetInt(pMac, WNI_CFG_VHT_CHANNEL_CENTER_FREQ_SEGMENT1, centerChan)
                                                                     != eSIR_SUCCESS)
                        {
                            limLog(pMac, LOGP, FL("could not set  WNI_CFG_CHANNEL_BONDING_MODE at CFG"));
=======
                        limLog(pMac, LOGW, FL("***Center Channel for 80MHZ channel width = %ld\n"),centerChan);
                        if (cfgSetInt(pMac, WNI_CFG_VHT_CHANNEL_CENTER_FREQ_SEGMENT1, centerChan)
                                                                     != eSIR_SUCCESS)
                        {
                            limLog(pMac, LOGP, FL("could not set  WNI_CFG_CHANNEL_BONDING_MODE at CFG\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                            retCode = eSIR_LOGP_EXCEPTION;
                            goto free;
                        }
                    }
                }

                /* All the translation is done by now for gVhtChannelWidth from .ini file to 
                 * the actual values as defined in spec. So, grabing the spec value which is 
                 * updated in .dat file by the above logic */
                if (wlan_cfgGetInt(pMac, WNI_CFG_VHT_CHANNEL_WIDTH,
                                   &chanWidth) != eSIR_SUCCESS)
                {
                    limLog(pMac, LOGP,
<<<<<<< HEAD
                      FL("Unable to retrieve Channel Width from CFG"));
                }
                /*For Sta+p2p-Go concurrency  
                  vhtTxChannelWidthSet is used for storing p2p-GO channel width
                  apChanWidth is used for storing the AP channel width that the Sta is going to associate.
                  Initialize the apChanWidth same as p2p-GO channel width this gets over written once the station joins the AP
                */
                psessionEntry->vhtTxChannelWidthSet = chanWidth;
                psessionEntry->apChanWidth = chanWidth;         
=======
                      FL("Unable to retrieve Channel Width from CFG\n"));
                }

                psessionEntry->vhtTxChannelWidthSet = chanWidth;
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            }
            psessionEntry->htSecondaryChannelOffset = limGetHTCBState(pSmeStartBssReq->cbMode);
#endif
        }
        else
        {
<<<<<<< HEAD
            PELOGW(limLog(pMac, LOGW, FL("Received invalid eWNI_SME_START_BSS_REQ"));)
=======
            PELOGW(limLog(pMac, LOGW, FL("Received invalid eWNI_SME_START_BSS_REQ\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retCode = eSIR_SME_INVALID_PARAMETERS;
            goto free;
        }

        // Delete pre-auth list if any
        limDeletePreAuthList(pMac);

        // Delete IBSS peer BSSdescription list if any
        //limIbssDelete(pMac); sep 26 review



#ifdef FIXME_GEN6   //following code may not be required. limInitMlm is now being invoked during peStart
        /// Initialize MLM state machine
        limInitMlm(pMac);
#endif

        psessionEntry->htCapability = IS_DOT11_MODE_HT(pSmeStartBssReq->dot11mode);

<<<<<<< HEAD
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            /* keep the RSN/WPA IE information in PE Session Entry
             * later will be using this to check when received (Re)Assoc req
             * */
        limSetRSNieWPAiefromSmeStartBSSReqMessage(pMac,&pSmeStartBssReq->rsnIE,psessionEntry);

<<<<<<< HEAD

=======
#endif

#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        //Taken care for only softAP case rest need to be done
        if (psessionEntry->limSystemRole == eLIM_AP_ROLE){
            psessionEntry->gLimProtectionControl =  pSmeStartBssReq->protEnabled;
            /*each byte will have the following info
             *bit7       bit6    bit5   bit4 bit3   bit2  bit1 bit0
             *reserved reserved RIFS Lsig n-GF ht20 11g 11b*/
            palCopyMemory( pMac->hHdd, (void *) &psessionEntry->cfgProtection,
                          (void *) &pSmeStartBssReq->ht_capab,
                          sizeof( tCfgProtection ));
            psessionEntry->pAPWPSPBCSession = NULL; // Initialize WPS PBC session link list
        }
<<<<<<< HEAD
=======
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        // Prepare and Issue LIM_MLM_START_REQ to MLM
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmStartReq, sizeof(tLimMlmStartReq)))
        {
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for mlmStartReq"));
=======
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for mlmStartReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retCode = eSIR_SME_RESOURCES_UNAVAILABLE;
            goto free;
        }

        (void)palZeroMemory(pMac->hHdd, (void *) pMlmStartReq, sizeof(tLimMlmStartReq));

        /* Copy SSID to the MLM start structure */
        palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmStartReq->ssId,
                          (tANI_U8 *) &pSmeStartBssReq->ssId,
                          pSmeStartBssReq->ssId.length + 1);
<<<<<<< HEAD
        pMlmStartReq->ssidHidden = pSmeStartBssReq->ssidHidden;
        pMlmStartReq->obssProtEnabled = pSmeStartBssReq->obssProtEnabled;
=======
#ifdef WLAN_SOFTAP_FEATURE
        pMlmStartReq->ssidHidden = pSmeStartBssReq->ssidHidden;
        pMlmStartReq->obssProtEnabled = pSmeStartBssReq->obssProtEnabled;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


        pMlmStartReq->bssType = psessionEntry->bssType;

        /* Fill PE session Id from the session Table */
        pMlmStartReq->sessionId = psessionEntry->peSessionId;

        if( (pMlmStartReq->bssType == eSIR_BTAMP_STA_MODE) || (pMlmStartReq->bssType == eSIR_BTAMP_AP_MODE )
<<<<<<< HEAD
            || (pMlmStartReq->bssType == eSIR_INFRA_AP_MODE)
=======
#ifdef WLAN_SOFTAP_FEATURE
            || (pMlmStartReq->bssType == eSIR_INFRA_AP_MODE)
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        )
        {
            //len = sizeof(tSirMacAddr);
            //retStatus = wlan_cfgGetStr(pMac, WNI_CFG_STA_ID, (tANI_U8 *) pMlmStartReq->bssId, &len);
            //if (retStatus != eSIR_SUCCESS)
<<<<<<< HEAD
            //limLog(pMac, LOGP, FL("could not retrive BSSID, retStatus=%d"), retStatus);
=======
            //limLog(pMac, LOGP, FL("could not retrive BSSID, retStatus=%d\n"), retStatus);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

            /* Copy the BSSId from sessionTable to mlmStartReq struct */
            sirCopyMacAddr(pMlmStartReq->bssId,psessionEntry->bssId);
        }

        else // ibss mode
        {
            pMac->lim.gLimIbssCoalescingHappened = false;

            if((retStatus = wlan_cfgGetInt(pMac, WNI_CFG_IBSS_AUTO_BSSID, &autoGenBssId)) != eSIR_SUCCESS)
            {
<<<<<<< HEAD
                limLog(pMac, LOGP, FL("Could not retrieve Auto Gen BSSID, retStatus=%d"), retStatus);
=======
                limLog(pMac, LOGP, FL("Could not retrieve Auto Gen BSSID, retStatus=%d\n"), retStatus);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                retCode = eSIR_LOGP_EXCEPTION;
                goto free;
            }

            if(!autoGenBssId)
            {   
                // We're not auto generating BSSID. Instead, get it from session entry
                sirCopyMacAddr(pMlmStartReq->bssId,psessionEntry->bssId);
                
                if(pMlmStartReq->bssId[0] & 0x01)
                {
<<<<<<< HEAD
                   PELOGE(limLog(pMac, LOGE, FL("Request to start IBSS with group BSSID\n Autogenerating the BSSID"));)
=======
                   PELOGE(limLog(pMac, LOGE, FL("Request to start IBSS with group BSSID\n Autogenerating the BSSID\n"));)                    
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                   autoGenBssId = TRUE;
                }             
            }

            if( autoGenBssId )
            {   //if BSSID is not any uc id. then use locally generated BSSID.
                //Autogenerate the BSSID
                limGetRandomBssid( pMac, pMlmStartReq->bssId);
                pMlmStartReq->bssId[0]= 0x02;
                
                /* Copy randomly generated BSSID to the session Table */
                sirCopyMacAddr(psessionEntry->bssId,pMlmStartReq->bssId);
            }
        }
        /* store the channel num in mlmstart req structure */
        pMlmStartReq->channelNumber = psessionEntry->currentOperChannel;
        pMlmStartReq->cbMode = pSmeStartBssReq->cbMode;        
        pMlmStartReq->beaconPeriod = psessionEntry->beaconParams.beaconInterval;

<<<<<<< HEAD
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        if(psessionEntry->limSystemRole == eLIM_AP_ROLE ){
            pMlmStartReq->dtimPeriod = psessionEntry->dtimPeriod;
            pMlmStartReq->wps_state = psessionEntry->wps_state;

        }else
<<<<<<< HEAD
        {
            if (wlan_cfgGetInt(pMac, WNI_CFG_DTIM_PERIOD, &val) != eSIR_SUCCESS)
                limLog(pMac, LOGP, FL("could not retrieve DTIM Period"));
=======
#endif        
        {
            if (wlan_cfgGetInt(pMac, WNI_CFG_DTIM_PERIOD, &val) != eSIR_SUCCESS)
                limLog(pMac, LOGP, FL("could not retrieve DTIM Period\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pMlmStartReq->dtimPeriod = (tANI_U8)val;
        }   
            
        if (wlan_cfgGetInt(pMac, WNI_CFG_CFP_PERIOD, &val) != eSIR_SUCCESS)
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("could not retrieve Beacon interval"));
        pMlmStartReq->cfParamSet.cfpPeriod = (tANI_U8)val;
            
        if (wlan_cfgGetInt(pMac, WNI_CFG_CFP_MAX_DURATION, &val) != eSIR_SUCCESS)
            limLog(pMac, LOGP, FL("could not retrieve CFPMaxDuration"));
=======
            limLog(pMac, LOGP, FL("could not retrieve Beacon interval\n"));
        pMlmStartReq->cfParamSet.cfpPeriod = (tANI_U8)val;
            
        if (wlan_cfgGetInt(pMac, WNI_CFG_CFP_MAX_DURATION, &val) != eSIR_SUCCESS)
            limLog(pMac, LOGP, FL("could not retrieve CFPMaxDuration\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        pMlmStartReq->cfParamSet.cfpMaxDuration = (tANI_U16) val;
        
        //this may not be needed anymore now, as rateSet is now included in the session entry and MLM has session context.
        palCopyMemory(pMac->hHdd, (void*)&pMlmStartReq->rateSet, (void*)&psessionEntry->rateSet,
                       sizeof(tSirMacRateSet));

                      
        // Now populate the 11n related parameters
        pMlmStartReq->nwType    = psessionEntry->nwType;
        pMlmStartReq->htCapable = psessionEntry->htCapability;
        //
        // FIXME_GEN4 - Determine the appropriate defaults...
        //
        pMlmStartReq->htOperMode        = pMac->lim.gHTOperMode;
        pMlmStartReq->dualCTSProtection = pMac->lim.gHTDualCTSProtection; // Unused
        pMlmStartReq->txChannelWidthSet = psessionEntry->htRecommendedTxWidthSet;

        /* sep26 review */
        psessionEntry->limRFBand = limGetRFBand(channelNumber);

        // Initialize 11h Enable Flag
        psessionEntry->lim11hEnable = 0;
        if((pMlmStartReq->bssType != eSIR_IBSS_MODE) &&
            (SIR_BAND_5_GHZ == psessionEntry->limRFBand) )
        {
            if (wlan_cfgGetInt(pMac, WNI_CFG_11H_ENABLED, &val) != eSIR_SUCCESS)
<<<<<<< HEAD
                limLog(pMac, LOGP, FL("Fail to get WNI_CFG_11H_ENABLED "));
=======
                limLog(pMac, LOGP, FL("Fail to get WNI_CFG_11H_ENABLED \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            psessionEntry->lim11hEnable = val;
        }
            
        if (!psessionEntry->lim11hEnable)
        {
            if (cfgSetInt(pMac, WNI_CFG_LOCAL_POWER_CONSTRAINT, 0) != eSIR_SUCCESS)
<<<<<<< HEAD
                limLog(pMac, LOGP, FL("Fail to get WNI_CFG_11H_ENABLED "));
=======
                limLog(pMac, LOGP, FL("Fail to get WNI_CFG_11H_ENABLED \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        }

        psessionEntry ->limPrevSmeState = psessionEntry->limSmeState;
        psessionEntry ->limSmeState     =  eLIM_SME_WT_START_BSS_STATE;
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry ->limSmeState));

        limPostMlmMessage(pMac, LIM_MLM_START_REQ, (tANI_U32 *) pMlmStartReq);
        return;
    }
    else
    {
       
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Received unexpected START_BSS_REQ, in state %X"),pMac->lim.gLimSmeState);
=======
        limLog(pMac, LOGE, FL("Received unexpected START_BSS_REQ, in state %X\n"),pMac->lim.gLimSmeState);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        retCode = eSIR_SME_BSS_ALREADY_STARTED_OR_JOINED;
        goto end;
    } // if (pMac->lim.gLimSmeState == eLIM_SME_OFFLINE_STATE)

free:
<<<<<<< HEAD
    if ((psessionEntry != NULL) &&
        (psessionEntry->pLimStartBssReq == pSmeStartBssReq))
    {
        psessionEntry->pLimStartBssReq = NULL;
    }
    palFreeMemory(pMac->hHdd, pSmeStartBssReq);
    palFreeMemory(pMac->hHdd, pMlmStartReq);
=======
    palFreeMemory( pMac->hHdd, pSmeStartBssReq);
    pSmeStartBssReq = NULL;
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

end:

    /* This routine should return the sme sessionId and SME transaction Id */
    limGetSessionInfo(pMac,(tANI_U8*)pMsgBuf,&smesessionId,&smetransactionId); 
    
    if(NULL != psessionEntry)
    {
        peDeleteSession(pMac,psessionEntry);
        psessionEntry = NULL;
    }     
    limSendSmeStartBssRsp(pMac, eWNI_SME_START_BSS_RSP, retCode,psessionEntry,smesessionId,smetransactionId);
} /*** end __limHandleSmeStartBssRequest() ***/


/**--------------------------------------------------------------
\fn     __limProcessSmeStartBssReq

\brief  Wrapper for the function __limHandleSmeStartBssRequest
        This message will be defered until softmac come out of
        scan mode or if we have detected radar on the current
        operating channel.
\param  pMac
\param  pMsg

\return TRUE - If we consumed the buffer
        FALSE - If have defered the message.
 ---------------------------------------------------------------*/
static tANI_BOOLEAN
__limProcessSmeStartBssReq(tpAniSirGlobal pMac, tpSirMsgQ pMsg)
{
    if (__limIsDeferedMsgForLearn(pMac, pMsg) ||
            __limIsDeferedMsgForRadar(pMac, pMsg))
    {
        /**
         * If message defered, buffer is not consumed yet.
         * So return false
         */
        return eANI_BOOLEAN_FALSE;
    }

    __limHandleSmeStartBssRequest(pMac, (tANI_U32 *) pMsg->bodyptr);
    return eANI_BOOLEAN_TRUE;
}


/**
 *  limGetRandomBssid()
 *
 *  FUNCTION:This function is called to process generate the random number for bssid
 *  This function is called to process SME_SCAN_REQ message
 *  from HDD or upper layer application.
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 * 1. geneartes the unique random number for bssid in ibss
 *
 *  @param  pMac      Pointer to Global MAC structure
 *  @param  *data      Pointer to  bssid  buffer
 *  @return None
 */
void limGetRandomBssid(tpAniSirGlobal pMac, tANI_U8 *data)
{
     tANI_U32 random[2] ;
     random[0] = tx_time_get();
     random[0] |= (random[0] << 15) ;
     random[1] = random[0] >> 1;
     palCopyMemory(pMac->hHdd, data, (tANI_U8*)random, sizeof(tSirMacAddr));
}

<<<<<<< HEAD
=======

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
/**
 * __limProcessSmeScanReq()
 *
 *FUNCTION:
 * This function is called to process SME_SCAN_REQ message
 * from HDD or upper layer application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 * 1. Periodic scanning should be requesting to return unique
 *    scan results.
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limProcessSmeScanReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tANI_U32            len;
    tLimMlmScanReq      *pMlmScanReq;
    tpSirSmeScanReq     pScanReq;
    tANI_U8             i = 0;

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_SCAN_REQ_EVENT, NULL, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    
    pScanReq = (tpSirSmeScanReq) pMsgBuf;   
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("SME SCAN REQ numChan %d min %d max %d IELen %d first %d fresh %d unique %d type %d mode %d rsp %d"),
=======
    PELOG1(limLog(pMac, LOG1, FL("SME SCAN REQ numChan %d min %d max %d IELen %d first %d fresh %d unique %d type %d mode %d rsp %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           pScanReq->channelList.numChannels,
           pScanReq->minChannelTime,
           pScanReq->maxChannelTime,
           pScanReq->uIEFieldLen, 
           pScanReq->returnAfterFirstMatch,
           pScanReq->returnFreshResults,
           pScanReq->returnUniqueResults,
           pScanReq->scanType,
           pScanReq->backgroundScanMode,
           pMac->lim.gLimRspReqd ? 1 : 0);)
<<<<<<< HEAD

    /* Since scan req always requires a response, we will overwrite response required here.
     * This is added esp to take care of the condition where in p2p go case, we hold the scan req and
     * insert single NOA. We send the held scan request to FW later on getting start NOA ind from FW so
     * we lose state of the gLimRspReqd flag for the scan req if any other request comes by then.
     * e.g. While unit testing, we found when insert single NOA is done, we see a get stats request which turns the flag
     * gLimRspReqd to FALSE; now when we actually start the saved scan req for init scan after getting
     * NOA started, the gLimRspReqd being a global flag is showing FALSE instead of TRUE value for 
     * this saved scan req. Since all scan reqs coming to lim require a response, there is no harm in setting
     * the global flag gLimRspReqd to TRUE here.
     */
     pMac->lim.gLimRspReqd = TRUE;

=======
        
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    /*copy the Self MAC address from SmeReq to the globalplace , used for sending probe req.discussed on code review sep18*/
    sirCopyMacAddr(pMac->lim.gSelfMacAddr,  pScanReq->selfMacAddr);

   /* This routine should return the sme sessionId and SME transaction Id */
       
    if (!limIsSmeScanReqValid(pMac, pScanReq))
    {
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("Received SME_SCAN_REQ with invalid parameters"));)
=======
        PELOGW(limLog(pMac, LOGW, FL("Received SME_SCAN_REQ with invalid parameters\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        if (pMac->lim.gLimRspReqd)
        {
            pMac->lim.gLimRspReqd = false;

            limSendSmeScanRsp(pMac, sizeof(tSirSmeScanRsp), eSIR_SME_INVALID_PARAMETERS, pScanReq->sessionId, pScanReq->transactionId);

        } // if (pMac->lim.gLimRspReqd)

        return;
    }

    //if scan is disabled then return as invalid scan request.
    //if scan in power save is disabled, and system is in power save mode, then ignore scan request.
    if( (pMac->lim.fScanDisabled) || (!pMac->lim.gScanInPowersave && !limIsSystemInActiveState(pMac))  )
    {
<<<<<<< HEAD
        limSendSmeScanRsp(pMac, offsetof(tSirSmeScanRsp,bssDescription[0]), eSIR_SME_INVALID_PARAMETERS, pScanReq->sessionId, pScanReq->transactionId);
=======
        limSendSmeScanRsp(pMac, 8, eSIR_SME_INVALID_PARAMETERS, pScanReq->sessionId, pScanReq->transactionId);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }
    

    /**
     * If scan request is received in idle, joinFailed
     * states or in link established state (in STA role)
     * or in normal state (in STA-in-IBSS/AP role) with
     * 'return fresh scan results' request from HDD or
     * it is periodic background scanning request,
     * trigger fresh scan request to MLM
     */
  if (__limFreshScanReqd(pMac, pScanReq->returnFreshResults))
  {
        #if 0   
        // Update global SME state
        pMac->lim.gLimPrevSmeState = pMac->lim.gLimSmeState;
        if ((pMac->lim.gLimSmeState == eLIM_SME_IDLE_STATE) ||
            (pMac->lim.gLimSmeState == eLIM_SME_JOIN_FAILURE_STATE))
            pMac->lim.gLimSmeState = eLIM_SME_WT_SCAN_STATE;
        else if (pMac->lim.gLimSmeState == eLIM_SME_NORMAL_STATE)
            pMac->lim.gLimSmeState = eLIM_SME_NORMAL_CHANNEL_SCAN_STATE;
        else
            
        #endif //TO SUPPORT BT-AMP

        /*Change Global SME state  */

        /* Store the previous SME state */

         pMac->lim.gLimPrevSmeState = pMac->lim.gLimSmeState;
        
        pMac->lim.gLimSmeState = eLIM_SME_WT_SCAN_STATE;
<<<<<<< HEAD
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, pScanReq->sessionId, pMac->lim.gLimSmeState));
=======
        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, NO_SESSION, pMac->lim.gLimSmeState));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        if (pScanReq->returnFreshResults & SIR_BG_SCAN_PURGE_RESUTLS)
        {
            // Discard previously cached scan results
            limReInitScanResults(pMac);
        }

        pMac->lim.gLim24Band11dScanDone     = 0;
        pMac->lim.gLim50Band11dScanDone     = 0;
        pMac->lim.gLimReturnAfterFirstMatch =
                                    pScanReq->returnAfterFirstMatch;
        pMac->lim.gLimBackgroundScanMode =
                                    pScanReq->backgroundScanMode;

        pMac->lim.gLimReturnUniqueResults   =
              ((pScanReq->returnUniqueResults) > 0 ? true : false);
        /* De-activate Heartbeat timers for connected sessions while
         * scan is in progress if the system is in Active mode *
         * AND it is not a ROAMING ("background") scan */
        if(((ePMM_STATE_BMPS_WAKEUP == pMac->pmm.gPmmState) ||
<<<<<<< HEAD
           (ePMM_STATE_READY == pMac->pmm.gPmmState)) &&
           (pScanReq->backgroundScanMode != eSIR_ROAMING_SCAN ) &&
           (!IS_ACTIVEMODE_OFFLOAD_FEATURE_ENABLE))
=======
           (ePMM_STATE_READY == pMac->pmm.gPmmState))
            && (pScanReq->backgroundScanMode != eSIR_ROAMING_SCAN ))
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        {
          for(i=0;i<pMac->lim.maxBssId;i++)
          {
            if((peFindSessionBySessionId(pMac,i) != NULL) &&
               (pMac->lim.gpSession[i].valid == TRUE) &&
               (eLIM_MLM_LINK_ESTABLISHED_STATE == pMac->lim.gpSession[i].limMlmState))
            {
               limHeartBeatDeactivateAndChangeTimer(pMac, peFindSessionBySessionId(pMac,i));
            }   
          }
        }

        if (pScanReq->channelList.numChannels == 0)
        {
            tANI_U32            cfg_len;
            // Scan all channels
            len = sizeof(tLimMlmScanReq) + 
                  (sizeof( pScanReq->channelList.channelNumber ) * (WNI_CFG_VALID_CHANNEL_LIST_LEN - 1)) +
                  pScanReq->uIEFieldLen;
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmScanReq, len) )
            {
                // Log error
                limLog(pMac, LOGP,
<<<<<<< HEAD
                       FL("call to palAllocateMemory failed for mlmScanReq (%d)"), len);
=======
                       FL("call to palAllocateMemory failed for mlmScanReq (%d)\n"), len);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

                return;
            }

            // Initialize this buffer
            palZeroMemory( pMac->hHdd, (tANI_U8 *) pMlmScanReq, len );

            cfg_len = WNI_CFG_VALID_CHANNEL_LIST_LEN;
            if (wlan_cfgGetStr(pMac, WNI_CFG_VALID_CHANNEL_LIST,
                          pMlmScanReq->channelList.channelNumber,
                          &cfg_len) != eSIR_SUCCESS)
            {
                /**
                 * Could not get Valid channel list from CFG.
                 * Log error.
                 */
                limLog(pMac, LOGP,
<<<<<<< HEAD
                       FL("could not retrieve Valid channel list"));
=======
                       FL("could not retrieve Valid channel list\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            }
            pMlmScanReq->channelList.numChannels = (tANI_U8) cfg_len;
        }
        else
        {
            len = sizeof( tLimMlmScanReq ) - sizeof( pScanReq->channelList.channelNumber ) + 
                   (sizeof( pScanReq->channelList.channelNumber ) * pScanReq->channelList.numChannels ) +
                   pScanReq->uIEFieldLen;

            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmScanReq, len) )
            {
                // Log error
                limLog(pMac, LOGP,
<<<<<<< HEAD
                    FL("call to palAllocateMemory failed for mlmScanReq(%d)"), len);
=======
                    FL("call to palAllocateMemory failed for mlmScanReq(%d)\n"), len);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

                return;
            }

            // Initialize this buffer
            palZeroMemory( pMac->hHdd, (tANI_U8 *) pMlmScanReq, len);
            pMlmScanReq->channelList.numChannels =
                            pScanReq->channelList.numChannels;

            palCopyMemory( pMac->hHdd, pMlmScanReq->channelList.channelNumber,
                          pScanReq->channelList.channelNumber,
                          pScanReq->channelList.numChannels);
        }

        pMlmScanReq->uIEFieldLen = pScanReq->uIEFieldLen;
        pMlmScanReq->uIEFieldOffset = len - pScanReq->uIEFieldLen;
        
        if(pScanReq->uIEFieldLen)
        {
            palCopyMemory( pMac->hHdd, (tANI_U8 *)pMlmScanReq+ pMlmScanReq->uIEFieldOffset,
                          (tANI_U8 *)pScanReq+(pScanReq->uIEFieldOffset),
                          pScanReq->uIEFieldLen);
        }

        pMlmScanReq->bssType = pScanReq->bssType;
        palCopyMemory( pMac->hHdd, pMlmScanReq->bssId,
                      pScanReq->bssId,
                      sizeof(tSirMacAddr));
        pMlmScanReq->numSsid = pScanReq->numSsid;

        i = 0;
        while (i < pMlmScanReq->numSsid)
        {
            palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmScanReq->ssId[i],
                      (tANI_U8 *) &pScanReq->ssId[i],
                      pScanReq->ssId[i].length + 1);

            i++;
        } 
       

        pMlmScanReq->scanType = pScanReq->scanType;
        pMlmScanReq->backgroundScanMode = pScanReq->backgroundScanMode;
        pMlmScanReq->minChannelTime = pScanReq->minChannelTime;
        pMlmScanReq->maxChannelTime = pScanReq->maxChannelTime;
<<<<<<< HEAD
        pMlmScanReq->minChannelTimeBtc = pScanReq->minChannelTimeBtc;
        pMlmScanReq->maxChannelTimeBtc = pScanReq->maxChannelTimeBtc;
        pMlmScanReq->dot11mode = pScanReq->dot11mode;
        pMlmScanReq->p2pSearch = pScanReq->p2pSearch;
=======
        pMlmScanReq->dot11mode = pScanReq->dot11mode;
#ifdef WLAN_FEATURE_P2P
        pMlmScanReq->p2pSearch = pScanReq->p2pSearch;
        pMlmScanReq->skipDfsChnlInP2pSearch = pScanReq->skipDfsChnlInP2pSearch;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        //Store the smeSessionID and transaction ID for later use.
        pMac->lim.gSmeSessionId = pScanReq->sessionId;
        pMac->lim.gTransactionId = pScanReq->transactionId;

        // Issue LIM_MLM_SCAN_REQ to MLM
        limPostMlmMessage(pMac, LIM_MLM_SCAN_REQ, (tANI_U32 *) pMlmScanReq);

    } // if ((pMac->lim.gLimSmeState == eLIM_SME_IDLE_STATE) || ...
    
    else
    {
        /// In all other cases return 'cached' scan results
        if ((pMac->lim.gLimRspReqd) || pMac->lim.gLimReportBackgroundScanResults)
        {
            tANI_U16    scanRspLen = sizeof(tSirSmeScanRsp);

            pMac->lim.gLimRspReqd = false;
<<<<<<< HEAD
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
            if (pScanReq->returnFreshResults & SIR_BG_SCAN_RETURN_LFR_CACHED_RESULTS)
            {
                pMac->lim.gLimSmeLfrScanResultLength = pMac->lim.gLimMlmLfrScanResultLength;
                if (pMac->lim.gLimSmeLfrScanResultLength == 0)
                {
                    limSendSmeLfrScanRsp(pMac, scanRspLen,
                                         eSIR_SME_SUCCESS,
                                         pScanReq->sessionId,
                                         pScanReq->transactionId);
                }
                else
                {
                    scanRspLen = sizeof(tSirSmeScanRsp) +
                                 pMac->lim.gLimSmeLfrScanResultLength -
                                 sizeof(tSirBssDescription);
                    limSendSmeLfrScanRsp(pMac, scanRspLen, eSIR_SME_SUCCESS,
                               pScanReq->sessionId, pScanReq->transactionId);
                }
            }
            else
            {
#endif
               if (pMac->lim.gLimSmeScanResultLength == 0)
               {
                  limSendSmeScanRsp(pMac, scanRspLen, eSIR_SME_SUCCESS,
                          pScanReq->sessionId, pScanReq->transactionId);
               }
               else
               {
                  scanRspLen = sizeof(tSirSmeScanRsp) +
                               pMac->lim.gLimSmeScanResultLength -
                               sizeof(tSirBssDescription);
                  limSendSmeScanRsp(pMac, scanRspLen, eSIR_SME_SUCCESS,
                                  pScanReq->sessionId, pScanReq->transactionId);
               }
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
            }
#endif
=======

            if (pMac->lim.gLimSmeScanResultLength == 0)
            {
                limSendSmeScanRsp(pMac, scanRspLen, eSIR_SME_SUCCESS, pScanReq->sessionId, pScanReq->transactionId);
            }
            else
            {
                scanRspLen = sizeof(tSirSmeScanRsp) +
                             pMac->lim.gLimSmeScanResultLength -
                             sizeof(tSirBssDescription);
                limSendSmeScanRsp(pMac, scanRspLen, eSIR_SME_SUCCESS, pScanReq->sessionId, pScanReq->transactionId);
            }
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

            if (pScanReq->returnFreshResults & SIR_BG_SCAN_PURGE_RESUTLS)
            {
                // Discard previously cached scan results
                limReInitScanResults(pMac);
            }
<<<<<<< HEAD
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
            if (pScanReq->returnFreshResults & SIR_BG_SCAN_PURGE_LFR_RESULTS)
            {
                // Discard previously cached scan results
                limReInitLfrScanResults(pMac);
            }
#endif
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        } // if (pMac->lim.gLimRspReqd)
    } // else ((pMac->lim.gLimSmeState == eLIM_SME_IDLE_STATE) || ...

<<<<<<< HEAD
=======
#if defined(ANI_PRODUCT_TYPE_CLIENT) || defined(ANI_AP_CLIENT_SDK)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#ifdef BACKGROUND_SCAN_ENABLED
    // start background scans if needed
    // There is a bug opened against softmac. Need to enable when the bug is fixed.
    __limBackgroundScanInitiate(pMac);
#endif
<<<<<<< HEAD
=======
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

} /*** end __limProcessSmeScanReq() ***/

#ifdef FEATURE_OEM_DATA_SUPPORT

static void __limProcessSmeOemDataReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpSirOemDataReq    pOemDataReq;
    tLimMlmOemDataReq* pMlmOemDataReq;

    pOemDataReq = (tpSirOemDataReq) pMsgBuf; 

    //post the lim mlm message now
    if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, (void**)&pMlmOemDataReq, (sizeof(tLimMlmOemDataReq))))
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("palAllocateMemory failed for mlmOemDataReq"));
=======
        limLog(pMac, LOGP, FL("palAllocateMemory failed for mlmOemDataReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    //Initialize this buffer
    palZeroMemory(pMac->hHdd, pMlmOemDataReq, (sizeof(tLimMlmOemDataReq)));

    palCopyMemory(pMac->hHdd, pMlmOemDataReq->selfMacAddr, pOemDataReq->selfMacAddr, sizeof(tSirMacAddr)); 
    palCopyMemory(pMac->hHdd, pMlmOemDataReq->oemDataReq, pOemDataReq->oemDataReq, OEM_DATA_REQ_SIZE);

    //Issue LIM_MLM_OEM_DATA_REQ to MLM
    limPostMlmMessage(pMac, LIM_MLM_OEM_DATA_REQ, (tANI_U32*)pMlmOemDataReq);

    return;

} /*** end __limProcessSmeOemDataReq() ***/

#endif //FEATURE_OEM_DATA_SUPPORT

<<<<<<< HEAD
/**
 * __limProcessClearDfsChannelList()
 *
 *FUNCTION:
 *Clear DFS channel list  when country is changed/aquired.
.*This message is sent from SME.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */
static void __limProcessClearDfsChannelList(tpAniSirGlobal pMac,
                                                           tpSirMsgQ pMsg)
{
    palZeroMemory(pMac->hHdd, &pMac->lim.dfschannelList,
                  sizeof(tSirDFSChannelList));
}
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

/**
 * __limProcessSmeJoinReq()
 *
 *FUNCTION:
 * This function is called to process SME_JOIN_REQ message
 * from HDD or upper layer application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */
static void
__limProcessSmeJoinReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
  //  tANI_U8             *pBuf;
    //tANI_U32            len;
//    tSirMacAddr         currentBssId;
    tpSirSmeJoinReq     pSmeJoinReq = NULL;
    tLimMlmJoinReq      *pMlmJoinReq;
    tSirResultCodes     retCode = eSIR_SME_SUCCESS;
    tANI_U32            val = 0;
    tANI_U16            nSize;
    tANI_U8             sessionId;
    tpPESession         psessionEntry = NULL;
    tANI_U8             smesessionId;
    tANI_U16            smetransactionId;
    tPowerdBm           localPowerConstraint = 0, regMax = 0;
<<<<<<< HEAD
    tANI_U16            ieLen;
    v_U8_t              *vendorIE;
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    //Not sending any session, since it is not created yet. The response whould have correct state.
    limDiagEventReport(pMac, WLAN_PE_DIAG_JOIN_REQ_EVENT, NULL, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("Received SME_JOIN_REQ"));)
=======
    PELOG1(limLog(pMac, LOG1, FL("Received SME_JOIN_REQ\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

#ifdef WLAN_FEATURE_VOWIFI
    /* Need to read the CFG here itself as this is used in limExtractAPCapability() below.
    * This CFG is actually read in rrmUpdateConfig() which is called later. Because this is not
    * read, RRM related path before calling rrmUpdateConfig() is not getting executed causing issues 
    * like not honoring power constraint on 1st association after driver loading. */
    if (wlan_cfgGetInt(pMac, WNI_CFG_RRM_ENABLED, &val) != eSIR_SUCCESS)
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("cfg get rrm enabled failed"));
=======
        limLog(pMac, LOGP, FL("cfg get rrm enabled failed\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    pMac->rrm.rrmPEContext.rrmEnable = (val) ? 1 : 0;
    val = 0;
#endif /* WLAN_FEATURE_VOWIFI */

   /**
     * Expect Join request in idle state.
     * Reassociate request is expected in link established state.
     */
    
    /* Global SME and LIM states are not defined yet for BT-AMP Support */
    if(pMac->lim.gLimSmeState == eLIM_SME_IDLE_STATE)
    {
        nSize = __limGetSmeJoinReqSizeForAlloc((tANI_U8*) pMsgBuf);
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSmeJoinReq, nSize))
        {
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pSmeJoinReq"));
=======
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pSmeJoinReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retCode = eSIR_SME_RESOURCES_UNAVAILABLE;
            goto end;
        }
        (void) palZeroMemory(pMac->hHdd, (void *) pSmeJoinReq, nSize);
 
        if ((limJoinReqSerDes(pMac, pSmeJoinReq, (tANI_U8 *)pMsgBuf) == eSIR_FAILURE) ||
                (!limIsSmeJoinReqValid(pMac, pSmeJoinReq)))
        {
            /// Received invalid eWNI_SME_JOIN_REQ
            // Log the event
<<<<<<< HEAD
            limLog(pMac, LOGW, FL("received SME_JOIN_REQ with invalid data"));
=======
            limLog(pMac, LOGW, FL("received SME_JOIN_REQ with invalid data\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            retCode = eSIR_SME_INVALID_PARAMETERS;
            goto end;
        }

        //pMac->lim.gpLimJoinReq = pSmeJoinReq; TO SUPPORT BT-AMP ,review os sep 23

        /* check for the existence of start BSS session  */
#ifdef FIXME_GEN6    
        if(pSmeJoinReq->bsstype == eSIR_BTAMP_AP_MODE)
        {
            if(peValidateBtJoinRequest(pMac)!= TRUE)
            {
<<<<<<< HEAD
                limLog(pMac, LOGW, FL("Start Bss session not present::SME_JOIN_REQ in unexpected state"));
=======
                limLog(pMac, LOGW, FL("Start Bss session not present::SME_JOIN_REQ in unexpected state\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                retCode = eSIR_SME_UNEXPECTED_REQ_RESULT_CODE;
                psessionEntry = NULL;
                goto end;   
            }
        }
        
#endif


        if((psessionEntry = peFindSessionByBssid(pMac,pSmeJoinReq->bssDescription.bssId,&sessionId)) != NULL)
        {
<<<<<<< HEAD
            limLog(pMac, LOGE, FL("Session Already exists for given BSSID"));
=======
            limLog(pMac, LOGE, FL("Session Already exists for given BSSID\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            
            if(psessionEntry->limSmeState == eLIM_SME_LINK_EST_STATE)
            {
                // Received eWNI_SME_JOIN_REQ for same
                // BSS as currently associated.
                // Log the event and send success
<<<<<<< HEAD
                PELOGW(limLog(pMac, LOGW, FL("Received SME_JOIN_REQ for currently joined BSS"));)
                /// Send Join success response to host
                retCode = eSIR_SME_ALREADY_JOINED_A_BSS;
                psessionEntry = NULL;
=======
                PELOGW(limLog(pMac, LOGW, FL("Received SME_JOIN_REQ for currently joined BSS\n"));)
                /// Send Join success response to host
                retCode = eSIR_SME_SUCCESS;
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                goto end;
            }
            else
            {
                retCode = eSIR_SME_REFUSED;
                psessionEntry = NULL;
                goto end;
            }    
        }    
        else       /* Session Entry does not exist for given BSSId */
        {       
            /* Try to Create a new session */
            if((psessionEntry = peCreateSession(pMac,pSmeJoinReq->bssDescription.bssId,&sessionId, pMac->lim.maxStation)) == NULL)
            {
<<<<<<< HEAD
                limLog(pMac, LOGE, FL("Session Can not be created "));
=======
                limLog(pMac, LOGE, FL("Session Can not be created \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                retCode = eSIR_SME_RESOURCES_UNAVAILABLE;
                goto end;
            }
        }   
        handleHTCapabilityandHTInfo(pMac, psessionEntry);
<<<<<<< HEAD
        psessionEntry->isAmsduSupportInAMPDU = pSmeJoinReq->isAmsduSupportInAMPDU;
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        /* Store Session related parameters */
        /* Store PE session Id in session Table */
        psessionEntry->peSessionId = sessionId;

        /* store the smejoin req handle in session table */
        psessionEntry->pLimJoinReq = pSmeJoinReq;
        
        /* Store SME session Id in sessionTable */
        psessionEntry->smeSessionId = pSmeJoinReq->sessionId;

        /* Store SME transaction Id in session Table */
        psessionEntry->transactionId = pSmeJoinReq->transactionId;

        /* Store beaconInterval */
        psessionEntry->beaconParams.beaconInterval = pSmeJoinReq->bssDescription.beaconInterval;

        /* Copying of bssId is already done, while creating session */
        //sirCopyMacAddr(psessionEntry->bssId,pSmeJoinReq->bssId);
        sirCopyMacAddr(psessionEntry->selfMacAddr,pSmeJoinReq->selfMacAddr);
        psessionEntry->bssType = pSmeJoinReq->bsstype;

        psessionEntry->statypeForBss = STA_ENTRY_PEER;
<<<<<<< HEAD
        psessionEntry->limWmeEnabled = pSmeJoinReq->isWMEenabled;
        psessionEntry->limQosEnabled = pSmeJoinReq->isQosEnabled;

        /* Store vendor specfic IE for CISCO AP */
        ieLen = (pSmeJoinReq->bssDescription.length +
                    sizeof( pSmeJoinReq->bssDescription.length ) -
                    GET_FIELD_OFFSET( tSirBssDescription, ieFields ));

        vendorIE = limGetVendorIEOuiPtr(pMac, SIR_MAC_CISCO_OUI,
                    SIR_MAC_CISCO_OUI_SIZE,
                      ((tANI_U8 *)&pSmeJoinReq->bssDescription.ieFields) , ieLen);

        if ( NULL != vendorIE )
        {
            limLog(pMac, LOGE,
                  FL("DUT is trying to connect to Cisco AP"));
            psessionEntry->isCiscoVendorAP = TRUE;
        }
        else
        {
            psessionEntry->isCiscoVendorAP = FALSE;
        }
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        /* Copy the dot 11 mode in to the session table */

        psessionEntry->dot11mode  = pSmeJoinReq->dot11mode;
        psessionEntry->nwType = pSmeJoinReq->bssDescription.nwType;
#ifdef WLAN_FEATURE_11AC
        psessionEntry->vhtCapability = IS_DOT11_MODE_VHT(psessionEntry->dot11mode);
        VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO_MED,
<<<<<<< HEAD
            "***__limProcessSmeJoinReq: vhtCapability=%d****",psessionEntry->vhtCapability);
        if (psessionEntry->vhtCapability )
        {
            psessionEntry->txBFIniFeatureEnabled = pSmeJoinReq->txBFIniFeatureEnabled;

            VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO_MED,
                "***__limProcessSmeJoinReq: txBFIniFeatureEnabled=%d****",
                psessionEntry->txBFIniFeatureEnabled);

            if( psessionEntry->txBFIniFeatureEnabled )
            {
                if (cfgSetInt(pMac, WNI_CFG_VHT_SU_BEAMFORMEE_CAP, psessionEntry->txBFIniFeatureEnabled)
                                                             != eSIR_SUCCESS)
                {
                    limLog(pMac, LOGP, FL("could not set  WNI_CFG_VHT_SU_BEAMFORMEE_CAP at CFG"));
                    retCode = eSIR_LOGP_EXCEPTION;
                    goto end;
                }
                VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO_MED,
                    "***__limProcessSmeJoinReq: txBFCsnValue=%d****", pSmeJoinReq->txBFCsnValue);

                if (cfgSetInt(pMac, WNI_CFG_VHT_CSN_BEAMFORMEE_ANT_SUPPORTED, pSmeJoinReq->txBFCsnValue)
                                                             != eSIR_SUCCESS)
                {
                    limLog(pMac, LOGP, FL("could not set  WNI_CFG_VHT_CSN_BEAMFORMEE_ANT_SUPPORTED at CFG"));
                    retCode = eSIR_LOGP_EXCEPTION;
                    goto end;
                }
            }
        }

=======
            "***__limProcessSmeJoinReq: vhtCapability=%d****\n",psessionEntry->vhtCapability);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#endif

        /*Phy mode*/
        psessionEntry->gLimPhyMode = pSmeJoinReq->bssDescription.nwType;

        /* Copy The channel Id to the session Table */
        psessionEntry->currentOperChannel = pSmeJoinReq->bssDescription.channelId;
        psessionEntry->htSupportedChannelWidthSet = (pSmeJoinReq->cbMode)?1:0; // This is already merged value of peer and self - done by csr in csrGetCBModeFromIes
        psessionEntry->htRecommendedTxWidthSet = psessionEntry->htSupportedChannelWidthSet;
        psessionEntry->htSecondaryChannelOffset = pSmeJoinReq->cbMode;

        /*Store Persona */
        psessionEntry->pePersona = pSmeJoinReq->staPersona;
        VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,
                  FL("PE PERSONA=%d cbMode %u"), psessionEntry->pePersona, pSmeJoinReq->cbMode);
        
        /* Copy the SSID from smejoinreq to session entry  */  
        psessionEntry->ssId.length = pSmeJoinReq->ssId.length;
        palCopyMemory( pMac->hHdd,psessionEntry->ssId.ssId,pSmeJoinReq->ssId.ssId,psessionEntry->ssId.length);
            
            /* Copy the SSID from smejoinreq to session entry  */  
            psessionEntry->ssId.length = pSmeJoinReq->ssId.length;
            palCopyMemory( pMac->hHdd,psessionEntry->ssId.ssId,pSmeJoinReq->ssId.ssId,psessionEntry->ssId.length);
            
            // Determin 11r or CCX connection based on input from SME
            // which inturn is dependent on the profile the user wants to connect
            // to, So input is coming from supplicant
#ifdef WLAN_FEATURE_VOWIFI_11R
            psessionEntry->is11Rconnection = pSmeJoinReq->is11Rconnection;
#endif
#ifdef FEATURE_WLAN_CCX
            psessionEntry->isCCXconnection = pSmeJoinReq->isCCXconnection;
#endif
#if defined WLAN_FEATURE_VOWIFI_11R || defined FEATURE_WLAN_CCX || defined(FEATURE_WLAN_LFR)
            psessionEntry->isFastTransitionEnabled = pSmeJoinReq->isFastTransitionEnabled;
#endif
            
#ifdef FEATURE_WLAN_LFR
            psessionEntry->isFastRoamIniFeatureEnabled = pSmeJoinReq->isFastRoamIniFeatureEnabled;
#endif
<<<<<<< HEAD
            psessionEntry->txLdpcIniFeatureEnabled = pSmeJoinReq->txLdpcIniFeatureEnabled;

=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            if(psessionEntry->bssType == eSIR_INFRASTRUCTURE_MODE)
            {
                psessionEntry->limSystemRole = eLIM_STA_ROLE;
            }
            else if(psessionEntry->bssType == eSIR_BTAMP_AP_MODE)
            {
                psessionEntry->limSystemRole = eLIM_BT_AMP_STA_ROLE;
            }
            else
            {   
                /* Throw an error and return and make sure to delete the session.*/
<<<<<<< HEAD
                limLog(pMac, LOGW, FL("received SME_JOIN_REQ with invalid bss type"));
=======
                limLog(pMac, LOGW, FL("received SME_JOIN_REQ with invalid bss type\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                retCode = eSIR_SME_INVALID_PARAMETERS;
                goto end;
            }    

        if(pSmeJoinReq->addIEScan.length)
        {
            palCopyMemory(pMac->hHdd, &psessionEntry->pLimJoinReq->addIEScan,
                          &pSmeJoinReq->addIEScan, sizeof(tSirAddie));
        }

        if(pSmeJoinReq->addIEAssoc.length)
        {
            palCopyMemory(pMac->hHdd, &psessionEntry->pLimJoinReq->addIEAssoc,
                          &pSmeJoinReq->addIEAssoc, sizeof(tSirAddie));
        }
                 
<<<<<<< HEAD
        val = sizeof(tLimMlmJoinReq) + psessionEntry->pLimJoinReq->bssDescription.length + 2;
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmJoinReq, val))
        {
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for mlmJoinReq"));
=======
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)

        val = sizeof(tLimMlmJoinReq) + sizeof(tSirMacSSidIE) +
              sizeof(tSirMacRateSetIE) + sizeof(tSirMacDsParamSetIE);
#else
        val = sizeof(tLimMlmJoinReq) + psessionEntry->pLimJoinReq->bssDescription.length + 2;
#endif
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmJoinReq, val))
        {
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for mlmJoinReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            return;
        }
        (void) palZeroMemory(pMac->hHdd, (void *) pMlmJoinReq, val);

        /* PE SessionId is stored as a part of JoinReq*/
        pMlmJoinReq->sessionId = psessionEntry->peSessionId;
        
        if (wlan_cfgGetInt(pMac, WNI_CFG_JOIN_FAILURE_TIMEOUT, (tANI_U32 *) &pMlmJoinReq->joinFailureTimeout)
            != eSIR_SUCCESS)
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("could not retrieve JoinFailureTimer value"));
=======
            limLog(pMac, LOGP, FL("could not retrieve JoinFailureTimer value\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        /* copy operational rate from psessionEntry*/
        palCopyMemory(pMac->hHdd, (void*)&psessionEntry->rateSet, (void*)&pSmeJoinReq->operationalRateSet,
                            sizeof(tSirMacRateSet));
        palCopyMemory(pMac->hHdd, (void*)&psessionEntry->extRateSet, (void*)&pSmeJoinReq->extendedRateSet,
                            sizeof(tSirMacRateSet));
        //this may not be needed anymore now, as rateSet is now included in the session entry and MLM has session context.
        palCopyMemory(pMac->hHdd, (void*)&pMlmJoinReq->operationalRateSet, (void*)&psessionEntry->rateSet,
                           sizeof(tSirMacRateSet));

        psessionEntry->encryptType = pSmeJoinReq->UCEncryptionType;

<<<<<<< HEAD
=======
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)
        palCopyMemory( pMac->hHdd, pMlmJoinReq->bssDescription.bssId,
                       pMac->lim.gpLimJoinReq->neighborBssList.bssList[0].bssId,
                       sizeof(tSirMacAddr));
        
        pMlmJoinReq->bssDescription.capabilityInfo = 1;
           
        pMlmJoinReq->bssDescription.aniIndicator =
              (tANI_U8) pMac->lim.gpLimJoinReq->neighborBssList.bssList[0].wniIndicator;
              
        pMlmJoinReq->bssDescription.nwType =
            pMac->lim.gpLimJoinReq->neighborBssList.bssList[0].nwType;

        pMlmJoinReq->bssDescription.channelId =
            pMac->lim.gpLimJoinReq->neighborBssList.bssList[0].channelId;

            limCopyNeighborInfoToCfg(pMac,
                pMac->lim.gpLimJoinReq->neighborBssList.bssList[0], psessionEntry);

        palCopyMemory( pMac->hHdd, pMac->lim.gLimCurrentBssId,
            pMac->lim.gpLimJoinReq->neighborBssList.bssList[0].bssId,
            sizeof(tSirMacAddr));

        pMac->lim.gLimCurrentChannelId =
            pMac->lim.gpLimJoinReq->neighborBssList.bssList[0].channelId;

        pMac->lim.gLimCurrentBssCaps =
            pMac->lim.gpLimJoinReq->neighborBssList.bssList[0].capabilityInfo;
        palCopyMemory( pMac->hHdd,
         (tANI_U8 *) &pMac->lim.gLimCurrentSSID,
         (tANI_U8 *) &pMac->lim.gpLimJoinReq->neighborBssList.bssList[0].ssId,
        pMac->lim.gpLimJoinReq->neighborBssList.bssList[0].ssId.length+1);
#else
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        pMlmJoinReq->bssDescription.length = psessionEntry->pLimJoinReq->bssDescription.length;

        palCopyMemory( pMac->hHdd,
           (tANI_U8 *) &pMlmJoinReq->bssDescription.bssId,
           (tANI_U8 *) &psessionEntry->pLimJoinReq->bssDescription.bssId,
           psessionEntry->pLimJoinReq->bssDescription.length + 2);

        psessionEntry->limCurrentBssCaps =
           psessionEntry->pLimJoinReq->bssDescription.capabilityInfo;

        regMax = cfgGetRegulatoryMaxTransmitPower( pMac, psessionEntry->currentOperChannel ); 
        localPowerConstraint = regMax;
        limExtractApCapability( pMac,
           (tANI_U8 *) psessionEntry->pLimJoinReq->bssDescription.ieFields,
           limGetIElenFromBssDescription(&psessionEntry->pLimJoinReq->bssDescription),
           &psessionEntry->limCurrentBssQosCaps,
           &psessionEntry->limCurrentBssPropCap,
           &pMac->lim.gLimCurrentBssUapsd //TBD-RAJESH  make gLimCurrentBssUapsd this session specific
<<<<<<< HEAD
           , &localPowerConstraint,
           psessionEntry
=======
           , &localPowerConstraint
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           ); 
#ifdef FEATURE_WLAN_CCX
            psessionEntry->maxTxPower = limGetMaxTxPower(regMax, localPowerConstraint, pMac->roam.configParam.nTxPowerCap);
#else
            psessionEntry->maxTxPower = VOS_MIN( regMax , (localPowerConstraint) );
#endif
#if defined WLAN_VOWIFI_DEBUG
        limLog( pMac, LOGE, "Regulatory max = %d, local power constraint = %d, max tx = %d", regMax, localPowerConstraint, psessionEntry->maxTxPower );
#endif

        if (pMac->lim.gLimCurrentBssUapsd)
        {
            pMac->lim.gUapsdPerAcBitmask = psessionEntry->pLimJoinReq->uapsdPerAcBitmask;
<<<<<<< HEAD
            limLog( pMac, LOG1, FL("UAPSD flag for all AC - 0x%2x"), pMac->lim.gUapsdPerAcBitmask);
=======
            limLog( pMac, LOG1, FL("UAPSD flag for all AC - 0x%2x\n"), pMac->lim.gUapsdPerAcBitmask);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

            // resetting the dynamic uapsd mask 
            pMac->lim.gUapsdPerAcDeliveryEnableMask = 0;
            pMac->lim.gUapsdPerAcTriggerEnableMask = 0;
        }
<<<<<<< HEAD
=======
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        psessionEntry->limRFBand = limGetRFBand(psessionEntry->currentOperChannel);

        // Initialize 11h Enable Flag
        if(SIR_BAND_5_GHZ == psessionEntry->limRFBand)
        {
            if (wlan_cfgGetInt(pMac, WNI_CFG_11H_ENABLED, &val) != eSIR_SUCCESS)
<<<<<<< HEAD
                limLog(pMac, LOGP, FL("Fail to get WNI_CFG_11H_ENABLED "));
=======
                limLog(pMac, LOGP, FL("Fail to get WNI_CFG_11H_ENABLED \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            psessionEntry->lim11hEnable = val;
        }
        else
            psessionEntry->lim11hEnable = 0;
        
        //To care of the scenario when STA transitions from IBSS to Infrastructure mode.
        pMac->lim.gLimIbssCoalescingHappened = false;

            psessionEntry->limPrevSmeState = psessionEntry->limSmeState;
            psessionEntry->limSmeState = eLIM_SME_WT_JOIN_STATE;
            MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));

<<<<<<< HEAD
        PELOG1(limLog(pMac, LOG1, FL("SME JoinReq: SSID %d.%c%c%c%c%c%c"),
=======
        PELOG1(limLog(pMac, LOG1, FL("SME JoinReq: SSID %d.%c%c%c%c%c%c\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               psessionEntry->ssId.length,
               psessionEntry->ssId.ssId[0],
               psessionEntry->ssId.ssId[1],
               psessionEntry->ssId.ssId[2],
               psessionEntry->ssId.ssId[3],
               psessionEntry->ssId.ssId[4],
               psessionEntry->ssId.ssId[5]);
<<<<<<< HEAD
        limLog(pMac, LOG1, FL("Channel %d, BSSID %x:%x:%x:%x:%x:%x"),
=======
        limLog(pMac, LOG1, FL("Channel %d, BSSID %x:%x:%x:%x:%x:%x\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               psessionEntry->currentOperChannel,
               psessionEntry->bssId[0],
               psessionEntry->bssId[1],
               psessionEntry->bssId[2],
               psessionEntry->bssId[3],
               psessionEntry->bssId[4],
               psessionEntry->bssId[5]);)

        /* Indicate whether spectrum management is enabled*/
        psessionEntry->spectrumMgtEnabled = 
           pSmeJoinReq->spectrumMgtIndicator;
        /* Issue LIM_MLM_JOIN_REQ to MLM */
        limPostMlmMessage(pMac, LIM_MLM_JOIN_REQ, (tANI_U32 *) pMlmJoinReq);
        return;

    }
    else
    {
        /* Received eWNI_SME_JOIN_REQ un expected state */
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("received unexpected SME_JOIN_REQ in state %X"), pMac->lim.gLimSmeState);
=======
        limLog(pMac, LOGE, FL("received unexpected SME_JOIN_REQ in state %X\n"), pMac->lim.gLimSmeState);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limPrintSmeState(pMac, LOGE, pMac->lim.gLimSmeState);
        retCode = eSIR_SME_UNEXPECTED_REQ_RESULT_CODE;
        psessionEntry = NULL;
        goto end;
        
    }

end:
    limGetSessionInfo(pMac,(tANI_U8*)pMsgBuf,&smesessionId,&smetransactionId); 
    
    if(pSmeJoinReq)
    {
        palFreeMemory( pMac->hHdd, pSmeJoinReq);
        pSmeJoinReq = NULL;
        if (NULL != psessionEntry)
        {
            psessionEntry->pLimJoinReq = NULL;
        }
    }
    
    if(retCode != eSIR_SME_SUCCESS)
    {
        if(NULL != psessionEntry)
        {
            peDeleteSession(pMac,psessionEntry);
            psessionEntry = NULL;
        }
    } 

    limSendSmeJoinReassocRsp(pMac, eWNI_SME_JOIN_RSP, retCode, eSIR_MAC_UNSPEC_FAILURE_STATUS,psessionEntry,smesessionId,smetransactionId);
} /*** end __limProcessSmeJoinReq() ***/


#ifdef FEATURE_WLAN_CCX
<<<<<<< HEAD
tANI_U8 limGetMaxTxPower(tPowerdBm regMax, tPowerdBm apTxPower, tANI_U8 iniTxPower)
=======
tANI_U8 limGetMaxTxPower(tPowerdBm regMax, tPowerdBm apTxPower, tPowerdBm iniTxPower)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
{
    tANI_U8 maxTxPower = 0;
    tANI_U8 txPower = VOS_MIN( regMax , (apTxPower) );
    txPower = VOS_MIN(txPower, iniTxPower);
    if((txPower >= MIN_TX_PWR_CAP) && (txPower <= MAX_TX_PWR_CAP))
        maxTxPower =  txPower;
    else if (txPower < MIN_TX_PWR_CAP)
        maxTxPower = MIN_TX_PWR_CAP;
    else
        maxTxPower = MAX_TX_PWR_CAP;

    return (maxTxPower);
}
#endif

/**
 * __limProcessSmeReassocReq()
 *
 *FUNCTION:
 * This function is called to process SME_REASSOC_REQ message
 * from HDD or upper layer application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limProcessSmeReassocReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tANI_U16                caps;
    tANI_U32                val;
<<<<<<< HEAD
    tpSirSmeJoinReq    pReassocReq = NULL;
=======
    tpSirSmeReassocReq pReassocReq = NULL;
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    tLimMlmReassocReq  *pMlmReassocReq;
    tSirResultCodes    retCode = eSIR_SME_SUCCESS;
    tpPESession        psessionEntry = NULL;
    tANI_U8            sessionId; 
    tANI_U8            smeSessionId; 
    tANI_U16           transactionId; 
    tPowerdBm            localPowerConstraint = 0, regMax = 0;
    tANI_U32           teleBcnEn = 0;
    tANI_U16            nSize;


<<<<<<< HEAD
    PELOG3(limLog(pMac, LOG3, FL("Received REASSOC_REQ"));)
=======
    PELOG3(limLog(pMac, LOG3, FL("Received REASSOC_REQ\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    
    nSize = __limGetSmeJoinReqSizeForAlloc((tANI_U8 *) pMsgBuf);
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pReassocReq, nSize ))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for pReassocReq"));
=======
               FL("call to palAllocateMemory failed for pReassocReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        retCode = eSIR_SME_RESOURCES_UNAVAILABLE;
        goto end;
    }
    (void) palZeroMemory(pMac->hHdd, (void *) pReassocReq, nSize);
    if ((limJoinReqSerDes(pMac, (tpSirSmeJoinReq) pReassocReq,
                          (tANI_U8 *) pMsgBuf) == eSIR_FAILURE) ||
        (!limIsSmeJoinReqValid(pMac,
                               (tpSirSmeJoinReq) pReassocReq)))
    {
        /// Received invalid eWNI_SME_REASSOC_REQ
        // Log the event
        limLog(pMac, LOGW,
<<<<<<< HEAD
               FL("received SME_REASSOC_REQ with invalid data"));
=======
               FL("received SME_REASSOC_REQ with invalid data\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        retCode = eSIR_SME_INVALID_PARAMETERS;
        goto end;
    }

   if((psessionEntry = peFindSessionByBssid(pMac,pReassocReq->bssDescription.bssId,&sessionId))==NULL)
    {
        limPrintMacAddr(pMac, pReassocReq->bssDescription.bssId, LOGE);
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("Session does not exist for given bssId"));
=======
        limLog(pMac, LOGP, FL("Session does not exist for given bssId\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        retCode = eSIR_SME_INVALID_PARAMETERS;
        goto end;
    }

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_REASSOC_REQ_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    //pMac->lim.gpLimReassocReq = pReassocReq;//TO SUPPORT BT-AMP

    /* Store the reassoc handle in the session Table.. 23rd sep review */
    psessionEntry->pLimReAssocReq = pReassocReq;

    /**
     * Reassociate request is expected
     * in link established state only.
     */

    if (psessionEntry->limSmeState != eLIM_SME_LINK_EST_STATE)
    {
#if defined(WLAN_FEATURE_VOWIFI_11R) || defined(FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
        if (psessionEntry->limSmeState == eLIM_SME_WT_REASSOC_STATE)
        {
            // May be from 11r FT pre-auth. So lets check it before we bail out
<<<<<<< HEAD
            limLog(pMac, LOG1, FL("Session in reassoc state is %d"),
=======
            limLog(pMac, LOGE, FL("Session in reassoc state is %d\n"), 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                psessionEntry->peSessionId);

            // Make sure its our preauth bssid
            if (!palEqualMemory( pMac->hHdd, pReassocReq->bssDescription.bssId, 
                pMac->ft.ftPEContext.pFTPreAuthReq->preAuthbssId, 6))
            {
                limPrintMacAddr(pMac, pReassocReq->bssDescription.bssId, LOGE);
                limPrintMacAddr(pMac, pMac->ft.ftPEContext.pFTPreAuthReq->preAuthbssId, LOGE);
<<<<<<< HEAD
                limLog(pMac, LOGP, FL("Unknown bssId in reassoc state"));
=======
                limLog(pMac, LOGP, FL("Unknown bssId in reassoc state\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                retCode = eSIR_SME_INVALID_PARAMETERS;
                goto end;
            }

            limProcessMlmFTReassocReq(pMac, pMsgBuf, psessionEntry);
            return;
        }
#endif
        /// Should not have received eWNI_SME_REASSOC_REQ
        // Log the event
        limLog(pMac, LOGE,
<<<<<<< HEAD
               FL("received unexpected SME_REASSOC_REQ in state %X"),
=======
               FL("received unexpected SME_REASSOC_REQ in state %X\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               psessionEntry->limSmeState);
        limPrintSmeState(pMac, LOGE, psessionEntry->limSmeState);

        retCode = eSIR_SME_UNEXPECTED_REQ_RESULT_CODE;
        goto end;
    }

    palCopyMemory( pMac->hHdd,
             psessionEntry->limReAssocbssId,
             psessionEntry->pLimReAssocReq->bssDescription.bssId,
             sizeof(tSirMacAddr));

    psessionEntry->limReassocChannelId =
         psessionEntry->pLimReAssocReq->bssDescription.channelId;

    psessionEntry->reAssocHtSupportedChannelWidthSet =
         (psessionEntry->pLimReAssocReq->cbMode)?1:0;
    psessionEntry->reAssocHtRecommendedTxWidthSet =
         psessionEntry->reAssocHtSupportedChannelWidthSet;
    psessionEntry->reAssocHtSecondaryChannelOffset =
         psessionEntry->pLimReAssocReq->cbMode;

    psessionEntry->limReassocBssCaps =
                psessionEntry->pLimReAssocReq->bssDescription.capabilityInfo;
    regMax = cfgGetRegulatoryMaxTransmitPower( pMac, psessionEntry->currentOperChannel ); 
    localPowerConstraint = regMax;
    limExtractApCapability( pMac,
              (tANI_U8 *) psessionEntry->pLimReAssocReq->bssDescription.ieFields,
              limGetIElenFromBssDescription(
                     &psessionEntry->pLimReAssocReq->bssDescription),
              &psessionEntry->limReassocBssQosCaps,
              &psessionEntry->limReassocBssPropCap,
              &pMac->lim.gLimCurrentBssUapsd //TBD-RAJESH make gLimReassocBssUapsd session specific
<<<<<<< HEAD
              , &localPowerConstraint,
              psessionEntry
=======
              , &localPowerConstraint
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
              );

    psessionEntry->maxTxPower = VOS_MIN( regMax , (localPowerConstraint) );
#if defined WLAN_VOWIFI_DEBUG
            limLog( pMac, LOGE, "Regulatory max = %d, local power constraint = %d, max tx = %d", regMax, localPowerConstraint, psessionEntry->maxTxPower );
#endif
    {
    #if 0
    if (wlan_cfgGetStr(pMac, WNI_CFG_SSID, pMac->lim.gLimReassocSSID.ssId,
                  &cfgLen) != eSIR_SUCCESS)
    {
        /// Could not get SSID from CFG. Log error.
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("could not retrive SSID"));
=======
        limLog(pMac, LOGP, FL("could not retrive SSID\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }
    #endif//TO SUPPORT BT-AMP
    
    /* Copy the SSID from sessio entry to local variable */
    #if 0
    palCopyMemory( pMac->hHdd, pMac->lim.gLimReassocSSID.ssId,
                   psessionEntry->ssId.ssId,
                   psessionEntry->ssId.length);
    #endif
    psessionEntry->limReassocSSID.length = pReassocReq->ssId.length;
    palCopyMemory( pMac->hHdd, psessionEntry->limReassocSSID.ssId,
                    pReassocReq->ssId.ssId, psessionEntry->limReassocSSID.length);

    }

    if (pMac->lim.gLimCurrentBssUapsd)
    {
        pMac->lim.gUapsdPerAcBitmask = psessionEntry->pLimReAssocReq->uapsdPerAcBitmask;
<<<<<<< HEAD
        limLog( pMac, LOG1, FL("UAPSD flag for all AC - 0x%2x"), pMac->lim.gUapsdPerAcBitmask);
=======
        limLog( pMac, LOG1, FL("UAPSD flag for all AC - 0x%2x\n"), pMac->lim.gUapsdPerAcBitmask);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmReassocReq, sizeof(tLimMlmReassocReq)))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for mlmReassocReq"));
=======
               FL("call to palAllocateMemory failed for mlmReassocReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        retCode = eSIR_SME_RESOURCES_UNAVAILABLE;
        goto end;
    }

    palCopyMemory( pMac->hHdd, pMlmReassocReq->peerMacAddr,
                  psessionEntry->limReAssocbssId,
                  sizeof(tSirMacAddr));

    if (wlan_cfgGetInt(pMac, WNI_CFG_REASSOCIATION_FAILURE_TIMEOUT,
                  (tANI_U32 *) &pMlmReassocReq->reassocFailureTimeout)
                           != eSIR_SUCCESS)
    {
        /**
         * Could not get ReassocFailureTimeout value
         * from CFG. Log error.
         */
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("could not retrieve ReassocFailureTimeout value"));
=======
               FL("could not retrieve ReassocFailureTimeout value\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

    if (cfgGetCapabilityInfo(pMac, &caps,psessionEntry) != eSIR_SUCCESS)
    {
        /**
         * Could not get Capabilities value
         * from CFG. Log error.
         */
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("could not retrieve Capabilities value"));
=======
               FL("could not retrieve Capabilities value\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }
    pMlmReassocReq->capabilityInfo = caps;
    
    /* Update PE sessionId*/
    pMlmReassocReq->sessionId = sessionId;

   /* If telescopic beaconing is enabled, set listen interval to
     WNI_CFG_TELE_BCN_MAX_LI */
    if(wlan_cfgGetInt(pMac, WNI_CFG_TELE_BCN_WAKEUP_EN, &teleBcnEn) != 
       eSIR_SUCCESS) 
<<<<<<< HEAD
       limLog(pMac, LOGP, FL("Couldn't get WNI_CFG_TELE_BCN_WAKEUP_EN"));
=======
       limLog(pMac, LOGP, FL("Couldn't get WNI_CFG_TELE_BCN_WAKEUP_EN\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
   
    val = WNI_CFG_LISTEN_INTERVAL_STADEF;
   
    if(teleBcnEn)
    {
       if(wlan_cfgGetInt(pMac, WNI_CFG_TELE_BCN_MAX_LI, &val) != 
          eSIR_SUCCESS)
       {
            /**
            * Could not get ListenInterval value
            * from CFG. Log error.
          */
<<<<<<< HEAD
          limLog(pMac, LOGP, FL("could not retrieve ListenInterval"));
=======
          limLog(pMac, LOGP, FL("could not retrieve ListenInterval\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
       }
    }
    else
    {
       if (wlan_cfgGetInt(pMac, WNI_CFG_LISTEN_INTERVAL, &val) != eSIR_SUCCESS)
       {
         /**
            * Could not get ListenInterval value
            * from CFG. Log error.
          */
<<<<<<< HEAD
          limLog(pMac, LOGP, FL("could not retrieve ListenInterval"));
=======
          limLog(pMac, LOGP, FL("could not retrieve ListenInterval\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
       }
    }

    /* Delete all BA sessions before Re-Assoc.
     *  BA frames are class 3 frames and the session 
     *  is lost upon disassociation and reassociation.
     */

<<<<<<< HEAD
    limDeleteBASessions(pMac, psessionEntry, BA_BOTH_DIRECTIONS);
=======
    limDelAllBASessions(pMac);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    pMlmReassocReq->listenInterval = (tANI_U16) val;

    /* Indicate whether spectrum management is enabled*/
    psessionEntry->spectrumMgtEnabled = pReassocReq->spectrumMgtIndicator;

    psessionEntry->limPrevSmeState = psessionEntry->limSmeState;
    psessionEntry->limSmeState    = eLIM_SME_WT_REASSOC_STATE;

    MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));

    limPostMlmMessage(pMac,
                      LIM_MLM_REASSOC_REQ,
                      (tANI_U32 *) pMlmReassocReq);
    return;

end:
    if (pReassocReq)
        palFreeMemory( pMac->hHdd, pReassocReq);

    if (psessionEntry)
    {
       // error occurred after we determined the session so extract
       // session and transaction info from there
       smeSessionId = psessionEntry->smeSessionId;
       transactionId = psessionEntry->transactionId;
    }
    else
    {
       // error occurred before or during the time we determined the session
       // so extract the session and transaction info from the message
       limGetSessionInfo(pMac,(tANI_U8*)pMsgBuf, &smeSessionId, &transactionId);
    }

    /// Send Reassoc failure response to host
    /// (note psessionEntry may be NULL, but that's OK)
    limSendSmeJoinReassocRsp(pMac, eWNI_SME_REASSOC_RSP,
                             retCode, eSIR_MAC_UNSPEC_FAILURE_STATUS,
                             psessionEntry, smeSessionId, transactionId);

} /*** end __limProcessSmeReassocReq() ***/


tANI_BOOLEAN sendDisassocFrame = 1;
/**
 * __limProcessSmeDisassocReq()
 *
 *FUNCTION:
 * This function is called to process SME_DISASSOC_REQ message
 * from HDD or upper layer application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limProcessSmeDisassocReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tANI_U16                disassocTrigger, reasonCode;
    tLimMlmDisassocReq      *pMlmDisassocReq;
    tSirResultCodes         retCode = eSIR_SME_SUCCESS;
    tSirRetStatus           status;
    tSirSmeDisassocReq      smeDisassocReq;
    tpPESession             psessionEntry = NULL; 
    tANI_U8                 sessionId;
    tANI_U8                 smesessionId;
    tANI_U16                smetransactionId;

<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1,FL("received DISASSOC_REQ message"));)
    
    if (pMsgBuf == NULL)
    {
        limLog(pMac, LOGE, FL("Buffer is Pointing to NULL"));
=======
    PELOG1(limLog(pMac, LOG1,FL("received DISASSOC_REQ message\n"));)
    
    if (pMsgBuf == NULL)
    {
        limLog(pMac, LOGE, FL("Buffer is Pointing to NULL\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    limGetSessionInfo(pMac, (tANI_U8 *)pMsgBuf,&smesessionId, &smetransactionId);

    status = limDisassocReqSerDes(pMac, &smeDisassocReq, (tANI_U8 *) pMsgBuf);
    
    if ( (eSIR_FAILURE == status) ||
         (!limIsSmeDisassocReqValid(pMac, &smeDisassocReq, psessionEntry)) )
    {
        PELOGE(limLog(pMac, LOGE,
<<<<<<< HEAD
               FL("received invalid SME_DISASSOC_REQ message"));)
=======
               FL("received invalid SME_DISASSOC_REQ message\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        if (pMac->lim.gLimRspReqd)
        {
            pMac->lim.gLimRspReqd = false;

            retCode         = eSIR_SME_INVALID_PARAMETERS;
            disassocTrigger = eLIM_HOST_DISASSOC;
            goto sendDisassoc;
        }

        return;
    }


<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1,   FL("received DISASSOC_REQ message. Reason: %d global SmeState: %d"),
=======
    PELOGE(limLog(pMac, LOGE,   FL("received DISASSOC_REQ message. Reason: %d global SmeState: %d\n"), 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                                                        smeDisassocReq.reasonCode, pMac->lim.gLimSmeState);)


    if((psessionEntry = peFindSessionByBssid(pMac,smeDisassocReq.bssId,&sessionId))== NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGE,FL("session does not exist for given bssId"));
=======
        limLog(pMac, LOGE,FL("session does not exist for given bssId\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        retCode = eSIR_SME_INVALID_PARAMETERS;
        disassocTrigger = eLIM_HOST_DISASSOC;
        goto sendDisassoc;
        
    }

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
   limDiagEventReport(pMac, WLAN_PE_DIAG_DISASSOC_REQ_EVENT, psessionEntry, 0, smeDisassocReq.reasonCode);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    
    /* Update SME session Id and SME transaction ID*/

    psessionEntry->smeSessionId = smesessionId;
    psessionEntry->transactionId = smetransactionId;

    switch (psessionEntry->limSystemRole)
    {
        case eLIM_STA_ROLE:
        case eLIM_BT_AMP_STA_ROLE:
            switch (psessionEntry->limSmeState)
            {
                case eLIM_SME_ASSOCIATED_STATE:
                case eLIM_SME_LINK_EST_STATE:
                    psessionEntry->limPrevSmeState = psessionEntry->limSmeState;
                    psessionEntry->limSmeState= eLIM_SME_WT_DISASSOC_STATE;
<<<<<<< HEAD
#ifdef FEATURE_WLAN_TDLS
                    /* Delete all TDLS peers connected before leaving BSS*/
                    limDeleteTDLSPeers(pMac, psessionEntry);
#endif
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                    MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
                    break;

                case eLIM_SME_WT_DEAUTH_STATE:
                    /* PE shall still process the DISASSOC_REQ and proceed with 
                     * link tear down even if it had already sent a DEAUTH_IND to
                     * to SME. pMac->lim.gLimPrevSmeState shall remain the same as
                     * its been set when PE entered WT_DEAUTH_STATE. 
                     */                  
                    psessionEntry->limSmeState= eLIM_SME_WT_DISASSOC_STATE;
                    MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
<<<<<<< HEAD
                    limLog(pMac, LOG1, FL("Rcvd SME_DISASSOC_REQ while in SME_WT_DEAUTH_STATE. "));
=======
                    limLog(pMac, LOG1, FL("Rcvd SME_DISASSOC_REQ while in SME_WT_DEAUTH_STATE. \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                    break;

                case eLIM_SME_WT_DISASSOC_STATE:
                    /* PE Recieved a Disassoc frame. Normally it gets DISASSOC_CNF but it
                     * received DISASSOC_REQ. Which means host is also trying to disconnect.
                     * PE can continue processing DISASSOC_REQ and send the response instead
                     * of failing the request. SME will anyway ignore DEAUTH_IND that was sent
                     * for disassoc frame.
                     *
                     * It will send a disassoc, which is ok. However, we can use the global flag
                     * sendDisassoc to not send disassoc frame.
                     */
<<<<<<< HEAD
                    limLog(pMac, LOG1, FL("Rcvd SME_DISASSOC_REQ while in SME_WT_DISASSOC_STATE. "));
=======
                    limLog(pMac, LOG1, FL("Rcvd SME_DISASSOC_REQ while in SME_WT_DISASSOC_STATE. \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                    break;

                case eLIM_SME_JOIN_FAILURE_STATE: {
                    /** Return Success as we are already in Disconnected State*/
                     if (pMac->lim.gLimRspReqd) {
                        retCode = eSIR_SME_SUCCESS;  
                        disassocTrigger = eLIM_HOST_DISASSOC;
                        goto sendDisassoc;
                    }
                }break;
                default:
                    /**
                     * STA is not currently associated.
                     * Log error and send response to host
                     */
                    limLog(pMac, LOGE,
<<<<<<< HEAD
                       FL("received unexpected SME_DISASSOC_REQ in state %X"),
=======
                       FL("received unexpected SME_DISASSOC_REQ in state %X\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                       psessionEntry->limSmeState);
                    limPrintSmeState(pMac, LOGE, psessionEntry->limSmeState);

                    if (pMac->lim.gLimRspReqd)
                    {
                        if (psessionEntry->limSmeState !=
                                                eLIM_SME_WT_ASSOC_STATE)
                                    pMac->lim.gLimRspReqd = false;

                        retCode = eSIR_SME_UNEXPECTED_REQ_RESULT_CODE;
                        disassocTrigger = eLIM_HOST_DISASSOC;
                        goto sendDisassoc;
                    }

                    return;
            }

            break;

        case eLIM_AP_ROLE:
    case eLIM_BT_AMP_AP_ROLE:
            // Fall through
            break;

        case eLIM_STA_IN_IBSS_ROLE:
        default: // eLIM_UNKNOWN_ROLE
            limLog(pMac, LOGE,
<<<<<<< HEAD
               FL("received unexpected SME_DISASSOC_REQ for role %d"),
=======
               FL("received unexpected SME_DISASSOC_REQ for role %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               psessionEntry->limSystemRole);

            retCode = eSIR_SME_UNEXPECTED_REQ_RESULT_CODE;
            disassocTrigger = eLIM_HOST_DISASSOC;
            goto sendDisassoc;
    } // end switch (pMac->lim.gLimSystemRole)

    if (smeDisassocReq.reasonCode == eLIM_LINK_MONITORING_DISASSOC)
    {
        /// Disassociation is triggered by Link Monitoring
        disassocTrigger = eLIM_LINK_MONITORING_DISASSOC;
        reasonCode      = eSIR_MAC_DISASSOC_DUE_TO_INACTIVITY_REASON;
    }
    else
    {
        disassocTrigger = eLIM_HOST_DISASSOC;
        reasonCode      = smeDisassocReq.reasonCode;
    }

    if (smeDisassocReq.doNotSendOverTheAir)
    {
        sendDisassocFrame = 0;     
    }
    // Trigger Disassociation frame to peer MAC entity
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmDisassocReq, sizeof(tLimMlmDisassocReq)))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for mlmDisassocReq"));
=======
               FL("call to palAllocateMemory failed for mlmDisassocReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        return;
    }

    palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmDisassocReq->peerMacAddr,
                  (tANI_U8 *) &smeDisassocReq.peerMacAddr,
                  sizeof(tSirMacAddr));

    pMlmDisassocReq->reasonCode      = reasonCode;
    pMlmDisassocReq->disassocTrigger = disassocTrigger;
    
    /* Update PE session ID*/
    pMlmDisassocReq->sessionId = sessionId;
<<<<<<< HEAD
=======
#ifdef ANI_PRODUCT_TYPE_AP
    pMlmDisassocReq->aid             = smeDisassocReq.aid;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    limPostMlmMessage(pMac,
                      LIM_MLM_DISASSOC_REQ,
                      (tANI_U32 *) pMlmDisassocReq);
    return;

sendDisassoc:
    if (psessionEntry) 
        limSendSmeDisassocNtf(pMac, smeDisassocReq.peerMacAddr,
                          retCode,
                          disassocTrigger,
<<<<<<< HEAD
                          1,smesessionId,smetransactionId,psessionEntry);
=======
#ifdef ANI_PRODUCT_TYPE_AP
                          smeDisassocReq.aid);
#else
                          1,smesessionId,smetransactionId,psessionEntry);
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    else 
        limSendSmeDisassocNtf(pMac, smeDisassocReq.peerMacAddr, 
                retCode, 
                disassocTrigger,
<<<<<<< HEAD
                1, smesessionId, smetransactionId, NULL);
=======
#ifdef ANI_PRODUCT_TYPE_AP
                smeDisassocReq.aid);
#else
                1, 0, 0, NULL);
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


} /*** end __limProcessSmeDisassocReq() ***/


/** -----------------------------------------------------------------
  \brief __limProcessSmeDisassocCnf() - Process SME_DISASSOC_CNF
   
  This function is called to process SME_DISASSOC_CNF message
  from HDD or upper layer application. 
    
  \param pMac - global mac structure
  \param pStaDs - station dph hash node 
  \return none 
  \sa
  ----------------------------------------------------------------- */
static void
__limProcessSmeDisassocCnf(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirSmeDisassocCnf  smeDisassocCnf;
    tANI_U16  aid;
    tpDphHashNode  pStaDs;
    tSirRetStatus  status = eSIR_SUCCESS;
    tpPESession         psessionEntry;
    tANI_U8             sessionId;


<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("received DISASSOC_CNF message"));)
=======
    PELOG1(limLog(pMac, LOG1, FL("received DISASSOC_CNF message\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    status = limDisassocCnfSerDes(pMac, &smeDisassocCnf,(tANI_U8 *) pMsgBuf);

    if (status == eSIR_FAILURE)
    {
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("invalid SME_DISASSOC_CNF message"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("invalid SME_DISASSOC_CNF message\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    if((psessionEntry = peFindSessionByBssid(pMac, smeDisassocCnf.bssId, &sessionId))== NULL)
    {
<<<<<<< HEAD
         limLog(pMac, LOGE,FL("session does not exist for given bssId"));
=======
         limLog(pMac, LOGE,FL("session does not exist for given bssId\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
         return;
    }

    if (!limIsSmeDisassocCnfValid(pMac, &smeDisassocCnf, psessionEntry))
    {
<<<<<<< HEAD
        limLog(pMac, LOGW, FL("received invalid SME_DISASSOC_CNF message"));
=======
        limLog(pMac, LOGW, FL("received invalid SME_DISASSOC_CNF message\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    if (smeDisassocCnf.messageType == eWNI_SME_DISASSOC_CNF)
        limDiagEventReport(pMac, WLAN_PE_DIAG_DISASSOC_CNF_EVENT, psessionEntry, (tANI_U16)smeDisassocCnf.statusCode, 0);
    else if (smeDisassocCnf.messageType ==  eWNI_SME_DEAUTH_CNF)
        limDiagEventReport(pMac, WLAN_PE_DIAG_DEAUTH_CNF_EVENT, psessionEntry, (tANI_U16)smeDisassocCnf.statusCode, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    switch (psessionEntry->limSystemRole)
    {
        case eLIM_STA_ROLE:
        case eLIM_BT_AMP_STA_ROLE:  //To test reconn
            if ((psessionEntry->limSmeState != eLIM_SME_IDLE_STATE) &&
                (psessionEntry->limSmeState != eLIM_SME_WT_DISASSOC_STATE) &&
                (psessionEntry->limSmeState != eLIM_SME_WT_DEAUTH_STATE))
            {
                limLog(pMac, LOGE,
<<<<<<< HEAD
                   FL("received unexp SME_DISASSOC_CNF in state %X"),
=======
                   FL("received unexp SME_DISASSOC_CNF in state %X\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                  psessionEntry->limSmeState);
                limPrintSmeState(pMac, LOGE, psessionEntry->limSmeState);
                return;
            }
            break;

        case eLIM_AP_ROLE:
            // Fall through
<<<<<<< HEAD
            break;
=======
#ifdef WLAN_SOFTAP_FEATURE
            break;
#else
            return;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        case eLIM_STA_IN_IBSS_ROLE:
        default: // eLIM_UNKNOWN_ROLE
            limLog(pMac, LOGE,
<<<<<<< HEAD
               FL("received unexpected SME_DISASSOC_CNF role %d"),
=======
               FL("received unexpected SME_DISASSOC_CNF role %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               psessionEntry->limSystemRole);

            return;
    } 


    if ( (psessionEntry->limSmeState == eLIM_SME_WT_DISASSOC_STATE) || 
         (psessionEntry->limSmeState == eLIM_SME_WT_DEAUTH_STATE)
<<<<<<< HEAD
          || (psessionEntry->limSystemRole == eLIM_AP_ROLE )   
=======
#ifdef WLAN_SOFTAP_FEATURE
          || (psessionEntry->limSystemRole == eLIM_AP_ROLE )   
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
     )
    {       
        pStaDs = dphLookupHashEntry(pMac, smeDisassocCnf.peerMacAddr, &aid, &psessionEntry->dph.dphHashTable);
        if (pStaDs == NULL)
        {
            PELOGW(limLog(pMac, LOGW, FL("received DISASSOC_CNF for a STA that does not have context, addr= "));
            limPrintMacAddr(pMac, smeDisassocCnf.peerMacAddr, LOGW);)
            return;
        }
        /* Delete FT session if there exists one */
        limFTCleanup(pMac);
        limCleanupRxPath(pMac, pStaDs, psessionEntry);
<<<<<<< HEAD

        limCleanUpDisassocDeauthReq(pMac, (char*)&smeDisassocCnf.peerMacAddr, 0);
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

    return;
} 


/**
 * __limProcessSmeDeauthReq()
 *
 *FUNCTION:
 * This function is called to process SME_DEAUTH_REQ message
 * from HDD or upper layer application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limProcessSmeDeauthReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tANI_U16                deauthTrigger, reasonCode;
    tLimMlmDeauthReq        *pMlmDeauthReq;
    tSirSmeDeauthReq        smeDeauthReq;
    tSirResultCodes         retCode = eSIR_SME_SUCCESS;
    tSirRetStatus           status = eSIR_SUCCESS;
    tpPESession             psessionEntry; 
    tANI_U8                 sessionId; //PE sessionId
    tANI_U8                 smesessionId;  
    tANI_U16                smetransactionId;
    
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1,FL("received DEAUTH_REQ message"));)
=======
    PELOG1(limLog(pMac, LOG1,FL("received DEAUTH_REQ message\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    status = limDeauthReqSerDes(pMac, &smeDeauthReq,(tANI_U8 *) pMsgBuf);

    limGetSessionInfo(pMac,(tANI_U8 *)pMsgBuf,&smesessionId,&smetransactionId);

    //We need to get a session first but we don't even know if the message is correct.
    if((psessionEntry = peFindSessionByBssid(pMac, smeDeauthReq.bssId, &sessionId)) == NULL)
    {
<<<<<<< HEAD
       limLog(pMac, LOGE,FL("session does not exist for given bssId"));
=======
       limLog(pMac, LOGE,FL("session does not exist for given bssId\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
       retCode = eSIR_SME_INVALID_PARAMETERS;
       deauthTrigger = eLIM_HOST_DEAUTH;
       goto sendDeauth;
       
    }

    if ((status == eSIR_FAILURE) || (!limIsSmeDeauthReqValid(pMac, &smeDeauthReq, psessionEntry)))
    {
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGW,FL("received invalid SME_DEAUTH_REQ message"));)
=======
        PELOGE(limLog(pMac, LOGW,FL("received invalid SME_DEAUTH_REQ message\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        if (pMac->lim.gLimRspReqd)
        {
            pMac->lim.gLimRspReqd = false;

            retCode       = eSIR_SME_INVALID_PARAMETERS;
            deauthTrigger = eLIM_HOST_DEAUTH;
            goto sendDeauth;
        }

        return;
    }

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_DEAUTH_REQ_EVENT, psessionEntry, 0, smeDeauthReq.reasonCode);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    /* Update SME session ID and Transaction ID */
    psessionEntry->smeSessionId = smesessionId;
    psessionEntry->transactionId = smetransactionId;
        

    switch (psessionEntry->limSystemRole)
    {
        case eLIM_STA_ROLE:
        case eLIM_BT_AMP_STA_ROLE:
            
            switch (psessionEntry->limSmeState)
            {
                case eLIM_SME_ASSOCIATED_STATE:
                case eLIM_SME_LINK_EST_STATE:
                case eLIM_SME_WT_ASSOC_STATE:
                case eLIM_SME_JOIN_FAILURE_STATE:
                case eLIM_SME_IDLE_STATE:
                    psessionEntry->limPrevSmeState = psessionEntry->limSmeState;
                    psessionEntry->limSmeState = eLIM_SME_WT_DEAUTH_STATE;
<<<<<<< HEAD
                    MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
=======
              MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, pMac->lim.gLimSmeState));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

                    // Send Deauthentication request to MLM below

                    break;
<<<<<<< HEAD
                case eLIM_SME_WT_DEAUTH_STATE:
                    /*
                     * PE Recieved a Deauth frame. Normally it gets
                     * DEAUTH_CNF but it received DEAUTH_REQ. Which
                     * means host is also trying to disconnect.
                     * PE can continue processing DEAUTH_REQ and send
                     * the response instead of failing the request.
                     * SME will anyway ignore DEAUTH_IND that was sent
                     * for deauth frame.
                     */
                    limLog(pMac, LOG1, FL("Rcvd SME_DEAUTH_REQ while in "
                       "SME_WT_DEAUTH_STATE. "));
                    break;
=======

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                default:
                    /**
                     * STA is not in a state to deauthenticate with
                     * peer. Log error and send response to host.
                     */
                    limLog(pMac, LOGE,
<<<<<<< HEAD
                    FL("received unexp SME_DEAUTH_REQ in state %X"),psessionEntry->limSmeState);
=======
                    FL("received unexp SME_DEAUTH_REQ in state %X\n"),psessionEntry->limSmeState);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                    limPrintSmeState(pMac, LOGE, psessionEntry->limSmeState);

                    if (pMac->lim.gLimRspReqd)
                    {
                        pMac->lim.gLimRspReqd = false;

                        retCode       = eSIR_SME_STA_NOT_AUTHENTICATED;
                        deauthTrigger = eLIM_HOST_DEAUTH;
<<<<<<< HEAD
                        /**
                         *here we received deauth request from AP so sme state is
                          eLIM_SME_WT_DEAUTH_STATE.if we have ISSUED delSta then
                          mlm state should be eLIM_MLM_WT_DEL_STA_RSP_STATE and if
                          we got delBSS rsp then mlm state should be eLIM_MLM_IDLE_STATE
                          so the below condition captures the state where delSta
                          not done and firmware still in connected state.
                        */
                        if (psessionEntry->limSmeState == eLIM_SME_WT_DEAUTH_STATE &&
                            psessionEntry->limMlmState != eLIM_MLM_IDLE_STATE &&
                            psessionEntry->limMlmState != eLIM_MLM_WT_DEL_STA_RSP_STATE)
                        {
                            retCode = eSIR_SME_DEAUTH_STATUS;
                        }
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                        goto sendDeauth;
                    }

                    return;
            }

            break;

        case eLIM_STA_IN_IBSS_ROLE:

            return;

        case eLIM_AP_ROLE:
            // Fall through

            break;

        default:
            limLog(pMac, LOGE,
<<<<<<< HEAD
               FL("received unexpected SME_DEAUTH_REQ for role %X"),psessionEntry->limSystemRole);
=======
               FL("received unexpected SME_DEAUTH_REQ for role %X\n"),psessionEntry->limSystemRole);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

            return;
    } // end switch (pMac->lim.gLimSystemRole)

    if (smeDeauthReq.reasonCode == eLIM_LINK_MONITORING_DEAUTH)
    {
        /// Deauthentication is triggered by Link Monitoring
<<<<<<< HEAD
        PELOG1(limLog(pMac, LOG1, FL("**** Lost link with AP ****"));)
=======
        PELOG1(limLog(pMac, LOG1, FL("**** Lost link with AP ****\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        deauthTrigger = eLIM_LINK_MONITORING_DEAUTH;
        reasonCode    = eSIR_MAC_UNSPEC_FAILURE_REASON;
    }
    else
    {
        deauthTrigger = eLIM_HOST_DEAUTH;
        reasonCode    = smeDeauthReq.reasonCode;
    }

    // Trigger Deauthentication frame to peer MAC entity
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmDeauthReq, sizeof(tLimMlmDeauthReq)))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for mlmDeauthReq"));
=======
               FL("call to palAllocateMemory failed for mlmDeauthReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        return;
    }

    palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmDeauthReq->peerMacAddr,
                  (tANI_U8 *) &smeDeauthReq.peerMacAddr,
                  sizeof(tSirMacAddr));

    pMlmDeauthReq->reasonCode = reasonCode;
    pMlmDeauthReq->deauthTrigger = deauthTrigger;
<<<<<<< HEAD
=======
#ifdef ANI_PRODUCT_TYPE_AP
    pMlmDeauthReq->aid = smeDeauthReq.aid;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    /* Update PE session Id*/
    pMlmDeauthReq->sessionId = sessionId;

    limPostMlmMessage(pMac,
                      LIM_MLM_DEAUTH_REQ,
                      (tANI_U32 *) pMlmDeauthReq);
    return;

sendDeauth:
    limSendSmeDeauthNtf(pMac, smeDeauthReq.peerMacAddr,
                        retCode,
                        deauthTrigger,
<<<<<<< HEAD
                        1, 
=======
#ifdef ANI_PRODUCT_TYPE_AP
                        smeDeauthReq.aid,
#else
                        1, 
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                        smesessionId, smetransactionId);
} /*** end __limProcessSmeDeauthReq() ***/



/**
 * __limProcessSmeSetContextReq()
 *
 *FUNCTION:
 * This function is called to process SME_SETCONTEXT_REQ message
 * from HDD or upper layer application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limProcessSmeSetContextReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpSirSmeSetContextReq  pSetContextReq;
    tLimMlmSetKeysReq      *pMlmSetKeysReq;
    tpPESession             psessionEntry;
    tANI_U8                 sessionId;  //PE sessionID
    tANI_U8                 smesessionId;
    tANI_U16                smetransactionId;
    

    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
           FL("received SETCONTEXT_REQ message")););
=======
           FL("received SETCONTEXT_REQ message\n")););
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    
    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
=======
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    limGetSessionInfo(pMac,(tANI_U8 *)pMsgBuf,&smesessionId,&smetransactionId);
    
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSetContextReq,
                                                (sizeof(tSirKeys) * SIR_MAC_MAX_NUM_OF_DEFAULT_KEYS)))
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pSetContextReq"));
=======
        limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pSetContextReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    if ((limSetContextReqSerDes(pMac, pSetContextReq, (tANI_U8 *) pMsgBuf) == eSIR_FAILURE) ||
        (!limIsSmeSetContextReqValid(pMac, pSetContextReq)))
    {
<<<<<<< HEAD
        limLog(pMac, LOGW, FL("received invalid SME_SETCONTEXT_REQ message"));
=======
        limLog(pMac, LOGW, FL("received invalid SME_SETCONTEXT_REQ message\n")); 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }

    if(pSetContextReq->keyMaterial.numKeys > SIR_MAC_MAX_NUM_OF_DEFAULT_KEYS)
    {
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("numKeys:%d is more than SIR_MAC_MAX_NUM_OF_DEFAULT_KEYS"), pSetContextReq->keyMaterial.numKeys);)
        limSendSmeSetContextRsp(pMac,
                                pSetContextReq->peerMacAddr,
                                1,
=======
        PELOGE(limLog(pMac, LOGE, FL("numKeys:%d is more than SIR_MAC_MAX_NUM_OF_DEFAULT_KEYS\n"), pSetContextReq->keyMaterial.numKeys);)        
        limSendSmeSetContextRsp(pMac,
                                pSetContextReq->peerMacAddr,
#ifdef ANI_PRODUCT_TYPE_AP
                                pSetContextReq->aid,
#else
                                1,
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                                eSIR_SME_INVALID_PARAMETERS,NULL,
                                smesessionId,smetransactionId);

        goto end;
    }


    if((psessionEntry = peFindSessionByBssid(pMac, pSetContextReq->bssId, &sessionId)) == NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGW, FL("Session does not exist for given BSSID"));
        limSendSmeSetContextRsp(pMac,
                                pSetContextReq->peerMacAddr,
                                1,
=======
        limLog(pMac, LOGW, FL("Session does not exist for given BSSID\n"));
        limSendSmeSetContextRsp(pMac,
                                pSetContextReq->peerMacAddr,
#ifdef ANI_PRODUCT_TYPE_AP
                                pSetContextReq->aid,
#else
                                1,
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                                eSIR_SME_INVALID_PARAMETERS,NULL,
                                smesessionId,smetransactionId);

        goto end;
    }

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_SETCONTEXT_REQ_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT


    if ((((psessionEntry->limSystemRole == eLIM_STA_ROLE) || (psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE)) &&
         (psessionEntry->limSmeState == eLIM_SME_LINK_EST_STATE)) ||
        (((psessionEntry->limSystemRole == eLIM_STA_IN_IBSS_ROLE) ||
          (psessionEntry->limSystemRole == eLIM_AP_ROLE)|| (psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE)) &&
         (psessionEntry->limSmeState == eLIM_SME_NORMAL_STATE)))
    {
        // Trigger MLM_SETKEYS_REQ
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmSetKeysReq, sizeof(tLimMlmSetKeysReq)))
        {
            // Log error
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for mlmSetKeysReq"));
=======
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for mlmSetKeysReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            goto end;
        }

        pMlmSetKeysReq->edType  = pSetContextReq->keyMaterial.edType;
        pMlmSetKeysReq->numKeys = pSetContextReq->keyMaterial.numKeys;
        if(pMlmSetKeysReq->numKeys > SIR_MAC_MAX_NUM_OF_DEFAULT_KEYS)
        {
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("Num of keys exceeded max num of default keys limit"));
=======
            limLog(pMac, LOGP, FL("Num of keys exceeded max num of default keys limit\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            goto end;
        }
        palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmSetKeysReq->peerMacAddr,
                      (tANI_U8 *) &pSetContextReq->peerMacAddr,
                      sizeof(tSirMacAddr));

<<<<<<< HEAD
=======
#ifdef ANI_PRODUCT_TYPE_AP
        pMlmSetKeysReq->aid = pSetContextReq->aid;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmSetKeysReq->key,
                      (tANI_U8 *) &pSetContextReq->keyMaterial.key,
                      sizeof(tSirKeys) * (pMlmSetKeysReq->numKeys ? pMlmSetKeysReq->numKeys : 1));

        pMlmSetKeysReq->sessionId = sessionId;
#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
        PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
           FL("received SETCONTEXT_REQ message sessionId=%d"), pMlmSetKeysReq->sessionId););
#endif

=======
           FL("received SETCONTEXT_REQ message sessionId=%d\n"), pMlmSetKeysReq->sessionId););
#endif

#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        if(((pSetContextReq->keyMaterial.edType == eSIR_ED_WEP40) || (pSetContextReq->keyMaterial.edType == eSIR_ED_WEP104))
        && (psessionEntry->limSystemRole == eLIM_AP_ROLE))
        {
            if(pSetContextReq->keyMaterial.key[0].keyLength)
            {
                tANI_U8 keyId;
                keyId = pSetContextReq->keyMaterial.key[0].keyId;
                palCopyMemory(pMac, (tANI_U8 *)&psessionEntry->WEPKeyMaterial[keyId],
                   (tANI_U8 *) &pSetContextReq->keyMaterial, sizeof(tSirKeyMaterial));
            }
            else {
                tANI_U32 i;
                for( i = 0; i < SIR_MAC_MAX_NUM_OF_DEFAULT_KEYS; i++)
                {
                    palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmSetKeysReq->key[i],
                        (tANI_U8 *)psessionEntry->WEPKeyMaterial[i].key, sizeof(tSirKeys));
                }
            }
        }
<<<<<<< HEAD

        limPostMlmMessage(pMac, LIM_MLM_SETKEYS_REQ, (tANI_U32 *) pMlmSetKeysReq);
=======
#endif

        limPostMlmMessage(pMac, LIM_MLM_SETKEYS_REQ, (tANI_U32 *) pMlmSetKeysReq);

#ifdef ANI_AP_SDK
        /* For SDK acting as STA under Linux, need to consider the AP as *
         * as authenticatated.                                           */
        if ( (psessionEntry->limSystemRole == eLIM_STA_ROLE) &&
             (psessionEntry->limSmeState == eLIM_SME_LINK_EST_STATE))
        {
            tpDphHashNode pSta;
            pSta = dphGetHashEntry(pMac, 0, &psessionEntry->dph.dphHashTable);
            if (pSta)
                pSta->staAuthenticated = 1;
        }
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }
    else
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
           FL("received unexpected SME_SETCONTEXT_REQ for role %d, state=%X"),
=======
           FL("received unexpected SME_SETCONTEXT_REQ for role %d, state=%X\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           psessionEntry->limSystemRole,
           psessionEntry->limSmeState);
        limPrintSmeState(pMac, LOGE, psessionEntry->limSmeState);

        limSendSmeSetContextRsp(pMac, pSetContextReq->peerMacAddr,
<<<<<<< HEAD
                                1,
=======
#ifdef ANI_PRODUCT_TYPE_AP
                                pSetContextReq->aid,
#else
                                1,
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                                eSIR_SME_UNEXPECTED_REQ_RESULT_CODE,psessionEntry,
                                smesessionId,
                                smetransactionId);
    }

end:
    palFreeMemory( pMac->hHdd, pSetContextReq);
    return;
} /*** end __limProcessSmeSetContextReq() ***/

/**
 * __limProcessSmeRemoveKeyReq()
 *
 *FUNCTION:
 * This function is called to process SME_REMOVEKEY_REQ message
 * from HDD or upper layer application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limProcessSmeRemoveKeyReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpSirSmeRemoveKeyReq    pRemoveKeyReq;
    tLimMlmRemoveKeyReq     *pMlmRemoveKeyReq;
    tpPESession             psessionEntry;
    tANI_U8                 sessionId;  //PE sessionID
    tANI_U8                 smesessionId;  
    tANI_U16                smetransactionId;

    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
           FL("received REMOVEKEY_REQ message"));)

    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
=======
           FL("received REMOVEKEY_REQ message\n"));)

    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           return;
    }

    
    limGetSessionInfo(pMac,(tANI_U8 *)pMsgBuf,&smesessionId,&smetransactionId);

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pRemoveKeyReq,
                                                (sizeof(*pRemoveKeyReq))))
    {
        //Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for pRemoveKeyReq"));
=======
               FL("call to palAllocateMemory failed for pRemoveKeyReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        return;
     }

    if ((limRemoveKeyReqSerDes(pMac,
                                pRemoveKeyReq,
                                (tANI_U8 *) pMsgBuf) == eSIR_FAILURE))
    {
        limLog(pMac, LOGW,
<<<<<<< HEAD
               FL("received invalid SME_REMOVECONTEXT_REQ message"));
=======
               FL("received invalid SME_REMOVECONTEXT_REQ message\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        /* extra look up is needed since, session entry to be passed il limsendremovekey response */

        if((psessionEntry = peFindSessionByBssid(pMac,pRemoveKeyReq->bssId,&sessionId))== NULL)
        {     
<<<<<<< HEAD
            limLog(pMac, LOGE,FL("session does not exist for given bssId"));
=======
            limLog(pMac, LOGE,FL("session does not exist for given bssId\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            //goto end;
        }

        limSendSmeRemoveKeyRsp(pMac,
                                pRemoveKeyReq->peerMacAddr,
                                eSIR_SME_INVALID_PARAMETERS,psessionEntry,
                                smesessionId,smetransactionId);

        goto end;
    }

    if((psessionEntry = peFindSessionByBssid(pMac,pRemoveKeyReq->bssId, &sessionId))== NULL)
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
                      FL("session does not exist for given bssId"));
=======
                      FL("session does not exist for given bssId\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeRemoveKeyRsp(pMac,
                                pRemoveKeyReq->peerMacAddr,
                                eSIR_SME_UNEXPECTED_REQ_RESULT_CODE, NULL,
                                smesessionId, smetransactionId);
        goto end;
    }


    if ((((psessionEntry->limSystemRole == eLIM_STA_ROLE)|| (psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE))&&
         (psessionEntry->limSmeState == eLIM_SME_LINK_EST_STATE)) ||
        (((psessionEntry->limSystemRole == eLIM_STA_IN_IBSS_ROLE) ||
          (psessionEntry->limSystemRole == eLIM_AP_ROLE)|| (psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE)) &&
         (psessionEntry->limSmeState == eLIM_SME_NORMAL_STATE)))
    {
        // Trigger MLM_REMOVEKEYS_REQ
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmRemoveKeyReq, sizeof(tLimMlmRemoveKeyReq)))
        {
            // Log error
            limLog(pMac, LOGP,
<<<<<<< HEAD
                   FL("call to palAllocateMemory failed for mlmRemoveKeysReq"));
=======
                   FL("call to palAllocateMemory failed for mlmRemoveKeysReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

            goto end;
        }

        pMlmRemoveKeyReq->edType  = (tAniEdType)pRemoveKeyReq->edType; 
        pMlmRemoveKeyReq->keyId = pRemoveKeyReq->keyId;
        pMlmRemoveKeyReq->wepType = pRemoveKeyReq->wepType;
        pMlmRemoveKeyReq->unicast = pRemoveKeyReq->unicast;
        
        /* Update PE session Id */
        pMlmRemoveKeyReq->sessionId = sessionId;

        palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmRemoveKeyReq->peerMacAddr,
                      (tANI_U8 *) &pRemoveKeyReq->peerMacAddr,
                      sizeof(tSirMacAddr));


        limPostMlmMessage(pMac,
                          LIM_MLM_REMOVEKEY_REQ,
                          (tANI_U32 *) pMlmRemoveKeyReq);
    }
    else
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
           FL("received unexpected SME_REMOVEKEY_REQ for role %d, state=%X"),
=======
           FL("received unexpected SME_REMOVEKEY_REQ for role %d, state=%X\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           psessionEntry->limSystemRole,
           psessionEntry->limSmeState);
        limPrintSmeState(pMac, LOGE, psessionEntry->limSmeState);

        limSendSmeRemoveKeyRsp(pMac,
                                pRemoveKeyReq->peerMacAddr,
                                eSIR_SME_UNEXPECTED_REQ_RESULT_CODE,psessionEntry,
                                smesessionId,smetransactionId);
    }

end:
    palFreeMemory( pMac->hHdd, pRemoveKeyReq);
} /*** end __limProcessSmeRemoveKeyReq() ***/

void limProcessSmeGetScanChannelInfo(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirMsgQ         mmhMsg;
    tpSmeGetScanChnRsp  pSirSmeRsp;
    tANI_U16 len = 0;

    if(pMac->lim.scanChnInfo.numChnInfo > SIR_MAX_SUPPORTED_CHANNEL_LIST)
    {
<<<<<<< HEAD
        limLog(pMac, LOGW, FL("numChn is out of bounds %d"),
=======
        limLog(pMac, LOGW, FL("numChn is out of bounds %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                pMac->lim.scanChnInfo.numChnInfo);
        pMac->lim.scanChnInfo.numChnInfo = SIR_MAX_SUPPORTED_CHANNEL_LIST;
    }

    PELOG2(limLog(pMac, LOG2,
<<<<<<< HEAD
           FL("Sending message %s with number of channels %d"),
=======
           FL("Sending message %s with number of channels %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           limMsgStr(eWNI_SME_GET_SCANNED_CHANNEL_RSP), pMac->lim.scanChnInfo.numChnInfo);)

    len = sizeof(tSmeGetScanChnRsp) + (pMac->lim.scanChnInfo.numChnInfo - 1) * sizeof(tLimScanChn);
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeRsp, len ))
    {
        /// Buffer not available. Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for JOIN/REASSOC_RSP"));
=======
               FL("call to palAllocateMemory failed for JOIN/REASSOC_RSP\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        return;
    }
    palZeroMemory(pMac->hHdd, pSirSmeRsp, len);

<<<<<<< HEAD
    pSirSmeRsp->mesgType = eWNI_SME_GET_SCANNED_CHANNEL_RSP;
    pSirSmeRsp->mesgLen = len;
=======
#if defined(ANI_PRODUCT_TYPE_AP) && defined(ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*)&pSirSmeRsp->mesgType, eWNI_SME_GET_SCANNED_CHANNEL_RSP);
    sirStoreU16N((tANI_U8*)&pSirSmeRsp->mesgLen, len);
#else
    pSirSmeRsp->mesgType = eWNI_SME_GET_SCANNED_CHANNEL_RSP;
    pSirSmeRsp->mesgLen = len;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    pSirSmeRsp->sessionId = 0;

    if(pMac->lim.scanChnInfo.numChnInfo)
    {
        pSirSmeRsp->numChn = pMac->lim.scanChnInfo.numChnInfo;
        palCopyMemory(pMac->hHdd, pSirSmeRsp->scanChn, pMac->lim.scanChnInfo.scanChn, sizeof(tLimScanChn) * pSirSmeRsp->numChn);
    }
    //Clear the list
    limRessetScanChannelInfo(pMac);

    mmhMsg.type = eWNI_SME_GET_SCANNED_CHANNEL_RSP;
    mmhMsg.bodyptr = pSirSmeRsp;
    mmhMsg.bodyval = 0;
  
    pMac->lim.gLimRspReqd = false;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    limSysProcessMmhMsgApi(pMac, &mmhMsg,  ePROT);
}


<<<<<<< HEAD
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
void limProcessSmeGetAssocSTAsInfo(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirSmeGetAssocSTAsReq  getAssocSTAsReq;
    tpDphHashNode           pStaDs = NULL;
    tpPESession             psessionEntry = NULL;
    tSap_Event              sapEvent;
    tpWLAN_SAPEventCB       pSapEventCallback = NULL;
    tpSap_AssocMacAddr      pAssocStasTemp = NULL;// #include "sapApi.h"
    tANI_U8                 sessionId = CSR_SESSION_ID_INVALID;
    tANI_U8                 assocId = 0;
    tANI_U8                 staCount = 0;

    if (!limIsSmeGetAssocSTAsReqValid(pMac, &getAssocSTAsReq, (tANI_U8 *) pMsgBuf))
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
                        FL("received invalid eWNI_SME_GET_ASSOC_STAS_REQ message"));
=======
                        FL("received invalid eWNI_SME_GET_ASSOC_STAS_REQ message\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto limAssocStaEnd;
    }

    switch (getAssocSTAsReq.modId)
    {
/**        
        case VOS_MODULE_ID_HAL:
            wdaPostCtrlMsg( pMac, &msgQ );
            return;

        case VOS_MODULE_ID_TL:
            Post msg TL
            return;
*/
        case VOS_MODULE_ID_PE:
        default:
            break;
    }

<<<<<<< HEAD
    // Get Associated stations from PE
=======
    // Get Assoctiated stations from PE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    // Find PE session Entry
    if ((psessionEntry = peFindSessionByBssid(pMac, getAssocSTAsReq.bssId, &sessionId)) == NULL)
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
                        FL("session does not exist for given bssId"));
=======
                        FL("session does not exist for given bssId\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto limAssocStaEnd;
    }

    if (psessionEntry->limSystemRole != eLIM_AP_ROLE)
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
                        FL("Received unexpected message in state %X, in role %X"),
=======
                        FL("Received unexpected message in state %X, in role %X\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                        psessionEntry->limSmeState , psessionEntry->limSystemRole);
        goto limAssocStaEnd;
    }

    // Retrieve values obtained in the request message
    pSapEventCallback   = (tpWLAN_SAPEventCB)getAssocSTAsReq.pSapEventCallback;
    pAssocStasTemp      = (tpSap_AssocMacAddr)getAssocSTAsReq.pAssocStasArray;

    for (assocId = 0; assocId < psessionEntry->dph.dphHashTable.size; assocId++)// Softap dphHashTable.size = 8
    {
        pStaDs = dphGetHashEntry(pMac, assocId, &psessionEntry->dph.dphHashTable);

        if (NULL == pStaDs)
            continue;

        if (pStaDs->valid)
        {
            palCopyMemory(pMac->hHdd, (tANI_U8 *)&pAssocStasTemp->staMac,
                                        (tANI_U8 *)&pStaDs->staAddr,
                                        sizeof(v_MACADDR_t));  // Mac address
            pAssocStasTemp->assocId = (v_U8_t)pStaDs->assocId;         // Association Id
            pAssocStasTemp->staId   = (v_U8_t)pStaDs->staIndex;        // Station Id

            limLog(pMac, LOG1, FL("dph Station Number = %d"), staCount+1);
            limLog(pMac, LOG1, FL("MAC = %02x:%02x:%02x:%02x:%02x:%02x"),
                                        pStaDs->staAddr[0],
                                        pStaDs->staAddr[1],
                                        pStaDs->staAddr[2],
                                        pStaDs->staAddr[3],
                                        pStaDs->staAddr[4],
                                        pStaDs->staAddr[5]);
            limLog(pMac, LOG1, FL("Association Id = %d"),pStaDs->assocId);
            limLog(pMac, LOG1, FL("Station Index = %d"),pStaDs->staIndex);

            pAssocStasTemp++;
            staCount++;
        }
    }

limAssocStaEnd:
    // Call hdd callback with sap event to send the list of associated stations from PE
    if (pSapEventCallback != NULL)
    {
        sapEvent.sapHddEventCode = eSAP_ASSOC_STA_CALLBACK_EVENT;
        sapEvent.sapevt.sapAssocStaListEvent.module = VOS_MODULE_ID_PE;
        sapEvent.sapevt.sapAssocStaListEvent.noOfAssocSta = staCount;
        sapEvent.sapevt.sapAssocStaListEvent.pAssocStas = (tpSap_AssocMacAddr)getAssocSTAsReq.pAssocStasArray;
        pSapEventCallback(&sapEvent, getAssocSTAsReq.pUsrContext);
    }
}


/**
 * limProcessSmeGetWPSPBCSessions
 *
 *FUNCTION:
 * This function is called when query the WPS PBC overlap message is received
 *
 *LOGIC:
 * This function parses get WPS PBC overlap information message and call callback to pass  
 * WPS PBC overlap information back to hdd.
 *ASSUMPTIONS:
 *
 *
 *NOTE:
 *
 * @param  pMac     Pointer to Global MAC structure
 * @param  pMsgBuf  A pointer to WPS PBC overlap query message
*
 * @return None
 */
void limProcessSmeGetWPSPBCSessions(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirSmeGetWPSPBCSessionsReq  GetWPSPBCSessionsReq;
    tpPESession                  psessionEntry = NULL;
    tSap_Event                   sapEvent;
    tpWLAN_SAPEventCB            pSapEventCallback = NULL;
    tANI_U8                      sessionId = CSR_SESSION_ID_INVALID;
    tSirMacAddr                  zeroMac = {0,0,0,0,0,0};
        
    sapEvent.sapevt.sapGetWPSPBCSessionEvent.status = VOS_STATUS_E_FAULT;
    
    if (limIsSmeGetWPSPBCSessionsReqValid(pMac,  &GetWPSPBCSessionsReq, (tANI_U8 *) pMsgBuf) != eSIR_SUCCESS)
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
                        FL("received invalid eWNI_SME_GET_ASSOC_STAS_REQ message"));
        goto limGetWPSPBCSessionsEnd;
    }

    // Get Associated stations from PE
=======
                        FL("received invalid eWNI_SME_GET_ASSOC_STAS_REQ message\n"));
        goto limGetWPSPBCSessionsEnd;
    }

    // Get Assoctiated stations from PE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    // Find PE session Entry
    if ((psessionEntry = peFindSessionByBssid(pMac, GetWPSPBCSessionsReq.bssId, &sessionId)) == NULL)
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
                        FL("session does not exist for given bssId"));
=======
                        FL("session does not exist for given bssId\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto limGetWPSPBCSessionsEnd;
    }

    if (psessionEntry->limSystemRole != eLIM_AP_ROLE)
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
                        FL("Received unexpected message in role %X"),
=======
                        FL("Received unexpected message in role %X\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                        psessionEntry->limSystemRole);
        goto limGetWPSPBCSessionsEnd;
    }

<<<<<<< HEAD
    // Call hdd callback with sap event to send the WPS PBC overlap information
=======
    // Call hdd callback with sap event to send the WPS PBC overlap infromation
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    sapEvent.sapHddEventCode =  eSAP_GET_WPSPBC_SESSION_EVENT;
    sapEvent.sapevt.sapGetWPSPBCSessionEvent.module = VOS_MODULE_ID_PE;

    if (palEqualMemory(pMac->hHdd, zeroMac, GetWPSPBCSessionsReq.pRemoveMac, sizeof(tSirMacAddr)))
    { //This is GetWpsSession call

      limGetWPSPBCSessions(pMac,
              sapEvent.sapevt.sapGetWPSPBCSessionEvent.addr.bytes, sapEvent.sapevt.sapGetWPSPBCSessionEvent.UUID_E, 
              &sapEvent.sapevt.sapGetWPSPBCSessionEvent.wpsPBCOverlap, psessionEntry);
    }
    else
    {
      limRemovePBCSessions(pMac, GetWPSPBCSessionsReq.pRemoveMac,psessionEntry);
      /* don't have to inform the HDD/Host */
      return;
    }
    
<<<<<<< HEAD
    PELOG4(limLog(pMac, LOGE, FL("wpsPBCOverlap %d"), sapEvent.sapevt.sapGetWPSPBCSessionEvent.wpsPBCOverlap);)
=======
    PELOG4(limLog(pMac, LOGE, FL("wpsPBCOverlap %d\n"), sapEvent.sapevt.sapGetWPSPBCSessionEvent.wpsPBCOverlap);)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    PELOG4(limPrintMacAddr(pMac, sapEvent.sapevt.sapGetWPSPBCSessionEvent.addr.bytes, LOG4);)
    
    sapEvent.sapevt.sapGetWPSPBCSessionEvent.status = VOS_STATUS_SUCCESS;
  
limGetWPSPBCSessionsEnd:
    pSapEventCallback   = (tpWLAN_SAPEventCB)GetWPSPBCSessionsReq.pSapEventCallback;
    pSapEventCallback(&sapEvent, GetWPSPBCSessionsReq.pUsrContext);
}

<<<<<<< HEAD
=======
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


/**
 * __limCounterMeasures()
 *
 * FUNCTION:
 * This function is called to "implement" MIC counter measure
 * and is *temporary* only
 *
 * LOGIC: on AP, disassoc all STA associated thru TKIP,
 * we don't do the proper STA disassoc sequence since the
 * BSS will be stoped anyway
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @return None
 */

static void
__limCounterMeasures(tpAniSirGlobal pMac, tpPESession psessionEntry)
{
    tSirMacAddr mac = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    if ( (psessionEntry->limSystemRole == eLIM_AP_ROLE) || (psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE)
        || (psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE) )
         
<<<<<<< HEAD
        limSendDisassocMgmtFrame(pMac, eSIR_MAC_MIC_FAILURE_REASON, mac, psessionEntry, FALSE);

};


=======
        limSendDisassocMgmtFrame(pMac, eSIR_MAC_MIC_FAILURE_REASON, mac, psessionEntry);

    tx_thread_sleep(10);
};


#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
void
limProcessTkipCounterMeasures(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirSmeTkipCntrMeasReq  tkipCntrMeasReq;
    tpPESession             psessionEntry;
    tANI_U8                 sessionId;      //PE sessionId

    if ( limTkipCntrMeasReqSerDes( pMac, &tkipCntrMeasReq, (tANI_U8 *) pMsgBuf ) != eSIR_SUCCESS )
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
                        FL("received invalid eWNI_SME_TKIP_CNTR_MEAS_REQ message"));
=======
                        FL("received invalid eWNI_SME_TKIP_CNTR_MEAS_REQ message\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    if ( NULL == (psessionEntry = peFindSessionByBssid( pMac, tkipCntrMeasReq.bssId, &sessionId )) )
    {
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("session does not exist for given BSSID "));
=======
        limLog(pMac, LOGE, FL("session does not exist for given BSSID \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    if ( tkipCntrMeasReq.bEnable )
    {
        __limCounterMeasures( pMac, psessionEntry );
    }

    psessionEntry->bTkipCntrMeasActive = tkipCntrMeasReq.bEnable;
}
<<<<<<< HEAD
=======
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


static void
__limHandleSmeStopBssRequest(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirSmeStopBssReq  stopBssReq;
    tSirRetStatus      status;
    tLimSmeStates      prevState;
    tANI_U8            sessionId;  //PE sessionId
    tpPESession        psessionEntry;
    tANI_U8            smesessionId;
    tANI_U16           smetransactionId;
    
    limGetSessionInfo(pMac,(tANI_U8 *)pMsgBuf,&smesessionId,&smetransactionId);
        


    if ((limStopBssReqSerDes(pMac, &stopBssReq, (tANI_U8 *) pMsgBuf) != eSIR_SUCCESS) ||
        !limIsSmeStopBssReqValid(pMsgBuf))
    {
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("received invalid SME_STOP_BSS_REQ message"));)
=======
        PELOGW(limLog(pMac, LOGW, FL("received invalid SME_STOP_BSS_REQ message\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        /// Send Stop BSS response to host
        limSendSmeRsp(pMac, eWNI_SME_STOP_BSS_RSP, eSIR_SME_INVALID_PARAMETERS,smesessionId,smetransactionId);
        return;
    }

 
    if((psessionEntry = peFindSessionByBssid(pMac,stopBssReq.bssId,&sessionId)) == NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGW, FL("session does not exist for given BSSID "));
=======
        limLog(pMac, LOGW, FL("session does not exist for given BSSID \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeRsp(pMac, eWNI_SME_STOP_BSS_RSP, eSIR_SME_INVALID_PARAMETERS,smesessionId,smetransactionId);
        return;
    }

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_STOP_BSS_REQ_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT


    if ((psessionEntry->limSmeState != eLIM_SME_NORMAL_STATE) ||    /* Added For BT -AMP Support */
        (psessionEntry->limSystemRole == eLIM_STA_ROLE ))
    {
        /**
         * Should not have received STOP_BSS_REQ in states
         * other than 'normal' state or on STA in Infrastructure
         * mode. Log error and return response to host.
         */
        limLog(pMac, LOGE,
<<<<<<< HEAD
           FL("received unexpected SME_STOP_BSS_REQ in state %X, for role %d"),
=======
           FL("received unexpected SME_STOP_BSS_REQ in state %X, for role %d\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           psessionEntry->limSmeState, psessionEntry->limSystemRole);
        limPrintSmeState(pMac, LOGE, psessionEntry->limSmeState);
        /// Send Stop BSS response to host
        limSendSmeRsp(pMac, eWNI_SME_STOP_BSS_RSP, eSIR_SME_UNEXPECTED_REQ_RESULT_CODE,smesessionId,smetransactionId);
        return;
    }

<<<<<<< HEAD
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    if (psessionEntry->limSystemRole == eLIM_AP_ROLE )
    {
        limWPSPBCClose(pMac, psessionEntry);
    }
<<<<<<< HEAD
    PELOGW(limLog(pMac, LOGW, FL("RECEIVED STOP_BSS_REQ with reason code=%d"), stopBssReq.reasonCode);)
=======
#endif
    PELOGW(limLog(pMac, LOGW, FL("RECEIVED STOP_BSS_REQ with reason code=%d\n"), stopBssReq.reasonCode);)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    prevState = psessionEntry->limSmeState;

    psessionEntry->limSmeState = eLIM_SME_IDLE_STATE;
    MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));

    /* Update SME session Id and Transaction Id */
    psessionEntry->smeSessionId = smesessionId;
    psessionEntry->transactionId = smetransactionId;

    /* BTAMP_STA and STA_IN_IBSS should NOT send Disassoc frame */
    if ( (eLIM_STA_IN_IBSS_ROLE != psessionEntry->limSystemRole) && (eLIM_BT_AMP_STA_ROLE != psessionEntry->limSystemRole) )
    {
        tSirMacAddr   bcAddr = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
        if ((stopBssReq.reasonCode == eSIR_SME_MIC_COUNTER_MEASURES))
            // Send disassoc all stations associated thru TKIP
            __limCounterMeasures(pMac,psessionEntry);
        else
<<<<<<< HEAD
            limSendDisassocMgmtFrame(pMac, eSIR_MAC_DEAUTH_LEAVING_BSS_REASON, bcAddr, psessionEntry, FALSE);
=======
            limSendDisassocMgmtFrame(pMac, eSIR_MAC_DISASSOC_LEAVING_BSS_REASON, bcAddr,psessionEntry);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

    //limDelBss is also called as part of coalescing, when we send DEL BSS followed by Add Bss msg.
    pMac->lim.gLimIbssCoalescingHappened = false;
    
    /* send a delBss to HAL and wait for a response */
    status = limDelBss(pMac, NULL,psessionEntry->bssIdx,psessionEntry);
    
    if (status != eSIR_SUCCESS)
    {
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("delBss failed for bss %d"), psessionEntry->bssIdx);)
=======
        PELOGE(limLog(pMac, LOGE, FL("delBss failed for bss %d\n"), psessionEntry->bssIdx);)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        psessionEntry->limSmeState= prevState;

        MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, psessionEntry->peSessionId, psessionEntry->limSmeState));
   
        limSendSmeRsp(pMac, eWNI_SME_STOP_BSS_RSP, eSIR_SME_STOP_BSS_FAILURE,smesessionId,smetransactionId);
    }
}


/**--------------------------------------------------------------
\fn     __limProcessSmeStopBssReq

\brief  Wrapper for the function __limHandleSmeStopBssRequest
        This message will be defered until softmac come out of
        scan mode. Message should be handled even if we have
        detected radar in the current operating channel.
\param  pMac
\param  pMsg

\return TRUE - If we consumed the buffer
        FALSE - If have defered the message.
 ---------------------------------------------------------------*/
static tANI_BOOLEAN
__limProcessSmeStopBssReq(tpAniSirGlobal pMac, tpSirMsgQ pMsg)
{
    if (__limIsDeferedMsgForLearn(pMac, pMsg))
    {
        /**
         * If message defered, buffer is not consumed yet.
         * So return false
         */
        return eANI_BOOLEAN_FALSE;
    }
    __limHandleSmeStopBssRequest(pMac, (tANI_U32 *) pMsg->bodyptr);
    return eANI_BOOLEAN_TRUE;
} /*** end __limProcessSmeStopBssReq() ***/


void limProcessSmeDelBssRsp(
    tpAniSirGlobal  pMac,
    tANI_U32        body,tpPESession psessionEntry)
{

    (void) body;
    SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
    //TBD: get the sessionEntry
    dphHashTableClassInit(pMac, &psessionEntry->dph.dphHashTable);
    limDeletePreAuthList(pMac);
    limIbssDelete(pMac,psessionEntry);
    limSendSmeRsp(pMac, eWNI_SME_STOP_BSS_RSP, eSIR_SME_SUCCESS,psessionEntry->smeSessionId,psessionEntry->transactionId);
    return;
}


<<<<<<< HEAD
=======
#if 0
/**
 * __limProcessSmePromiscuousReq()
 *
 *FUNCTION:
 * This function is called to process SME_PROMISCUOUS_REQ message
 * from HDD or upper layer application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limProcessSmePromiscuousReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{

    tANI_U32                cfg = sizeof(tSirMacAddr);
    tSirMacAddr        currentBssId;
    tLimMlmDisassocReq *pMlmDisassocReq;
    tSirMacAddr        bcAddr = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    
    
    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
           return;
    }

    PELOG1(limLog(pMac, LOG1,
           FL("received PROMISCUOUS_REQ message\n"));)

    if (wlan_cfgGetStr(pMac, WNI_CFG_BSSID, currentBssId, &cfg) !=
                                eSIR_SUCCESS)
    {
        /// Could not get BSSID from CFG. Log error.
        limLog(pMac, LOGP, FL("could not retrieve BSSID\n"));
    }

    if ((((pMac->lim.gLimSystemRole == eLIM_STA_ROLE) ||
         (pMac->lim.gLimSystemRole == eLIM_STA_IN_IBSS_ROLE)) &&
         ((pMac->lim.gLimSmeState == eLIM_SME_ASSOCIATED_STATE) ||
          (pMac->lim.gLimSmeState == eLIM_SME_LINK_EST_STATE))) ||
        ((pMac->lim.gLimSystemRole == eLIM_AP_ROLE) &&
         (pMac->lim.gLimSmeState == eLIM_SME_NORMAL_STATE)))
    {
        // Trigger Disassociation frame to peer MAC entity
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMlmDisassocReq, sizeof(tLimMlmDisassocReq)))
        {
            // Log error
            limLog(pMac, LOGP,
                   FL("call to palAllocateMemory failed for mlmDisassocReq\n"));

            return;
        }

        if (pMac->lim.gLimSystemRole == eLIM_AP_ROLE)
            palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMlmDisassocReq->peerMacAddr,
                          (tANI_U8 *) &bcAddr,
                          sizeof(tSirMacAddr));
        else
            palCopyMemory( pMac->hHdd, pMlmDisassocReq->peerMacAddr,
                          currentBssId,
                          sizeof(tSirMacAddr));

        pMlmDisassocReq->reasonCode      =
                                eSIR_MAC_DISASSOC_LEAVING_BSS_REASON;
        pMlmDisassocReq->disassocTrigger =
                                      eLIM_PROMISCUOUS_MODE_DISASSOC;

        pMac->lim.gLimPrevSmeState = pMac->lim.gLimSmeState;
        pMac->lim.gLimSmeState     = eLIM_SME_WT_DISASSOC_STATE;
     MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, 0, pMac->lim.gLimSmeState));

        limPostMlmMessage(pMac,
                          LIM_MLM_DISASSOC_REQ,
                          (tANI_U32 *) pMlmDisassocReq);
    }
    else
    {
        // Send Promiscuous mode response to host
        limSendSmePromiscuousModeRsp(pMac);

        pMac->lim.gLimSmeState = eLIM_SME_OFFLINE_STATE;
     MTRACE(macTrace(pMac, TRACE_CODE_SME_STATE, 0, pMac->lim.gLimSmeState));
    }

} /*** end __limProcessSmePromiscuousReq() ***/
#endif


>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
/**---------------------------------------------------------------
\fn     __limProcessSmeAssocCnfNew
\brief  This function handles SME_ASSOC_CNF/SME_REASSOC_CNF 
\       in BTAMP AP.
\
\param  pMac
\param  msgType - message type
\param  pMsgBuf - a pointer to the SME message buffer
\return None
------------------------------------------------------------------*/

  void
__limProcessSmeAssocCnfNew(tpAniSirGlobal pMac, tANI_U32 msgType, tANI_U32 *pMsgBuf)
{
    tSirSmeAssocCnf    assocCnf;
    tpDphHashNode      pStaDs = NULL;
    tpPESession        psessionEntry= NULL;
    tANI_U8            sessionId; 
      

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("pMsgBuf is NULL "));
=======
        limLog(pMac, LOGE, FL("pMsgBuf is NULL \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }

    if ((limAssocCnfSerDes(pMac, &assocCnf, (tANI_U8 *) pMsgBuf) == eSIR_FAILURE) ||
        !__limIsSmeAssocCnfValid(&assocCnf))
    {
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Received invalid SME_RE(ASSOC)_CNF message "));
=======
        limLog(pMac, LOGE, FL("Received invalid SME_RE(ASSOC)_CNF message \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }

    if((psessionEntry = peFindSessionByBssid(pMac, assocCnf.bssId, &sessionId))== NULL)
    {        
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("session does not exist for given bssId"));
=======
        limLog(pMac, LOGE, FL("session does not exist for given bssId\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }

    if ( ((psessionEntry->limSystemRole != eLIM_AP_ROLE) && (psessionEntry->limSystemRole != eLIM_BT_AMP_AP_ROLE)) ||
         ((psessionEntry->limSmeState != eLIM_SME_NORMAL_STATE) && (psessionEntry->limSmeState != eLIM_SME_NORMAL_CHANNEL_SCAN_STATE)))
    {
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Received unexpected message %X in state %X, in role %X"),
=======
        limLog(pMac, LOGE, FL("Received unexpected message %X in state %X, in role %X\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               msgType, psessionEntry->limSmeState , psessionEntry->limSystemRole);
        goto end;
    }

    pStaDs = dphGetHashEntry(pMac, assocCnf.aid, &psessionEntry->dph.dphHashTable);
    
    if (pStaDs == NULL)
    {        
        limLog(pMac, LOG1,
            FL("Received invalid message %X due to no STA context, for aid %d, peer "),
            msgType, assocCnf.aid);
        limPrintMacAddr(pMac, assocCnf.peerMacAddr, LOG1);     

        /*
        ** send a DISASSOC_IND message to WSM to make sure
        ** the state in WSM and LIM is the same
        **/
       limSendSmeDisassocNtf( pMac, assocCnf.peerMacAddr, eSIR_SME_STA_NOT_ASSOCIATED,
                              eLIM_PEER_ENTITY_DISASSOC, assocCnf.aid,psessionEntry->smeSessionId,psessionEntry->transactionId,psessionEntry);
       goto end;
    }
    if ((pStaDs &&
         (( !palEqualMemory( pMac->hHdd,(tANI_U8 *) pStaDs->staAddr,
                     (tANI_U8 *) assocCnf.peerMacAddr,
                     sizeof(tSirMacAddr)) ) ||
          (pStaDs->mlmStaContext.mlmState != eLIM_MLM_WT_ASSOC_CNF_STATE) ||
          ((pStaDs->mlmStaContext.subType == LIM_ASSOC) &&
           (msgType != eWNI_SME_ASSOC_CNF)) ||
          ((pStaDs->mlmStaContext.subType == LIM_REASSOC) &&
<<<<<<< HEAD
           (msgType != eWNI_SME_ASSOC_CNF))))) // since softap is passing this as ASSOC_CNF and subtype differs
=======
#ifdef WLAN_SOFTAP_FEATURE
           (msgType != eWNI_SME_ASSOC_CNF))))) // since softap is passing this as ASSOC_CNF and subtype differs
#else
           (msgType != eWNI_SME_REASSOC_CNF)))))
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    {
        limLog(pMac, LOG1,
           FL("Received invalid message %X due to peerMacAddr mismatched or not in eLIM_MLM_WT_ASSOC_CNF_STATE state, for aid %d, peer "),
           msgType, assocCnf.aid);
        limPrintMacAddr(pMac, assocCnf.peerMacAddr, LOG1);
        goto end;
    }

    /*
    ** Deactivate/delet CNF_WAIT timer since ASSOC_CNF
    ** has been received
    **/
<<<<<<< HEAD
    limLog(pMac, LOG1, FL("Received SME_ASSOC_CNF. Delete Timer"));
=======
    limLog(pMac, LOG1, FL("Received SME_ASSOC_CNF. Delete Timer\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    limDeactivateAndChangePerStaIdTimer(pMac, eLIM_CNF_WAIT_TIMER, pStaDs->assocId);

    if (assocCnf.statusCode == eSIR_SME_SUCCESS)
    {        
        /* In BTAMP-AP, PE already finished the WDA_ADD_STA sequence
         * when it had received Assoc Request frame. Now, PE just needs to send 
         * Association Response frame to the requesting BTAMP-STA.
         */
        pStaDs->mlmStaContext.mlmState = eLIM_MLM_LINK_ESTABLISHED_STATE;
<<<<<<< HEAD
        limLog(pMac, LOG1, FL("sending Assoc Rsp frame to STA (assoc id=%d) "), pStaDs->assocId);
=======
        limLog(pMac, LOG1, FL("sending Assoc Rsp frame to STA (assoc id=%d) \n"), pStaDs->assocId);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendAssocRspMgmtFrame( pMac, eSIR_SUCCESS, pStaDs->assocId, pStaDs->staAddr, 
                                  pStaDs->mlmStaContext.subType, pStaDs, psessionEntry);
        goto end;      
    } // (assocCnf.statusCode == eSIR_SME_SUCCESS)
    else
    {
        // SME_ASSOC_CNF status is non-success, so STA is not allowed to be associated
        /*Since the HAL sta entry is created for denied STA we need to remove this HAL entry.So to do that set updateContext to 1*/
        if(!pStaDs->mlmStaContext.updateContext)
           pStaDs->mlmStaContext.updateContext = 1;
        limRejectAssociation(pMac, pStaDs->staAddr,
                             pStaDs->mlmStaContext.subType,
                             true, pStaDs->mlmStaContext.authType,
                             pStaDs->assocId, true,
                             eSIR_MAC_UNSPEC_FAILURE_STATUS, psessionEntry);
<<<<<<< HEAD
=======
        return;
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    }

end:
    if((psessionEntry != NULL) && (pStaDs != NULL))
    {
        if ( psessionEntry->parsedAssocReq[pStaDs->assocId] != NULL )
        {
            if ( ((tpSirAssocReq)(psessionEntry->parsedAssocReq[pStaDs->assocId]))->assocReqFrame) 
            {
                palFreeMemory(pMac->hHdd,((tpSirAssocReq)(psessionEntry->parsedAssocReq[pStaDs->assocId]))->assocReqFrame);
                ((tpSirAssocReq)(psessionEntry->parsedAssocReq[pStaDs->assocId]))->assocReqFrame = NULL;
            }

            palFreeMemory(pMac->hHdd, psessionEntry->parsedAssocReq[pStaDs->assocId]);  
            psessionEntry->parsedAssocReq[pStaDs->assocId] = NULL;
        }
    }

} /*** end __limProcessSmeAssocCnfNew() ***/


<<<<<<< HEAD


static void
__limProcessSmeAddtsReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpDphHashNode   pStaDs;
    tSirMacAddr     peerMac;
    tpSirAddtsReq   pSirAddts;
    tANI_U32        timeout;
    tpPESession     psessionEntry;
    tANI_U8         sessionId;  //PE sessionId
    tANI_U8         smesessionId;
    tANI_U16        smetransactionId;


    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
           return;
    }

    limGetSessionInfo(pMac,(tANI_U8 *)pMsgBuf,&smesessionId,&smetransactionId);
    
    pSirAddts = (tpSirAddtsReq) pMsgBuf;

    if((psessionEntry = peFindSessionByBssid(pMac, pSirAddts->bssId,&sessionId))== NULL)
    {
        limLog(pMac, LOGE, "Session Does not exist for given bssId");
        return;
    }
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_ADDTS_REQ_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
=======
#ifdef ANI_PRODUCT_TYPE_AP
/**
 * __limProcessSmeAssocCnf()
 *
 *FUNCTION:
 * This function is called by limProcessSmeMessages() upon
 * receiving SME_ASSOC_CNF/SME_REASSOC_CNF from WSM.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 *
 * @return None
 */

static void
__limProcessSmeAssocCnf(tpAniSirGlobal pMac, tANI_U32 msgType, tANI_U32 *pMsgBuf)
{
    tSirSmeAssocCnf    assocCnf;
    tpDphHashNode      pStaDs;
    tpPESession        psessionEntry;
    tANI_U8            sessionId; 
    tHalBitVal cbBitVal;
    tANI_U8 tspecIdx = 0; //index in the lim tspec table.

    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
           return;
    }

   if ((limAssocCnfSerDes(pMac, &assocCnf, (tANI_U8 *) pMsgBuf) ==
                            eSIR_FAILURE) ||
        !__limIsSmeAssocCnfValid(&assocCnf))
    {
        limLog(pMac, LOGW,
           FL("Received re/assocCnf message with invalid parameters\n"));

        return;
    }

    if((psessionEntry = peFindSessionByBssid(pMac,assocCnf->bssId,&sessionId))== NULL)
    {
        
        limLog(pMac, LOGE,
                      FL("session does not exist for given bssId\n"));
        return;
    }

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_ASSOC_CNF_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    
    if ( ((psessionEntry->limSystemRole != eLIM_AP_ROLE) && (psessionEntry->limSystemRole != eLIM_BT_AMP_AP_ROLE)) ||
         ((psessionEntry->limSmeState != eLIM_SME_NORMAL_STATE) && (psessionEntry->limSmeState != eLIM_SME_NORMAL_CHANNEL_SCAN_STATE)))
    {
        limLog(pMac, LOGE,
         FL("Received unexpected message %X in state %X, in role %X\n"),
         msgType, psessionEntry->limSmeState , psessionEntry->limSystemRole);

        return;
    }

    pStaDs = dphGetHashEntry(pMac, assocCnf.aid, &psessionEntry->dph.dphHashTable);


    if (pStaDs == NULL)
    {
        
        PELOG1(limLog(pMac, LOG1,
           FL("Received invalid message %X due to no STA context, for aid %d, peer "),
           msgType, assocCnf.aid);
        limPrintMacAddr(pMac, assocCnf.peerMacAddr, LOG1);)
       
        /*
        ** send a DISASSOC_IND message to WSM to make sure
        ** the state in WSM and LIM is the same
        **/

        limSendSmeDisassocNtf(pMac,
            assocCnf.peerMacAddr,
            eSIR_SME_STA_NOT_ASSOCIATED,
            eLIM_PEER_ENTITY_DISASSOC,
            assocCnf.aid,psessionEntry);

        return;
    }
    if ((pStaDs &&
         (( !palEqualMemory( pMac->hHdd,(tANI_U8 *) pStaDs->staAddr,
                     (tANI_U8 *) assocCnf.peerMacAddr,
                     sizeof(tSirMacAddr)) ) ||
          (pStaDs->mlmStaContext.mlmState !=
                          eLIM_MLM_WT_ASSOC_CNF_STATE) ||
          ((pStaDs->mlmStaContext.subType == LIM_ASSOC) &&
           (msgType != eWNI_SME_ASSOC_CNF)) ||
          ((pStaDs->mlmStaContext.subType == LIM_REASSOC) &&
           (msgType != eWNI_SME_REASSOC_CNF)))))
    {
        PELOG1(limLog(pMac, LOG1,
           FL("Received invalid message %X due to peerMacAddr mismatched or not in eLIM_MLM_WT_ASSOC_CNF_STATE state, for aid %d, peer "),
           msgType, assocCnf.aid);
        limPrintMacAddr(pMac, assocCnf.peerMacAddr, LOG1);)

        return;
    }

    /*
    ** Deactivate/delet CNF_WAIT timer since ASSOC_CNF
    ** has been received
    **/

    PELOG1(limLog(pMac, LOG1, FL("Received Cnf. Delete Timer\n"));)
    limDeactivateAndChangePerStaIdTimer(pMac, eLIM_CNF_WAIT_TIMER,
                                        pStaDs->assocId);

    if (assocCnf.statusCode == eSIR_SME_SUCCESS)
    {
        tSirMacScheduleIE schedule;

        // If STA is a TITAN-compatible device, then setup
        // the TITAN proprietary capabilities appropriately
        // in the per STA DS, as per the local TITAN Prop
        // capabilities of this AP

        // STA is allowed to be associated
        if (pStaDs->mlmStaContext.updateContext)
        {

              tLimMlmStates mlmPrevState = pStaDs->mlmStaContext.mlmState;
              //we need to set the mlmState here in order differentiate in limDelSta.
              pStaDs->mlmStaContext.mlmState = eLIM_MLM_WT_ASSOC_DEL_STA_RSP_STATE;
              if(limDelSta(pMac, pStaDs, true,psessionEntry) != eSIR_SUCCESS)
              {
                  limLog(pMac, LOGE,
                         FL("could not DEL STA with assocId=%d staId %d\n"),
                         pStaDs->assocId, pStaDs->staIndex);

                  limRejectAssociation(pMac,
                           pStaDs->staAddr,
                           pStaDs->mlmStaContext.subType,
                           true, pStaDs->mlmStaContext.authType,
                           pStaDs->assocId, true,
                           (tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS,
                           psessionEntry);

                  //Restoring the state back.
                  pStaDs->mlmStaContext.mlmState = mlmPrevState;
                  return;
              }
              return;
        }
        else
        {
            // Add STA context at HW
            if (limAddSta(pMac, pStaDs,psessionEntry) != eSIR_SUCCESS)
            {
                limLog(pMac, LOGE,
                       FL("could not Add STA with assocId=%d\n"),
                       pStaDs->assocId);

              // delete the TS if it has already been added.
               // send the response with error status.
                if(pStaDs->qos.addtsPresent)
                {
                  limAdmitControlDeleteTS(pMac, pStaDs->assocId, &pStaDs->qos.addts.tspec.tsinfo, NULL, &tspecIdx);
                }

                limRejectAssociation(pMac,
                         pStaDs->staAddr,
                         pStaDs->mlmStaContext.subType,
                         true, pStaDs->mlmStaContext.authType,
                         pStaDs->assocId, true,
                         (tSirResultCodes) eSIR_MAC_UNSPEC_FAILURE_STATUS,
                         psessionEntry);

            }
            return;
        }

   } // if (assocCnf.statusCode == eSIR_SME_SUCCESS)
    else
    {
        // STA is not allowed to be associated
        limRejectAssociation(pMac, pStaDs->staAddr,
                             pStaDs->mlmStaContext.subType,
                             true, pStaDs->mlmStaContext.authType,
                             pStaDs->assocId, true,
                             assocCnf.statusCode, psessionEntry);
    }
} /*** end __limProcessSmeAssocCnf() ***/
#endif


static void
__limProcessSmeAddtsReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpDphHashNode   pStaDs;
    tSirMacAddr     peerMac;
    tpSirAddtsReq   pSirAddts;
    tANI_U32        timeout;
    tpPESession     psessionEntry;
    tANI_U8         sessionId;  //PE sessionId
    tANI_U8         smesessionId;
    tANI_U16        smetransactionId;


    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
           return;
    }

    limGetSessionInfo(pMac,(tANI_U8 *)pMsgBuf,&smesessionId,&smetransactionId);
    
    pSirAddts = (tpSirAddtsReq) pMsgBuf;

    if((psessionEntry = peFindSessionByBssid(pMac, pSirAddts->bssId,&sessionId))== NULL)
    {
        limLog(pMac, LOGE, "Session Does not exist for given bssId\n");
        return;
    }
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_ADDTS_REQ_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    


    /* if sta
     *  - verify assoc state
     *  - send addts request to ap
     *  - wait for addts response from ap
     * if ap, just ignore with error log
     */
    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
           FL("Received SME_ADDTS_REQ (TSid %d, UP %d)"),
=======
           FL("Received SME_ADDTS_REQ (TSid %d, UP %d)\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           pSirAddts->req.tspec.tsinfo.traffic.tsid,
           pSirAddts->req.tspec.tsinfo.traffic.userPrio);)

    if ((psessionEntry->limSystemRole != eLIM_STA_ROLE)&&(psessionEntry->limSystemRole != eLIM_BT_AMP_STA_ROLE))
    {
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, "AddTs received on AP - ignoring");)
=======
        PELOGE(limLog(pMac, LOGE, "AddTs received on AP - ignoring\n");)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeAddtsRsp(pMac, pSirAddts->rspReqd, eSIR_FAILURE, psessionEntry, pSirAddts->req.tspec, 
                smesessionId,smetransactionId);
        return;
    }

    //Ignore the request if STA is in 11B mode.
    if(psessionEntry->dot11mode == WNI_CFG_DOT11_MODE_11B)
    {
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, "AddTS received while Dot11Mode is 11B - ignoring");)
=======
        PELOGE(limLog(pMac, LOGE, "AddTS received while Dot11Mode is 11B - ignoring\n");)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeAddtsRsp(pMac, pSirAddts->rspReqd, eSIR_FAILURE, psessionEntry, pSirAddts->req.tspec, 
                smesessionId,smetransactionId);
        return;
    }


    pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);

    if(pStaDs == NULL)
    {
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, "Cannot find AP context for addts req");)
=======
        PELOGE(limLog(pMac, LOGE, "Cannot find AP context for addts req\n");)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeAddtsRsp(pMac, pSirAddts->rspReqd, eSIR_FAILURE, psessionEntry, pSirAddts->req.tspec,
            smesessionId,smetransactionId);
        return;
    }

    if ((! pStaDs->valid) ||
        (pStaDs->mlmStaContext.mlmState != eLIM_MLM_LINK_ESTABLISHED_STATE))
    {
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, "AddTs received in invalid MLM state");)
=======
        PELOGE(limLog(pMac, LOGE, "AddTs received in invalid MLM state\n");)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeAddtsRsp(pMac, pSirAddts->rspReqd, eSIR_FAILURE, psessionEntry, pSirAddts->req.tspec,
            smesessionId,smetransactionId);
        return;
    }

    pSirAddts->req.wsmTspecPresent = 0;
    pSirAddts->req.wmeTspecPresent = 0;
    pSirAddts->req.lleTspecPresent = 0;
    
    if ((pStaDs->wsmEnabled) &&
        (pSirAddts->req.tspec.tsinfo.traffic.accessPolicy != SIR_MAC_ACCESSPOLICY_EDCA))
        pSirAddts->req.wsmTspecPresent = 1;
    else if (pStaDs->wmeEnabled)
        pSirAddts->req.wmeTspecPresent = 1;
    else if (pStaDs->lleEnabled)
        pSirAddts->req.lleTspecPresent = 1;
    else
    {
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, FL("ADDTS_REQ ignore - qos is disabled"));)
=======
        PELOGW(limLog(pMac, LOGW, FL("ADDTS_REQ ignore - qos is disabled\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        limSendSmeAddtsRsp(pMac, pSirAddts->rspReqd, eSIR_FAILURE, psessionEntry, pSirAddts->req.tspec,
            smesessionId,smetransactionId);
        return;
    }

    if ((psessionEntry->limSmeState != eLIM_SME_ASSOCIATED_STATE) &&
        (psessionEntry->limSmeState != eLIM_SME_LINK_EST_STATE))
    {
<<<<<<< HEAD
        limLog(pMac, LOGE, "AddTs received in invalid LIMsme state (%d)",
=======
        limLog(pMac, LOGE, "AddTs received in invalid LIMsme state (%d)\n",
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
              psessionEntry->limSmeState);
        limSendSmeAddtsRsp(pMac, pSirAddts->rspReqd, eSIR_FAILURE, psessionEntry, pSirAddts->req.tspec,
            smesessionId,smetransactionId);
        return;
    }

    if (pMac->lim.gLimAddtsSent)
    {
<<<<<<< HEAD
        limLog(pMac, LOGE, "Addts (token %d, tsid %d, up %d) is still pending",
=======
        limLog(pMac, LOGE, "Addts (token %d, tsid %d, up %d) is still pending\n",
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               pMac->lim.gLimAddtsReq.req.dialogToken,
               pMac->lim.gLimAddtsReq.req.tspec.tsinfo.traffic.tsid,
               pMac->lim.gLimAddtsReq.req.tspec.tsinfo.traffic.userPrio);
        limSendSmeAddtsRsp(pMac, pSirAddts->rspReqd, eSIR_FAILURE, psessionEntry, pSirAddts->req.tspec,
            smesessionId,smetransactionId);
        return;
    }

    #if 0
    val = sizeof(tSirMacAddr);
    if (wlan_cfgGetStr(pMac, WNI_CFG_BSSID, peerMac, &val) != eSIR_SUCCESS)
    {
        /// Could not get BSSID from CFG. Log error.
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("could not retrieve BSSID"));
=======
        limLog(pMac, LOGP, FL("could not retrieve BSSID\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }
    #endif
    sirCopyMacAddr(peerMac,psessionEntry->bssId);

    // save the addts request
    pMac->lim.gLimAddtsSent = true;
    palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMac->lim.gLimAddtsReq, (tANI_U8 *) pSirAddts, sizeof(tSirAddtsReq));

    // ship out the message now
    limSendAddtsReqActionFrame(pMac, peerMac, &pSirAddts->req,
            psessionEntry);
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, "Sent ADDTS request");)
=======
    PELOG1(limLog(pMac, LOG1, "Sent ADDTS request\n");)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

    // start a timer to wait for the response
    if (pSirAddts->timeout) 
        timeout = pSirAddts->timeout;
    else if (wlan_cfgGetInt(pMac, WNI_CFG_ADDTS_RSP_TIMEOUT, &timeout) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("Unable to get Cfg param %d (Addts Rsp Timeout)"),
=======
        limLog(pMac, LOGP, FL("Unable to get Cfg param %d (Addts Rsp Timeout)\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               WNI_CFG_ADDTS_RSP_TIMEOUT);
        return;
    }

    timeout = SYS_MS_TO_TICKS(timeout);
    if (tx_timer_change(&pMac->lim.limTimers.gLimAddtsRspTimer, timeout, 0) != TX_SUCCESS)
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("AddtsRsp timer change failed!"));
=======
        limLog(pMac, LOGP, FL("AddtsRsp timer change failed!\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }
    pMac->lim.gLimAddtsRspTimerCount++;
    if (tx_timer_change_context(&pMac->lim.limTimers.gLimAddtsRspTimer,
                                pMac->lim.gLimAddtsRspTimerCount) != TX_SUCCESS)
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("AddtsRsp timer change failed!"));
=======
        limLog(pMac, LOGP, FL("AddtsRsp timer change failed!\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }
    MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, psessionEntry->peSessionId, eLIM_ADDTS_RSP_TIMER));
    
    //add the sessionId to the timer object
    pMac->lim.limTimers.gLimAddtsRspTimer.sessionId = sessionId;
    if (tx_timer_activate(&pMac->lim.limTimers.gLimAddtsRspTimer) != TX_SUCCESS)
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("AddtsRsp timer activation failed!"));
=======
        limLog(pMac, LOGP, FL("AddtsRsp timer activation failed!\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }
    return;
}


static void
__limProcessSmeDeltsReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tSirMacAddr     peerMacAddr;
    tANI_U8         ac;
    tSirMacTSInfo   *pTsinfo;
    tpSirDeltsReq   pDeltsReq = (tpSirDeltsReq) pMsgBuf;
    tpDphHashNode   pStaDs = NULL;
    tpPESession     psessionEntry;
    tANI_U8         sessionId;
    tANI_U32        status = eSIR_SUCCESS;
    tANI_U8         smesessionId;
    tANI_U16        smetransactionId;    

    limGetSessionInfo(pMac,(tANI_U8 *)pMsgBuf,&smesessionId,&smetransactionId);
    
    if((psessionEntry = peFindSessionByBssid(pMac, pDeltsReq->bssId, &sessionId))== NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGE, "Session Does not exist for given bssId");
=======
        limLog(pMac, LOGE, "Session Does not exist for given bssId\n");
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        status = eSIR_FAILURE;
        goto end;
    }
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_DELTS_REQ_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT


    if (eSIR_SUCCESS != limValidateDeltsReq(pMac, pDeltsReq, peerMacAddr,psessionEntry))
    {
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("limValidateDeltsReq failed"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("limValidateDeltsReq failed\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        status = eSIR_FAILURE;
        limSendSmeDeltsRsp(pMac, pDeltsReq, eSIR_FAILURE,psessionEntry,smesessionId,smetransactionId);
        return;
    }

<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("Sent DELTS request to station with assocId = %d MacAddr = %x:%x:%x:%x:%x:%x"),
=======
    PELOG1(limLog(pMac, LOG1, FL("Sent DELTS request to station with assocId = %d MacAddr = %x:%x:%x:%x:%x:%x\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
              pDeltsReq->aid, peerMacAddr[0], peerMacAddr[1], peerMacAddr[2],
              peerMacAddr[3], peerMacAddr[4], peerMacAddr[5]);)

    limSendDeltsReqActionFrame(pMac, peerMacAddr, pDeltsReq->req.wmeTspecPresent, &pDeltsReq->req.tsinfo, &pDeltsReq->req.tspec,
              psessionEntry);

    pTsinfo = pDeltsReq->req.wmeTspecPresent ? &pDeltsReq->req.tspec.tsinfo : &pDeltsReq->req.tsinfo;

    /* We've successfully send DELTS frame to AP. Update the 
     * dynamic UAPSD mask. The AC for this TSPEC to be deleted
     * is no longer trigger enabled or delivery enabled
     */
    limSetTspecUapsdMask(pMac, pTsinfo, CLEAR_UAPSD_MASK);

    /* We're deleting the TSPEC, so this particular AC is no longer
     * admitted.  PE needs to downgrade the EDCA
     * parameters(for the AC for which TS is being deleted) to the
     * next best AC for which ACM is not enabled, and send the
     * updated values to HAL. 
     */ 
    ac = upToAc(pTsinfo->traffic.userPrio);

    if(pTsinfo->traffic.direction == SIR_MAC_DIRECTION_UPLINK)
    {
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_UPLINK] &= ~(1 << ac);
    }
    else if(pTsinfo->traffic.direction == SIR_MAC_DIRECTION_DNLINK)
    {
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_DNLINK] &= ~(1 << ac);
    }
    else if(pTsinfo->traffic.direction == SIR_MAC_DIRECTION_BIDIR)
    {
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_UPLINK] &= ~(1 << ac);
      pMac->lim.gAcAdmitMask[SIR_MAC_DIRECTION_DNLINK] &= ~(1 << ac);
    }

    limSetActiveEdcaParams(pMac, psessionEntry->gLimEdcaParams, psessionEntry);

    pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
    if (pStaDs != NULL)
    {
        if (pStaDs->aniPeer == eANI_BOOLEAN_TRUE) 
            limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_TRUE);
        else
            limSendEdcaParams(pMac, psessionEntry->gLimEdcaParamsActive, pStaDs->bssId, eANI_BOOLEAN_FALSE);
        status = eSIR_SUCCESS;
    }
    else
    {
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Self entry missing in Hash Table "));
=======
        limLog(pMac, LOGE, FL("Self entry missing in Hash Table \n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
     status = eSIR_FAILURE;
    }     
#ifdef FEATURE_WLAN_CCX
    limDeactivateAndChangeTimer(pMac,eLIM_TSM_TIMER);
#endif

    // send an sme response back
    end:
         limSendSmeDeltsRsp(pMac, pDeltsReq, eSIR_SUCCESS,psessionEntry,smesessionId,smetransactionId);
}


void
limProcessSmeAddtsRspTimeout(tpAniSirGlobal pMac, tANI_U32 param)
{
    //fetch the sessionEntry based on the sessionId
    tpPESession psessionEntry;
    if((psessionEntry = peFindSessionBySessionId(pMac, pMac->lim.limTimers.gLimAddtsRspTimer.sessionId))== NULL) 
    {
<<<<<<< HEAD
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID"));
=======
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    if (  (psessionEntry->limSystemRole != eLIM_STA_ROLE) && (psessionEntry->limSystemRole != eLIM_BT_AMP_STA_ROLE)   )
    {
<<<<<<< HEAD
        limLog(pMac, LOGW, "AddtsRspTimeout in non-Sta role (%d)", psessionEntry->limSystemRole);
=======
        limLog(pMac, LOGW, "AddtsRspTimeout in non-Sta role (%d)\n", psessionEntry->limSystemRole);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        pMac->lim.gLimAddtsSent = false;
        return;
    }

    if (! pMac->lim.gLimAddtsSent)
    {
<<<<<<< HEAD
        PELOGW(limLog(pMac, LOGW, "AddtsRspTimeout but no AddtsSent");)
=======
        PELOGW(limLog(pMac, LOGW, "AddtsRspTimeout but no AddtsSent\n");)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    if (param != pMac->lim.gLimAddtsRspTimerCount)
    {
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("Invalid AddtsRsp Timer count %d (exp %d)"),
=======
        limLog(pMac, LOGE, FL("Invalid AddtsRsp Timer count %d (exp %d)\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
               param, pMac->lim.gLimAddtsRspTimerCount);
        return;
    }

    // this a real response timeout
    pMac->lim.gLimAddtsSent = false;
    pMac->lim.gLimAddtsRspTimerCount++;

    limSendSmeAddtsRsp(pMac, true, eSIR_SME_ADDTS_RSP_TIMEOUT, psessionEntry, pMac->lim.gLimAddtsReq.req.tspec,
            psessionEntry->smeSessionId, psessionEntry->transactionId);
}


/**
 * __limProcessSmeStatsRequest()
 *
 *FUNCTION:
 * 
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */
static void
__limProcessSmeStatsRequest(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpAniGetStatsReq    pStatsReq;
    tSirMsgQ msgQ;
    tpPESession psessionEntry;
    tANI_U8     sessionId;

    
    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
=======
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
           return;
    }
    
    pStatsReq = (tpAniGetStatsReq) pMsgBuf;
    
    if((psessionEntry = peFindSessionByBssid(pMac,pStatsReq->bssId,&sessionId))== NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("session does not exist for given bssId"));
        palFreeMemory( pMac, pMsgBuf );
        pMsgBuf = NULL;
=======
        limLog(pMac, LOGE, FL("session does not exist for given bssId\n"));
        palFreeMemory( pMac, pMsgBuf );
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

       
    
    switch(pStatsReq->msgType)
    {
        //Add Lim stats here. and send reqsponse.

        //HAL maintained Stats.
        case eWNI_SME_STA_STAT_REQ:
            msgQ.type = WDA_STA_STAT_REQ;
            break;
        case eWNI_SME_AGGR_STAT_REQ:
            msgQ.type = WDA_AGGR_STAT_REQ;
            break;
        case eWNI_SME_GLOBAL_STAT_REQ:
            msgQ.type = WDA_GLOBAL_STAT_REQ;
            break;
        case eWNI_SME_STAT_SUMM_REQ:
            msgQ.type = WDA_STAT_SUMM_REQ;
            break;   
        default: //Unknown request.
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, "Unknown Statistics request");)
            palFreeMemory( pMac, pMsgBuf );
            pMsgBuf = NULL;
=======
            PELOGE(limLog(pMac, LOGE, "Unknown Statistics request\n");)
            palFreeMemory( pMac, pMsgBuf );
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            return;
    }

    if ( !pMac->lim.gLimRspReqd ) 
    {
        palFreeMemory( pMac, pMsgBuf );
        return;
    }
    else
    {
        pMac->lim.gLimRspReqd = FALSE;
    }

    msgQ.reserved = 0;
    msgQ.bodyptr = pMsgBuf;
    msgQ.bodyval = 0;
<<<<<<< HEAD
    if(NULL == psessionEntry)
    {
        MTRACE(macTraceMsgTx(pMac, NO_SESSION, msgQ.type));
    }
    else
    {
        MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, msgQ.type));
    }
    if( eSIR_SUCCESS != (wdaPostCtrlMsg( pMac, &msgQ ))){
        limLog(pMac, LOGP, "Unable to forward request");
        palFreeMemory( pMac, pMsgBuf );
        pMsgBuf = NULL;
=======
    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, msgQ.type));

    if( eSIR_SUCCESS != (wdaPostCtrlMsg( pMac, &msgQ ))){
        limLog(pMac, LOGP, "Unable to forward request\n");
        palFreeMemory( pMac, pMsgBuf );
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    return;
}


/**
 * __limProcessSmeGetStatisticsRequest()
 *
 *FUNCTION:
 * 
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */
static void
__limProcessSmeGetStatisticsRequest(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpAniGetPEStatsReq    pPEStatsReq;
    tSirMsgQ msgQ;

    pPEStatsReq = (tpAniGetPEStatsReq) pMsgBuf;
    
    //pPEStatsReq->msgType should be eWNI_SME_GET_STATISTICS_REQ

    msgQ.type = WDA_GET_STATISTICS_REQ;    

    if ( !pMac->lim.gLimRspReqd ) 
    {
        palFreeMemory( pMac, pMsgBuf );
        return;
    }
    else
    {
        pMac->lim.gLimRspReqd = FALSE;
    }

    msgQ.reserved = 0;
    msgQ.bodyptr = pMsgBuf;
    msgQ.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, msgQ.type));

    if( eSIR_SUCCESS != (wdaPostCtrlMsg( pMac, &msgQ ))){
        palFreeMemory( pMac, pMsgBuf );
<<<<<<< HEAD
        pMsgBuf = NULL;
        limLog(pMac, LOGP, "Unable to forward request");
        return;
    }

    return;
}


#if defined WLAN_FEATURE_VOWIFI_11R || defined FEATURE_WLAN_CCX || defined(FEATURE_WLAN_LFR)
/**
 * __limProcessSmeGetRoamRssiRequest()
 *
 *FUNCTION:
 *
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */
static void
__limProcessSmeGetRoamRssiRequest(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpAniGetRssiReq    pPEGetRoamRssiReq = NULL;
    tSirMsgQ msgQ;

    pPEGetRoamRssiReq = (tpAniGetRssiReq) pMsgBuf;
    msgQ.type = WDA_GET_ROAM_RSSI_REQ;

    if ( !pMac->lim.gLimRspReqd )
    {
        palFreeMemory( pMac, pMsgBuf );
        return;
    }
    else
    {
        pMac->lim.gLimRspReqd = FALSE;
    }

    msgQ.reserved = 0;
    msgQ.bodyptr = pMsgBuf;
    msgQ.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, msgQ.type));

    if( eSIR_SUCCESS != (wdaPostCtrlMsg( pMac, &msgQ ))){
        palFreeMemory( pMac, pMsgBuf );
        pMsgBuf = NULL;
        limLog(pMac, LOGP, "Unable to forward request");
=======
        limLog(pMac, LOGP, "Unable to forward request\n");
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    return;
}
<<<<<<< HEAD
#endif


=======


#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
static void
__limProcessSmeUpdateAPWPSIEs(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpSirUpdateAPWPSIEsReq  pUpdateAPWPSIEsReq;
    tpPESession             psessionEntry;
    tANI_U8                 sessionId;  //PE sessionID

    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
           FL("received UPDATE_APWPSIEs_REQ message")););
    
    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
        return;
    }

    if( palAllocateMemory( pMac->hHdd, (void **)&pUpdateAPWPSIEsReq, sizeof(tSirUpdateAPWPSIEsReq)))
    {
        limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pUpdateAPWPSIEsReq"));
        return;
    }

    if ((limUpdateAPWPSIEsReqSerDes(pMac, pUpdateAPWPSIEsReq, (tANI_U8 *) pMsgBuf) == eSIR_FAILURE))
    {
        limLog(pMac, LOGW, FL("received invalid SME_SETCONTEXT_REQ message"));
        goto end;
    }

    if((psessionEntry = peFindSessionByBssid(pMac, pUpdateAPWPSIEsReq->bssId, &sessionId)) == NULL)
    {
        limLog(pMac, LOGW, FL("Session does not exist for given BSSID"));
=======
           FL("received UPDATE_APWPSIEs_REQ message\n")););
    
    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
        return;
    }
    
    if( palAllocateMemory( pMac->hHdd, (void **)&pUpdateAPWPSIEsReq, sizeof(tSirUpdateAPWPSIEsReq)))
    {
        limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pUpdateAPWPSIEsReq\n"));
        return;
    }

    if ((limUpdateAPWPSIEsReqSerDes(pMac, pUpdateAPWPSIEsReq, (tANI_U8 *) pMsgBuf) == eSIR_FAILURE)) 
    {
        limLog(pMac, LOGW, FL("received invalid SME_SETCONTEXT_REQ message\n")); 
        goto end;
    }
    
    if((psessionEntry = peFindSessionByBssid(pMac, pUpdateAPWPSIEsReq->bssId, &sessionId)) == NULL)
    {
        limLog(pMac, LOGW, FL("Session does not exist for given BSSID\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }

    palCopyMemory(pMac->hHdd, &psessionEntry->APWPSIEs, &pUpdateAPWPSIEsReq->APWPSIEs, sizeof(tSirAPWPSIEs));
<<<<<<< HEAD

    schSetFixedBeaconFields(pMac, psessionEntry);
    limSendBeaconInd(pMac, psessionEntry);
=======
    
    schSetFixedBeaconFields(pMac, psessionEntry);
    limSendBeaconInd(pMac, psessionEntry); 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

end:
    palFreeMemory( pMac->hHdd, pUpdateAPWPSIEsReq);
    return;
} /*** end __limProcessSmeUpdateAPWPSIEs(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf) ***/

static void
__limProcessSmeHideSSID(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpSirUpdateParams       pUpdateParams;
    tpPESession             psessionEntry;

    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
           FL("received HIDE_SSID message")););
    
    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
=======
           FL("received HIDE_SSID message\n")););
    
    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    pUpdateParams = (tpSirUpdateParams)pMsgBuf;
    
    if((psessionEntry = peFindSessionBySessionId(pMac, pUpdateParams->sessionId)) == NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGW, "Session does not exist for given sessionId %d",
=======
        limLog(pMac, LOGW, "Session does not exist for given sessionId %d\n",
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                      pUpdateParams->sessionId);
        return;
    }

    /* Update the session entry */
    psessionEntry->ssidHidden = pUpdateParams->ssidHidden;
   
    /* Update beacon */
    schSetFixedBeaconFields(pMac, psessionEntry);
    limSendBeaconInd(pMac, psessionEntry); 

    return;
} /*** end __limProcessSmeHideSSID(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf) ***/

static void
__limProcessSmeSetWPARSNIEs(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpSirUpdateAPWPARSNIEsReq  pUpdateAPWPARSNIEsReq;
    tpPESession             psessionEntry;
    tANI_U8                 sessionId;  //PE sessionID

    if(pMsgBuf == NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
=======
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }
    
    if( palAllocateMemory( pMac->hHdd, (void **)&pUpdateAPWPARSNIEsReq, sizeof(tSirUpdateAPWPSIEsReq)))
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pUpdateAPWPARSNIEsReq"));
=======
        limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pUpdateAPWPARSNIEsReq\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        return;
    }

    if ((limUpdateAPWPARSNIEsReqSerDes(pMac, pUpdateAPWPARSNIEsReq, (tANI_U8 *) pMsgBuf) == eSIR_FAILURE)) 
    {
<<<<<<< HEAD
        limLog(pMac, LOGW, FL("received invalid SME_SETCONTEXT_REQ message"));
=======
        limLog(pMac, LOGW, FL("received invalid SME_SETCONTEXT_REQ message\n")); 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }
    
    if((psessionEntry = peFindSessionByBssid(pMac, pUpdateAPWPARSNIEsReq->bssId, &sessionId)) == NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGW, FL("Session does not exist for given BSSID"));
=======
        limLog(pMac, LOGW, FL("Session does not exist for given BSSID\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        goto end;
    }

    palCopyMemory(pMac->hHdd, &psessionEntry->pLimStartBssReq->rsnIE, &pUpdateAPWPARSNIEsReq->APWPARSNIEs, sizeof(tSirRSNie));
    
    limSetRSNieWPAiefromSmeStartBSSReqMessage(pMac, &psessionEntry->pLimStartBssReq->rsnIE, psessionEntry);
    
    psessionEntry->pLimStartBssReq->privacy = 1;
    psessionEntry->privacy = 1;
    
    schSetFixedBeaconFields(pMac, psessionEntry);
    limSendBeaconInd(pMac, psessionEntry); 

end:
    palFreeMemory( pMac->hHdd, pUpdateAPWPARSNIEsReq);
    return;
} /*** end __limProcessSmeSetWPARSNIEs(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf) ***/

<<<<<<< HEAD
/*
Update the beacon Interval dynamically if beaconInterval is different in MCC 
*/
static void
__limProcessSmeChangeBI(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpSirChangeBIParams     pChangeBIParams;
    tpPESession             psessionEntry;
    tANI_U8  sessionId = 0;
    tUpdateBeaconParams beaconParams;

    PELOG1(limLog(pMac, LOG1,
           FL("received Update Beacon Interval message")););
    
    if(pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
        return;
    }

    vos_mem_zero(&beaconParams, sizeof(tUpdateBeaconParams));
    pChangeBIParams = (tpSirChangeBIParams)pMsgBuf;

    if((psessionEntry = peFindSessionByBssid(pMac, pChangeBIParams->bssId, &sessionId)) == NULL)
    {
        limLog(pMac, LOGE, FL("Session does not exist for given BSSID"));
        return;
    }

    /*Update sessionEntry Beacon Interval*/
    if(psessionEntry->beaconParams.beaconInterval != 
                                        pChangeBIParams->beaconInterval )
    {
       psessionEntry->beaconParams.beaconInterval = pChangeBIParams->beaconInterval;
    }

    /*Update sch beaconInterval*/
    if(pMac->sch.schObject.gSchBeaconInterval != 
                                        pChangeBIParams->beaconInterval )
    {
        pMac->sch.schObject.gSchBeaconInterval = pChangeBIParams->beaconInterval;

        PELOG1(limLog(pMac, LOG1,
               FL("LIM send update BeaconInterval Indication : %d"),pChangeBIParams->beaconInterval););

        /* Update beacon */
        schSetFixedBeaconFields(pMac, psessionEntry);

        beaconParams.bssIdx = psessionEntry->bssIdx;
        //Set change in beacon Interval
        beaconParams.beaconInterval = pChangeBIParams->beaconInterval;
        beaconParams.paramChangeBitmap = PARAM_BCN_INTERVAL_CHANGED;
        limSendBeaconParams(pMac, &beaconParams, psessionEntry);
    }

    return;
} /*** end __limProcessSmeChangeBI(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf) ***/

=======
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


/** -------------------------------------------------------------
\fn limProcessSmeDelBaPeerInd
\brief handles indication message from HDD to send delete BA request
\param   tpAniSirGlobal pMac
\param   tANI_U32 pMsgBuf
\return None
-------------------------------------------------------------*/
void
limProcessSmeDelBaPeerInd(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tANI_U16            assocId =0;
    tpSmeDelBAPeerInd   pSmeDelBAPeerInd = (tpSmeDelBAPeerInd)pMsgBuf;
    tpDphHashNode       pSta;
    tpPESession         psessionEntry;
    tANI_U8             sessionId;
    


    if(NULL == pSmeDelBAPeerInd)
        return;

    if ((psessionEntry = peFindSessionByBssid(pMac,pSmeDelBAPeerInd->bssId,&sessionId))==NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGE,FL("session does not exist for given bssId"));
        return;
    }
    limLog(pMac, LOGW, FL("called with staId = %d, tid = %d, baDirection = %d"),
=======
        limLog(pMac, LOGE,FL("session does not exist for given bssId\n"));
        return;
    }
    limLog(pMac, LOGW, FL("called with staId = %d, tid = %d, baDirection = %d\n"), 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
              pSmeDelBAPeerInd->staIdx, pSmeDelBAPeerInd->baTID, pSmeDelBAPeerInd->baDirection);

    pSta = dphLookupAssocId(pMac, pSmeDelBAPeerInd->staIdx, &assocId, &psessionEntry->dph.dphHashTable);    
    if( eSIR_SUCCESS != limPostMlmDelBAReq( pMac,
          pSta,
          pSmeDelBAPeerInd->baDirection,
          pSmeDelBAPeerInd->baTID,
          eSIR_MAC_UNSPEC_FAILURE_REASON,psessionEntry))
    {
      limLog( pMac, LOGW,
          FL( "Failed to post LIM_MLM_DELBA_REQ to " ));
      if (pSta)
          limPrintMacAddr(pMac, pSta->staAddr, LOGW); 
    }
}

// --------------------------------------------------------------------
/**
 * __limProcessReportMessage
 *
 * FUNCTION:  Processes the next received Radio Resource Management message
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param None
 * @return None
 */

void __limProcessReportMessage(tpAniSirGlobal pMac, tpSirMsgQ pMsg)
{
#ifdef WLAN_FEATURE_VOWIFI
   switch (pMsg->type)
   {
      case eWNI_SME_NEIGHBOR_REPORT_REQ_IND:
         rrmProcessNeighborReportReq( pMac, pMsg->bodyptr );
         break;
      case eWNI_SME_BEACON_REPORT_RESP_XMIT_IND:
        {
#if defined FEATURE_WLAN_CCX
         tpSirBeaconReportXmitInd pBcnReport=NULL;
         tpPESession psessionEntry=NULL;
         tANI_U8 sessionId;

         if(pMsg->bodyptr == NULL)
         {
<<<<<<< HEAD
            limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
=======
            limLog(pMac, LOGE,FL("Buffer is Pointing to NULL\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            return;
         }
         pBcnReport = (tpSirBeaconReportXmitInd )pMsg->bodyptr;
         if((psessionEntry = peFindSessionByBssid(pMac, pBcnReport->bssId,&sessionId))== NULL)
         {
<<<<<<< HEAD
            limLog(pMac, LOGE, "Session Does not exist for given bssId");
=======
            limLog(pMac, LOGE, "Session Does not exist for given bssId\n");
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            return;
         }
         if (psessionEntry->isCCXconnection)
             ccxProcessBeaconReportXmit( pMac, pMsg->bodyptr);
         else
#endif
             rrmProcessBeaconReportXmit( pMac, pMsg->bodyptr );
        }
        break;
   }
#endif
}

#if defined(FEATURE_WLAN_CCX) || defined(WLAN_FEATURE_VOWIFI)
// --------------------------------------------------------------------
/**
 * limSendSetMaxTxPowerReq
 *
 * FUNCTION:  Send SIR_HAL_SET_MAX_TX_POWER_REQ message to change the max tx power.
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param txPower txPower to be set.
 * @param pSessionEntry session entry.
 * @return None
 */
tSirRetStatus
limSendSetMaxTxPowerReq ( tpAniSirGlobal pMac, tPowerdBm txPower, tpPESession pSessionEntry )
{
   tpMaxTxPowerParams pMaxTxParams = NULL;
   tSirRetStatus  retCode = eSIR_SUCCESS;
   tSirMsgQ       msgQ;

   if( pSessionEntry == NULL )
   {
<<<<<<< HEAD
      PELOGE(limLog(pMac, LOGE, "%s:%d: Inavalid parameters", __func__, __LINE__ );)
=======
      PELOGE(limLog(pMac, LOGE, "%s:%d: Inavalid parameters\n", __func__, __LINE__ );)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
      return eSIR_FAILURE;
   }
   if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd,
            (void **) &pMaxTxParams, sizeof(tMaxTxPowerParams) ) ) 
   {
<<<<<<< HEAD
      limLog( pMac, LOGP, "%s:%d:Unable to allocate memory for pMaxTxParams ", __func__, __LINE__);
=======
      limLog( pMac, LOGP, "%s:%d:Unable to allocate memory for pMaxTxParams \n", __func__, __LINE__);
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
      return eSIR_MEM_ALLOC_FAILED;

   }
#if defined(WLAN_VOWIFI_DEBUG) || defined(FEATURE_WLAN_CCX)
<<<<<<< HEAD
   PELOG1(limLog( pMac, LOG1, "%s:%d: Allocated memory for pMaxTxParams...will be freed in other module", __func__, __LINE__ );)
=======
   PELOG1(limLog( pMac, LOG1, "%s:%d: Allocated memory for pMaxTxParams...will be freed in other module\n", __func__, __LINE__ );)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#endif
   pMaxTxParams->power = txPower;
   palCopyMemory( pMac->hHdd, pMaxTxParams->bssId, pSessionEntry->bssId, sizeof(tSirMacAddr) );
   palCopyMemory( pMac->hHdd, pMaxTxParams->selfStaMacAddr, pSessionEntry->selfMacAddr, sizeof(tSirMacAddr) );

<<<<<<< HEAD
   msgQ.type = WDA_SET_MAX_TX_POWER_REQ;
   msgQ.bodyptr = pMaxTxParams;
   msgQ.bodyval = 0;
   PELOG1(limLog(pMac, LOG1, FL("Posting WDA_SET_MAX_TX_POWER_REQ to WDA"));)
   MTRACE(macTraceMsgTx(pMac, pSessionEntry->peSessionId, msgQ.type));
   retCode = wdaPostCtrlMsg(pMac, &msgQ);
   if (eSIR_SUCCESS != retCode)
   {
      PELOGE(limLog(pMac, LOGE, FL("wdaPostCtrlMsg() failed"));)
      palFreeMemory(pMac->hHdd, pMaxTxParams);
   }
   return retCode;
=======
    msgQ.type = WDA_SET_MAX_TX_POWER_REQ;
    msgQ.bodyptr = pMaxTxParams;
    msgQ.bodyval = 0;
    PELOGW(limLog(pMac, LOG1, FL("Posting WDA_SET_MAX_TX_POWER_REQ to WDA\n"));)
    if(eSIR_SUCCESS != (retCode = wdaPostCtrlMsg(pMac, &msgQ)))
    {
       PELOGW(limLog(pMac, LOGW, FL("wdaPostCtrlMsg() failed\n"));)
       if (NULL != pMaxTxParams)
       {
          palFreeMemory(pMac->hHdd, (tANI_U8*)pMaxTxParams);
       }
       return retCode;
    }
    return retCode;
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
}
#endif

/**
 * __limProcessSmeAddStaSelfReq()
 *
 *FUNCTION:
 * This function is called to process SME_ADD_STA_SELF_REQ message
 * from SME. It sends a SIR_HAL_ADD_STA_SELF_REQ message to HAL.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limProcessSmeAddStaSelfReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
   tSirMsgQ msg;
   tpAddStaSelfParams pAddStaSelfParams;
   tpSirSmeAddStaSelfReq pSmeReq = (tpSirSmeAddStaSelfReq) pMsgBuf;

   if ( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void**) &pAddStaSelfParams,
            sizeof( tAddStaSelfParams) ) )
   {
      limLog( pMac, LOGP, FL("Unable to allocate memory for tAddSelfStaParams") );
      return;
   }

   palCopyMemory( pMac->hHdd, pAddStaSelfParams->selfMacAddr, pSmeReq->selfMacAddr, sizeof(tSirMacAddr) ); 

   msg.type = SIR_HAL_ADD_STA_SELF_REQ;
   msg.reserved = 0;
   msg.bodyptr =  pAddStaSelfParams;
   msg.bodyval = 0;

<<<<<<< HEAD
   PELOGW(limLog(pMac, LOG1, FL("sending SIR_HAL_ADD_STA_SELF_REQ msg to HAL"));)
=======
   PELOGW(limLog(pMac, LOG1, FL("sending SIR_HAL_ADD_STA_SELF_REQ msg to HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
      MTRACE(macTraceMsgTx(pMac, NO_SESSION, msg.type));

   if(eSIR_SUCCESS != wdaPostCtrlMsg(pMac, &msg))
   {
<<<<<<< HEAD
      limLog(pMac, LOGP, FL("wdaPostCtrlMsg failed"));
=======
      limLog(pMac, LOGP, FL("wdaPostCtrlMsg failed\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
   }
   return;
} /*** end __limProcessAddStaSelfReq() ***/


/**
 * __limProcessSmeDelStaSelfReq()
 *
 *FUNCTION:
 * This function is called to process SME_DEL_STA_SELF_REQ message
 * from SME. It sends a SIR_HAL_DEL_STA_SELF_REQ message to HAL.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */

static void
__limProcessSmeDelStaSelfReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
   tSirMsgQ msg;
   tpDelStaSelfParams pDelStaSelfParams;
   tpSirSmeDelStaSelfReq pSmeReq = (tpSirSmeDelStaSelfReq) pMsgBuf;

   if ( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void**) &pDelStaSelfParams,
            sizeof( tDelStaSelfParams) ) )
   {
      limLog( pMac, LOGP, FL("Unable to allocate memory for tDelStaSelfParams") );
      return;
   }

   palCopyMemory( pMac->hHdd, pDelStaSelfParams->selfMacAddr, pSmeReq->selfMacAddr, sizeof(tSirMacAddr) ); 

   msg.type = SIR_HAL_DEL_STA_SELF_REQ;
   msg.reserved = 0;
   msg.bodyptr =  pDelStaSelfParams;
   msg.bodyval = 0;

<<<<<<< HEAD
   PELOGW(limLog(pMac, LOG1, FL("sending SIR_HAL_ADD_STA_SELF_REQ msg to HAL"));)
=======
   PELOGW(limLog(pMac, LOG1, FL("sending SIR_HAL_ADD_STA_SELF_REQ msg to HAL\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
      MTRACE(macTraceMsgTx(pMac, NO_SESSION, msg.type));

   if(eSIR_SUCCESS != wdaPostCtrlMsg(pMac, &msg))
   {
<<<<<<< HEAD
      limLog(pMac, LOGP, FL("wdaPostCtrlMsg failed"));
=======
      limLog(pMac, LOGP, FL("wdaPostCtrlMsg failed\n"));
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
   }
   return;
} /*** end __limProcessSmeDelStaSelfReq() ***/


<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_P2P
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
/**
 * __limProcessSmeRegisterMgmtFrameReq()
 *
 *FUNCTION:
 * This function is called to process eWNI_SME_REGISTER_MGMT_FRAME_REQ message
 * from SME. It Register this information within PE.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return None
 */
static void
__limProcessSmeRegisterMgmtFrameReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    VOS_STATUS vosStatus;
    tpSirRegisterMgmtFrame pSmeReq = (tpSirRegisterMgmtFrame)pMsgBuf;
    tpLimMgmtFrameRegistration pLimMgmtRegistration = NULL, pNext = NULL;
    tANI_BOOLEAN match = VOS_FALSE;
    PELOG1(limLog(pMac, LOG1, 
<<<<<<< HEAD
           FL("registerFrame %d, frameType %d, matchLen %d"),
=======
           FL("registerFrame %d, frameType %d, matchLen %d\n"), 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            pSmeReq->registerFrame, pSmeReq->frameType, pSmeReq->matchLen);)

    /* First check whether entry exists already*/

    vos_list_peek_front(&pMac->lim.gLimMgmtFrameRegistratinQueue,
            (vos_list_node_t**)&pLimMgmtRegistration);

    while(pLimMgmtRegistration != NULL)
    {
        if (pLimMgmtRegistration->frameType == pSmeReq->frameType)
        {
            if(pSmeReq->matchLen)
            {
                if (pLimMgmtRegistration->matchLen == pSmeReq->matchLen)
                {
                    if (palEqualMemory(pMac, pLimMgmtRegistration->matchData, 
                                pSmeReq->matchData, pLimMgmtRegistration->matchLen))
                    {
<<<<<<< HEAD
                        /* found match! */
=======
                        /* found match! */   
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                        match = VOS_TRUE;
                        break;
                    }
                }
            }
            else
            {
<<<<<<< HEAD
                /* found match! */
=======
                /* found match! */   
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
                match = VOS_TRUE;
                break;
            }
        }
        vosStatus = vos_list_peek_next (
                &pMac->lim.gLimMgmtFrameRegistratinQueue,
                (vos_list_node_t*) pLimMgmtRegistration,
                (vos_list_node_t**) &pNext );

        pLimMgmtRegistration = pNext;
        pNext = NULL; 

    }

    if (match)
    {
        vos_list_remove_node(&pMac->lim.gLimMgmtFrameRegistratinQueue,
                (vos_list_node_t*)pLimMgmtRegistration);
        palFreeMemory(pMac,pLimMgmtRegistration);
    }

    if(pSmeReq->registerFrame)
    {
        palAllocateMemory(pMac, (void**)&pLimMgmtRegistration,
                        sizeof(tLimMgmtFrameRegistration) + pSmeReq->matchLen);
        if(pLimMgmtRegistration != NULL)
        {
<<<<<<< HEAD
            palZeroMemory(pMac, (void*)pLimMgmtRegistration,
=======
            palZeroMemory(pMac, (void*)pLimMgmtRegistration, 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
              sizeof(tLimMgmtFrameRegistration) + pSmeReq->matchLen );
            pLimMgmtRegistration->frameType = pSmeReq->frameType;
            pLimMgmtRegistration->matchLen  = pSmeReq->matchLen;
            pLimMgmtRegistration->sessionId = pSmeReq->sessionId;
            if(pSmeReq->matchLen)
            {
<<<<<<< HEAD
                palCopyMemory(pMac,pLimMgmtRegistration->matchData,
                              pSmeReq->matchData, pSmeReq->matchLen);
            }
=======
                palCopyMemory(pMac,pLimMgmtRegistration->matchData, 
                              pSmeReq->matchData, pSmeReq->matchLen);
            }
     
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            vos_list_insert_front(&pMac->lim.gLimMgmtFrameRegistratinQueue,
                              &pLimMgmtRegistration->node);
        }
    }

    return;
} /*** end __limProcessSmeRegisterMgmtFrameReq() ***/
<<<<<<< HEAD

static tANI_BOOLEAN
__limInsertSingleShotNOAForScan(tpAniSirGlobal pMac, tANI_U32 noaDuration)
{
    tpP2pPsParams pMsgNoA;
    tSirMsgQ msg;

    if( eHAL_STATUS_SUCCESS != palAllocateMemory(
                  pMac->hHdd, (void **) &pMsgNoA, sizeof( tP2pPsConfig )))
    {
        limLog( pMac, LOGP,
                     FL( "Unable to allocate memory during NoA Update" ));
        goto error;
    }

    palZeroMemory( pMac->hHdd, (tANI_U8 *)pMsgNoA, sizeof(tP2pPsConfig));
    /* Below params used for opp PS/periodic NOA and are don't care in this case - so initialized to 0 */
    pMsgNoA->opp_ps = 0;
    pMsgNoA->ctWindow = 0;
    pMsgNoA->duration = 0;
    pMsgNoA->interval = 0;
    pMsgNoA->count = 0;

    /* Below params used for Single Shot NOA - so assign proper values */
    pMsgNoA->psSelection = P2P_SINGLE_NOA;
    pMsgNoA->single_noa_duration = noaDuration;

    /* Start Insert NOA timer
     * If insert NOA req fails or NOA rsp fails or start NOA indication doesn't come from FW due to GO session deletion
     * or any other failure or reason, we still need to process the deferred SME req. The insert NOA
     * timer of 500 ms will ensure the stored SME req always gets processed
     */
    if (tx_timer_activate(&pMac->lim.limTimers.gLimP2pSingleShotNoaInsertTimer)
                                      == TX_TIMER_ERROR)
    {
        /// Could not activate Insert NOA timer.
        // Log error
        limLog(pMac, LOGP, FL("could not activate Insert Single Shot NOA during scan timer"));

        // send the scan response back with status failure and do not even call insert NOA
        limSendSmeScanRsp(pMac, sizeof(tSirSmeScanRsp), eSIR_SME_SCAN_FAILED, pMac->lim.gSmeSessionId, pMac->lim.gTransactionId);
        palFreeMemory( pMac->hHdd, pMsgNoA);
        goto error;
    }

    MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, NO_SESSION, eLIM_INSERT_SINGLESHOT_NOA_TIMER));

    msg.type = WDA_SET_P2P_GO_NOA_REQ;
    msg.reserved = 0;
    msg.bodyptr = pMsgNoA;
    msg.bodyval = 0;

    if(eSIR_SUCCESS != wdaPostCtrlMsg(pMac, &msg))
    {
        /* In this failure case, timer is already started, so its expiration will take care of sending scan response */
        limLog(pMac, LOGP, FL("wdaPost Msg failed"));
        /* Deactivate the NOA timer in failure case */
        limDeactivateAndChangeTimer(pMac, eLIM_INSERT_SINGLESHOT_NOA_TIMER);
        goto error;
    }
    return FALSE;

error:
    /* In any of the failure cases, just go ahead with the processing of registered deferred SME request without
     * worrying about the NOA
     */
    limProcessRegdDefdSmeReqAfterNOAStart(pMac);
    // msg buffer is consumed and freed in above function so return FALSE
    return FALSE;

}

static void __limRegisterDeferredSmeReqForNOAStart(tpAniSirGlobal pMac, tANI_U16 msgType, tANI_U32 *pMsgBuf)
{
    limLog(pMac, LOG1, FL("Reg msgType %d"), msgType) ;
    pMac->lim.gDeferMsgTypeForNOA = msgType;
    pMac->lim.gpDefdSmeMsgForNOA = pMsgBuf;
}

static void __limDeregisterDeferredSmeReqAfterNOAStart(tpAniSirGlobal pMac)
{
    limLog(pMac, LOG1, FL("Dereg msgType %d"), pMac->lim.gDeferMsgTypeForNOA) ;
    pMac->lim.gDeferMsgTypeForNOA = 0;
    if (pMac->lim.gpDefdSmeMsgForNOA != NULL)
    {
        /* __limProcessSmeScanReq consumed the buffer. We can free it. */
        palFreeMemory( pMac->hHdd, (tANI_U32 *) pMac->lim.gpDefdSmeMsgForNOA);
        pMac->lim.gpDefdSmeMsgForNOA = NULL;
    }
}

static
tANI_U32 limCalculateNOADuration(tpAniSirGlobal pMac, tANI_U16 msgType, tANI_U32 *pMsgBuf)
{
    tANI_U32 noaDuration = 0;

    switch (msgType)
    {
        case eWNI_SME_SCAN_REQ:
        {
            tANI_U32 val;
            tANI_U8 i;
            tpSirSmeScanReq pScanReq = (tpSirSmeScanReq) pMsgBuf;
            if (wlan_cfgGetInt(pMac, WNI_CFG_PASSIVE_MAXIMUM_CHANNEL_TIME, &val) != eSIR_SUCCESS)
            {
                /*
                 * Could not get max channel value
                 * from CFG. Log error.
                 */
                limLog(pMac, LOGP, FL("could not retrieve passive max channel value"));

                /* use a default value of 110ms */
                val = DEFAULT_PASSIVE_MAX_CHANNEL_TIME;
            }

            for (i = 0; i < pScanReq->channelList.numChannels; i++) {
                tANI_U8 channelNum = pScanReq->channelList.channelNumber[i];

                if (limActiveScanAllowed(pMac, channelNum)) {
                    /* Use min + max channel time to calculate the total duration of scan */
                    noaDuration += pScanReq->minChannelTime + pScanReq->maxChannelTime;
                } else {
                    /* using the value from WNI_CFG_PASSIVE_MINIMUM_CHANNEL_TIME as is done in
                     * void limContinuePostChannelScan(tpAniSirGlobal pMac)
                     */
                    noaDuration += val;
                }
            }

            /* Adding an overhead of 20ms to account for the scan messaging delays */
            noaDuration += SCAN_MESSAGING_OVERHEAD;
            noaDuration *= CONV_MS_TO_US;

            break;
        }

        case eWNI_SME_OEM_DATA_REQ:
            noaDuration = OEM_DATA_NOA_DURATION*CONV_MS_TO_US; // use 60 msec as default
            break;

        case eWNI_SME_REMAIN_ON_CHANNEL_REQ:
        {
            tSirRemainOnChnReq *pRemainOnChnReq = (tSirRemainOnChnReq *) pMsgBuf;
            noaDuration = (pRemainOnChnReq->duration)*CONV_MS_TO_US;
            break;
        }

        case eWNI_SME_JOIN_REQ:
            noaDuration = JOIN_NOA_DURATION*CONV_MS_TO_US;
            break;

        default:
            noaDuration = 0;
            break;

    }
    limLog(pMac, LOGW, FL("msgType %d noa %d"), msgType, noaDuration);
    return noaDuration;
}

void limProcessRegdDefdSmeReqAfterNOAStart(tpAniSirGlobal pMac)
{
    tANI_BOOLEAN bufConsumed = TRUE;

    limLog(pMac, LOG1, FL("Process defd sme req %d"), pMac->lim.gDeferMsgTypeForNOA);
    if ( (pMac->lim.gDeferMsgTypeForNOA != 0) &&
         (pMac->lim.gpDefdSmeMsgForNOA != NULL) )
    {
        switch (pMac->lim.gDeferMsgTypeForNOA)
        {
            case eWNI_SME_SCAN_REQ:
                __limProcessSmeScanReq(pMac, pMac->lim.gpDefdSmeMsgForNOA);
                break;
            case eWNI_SME_OEM_DATA_REQ:
                __limProcessSmeOemDataReq(pMac, pMac->lim.gpDefdSmeMsgForNOA);
                break;
            case eWNI_SME_REMAIN_ON_CHANNEL_REQ:
                bufConsumed = limProcessRemainOnChnlReq(pMac, pMac->lim.gpDefdSmeMsgForNOA);
                /* limProcessRemainOnChnlReq doesnt want us to free the buffer since
                 * it is freed in limRemainOnChnRsp. this change is to avoid "double free"
                 */
                if (FALSE == bufConsumed)
                {
                    pMac->lim.gpDefdSmeMsgForNOA = NULL;
                }
                break;
            case eWNI_SME_JOIN_REQ:
                __limProcessSmeJoinReq(pMac, pMac->lim.gpDefdSmeMsgForNOA);
                break;
            default:
                limLog(pMac, LOGE, FL("Unknown deferred msg type %d"), pMac->lim.gDeferMsgTypeForNOA);
                break;
        }
        __limDeregisterDeferredSmeReqAfterNOAStart(pMac);
    }
    else
    {
        limLog( pMac, LOGW, FL("start received from FW when no sme deferred msg pending. Do nothing."
            "It might happen sometime when NOA start ind and timeout happen at the same time"));
    }
}

#ifdef FEATURE_WLAN_TDLS_INTERNAL
/*
 * Process Discovery request recieved from SME and transmit to AP.
 */
static tSirRetStatus limProcessSmeDisStartReq(tpAniSirGlobal pMac, 
                                                           tANI_U32 *pMsgBuf)
{
    /* get all discovery request parameters */
    tSirTdlsDisReq *disReq = (tSirTdlsDisReq *) pMsgBuf ;
    tpPESession psessionEntry;
    tANI_U8      sessionId;

    VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,
                                  ("Discovery Req Recieved")) ;

    if((psessionEntry = peFindSessionByBssid(pMac, disReq->bssid, &sessionId)) 
                                                                        == NULL)
    {
         VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_ERROR, 
                    "PE Session does not exist for given sme sessionId %d",
                                                            disReq->sessionId);
         goto lim_tdls_dis_start_error;
    }
    
    /* check if we are in proper state to work as TDLS client */ 
    if (psessionEntry->limSystemRole != eLIM_STA_ROLE)
    {
        VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_ERROR, 
                         "dis req received in wrong system Role %d",
                                             psessionEntry->limSystemRole);
        goto lim_tdls_dis_start_error;
    }

    /*
     * if we are still good, go ahead and check if we are in proper state to
     * do TDLS discovery procedure.
     */
     if ((psessionEntry->limSmeState != eLIM_SME_ASSOCIATED_STATE) &&
                (psessionEntry->limSmeState != eLIM_SME_LINK_EST_STATE))
     {
     
         limLog(pMac, LOGE, "dis req received in invalid LIMsme \
                               state (%d)", psessionEntry->limSmeState);
         goto lim_tdls_dis_start_error;
     }
    
    /*
     * if we are still good, go ahead and transmit TDLS discovery request,
     * and save Dis Req info for future reference.
     */

#if 0 // TDLS_hklee: D13 no need to open Addr2 unknown data packet 
    /* 
     * send message to HAL to set RXP filters to receieve frame on 
     * direct link..
     */
     //limSetLinkState(pMac, eSIR_LINK_TDLS_DISCOVERY_STATE, 
     //                                    psessionEntry->bssId) ;
#endif

     /* save dis request message for matching dialog token */
     palCopyMemory( pMac->hHdd, (tANI_U8 *) &pMac->lim.gLimTdlsDisReq, 
                           (tANI_U8 *) disReq, sizeof(tSirTdlsDisReq));

     VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,
                             "Transmit Discovery Request Frame") ;
     /* format TDLS discovery request frame and transmit it */
     limSendTdlsDisReqFrame(pMac, disReq->peerMac, disReq->dialog, 
                                                       psessionEntry) ;

     /* prepare for response */
     pMac->lim.gLimTdlsDisStaCount = 0 ;
     pMac->lim.gLimTdlsDisResultList = NULL ;

    /*
     * start TDLS discovery request timer to wait for discovery responses
     * from all TDLS enabled clients in BSS.
     */

    VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,
                                ("Start Discovery request Timeout Timer")) ;
    MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, 0, 
                                             eLIM_TDLS_DISCOVERY_RSP_WAIT));

    /* assign appropriate sessionId to the timer object */
    pMac->lim.limTimers.gLimTdlsDisRspWaitTimer.sessionId = 
                                            psessionEntry->peSessionId;

    if (tx_timer_activate(&pMac->lim.limTimers.gLimTdlsDisRspWaitTimer)
                                                               != TX_SUCCESS)
    {
        limLog(pMac, LOGP, FL("TDLS discovery response timer \
                                                  activation failed!"));
        goto lim_tdls_dis_start_error;
    }
    /* 
     * when timer expired, eWNI_SME_TDLS_DISCOVERY_START_RSP is sent 
     *  back to SME 
     */
    return (eSIR_SUCCESS) ; 
lim_tdls_dis_start_error:
   /* in error case, PE has to sent the response SME immediately with error code */
   limSendSmeTdlsDisRsp(pMac, eSIR_FAILURE, 
                                     eWNI_SME_TDLS_DISCOVERY_START_RSP);
   return eSIR_FAILURE;
}
/*
 * Process link start request recieved from SME and transmit to AP.
 */
eHalStatus limProcessSmeLinkStartReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    /* get all discovery request parameters */
    tSirTdlsSetupReq *setupReq = (tSirTdlsSetupReq *) pMsgBuf ;
    tLimTdlsLinkSetupInfo *linkSetupInfo; 
    //tLimTdlsLinkSetupPeer *setupPeer;
    tpPESession psessionEntry;
    tANI_U8      sessionId;
    eHalStatus   status;
    
    if((psessionEntry = peFindSessionByBssid(pMac, 
                                    setupReq->bssid, &sessionId)) == NULL)
    {
         VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_ERROR, 
                     "PE Session does not exist for given sme sessionId %d",
                                                          setupReq->sessionId);
         goto lim_tdls_link_start_error;
    }
    
    /* check if we are in proper state to work as TDLS client */ 
    if (psessionEntry->limSystemRole != eLIM_STA_ROLE)
    {
        VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_ERROR, 
                      "TDLS link setup req received in wrong system Role %d",
                                                psessionEntry->limSystemRole);
        goto lim_tdls_link_start_error;
    }

    /*
     * if we are still good, go ahead and check if we are in proper state to
     * do TDLS setup procedure.
     */
    if ((psessionEntry->limSmeState != eLIM_SME_ASSOCIATED_STATE) &&
            (psessionEntry->limSmeState != eLIM_SME_LINK_EST_STATE))
    {
        limLog(pMac, LOGE, "Setup request in invalid LIMsme \
                              state (%d)", pMac->lim.gLimSmeState);
        goto lim_tdls_link_start_error;
    }
    
    /*
     * Now, go ahead and transmit TDLS discovery request, and save setup Req 
     * info for future reference.
     */
     /* create node for Link setup */
    linkSetupInfo = &pMac->lim.gLimTdlsLinkSetupInfo ;
    //setupPeer = NULL ;
   
    status = limTdlsPrepareSetupReqFrame(pMac, linkSetupInfo, setupReq->dialog, 
                                          setupReq->peerMac, psessionEntry) ; 
    if(eHAL_STATUS_SUCCESS == status)
    /* in case of success, eWNI_SME_TDLS_LINK_START_RSP is sent back to SME later when 
    TDLS setup cnf TX complete is successful. */
        return eSIR_SUCCESS;
#if 0

    /*
    * we allocate the TDLS setup Peer Memory here, we will free'd this
    * memory after teardown, if the link is successfully setup or
    * free this memory if any timeout is happen in link setup procedure
    */
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd,
                  (void **) &setupPeer, sizeof( tLimTdlsLinkSetupPeer )))
    {
     limLog( pMac, LOGP, 
                  FL( "Unable to allocate memory during ADD_STA" ));
     VOS_ASSERT(0) ;
     return eSIR_MEM_ALLOC_FAILED;
    }
    setupPeer->dialog = setupReq->dialog ;
    setupPeer->tdls_prev_link_state =  setupPeer->tdls_link_state ;
    setupPeer->tdls_link_state = TDLS_LINK_SETUP_START_STATE ;
    /* TDLS_sessionize: remember sessionId for future */
    setupPeer->tdls_sessionId = psessionEntry->peSessionId;
    setupPeer->tdls_bIsResponder = 1;

    /* 
    * we only populate peer MAC, so it can assit us to find the
    * TDLS peer after response/or after response timeout
    */
    palCopyMemory(pMac->hHdd, setupPeer->peerMac, setupReq->peerMac,
                                              sizeof(tSirMacAddr)) ;
    /* format TDLS discovery request frame and transmit it */
    limSendTdlsLinkSetupReqFrame(pMac, setupReq->peerMac, 
                                       setupReq->dialog, psessionEntry, NULL, 0) ;

    limStartTdlsTimer(pMac, psessionEntry->peSessionId, 
                        &setupPeer->gLimTdlsLinkSetupRspTimeoutTimer,
     (tANI_U32)setupPeer->peerMac, WNI_CFG_TDLS_LINK_SETUP_RSP_TIMEOUT,
                            SIR_LIM_TDLS_LINK_SETUP_RSP_TIMEOUT) ;
    /* update setup peer list */
    setupPeer->next = linkSetupInfo->tdlsLinkSetupList ;
    linkSetupInfo->tdlsLinkSetupList = setupPeer ;
    /* in case of success, eWNI_SME_TDLS_LINK_START_RSP is sent back to SME later when 
    TDLS setup cnf TX complete is successful. --> see limTdlsSetupCnfTxComplete() */
    return eSIR_SUCCESS ; 
#endif
lim_tdls_link_start_error:    
    /* in case of error, return immediately to SME */
    limSendSmeTdlsLinkStartRsp(pMac, eSIR_FAILURE, setupReq->peerMac, 
                                         eWNI_SME_TDLS_LINK_START_RSP);
    return eSIR_FAILURE ;
}

/*
 * Process link teardown request recieved from SME and transmit to AP.
 */
eHalStatus limProcessSmeTeardownReq(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    /* get all discovery request parameters */
    tSirTdlsTeardownReq *teardownReq = (tSirTdlsTeardownReq *) pMsgBuf ;
    tLimTdlsLinkSetupPeer *setupPeer;
    tpPESession psessionEntry;
    tANI_U8      sessionId;
    
    if((psessionEntry = peFindSessionByBssid(pMac, teardownReq->bssid, &sessionId)) == NULL)
    {
         VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_ERROR, 
                        "PE Session does not exist for given sme sessionId %d", teardownReq->sessionId);
         goto lim_tdls_teardown_req_error;
    }
    
    /* check if we are in proper state to work as TDLS client */ 
    if (psessionEntry->limSystemRole != eLIM_STA_ROLE)
    {
        VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_ERROR, 
                          "TDLS teardown req received in wrong system Role %d", psessionEntry->limSystemRole);
        goto lim_tdls_teardown_req_error;
    }

    /*
     * if we are still good, go ahead and check if we are in proper state to
     * do TDLS setup procedure.
     */
    if ((psessionEntry->limSmeState != eLIM_SME_ASSOCIATED_STATE) &&
            (psessionEntry->limSmeState != eLIM_SME_LINK_EST_STATE))
    {
        limLog(pMac, LOGE, "TDLS teardwon req received in invalid LIMsme \
                               state (%d)", psessionEntry->limSmeState);
        goto lim_tdls_teardown_req_error;
    }
    
    VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,
            "Teardown for peer = %02x,%02x,%02x,%02x,%02x,%02x",
                                             teardownReq->peerMac[0],
                                             teardownReq->peerMac[1],
                                             teardownReq->peerMac[2],
                                             teardownReq->peerMac[3],
                                             teardownReq->peerMac[4],
                                             teardownReq->peerMac[5]) ;
    /*
     * Now, go ahead and transmit TDLS teardown request, and save teardown info
     * info for future reference.
     */
     /* Verify if this link is setup */
    setupPeer = NULL ;
    limTdlsFindLinkPeer(pMac, teardownReq->peerMac, &setupPeer);
    if(NULL == setupPeer)
    {
        VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,
                                ("invalid Peer on teardown ")) ;
        goto lim_tdls_teardown_req_error;
    }


    (setupPeer)->tdls_prev_link_state = (setupPeer)->tdls_link_state ;
    (setupPeer)->tdls_link_state = TDLS_LINK_TEARDOWN_START_STATE ;
    /* TDLS_sessionize: check sessionId in case */
    if((setupPeer)->tdls_sessionId != psessionEntry->peSessionId) 
    {
        limLog(pMac, LOGE, "TDLS teardown req; stored sessionId (%d) not matched from peSessionId (%d)", \
            (setupPeer)->tdls_sessionId, psessionEntry->limSmeState);
        (setupPeer)->tdls_sessionId = psessionEntry->peSessionId;
    }
    
    /* format TDLS teardown request frame and transmit it */
    if(eSIR_SUCCESS != limSendTdlsTeardownFrame(pMac, teardownReq->peerMac, 
                                eSIR_MAC_TDLS_TEARDOWN_UNSPEC_REASON, psessionEntry, NULL, 0 ))
    {
        VOS_TRACE(VOS_MODULE_ID_PE, VOS_TRACE_LEVEL_INFO,
                                ("couldn't send teardown frame ")) ;
        goto lim_tdls_teardown_req_error;
    }
    /* in case of success, eWNI_SME_TDLS_TEARDOWN_RSP is sent back to SME later when 
    TDLS teardown TX complete is successful. --> see limTdlsTeardownTxComplete() */
    return eSIR_SUCCESS;
lim_tdls_teardown_req_error:    
    /* in case of error, return immediately to SME */
    limSendSmeTdlsTeardownRsp(pMac, eSIR_FAILURE, teardownReq->peerMac, 
                                     eWNI_SME_TDLS_TEARDOWN_RSP);
    return eSIR_FAILURE;
}


#endif

static void
__limProcessSmeResetApCapsChange(tpAniSirGlobal pMac, tANI_U32 *pMsgBuf)
{
    tpSirResetAPCapsChange pResetCapsChange;
    tpPESession             psessionEntry;
    tANI_U8  sessionId = 0;
    if (pMsgBuf == NULL)
    {
        limLog(pMac, LOGE,FL("Buffer is Pointing to NULL"));
        return;
    }

    pResetCapsChange = (tpSirResetAPCapsChange)pMsgBuf;
    psessionEntry = peFindSessionByBssid(pMac, pResetCapsChange->bssId, &sessionId);
    if (psessionEntry == NULL)
    {
        limLog(pMac, LOGE, FL("Session does not exist for given BSSID"));
        return;
    }

    psessionEntry->limSentCapsChangeNtf = false;
    return;
}
=======
#endif

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

/**
 * limProcessSmeReqMessages()
 *
 *FUNCTION:
 * This function is called by limProcessMessageQueue(). This
 * function processes SME request messages from HDD or upper layer
 * application.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 *
 * @param  pMac      Pointer to Global MAC structure
 * @param  msgType   Indicates the SME message type
 * @param  *pMsgBuf  A pointer to the SME message buffer
 * @return Boolean - TRUE - if pMsgBuf is consumed and can be freed.
 *                   FALSE - if pMsgBuf is not to be freed.
 */

tANI_BOOLEAN
limProcessSmeReqMessages(tpAniSirGlobal pMac, tpSirMsgQ pMsg)
{
    tANI_BOOLEAN bufConsumed = TRUE; //Set this flag to false within case block of any following message, that doesnt want pMsgBuf to be freed.
    tANI_U32 *pMsgBuf = pMsg->bodyptr;
<<<<<<< HEAD
    tpSirSmeScanReq     pScanReq;
    PELOG1(limLog(pMac, LOG1, FL("LIM Received SME Message %s(%d) Global LimSmeState:%s(%d) Global LimMlmState: %s(%d)"),
=======

    PELOG1(limLog(pMac, LOG1, FL("LIM Received SME Message %s(%d) Global LimSmeState:%s(%d) Global LimMlmState: %s(%d)\n"),
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
         limMsgStr(pMsg->type), pMsg->type,
         limSmeStateStr(pMac->lim.gLimSmeState), pMac->lim.gLimSmeState,
         limMlmStateStr(pMac->lim.gLimMlmState), pMac->lim.gLimMlmState );)

<<<<<<< HEAD
    pScanReq = (tpSirSmeScanReq) pMsgBuf;
    /* Special handling of some SME Req msgs where we have an existing GO session and
     * want to insert NOA before processing those msgs. These msgs will be processed later when
     * start event happens
     */
    switch (pMsg->type)
    {
        case eWNI_SME_SCAN_REQ:
        case eWNI_SME_REMAIN_ON_CHANNEL_REQ:

            /* If scan is disabled return from here
             */
            if (pMac->lim.fScanDisabled)
            {
                PELOGE(limLog(pMac, LOGE, FL("Error: Scan Disabled"));)
                if (pMsg->type == eWNI_SME_SCAN_REQ)
                {
                   limSendSmeScanRsp(pMac,
                                     offsetof(tSirSmeScanRsp,bssDescription[0]),
                                     eSIR_SME_INVALID_PARAMETERS,
                                     pScanReq->sessionId,
                                     pScanReq->transactionId);

                   bufConsumed = TRUE;
                }
                else if (pMsg->type == eWNI_SME_REMAIN_ON_CHANNEL_REQ)
                {
                    pMac->lim.gpDefdSmeMsgForNOA = NULL;
                    pMac->lim.gpLimRemainOnChanReq = (tpSirRemainOnChnReq )pMsgBuf;
                    limRemainOnChnRsp(pMac,eHAL_STATUS_FAILURE, NULL);

                    /*
                     * limRemainOnChnRsp will free the buffer this change is to
                     * avoid "double free"
                     */
                    bufConsumed = FALSE;
                }

                return bufConsumed;
            }
            /*
             * Do not add BREAK here
             */
        case eWNI_SME_OEM_DATA_REQ:
        case eWNI_SME_JOIN_REQ:
            /* If we have an existing P2P GO session we need to insert NOA before actually process this SME Req */
            if ((limIsNOAInsertReqd(pMac) == TRUE) && IS_FEATURE_SUPPORTED_BY_FW(P2P_GO_NOA_DECOUPLE_INIT_SCAN))
            {
                tANI_U32 noaDuration;
                __limRegisterDeferredSmeReqForNOAStart(pMac, pMsg->type, pMsgBuf);
                noaDuration = limCalculateNOADuration(pMac, pMsg->type, pMsgBuf);
                bufConsumed = __limInsertSingleShotNOAForScan(pMac, noaDuration);
                return bufConsumed;
            }
    }
    /* If no insert NOA required then execute the code below */

=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
    switch (pMsg->type)
    {
        case eWNI_SME_START_REQ:
            __limProcessSmeStartReq(pMac, pMsgBuf);
            break;

        case eWNI_SME_SYS_READY_IND:
            bufConsumed = __limProcessSmeSysReadyInd(pMac, pMsgBuf);
            break;

<<<<<<< HEAD
=======

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        case eWNI_SME_START_BSS_REQ:
            bufConsumed = __limProcessSmeStartBssReq(pMac, pMsg);
            break;

        case eWNI_SME_SCAN_REQ:
            __limProcessSmeScanReq(pMac, pMsgBuf);
<<<<<<< HEAD
=======

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            break;

#ifdef FEATURE_OEM_DATA_SUPPORT
        case eWNI_SME_OEM_DATA_REQ:
            __limProcessSmeOemDataReq(pMac, pMsgBuf);
<<<<<<< HEAD
            break;
#endif
=======

            break;
#endif
#ifdef WLAN_FEATURE_P2P
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        case eWNI_SME_REMAIN_ON_CHANNEL_REQ:
            bufConsumed = limProcessRemainOnChnlReq(pMac, pMsgBuf);
            break;

        case eWNI_SME_UPDATE_NOA:
            __limProcessSmeNoAUpdate(pMac, pMsgBuf);
            break;
<<<<<<< HEAD
        case eWNI_SME_CLEAR_DFS_CHANNEL_LIST:
            __limProcessClearDfsChannelList(pMac, pMsg);
            break;
        case eWNI_SME_JOIN_REQ:
            __limProcessSmeJoinReq(pMac, pMsgBuf);
=======
#endif
        case eWNI_SME_JOIN_REQ:
            __limProcessSmeJoinReq(pMac, pMsgBuf);

>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            break;

        case eWNI_SME_AUTH_REQ:
           // __limProcessSmeAuthReq(pMac, pMsgBuf);

            break;

        case eWNI_SME_REASSOC_REQ:
            __limProcessSmeReassocReq(pMac, pMsgBuf);

            break;

        case eWNI_SME_PROMISCUOUS_MODE_REQ:
            //__limProcessSmePromiscuousReq(pMac, pMsgBuf);

            break;

        case eWNI_SME_DISASSOC_REQ:
            __limProcessSmeDisassocReq(pMac, pMsgBuf);

            break;

        case eWNI_SME_DISASSOC_CNF:
        case eWNI_SME_DEAUTH_CNF:
            __limProcessSmeDisassocCnf(pMac, pMsgBuf);

            break;

        case eWNI_SME_DEAUTH_REQ:
            __limProcessSmeDeauthReq(pMac, pMsgBuf);

            break;

<<<<<<< HEAD
=======
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && defined(ANI_PRODUCT_TYPE_AP)
        case eWNI_SME_SWITCH_CHL_REQ:
        case eWNI_SME_SWITCH_CHL_CB_PRIMARY_REQ:
        case eWNI_SME_SWITCH_CHL_CB_SECONDARY_REQ:
            bufConsumed = __limProcessSmeSwitchChlReq(pMac, pMsg);
            break;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


        case eWNI_SME_SETCONTEXT_REQ:
            __limProcessSmeSetContextReq(pMac, pMsgBuf);

            break;

        case eWNI_SME_REMOVEKEY_REQ:
            __limProcessSmeRemoveKeyReq(pMac, pMsgBuf);

            break;

        case eWNI_SME_STOP_BSS_REQ:
            bufConsumed = __limProcessSmeStopBssReq(pMac, pMsg);
            break;

        case eWNI_SME_ASSOC_CNF:
        case eWNI_SME_REASSOC_CNF:
            if (pMsg->type == eWNI_SME_ASSOC_CNF)
<<<<<<< HEAD
                PELOG1(limLog(pMac, LOG1, FL("Received ASSOC_CNF message"));)
            else
                PELOG1(limLog(pMac, LOG1, FL("Received REASSOC_CNF message"));)
=======
                PELOG1(limLog(pMac, LOG1, FL("Received ASSOC_CNF message\n"));)
            else
                PELOG1(limLog(pMac, LOG1, FL("Received REASSOC_CNF message\n"));)
#ifdef ANI_PRODUCT_TYPE_AP
            __limProcessSmeAssocCnf(pMac, pMsg->type, pMsgBuf);
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            __limProcessSmeAssocCnfNew(pMac, pMsg->type, pMsgBuf);
            break;

        case eWNI_SME_ADDTS_REQ:
<<<<<<< HEAD
            PELOG1(limLog(pMac, LOG1, FL("Received ADDTS_REQ message"));)
=======
            PELOG1(limLog(pMac, LOG1, FL("Received ADDTS_REQ message\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            __limProcessSmeAddtsReq(pMac, pMsgBuf);
            break;

        case eWNI_SME_DELTS_REQ:
<<<<<<< HEAD
            PELOG1(limLog(pMac, LOG1, FL("Received DELTS_REQ message"));)
=======
            PELOG1(limLog(pMac, LOG1, FL("Received DELTS_REQ message\n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            __limProcessSmeDeltsReq(pMac, pMsgBuf);
            break;

        case SIR_LIM_ADDTS_RSP_TIMEOUT:
<<<<<<< HEAD
            PELOG1(limLog(pMac, LOG1, FL("Received SIR_LIM_ADDTS_RSP_TIMEOUT message "));)
=======
            PELOG1(limLog(pMac, LOG1, FL("Received SIR_LIM_ADDTS_RSP_TIMEOUT message \n"));)
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            limProcessSmeAddtsRspTimeout(pMac, pMsg->bodyval);
            break;

        case eWNI_SME_STA_STAT_REQ:
        case eWNI_SME_AGGR_STAT_REQ:
        case eWNI_SME_GLOBAL_STAT_REQ:
        case eWNI_SME_STAT_SUMM_REQ:
            __limProcessSmeStatsRequest( pMac, pMsgBuf);
            //HAL consumes pMsgBuf. It will be freed there. Set bufConsumed to false.
            bufConsumed = FALSE;
            break;
        case eWNI_SME_GET_STATISTICS_REQ:
            __limProcessSmeGetStatisticsRequest( pMac, pMsgBuf);
            //HAL consumes pMsgBuf. It will be freed there. Set bufConsumed to false.
            bufConsumed = FALSE;
            break;              
<<<<<<< HEAD
#if defined WLAN_FEATURE_VOWIFI_11R || defined FEATURE_WLAN_CCX || defined(FEATURE_WLAN_LFR)
        case eWNI_SME_GET_ROAM_RSSI_REQ:
            __limProcessSmeGetRoamRssiRequest( pMac, pMsgBuf);
            //HAL consumes pMsgBuf. It will be freed there. Set bufConsumed to false.
            bufConsumed = FALSE;
            break;
#endif
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        case eWNI_SME_DEL_BA_PEER_IND:
            limProcessSmeDelBaPeerInd(pMac, pMsgBuf);
            break;
        case eWNI_SME_GET_SCANNED_CHANNEL_REQ:
            limProcessSmeGetScanChannelInfo(pMac, pMsgBuf);
            break;
<<<<<<< HEAD
=======
#ifdef WLAN_SOFTAP_FEATURE
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        case eWNI_SME_GET_ASSOC_STAS_REQ:
            limProcessSmeGetAssocSTAsInfo(pMac, pMsgBuf);
            break;
        case eWNI_SME_TKIP_CNTR_MEAS_REQ:
            limProcessTkipCounterMeasures(pMac, pMsgBuf);
            break;

       case eWNI_SME_HIDE_SSID_REQ: 
            __limProcessSmeHideSSID(pMac, pMsgBuf);
            break;
       case eWNI_SME_UPDATE_APWPSIE_REQ: 
            __limProcessSmeUpdateAPWPSIEs(pMac, pMsgBuf);
            break;
        case eWNI_SME_GET_WPSPBC_SESSION_REQ:
             limProcessSmeGetWPSPBCSessions(pMac, pMsgBuf); 
             break;
         
        case eWNI_SME_SET_APWPARSNIEs_REQ:
              __limProcessSmeSetWPARSNIEs(pMac, pMsgBuf);        
              break;
<<<<<<< HEAD

        case eWNI_SME_CHNG_MCC_BEACON_INTERVAL:
             //Update the beaconInterval
             __limProcessSmeChangeBI(pMac, pMsgBuf );
             break;
=======
#endif            
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
            
#if defined WLAN_FEATURE_VOWIFI 
        case eWNI_SME_NEIGHBOR_REPORT_REQ_IND:
        case eWNI_SME_BEACON_REPORT_RESP_XMIT_IND:
            __limProcessReportMessage(pMac, pMsg);
            break;
#endif

#if defined WLAN_FEATURE_VOWIFI_11R
       case eWNI_SME_FT_PRE_AUTH_REQ:
            bufConsumed = (tANI_BOOLEAN)limProcessFTPreAuthReq(pMac, pMsg);
            break;
       case eWNI_SME_FT_UPDATE_KEY:
            limProcessFTUpdateKey(pMac, pMsgBuf);
            break;

       case eWNI_SME_FT_AGGR_QOS_REQ:
            limProcessFTAggrQosReq(pMac, pMsgBuf);
            break;
#endif

#if defined FEATURE_WLAN_CCX
       case eWNI_SME_CCX_ADJACENT_AP_REPORT:
            limProcessAdjacentAPRepMsg ( pMac, pMsgBuf );
            break;
#endif
       case eWNI_SME_ADD_STA_SELF_REQ:
            __limProcessSmeAddStaSelfReq( pMac, pMsgBuf );
            break;
        case eWNI_SME_DEL_STA_SELF_REQ:
            __limProcessSmeDelStaSelfReq( pMac, pMsgBuf );
            break;

<<<<<<< HEAD
        case eWNI_SME_REGISTER_MGMT_FRAME_REQ:
            __limProcessSmeRegisterMgmtFrameReq( pMac, pMsgBuf );
            break;
#ifdef FEATURE_WLAN_TDLS
        case eWNI_SME_TDLS_SEND_MGMT_REQ:
            limProcessSmeTdlsMgmtSendReq(pMac, pMsgBuf);
            break;
        case eWNI_SME_TDLS_ADD_STA_REQ:
            limProcessSmeTdlsAddStaReq(pMac, pMsgBuf);
            break;
        case eWNI_SME_TDLS_DEL_STA_REQ:
            limProcessSmeTdlsDelStaReq(pMac, pMsgBuf);
            break;
#endif
#ifdef FEATURE_WLAN_TDLS_INTERNAL
        case eWNI_SME_TDLS_DISCOVERY_START_REQ:
            limProcessSmeDisStartReq(pMac,  pMsgBuf);
            break ;
        case eWNI_SME_TDLS_LINK_START_REQ:
            limProcessSmeLinkStartReq(pMac,  pMsgBuf);
            break ;
        case eWNI_SME_TDLS_TEARDOWN_REQ:
            limProcessSmeTeardownReq(pMac,  pMsgBuf);
            break ;
#endif
        case eWNI_SME_RESET_AP_CAPS_CHANGED:
            __limProcessSmeResetApCapsChange(pMac, pMsgBuf);
            break;

        case eWNI_SME_SET_TX_POWER_REQ:
            limSendSetTxPowerReq(pMac,  pMsgBuf);
            break ;
=======
#ifdef WLAN_FEATURE_P2P
        case eWNI_SME_REGISTER_MGMT_FRAME_REQ:
            __limProcessSmeRegisterMgmtFrameReq( pMac, pMsgBuf );
            break;
#endif        
            
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838

        default:
            vos_mem_free((v_VOID_t*)pMsg->bodyptr);
            pMsg->bodyptr = NULL;
            break;
    } // switch (msgType)

    return bufConsumed;
} /*** end limProcessSmeReqMessages() ***/
