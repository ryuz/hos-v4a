

TARGET ?= sample

ifeq ($(ROM),Yes)
TARGET := $(TARGET)_rom
ADDR_VECT ?= 000000000
ADDR_ROM  ?= 000000400
ADDR_RAM  ?= 000400000
else
ADDR_VECT ?= 000400000
ADDR_ROM  ?= 000400400
ADDR_RAM  ?= 000410000
endif

# ディレクトリ
OS_DIR      = ../../../../..
KERNEL_DIR = $(OS_DIR)/kernel
APLFW_DIR  = $(OS_DIR)/aplfw

KERNEL_INC_DIR  = $(KERNEL_DIR)/include
APLFW_INC_DIR   = $(APLFW_DIR)

KERNEL_BUILD_DIR = $(KERNEL_DIR)/build/sh/sh2/shc
APLFW_BUILD_DIR  = $(APLFW_DIR)/build/sh/sh2/shc

KERNEL_CFG  = $(OS_DIR)/cfgrtr/build/gcc/h4acfg-sh2.exe
KERNEL_LIB  = $(KERNEL_BUILD_DIR)/libhosv4a.lib
APLFW_LIB   = $(APLFW_BUILD_DIR)/hosaplfw.lib

ifeq ($(DEBUG),Yes)
KERNEL_LIB  = $(KERNEL_BUILD_DIR)/libhosv4adbg.lib
APLFW_LIB   = $(APLFW_BUILD_DIR)/hosaplfwdbg.lib
endif


# Tools
CC     = shc
ASM    = asmsh
LINK   = optlnk

CFLAGS = -CP=sh2 -DEBug -NOLOGO -I=$(KERNEL_INC_DIR),$(APLFW_INC_DIR)
AFLAGS = -CP=sh2 -DEBug -NOLOGO
LFLAGS = 

OBJS_DIR = objs

OBJS = $(OBJS_DIR)/vcttbl.obj		\
       $(OBJS_DIR)/startup.obj		\
       $(OBJS_DIR)/dbsct.obj		\
       $(OBJS_DIR)/main.obj			\
       $(OBJS_DIR)/kernel_cfg.obj	\
       $(OBJS_DIR)/sample.obj		\
       $(OBJS_DIR)/ostimer.obj		\


STD_LIBS = stdlib.lib

VPATH = .:..:$(SRC_DIR)/driver/renesas


all: mkdir_objs mk_kernel mk_aplfw $(TARGET).abs


$(TARGET).abs: $(OBJS) $(STD_LIBS) $(OS_LIBS)
	echo rom D=R                                      > $(OBJS_DIR)/subcmd.txt
	echo -OPtimize                                   >> $(OBJS_DIR)/subcmd.txt
	echo list $(TARGET).map                          >> $(OBJS_DIR)/subcmd.txt
	echo -Input=$(OBJS) | sed "s/ /,/g"              >> $(OBJS_DIR)/subcmd.txt
	echo -LIB=$(KERNEL_LIB),$(APLFW_LIB),$(STD_LIBS) >> $(OBJS_DIR)/subcmd.txt
	echo "-start=VECTTBL/$(ADDR_VECT),P,C,C\$$BSEC,C\$$DSEC,D/$(ADDR_ROM),B,R,S/$(ADDR_RAM)" >> $(OBJS_DIR)/subcmd.txt
	echo -output=$(TARGET).abs                       >> $(OBJS_DIR)/subcmd.txt
	echo end                                         >> $(OBJS_DIR)/subcmd.txt
	echo -input=$(TARGET).abs                        >> $(OBJS_DIR)/subcmd.txt
	echo form stype                                  >> $(OBJS_DIR)/subcmd.txt
	echo output $(TARGET).mot                        >> $(OBJS_DIR)/subcmd.txt
	echo -exit                                       >> $(OBJS_DIR)/subcmd.txt
	$(LINK) -SU=$(OBJS_DIR)/subcmd.txt

$(STD_LIBS):
	lbgsh -OUTPut=$(STD_LIBS) -CP=sh2 -REent 

mk_kernel:
	make -C $(KERNEL_BUILD_DIR) -f gmake.mak

mk_aplfw:
	make -C $(APLFW_BUILD_DIR) -f gmake.mak

mkdir_objs:
	@mkdir -p $(OBJS_DIR)

clean:
	rm -f $(OBJS) $(TARGET) ../kernel_cfg.c ../kernel_id.h

clean-all: clean
	make -C $(KERNEL_BUILD_DIR) -f gmake.mak clean
	make -C $(APLFW_BUILD_DIR) -f gmake.mak clean


$(OBJS_DIR)/sample.obj: sample.c ../kernel_id.h

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFG) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h



$(OBJS_DIR)/%.obj :: %.c
	$(CC) $(CFLAGS) $< -OB=$@ -List=$(@:%.obj=%.lst)

$(OBJS_DIR)/%.obj :: %.src
	$(ASM) $(AFLAGS) $< -OB=$@


