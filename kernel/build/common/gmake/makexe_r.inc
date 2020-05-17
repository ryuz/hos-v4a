# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2008 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{ルール}%en{rule}
# --------------------------------------


# %jp{カーネルライブラリ}%en{kernel library}
$(KERNEL_LIB): kernel_make


# %jp{実行ファイル生成}%en{make execution file}
.PHONY : makeexe_all
makeexe_all: $(KERNEL_LIB) makeexe_mkobjsdir $(CSRCS) $(ASRCS)


# %jp{クリーンナップ}%en{clean}
.PHONY : makeexe_clean
makeexe_clean:
	-$(CMD_RM) $(TARGET_LIB) $(OBJS)

makeexe_distclean:
	-$(CMD_RM) $(OBJS_DIR)/depend.inc
	-$(CMD_RMDIR) $(OBJS_DIR)


# %jp{オブジェクト出力ディレクトリ作成}%en{make object file firectory}
.PHONY : makeexe_mkobjsdir
makeexe_mkobjsdir:
	-$(CMD_MKDIR) $(OBJS_DIR)


# %jp{依存関係の生成}%en{make depend}
DEPFLAGS += -MM $(patsubst %,-I%,$(INC_DIRS))
.PHONY : makeexe_depend
makeexe_depend:
	-$(CMD_MKDIR) $(OBJS_DIR)
	-$(CMD_DEPEND) $(DEPFLAGS) $(CSRCS) | sed -e "s?\.o?\.$(EXT_OBJ)?g" | sed -e "s?^\(.*\):?$(OBJS_DIR)/\1:?g" > $(DEPEND_FILE)

# CSRCS に kernel_cfg.c などが含まれており、そのままだと誤動作するのでコメントアウト
# $(DEPEND_FILE): $(CSRCS)

-include $(OBJS_DIR)/depend.inc


# %jp{ソースのコピー}%en{sorce file copy}
ifneq ($(SRCCPYDIR),)
.PHONY : makeexe_srccpy
makeexe_srccpy:
	$(CMD_CP) -t $(SRCCPYDIR) $(ASRCS) $(CSRCS)
endif


# %jp{カーネル生成}%en{make kernel library}
.PHONY : kernel_make
kernel_make:
	$(MAKE) -C $(KERNEL_BUILD_DIR) $(KERNEL_MAKOPT)


# %jp{カーネルクリーン}%en{clean kernel}
.PHONY : kernel_clean
kernel_clean:
	$(MAKE) -C $(KERNEL_BUILD_DIR) $(KERNEL_MAKOPT) clean

# %jp{カーネル全クリーン}%en{clean distkernel}
.PHONY : kernel_distclean
kernel_distclean:
	$(MAKE) -C $(KERNEL_BUILD_DIR) $(KERNEL_MAKOPT) distclean

# %jp{カーネルdepend}%en{depend kernel}
.PHONY : kernel_depend
kernel_depend:
	$(MAKE) -C $(KERNEL_BUILD_DIR) $(KERNEL_MAKOPT) depend



# end of file
