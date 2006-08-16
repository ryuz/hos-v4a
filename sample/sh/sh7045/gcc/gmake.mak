

TARGET ?= sample.out

# Tools
CC     = sh-elf-gcc
ASM    = sh-elf-gcc
LINK   = sh-elf-gcc
DEPEND = sh-elf-gcc -M
LINT   = splint
AWK    = gawk


INC_DIR = ../../../../kernel/include


CFLAGS = -c -g -O0 -Wall -std=c89 -I$(INC_DIR)
AFLAGS = -c -g
LFLAGS = -m2 -nostartfiles -Wl,-v,-t,-Map,sample.map,-Tsample.x

OBJS = vector.o crt0.o kernel_cfg.o sample.o ../../../../kernel/build/sh/sh2/gcc/libhosv4a.a

all: $(OBJS)
	$(LINK) $(LFLAGS) $(OBJS) -o sample.elf


vector.o: vector.S
	$(CC) $(AFLAGS) vector.S -o vector.o

crt0.o: crt0.S
	$(CC) $(AFLAGS) crt0.S -o crt0.o

sample.o: sample.c
	$(CC) $(CFLAGS) sample.c -o sample.o

kernel_cfg.o: kernel_cfg.c
	$(CC) $(CFLAGS) kernel_cfg.c -o kernel_cfg.o

kernel_cfg.c: system.cfg
	cpp -E system.cfg > system.i
	../../../../cfgrtr/build/gcc/h4acfg-sh2


