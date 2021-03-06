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

#if !defined( HDD_CONNECTION_H__ ) 
<<<<<<< HEAD
#define HDD_CONNECTION_H__
#include <wlan_hdd_mib.h>
#define HDD_MAX_NUM_IBSS_STA ( 9 )
#ifdef FEATURE_WLAN_TDLS
#define HDD_MAX_NUM_TDLS_STA ( 8 )
#define TDLS_STA_INDEX_VALID(staId) \
                          (((staId) >= 4) && ((staId) < 0xFF))
#endif
=======
#define HDD_CONNECTION_H__ 
#include <wlan_hdd_mib.h>
#define HDD_MAX_NUM_IBSS_STA ( 4 )
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#define TKIP_COUNTER_MEASURE_STARTED 1
#define TKIP_COUNTER_MEASURE_STOPED  0 
/* Timeout (in ms) for Link to Up before Registering Station */
#define ASSOC_LINKUP_TIMEOUT 60
typedef enum 
{
   /** Not associated in Infra or participating in an IBSS / Ad-hoc network.*/
   eConnectionState_NotConnected,
<<<<<<< HEAD

   /** While connection in progress */
   eConnectionState_Connecting,

=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
   /** Associated in an Infrastructure network.*/
   eConnectionState_Associated,

   /** Participating in an IBSS network though disconnected (no partner stations
       in the IBSS).*/
   eConnectionState_IbssDisconnected,

   /** Participating in an IBSS network with partner stations also present*/
   eConnectionState_IbssConnected,

   /** Disconnecting in an Infrastructure network.*/
   eConnectionState_Disconnecting
<<<<<<< HEAD

=======
	
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
}eConnectionState;
/**This structure stores the connection information */
typedef struct connection_info_s
{
   /** connection state of the NIC.*/
   eConnectionState connState;
   
   /** BSS type of the current connection.   Comes from the MIB at the
       time the connect request is issued in combination with the BssDescription
      from the associated entity.*/
      
   eMib_dot11DesiredBssType connDot11DesiredBssType;
   /** BSSID */
   tCsrBssid bssId;
   
   /** SSID Info*/
   tCsrSSIDInfo SSID;
   
   /** Station ID */
   v_U8_t staId[ HDD_MAX_NUM_IBSS_STA ];
   /** Peer Mac Address of the IBSS Stations */
   v_MACADDR_t peerMacAddress[ HDD_MAX_NUM_IBSS_STA ];         
   /** Auth Type */
   eCsrAuthType   authType;

   /** Unicast Encryption Type */
   eCsrEncryptionType ucEncryptionType;

   /** Multicast Encryption Type */
   eCsrEncryptionType mcEncryptionType;

   /** Keys */
   tCsrKeys Keys;

   /** Operation Channel  */
   v_U8_t operationChannel; 
   
    /** Remembers authenticated state */
   v_U8_t uIsAuthenticated;
<<<<<<< HEAD

   /** Dot11Mode */
   tANI_U32 dot11Mode;
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
   
}connection_info_t;
/*Forward declaration of Adapter*/
typedef struct hdd_adapter_s hdd_adapter_t;
typedef struct hdd_context_s hdd_context_t;
typedef struct hdd_station_ctx hdd_station_ctx_t;
typedef struct hdd_ap_ctx_s  hdd_ap_ctx_t;
<<<<<<< HEAD
typedef struct hdd_mon_ctx_s  hdd_mon_ctx_t;
=======
#ifdef CONFIG_CFG80211   
typedef struct hdd_mon_ctx_s  hdd_mon_ctx_t;
#endif
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838


extern v_BOOL_t hdd_connIsConnected( hdd_station_ctx_t *pHddStaCtx );
extern eHalStatus hdd_smeRoamCallback( void *pContext, tCsrRoamInfo *pRoamInfo, v_U32_t roamId, 
                                eRoamCmdStatus roamStatus, eCsrRoamResult roamResult );

extern v_VOID_t hdd_connSaveConnectInfo( hdd_adapter_t *pAdapter, tCsrRoamInfo *pRoamInfo, eCsrRoamBssType eBssType );

<<<<<<< HEAD
v_BOOL_t hdd_connGetConnectedBssType( hdd_station_ctx_t *pHddCtx,
=======
extern v_BOOL_t hdd_connGetConnectedBssType( hdd_station_ctx_t *pHddCtx, 
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
        eMib_dot11DesiredBssType *pConnectedBssType );

int hdd_SetGENIEToCsr( hdd_adapter_t *pAdapter, eCsrAuthType *RSNAuthType );

int hdd_set_csr_auth_type( hdd_adapter_t *pAdapter, eCsrAuthType RSNAuthType );
<<<<<<< HEAD
VOS_STATUS hdd_roamRegisterTDLSSTA( hdd_adapter_t *pAdapter,
                                    tANI_U8 *peerMac, tANI_U16 staId, tANI_U8 ucastSig);
void hdd_PerformRoamSetKeyComplete(hdd_adapter_t *pAdapter);
=======
>>>>>>> 8f21ba79e30f047f727d3b9dd531267c1db2a838
#endif
