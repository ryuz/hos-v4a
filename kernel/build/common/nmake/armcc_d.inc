# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


.SUFFIXES :
.SUFFIXES : .o .c .s


# %jp{ツール定義}%en{Tools}
!ifndef CMD_CC
CMD_CC   = armcc
!endif
!ifndef CMD_ASM
CMD_ASM  = armasm
!endif
!ifndef CMD_LIBR
CMD_LIBR = armar
!endif
!ifndef CMD_LINK
CMD_LINK = armlink
!endif
!ifndef CMD_OBJCNV
CMD_OBJCNV = fromelf
!endif


# %jp{拡張子定義}%en{file extensions}
EXT_C   = c
EXT_CPP = cpp
EXT_ASM = s
EXT_OBJ = o
EXT_LIB = a
EXT_EXE = axf
EXT_MOT = mot
EXT_HEX = hex
EXT_BIN = bin



# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}$en{common options}
CFLAGS = -c --apcs /interwork


# %jp{デバッグオプションの定義}$en{debug options}
CFLAGS_DBG = -g


# %jp{最適化オプションの定義}$en{optimize options}
CFLAGS_OPT_NONE   = -O0
CFLAGS_OPT_SIZE   = -O3 -Ospace
CFLAGS_OPT_SPEED  = -O3 -Otime
CFLAGS_OPT_NORMAL = -O3



# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}$en{common options}
AFLAGS = $(AFLAGS) --apcs /interwork


# %jp{デバッグオプションの定義}$en{debug options}
AFLAGS_DBG = -g


# %jp{最適化オプションの定義}$en{optimize options}
AFLAGS_OPT_NONE  =
AFLAGS_OPT_SIZE  =
AFLAGS_OPT_SPEED =



# end of file
