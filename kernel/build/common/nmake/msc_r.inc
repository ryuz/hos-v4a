# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------




# --------------------------------------
#  %jp{オプション展開}%en{options}
# --------------------------------------

# %jp{C言語インクルードパスオプションの定義}%en{C-compiler include path}
!ifdef INC_DIRS
INC_DIRS = $(INC_DIRS:	= )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = @$(INC_DIRS)@
INC_DIRS = $(INC_DIRS:@ =)
INC_DIRS = $(INC_DIRS: @=)
INC_DIRS = $(INC_DIRS:@=)
CFLAGS_INC = /I$(INC_DIRS: = /I)
!endif


# %jp{C言語マクロ定義オプションの定義}%en{C-compiler define macros}
!ifdef C_DEFS
C_DEFS = $(C_DEFS:	= )
C_DEFS = $(C_DEFS:  = )
C_DEFS = $(C_DEFS:  = )
C_DEFS = $(C_DEFS:  = )
C_DEFS = @$(C_DEFS)@
C_DEFS = $(C_DEFS:@ =)
C_DEFS = $(C_DEFS: @=)
C_DEFS = $(C_DEFS:@=)
CFLAGS_DEF = /D$(C_DEFS: = /D)
!endif


# %jp{アセンブリ言語インクルードパスオプションの定義}%en{Assembler include path}
!ifdef INC_DIRS
AFLAGS_INC = -I=$(INC_DIRS: =,)
!endif


# %jp{アセンブリ言語マクロ定義オプションの定義}%en{Assembler define macros}
!ifdef A_DEFS
A_DEFS = $(A_DEFS:	= )
A_DEFS = $(A_DEFS:  = )
A_DEFS = $(A_DEFS:  = )
A_DEFS = $(A_DEFS:  = )
A_DEFS = @$(A_DEFS)@
A_DEFS = $(A_DEFS:@ =)
A_DEFS = $(A_DEFS: @=)
A_DEFS = $(A_DEFS:@=)
AFLAGS_DEF = /D$(A_DEFS: = /D)
!endif


# %jp{基本オプション設定}{Options marged}
CFLAGS = $(CFLAGS) $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS = $(AFLAGS) $(AFLAGS_INC) $(AFLAGS_DEF)



# --------------------------------------
#  %jpルール定義}%en{Rules}
# --------------------------------------

# %jp{実行ファイル生成}%en{Executable file}
!ifdef TARGET_EXE
$(TARGET_EXE): $(OBJS)
	$(CMD_LINK) $(LNFLAGS) $(OBJS) $(LIBS) /Fe$(TARGET_EXE)
!endif


# %jp{ライブラリ生成}%en{Library}
!ifdef TARGET_LIB
$(TARGET_LIB): $(OBJS)
	$(CMD_LIBR) /OUT:$(TARGET_LIB) $(OBJS)
!endif


# %jp{Cコンパイル}%en{C Compile}
{$(OBJS_DIR)}.c{$(OBJS_DIR)}.obj :
	$(CMD_CC) $(CFLAGS) $< /Fo$@


# %jp{アセンブル}%en{Assemble}
{$(OBJS_DIR)}.asm{$(OBJS_DIR)}.obj :
	$(CMD_ASM) $(AFLAGS) $< /Fo=$@



# end of file
