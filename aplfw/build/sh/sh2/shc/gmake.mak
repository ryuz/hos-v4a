# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for SH2
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# %jp{ターゲット名}
TARGET ?= hosaplfw

# %jp{ディレクトリ定義}
TOP_DIR           = ../../../../..
APLFW_DIR         = $(TOP_DIR)/aplfw
KERNEL_DIR        = $(TOP_DIR)/kernel
APLFW_MKINK_DIR   = $(APLFW_DIR)/build/common/gmake
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
MAKE_INC_DIR      = $(KERNEL_DIR)/build/common/gmake
OBJS_DIR          = objs_$(TARGET)

# %jp{共通設定読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{インクルードパス設定}
INC_DIRS += $(APLFW_DIR) $(KERNEL_DIR)/include


# %jp{オプションフラグ}
AFLAGS += -CPu=sh2
CFLAGS += -CPu=sh2
LFLAGS += 


# SCIデバイスドライバ追加
SCI_DIR   = $(APLFW_DIR)/driver/serial/renesas
SRC_DIRS += $(SCI_DIR)
CSRCS    += $(SCI_DIR)/scidrv_create.c				\
            $(SCI_DIR)/scidrv_delete.c				\
            $(SCI_DIR)/scidrv_open.c				\
            $(SCI_DIR)/scidrv_close.c				\
            $(SCI_DIR)/scidrv_iocontrol.c			\
            $(SCI_DIR)/scidrv_seek.c				\
            $(SCI_DIR)/scidrv_read.c				\
            $(SCI_DIR)/scidrv_write.c				\
            $(SCI_DIR)/scidrv_flush.c				\
            $(SCI_DIR)/scidrv_isr.c					\
            $(SCI_DIR)/scihal_create.c				\
            $(SCI_DIR)/scihal_delete.c				\
            $(SCI_DIR)/scihal_setup.c				\
            $(SCI_DIR)/scihal_stop.c				\
            $(SCI_DIR)/scihal_setspeed.c			\
            $(SCI_DIR)/scihal_recvchar.c			\
            $(SCI_DIR)/scihal_sendchar.c			\
            $(SCI_DIR)/scihal_enableinterrupt.c


all: makelib_all

clean: makelib_clean
	$(RM) -f *.lst


# %jp{shc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/shc_d.inc

# %jp{共通設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc
include $(APLFW_MKINK_DIR)/aplfwsrc.inc


# %jp{shc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/shc_r.inc

# %jp{依存関係定義読込み}
include $(APLFW_MKINK_DIR)/aplfwdep.inc


# end of file
