# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


.SUFFIXES :
.SUFFIXES : .obj .c .src


# %jp{ツール定義}%en{Tools}
!ifndef CMD_CC
CMD_CC = shc
!endif
!ifndef CMD_ASM
CMD_ASM = asmsh
!endif
!ifndef CMD_LIBR
CMD_LIBR = optlnk
!endif
!ifndef CMD_LINK
CMD_LINK = optlnk
!endif
!ifndef CMD_OBJCNV
CMD_OBJCNV = optlnk
!endif


# %jp{拡張子定義}
EXT_C   = c
EXT_CPP = cpp
EXT_ASM = src
EXT_OBJ = obj
EXT_LIB = lib
EXT_EXE = abs
EXT_MOT = mot
EXT_HEX = hex
EXT_BIN = bin



# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}
CFLAGS = $(CFLAGS) -NOLOGO -NOList


# %jp{インクルードパスオプションの定義}
!ifdef INC_DIRS
INC_DIRS = $(INC_DIRS:	= )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = @$(INC_DIRS)@
INC_DIRS = $(INC_DIRS:@ =)
INC_DIRS = $(INC_DIRS: @=)
INC_DIRS = $(INC_DIRS:@=)

CFLAGS_INC = -I=$(INC_DIRS: =,)
!endif

# %jp{マクロ定義オプションの定義}
!ifdef C_DEFS
C_DEFS = $(C_DEFS:	= )
C_DEFS = $(C_DEFS:  = )
C_DEFS = $(C_DEFS:  = )
C_DEFS = $(C_DEFS:  = )
C_DEFS = @$(C_DEFS)@
C_DEFS = $(C_DEFS:@ =)
C_DEFS = $(C_DEFS: @=)
C_DEFS = $(C_DEFS:@=)

CFLAGS_DEF = -DEF=$(C_DEFS: =,)
!endif

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
AFLAGS = $(AFLAGS) -NOLOGO


# %jp{インクルードパスオプションの定義}
!ifdef INC_DIRS
AFLAGS_INC = -I=$(INC_DIRS: =,)
!endif


# %jp{マクロ定義オプションの定義}
!ifdef A_DEFS
A_DEFS = $(A_DEFS:	= )
A_DEFS = $(A_DEFS:  = )
A_DEFS = $(A_DEFS:  = )
A_DEFS = $(A_DEFS:  = )
A_DEFS = @$(A_DEFS)@
A_DEFS = $(A_DEFS:@ =)
A_DEFS = $(A_DEFS: @=)
A_DEFS = $(A_DEFS:@=)

AFLAGS_DEF = -DEF=$(A_DEFS: =,)
!endif


# %jp{デバッグオプションの定義}
AFLAGS_DBG = -DEBug


# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE  =
AFLAGS_OPT_SIZE  =
AFLAGS_OPT_SPEED =



# end of file
