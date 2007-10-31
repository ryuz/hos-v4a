# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common depend file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------------------
#  Default setting
# --------------------------------------------------

# System
LINK_SYSTEM      ?= Yes
LINK_SYSAPI      ?= Yes
LINK_HANDLE      ?= Yes
LINK_MEMORY      ?= Yes
LINK_TIME        ?= Yes
LINK_PROCESS     ?= Yes
LINK_FILE        ?= Yes
LINK_COMMAND     ?= Yes
LINK_SHELL       ?= Yes

# Librarys
LINK_MEMPOL      ?= Yes
LINK_ASSOC       ?= Yes
LINK_LIST        ?= Yes
LINK_STREAMBUF   ?= Yes
LINK_PACKETBUF   ?= Yes
LINK_IPCHECKSUM  ?= Yes
LINK_CRC16       ?= Yes


# Device drivers
LINK_VT100       ?= Yes
LINK_TCPIP       ?= Yes
LINK_IPETHER     ?= Yes
LINK_NE2000      ?= Yes
LINK_LAN9000     ?= Yes
LINK_LAN9118     ?= Yes
LINK_PC16550     ?= Yes
LINK_AT91USART   ?= No
LINK_RENESASSCI  ?= No

# Applications
LINK_MEMDUMP     ?= Yes
LINK_MEMWRITE    ?= Yes
LINK_MEMTEST     ?= Yes
LINK_KEYTEST     ?= Yes
LINK_TIMECMD     ?= Yes
LINK_FILELIST    ?= Yes
LINK_FILECAT     ?= Yes
LINK_FILECOPY    ?= Yes
LINK_FILEDUMP    ?= Yes
LINK_ETHERSNOOP  ?= Yes
LINK_HELLO       ?= Yes



# --------------------------------------------------
#  Include
# --------------------------------------------------

# Include directories
INC_DIRS += $(APLFW_DIR)



# --------------------------------------------------
#  Systems
# --------------------------------------------------

# System
ifeq ($(LINK_SYSTEM),Yes)
SYSTEM_DIR = $(APLFW_DIR)/system/system
SRC_DIRS += $(SYSTEM_DIR)
CSRCS += $(SYSTEM_DIR)/system_initialize.c
CSRCS += $(SYSTEM_DIR)/system_boot.c
CSRCS += $(SYSTEM_DIR)/system_requestproc.c
CSRCS += $(SYSTEM_DIR)/system_process.c
endif


# System API
ifeq ($(LINK_SYSAPI),Yes)
SYSAPI_DIR = $(APLFW_DIR)/system/sysapi
SRC_DIRS += $(SYSAPI_DIR)
CSRCS += $(SYSAPI_DIR)/sysapi_initialize.c
CSRCS += $(SYSAPI_DIR)/sysloc_lock.c
CSRCS += $(SYSAPI_DIR)/sysloc_unlock.c
CSRCS += $(SYSAPI_DIR)/sysevt_clear.c
CSRCS += $(SYSAPI_DIR)/sysevt_create.c
CSRCS += $(SYSAPI_DIR)/sysevt_delete.c
CSRCS += $(SYSAPI_DIR)/sysevt_set.c
CSRCS += $(SYSAPI_DIR)/sysevt_wait.c
CSRCS += $(SYSAPI_DIR)/sysint_clear.c
CSRCS += $(SYSAPI_DIR)/sysint_disable.c
CSRCS += $(SYSAPI_DIR)/sysint_enable.c
CSRCS += $(SYSAPI_DIR)/sysisr_create.c
CSRCS += $(SYSAPI_DIR)/sysisr_delete.c
CSRCS += $(SYSAPI_DIR)/sysmem_alloc.c
CSRCS += $(SYSAPI_DIR)/sysmem_free.c
CSRCS += $(SYSAPI_DIR)/sysmem_getmemif.c
CSRCS += $(SYSAPI_DIR)/sysmem_getsize.c
CSRCS += $(SYSAPI_DIR)/sysmem_realloc.c
CSRCS += $(SYSAPI_DIR)/sysmtx_create.c
CSRCS += $(SYSAPI_DIR)/sysmtx_delete.c
CSRCS += $(SYSAPI_DIR)/sysmtx_lock.c
CSRCS += $(SYSAPI_DIR)/sysmtx_unlock.c
CSRCS += $(SYSAPI_DIR)/sysprc_create.c
CSRCS += $(SYSAPI_DIR)/sysprc_delete.c
CSRCS += $(SYSAPI_DIR)/sysprc_exit.c
CSRCS += $(SYSAPI_DIR)/sysprc_getcurrenthandle.c
CSRCS += $(SYSAPI_DIR)/sysprc_start.c
CSRCS += $(SYSAPI_DIR)/systim_getsystemtime.c
CSRCS += $(SYSAPI_DIR)/systim_wait.c
endif


# Handle Object
ifeq ($(LINK_HANDLE),Yes)
HANDLE_DIR = $(APLFW_DIR)/system/handle
SRC_DIRS += $(HANDLE_DIR)
CSRCS += $(HANDLE_DIR)/handle_close.c
CSRCS += $(HANDLE_DIR)/handleobj_create.c
CSRCS += $(HANDLE_DIR)/handleobj_delete.c
endif


# Memory
ifeq ($(LINK_MEMORY),Yes)
MEMORY_DIR = $(APLFW_DIR)/system/memory
SRC_DIRS += $(MEMORY_DIR)
CSRCS += $(MEMORY_DIR)/memory.c
endif


# Time
ifeq ($(LINK_TIME),Yes)
TIME_DIR = $(APLFW_DIR)/system/time
SRC_DIRS += $(TIME_DIR)
CSRCS += $(TIME_DIR)/time_getsystemtime.c
CSRCS += $(TIME_DIR)/time_wait.c
endif


# Process
ifeq ($(LINK_PROCESS),Yes)
PROCESS_DIR = $(APLFW_DIR)/system/process
SRC_DIRS += $(PROCESS_DIR)
CSRCS += $(PROCESS_DIR)/process.c
CSRCS += $(PROCESS_DIR)/procobj.c
endif


# File
ifeq ($(LINK_FILE),Yes)
FILE_DIR = $(APLFW_DIR)/system/file
SRC_DIRS += $(FILE_DIR)
CSRCS += $(FILE_DIR)/file_initialize.c
CSRCS += $(FILE_DIR)/file_open.c
CSRCS += $(FILE_DIR)/file_close.c
CSRCS += (FILE_DIR)/file_iocontrol.c
CSRCS += (FILE_DIR)/file_seek.c
CSRCS += (FILE_DIR)/file_read.c
CSRCS += (FILE_DIR)/file_write.c
CSRCS += (FILE_DIR)/file_readdir.c
CSRCS += (FILE_DIR)/file_getchar.c
CSRCS += (FILE_DIR)/file_getstring.c
CSRCS += (FILE_DIR)/file_putchar.c
CSRCS += (FILE_DIR)/file_putstring.c
CSRCS += (FILE_DIR)/file_adddevice.c
CSRCS += (FILE_DIR)/file_addvolume.c
CSRCS += (FILE_DIR)/drvobj_create.c
CSRCS += (FILE_DIR)/drvobj_delete.c
CSRCS += (FILE_DIR)/drvobj_open.c
CSRCS += (FILE_DIR)/drvobj_close.c
CSRCS += (FILE_DIR)/drvobj_iocontrol.c
CSRCS += (FILE_DIR)/drvobj_seek.c
CSRCS += (FILE_DIR)/drvobj_read.c
CSRCS += (FILE_DIR)/drvobj_write.c
CSRCS += (FILE_DIR)/drvobj_flush.c
CSRCS += (FILE_DIR)/fileobj_create.c
CSRCS += (FILE_DIR)/fileobj_delete.c
CSRCS += (FILE_DIR)/volumeobj_create.c
CSRCS += (FILE_DIR)/volumeobj_makedir.c
CSRCS += (FILE_DIR)/volumeobj_remove.c
CSRCS += (FILE_DIR)/chrdrv_create.c
CSRCS += (FILE_DIR)/chrdrv_delete.c
CSRCS += (FILE_DIR)/chrfile_create.c
CSRCS += (FILE_DIR)/chrfile_delete.c
CSRCS += (FILE_DIR)/sysvol_create.c
CSRCS += (FILE_DIR)/sysvol_delete.c
CSRCS += (FILE_DIR)/sysvol_open.c
CSRCS += (FILE_DIR)/sysvol_close.c
CSRCS += (FILE_DIR)/sysvol_iocontrol.c
CSRCS += (FILE_DIR)/sysvol_adddevice.c
CSRCS += (FILE_DIR)/console_getch.c
CSRCS += (FILE_DIR)/filefmt.c
CSRCS += (FILE_DIR)/stdfile.c
endif


# Command
ifeq ($(LINK_COMMAND),Yes)
COMMAND_DIR = $(APLFW_DIR)/system/command
SRC_DIRS += $(COMMAND_DIR)
CSRCS += $(COMMAND_DIR)/command.c
endif


# Shell
ifeq ($(LINK_SHELL),Yes)
SHELL_DIR = $(APLFW_DIR)/system/shell
SRC_DIRS += $(SHELL_DIR)
CSRCS += $(SHELL_DIR)/shell.c
endif



# --------------------------------------------------
#  Librarys
# --------------------------------------------------

# Memory Pool
ifeq ($(LINK_MEMPOL),Yes)
MEMPOL_DIR = $(APLFW_DIR)/library/container/mempol
SRC_DIRS += $(MEMPOL_DIR)
CSRCS += $(MEMPOL_DIR)/mempol.c	
endif


# Association Array
ifeq ($(LINK_ASSOC),Yes)
ASSOC_DIR = $(APLFW_DIR)/library/container/assoc
SRC_DIRS += $(ASSOC_DIR)
CSRCS += $(ASSOC_DIR)/assoc.c
endif


# List
ifeq ($(LINK_LIST),Yes)
LIST_DIR = $(APLFW_DIR)/library/container/list
SRC_DIRS += $(LIST_DIR)
CSRCS += $(LIST_DIR)/list_create.c
CSRCS += $(LIST_DIR)/list_createex.c
CSRCS += $(LIST_DIR)/list_addtail.c
CSRCS += $(LIST_DIR)/list_getat.c
CSRCS += $(LIST_DIR)/list_getheadpos.c
CSRCS += $(LIST_DIR)/list_getnextpos.c
CSRCS += $(LIST_DIR)/list_getprevpos.c
CSRCS += $(LIST_DIR)/list_gettailpos.c
CSRCS += $(LIST_DIR)/list_remove.c
endif


# Stream Buffer
ifeq ($(LINK_STREAMBUF),Yes)
STREAMBUF_DIR = $(APLFW_DIR)/library/container/streambuf
SRC_DIRS += $(STREAMBUF_DIR)
CSRCS += $(STREAMBUF_DIR)/streambuf_create.c
CSRCS += $(STREAMBUF_DIR)/streambuf_getbuf.c
CSRCS += $(STREAMBUF_DIR)/streambuf_sendbuf.c
CSRCS += $(STREAMBUF_DIR)/streambuf_senddata.c
CSRCS += $(STREAMBUF_DIR)/streambuf_sendchar.c
CSRCS += $(STREAMBUF_DIR)/streambuf_recvbuf.c
CSRCS += $(STREAMBUF_DIR)/streambuf_relbuf.c
CSRCS += $(STREAMBUF_DIR)/streambuf_recvdata.c
CSRCS += $(STREAMBUF_DIR)/streambuf_recvchar.c
CSRCS += $(STREAMBUF_DIR)/streambuf_clear.c
CSRCS += $(STREAMBUF_DIR)/streambuf_refdatasize.c
CSRCS += $(STREAMBUF_DIR)/streambuf_reffreesize.c
endif


# Packet Buffer
ifeq ($(LINK_PACKETBUF),Yes)
PACKETBUF_DIR  = $(APLFW_DIR)/library/container/packetbuf
SRC_DIRS += $(PACKETBUF_DIR)
CSRCS += $(PACKETBUF_DIR)/packetbuf_create.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_getbuf.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_sendbuf.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_senddata.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_recvbuf.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_relbuf.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_recvdata.c
CSRCS += $(PACKETBUF_DIR)/packetbuf_clear.c
endif


# IP check-sum
ifeq ($(LINK_IPCHECKSUM),Yes)
IPCHECKSUM_DIR = $(APLFW_DIR)/library/algorithm/ipchecksum
SRC_DIRS += $(IPCHECKSUM_DIR)
CSRCS += $(IPCHECKSUM_DIR)/ipchecksum_getdigest.c
CSRCS += $(IPCHECKSUM_DIR)/ipchecksum_update.c
endif


# 16bit CRC
ifeq ($(LINK_CRC16),Yes)
CRC16_DIR = $(APLFW_DIR)/library/algorithm/crc16
SRC_DIRS += $(CRC16_DIR)
CSRCS += $(CRC16_DIR)/crc16_getdigest.c
CSRCS += $(CRC16_DIR)/crc16_update.c
CSRCS += $(CRC16_DIR)/crc16_reset.c
CSRCS += $(CRC16_DIR)/crc16_table.c
endif



# --------------------------------------------------
#  Device Drivers
# --------------------------------------------------

# VT100
ifeq ($(LINK_VT100),Yes)
VT100_DIR = $(APLFW_DIR)/driver/console/vt100
SRC_DIRS += $(VT100_DIR)
CSRCS += $(VT100_DIR)/vt100drv_create.c
CSRCS += $(VT100_DIR)/vt100drv_delete.c
CSRCS += $(VT100_DIR)/vt100drv_open.c
CSRCS += $(VT100_DIR)/vt100drv_close.c
CSRCS += $(VT100_DIR)/vt100drv_iocontrol.c
CSRCS += $(VT100_DIR)/vt100drv_seek.c
CSRCS += $(VT100_DIR)/vt100drv_read.c
CSRCS += $(VT100_DIR)/vt100drv_write.c
CSRCS += $(VT100_DIR)/vt100drv_flush.c
CSRCS += $(VT100_DIR)/vt100drv_getch.c
endif


# TCP/IP
ifeq ($(LINK_TCPIP),Yes)
TCPIP_DIR = $(APLFW_DIR)/driver/tcpip/tcpip
SRC_DIRS += $(TCPIP_DIR)
CSRCS += $(TCPIP_DIR)/tcpip_create.c
CSRCS += $(TCPIP_DIR)/tcpip_delete.c
CSRCS += $(TCPIP_DIR)/tcpip_open.c
CSRCS += $(TCPIP_DIR)/tcpip_clese.c
CSRCS += $(TCPIP_DIR)/tcpip_iocontrol.c
CSRCS += $(TCPIP_DIR)/tcpip_seek.c
CSRCS += $(TCPIP_DIR)/tcpip_read.c
CSRCS += $(TCPIP_DIR)/tcpip_write.c
CSRCS += $(TCPIP_DIR)/tcpip_flush.c
CSRCS += $(TCPIP_DIR)/tcpip_recv.c
endif


# IpEther
ifeq ($(LINK_IPETHER),Yes)
IPETHER_DIR = $(APLFW_DIR)/driver/tcpip/ipether
SRC_DIRS += $(IPETHER_DIR)
CSRCS += $(IPETHER_DIR)/ipether_create.c
CSRCS += $(IPETHER_DIR)/ipether_delete.c
CSRCS += $(IPETHER_DIR)/ipether_open.c
CSRCS += $(IPETHER_DIR)/ipether_clese.c
CSRCS += $(IPETHER_DIR)/ipether_iocontrol.c
CSRCS += $(IPETHER_DIR)/ipether_seek.c
CSRCS += $(IPETHER_DIR)/ipether_read.c
CSRCS += $(IPETHER_DIR)/ipether_write.c
CSRCS += $(IPETHER_DIR)/ipether_recv.c
CSRCS += $(IPETHER_DIR)/ipether_flush.c
CSRCS += $(IPETHER_DIR)/ipether_getmacaddr.c
endif


# NE2000
ifeq ($(LINK_NE2000),Yes)
NE2000_DIR = $(APLFW_DIR)/driver/ether/ne2000
SRC_DIRS += $(NE2000_DIR)
CSRCS += $(NE2000_DIR)/ne2000drv.c
CSRCS += $(NE2000_DIR)/ne2000hal.c
endif


# LAN91C111
ifeq ($(LINK_LAN9000),Yes)
LAN9000_DIR = $(APLFW_DIR)/driver/ether/lan9000
SRC_DIRS += $(LAN9000_DIR)
CSRCS +=$(LAN9000_DIR)/lan9000drv_close.c
CSRCS +=$(LAN9000_DIR)/lan9000drv_create.c
CSRCS +=$(LAN9000_DIR)/lan9000drv_delete.c
CSRCS +=$(LAN9000_DIR)/lan9000drv_flush.c
CSRCS +=$(LAN9000_DIR)/lan9000drv_iocontrol.c
CSRCS +=$(LAN9000_DIR)/lan9000drv_isr.c
CSRCS +=$(LAN9000_DIR)/lan9000drv_open.c
CSRCS +=$(LAN9000_DIR)/lan9000drv_read.c
CSRCS +=$(LAN9000_DIR)/lan9000drv_seek.c
CSRCS +=$(LAN9000_DIR)/lan9000drv_write.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_create.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_delete.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_enableinterrupt.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_getinterruptstatus.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_getphysicaladdr.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_mii.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_phyregread.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_phyregwrite.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_recv.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_send.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_setinterruptmask.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_setup.c
CSRCS +=$(LAN9000_DIR)/lan9000hal_stop.c
endif


# LAN9118
ifeq ($(LINK_LAN9118),Yes)
LAN9118_DIR = $(APLFW_DIR)/driver/ether/lan9118
SRC_DIRS += $(LAN9118_DIR)
CSRCS += $(LAN9118_DIR)/lan9118drv_create.c
CSRCS += $(LAN9118_DIR)/lan9118drv_delete.c
CSRCS += $(LAN9118_DIR)/lan9118drv_open.c
CSRCS += $(LAN9118_DIR)/lan9118drv_close.c
CSRCS += $(LAN9118_DIR)/lan9118drv_iocontrol.c
CSRCS += $(LAN9118_DIR)/lan9118drv_seek.c
CSRCS += $(LAN9118_DIR)/lan9118drv_read.c
CSRCS += $(LAN9118_DIR)/lan9118drv_write.c
CSRCS += $(LAN9118_DIR)/lan9118drv_flush.c
CSRCS += $(LAN9118_DIR)/lan9118drv_isr.c
endif


# PC16550
ifeq ($(LINK_PC16550),Yes)
PC16550_DIR = $(APLFW_DIR)/driver/serial/pc16550
SRC_DIRS += $(PC16550_DIR)
CSRCS += $(PC16550_DIR)/pc16550drv_create.c
CSRCS += $(PC16550_DIR)/pc16550drv_delete.c
CSRCS += $(PC16550_DIR)/pc16550drv_open.c
CSRCS += $(PC16550_DIR)/pc16550drv_close.c
CSRCS += $(PC16550_DIR)/pc16550drv_iocontrol.c
CSRCS += $(PC16550_DIR)/pc16550drv_seek.c
CSRCS += $(PC16550_DIR)/pc16550drv_read.c
CSRCS += $(PC16550_DIR)/pc16550drv_write.c
CSRCS += $(PC16550_DIR)/pc16550drv_flush.c
CSRCS += $(PC16550_DIR)/pc16550drv_isr.c
CSRCS += $(PC16550_DIR)/pc16550hal_create.c
CSRCS += $(PC16550_DIR)/pc16550hal_delete.c
CSRCS += $(PC16550_DIR)/pc16550hal_setup.c
CSRCS += $(PC16550_DIR)/pc16550hal_stop.c
CSRCS += $(PC16550_DIR)/pc16550hal_setspeed.c
CSRCS += $(PC16550_DIR)/pc16550hal_recvchar.c
CSRCS += $(PC16550_DIR)/pc16550hal_sendchar.c
CSRCS += $(PC16550_DIR)/pc16550hal_enableinterrupt.c
CSRCS += $(PC16550_DIR)/pc16550hal_getinterruptstatus.c
CSRCS += $(PC16550_DIR)/pc16550hal_getstatus.c
endif


# Atmel AT91 USART
ifeq ($(LINK_AT91USART),Yes)
AT91USART_DIR = $(APLFW_DIR)/driver/serial/at91
SRC_DIRS += $(AT91USART_DIR)
CSRCS += $(AT91USART_DIR)/at91usartdrv_create.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_delete.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_open.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_close.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_iocontrol.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_seek.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_read.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_write.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_flush.c
CSRCS += $(AT91USART_DIR)/at91usartdrv_isr.c
endif


# Renesas SCI
ifeq ($(LINK_RENESASSCI),Yes)
RENESASSCI_DIR = $(APLFW_DIR)/driver/serial/renesas
SRC_DIRS += $(RENESASSCI_DIR)
CSRCS += $(RENESASSCI_DIR)/scidrv_create.c
CSRCS += $(RENESASSCI_DIR)/scidrv_delete.c
CSRCS += $(RENESASSCI_DIR)/scidrv_open.c
CSRCS += $(RENESASSCI_DIR)/scidrv_close.c
CSRCS += $(RENESASSCI_DIR)/scidrv_iocontrol.c
CSRCS += $(RENESASSCI_DIR)/scidrv_seek.c
CSRCS += $(RENESASSCI_DIR)/scidrv_read.c
CSRCS += $(RENESASSCI_DIR)/scidrv_write.c
CSRCS += $(RENESASSCI_DIR)/scidrv_flush.c
CSRCS += $(RENESASSCI_DIR)/scidrv_isr.c
CSRCS += $(RENESASSCI_DIR)/scihal_create.c
CSRCS += $(RENESASSCI_DIR)/scihal_delete.c
CSRCS += $(RENESASSCI_DIR)/scihal_enableinterrupt.c
CSRCS += $(RENESASSCI_DIR)/scihal_recvchar.c
CSRCS += $(RENESASSCI_DIR)/scihal_sendchar.c
CSRCS += $(RENESASSCI_DIR)/scihal_setspeed.c
CSRCS += $(RENESASSCI_DIR)/scihal_setup.c
CSRCS += $(RENESASSCI_DIR)/scihal_stop.c
endif



# --------------------------------------------------
#  Applications
# --------------------------------------------------


# Memory Dump
ifeq ($(LINK_MEMDUMP),Yes)
MEMDUMP_DIR = $(APLFW_DIR)/application/utility/memdump
SRC_DIRS += $(MEMDUMP_DIR)
CSRCS += $(MEMDUMP_DIR)/memdump_main.c
endif


# Memory Write
ifeq ($(LINK_MEMWRITE),Yes)
MEMWRITE_DIR = $(APLFW_DIR)/application/utility/memwrite
SRC_DIRS += $(MEMWRITE_DIR)
CSRCS += $(MEMWRITE_DIR)/memwrite_main.c
endif


# Memory Test
ifeq ($(LINK_MEMTEST),Yes)
MEMTEST_DIR = $(APLFW_DIR)/application/utility/memtest
SRC_DIRS += $(MEMTEST_DIR)
CSRCS += $(MEMTEST_DIR)/memtest_main.c
endif


# Key Test
ifeq ($(LINK_KEYTEST),Yes)
KEYTEST_DIR = $(APLFW_DIR)/application/utility/keytest
SRC_DIRS += $(KEYTEST_DIR)
CSRCS += $(KEYTEST_DIR)/keytest_main.c
endif


# Time Command
ifeq ($(LINK_TIMECMD),Yes)
TIMECMD_DIR = $(APLFW_DIR)/application/utility/timecmd
SRC_DIRS += $(TIMECMD_DIR)
CSRCS += $(TIMECMD_DIR)/timecmd_main.c
endif


# File List
ifeq ($(LINK_FILELIST),Yes)
FILELIST_DIR = $(APLFW_DIR)/application/filecmd/filelist
SRC_DIRS += $(FILELIST_DIR)
CSRCS += $(FILELIST_DIR)/filelist_main.c
endif


# File Cat
ifeq ($(LINK_FILECAT),Yes)
FILECAT_DIR = $(APLFW_DIR)/application/filecmd/filecat
SRC_DIRS += $(FILECAT_DIR)
CSRCS += $(FILECAT_DIR)/filecat_main.c
endif


# File Copy
ifeq ($(LINK_FILECOPY),Yes)
FILECOPY_DIR = $(APLFW_DIR)/application/filecmd/filecopy
SRC_DIRS += $(FILECOPY_DIR)
CSRCS += $(FILECOPY_DIR)/filecopy_main.c
endif


# File Dump
ifeq ($(LINK_FILEDUMP),Yes)
FILEDUMP_DIR = $(APLFW_DIR)/application/filecmd/filedump
SRC_DIRS += $(FILEDUMP_DIR)
CSRCS += $(FILEDUMP_DIR)/filedump_main.c
endif


# Ether Snoopt
ifeq ($(LINK_ETHERSNOOP),Yes)
ETHERSNOOP_DIR = $(APLFW_DIR)/application/netcmd/ethersnoop
SRC_DIRS += $(ETHERSNOOP_DIR)
CSRCS += $(ETHERSNOOP_DIR)/ethersnoop_main.c
endif


# Hello World
ifeq ($(LINK_HELLO),Yes)
HELLO_DIR = $(APLFW_DIR)/application/example/hello
SRC_DIRS += $(HELLO_DIR)
CSRCS += $(HELLO_DIR)/hello.c
endif


# end of file
