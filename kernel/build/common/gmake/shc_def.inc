# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{特殊文字定義}
comma:= ,
empty:=
space:= $(empty) $(empty)


# %jp{ツール定義}%en{Tools}
CMD_CC     ?= shc
CMD_ASM    ?= asmsh
CMD_LIBR   ?= optlnk
CMD_LINK   ?= optlnk
CMD_OBJCNV ?= optlnk

# %jp{拡張子定義}
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

# %jp{共通オプションの設定}
CFLAGS += -NOLOGO

# %jp{インクルードパスオプションの定義}
CFLAGS_INC = -I=$(subst $(space),$(comma),$(strip $(INC_DIRS)))

# %jp{マクロ定義オプションの定義}
CFLAGS_DEF = 

# %jp{デバッグオプションの定義}
CFLAGS_DBG = -DEBug

# %jp{最適化オプションの定義}
CFLAGS_OPT_NONE  = -OP=0
CFLAGS_OPT_SIZE  = -OP=1
CFLAGS_OPT_SPEED = -OP=1


# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}
AFLAGS += -NOLOGO

# %jp{インクルードパスオプションの定義}
AFLAGS_INC = -I=$(subst $(space),$(comma),$(strip $(A_INC)))

# %jp{マクロ定義オプションの定義}
AFLAGS_DEF = 

# %jp{デバッグオプションの定義}
AFLAGS_DBG = -DEBug

# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE  =
AFLAGS_OPT_SIZE  =
AFLAGS_OPT_SPEED =


# end of file
