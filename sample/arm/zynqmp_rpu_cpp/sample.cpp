/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sample.cpp
 * @brief サンプルプログラム
 *
 * Copyright (C) 1998-2021 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "kernel.h"
#include "kernel_id.h"
#include "sample.h"
#include "uart.h"

ID mbxid;
ID mpfid;


inline int LEFT(int num)	{ return num <= 1 ? 5 : num - 1; }
inline int RIGHT(int num)	{ return num >= 5 ? 1 : num + 1; }


// メッセージ構造体
struct T_PRINT_MSG
{
	T_MSG msg;
	char  text[32];
};


// 初期化ハンドラ
void Sample_Initialize(VP_INT exinf)
{
	T_CMPF cmpf;
	T_CMBX cmbx;
	
	// UART初期化
	Uart_Initialize();
	
	// 固定長メモリプール生成
	cmpf.mpfatr = TA_TFIFO;					
	cmpf.blkcnt = 3;						
	cmpf.blksz  = sizeof(T_PRINT_MSG);		
	cmpf.mpf    = NULL;						
	mpfid = acre_mpf(&cmpf);

	// メールボックス生成
	cmbx.mbxatr  = TA_TFIFO | TA_TFIFO;		
	cmbx.maxmpri = 1;						
	cmbx.mprihd  = NULL;					
	mbxid = acre_mbx(&cmbx);

	// タスク起動
	act_tsk(TSKID_PRINT);
	act_tsk(TSKID_SAMPLE1);
	act_tsk(TSKID_SAMPLE2);
	act_tsk(TSKID_SAMPLE3);
	act_tsk(TSKID_SAMPLE4);
	act_tsk(TSKID_SAMPLE5);
}


// 適当な時間待つ
void rand_wait(void)
{
	int r;

	wai_sem(SEMID_RAND);
	r = rand();
	sig_sem(SEMID_RAND);

	dly_tsk((r % 1000) + 10);
}


// 状態表示}
void print_state(int num, const char *text)
{
	T_PRINT_MSG *msg;
	VP  mem;
	
	// メモリ取得
	get_mpf(mpfid, &mem);
	msg = (T_PRINT_MSG *)mem;

	// 文字列生成
	msg->text[0] = '0' + num;
	msg->text[1] = ' ';
	msg->text[2] = ':';
	msg->text[3] = ' ';
	strcpy(&msg->text[4], text);
	strcat(msg->text, "\n");
	
	// 表示タスクに送信
	snd_mbx(mbxid, (T_MSG *)msg);
}


// サンプルタスク
void Sample_Task(VP_INT exinf)
{
	int num;
	
	num = (int)exinf;
	
	// いわゆる哲学者の食事の問題
	for ( ; ; )
	{
		// 適当な時間考える
		print_state(num, "thinking");
		rand_wait();
		
		// 左右のフォークを取るまでループ
		for ( ; ; )
		{
			// 左から順に取る
			wai_sem(LEFT(num));
			if ( pol_sem(RIGHT(num)) == E_OK )
			{
				break;	// 両方取れた
			}
			sig_sem(LEFT(num));	// 取れなければ離す
			
			// 適当な時間待つ
			print_state(num, "hungry");
			rand_wait();

			// 右から順に取る} */
			wai_sem(RIGHT(num));
			if ( pol_sem(LEFT(num)) == E_OK )
			{
				break;	// 両方取れた
			}
			sig_sem(RIGHT(num));	// 取れなければ離す

			// 適当な時間待つ
			print_state(num, "hungry");
			rand_wait();
		}
		
		// 適当な時間、食べる
		print_state(num, "eating");
		rand_wait();
		
		// フォークを置く
		sig_sem(LEFT(num));
		sig_sem(RIGHT(num));
	}
}


// 表示タスク
void Sample_Print(VP_INT exinf)
{
	T_PRINT_MSG *msg;
	
	for ( ; ; )
	{
		rcv_mbx(mbxid, (T_MSG **)&msg);
		Uart_PutString(msg->text);
		rel_mpf(mpfid, msg);
	}
}

// end of file
