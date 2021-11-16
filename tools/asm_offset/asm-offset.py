#!/usr/bin/env python3
#
#  Hyper Operating System V4 Advance
#
# @file  asm-offset.py
# @brief %jp{データ構造のオフセットアドレス定義生成ツール}%en{A tool to generate the offset addresses of members in data structures.}
#
# Copyright (C) 1998-2021 by Project HOS
# http://sourceforge.jp/projects/hos/
#

import sys, codecs, os, re, datetime
import argparse
import pathlib

"""
asm-offset [options]
usage: asm-offset -h -v infile outfile top_dir

options:
  --version                          版数情報表示
  -h, --help                         ヘルプ表示
  -v, --verbose                      冗長モードに設定
arguments:
  infile                             入力ファイルへのパス
  outfile                            出力ファイルへのパス
  top_dir                            トップディレクトリへのパス
"""

parser = argparse.ArgumentParser(usage="%(prog)s [options]")
parser.add_argument("-v", "--verbose", action="store_true", help="set verbose mode")
parser.add_argument('infile', help='Input file path')
parser.add_argument('outfile', help='Output file path')
parser.add_argument('top_dir', help='top directory path')


class asmOffset:
    def __init__(self):
        self.cmdname = 'asm_offset'
        self.infile = None
        self.outfile = None
        self.top_dir = None
        self.verbose = False
        self.headdef = None
        self.args = parser.parse_args() # コマンドライン読み取り
        self.readConfig() # コマンドラインの設定を反映
    def setVerbose(self):
        self.verbose = True
    def getVerbose(self):
        return self.verbose;
    def setConfigFile(self, file):
        self.configfile = file
    def getConfigFile(self):
        return self.configfile
    def getInfile(self):
        return self.infile
    def getOutfile(self):
        return self.outfile
    def getHeaderFileDefinition(self, outfile, topdir):
        # 出力先ファイルの絶対パスを得る
        abs_path = os.path.abspath(outfile)
        # 出力先ファイルのトップディレクトリからの相対パスを得る
        rel_path = os.path.relpath(abs_path, start=os.path.abspath(topdir))
        # ファイル名を得る
        base_name = os.path.basename(rel_path)
        # ディレクトリ名を得る
        dir_name = os.path.dirname(rel_path)
        # ディレクトリデリミタを__に置き換える
        def_name = dir_name.replace(os.sep, '__')
        # ..を_parent_dir_に置き換える
        def_name = def_name.replace('..', '_parent_dir_')
        # .を_current_dir_に置き換える
        def_name = def_name.replace('.', '_current_dir_')
        #_KERNELと末尾の__を追加
        def_name = '_KERNEL__' + def_name + '__' + base_name.replace('.','_') + '__'
        return def_name
    ##
    # @brief %jp{ヘッダファイルの冒頭部分を出力}%en{Output head part of the header file}
    # @param[in] fh ヘッダファイル書込み用ファイルハンドラ
    #
    def outputHead(self, fh):
        fh.write("""/**
 *  Hyper Operating System V4 Advance
 *
 * @file %s
 * @brief Structure offset definitions
 * @note  This file is generated automatically, don't edit by hand.
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#if !defined(%s)
#define %s

""" % ( os.path.basename(self.outfile), self.headdef, self.headdef) )

    ##
    # @brief %jp{アセンブラオフセットヘッダ生成}
    # %en{Generate offset definitions for assembler files.}
    #
    #
    # asm-offset-helper.hのマクロが
    #
    # .ascii "@ASM_OFFSET@Cマクロ名[空白]マクロ定義値[空白]マクロ定義値算出式"
    #
    # というインラインアセンブラ文を出力する
    #
    # 例:.ascii "@ASM_OFFSET@TI_SIZE $32 sizeof(struct _thread_info)"
    #
    # 本関数は, @ASM_OFFSET@を含む行を取り出し以下を行い
    # Cプリプロセッサのマクロ定義を出力する
    #
    # 1) 行の先頭と末尾の空白/改行を削除
    #    例:\s*.ascii "@ASM_OFFSET@TI_SIZE $32 sizeof(struct _thread_info)"\s*
    #     =>.ascii "@ASM_OFFSET@TI_SIZE $32 sizeof(struct _thread_info)"
    #
    # 2) ".ascii空白の繰り返し"部分を削除
    #    例:.ascii "@ASM_OFFSET@TI_SIZE $32 sizeof(struct _thread_info)"
    #     =>"@ASM_OFFSET@TI_SIZE $32 sizeof(struct _thread_info)"
    #
    # 3) @ASM_OFFSET@を削除
    #    例:"@ASM_OFFSET@TI_SIZE $32 sizeof(struct _thread_info)"
    #     =>"TI_SIZE $32 sizeof(struct _thread_info)"
    #
    # 4) 前後の"を削除
    #    例:"TI_SIZE $32 sizeof(struct _thread_info)"
    #     =>TI_SIZE $32 sizeof(struct _thread_info)
    #
    # 5) 残る文字列を空白で区切って分割し, マクロ名,
    #    定義値内に$があればを削除し, 定義値算出式文字列(コメント)を取り出し,
    #    Cプリプロセサ定義を出力する
    #    例:TI_SIZE $32 sizeof(struct _thread_info)
    #     =>#define TI_SIZE (32)  /*  sizeof(struct _thread_info)  */
    #
    def genAsmOffset(self):

        with open(self.outfile, "w") as fh:
            with open(self.infile, 'r') as f:
                self.headdef = self.getHeaderFileDefinition(self.outfile, self.top_dir)
                self.outputHead(fh)
                for line in f:
                    if (re.search(r'@ASM_OFFSET@', line)):

                        # 1-1) 行の先頭と末尾の空白を削除
                        line = line.lstrip()
                        line = line.rstrip()

                        # 1-2) 行の先頭と末尾の改行を削除
                        line = line.rstrip('\r')
                        line = line.rstrip('\n')

                        # 2) ".ascii空白の繰り返し"部分を削除,
                        line = re.sub(".ascii\s+","",line)

                        # 3) @ASM_OFFSET@を削除
                        line = line.replace("@ASM_OFFSET@","")

                        # 4) 前後の"を削除
                        line = line.lstrip('"')
                        line = line.rstrip('"')

                        # 5-1) 残る文字列を空白で区切って分割
                        # defs[0] マクロ名
                        # defs[1] 定義値(x64の場合, $文字含む)
                        # defs[2] 定義値算出式文字列(コメント)
                        defs = re.split('\s+', line ,2)

                        # 5-2) Cプリプロセサ定義を出力する
                        # #define マクロ名 ($を取り除いた定義値)
                        #                     /*< 定義値算出式 */
                        # というマクロ定義が出力される
                        fh.write("#define %s (%s) /*< %s */\n" %
                                 (defs[0], re.sub('\$*', '',
                                                  defs[1]), defs[2]))
                fh.write("\n\n")
                fh.write("#endif  /*  %s  */\n" % (self.headdef) )
                fh.write("\n\n")
                fh.write("/* end of file */\n")
        return

    ##
    # @brief %jp{コマンドラインパラメタ解析}
    # %en{Parse command line parameters.}
    #
    def readConfig(self):

        # 冗長表示フラグの設定
        if self.args.verbose:
            self.setVerbose()

        # 入力ファイルが存在し, 通常ファイルだった場合は指定されたファイルを入力ファイルとする
        if self.args.infile and os.path.exists(self.args.infile) and os.path.isfile(self.args.infile):
            self.infile = self.args.infile
        else:
            print("Can not open input file: %s" % (self.args.infile), file=sys.stderr)
            sys.exit(1)

        # 出力ファイル指定時は, 指定されたファイルを出力ファイルとする
        if self.args.outfile:
            self.outfile = self.args.outfile
        else:
            print("Can not open output file: %s" % (self.args.outfile), file=sys.stderr)
            sys.exit(1)

        # トップディレクトリが存在し, ディレクトリであることを確認する
        if self.args.top_dir and os.path.exists(self.args.top_dir) and os.path.isdir(self.args.top_dir):
            self.top_dir = self.args.top_dir
        else:
            print("Can not find the kernel directory or it is not a directory: %s" % (self.args.top_dir), file=sys.stderr)
            sys.exit(1)

if __name__ == '__main__':

    obj = asmOffset()  # オブジェクト生成
    obj.genAsmOffset() # ヘッダ生成



# end of file
