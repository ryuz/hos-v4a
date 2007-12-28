/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ipether.h
 * @brief %jp{Ether上にIPプロトコルを実装(つまりMAC層近辺)}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__ipether_h__
#define __HOS__ipether_h__


#include "system/sysapi/sysapi.h"
#include "system/file/syncdrv_local.h"


#define IPETHER_ARPTBL_SIZE			4
#define IPETHER_RECVBUS_SIZE		4
#define IPETHER_MAXPACKET_SIZE		2048


/* IP-Ether生成情報 */
typedef struct t_ipether_inf
{
	unsigned char	ubIpAddr[4];			/* IPアドレス */
	unsigned char	ubSubNetMask[4];		/* サブネットマスク */
	unsigned char	ubGateWayIpAddr[4];		/* デフォルトゲートウェイアドレス */
} T_IPETHER_INF;



/* ARPテーブル */
typedef struct t_ipether_arptbl
{
	unsigned char	ubIpAddr[4];	/* IPアドレス */
	unsigned char	ubMacAddr[6];	/* MACアドレス */
} T_IPETHER_ARPTBL;



/* Etherドライバ制御部 */
typedef struct c_ipether
{
	C_SYNCDRV			SyncDrv;				/* キャラクタ型デバイスドライバを継承 */

	HANDLE				hEther;					/* Etherドライバ */
	
	int					iOpenCount;				/* オープンカウンタ */

	SYSPRC_HANDLE		hPrcRecv;				/* 受信プロセス */
	SYSMTX_HANDLE		hMtxSend;				/* 排他制御ミューテックス */
	SYSMTX_HANDLE		hMtxRecv;				/* 排他制御ミューテックス */
	SYSMTX_HANDLE		hMtxArp;				/* 排他制御ミューテックス */

	SYSEVT_HANDLE		hEvtRecv;				/*  */
	SYSEVT_HANDLE		hEvtArp;				/*  */

	unsigned char		ubMyIpAddr[4];			/* 自IPアドレス */
	unsigned char		ubMyMacAddr[6];			/* 自MACアドレス */
	
	unsigned char		ubSubNetMask[4];		/* サブネットマスク */
	unsigned char		ubGateWayIpAddr[4];		/* ゲートウェイのIPアドレス */
	
	T_IPETHER_ARPTBL	ArpTbl[IPETHER_ARPTBL_SIZE];
	
	int					iRecvHead;				/* 受信パケット先頭位置 */
	int					iRecvNum;				/* 受信パケット数 */

	unsigned char		ubSendBuf[IPETHER_MAXPACKET_SIZE];
	unsigned char		ubRecvBuf[IPETHER_RECVBUS_SIZE][IPETHER_MAXPACKET_SIZE];
} C_IPETHER;


#ifdef __cplusplus
extern "C" {
#endif

HANDLE IpEther_Create(const char *pszEther, const T_IPETHER_INF *pInf);		/**< 生成 */
void   IpEther_Delete(HANDLE hDriver);										/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__ipether_h__ */



/* endof file */
