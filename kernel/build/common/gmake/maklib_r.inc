# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{ルール}%en{Rules}
# --------------------------------------

# %jp{ライブラリ生成}%en{library}
.PHONY : makelib_all
makelib_all: $(CSRCS) $(ASRCS) makelib_mkobjsdir $(TARGET_LIB)


# %jp{一括処理}%en{batch build}
.PHONY : makelib_batch
makelib_batch: $(CSRCS) $(ASRCS) makelib_mkobjsdir batch_asm batch_c $(TARGET_LIB)


# %jp{クリーンナップ}%en{clean}
.PHONY : makelib_clean
makelib_clean:
	$(CMD_RM) -f $(TARGET_LIB) $(OBJS)


# %jp{依存関係の生成}%en{depend}
DEPFLAGS += -MM $(patsubst %,-I%,$(INC_DIRS))
.PHONY : makelib_depend
makelib_depend: makelib_mkobjsdir
	$(CMD_DEPEND) $(DEPFLAGS) $(CSRCS) | sed -e 's?\.o?\.$(EXT_OBJ)?g' | sed -e 's?^\(.*\):?$(OBJS_DIR)/\1:?g' > $(OBJS_DIR)/depend.inc

-include $(OBJS_DIR)/depend.inc


# %jp{オブジェクト出力ディレクトリ作成}%en{objects directory}
.PHONY : makelib_mkobjsdir
makelib_mkobjsdir:
	$(CMD_MKDIR) -p $(OBJS_DIR)


# %jp{ソースのコピー}%en{spurce files copy}
ifneq ($(SRCCPYDIR),)
.PHONY : makelib_srccpy
makelib_srccpy:
	$(CMD_CP) -t $(SRCCPYDIR) $(ASRCS) $(CSRCS)
endif



# end of file
