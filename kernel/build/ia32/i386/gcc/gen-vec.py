#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  Hyper Operating System V4 Advance
#
# @file  gen-vec.py
# @brief %jp{x86 vector generator}%en{A tool to generate vector routines for x86.}
#
# Copyright (C) 1998-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
#

import argparse

exception_names = ("Divide Error",
             "Debug Exception Fault/Trap",
             "NMI Interrupt",
             "Breakpoint",
             "Overflow",
             "BOUND Range Exceeded",
             "Invalid Opcode (Undefined Opcode)",
             "Device Not Available (No Math Coprocessor)",
             "Double Fault",
             "Coprocessor Segment Overrun",
             "Invalid TSS",
             "Segment Not Present",
             "Stack-Segment Fault",
             "General Protection",
             "Page Fault",
             "Intel reserved",
             "x87 FPU Floating-Point Error (Math Fault)",
             "Alignment Check",
             "Machine Check",
             "SIMD Floating-Point Exception",
             "Virtualization Exception")

GENVEC_VECTOR_NR=256
GENVEC_EXCEPTION_NR=21
GENVEC_RESERVED_NR=32

DOUBLE_FAULT_VEC=8
INVALID_TSS_VEC=10
PAGE_FAULT_VEC=14
ALIGNMENT_CHECK_VEC=17
SYSCALL_VEC=0x90

def genheader(fname):
    """
    @brief Generate a head portion of IA32 vector routines

    :param fname: filename of the file.

    """

    print("""/* -*- mode: gas; coding:utf-8 -*- */
/**
 *  Hyper Operating System V4 Advance
 *
 * @file  %s
 * @brief %%jp{x86例外/割込みベクタ}
 *
 * @note  This file is generated automatically, don't edit by hand.
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#define _MACRO_ONLY

""" % (fname))

def genvec():
    """
    @brief Generate vector entries for IA32
    """

    print ("\t.text")
    print ("\t.extern\t_kernel_ia32_build_trap_context\n\n")
    for i in range(GENVEC_VECTOR_NR):
        if ( GENVEC_EXCEPTION_NR > i ):
            print ("/*  %s */" % exception_names[i])
        elif ( GENVEC_RESERVED_NR > i ):
            print ("/*  Intel reserved %d  */" % (i - ( GENVEC_EXCEPTION_NR - 1 ) ))
        else:
            print ("/*  External interrupt %d  */" % ( i - GENVEC_RESERVED_NR ))
        print (".global _kernel_vector_%03d" % (i) )
        print ("_kernel_vector_%03d:" % (i))
        if (not ( ( i == DOUBLE_FAULT_VEC )
                  or ( ( INVALID_TSS_VEC <= i ) and ( i <= PAGE_FAULT_VEC ) )
                  or ( i == ALIGNMENT_CHECK_VEC ) ) ):
                print ("\tpushl\t$0")
        print ("\tpushl\t$%d" % i)
        print ("\tjmp\t_kernel_ia32_build_trap_context")
        print ("")

"""
gen-vec.py [options]
usage: gen-vec.py -h -v outfile

options:
  --version                          版数情報表示
  -h, --help                         ヘルプ表示
arguments:
  outfile                            出力ファイル名
"""

parser = argparse.ArgumentParser(usage="%(prog)s [options]")
parser.add_argument('outfile', help='Output file name')

if __name__ == "__main__":
    args = parser.parse_args() # コマンドライン読み取り

    genheader(args.outfile)  # コメント部
    genvec()     # 割込みベクタ定義の生成
