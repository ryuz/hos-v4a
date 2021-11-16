/**
 *  Hyper Operating System V4 Advance
 *
 * @file  asm_offset_helper.h
 * @brief %jp{構造体オフセットマクロ出力}%en{Offset address for assembler codes.}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#if !defined(_TOOLS__ASM_OFFSET__ASM_OFFSET_HELPER_H)
#define _TOOLS__ASM_OFFSET__ASM_OFFSET_HELPER_H

#define _IN_ASM_OFFSET 1  /*  アセンブラ用オフセット定義出力処理中であることを定義  */

/**
   構造体中のメンバオフセットを算出する
   @param[in] _type   構造体の型
   @param[in] _member _type型構造体中のメンバ名
   @return type型構造体中のメンバmemberのオフセットアドレス
 */
#define __asm_offsetof(_type, _member) (&((_type *)0)->_member)

/**
   第1引数で指定されたマクロ名で第2引数で指定された値を定義する
   @param[in] _mac マクロ名
   @param[in] _val 値(例えば, sizeof(データ構造型) などC言語固有の値算出式)
   @note 本マクロ自身は, 指定されたシンボルのデータサイズを表すアスキー文字列
         定義アセンブラ文を出力する。具体的には,
	 .ascii "@ASM_OFFSET@シンボル名 アドレス値 アドレス値算出式"
         を出力する。上記出力を$(TOP_DIR)/tools/asm_offset/asm_offset.pyが
	 $(OBJS_DIR)asm_off.hなどの出力先ヘッダファイル中のマクロ定義に変換する。
 */
#define DEFINE_VAL(_mac, _val) 						  \
        asm volatile("\n.ascii \"@ASM_OFFSET@" #_mac " %0 " #_val "\"" : : "i" (_val)) \


/**
   第2引数で指定された構造体中にあるメンバのオフセットアドレスを
   第1引数で指定されたマクロ名で定義する。 メンバ名は, 第3引数で指定する。
   @param[in] _mac マクロ名
   @param[in] _str 構造体タグ名
   @param[in] _mem 構造体_str中のメンバ名
   @note  本マクロ自身は, 構造体メンバオフセットアドレスを表すアスキー文字列定義
   アセンブラ文を出力する。具体的には,
   .ascii "@ASM_OFFSET@シンボル名 メンバオフセットアドレス アドレス値算出式"
   を出力する。上記出力を$(TOP_DIR)/tools/asm_offset/asm_offset.pyが
   $(OBJS_DIR)asm_off.hなどの出力先ヘッダファイル中のマクロ定義に変換する。
 */
#define OFFSET(_mac, _str, _mem) \
	DEFINE_VAL(_mac, __asm_offsetof(struct _str, _mem))


#endif  /*  _TOOLS__ASM_OFFSET__ASM_OFFSET_HELPER_H  */



/* end of file */
