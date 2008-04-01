# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


.SUFFIXES :
.SUFFIXES : .ro .c .as


# %jp{コマンド定義}%en{Tools}
!ifndef CMD_CC
CMD_CC   = cc103S
!endif
!ifndef CMD_ASM
CMD_ASM  = cc103S
!endif
!ifndef CMD_LIBR
CMD_LIBR = ar103S
!endif
!ifndef CMD_LINK
CMD_LINK = cc103S
!endif
!ifndef CMD_OBJCNV
CMD_OBJCNV = xcv103
!endif


# %jp{拡張子定義}
EXT_C   = c
EXT_CPP = cpp
EXT_ASM = as
EXT_OBJ = ro
EXT_LIB = l
EXT_EXE = x
EXT_MOT = mot
EXT_HEX = hex
EXT_BIN = bin



# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}
CFLAGS = $(CFLAGS) -c -g

# %jp{リリースモードオプションの定義}
CFLAGS_REL = 

# %jp{デバッグモードオプションの定義}
CFLAGS_DBG = 

# %jp{最適化オプションの定義}
CFLAGS_OPT_NONE   = 
CFLAGS_OPT_NORMAL = -O
CFLAGS_OPT_SIZE   = -Os
CFLAGS_OPT_SPEED  = -Ot


# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}
AFLAGS = $(AFLAGS) -c

# %jp{リリースモードオプションの定義}
AFLAGS_REL = 

# %jp{デバッグモードオプションの定義}
AFLAGS_DBG = -g

# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE   =
CFLAGS_OPT_NORMAL =
AFLAGS_OPT_SIZE   =
AFLAGS_OPT_SPEED  =


# end of file
