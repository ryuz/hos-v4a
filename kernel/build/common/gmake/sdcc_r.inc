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
ifneq ($(INC_DIRS),)
CFLAGS_INC ?= $(patsubst %,-I%,$(INC_DIRS))
endif


# %jp{C言語マクロ定義オプションの定義}%en{C-compiler define macros}
ifneq ($(C_DEFS),)
CFLAGS_DEF ?= $(patsubst %,-D%,$(C_DEFS))
endif


# %jp{アセンブリ言語インクルードパスオプションの定義}%en{Assembler include path}
ifneq ($(INC_DIRS),)
AFLAGS_INC ?= $(patsubst %,-I%,$(INC_DIRS))
endif


# %jp{アセンブリ言語マクロ定義オプションの定義}%en{Assembler define macros}
ifneq ($(A_DEFS),)
AFLAGS_DEF ?= $(patsubst %,-D%,$(A_DEFS))
endif


# %jp{オプション統合}{Options marged}
CFLAGS += $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS += $(AFLAGS_INC) $(AFLAGS_DEF)



# --------------------------------------
#  %jpルール定義}%en{Rules}
# --------------------------------------


# %jp{実行ファイル生成}%en{Executable file}
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_LINK) $(LNFLAGS) $(OBJS) $(LIBS) $(LNFLAGS2) -o $(TARGET_EXE)


# %jp{モトローラS形式ファイル生成}%en{Motorola S format file}
$(TARGET_MOT): $(TARGET_EXE)
	$(CMD_OBJCNV) -O srec $(TARGET_EXE) $(TARGET_MOT)


# %jp{インテルHEX形式ファイル生成}%en{Intel HEX format file}
$(TARGET_HEX): $(TARGET_EXE)
	$(CMD_OBJCNV) -O ihex $(TARGET_EXE) $(TARGET_HEX)


# %jp{プレーンバイナリ形式ファイル生成}%en{Plain Binary}
$(TARGET_BIN): $(TARGET_EXE)
	$(CMD_OBJCNV) -O binary $(TARGET_EXE) $(TARGET_BIN)


# %jp{ライブラリ生成}%en{Library}
$(TARGET_LIB): $(OBJS)
	$(CMD_LIBR) $(ARFLAGS) -r $(TARGET_LIB) $(OBJS)


# %jp{Cコンパイル}%en{C Compile}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_C)
	$(CMD_CC) $(CFLAGS) -c $< -o $@


# %jp{アセンブル}%en{Assemble}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_ASM)
	$(CMD_ASM) $(AFLAGS) -c $< -o $@


# %jp{一括コンパイル}%en{batch cmpile}
batch_c:
	$(CMD_CC) $(CFLAGS) -c $(CSRCS)
	$(CMD_MV) -f $(addsuffix .$(EXT_OBJ), $(basename $(notdir $(CSRCS)))) $(OBJS_DIR)


# %jp{一括アセンブル}%en{batch cmpile}
batch_asm:
	$(CMD_CC) $(CFLAGS) -c $(ASRCS)
	$(CMD_MV) -f $(addsuffix .$(EXT_OBJ), $(basename $(notdir $(ASRCS)))) $(OBJS_DIR)



# end of file
