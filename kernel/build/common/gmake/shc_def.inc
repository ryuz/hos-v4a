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
CC     = shc
ASM    = asmsh
LIBR   = optlnk

# %jp{拡張子定義}
C_EXT   = c
CPP_EXT = cpp
ASM_EXT = src
OBJ_EXT = obj
LIB_EXT = lib



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
