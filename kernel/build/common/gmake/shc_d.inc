# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------




# %jp{ツール定義}%en{Tools}
CMD_CC     ?= shc
CMD_ASM    ?= asmsh
CMD_LIBR   ?= optlnk
CMD_LINK   ?= optlnk
CMD_OBJCNV ?= optlnk


# %jp{拡張子定義}%en{file extensions}
EXT_C   ?= c
EXT_CPP ?= cpp
EXT_ASM ?= src
EXT_OBJ ?= obj
EXT_LIB ?= lib
EXT_EXE ?= abs
EXT_MOT ?= mot
EXT_HEX ?= hex
EXT_BIN ?= bin



# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}%en{common options}
CFLAGS += -NOLOGO


# %jp{デバッグオプションの定義}%en{debug options}
CFLAGS_DBG = -DEBug


# %jp{最適化オプションの定義}%en{optimize options}
CFLAGS_OPT_NONE   = -OP=0
CFLAGS_OPT_SIZE   = -OP=1
CFLAGS_OPT_SPEED  = -OP=1
CFLAGS_OPT_NORMAL = -OP=1



# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}%en{common options}
AFLAGS += -NOLOGO


# %jp{デバッグオプションの定義}%en{debug options}
AFLAGS_DBG = -DEBug


# %jp{最適化オプションの定義}%en{optimize options}
AFLAGS_OPT_NONE  =
AFLAGS_OPT_SIZE  =
AFLAGS_OPT_SPEED =



# end of file
