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


// メッセージ構造体
struct T_PRINT_MSG
{
    T_MSG msg;
    char  text[32];
};

// 初期化ハンドラ
void Sample_Initialize(VP_INT exinf)
{
    // UART初期化
    Uart_Initialize();
    Uart_PutString("Start\r\n");
    
    // 固定長メモリプール生成
    T_CMPF cmpf;
    cmpf.mpfatr = TA_TFIFO;                 
    cmpf.blkcnt = 3;                        
    cmpf.blksz  = sizeof(T_PRINT_MSG);      
    cmpf.mpf    = NULL;                     
    mpfid = acre_mpf(&cmpf);

    // メールボックス生成
    T_CMBX cmbx;
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

// 文字列表示タスク
void Sample_Print(VP_INT exinf)
{
    for ( ; ; ) {
        // メッセージを受けてUARTに表示
        T_PRINT_MSG *msg;
        rcv_mbx(mbxid, (T_MSG **)&msg);
        Uart_PutString(msg->text);
        rel_mpf(mpfid, msg);
    }
}


// 哲学者クラス
class Philosopher
{
protected:
    ID  m_num;      // 自分の番号
    ID  m_left;     // 左のフォーク相当のセマフォID
    ID  m_right;    // 右のフォーク相当のセマフォID

    int LEFT(int num)    { return num <= 1 ? 5 : num - 1; }
    int RIGHT(int num)   { return num >= 5 ? 1 : num + 1; }

public:
    // コンストラクタ
    Philosopher(ID num)
    {
        m_num   = num;
        m_left  = LEFT(m_num);
        m_right = RIGHT(m_num);
    }

    // いわゆる食事する哲学者の問題
    void Dining(void)
    {
        for ( ; ; ) {
            // 適当な時間考える
            RandomWait("thinking");
        
            // 左右のフォークを取るまでループ
            for ( ; ; )
            {
                // 左から順に取る
                wai_sem(m_left);
                if ( pol_sem(m_right) == E_OK )
                {
                    break;  // 両方取れた
                }
                sig_sem(m_left); // 取れなければ離す
                
                // お腹を空かせながら適当な時間待つ
                RandomWait("hungry");

                // 右から順に取る} */
                wai_sem(m_right);
                if ( pol_sem(m_left) == E_OK ) {
                    break;  // 両方取れた
                }
                sig_sem(m_right);    // 取れなければ離す

                // お腹を空かせながら適当な時間待つ
                RandomWait("hungry");
            }
            
            // 適当な時間食べる
            RandomWait("eating");
            
            // 両方のフォークを置く
            sig_sem(m_left);
            sig_sem(m_right);
        }
    }

protected:
    // 状態を表示して適当な時間待つ
    void RandomWait(const char *status)
    {
        // 状態を出力
        SendPrintMessage(status);

        // セマフォで排他制御して newlib の乱数利用
        wai_sem(SEMID_RAND);
        int r;
        r = rand();
        sig_sem(SEMID_RAND);
        dly_tsk((r % 1000) + 10);
    }
    
    // 自分の番号をつけて文字列送信
    void SendPrintMessage(const char *text)
    {
        // メモリ取得
        VP  mem;
        get_mpf(mpfid, &mem);
        auto msg = (T_PRINT_MSG *)mem;

        // 文字列生成
        msg->text[0] = '0' + m_num;
        msg->text[1] = ' ';
        msg->text[2] = ':';
        msg->text[3] = ' ';
        strcpy(&msg->text[4], text);
        strcat(msg->text, "\r\n");

        // 表示タスクに送信
        snd_mbx(mbxid, (T_MSG *)msg);
    }
};

// 5人の哲学者
Philosopher g_philosopher1(1);
Philosopher g_philosopher2(2);
Philosopher g_philosopher3(3);
Philosopher g_philosopher4(4);
Philosopher g_philosopher5(5);

// ITRONのタスクを分配
void Sample_Task(VP_INT exinf)
{
    switch (exinf) {
    case 1: g_philosopher1.Dining(); break;
    case 2: g_philosopher2.Dining(); break;
    case 3: g_philosopher3.Dining(); break;
    case 4: g_philosopher4.Dining(); break;
    case 5: g_philosopher5.Dining(); break;
    }
}


// end of file
