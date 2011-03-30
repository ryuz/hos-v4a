/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sample.c
 * @brief %jp{サンプルプログラム}%en{Sample program}
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdlib.h>
#include <string.h>
#include "kernel.h"
#include "kernel_id.h"
#include "uart.h"


#define LEFT(num)	((num) <= 1 ? 5 : (num) - 1)
#define RIGHT(num)	((num) >= 5 ? 1 : (num) + 1)


/** %jp{初期化ハンドラ} */
void Sample_Initialize(VP_INT exinf)
{
	/* %jp{UART初期化} */
	Uart_Initialize();
}


/** %jp{適当な時間待つ} */
void rand_wait(void)
{
	static	long	x = 1;
	int 			r;

	/* 擬似乱数生成 */
	wai_sem(SEMID_RAND);
	x = x * 214013 + 2531011;
	r = ((x >> 16) & 0xffff);
	sig_sem(SEMID_RAND);

	dly_tsk((r % 100) + 10);
}


/** %jp{状態表示} */
void print_state(int num, char *text)
{
	wai_sem(SEMID_UART);

	/* %jp{文字列生成} */
	Uart_PutChar('0' + num);
	Uart_PutChar(' ');
	Uart_PutChar(':');
	Uart_PutChar(' ');
	Uart_PutString(text);
	Uart_PutChar('\r');
	Uart_PutChar('\n');

	sig_sem(SEMID_UART);
}


/** %jp{サンプルタスク} */
void Sample_Task(VP_INT exinf)
{
	int num;

	num = (int)exinf;

	/* %jp{いわゆる哲学者の食事の問題} */
	for ( ; ; )
	{
		/* %jp{適当な時間考える} */
		print_state(num, "thinking");
		rand_wait();

		/* %jp{左右のフォークを取るまでループ} */
		for ( ; ; )
		{
			/* %jp{左から順に取る} */
			wai_sem(LEFT(num));
			if ( pol_sem(RIGHT(num)) == E_OK )
			{
				break;	/* %jp{両方取れた} */
			}
			sig_sem(LEFT(num));	/* %jp{取れなければ離す} */

			/* %jp{適当な時間待つ} */
			print_state(num, "hungry");
			rand_wait();

			/* %jp{右から順に取る} */
			wai_sem(RIGHT(num));
			if ( pol_sem(LEFT(num)) == E_OK )
			{
				break;	/* %jp{両方取れた} */
			}
			sig_sem(RIGHT(num));	/* %jp{取れなければ離す} */

			/* %jp{適当な時間待つ} */
			print_state(num, "hungry");
			rand_wait();
		}

		/* %jp{適当な時間、食べる} */
		print_state(num, "eating");
		rand_wait();

		/* %jp{フォークを置く} */
		sig_sem(LEFT(num));
		sig_sem(RIGHT(num));
	}
}



/* end of file */
