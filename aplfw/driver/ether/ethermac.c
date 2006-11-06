
#include <string.h>
#include "system/file.h"

#define ETHERMAC_ARPTABLE_NUM	16

typedef struct t_ethermac_arpinf
{
	unsigned char ubMacAddr[6];		/* MACアドレス */
	unsigned char ubIpAddr[4];		/* IPアドレス */
} T_ETHERMAC_ARPINF;


typedef struct c_ethermac
{
	HANDLE            hEther;
	unsigned char     ubMyMacAddr[6];						/* 自MACアドレス */
	unsigned char     ubMyIpAddr[4];						/* 自IPアドレス */
	T_ETHERMAC_ARPINF ubArpTable[ETHERMAC_ARPTABLE_NUM];	/* ARPテーブル */

	unsigned char     ubBuf[1514];
} C_ETHERMAC;


/* ARP要求送信 */
void EtherMac_SendArpReq(C_ETHERMAC *self, const unsigned char *pubIpAddr)
{
	unsigned char *pubBuf;
	
	pubBuf = self->ubBuf;
	
	/* パケット生成 */
	memset(&pubBuf[0], 0xff, 6);					/* 送信先MACアドレス(ブロードキャスト) */
	memcpy(&pubBuf[6], self->ubMyMacAddr, 6);		/* 自局MACアドレス */
	pubBuf[12] = 0x08; pubBuf[13] = 0x06;			/* プロトコルタイプ */
	pubBuf[14] = 0x00; pubBuf[15] = 0x01;			/* ハードウェアタイプ(Ether) */
	pubBuf[16] = 0x08; pubBuf[17] = 0x00;			/* プロトコルタイプ(IP) */
	pubBuf[18] = 0x06;								/* ハードウェアアドレス長 */
	pubBuf[19] = 0x04;								/* プロトコルアドレス長 */
	pubBuf[20] = 0x00; pubBuf[21] = 0x01;			/* オペレーション(ARP要求) */
	memcpy(&pubBuf[22], self->ubMyMacAddr, 6);		/* 送信元ハードウェアアドレス */
	memcpy(&pubBuf[28], self->ubMyIpAddr, 4);		/* 送信元プロトコルアドレス */
	memset(&pubBuf[32], 0x00, 6);					/* ターゲットハードウェアアドレス */
	memcpy(&pubBuf[38], pubIpAddr, 4);				/* ターゲットプロトコルアドレス */
	
	/* 送信 */
	File_Write(self->hEther, pubBuf, 42);
}


/* ARP応答送信 */
void EtherMac_SendArpAck(C_ETHERMAC *self, const T_ETHERMAC_ARPINF *pArpInf)
{
	
}


