# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common depend file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# Include directories
INC_DIRS += $(APLFW_DIR)


# Source directories
SRC_DIRS += $(APLFW_DIR)/system/sysapi						\
            $(APLFW_DIR)/system/handle						\
            $(APLFW_DIR)/system/file						\
            $(APLFW_DIR)/system/memory						\
            $(APLFW_DIR)/system/shell						\
            $(APLFW_DIR)/library/container/mempol			\
            $(APLFW_DIR)/library/container/stmbuf			\


# C source files
CSRCS    += $(APLFW_DIR)/system/sysapi/sysapi.c				\
            $(APLFW_DIR)/system/handle/handle.c				\
            $(APLFW_DIR)/system/handle/hdlobj.c				\
            $(APLFW_DIR)/system/file/file.c					\
            $(APLFW_DIR)/system/memory/memory.c				\
            $(APLFW_DIR)/system/shell/shell.c				\
            $(APLFW_DIR)/library/container/mempol/mempol.c	\
            $(APLFW_DIR)/library/container/stmbuf/stmbuf.c	\


# end of file
