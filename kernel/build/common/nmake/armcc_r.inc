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
!if "$(INC_DIRS)" != ""
CFLAGS_INC = -I$(INC_DIRS: = -I)
!endif
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
!if "$(C_DEFS)" != ""
CFLAGS_DEF = -D$(C_DEFS: = -D)
!endif
!endif


# %jp{アセンブリ言語インクルードパスオプションの定義}%en{Assembler include path}
!ifdef INC_DIRS
!if "$(INC_DIRS)" != ""
AFLAGS_INC = -I$(INC_DIRS: = -I)
!endif
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
!if "$(A_DEFS)" != ""
AFLAGS_DEF = 
!endif
!endif


# %jp{基本オプション設定}{Options marged}
CFLAGS = $(CFLAGS) $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS = $(AFLAGS) $(AFLAGS_INC) $(AFLAGS_DEF)



# --------------------------------------
#  %jpルール定義}%en{Rules}
# --------------------------------------

# %jp{実行ファイル生成}%en{Executable file}
!if "$(TARGET_EXE)" != ""
$(TARGET_EXE): $(OBJS)
	$(CMD_LINK) $(LNFLAGS) -o $(TARGET_EXE) $(OBJS) $(LIBS)
!endif


# %jp{モトローラS形式ファイル生成}%en{Motorola S format file}
!if "$(TARGET_MOT)" != ""
$(TARGET_MOT): $(TARGET_EXE)
	$(CMD_OBJCNV) --m32 --output $(TARGET_MOT) $(TARGET_EXE)
!endif


# %jp{インテルHEX形式ファイル生成}%en{Intel HEX format file}
!if "$(TARGET_HEX)" != ""
$(TARGET_HEX): $(TARGET_EXE)
	$(CMD_OBJCNV) --i32 --output $(TARGET_HEX) $(TARGET_EXE)
!endif


# %jp{プレーンバイナリ形式ファイル生成}%en{Plain Binary}
!if "$(TARGET_BIN)" != ""
$(TARGET_BIN): $(TARGET_EXE)
	$(CMD_OBJCNV) --bin --output $(TARGET_BIN) $(TARGET_EXE)
!endif


# %jp{ライブラリ生成}%en{Library}
!if "$(TARGET_LIB)" != ""
$(TARGET_LIB): $(OBJS)
	$(CMD_LIBR) $(ARFLAGS) --create $(TARGET_LIB) $(OBJS)
!endif


# %jp{Cコンパイル}%en{C Compile}
{$(OBJS_DIR)}.c{$(OBJS_DIR)}.o :
	$(CMD_CC) $(CFLAGS) -c $< -o $@


# %jp{アセンブル}%en{Assemble}
{$(OBJS_DIR)}.s{$(OBJS_DIR)}.o :
	$(CMD_ASM) $(AFLAGS) $< -o $@



# end of file
