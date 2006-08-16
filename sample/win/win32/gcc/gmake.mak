

TARGET ?= sample.exe

INC_DIR = ../../../../kernel/include

# Tools
CC     = gcc
ASM    = gcc
LINK   = gcc
DEPEND = gcc -M
LINT   = splint
AWK    = gawk

CFLAGS = -c -g -O0 -Wall -I$(INC_DIR)
AFLAGS = -c -g
LFLAGS = 

OBJS_DIR = objs

OBJS = $(OBJS_DIR)/main.o			\
       $(OBJS_DIR)/sample.o			\
       $(OBJS_DIR)/ostimer.o		\
       $(OBJS_DIR)/wintimer.o		\
       $(OBJS_DIR)/kernel_cfg.o

OS_LIBS = ../../../../kernel/build/win/win32/gcc/libhosv4a.a
OS_CFG  = ../../../../cfgrtr/build/gcc/h4acfg-win32.exe

VPATH = ..

all: mkdir_objs mk_kernel $(TARGET)


$(TARGET): $(OBJS)
	$(LINK) $(LFLAGS) $(OBJS) $(OS_LIBS) -lwinmm -o $(TARGET)

mk_kernel:
	make -C ../../../../kernel/build/win/win32/gcc -f gmake.mak

mkdir_objs:
	@mkdir -p $(OBJS_DIR)

clean:
	rm -f $(OBJS) $(TARGET) ../kernel_cfg.c ../kernel_id.h

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(OS_CFG) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


$(OBJS_DIR)/sample.o: ../kernel_id.h

$(OBJS_DIR)/%.o :: %.c
	$(CC) $(CFLAGS) -c $< -o $@


