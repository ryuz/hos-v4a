# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common depend file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# Directories
INC_DIRS += $(APLFW_DIR)/system/sysapi				\
            $(APLFW_DIR)/system/handle				\
            $(APLFW_DIR)/system/file				\
            $(APLFW_DIR)/system/memory				\
            $(APLFW_DIR)/system/shell				\


SRC_DIRS += $(APLFW_DIR)/system/sysapi				\
            $(APLFW_DIR)/system/handle				\
            $(APLFW_DIR)/system/file				\
            $(APLFW_DIR)/system/memory				\
            $(APLFW_DIR)/system/shell				\


# C source files
CSRCS    += $(APLFW_DIR)/system/sysapi/sysapi.c		\
            $(APLFW_DIR)/system/handle/handle.c		\
            $(APLFW_DIR)/system/handle/hdlobj.c		\
            $(APLFW_DIR)/system/file/file.c			\


# end of file
