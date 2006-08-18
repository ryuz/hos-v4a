

TARGET ?= sample


ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)Dbg
endif

ifeq ($(ROM),Yes)
TARGET := $(TARGET)Rom
endif

ifeq ($(SIM),Yes)
TARGET := $(TARGET)Sim
endif


# 出力ファイル名
TARGET_ELF = $(TARGET).elf
TARGET_MOT = $(TARGET).mot

INC_DIR = ../../../../kernel/include


# Tools
CC     = sh-elf-gcc
ASM    = sh-elf-gcc
LINK   = sh-elf-gcc
DEPEND = sh-elf-gcc -M
OBJCNV = sh-elf-objcopy
LINT   = splint
AWK    = gawk

INC_DIR = ../../../../kernel/include


CFLAGS = -m2 -c -g -O0 -Wall -std=c89 -I$(INC_DIR)
AFLAGS = -m2 -c -g
LFLAGS = -m2 -nostartfiles -Wl,-v,-t,-Map,sample.map,-Tsample.x

OBJS = vector.o crt0.o kernel_cfg.o sample.o

OS_CFG  = ../../../../cfgrtr/build/gcc/h4acfg-sh2.exe

OBJS_DIR = objs

OBJS  = $(OBJS_DIR)/vector.o		\
        $(OBJS_DIR)/crt0.o			\
        $(OBJS_DIR)/kernel_cfg.o	\
        $(OBJS_DIR)/main.o			\
        $(OBJS_DIR)/sample.o		\
        $(OBJS_DIR)/ostimer.o		\
        $(OBJS_DIR)/sci1.o			\

VPATH = ..

all: mkdir_objs mk_kernel $(TARGET_ELF)


mk_kernel:
	make -C ../../../../kernel/build/sh/sh2/gcc -f gmake.mak

mkdir_objs:
	@mkdir -p $(OBJS_DIR)

$(TARGET_ELF): $(OBJS)
	$(LINK) $(LFLAGS) $(OBJS) ../../../../kernel/build/sh/sh2/gcc/libhosv4a.a -o $(TARGET_ELF)
	${OBJCNV} -O srec $(TARGET_ELF) ${TARGET_MOT}

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(OS_CFG) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h

$(OBJS_DIR)/sample.o: ../kernel_id.h

#vector.o: vector.S
#	$(CC) $(AFLAGS) vector.S -o vector.o

#crt0.o: crt0.S
#	$(CC) $(AFLAGS) crt0.S -o crt0.o

#sample.o: sample.c
#	$(CC) $(CFLAGS) sample.c -o sample.o

#kernel_cfg.o: kernel_cfg.c
#	$(CC) $(CFLAGS) kernel_cfg.c -o kernel_cfg.o

#kernel_cfg.c: system.cfg
#	cpp -E system.cfg > system.i
#	../../../../cfgrtr/build/gcc/h4acfg-sh2



$(OBJS_DIR)/sample.o: ../kernel_id.h

$(OBJS_DIR)/%.o :: %.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJS_DIR)/%.o :: %.S
	$(ASM) $(AFLAGS) $< -o $@




