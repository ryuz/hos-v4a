# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common include file for execution file
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{ルール}
# --------------------------------------


# %jp{カーネルライブラリ}
$(KERNEL_LIB): kernel_make


# %jp{all処理}
makeexe_all: $(KERNEL_LIB) mkdir_objs $(CSRCS) $(ASRCS)


# %jp{オブジェクト出力ディレクトリ作成}
mkdir_objs:
	-$(CMD_MKDIR) $(OBJS_DIR)


# %jp{クリーンナップ}
makeexe_clean:
	-$(CMD_RM) $(TARGET_LIB) $(OBJS)


# %jp{カーネル生成}
kernel_make:
	$(CMD_CD) $(KERNEL_BUILD_DIR)
	$(MAKE) DEBUG=$(KERNEL_DEBUG) ERRLEVEL=$(KERNEL_ERRLEVEL)
	$(CMD_CD) $(MAKEDIR)


# %jp{カーネル生成}
kernel_clean:
	$(CMD_CD) $(KERNEL_BUILD_DIR)
	$(MAKE) DEBUG=$(KERNEL_DEBUG) ERRLEVEL=$(KERNEL_ERRLEVEL) clean
	$(CMD_CD) $(MAKEDIR)



# end of file
