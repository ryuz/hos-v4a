# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2-sample
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{�e��ݒ�}{setting}
# --------------------------------------

# %jp{�^�[�Q�b�g��}%en{target name}
TARGET ?= sample


# %jp{�A�[�L�e�N�`����`}%en{architecture}
ARCH_NAME ?= sh2
ARCH_CC   ?= shc


# %jp{�f�B���N�g����`}%en{directories}
OS_DIR            = ../../../..
KERNEL_DIR        = $(OS_DIR)/kernel
KERNEL_CFGRTR_DIR = $(OS_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/sh/sh2/shc


# %jp{�R���t�B�M�����[�^��`}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-$(ARCH_NAME)


# %jp{���ʒ�`�Ǎ���}%jp{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


ifeq ($(MEMMAP),ram)
# %jp{RAM���s(���j�^�v���O�������p��z��)}%en{external RAM}
TARGET := $(TARGET)_ram
SECTION_VECT ?= 0FFFFE160
SECTION_RO  ?= 000400400
SECTION_RW  ?= 000410000
else
# %jp{ROM�Ă�����ꍇ}%en{internal ROM}
TARGET := $(TARGET)
SECTION_VECT ?= 000000000
SECTION_RO  ?= 000000400
SECTION_RW  ?= 0FFFFE000
endif


# %jp{�p�X�ݒ�}%en{add source directories}
INC_DIRS += . ..
SRC_DIRS += . ..


# %jp{�I�v�V�����t���O}%en{option flags}
AFLAGS  = -CPu=sh2
CFLAGS  = -CPu=sh2
LNFLAGS = 


# %jp{�R���p�C���ˑ��̐ݒ�Ǎ���}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{���s�t�@�C�������p�ݒ�Ǎ���}%en{definitions for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc


# %jp{�o�̓t�@�C����}%en{output files}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)

# %jp{C���C�u�������̎w��}%en{std library}
STD_LIBS = stdlib.lib




# --------------------------------------
#  %jp{�\�[�X�t�@�C��}%en{source files}
# --------------------------------------

# %jp{�A�Z���u���t�@�C���̒ǉ�}%en{assembry sources}
ASRCS += ./vcttbl.src
ASRCS += ./startup.src


# %jp{C����t�@�C���̒ǉ�}%en{C sources}
CSRCS += ./dbsct.c
CSRCS += ../kernel_cfg.c
CSRCS += ../main.c
CSRCS += ../sample.c
CSRCS += ../ostimer.c
CSRCS += ../sci1.c


# %jp{���C�u�����̒ǉ�}%en{library}
LIBS  += $(STD_LIBS)




# --------------------------------------
#  %jp{���[����`}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
.PHONY : all
all: makeexe_all $(TARGET_EXE) $(TARGET_MOT)

# %jp{�N���[��}%en{clean}
.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../kernel_cfg.c ../kernel_id.h

# %jp{�ˑ��֌W�X�V}%en{depend}
.PHONY : depend
depend: makeexe_depend

# %jp{�\�[�X�ꊇ�R�s�[}%en{source files copy}
.PHONY : srccpy
srccpy: makeexe_srccpy

# %jp{�J�[�l�����ƃN���[��}%en{mostlyclean}
.PHONY : mostlyclean
mostlyclean: clean kernel_clean


# %jp{�W�����C�u����}%en{std library}
$(STD_LIBS):
	lbgsh -OUTPut=$(STD_LIBS) -CPu=sh2 -REent


# %jp{�R���t�B�M�����[�^���s}%en{configurator}
../kernel_cfg.c ../kernel_id.h: ../system.cfg $(KERNEL_CFGRTR)
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


# %jp{���s�t�@�C�������p�ݒ�Ǎ���}%en{setting for execute file}
include $(KERNEL_MAKINC_DIR)/makeexe.inc

# %jp{shc�p�̃��[����`�Ǎ���}
include $(KERNEL_MAKINC_DIR)/shc_r.inc



# --------------------------------------
#  %jp{�ˑ��֌W}%en{dependency}
# --------------------------------------

$(OBJS_DIR)/sample.obj: ../sample.c ../kernel_id.h


# end of file
