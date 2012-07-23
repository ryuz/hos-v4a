# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2012 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ツール定義}%en{Tools}
CMD_CC     ?= sdcc
CMD_ASM    ?= sdcc
CMD_LIBR   ?= sdcclib
CMD_LINK   ?= sdcc
CMD_OBJCNV ?= sdcc


# %jp{拡張子定義}%en{file extensions}
EXT_C   ?= c
EXT_CPP ?= cpp
EXT_ASM ?= S
EXT_OBJ ?= rel
EXT_LIB ?= a
EXT_EXE ?= out
EXT_MOT ?= mot
EXT_HEX ?= hex
EXT_BIN ?= bin



# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}%en{common options}
CFLAGS +=


# %jp{デバッグオプションの定義}%en{debug options}
CFLAGS_DBG ?=


# %jp{最適化オプションの定義}%en{optimize options}
CFLAGS_OPT_NONE   ?=
CFLAGS_OPT_NORMAL ?=
CFLAGS_OPT_SIZE   ?= --opt-code-size
CFLAGS_OPT_SPEED  ?= --opt-code-speed



# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}%en{common options}
AFLAGS +=


# %jp{デバッグオプションの定義}%en{debug options}
AFLAGS_DBG ?= --debug


# %jp{最適化オプションの定義}%en{optimize options}
AFLAGS_OPT_NONE   ?=
AFLAGS_OPT_NORMAL ?=
AFLAGS_OPT_SIZE   ?=
AFLAGS_OPT_SPEED  ?=



# end of file
