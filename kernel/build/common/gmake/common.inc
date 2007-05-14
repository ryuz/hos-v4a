# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# --------------------------------------
#  %jp{共通設定}
# --------------------------------------

# %jp{特殊文字定義}
comma:= ,
empty:=
space:= $(empty) $(empty)

# %jp{ツール定義}%en{Tools}
CMD_ECHO   ?= echo
CMD_MKDIR  ?= mkdir
CMD_CP     ?= cp
CMD_MV     ?= mv
CMD_RM     ?= rm
CMD_DEPEND ?= gcc


# end of file
