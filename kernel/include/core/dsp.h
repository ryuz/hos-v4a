/**
 *  Hyper Operating System V4 Advance
 *
 * @file  dsp.h
 * @brief %jp{タスクディスパッチャのヘッダファイル}%en{task dispatcher heder file}
 *
 * @version $Id: dsp.h,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL_core__dsp_h__
#define _KERNEL_core__dsp_h__





#ifdef __cplusplus
extern "C" {
#endif

void _kernel_dsp_tsk(void);								/**< %jp{タスクディスパッチ} */
void _kernel_ent_tsk(VP_INT exinf1, VP_INT exinf2);		/**< %jp{タスクエントリーポイント} */

void _kernel_dsp_sta_tsk(_KERNEL_T_TSKHDL tskhdl);		/**< %jp{他タスクを開始する} */
void _kernel_dsp_ext_tsk(_KERNEL_T_TSKHDL tskhdl);		/**< %jp{自タスクを終了する} */
void _kernel_dsp_ter_tsk(_KERNEL_T_TSKHDL tskhdl);		/**< %jp{他タスクを終了する} */
void _kernel_dsp_wai_tsk(_KERNEL_T_TSKHDL tskhdl);		/**< %jp{自タスクを待ち状態にする} */
void _kernel_dsp_wup_tsk(_KERNEL_T_TSKHDL tskhdl);		/**< %jp{他タスクを待ち解除する} */

#ifdef __cplusplus
}
#endif


#define _KERNEL_DSP_TSK()			_kernel_dsp_tsk()			/**< タスクディスパッチ実施 */


/* %jp{実行中もレディーキューに繋ぐモデルの場合} */


#if _KERNEL_SPT_SUS_TSK	/*  %jp{サスペンドありのモデルの場合} */

#define _KERNEL_DSP_STA_TSK(tskhdl)		_kernel_dsp_sta_tsk(tskhdl)		/**< %jp{他タスクを開始する} */
#define _KERNEL_DSP_EXT_TSK(tskhdl)		_kernel_dsp_ext_tsk(tskhdl)		/**< %jp{自タスクを終了する} */
#define _KERNEL_DSP_TER_TSK(tskhdl)		_kernel_dsp_ter_tsk(tskhdl)		/**< %jp{他タスクを終了する} */
#define _KERNEL_DSP_WAI_TSK(tskhdl)		_kernel_dsp_wai_tsk(tskhdl)		/**< %jp{自タスクを待ち状態にする} */
#define _KERNEL_DSP_WUP_TSK(tskhdl)		_kernel_dsp_wup_tsk(tskhdl)		/**< %jp{他タスクを待ち解除する} */

#else /* %jp{サスペンド無しのモデルの場合} */

#if _KERNEL_RUNTSK_ON_RDQ	/* %jp{実行中もレディーキューに繋ぐ場合} */

#define _KERNEL_DSP_STA_TSK(tskhdl)		do { _KERNEL_TSK_SET_TSKSTAT(_KERNEL_TSK_TSKHDL2TCB(tskhdl), _KERNEL_TTS_RDY); _KERNEL_ADD_RDQ(tskhdl); } while (0)		/**< %jp{他タスクを開始する} */
#define _KERNEL_DSP_EXT_TSK(tskhdl)		do { _KERNEL_TSK_SET_TSKSTAT(_KERNEL_TSK_TSKHDL2TCB(tskhdl), _KERNEL_TTS_DMT); _KERNEL_RMV_RDQ(tskhdl); } while (0)		/**< %jp{自タスクを終了する} */
#define _KERNEL_DSP_TER_TSK(tskhdl)		do { _KERNEL_TSK_SET_TSKSTAT(_KERNEL_TSK_TSKHDL2TCB(tskhdl), _KERNEL_TTS_DMT); _KERNEL_RMV_RDQ(tskhdl); } while (0)		/**< %jp{他タスクを終了する} */
#define _KERNEL_DSP_WAI_TSK(tskhdl)		do { _KERNEL_TSK_SET_TSKSTAT(_KERNEL_TSK_TSKHDL2TCB(tskhdl), _KERNEL_TTS_WAI); _KERNEL_RMV_RDQ(tskhdl); } while (0)		/**< %jp{自タスクを待ち状態にする} */
#define _KERNEL_DSP_WUP_TSK(tskhdl)		do { _KERNEL_TSK_SET_TSKSTAT(_KERNEL_TSK_TSKHDL2TCB(tskhdl), _KERNEL_TTS_RDY); _KERNEL_ADD_RDQ(tskhdl); } while (0)		/**< %jp{他タスクを待ち解除する} */

#else /* %jp{実行中はレディーキューから外す場合} */

#define _KERNEL_DSP_STA_TSK(tskhdl)		do { _KERNEL_TSK_SET_TSKSTAT(_KERNEL_TSK_TSKHDL2TCB(tskhdl), _KERNEL_TTS_RDY); _KERNEL_ADD_RDQ(tskhdl); } while (0)		/**< 他タスクを開始する */
#define _KERNEL_DSP_EXT_TSK(tskhdl)		do { _KERNEL_TSK_SET_TSKSTAT(_KERNEL_TSK_TSKHDL2TCB(tskhdl), _KERNEL_TTS_DMT);                          } while (0)		/**< 自タスクを終了する */
#define _KERNEL_DSP_TER_TSK(tskhdl)		do { _KERNEL_TSK_SET_TSKSTAT(_KERNEL_TSK_TSKHDL2TCB(tskhdl), _KERNEL_TTS_DMT); _KERNEL_RMV_RDQ(tskhdl); } while (0)		/**< 他タスクを終了する */
#define _KERNEL_DSP_WAI_TSK(tskhdl)		do { _KERNEL_TSK_SET_TSKSTAT(_KERNEL_TSK_TSKHDL2TCB(tskhdl), _KERNEL_TTS_WAI);                          } while (0)		/**< 自タスクを待ち状態にする */
#define _KERNEL_DSP_WUP_TSK(tskhdl)		do { _KERNEL_TSK_SET_TSKSTAT(_KERNEL_TSK_TSKHDL2TCB(tskhdl), _KERNEL_TTS_RDY); _KERNEL_ADD_RDQ(tskhdl); } while (0)		/**< 他タスクを待ち解除する */

#endif

#endif



#endif	/* _KERNEL_core__dsp_h__ */



/* end of file */
