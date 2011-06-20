# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance  Application Framework
#    common depend file for nmake
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# ----------------------------------
#  source copy
# ----------------------------------
makelib_srcobjcp: $(HEADERS)


$(OBJS_DIR)\system.h : $(SYSTEM_DIR)\system.h
	$(CMD_CP) $(SYSTEM_DIR)\system.h $(OBJS_DIR)\

$(OBJS_DIR)\system_local.h : $(SYSTEM_DIR)\system_local.h
	$(CMD_CP) $(SYSTEM_DIR)\system_local.h $(OBJS_DIR)\

$(OBJS_DIR)\system_initialize.c : $(SYSTEM_DIR)\system_initialize.c
	$(CMD_CP) $(SYSTEM_DIR)\system_initialize.c $(OBJS_DIR)\

$(OBJS_DIR)\system_requestproc.c : $(SYSTEM_DIR)\system_requestproc.c
	$(CMD_CP) $(SYSTEM_DIR)\system_requestproc.c $(OBJS_DIR)\

$(OBJS_DIR)\system_process.c : $(SYSTEM_DIR)\system_process.c
	$(CMD_CP) $(SYSTEM_DIR)\system_process.c $(OBJS_DIR)\

$(OBJS_DIR)\system_getnextprocess.c : $(SYSTEM_DIR)\system_getnextprocess.c
	$(CMD_CP) $(SYSTEM_DIR)\system_getnextprocess.c $(OBJS_DIR)\

$(OBJS_DIR)\system_getsystemprocess.c : $(SYSTEM_DIR)\system_getsystemprocess.c
	$(CMD_CP) $(SYSTEM_DIR)\system_getsystemprocess.c $(OBJS_DIR)\

$(OBJS_DIR)\system_lock.c : $(SYSTEM_DIR)\system_lock.c
	$(CMD_CP) $(SYSTEM_DIR)\system_lock.c $(OBJS_DIR)\

$(OBJS_DIR)\system_unlock.c : $(SYSTEM_DIR)\system_unlock.c
	$(CMD_CP) $(SYSTEM_DIR)\system_unlock.c $(OBJS_DIR)\

$(OBJS_DIR)\whiteboard_setstring.c : $(SYSTEM_DIR)\whiteboard_setstring.c
	$(CMD_CP) $(SYSTEM_DIR)\whiteboard_setstring.c $(OBJS_DIR)\

$(OBJS_DIR)\whiteboard_getstring.c : $(SYSTEM_DIR)\whiteboard_getstring.c
	$(CMD_CP) $(SYSTEM_DIR)\whiteboard_getstring.c $(OBJS_DIR)\

$(OBJS_DIR)\whiteboard_setinteger.c : $(SYSTEM_DIR)\whiteboard_setinteger.c
	$(CMD_CP) $(SYSTEM_DIR)\whiteboard_setinteger.c $(OBJS_DIR)\

$(OBJS_DIR)\whiteboard_getinteger.c : $(SYSTEM_DIR)\whiteboard_getinteger.c
	$(CMD_CP) $(SYSTEM_DIR)\whiteboard_getinteger.c $(OBJS_DIR)\

$(OBJS_DIR)\whiteboard_getnextkey.c : $(SYSTEM_DIR)\whiteboard_getnextkey.c
	$(CMD_CP) $(SYSTEM_DIR)\whiteboard_getnextkey.c $(OBJS_DIR)\


$(OBJS_DIR)\sysapi.h : $(SYSAPI_DIR)\sysapi.h
	$(CMD_CP) $(SYSAPI_DIR)\sysapi.h $(OBJS_DIR)\

$(OBJS_DIR)\sysapi_local.h : $(SYSAPI_DIR)\sysapi_local.h
	$(CMD_CP) $(SYSAPI_DIR)\sysapi_local.h $(OBJS_DIR)\

$(OBJS_DIR)\sysapi_initialize.c : $(SYSAPI_DIR)\sysapi_initialize.c
	$(CMD_CP) $(SYSAPI_DIR)\sysapi_initialize.c $(OBJS_DIR)\

$(OBJS_DIR)\sysctx_isisr.c : $(SYSAPI_DIR)\sysctx_isisr.c
	$(CMD_CP) $(SYSAPI_DIR)\sysctx_isisr.c $(OBJS_DIR)\

$(OBJS_DIR)\sysloc_lock.c : $(SYSAPI_DIR)\sysloc_lock.c
	$(CMD_CP) $(SYSAPI_DIR)\sysloc_lock.c $(OBJS_DIR)\

$(OBJS_DIR)\sysloc_unlock.c : $(SYSAPI_DIR)\sysloc_unlock.c
	$(CMD_CP) $(SYSAPI_DIR)\sysloc_unlock.c $(OBJS_DIR)\

$(OBJS_DIR)\sysevt_clear.c : $(SYSAPI_DIR)\sysevt_clear.c
	$(CMD_CP) $(SYSAPI_DIR)\sysevt_clear.c $(OBJS_DIR)\

$(OBJS_DIR)\sysevt_create.c : $(SYSAPI_DIR)\sysevt_create.c
	$(CMD_CP) $(SYSAPI_DIR)\sysevt_create.c $(OBJS_DIR)\

$(OBJS_DIR)\sysevt_delete.c : $(SYSAPI_DIR)\sysevt_delete.c
	$(CMD_CP) $(SYSAPI_DIR)\sysevt_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\sysevt_set.c : $(SYSAPI_DIR)\sysevt_set.c
	$(CMD_CP) $(SYSAPI_DIR)\sysevt_set.c $(OBJS_DIR)\

$(OBJS_DIR)\sysevt_wait.c : $(SYSAPI_DIR)\sysevt_wait.c
	$(CMD_CP) $(SYSAPI_DIR)\sysevt_wait.c $(OBJS_DIR)\

$(OBJS_DIR)\sysint_clear.c : $(SYSAPI_DIR)\sysint_clear.c
	$(CMD_CP) $(SYSAPI_DIR)\sysint_clear.c $(OBJS_DIR)\

$(OBJS_DIR)\sysint_disable.c : $(SYSAPI_DIR)\sysint_disable.c
	$(CMD_CP) $(SYSAPI_DIR)\sysint_disable.c $(OBJS_DIR)\

$(OBJS_DIR)\sysint_enable.c : $(SYSAPI_DIR)\sysint_enable.c
	$(CMD_CP) $(SYSAPI_DIR)\sysint_enable.c $(OBJS_DIR)\

$(OBJS_DIR)\sysisr_create.c : $(SYSAPI_DIR)\sysisr_create.c
	$(CMD_CP) $(SYSAPI_DIR)\sysisr_create.c $(OBJS_DIR)\

$(OBJS_DIR)\sysisr_delete.c : $(SYSAPI_DIR)\sysisr_delete.c
	$(CMD_CP) $(SYSAPI_DIR)\sysisr_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmem_alloc.c : $(SYSAPI_DIR)\sysmem_alloc.c
	$(CMD_CP) $(SYSAPI_DIR)\sysmem_alloc.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmem_free.c : $(SYSAPI_DIR)\sysmem_free.c
	$(CMD_CP) $(SYSAPI_DIR)\sysmem_free.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmem_getmemheap.c : $(SYSAPI_DIR)\sysmem_getmemheap.c
	$(CMD_CP) $(SYSAPI_DIR)\sysmem_getmemheap.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmem_getsize.c : $(SYSAPI_DIR)\sysmem_getsize.c
	$(CMD_CP) $(SYSAPI_DIR)\sysmem_getsize.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmem_realloc.c : $(SYSAPI_DIR)\sysmem_realloc.c
	$(CMD_CP) $(SYSAPI_DIR)\sysmem_realloc.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmtx_create.c : $(SYSAPI_DIR)\sysmtx_create.c
	$(CMD_CP) $(SYSAPI_DIR)\sysmtx_create.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmtx_delete.c : $(SYSAPI_DIR)\sysmtx_delete.c
	$(CMD_CP) $(SYSAPI_DIR)\sysmtx_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmtx_lock.c : $(SYSAPI_DIR)\sysmtx_lock.c
	$(CMD_CP) $(SYSAPI_DIR)\sysmtx_lock.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmtx_unlock.c : $(SYSAPI_DIR)\sysmtx_unlock.c
	$(CMD_CP) $(SYSAPI_DIR)\sysmtx_unlock.c $(OBJS_DIR)\

$(OBJS_DIR)\sysprc_create.c : $(SYSAPI_DIR)\sysprc_create.c
	$(CMD_CP) $(SYSAPI_DIR)\sysprc_create.c $(OBJS_DIR)\

$(OBJS_DIR)\sysprc_delete.c : $(SYSAPI_DIR)\sysprc_delete.c
	$(CMD_CP) $(SYSAPI_DIR)\sysprc_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\sysprc_start.c : $(SYSAPI_DIR)\sysprc_start.c
	$(CMD_CP) $(SYSAPI_DIR)\sysprc_start.c $(OBJS_DIR)\

$(OBJS_DIR)\sysprc_terminate.c : $(SYSAPI_DIR)\sysprc_terminate.c
	$(CMD_CP) $(SYSAPI_DIR)\sysprc_terminate.c $(OBJS_DIR)\

$(OBJS_DIR)\sysprc_suspend.c : $(SYSAPI_DIR)\sysprc_suspend.c
	$(CMD_CP) $(SYSAPI_DIR)\sysprc_suspend.c $(OBJS_DIR)\

$(OBJS_DIR)\sysprc_resume.c : $(SYSAPI_DIR)\sysprc_resume.c
	$(CMD_CP) $(SYSAPI_DIR)\sysprc_resume.c $(OBJS_DIR)\

$(OBJS_DIR)\sysprc_getparam.c : $(SYSAPI_DIR)\sysprc_getparam.c
	$(CMD_CP) $(SYSAPI_DIR)\sysprc_getparam.c $(OBJS_DIR)\

$(OBJS_DIR)\sysprc_getcurrenthandle.c : $(SYSAPI_DIR)\sysprc_getcurrenthandle.c
	$(CMD_CP) $(SYSAPI_DIR)\sysprc_getcurrenthandle.c $(OBJS_DIR)\

$(OBJS_DIR)\sysprc_setsignalhandler.c : $(SYSAPI_DIR)\sysprc_setsignalhandler.c
	$(CMD_CP) $(SYSAPI_DIR)\sysprc_setsignalhandler.c $(OBJS_DIR)\

$(OBJS_DIR)\sysprc_sendsignal.c : $(SYSAPI_DIR)\sysprc_sendsignal.c
	$(CMD_CP) $(SYSAPI_DIR)\sysprc_sendsignal.c $(OBJS_DIR)\

$(OBJS_DIR)\systim_signal.c : $(SYSAPI_DIR)\systim_signal.c
	$(CMD_CP) $(SYSAPI_DIR)\systim_signal.c $(OBJS_DIR)\

$(OBJS_DIR)\systim_wait.c : $(SYSAPI_DIR)\systim_wait.c
	$(CMD_CP) $(SYSAPI_DIR)\systim_wait.c $(OBJS_DIR)\

$(OBJS_DIR)\systim_getsystemtime.c : $(SYSAPI_DIR)\systim_getsystemtime.c
	$(CMD_CP) $(SYSAPI_DIR)\systim_getsystemtime.c $(OBJS_DIR)\

$(OBJS_DIR)\systim_systimetosecond.c : $(SYSAPI_DIR)\systim_systimetosecond.c
	$(CMD_CP) $(SYSAPI_DIR)\systim_systimetosecond.c $(OBJS_DIR)\

$(OBJS_DIR)\systim_systimetonanosecond.c : $(SYSAPI_DIR)\systim_systimetonanosecond.c
	$(CMD_CP) $(SYSAPI_DIR)\systim_systimetonanosecond.c $(OBJS_DIR)\

$(OBJS_DIR)\systim_getcputime.c : $(SYSAPI_DIR)\systim_getcputime.c
	$(CMD_CP) $(SYSAPI_DIR)\systim_getcputime.c $(OBJS_DIR)\

$(OBJS_DIR)\systim_cputimetosecond.c : $(SYSAPI_DIR)\systim_cputimetosecond.c
	$(CMD_CP) $(SYSAPI_DIR)\systim_cputimetosecond.c $(OBJS_DIR)\

$(OBJS_DIR)\systim_cputimetonanosecond.c : $(SYSAPI_DIR)\systim_cputimetonanosecond.c
	$(CMD_CP) $(SYSAPI_DIR)\systim_cputimetonanosecond.c $(OBJS_DIR)\

$(OBJS_DIR)\sysio_allociomem.c : $(SYSAPI_DIR)\sysio_allociomem.c
	$(CMD_CP) $(SYSAPI_DIR)\sysio_allociomem.c $(OBJS_DIR)\

$(OBJS_DIR)\sysio_freeiomem.c : $(SYSAPI_DIR)\sysio_freeiomem.c
	$(CMD_CP) $(SYSAPI_DIR)\sysio_freeiomem.c $(OBJS_DIR)\

$(OBJS_DIR)\syshos_hook.c : $(SYSAPI_DIR)\syshos_hook.c
	$(CMD_CP) $(SYSAPI_DIR)\syshos_hook.c $(OBJS_DIR)\


$(OBJS_DIR)\sysmemheap.h : $(SYSMEM_DIR)\sysmemheap.h
	$(CMD_CP) $(SYSMEM_DIR)\sysmemheap.h $(OBJS_DIR)\

$(OBJS_DIR)\sysmemheap_local.h : $(SYSMEM_DIR)\sysmemheap_local.h
	$(CMD_CP) $(SYSMEM_DIR)\sysmemheap_local.h $(OBJS_DIR)\

$(OBJS_DIR)\sysmemheap_alignsize.c : $(SYSMEM_DIR)\sysmemheap_alignsize.c
	$(CMD_CP) $(SYSMEM_DIR)\sysmemheap_alignsize.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmemheap_alloc.c : $(SYSMEM_DIR)\sysmemheap_alloc.c
	$(CMD_CP) $(SYSMEM_DIR)\sysmemheap_alloc.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmemheap_constructor.c : $(SYSMEM_DIR)\sysmemheap_constructor.c
	$(CMD_CP) $(SYSMEM_DIR)\sysmemheap_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmemheap_destructor.c : $(SYSMEM_DIR)\sysmemheap_destructor.c
	$(CMD_CP) $(SYSMEM_DIR)\sysmemheap_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmemheap_free.c : $(SYSMEM_DIR)\sysmemheap_free.c
	$(CMD_CP) $(SYSMEM_DIR)\sysmemheap_free.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmemheap_getalign.c : $(SYSMEM_DIR)\sysmemheap_getalign.c
	$(CMD_CP) $(SYSMEM_DIR)\sysmemheap_getalign.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmemheap_getsize.c : $(SYSMEM_DIR)\sysmemheap_getsize.c
	$(CMD_CP) $(SYSMEM_DIR)\sysmemheap_getsize.c $(OBJS_DIR)\

$(OBJS_DIR)\sysmemheap_realloc.c : $(SYSMEM_DIR)\sysmemheap_realloc.c
	$(CMD_CP) $(SYSMEM_DIR)\sysmemheap_realloc.c $(OBJS_DIR)\


$(OBJS_DIR)\handle.h : $(HANDLE_DIR)\handle.h
	$(CMD_CP) $(HANDLE_DIR)\handle.h $(OBJS_DIR)\

$(OBJS_DIR)\handleobj.h : $(HANDLE_DIR)\handleobj.h
	$(CMD_CP) $(HANDLE_DIR)\handleobj.h $(OBJS_DIR)\

$(OBJS_DIR)\handleobj_local.h : $(HANDLE_DIR)\handleobj_local.h
	$(CMD_CP) $(HANDLE_DIR)\handleobj_local.h $(OBJS_DIR)\

$(OBJS_DIR)\handle_close.c : $(HANDLE_DIR)\handle_close.c
	$(CMD_CP) $(HANDLE_DIR)\handle_close.c $(OBJS_DIR)\

$(OBJS_DIR)\handleobj_create.c : $(HANDLE_DIR)\handleobj_create.c
	$(CMD_CP) $(HANDLE_DIR)\handleobj_create.c $(OBJS_DIR)\

$(OBJS_DIR)\handleobj_delete.c : $(HANDLE_DIR)\handleobj_delete.c
	$(CMD_CP) $(HANDLE_DIR)\handleobj_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\handleobj_constructor.c : $(HANDLE_DIR)\handleobj_constructor.c
	$(CMD_CP) $(HANDLE_DIR)\handleobj_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\handleobj_destructor.c : $(HANDLE_DIR)\handleobj_destructor.c
	$(CMD_CP) $(HANDLE_DIR)\handleobj_destructor.c $(OBJS_DIR)\


$(OBJS_DIR)\memory.h : $(MEMORY_DIR)\memory.h
	$(CMD_CP) $(MEMORY_DIR)\memory.h $(OBJS_DIR)\

$(OBJS_DIR)\memory.c : $(MEMORY_DIR)\memory.c
	$(CMD_CP) $(MEMORY_DIR)\memory.c $(OBJS_DIR)\


$(OBJS_DIR)\time.h : $(TIME_DIR)\time.h
	$(CMD_CP) $(TIME_DIR)\time.h $(OBJS_DIR)\

$(OBJS_DIR)\time_getsystemtime.c : $(TIME_DIR)\time_getsystemtime.c
	$(CMD_CP) $(TIME_DIR)\time_getsystemtime.c $(OBJS_DIR)\

$(OBJS_DIR)\time_wait.c : $(TIME_DIR)\time_wait.c
	$(CMD_CP) $(TIME_DIR)\time_wait.c $(OBJS_DIR)\


$(OBJS_DIR)\process.h : $(PROCESS_DIR)\process.h
	$(CMD_CP) $(PROCESS_DIR)\process.h $(OBJS_DIR)\

$(OBJS_DIR)\process_local.h : $(PROCESS_DIR)\process_local.h
	$(CMD_CP) $(PROCESS_DIR)\process_local.h $(OBJS_DIR)\

$(OBJS_DIR)\process_create.c : $(PROCESS_DIR)\process_create.c
	$(CMD_CP) $(PROCESS_DIR)\process_create.c $(OBJS_DIR)\

$(OBJS_DIR)\process_createex.c : $(PROCESS_DIR)\process_createex.c
	$(CMD_CP) $(PROCESS_DIR)\process_createex.c $(OBJS_DIR)\

$(OBJS_DIR)\process_delete.c : $(PROCESS_DIR)\process_delete.c
	$(CMD_CP) $(PROCESS_DIR)\process_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\process_constructor.c : $(PROCESS_DIR)\process_constructor.c
	$(CMD_CP) $(PROCESS_DIR)\process_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\process_destructor.c : $(PROCESS_DIR)\process_destructor.c
	$(CMD_CP) $(PROCESS_DIR)\process_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getcurrenthandle.c : $(PROCESS_DIR)\process_getcurrenthandle.c
	$(CMD_CP) $(PROCESS_DIR)\process_getcurrenthandle.c $(OBJS_DIR)\

$(OBJS_DIR)\process_exit.c : $(PROCESS_DIR)\process_exit.c
	$(CMD_CP) $(PROCESS_DIR)\process_exit.c $(OBJS_DIR)\

$(OBJS_DIR)\process_waitexit.c : $(PROCESS_DIR)\process_waitexit.c
	$(CMD_CP) $(PROCESS_DIR)\process_waitexit.c $(OBJS_DIR)\

$(OBJS_DIR)\process_setsignalproc.c : $(PROCESS_DIR)\process_setsignalproc.c
	$(CMD_CP) $(PROCESS_DIR)\process_setsignalproc.c $(OBJS_DIR)\

$(OBJS_DIR)\process_sendsignal.c : $(PROCESS_DIR)\process_sendsignal.c
	$(CMD_CP) $(PROCESS_DIR)\process_sendsignal.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getexitcode.c : $(PROCESS_DIR)\process_getexitcode.c
	$(CMD_CP) $(PROCESS_DIR)\process_getexitcode.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getparam.c : $(PROCESS_DIR)\process_getparam.c
	$(CMD_CP) $(PROCESS_DIR)\process_getparam.c $(OBJS_DIR)\

$(OBJS_DIR)\process_setparam.c : $(PROCESS_DIR)\process_setparam.c
	$(CMD_CP) $(PROCESS_DIR)\process_setparam.c $(OBJS_DIR)\

$(OBJS_DIR)\process_entersystemmode.c : $(PROCESS_DIR)\process_entersystemmode.c
	$(CMD_CP) $(PROCESS_DIR)\process_entersystemmode.c $(OBJS_DIR)\

$(OBJS_DIR)\process_leavesystemmode.c : $(PROCESS_DIR)\process_leavesystemmode.c
	$(CMD_CP) $(PROCESS_DIR)\process_leavesystemmode.c $(OBJS_DIR)\

$(OBJS_DIR)\process_issystemmode.c : $(PROCESS_DIR)\process_issystemmode.c
	$(CMD_CP) $(PROCESS_DIR)\process_issystemmode.c $(OBJS_DIR)\

$(OBJS_DIR)\process_setcurrentdir.c : $(PROCESS_DIR)\process_setcurrentdir.c
	$(CMD_CP) $(PROCESS_DIR)\process_setcurrentdir.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getcurrentdir.c : $(PROCESS_DIR)\process_getcurrentdir.c
	$(CMD_CP) $(PROCESS_DIR)\process_getcurrentdir.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getparentprocess.c : $(PROCESS_DIR)\process_getparentprocess.c
	$(CMD_CP) $(PROCESS_DIR)\process_getparentprocess.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getexecutiontime.c : $(PROCESS_DIR)\process_getexecutiontime.c
	$(CMD_CP) $(PROCESS_DIR)\process_getexecutiontime.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getcommandline.c : $(PROCESS_DIR)\process_getcommandline.c
	$(CMD_CP) $(PROCESS_DIR)\process_getcommandline.c $(OBJS_DIR)\

$(OBJS_DIR)\process_setterminal.c : $(PROCESS_DIR)\process_setterminal.c
	$(CMD_CP) $(PROCESS_DIR)\process_setterminal.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getterminal.c : $(PROCESS_DIR)\process_getterminal.c
	$(CMD_CP) $(PROCESS_DIR)\process_getterminal.c $(OBJS_DIR)\

$(OBJS_DIR)\process_setconin.c : $(PROCESS_DIR)\process_setconin.c
	$(CMD_CP) $(PROCESS_DIR)\process_setconin.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getconin.c : $(PROCESS_DIR)\process_getconin.c
	$(CMD_CP) $(PROCESS_DIR)\process_getconin.c $(OBJS_DIR)\

$(OBJS_DIR)\process_setconout.c : $(PROCESS_DIR)\process_setconout.c
	$(CMD_CP) $(PROCESS_DIR)\process_setconout.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getconout.c : $(PROCESS_DIR)\process_getconout.c
	$(CMD_CP) $(PROCESS_DIR)\process_getconout.c $(OBJS_DIR)\

$(OBJS_DIR)\process_setstdin.c : $(PROCESS_DIR)\process_setstdin.c
	$(CMD_CP) $(PROCESS_DIR)\process_setstdin.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getstdin.c : $(PROCESS_DIR)\process_getstdin.c
	$(CMD_CP) $(PROCESS_DIR)\process_getstdin.c $(OBJS_DIR)\

$(OBJS_DIR)\process_setstdout.c : $(PROCESS_DIR)\process_setstdout.c
	$(CMD_CP) $(PROCESS_DIR)\process_setstdout.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getstdout.c : $(PROCESS_DIR)\process_getstdout.c
	$(CMD_CP) $(PROCESS_DIR)\process_getstdout.c $(OBJS_DIR)\

$(OBJS_DIR)\process_setstderr.c : $(PROCESS_DIR)\process_setstderr.c
	$(CMD_CP) $(PROCESS_DIR)\process_setstderr.c $(OBJS_DIR)\

$(OBJS_DIR)\process_getstderr.c : $(PROCESS_DIR)\process_getstderr.c
	$(CMD_CP) $(PROCESS_DIR)\process_getstderr.c $(OBJS_DIR)\


$(OBJS_DIR)\event.h : $(EVENT_DIR)\event.h
	$(CMD_CP) $(EVENT_DIR)\event.h $(OBJS_DIR)\

$(OBJS_DIR)\event_local.h : $(EVENT_DIR)\event_local.h
	$(CMD_CP) $(EVENT_DIR)\event_local.h $(OBJS_DIR)\

$(OBJS_DIR)\event_create.c : $(EVENT_DIR)\event_create.c
	$(CMD_CP) $(EVENT_DIR)\event_create.c $(OBJS_DIR)\

$(OBJS_DIR)\event_delete.c : $(EVENT_DIR)\event_delete.c
	$(CMD_CP) $(EVENT_DIR)\event_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\event_set.c : $(EVENT_DIR)\event_set.c
	$(CMD_CP) $(EVENT_DIR)\event_set.c $(OBJS_DIR)\

$(OBJS_DIR)\event_clear.c : $(EVENT_DIR)\event_clear.c
	$(CMD_CP) $(EVENT_DIR)\event_clear.c $(OBJS_DIR)\

$(OBJS_DIR)\event_wait.c : $(EVENT_DIR)\event_wait.c
	$(CMD_CP) $(EVENT_DIR)\event_wait.c $(OBJS_DIR)\


$(OBJS_DIR)\console.h : $(FILE_DIR)\console.h
	$(CMD_CP) $(FILE_DIR)\console.h $(OBJS_DIR)\

$(OBJS_DIR)\drvobj.h : $(FILE_DIR)\drvobj.h
	$(CMD_CP) $(FILE_DIR)\drvobj.h $(OBJS_DIR)\

$(OBJS_DIR)\drvobj_local.h : $(FILE_DIR)\drvobj_local.h
	$(CMD_CP) $(FILE_DIR)\drvobj_local.h $(OBJS_DIR)\

$(OBJS_DIR)\file.h : $(FILE_DIR)\file.h
	$(CMD_CP) $(FILE_DIR)\file.h $(OBJS_DIR)\

$(OBJS_DIR)\fileobj.h : $(FILE_DIR)\fileobj.h
	$(CMD_CP) $(FILE_DIR)\fileobj.h $(OBJS_DIR)\

$(OBJS_DIR)\fileobj_local.h : $(FILE_DIR)\fileobj_local.h
	$(CMD_CP) $(FILE_DIR)\fileobj_local.h $(OBJS_DIR)\

$(OBJS_DIR)\file_local.h : $(FILE_DIR)\file_local.h
	$(CMD_CP) $(FILE_DIR)\file_local.h $(OBJS_DIR)\

$(OBJS_DIR)\stdfile.h : $(FILE_DIR)\stdfile.h
	$(CMD_CP) $(FILE_DIR)\stdfile.h $(OBJS_DIR)\

$(OBJS_DIR)\syncdrv.h : $(FILE_DIR)\syncdrv.h
	$(CMD_CP) $(FILE_DIR)\syncdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\syncdrv_local.h : $(FILE_DIR)\syncdrv_local.h
	$(CMD_CP) $(FILE_DIR)\syncdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\syncfile.h : $(FILE_DIR)\syncfile.h
	$(CMD_CP) $(FILE_DIR)\syncfile.h $(OBJS_DIR)\

$(OBJS_DIR)\syncfile_local.h : $(FILE_DIR)\syncfile_local.h
	$(CMD_CP) $(FILE_DIR)\syncfile_local.h $(OBJS_DIR)\

$(OBJS_DIR)\sysvol.h : $(FILE_DIR)\sysvol.h
	$(CMD_CP) $(FILE_DIR)\sysvol.h $(OBJS_DIR)\

$(OBJS_DIR)\sysvolfile.h : $(FILE_DIR)\sysvolfile.h
	$(CMD_CP) $(FILE_DIR)\sysvolfile.h $(OBJS_DIR)\

$(OBJS_DIR)\sysvolfile_local.h : $(FILE_DIR)\sysvolfile_local.h
	$(CMD_CP) $(FILE_DIR)\sysvolfile_local.h $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_local.h : $(FILE_DIR)\sysvol_local.h
	$(CMD_CP) $(FILE_DIR)\sysvol_local.h $(OBJS_DIR)\

$(OBJS_DIR)\volume.h : $(FILE_DIR)\volume.h
	$(CMD_CP) $(FILE_DIR)\volume.h $(OBJS_DIR)\

$(OBJS_DIR)\volumeobj.h : $(FILE_DIR)\volumeobj.h
	$(CMD_CP) $(FILE_DIR)\volumeobj.h $(OBJS_DIR)\

$(OBJS_DIR)\volumeobj_local.h : $(FILE_DIR)\volumeobj_local.h
	$(CMD_CP) $(FILE_DIR)\volumeobj_local.h $(OBJS_DIR)\

$(OBJS_DIR)\console_getch.c : $(FILE_DIR)\console_getch.c
	$(CMD_CP) $(FILE_DIR)\console_getch.c $(OBJS_DIR)\

$(OBJS_DIR)\drvobj_close.c : $(FILE_DIR)\drvobj_close.c
	$(CMD_CP) $(FILE_DIR)\drvobj_close.c $(OBJS_DIR)\

$(OBJS_DIR)\drvobj_constructor.c : $(FILE_DIR)\drvobj_constructor.c
	$(CMD_CP) $(FILE_DIR)\drvobj_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\drvobj_destructor.c : $(FILE_DIR)\drvobj_destructor.c
	$(CMD_CP) $(FILE_DIR)\drvobj_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\drvobj_flush.c : $(FILE_DIR)\drvobj_flush.c
	$(CMD_CP) $(FILE_DIR)\drvobj_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\drvobj_iocontrol.c : $(FILE_DIR)\drvobj_iocontrol.c
	$(CMD_CP) $(FILE_DIR)\drvobj_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\drvobj_open.c : $(FILE_DIR)\drvobj_open.c
	$(CMD_CP) $(FILE_DIR)\drvobj_open.c $(OBJS_DIR)\

$(OBJS_DIR)\drvobj_read.c : $(FILE_DIR)\drvobj_read.c
	$(CMD_CP) $(FILE_DIR)\drvobj_read.c $(OBJS_DIR)\

$(OBJS_DIR)\drvobj_seek.c : $(FILE_DIR)\drvobj_seek.c
	$(CMD_CP) $(FILE_DIR)\drvobj_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\drvobj_write.c : $(FILE_DIR)\drvobj_write.c
	$(CMD_CP) $(FILE_DIR)\drvobj_write.c $(OBJS_DIR)\

$(OBJS_DIR)\fileobj_constructor.c : $(FILE_DIR)\fileobj_constructor.c
	$(CMD_CP) $(FILE_DIR)\fileobj_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\fileobj_create.c : $(FILE_DIR)\fileobj_create.c
	$(CMD_CP) $(FILE_DIR)\fileobj_create.c $(OBJS_DIR)\

$(OBJS_DIR)\fileobj_delete.c : $(FILE_DIR)\fileobj_delete.c
	$(CMD_CP) $(FILE_DIR)\fileobj_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\fileobj_destructor.c : $(FILE_DIR)\fileobj_destructor.c
	$(CMD_CP) $(FILE_DIR)\fileobj_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\file_adddevice.c : $(FILE_DIR)\file_adddevice.c
	$(CMD_CP) $(FILE_DIR)\file_adddevice.c $(OBJS_DIR)\

$(OBJS_DIR)\file_addvolume.c : $(FILE_DIR)\file_addvolume.c
	$(CMD_CP) $(FILE_DIR)\file_addvolume.c $(OBJS_DIR)\

$(OBJS_DIR)\file_removevolume.c : $(FILE_DIR)\file_removevolume.c
	$(CMD_CP) $(FILE_DIR)\file_removevolume.c $(OBJS_DIR)\

$(OBJS_DIR)\file_getvolume.c : $(FILE_DIR)\file_getvolume.c
	$(CMD_CP) $(FILE_DIR)\file_getvolume.c $(OBJS_DIR)\

$(OBJS_DIR)\file_close.c : $(FILE_DIR)\file_close.c
	$(CMD_CP) $(FILE_DIR)\file_close.c $(OBJS_DIR)\

$(OBJS_DIR)\file_getchar.c : $(FILE_DIR)\file_getchar.c
	$(CMD_CP) $(FILE_DIR)\file_getchar.c $(OBJS_DIR)\

$(OBJS_DIR)\file_getstring.c : $(FILE_DIR)\file_getstring.c
	$(CMD_CP) $(FILE_DIR)\file_getstring.c $(OBJS_DIR)\

$(OBJS_DIR)\file_initialize.c : $(FILE_DIR)\file_initialize.c
	$(CMD_CP) $(FILE_DIR)\file_initialize.c $(OBJS_DIR)\

$(OBJS_DIR)\file_iocontrol.c : $(FILE_DIR)\file_iocontrol.c
	$(CMD_CP) $(FILE_DIR)\file_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\file_open.c : $(FILE_DIR)\file_open.c
	$(CMD_CP) $(FILE_DIR)\file_open.c $(OBJS_DIR)\

$(OBJS_DIR)\file_putchar.c : $(FILE_DIR)\file_putchar.c
	$(CMD_CP) $(FILE_DIR)\file_putchar.c $(OBJS_DIR)\

$(OBJS_DIR)\file_putstring.c : $(FILE_DIR)\file_putstring.c
	$(CMD_CP) $(FILE_DIR)\file_putstring.c $(OBJS_DIR)\

$(OBJS_DIR)\file_read.c : $(FILE_DIR)\file_read.c
	$(CMD_CP) $(FILE_DIR)\file_read.c $(OBJS_DIR)\

$(OBJS_DIR)\file_readdir.c : $(FILE_DIR)\file_readdir.c
	$(CMD_CP) $(FILE_DIR)\file_readdir.c $(OBJS_DIR)\

$(OBJS_DIR)\file_seek.c : $(FILE_DIR)\file_seek.c
	$(CMD_CP) $(FILE_DIR)\file_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\file_write.c : $(FILE_DIR)\file_write.c
	$(CMD_CP) $(FILE_DIR)\file_write.c $(OBJS_DIR)\

$(OBJS_DIR)\file_driveropen.c : $(FILE_DIR)\file_driveropen.c
	$(CMD_CP) $(FILE_DIR)\file_driveropen.c $(OBJS_DIR)\

$(OBJS_DIR)\file_relpathtoabspath.c : $(FILE_DIR)\file_relpathtoabspath.c
	$(CMD_CP) $(FILE_DIR)\file_relpathtoabspath.c $(OBJS_DIR)\

$(OBJS_DIR)\file_getdriverinformation.c : $(FILE_DIR)\file_getdriverinformation.c
	$(CMD_CP) $(FILE_DIR)\file_getdriverinformation.c $(OBJS_DIR)\

$(OBJS_DIR)\file_printformat.c : $(FILE_DIR)\file_printformat.c
	$(CMD_CP) $(FILE_DIR)\file_printformat.c $(OBJS_DIR)\

$(OBJS_DIR)\file_printformatv.c : $(FILE_DIR)\file_printformatv.c
	$(CMD_CP) $(FILE_DIR)\file_printformatv.c $(OBJS_DIR)\

$(OBJS_DIR)\stdio_printformat.c : $(FILE_DIR)\stdio_printformat.c
	$(CMD_CP) $(FILE_DIR)\stdio_printformat.c $(OBJS_DIR)\

$(OBJS_DIR)\syncdrv_constructor.c : $(FILE_DIR)\syncdrv_constructor.c
	$(CMD_CP) $(FILE_DIR)\syncdrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\syncdrv_destructor.c : $(FILE_DIR)\syncdrv_destructor.c
	$(CMD_CP) $(FILE_DIR)\syncdrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\syncdrv_endprocess.c : $(FILE_DIR)\syncdrv_endprocess.c
	$(CMD_CP) $(FILE_DIR)\syncdrv_endprocess.c $(OBJS_DIR)\

$(OBJS_DIR)\syncdrv_iocontrol.c : $(FILE_DIR)\syncdrv_iocontrol.c
	$(CMD_CP) $(FILE_DIR)\syncdrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\syncdrv_sendsignal.c : $(FILE_DIR)\syncdrv_sendsignal.c
	$(CMD_CP) $(FILE_DIR)\syncdrv_sendsignal.c $(OBJS_DIR)\

$(OBJS_DIR)\syncdrv_startprocess.c : $(FILE_DIR)\syncdrv_startprocess.c
	$(CMD_CP) $(FILE_DIR)\syncdrv_startprocess.c $(OBJS_DIR)\

$(OBJS_DIR)\syncfile_constructor.c : $(FILE_DIR)\syncfile_constructor.c
	$(CMD_CP) $(FILE_DIR)\syncfile_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\syncfile_create.c : $(FILE_DIR)\syncfile_create.c
	$(CMD_CP) $(FILE_DIR)\syncfile_create.c $(OBJS_DIR)\

$(OBJS_DIR)\syncfile_delete.c : $(FILE_DIR)\syncfile_delete.c
	$(CMD_CP) $(FILE_DIR)\syncfile_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\syncfile_destructor.c : $(FILE_DIR)\syncfile_destructor.c
	$(CMD_CP) $(FILE_DIR)\syncfile_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\syncfile_setsignal.c : $(FILE_DIR)\syncfile_setsignal.c
	$(CMD_CP) $(FILE_DIR)\syncfile_setsignal.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvolfile_constructor.c : $(FILE_DIR)\sysvolfile_constructor.c
	$(CMD_CP) $(FILE_DIR)\sysvolfile_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvolfile_create.c : $(FILE_DIR)\sysvolfile_create.c
	$(CMD_CP) $(FILE_DIR)\sysvolfile_create.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvolfile_delete.c : $(FILE_DIR)\sysvolfile_delete.c
	$(CMD_CP) $(FILE_DIR)\sysvolfile_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvolfile_destructor.c : $(FILE_DIR)\sysvolfile_destructor.c
	$(CMD_CP) $(FILE_DIR)\sysvolfile_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_constructor.c : $(FILE_DIR)\sysvol_constructor.c
	$(CMD_CP) $(FILE_DIR)\sysvol_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_open.c : $(FILE_DIR)\sysvol_open.c
	$(CMD_CP) $(FILE_DIR)\sysvol_open.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_close.c : $(FILE_DIR)\sysvol_close.c
	$(CMD_CP) $(FILE_DIR)\sysvol_close.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_create.c : $(FILE_DIR)\sysvol_create.c
	$(CMD_CP) $(FILE_DIR)\sysvol_create.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_delete.c : $(FILE_DIR)\sysvol_delete.c
	$(CMD_CP) $(FILE_DIR)\sysvol_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_destructor.c : $(FILE_DIR)\sysvol_destructor.c
	$(CMD_CP) $(FILE_DIR)\sysvol_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_iocontrol.c : $(FILE_DIR)\sysvol_iocontrol.c
	$(CMD_CP) $(FILE_DIR)\sysvol_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_adddevice.c : $(FILE_DIR)\sysvol_adddevice.c
	$(CMD_CP) $(FILE_DIR)\sysvol_adddevice.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_removedevice.c : $(FILE_DIR)\sysvol_removedevice.c
	$(CMD_CP) $(FILE_DIR)\sysvol_removedevice.c $(OBJS_DIR)\

$(OBJS_DIR)\sysvol_getdevice.c : $(FILE_DIR)\sysvol_getdevice.c
	$(CMD_CP) $(FILE_DIR)\sysvol_getdevice.c $(OBJS_DIR)\

$(OBJS_DIR)\volume_shutdown.c : $(FILE_DIR)\volume_shutdown.c
	$(CMD_CP) $(FILE_DIR)\volume_shutdown.c $(OBJS_DIR)\

$(OBJS_DIR)\volumeobj_constructor.c : $(FILE_DIR)\volumeobj_constructor.c
	$(CMD_CP) $(FILE_DIR)\volumeobj_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\volumeobj_create.c : $(FILE_DIR)\volumeobj_create.c
	$(CMD_CP) $(FILE_DIR)\volumeobj_create.c $(OBJS_DIR)\

$(OBJS_DIR)\volumeobj_delete.c : $(FILE_DIR)\volumeobj_delete.c
	$(CMD_CP) $(FILE_DIR)\volumeobj_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\volumeobj_destructor.c : $(FILE_DIR)\volumeobj_destructor.c
	$(CMD_CP) $(FILE_DIR)\volumeobj_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\volumeobj_shutdown.c : $(FILE_DIR)\volumeobj_shutdown.c
	$(CMD_CP) $(FILE_DIR)\volumeobj_shutdown.c $(OBJS_DIR)\

$(OBJS_DIR)\volumeobj_makedir.c : $(FILE_DIR)\volumeobj_makedir.c
	$(CMD_CP) $(FILE_DIR)\volumeobj_makedir.c $(OBJS_DIR)\

$(OBJS_DIR)\volumeobj_remove.c : $(FILE_DIR)\volumeobj_remove.c
	$(CMD_CP) $(FILE_DIR)\volumeobj_remove.c $(OBJS_DIR)\


$(OBJS_DIR)\command.h : $(COMMAND_DIR)\command.h
	$(CMD_CP) $(COMMAND_DIR)\command.h $(OBJS_DIR)\

$(OBJS_DIR)\command.c : $(COMMAND_DIR)\command.c
	$(CMD_CP) $(COMMAND_DIR)\command.c $(OBJS_DIR)\


$(OBJS_DIR)\valmemheap.h : $(VALMEMHEAP_DIR)\valmemheap.h
	$(CMD_CP) $(VALMEMHEAP_DIR)\valmemheap.h $(OBJS_DIR)\

$(OBJS_DIR)\valmemheap_local.h : $(VALMEMHEAP_DIR)\valmemheap_local.h
	$(CMD_CP) $(VALMEMHEAP_DIR)\valmemheap_local.h $(OBJS_DIR)\

$(OBJS_DIR)\valmemheap_constructor.c : $(VALMEMHEAP_DIR)\valmemheap_constructor.c
	$(CMD_CP) $(VALMEMHEAP_DIR)\valmemheap_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\valmemheap_alloc.c : $(VALMEMHEAP_DIR)\valmemheap_alloc.c
	$(CMD_CP) $(VALMEMHEAP_DIR)\valmemheap_alloc.c $(OBJS_DIR)\

$(OBJS_DIR)\valmemheap_realloc.c : $(VALMEMHEAP_DIR)\valmemheap_realloc.c
	$(CMD_CP) $(VALMEMHEAP_DIR)\valmemheap_realloc.c $(OBJS_DIR)\

$(OBJS_DIR)\valmemheap_free.c : $(VALMEMHEAP_DIR)\valmemheap_free.c
	$(CMD_CP) $(VALMEMHEAP_DIR)\valmemheap_free.c $(OBJS_DIR)\

$(OBJS_DIR)\valmemheap_getalign.c : $(VALMEMHEAP_DIR)\valmemheap_getalign.c
	$(CMD_CP) $(VALMEMHEAP_DIR)\valmemheap_getalign.c $(OBJS_DIR)\

$(OBJS_DIR)\valmemheap_getsize.c : $(VALMEMHEAP_DIR)\valmemheap_getsize.c
	$(CMD_CP) $(VALMEMHEAP_DIR)\valmemheap_getsize.c $(OBJS_DIR)\

$(OBJS_DIR)\valmemheap_alignsize.c : $(VALMEMHEAP_DIR)\valmemheap_alignsize.c
	$(CMD_CP) $(VALMEMHEAP_DIR)\valmemheap_alignsize.c $(OBJS_DIR)\

$(OBJS_DIR)\valmemheap_ismember.c : $(VALMEMHEAP_DIR)\valmemheap_ismember.c
	$(CMD_CP) $(VALMEMHEAP_DIR)\valmemheap_ismember.c $(OBJS_DIR)\


$(OBJS_DIR)\fixmemheap.h : $(FIXMEMHEAP_DIR)\fixmemheap.h
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap.h $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_local.h : $(FIXMEMHEAP_DIR)\fixmemheap_local.h
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_local.h $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_create.c : $(FIXMEMHEAP_DIR)\fixmemheap_create.c
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_create.c $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_delete.c : $(FIXMEMHEAP_DIR)\fixmemheap_delete.c
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_constructor.c : $(FIXMEMHEAP_DIR)\fixmemheap_constructor.c
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_alloc.c : $(FIXMEMHEAP_DIR)\fixmemheap_alloc.c
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_alloc.c $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_realloc.c : $(FIXMEMHEAP_DIR)\fixmemheap_realloc.c
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_realloc.c $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_free.c : $(FIXMEMHEAP_DIR)\fixmemheap_free.c
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_free.c $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_getalign.c : $(FIXMEMHEAP_DIR)\fixmemheap_getalign.c
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_getalign.c $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_getsize.c : $(FIXMEMHEAP_DIR)\fixmemheap_getsize.c
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_getsize.c $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_alignsize.c : $(FIXMEMHEAP_DIR)\fixmemheap_alignsize.c
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_alignsize.c $(OBJS_DIR)\

$(OBJS_DIR)\fixmemheap_ismember.c : $(FIXMEMHEAP_DIR)\fixmemheap_ismember.c
	$(CMD_CP) $(FIXMEMHEAP_DIR)\fixmemheap_ismember.c $(OBJS_DIR)\


$(OBJS_DIR)\automemheap.h : $(AUTOMEMHEAP_DIR)\automemheap.h
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap.h $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_local.h : $(AUTOMEMHEAP_DIR)\automemheap_local.h
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_local.h $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_alignsize.c : $(AUTOMEMHEAP_DIR)\automemheap_alignsize.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_alignsize.c $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_alloc.c : $(AUTOMEMHEAP_DIR)\automemheap_alloc.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_alloc.c $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_constructor.c : $(AUTOMEMHEAP_DIR)\automemheap_constructor.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_create.c : $(AUTOMEMHEAP_DIR)\automemheap_create.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_create.c $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_delete.c : $(AUTOMEMHEAP_DIR)\automemheap_delete.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_destructor.c : $(AUTOMEMHEAP_DIR)\automemheap_destructor.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_free.c : $(AUTOMEMHEAP_DIR)\automemheap_free.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_free.c $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_getalign.c : $(AUTOMEMHEAP_DIR)\automemheap_getalign.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_getalign.c $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_getsize.c : $(AUTOMEMHEAP_DIR)\automemheap_getsize.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_getsize.c $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_realloc.c : $(AUTOMEMHEAP_DIR)\automemheap_realloc.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_realloc.c $(OBJS_DIR)\

$(OBJS_DIR)\automemheap_searchheap.c : $(AUTOMEMHEAP_DIR)\automemheap_searchheap.c
	$(CMD_CP) $(AUTOMEMHEAP_DIR)\automemheap_searchheap.c $(OBJS_DIR)\


$(OBJS_DIR)\assoc.h : $(ASSOC_DIR)\assoc.h
	$(CMD_CP) $(ASSOC_DIR)\assoc.h $(OBJS_DIR)\

$(OBJS_DIR)\assoc_local.h : $(ASSOC_DIR)\assoc_local.h
	$(CMD_CP) $(ASSOC_DIR)\assoc_local.h $(OBJS_DIR)\

$(OBJS_DIR)\assoc_create.c : $(ASSOC_DIR)\assoc_create.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_create.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_createex.c : $(ASSOC_DIR)\assoc_createex.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_createex.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_delete.c : $(ASSOC_DIR)\assoc_delete.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_constructor.c : $(ASSOC_DIR)\assoc_constructor.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_destructor.c : $(ASSOC_DIR)\assoc_destructor.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_add.c : $(ASSOC_DIR)\assoc_add.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_add.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_set.c : $(ASSOC_DIR)\assoc_set.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_set.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_get.c : $(ASSOC_DIR)\assoc_get.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_get.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_getat.c : $(ASSOC_DIR)\assoc_getat.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_getat.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_getfirst.c : $(ASSOC_DIR)\assoc_getfirst.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_getfirst.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_getpos.c : $(ASSOC_DIR)\assoc_getpos.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_getpos.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_getnext.c : $(ASSOC_DIR)\assoc_getnext.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_getnext.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_remove.c : $(ASSOC_DIR)\assoc_remove.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_remove.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_addnode.c : $(ASSOC_DIR)\assoc_addnode.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_addnode.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_getnode.c : $(ASSOC_DIR)\assoc_getnode.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_getnode.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_removenode.c : $(ASSOC_DIR)\assoc_removenode.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_removenode.c $(OBJS_DIR)\

$(OBJS_DIR)\assoc_getminnode.c : $(ASSOC_DIR)\assoc_getminnode.c
	$(CMD_CP) $(ASSOC_DIR)\assoc_getminnode.c $(OBJS_DIR)\


$(OBJS_DIR)\hashtable.h : $(HASHTABLE_DIR)\hashtable.h
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable.h $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_local.h : $(HASHTABLE_DIR)\hashtable_local.h
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_local.h $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_create.c : $(HASHTABLE_DIR)\hashtable_create.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_create.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_createex.c : $(HASHTABLE_DIR)\hashtable_createex.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_createex.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_delete.c : $(HASHTABLE_DIR)\hashtable_delete.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_constructor.c : $(HASHTABLE_DIR)\hashtable_constructor.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_destructor.c : $(HASHTABLE_DIR)\hashtable_destructor.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_get.c : $(HASHTABLE_DIR)\hashtable_get.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_get.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_set.c : $(HASHTABLE_DIR)\hashtable_set.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_set.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_remove.c : $(HASHTABLE_DIR)\hashtable_remove.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_remove.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_removeall.c : $(HASHTABLE_DIR)\hashtable_removeall.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_removeall.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_findclose.c : $(HASHTABLE_DIR)\hashtable_findclose.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_findclose.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_findnext.c : $(HASHTABLE_DIR)\hashtable_findnext.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_findnext.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_findopen.c : $(HASHTABLE_DIR)\hashtable_findopen.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_findopen.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_searchnode.c : $(HASHTABLE_DIR)\hashtable_searchnode.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_searchnode.c $(OBJS_DIR)\

$(OBJS_DIR)\hashtable_createnode.c : $(HASHTABLE_DIR)\hashtable_createnode.c
	$(CMD_CP) $(HASHTABLE_DIR)\hashtable_createnode.c $(OBJS_DIR)\


$(OBJS_DIR)\list.h : $(LIST_DIR)\list.h
	$(CMD_CP) $(LIST_DIR)\list.h $(OBJS_DIR)\

$(OBJS_DIR)\list_local.h : $(LIST_DIR)\list_local.h
	$(CMD_CP) $(LIST_DIR)\list_local.h $(OBJS_DIR)\

$(OBJS_DIR)\list_create.c : $(LIST_DIR)\list_create.c
	$(CMD_CP) $(LIST_DIR)\list_create.c $(OBJS_DIR)\

$(OBJS_DIR)\list_createex.c : $(LIST_DIR)\list_createex.c
	$(CMD_CP) $(LIST_DIR)\list_createex.c $(OBJS_DIR)\

$(OBJS_DIR)\list_addtail.c : $(LIST_DIR)\list_addtail.c
	$(CMD_CP) $(LIST_DIR)\list_addtail.c $(OBJS_DIR)\

$(OBJS_DIR)\list_getat.c : $(LIST_DIR)\list_getat.c
	$(CMD_CP) $(LIST_DIR)\list_getat.c $(OBJS_DIR)\

$(OBJS_DIR)\list_getheadpos.c : $(LIST_DIR)\list_getheadpos.c
	$(CMD_CP) $(LIST_DIR)\list_getheadpos.c $(OBJS_DIR)\

$(OBJS_DIR)\list_getnextpos.c : $(LIST_DIR)\list_getnextpos.c
	$(CMD_CP) $(LIST_DIR)\list_getnextpos.c $(OBJS_DIR)\

$(OBJS_DIR)\list_getprevpos.c : $(LIST_DIR)\list_getprevpos.c
	$(CMD_CP) $(LIST_DIR)\list_getprevpos.c $(OBJS_DIR)\

$(OBJS_DIR)\list_gettailpos.c : $(LIST_DIR)\list_gettailpos.c
	$(CMD_CP) $(LIST_DIR)\list_gettailpos.c $(OBJS_DIR)\

$(OBJS_DIR)\list_remove.c : $(LIST_DIR)\list_remove.c
	$(CMD_CP) $(LIST_DIR)\list_remove.c $(OBJS_DIR)\


$(OBJS_DIR)\streambuf.h : $(STREAMBUF_DIR)\streambuf.h
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf.h $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_local.h : $(STREAMBUF_DIR)\streambuf_local.h
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_local.h $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_create.c : $(STREAMBUF_DIR)\streambuf_create.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_create.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_getbuf.c : $(STREAMBUF_DIR)\streambuf_getbuf.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_getbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_sendbuf.c : $(STREAMBUF_DIR)\streambuf_sendbuf.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_sendbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_senddata.c : $(STREAMBUF_DIR)\streambuf_senddata.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_senddata.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_sendchar.c : $(STREAMBUF_DIR)\streambuf_sendchar.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_sendchar.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_recvbuf.c : $(STREAMBUF_DIR)\streambuf_recvbuf.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_recvbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_relbuf.c : $(STREAMBUF_DIR)\streambuf_relbuf.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_relbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_recvdata.c : $(STREAMBUF_DIR)\streambuf_recvdata.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_recvdata.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_recvchar.c : $(STREAMBUF_DIR)\streambuf_recvchar.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_recvchar.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_clear.c : $(STREAMBUF_DIR)\streambuf_clear.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_clear.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_refdatasize.c : $(STREAMBUF_DIR)\streambuf_refdatasize.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_refdatasize.c $(OBJS_DIR)\

$(OBJS_DIR)\streambuf_reffreesize.c : $(STREAMBUF_DIR)\streambuf_reffreesize.c
	$(CMD_CP) $(STREAMBUF_DIR)\streambuf_reffreesize.c $(OBJS_DIR)\


$(OBJS_DIR)\packetbuf.h : $(PACKETBUF_DIR)\packetbuf.h
	$(CMD_CP) $(PACKETBUF_DIR)\packetbuf.h $(OBJS_DIR)\

$(OBJS_DIR)\packetbuf_local.h : $(PACKETBUF_DIR)\packetbuf_local.h
	$(CMD_CP) $(PACKETBUF_DIR)\packetbuf_local.h $(OBJS_DIR)\

$(OBJS_DIR)\packetbuf_create.c : $(PACKETBUF_DIR)\packetbuf_create.c
	$(CMD_CP) $(PACKETBUF_DIR)\packetbuf_create.c $(OBJS_DIR)\

$(OBJS_DIR)\packetbuf_getbuf.c : $(PACKETBUF_DIR)\packetbuf_getbuf.c
	$(CMD_CP) $(PACKETBUF_DIR)\packetbuf_getbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\packetbuf_sendbuf.c : $(PACKETBUF_DIR)\packetbuf_sendbuf.c
	$(CMD_CP) $(PACKETBUF_DIR)\packetbuf_sendbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\packetbuf_senddata.c : $(PACKETBUF_DIR)\packetbuf_senddata.c
	$(CMD_CP) $(PACKETBUF_DIR)\packetbuf_senddata.c $(OBJS_DIR)\

$(OBJS_DIR)\packetbuf_recvbuf.c : $(PACKETBUF_DIR)\packetbuf_recvbuf.c
	$(CMD_CP) $(PACKETBUF_DIR)\packetbuf_recvbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\packetbuf_relbuf.c : $(PACKETBUF_DIR)\packetbuf_relbuf.c
	$(CMD_CP) $(PACKETBUF_DIR)\packetbuf_relbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\packetbuf_recvdata.c : $(PACKETBUF_DIR)\packetbuf_recvdata.c
	$(CMD_CP) $(PACKETBUF_DIR)\packetbuf_recvdata.c $(OBJS_DIR)\

$(OBJS_DIR)\packetbuf_clear.c : $(PACKETBUF_DIR)\packetbuf_clear.c
	$(CMD_CP) $(PACKETBUF_DIR)\packetbuf_clear.c $(OBJS_DIR)\


$(OBJS_DIR)\ipchecksum.h : $(IPCHECKSUM_DIR)\ipchecksum.h
	$(CMD_CP) $(IPCHECKSUM_DIR)\ipchecksum.h $(OBJS_DIR)\

$(OBJS_DIR)\ipchecksum_local.h : $(IPCHECKSUM_DIR)\ipchecksum_local.h
	$(CMD_CP) $(IPCHECKSUM_DIR)\ipchecksum_local.h $(OBJS_DIR)\

$(OBJS_DIR)\ipchecksum_getdigest.c : $(IPCHECKSUM_DIR)\ipchecksum_getdigest.c
	$(CMD_CP) $(IPCHECKSUM_DIR)\ipchecksum_getdigest.c $(OBJS_DIR)\

$(OBJS_DIR)\ipchecksum_update.c : $(IPCHECKSUM_DIR)\ipchecksum_update.c
	$(CMD_CP) $(IPCHECKSUM_DIR)\ipchecksum_update.c $(OBJS_DIR)\


$(OBJS_DIR)\crc16.h : $(CRC16_DIR)\crc16.h
	$(CMD_CP) $(CRC16_DIR)\crc16.h $(OBJS_DIR)\

$(OBJS_DIR)\crc16_local.h : $(CRC16_DIR)\crc16_local.h
	$(CMD_CP) $(CRC16_DIR)\crc16_local.h $(OBJS_DIR)\

$(OBJS_DIR)\crc16_getdigest.c : $(CRC16_DIR)\crc16_getdigest.c
	$(CMD_CP) $(CRC16_DIR)\crc16_getdigest.c $(OBJS_DIR)\

$(OBJS_DIR)\crc16_update.c : $(CRC16_DIR)\crc16_update.c
	$(CMD_CP) $(CRC16_DIR)\crc16_update.c $(OBJS_DIR)\

$(OBJS_DIR)\crc16_reset.c : $(CRC16_DIR)\crc16_reset.c
	$(CMD_CP) $(CRC16_DIR)\crc16_reset.c $(OBJS_DIR)\

$(OBJS_DIR)\crc16_table.c : $(CRC16_DIR)\crc16_table.c
	$(CMD_CP) $(CRC16_DIR)\crc16_table.c $(OBJS_DIR)\


$(OBJS_DIR)\stringformat.h : $(STRINGFORMAT_DIR)\stringformat.h
	$(CMD_CP) $(STRINGFORMAT_DIR)\stringformat.h $(OBJS_DIR)\

$(OBJS_DIR)\stringformat_local.h : $(STRINGFORMAT_DIR)\stringformat_local.h
	$(CMD_CP) $(STRINGFORMAT_DIR)\stringformat_local.h $(OBJS_DIR)\

$(OBJS_DIR)\stringformat_formatstring.c : $(STRINGFORMAT_DIR)\stringformat_formatstring.c
	$(CMD_CP) $(STRINGFORMAT_DIR)\stringformat_formatstring.c $(OBJS_DIR)\

$(OBJS_DIR)\stringformat_formatstringv.c : $(STRINGFORMAT_DIR)\stringformat_formatstringv.c
	$(CMD_CP) $(STRINGFORMAT_DIR)\stringformat_formatstringv.c $(OBJS_DIR)\

$(OBJS_DIR)\stringformat_format.c : $(STRINGFORMAT_DIR)\stringformat_format.c
	$(CMD_CP) $(STRINGFORMAT_DIR)\stringformat_format.c $(OBJS_DIR)\

$(OBJS_DIR)\stringformat_formatv.c : $(STRINGFORMAT_DIR)\stringformat_formatv.c
	$(CMD_CP) $(STRINGFORMAT_DIR)\stringformat_formatv.c $(OBJS_DIR)\

$(OBJS_DIR)\stringformat_string.c : $(STRINGFORMAT_DIR)\stringformat_string.c
	$(CMD_CP) $(STRINGFORMAT_DIR)\stringformat_string.c $(OBJS_DIR)\

$(OBJS_DIR)\stringformat_decimal.c : $(STRINGFORMAT_DIR)\stringformat_decimal.c
	$(CMD_CP) $(STRINGFORMAT_DIR)\stringformat_decimal.c $(OBJS_DIR)\

$(OBJS_DIR)\stringformat_hexadecimal.c : $(STRINGFORMAT_DIR)\stringformat_hexadecimal.c
	$(CMD_CP) $(STRINGFORMAT_DIR)\stringformat_hexadecimal.c $(OBJS_DIR)\

$(OBJS_DIR)\stringformat_nibble.c : $(STRINGFORMAT_DIR)\stringformat_nibble.c
	$(CMD_CP) $(STRINGFORMAT_DIR)\stringformat_nibble.c $(OBJS_DIR)\


$(OBJS_DIR)\memutil.h : $(MEMUTIL_DIR)\memutil.h
	$(CMD_CP) $(MEMUTIL_DIR)\memutil.h $(OBJS_DIR)\

$(OBJS_DIR)\memutil_memcopyb.c : $(MEMUTIL_DIR)\memutil_memcopyb.c
	$(CMD_CP) $(MEMUTIL_DIR)\memutil_memcopyb.c $(OBJS_DIR)\

$(OBJS_DIR)\memutil_memcopyh.c : $(MEMUTIL_DIR)\memutil_memcopyh.c
	$(CMD_CP) $(MEMUTIL_DIR)\memutil_memcopyh.c $(OBJS_DIR)\

$(OBJS_DIR)\memutil_memcopyw.c : $(MEMUTIL_DIR)\memutil_memcopyw.c
	$(CMD_CP) $(MEMUTIL_DIR)\memutil_memcopyw.c $(OBJS_DIR)\

$(OBJS_DIR)\memutil_memsetb.c : $(MEMUTIL_DIR)\memutil_memsetb.c
	$(CMD_CP) $(MEMUTIL_DIR)\memutil_memsetb.c $(OBJS_DIR)\

$(OBJS_DIR)\memutil_memseth.c : $(MEMUTIL_DIR)\memutil_memseth.c
	$(CMD_CP) $(MEMUTIL_DIR)\memutil_memseth.c $(OBJS_DIR)\

$(OBJS_DIR)\memutil_memsetw.c : $(MEMUTIL_DIR)\memutil_memsetw.c
	$(CMD_CP) $(MEMUTIL_DIR)\memutil_memsetw.c $(OBJS_DIR)\


$(OBJS_DIR)\vt100drv.h : $(VT100_DIR)\vt100drv.h
	$(CMD_CP) $(VT100_DIR)\vt100drv.h $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_local.h : $(VT100_DIR)\vt100drv_local.h
	$(CMD_CP) $(VT100_DIR)\vt100drv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_create.c : $(VT100_DIR)\vt100drv_create.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_delete.c : $(VT100_DIR)\vt100drv_delete.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_constructor.c : $(VT100_DIR)\vt100drv_constructor.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_destructor.c : $(VT100_DIR)\vt100drv_destructor.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_open.c : $(VT100_DIR)\vt100drv_open.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_close.c : $(VT100_DIR)\vt100drv_close.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_iocontrol.c : $(VT100_DIR)\vt100drv_iocontrol.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_seek.c : $(VT100_DIR)\vt100drv_seek.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_read.c : $(VT100_DIR)\vt100drv_read.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_write.c : $(VT100_DIR)\vt100drv_write.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_flush.c : $(VT100_DIR)\vt100drv_flush.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\vt100drv_getch.c : $(VT100_DIR)\vt100drv_getch.c
	$(CMD_CP) $(VT100_DIR)\vt100drv_getch.c $(OBJS_DIR)\


$(OBJS_DIR)\pcattextdrv.h : $(PCATTEXT_DIR)\pcattextdrv.h
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_local.h : $(PCATTEXT_DIR)\pcattextdrv_local.h
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_create.c : $(PCATTEXT_DIR)\pcattextdrv_create.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_delete.c : $(PCATTEXT_DIR)\pcattextdrv_delete.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_constructor.c : $(PCATTEXT_DIR)\pcattextdrv_constructor.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_destructor.c : $(PCATTEXT_DIR)\pcattextdrv_destructor.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_open.c : $(PCATTEXT_DIR)\pcattextdrv_open.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_close.c : $(PCATTEXT_DIR)\pcattextdrv_close.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_iocontrol.c : $(PCATTEXT_DIR)\pcattextdrv_iocontrol.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_write.c : $(PCATTEXT_DIR)\pcattextdrv_write.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_putchar.c : $(PCATTEXT_DIR)\pcattextdrv_putchar.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_putchar.c $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_setcursor.c : $(PCATTEXT_DIR)\pcattextdrv_setcursor.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_setcursor.c $(OBJS_DIR)\

$(OBJS_DIR)\pcattextdrv_clearscreen.c : $(PCATTEXT_DIR)\pcattextdrv_clearscreen.c
	$(CMD_CP) $(PCATTEXT_DIR)\pcattextdrv_clearscreen.c $(OBJS_DIR)\


$(OBJS_DIR)\pcatkeydrv.h : $(PCATKEY_DIR)\pcatkeydrv.h
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv.h $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_local.h : $(PCATKEY_DIR)\pcatkeydrv_local.h
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_create.c : $(PCATKEY_DIR)\pcatkeydrv_create.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_delete.c : $(PCATKEY_DIR)\pcatkeydrv_delete.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_constructor.c : $(PCATKEY_DIR)\pcatkeydrv_constructor.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_destructor.c : $(PCATKEY_DIR)\pcatkeydrv_destructor.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_open.c : $(PCATKEY_DIR)\pcatkeydrv_open.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_close.c : $(PCATKEY_DIR)\pcatkeydrv_close.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_iocontrol.c : $(PCATKEY_DIR)\pcatkeydrv_iocontrol.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_seek.c : $(PCATKEY_DIR)\pcatkeydrv_seek.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_read.c : $(PCATKEY_DIR)\pcatkeydrv_read.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_write.c : $(PCATKEY_DIR)\pcatkeydrv_write.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\pcatkeydrv_flush.c : $(PCATKEY_DIR)\pcatkeydrv_flush.c
	$(CMD_CP) $(PCATKEY_DIR)\pcatkeydrv_flush.c $(OBJS_DIR)\


$(OBJS_DIR)\tcpip.h : $(TCPIP_DIR)\tcpip.h
	$(CMD_CP) $(TCPIP_DIR)\tcpip.h $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_local.h : $(TCPIP_DIR)\tcpip_local.h
	$(CMD_CP) $(TCPIP_DIR)\tcpip_local.h $(OBJS_DIR)\

$(OBJS_DIR)\tcpipfile.h : $(TCPIP_DIR)\tcpipfile.h
	$(CMD_CP) $(TCPIP_DIR)\tcpipfile.h $(OBJS_DIR)\

$(OBJS_DIR)\tcpipfile_local.h : $(TCPIP_DIR)\tcpipfile_local.h
	$(CMD_CP) $(TCPIP_DIR)\tcpipfile_local.h $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_create.c : $(TCPIP_DIR)\tcpip_create.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_create.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_delete.c : $(TCPIP_DIR)\tcpip_delete.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_constructor.c : $(TCPIP_DIR)\tcpip_constructor.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_destructor.c : $(TCPIP_DIR)\tcpip_destructor.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_open.c : $(TCPIP_DIR)\tcpip_open.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_open.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_close.c : $(TCPIP_DIR)\tcpip_close.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_close.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_iocontrol.c : $(TCPIP_DIR)\tcpip_iocontrol.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_seek.c : $(TCPIP_DIR)\tcpip_seek.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_read.c : $(TCPIP_DIR)\tcpip_read.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_read.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_write.c : $(TCPIP_DIR)\tcpip_write.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_write.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_flush.c : $(TCPIP_DIR)\tcpip_flush.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_recv.c : $(TCPIP_DIR)\tcpip_recv.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_recv.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpip_stringtoaddr.c : $(TCPIP_DIR)\tcpip_stringtoaddr.c
	$(CMD_CP) $(TCPIP_DIR)\tcpip_stringtoaddr.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpipfile_create.c : $(TCPIP_DIR)\tcpipfile_create.c
	$(CMD_CP) $(TCPIP_DIR)\tcpipfile_create.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpipfile_delete.c : $(TCPIP_DIR)\tcpipfile_delete.c
	$(CMD_CP) $(TCPIP_DIR)\tcpipfile_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpipfile_constructor.c : $(TCPIP_DIR)\tcpipfile_constructor.c
	$(CMD_CP) $(TCPIP_DIR)\tcpipfile_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\tcpipfile_destructor.c : $(TCPIP_DIR)\tcpipfile_destructor.c
	$(CMD_CP) $(TCPIP_DIR)\tcpipfile_destructor.c $(OBJS_DIR)\


$(OBJS_DIR)\ipether.h : $(IPETHER_DIR)\ipether.h
	$(CMD_CP) $(IPETHER_DIR)\ipether.h $(OBJS_DIR)\

$(OBJS_DIR)\ipether_local.h : $(IPETHER_DIR)\ipether_local.h
	$(CMD_CP) $(IPETHER_DIR)\ipether_local.h $(OBJS_DIR)\

$(OBJS_DIR)\ipether_create.c : $(IPETHER_DIR)\ipether_create.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_create.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_delete.c : $(IPETHER_DIR)\ipether_delete.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_constructor.c : $(IPETHER_DIR)\ipether_constructor.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_destructor.c : $(IPETHER_DIR)\ipether_destructor.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_open.c : $(IPETHER_DIR)\ipether_open.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_open.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_close.c : $(IPETHER_DIR)\ipether_close.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_close.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_iocontrol.c : $(IPETHER_DIR)\ipether_iocontrol.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_seek.c : $(IPETHER_DIR)\ipether_seek.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_read.c : $(IPETHER_DIR)\ipether_read.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_read.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_write.c : $(IPETHER_DIR)\ipether_write.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_write.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_recv.c : $(IPETHER_DIR)\ipether_recv.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_recv.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_flush.c : $(IPETHER_DIR)\ipether_flush.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\ipether_getmacaddr.c : $(IPETHER_DIR)\ipether_getmacaddr.c
	$(CMD_CP) $(IPETHER_DIR)\ipether_getmacaddr.c $(OBJS_DIR)\


$(OBJS_DIR)\ne2000drv.h : $(NE2000_DIR)\ne2000drv.h
	$(CMD_CP) $(NE2000_DIR)\ne2000drv.h $(OBJS_DIR)\

$(OBJS_DIR)\ne2000hal.h : $(NE2000_DIR)\ne2000hal.h
	$(CMD_CP) $(NE2000_DIR)\ne2000hal.h $(OBJS_DIR)\

$(OBJS_DIR)\ne2000drv.c : $(NE2000_DIR)\ne2000drv.c
	$(CMD_CP) $(NE2000_DIR)\ne2000drv.c $(OBJS_DIR)\

$(OBJS_DIR)\ne2000hal.c : $(NE2000_DIR)\ne2000hal.c
	$(CMD_CP) $(NE2000_DIR)\ne2000hal.c $(OBJS_DIR)\


$(OBJS_DIR)\lan9000drv.h : $(LAN9000_DIR)\lan9000drv.h
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv.h $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_local.h : $(LAN9000_DIR)\lan9000drv_local.h
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal.h : $(LAN9000_DIR)\lan9000hal.h
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal.h $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_local.h : $(LAN9000_DIR)\lan9000hal_local.h
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_local.h $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_close.c : $(LAN9000_DIR)\lan9000drv_close.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_create.c : $(LAN9000_DIR)\lan9000drv_create.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_delete.c : $(LAN9000_DIR)\lan9000drv_delete.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_constructor.c : $(LAN9000_DIR)\lan9000drv_constructor.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_destructor.c : $(LAN9000_DIR)\lan9000drv_destructor.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_flush.c : $(LAN9000_DIR)\lan9000drv_flush.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_iocontrol.c : $(LAN9000_DIR)\lan9000drv_iocontrol.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_isr.c : $(LAN9000_DIR)\lan9000drv_isr.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_isr.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_open.c : $(LAN9000_DIR)\lan9000drv_open.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_read.c : $(LAN9000_DIR)\lan9000drv_read.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_seek.c : $(LAN9000_DIR)\lan9000drv_seek.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000drv_write.c : $(LAN9000_DIR)\lan9000drv_write.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000drv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_create.c : $(LAN9000_DIR)\lan9000hal_create.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_create.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_delete.c : $(LAN9000_DIR)\lan9000hal_delete.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_getinterruptstatus.c : $(LAN9000_DIR)\lan9000hal_getinterruptstatus.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_getinterruptstatus.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_getphysicaladdr.c : $(LAN9000_DIR)\lan9000hal_getphysicaladdr.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_getphysicaladdr.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_mii.c : $(LAN9000_DIR)\lan9000hal_mii.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_mii.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_phyregread.c : $(LAN9000_DIR)\lan9000hal_phyregread.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_phyregread.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_phyregwrite.c : $(LAN9000_DIR)\lan9000hal_phyregwrite.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_phyregwrite.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_recv.c : $(LAN9000_DIR)\lan9000hal_recv.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_recv.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_send.c : $(LAN9000_DIR)\lan9000hal_send.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_send.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_setinterruptmask.c : $(LAN9000_DIR)\lan9000hal_setinterruptmask.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_setinterruptmask.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_setup.c : $(LAN9000_DIR)\lan9000hal_setup.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_setup.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9000hal_stop.c : $(LAN9000_DIR)\lan9000hal_stop.c
	$(CMD_CP) $(LAN9000_DIR)\lan9000hal_stop.c $(OBJS_DIR)\


$(OBJS_DIR)\lan9118drv.h : $(LAN9118_DIR)\lan9118drv.h
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv.h $(OBJS_DIR)\

$(OBJS_DIR)\lan9118drv_create.c : $(LAN9118_DIR)\lan9118drv_create.c
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9118drv_delete.c : $(LAN9118_DIR)\lan9118drv_delete.c
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9118drv_open.c : $(LAN9118_DIR)\lan9118drv_open.c
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9118drv_close.c : $(LAN9118_DIR)\lan9118drv_close.c
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9118drv_iocontrol.c : $(LAN9118_DIR)\lan9118drv_iocontrol.c
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9118drv_seek.c : $(LAN9118_DIR)\lan9118drv_seek.c
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9118drv_read.c : $(LAN9118_DIR)\lan9118drv_read.c
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9118drv_write.c : $(LAN9118_DIR)\lan9118drv_write.c
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9118drv_flush.c : $(LAN9118_DIR)\lan9118drv_flush.c
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\lan9118drv_isr.c : $(LAN9118_DIR)\lan9118drv_isr.c
	$(CMD_CP) $(LAN9118_DIR)\lan9118drv_isr.c $(OBJS_DIR)\


$(OBJS_DIR)\pc16550drv.h : $(PC16550_DIR)\pc16550drv.h
	$(CMD_CP) $(PC16550_DIR)\pc16550drv.h $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_local.h : $(PC16550_DIR)\pc16550drv_local.h
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal.h : $(PC16550_DIR)\pc16550hal.h
	$(CMD_CP) $(PC16550_DIR)\pc16550hal.h $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_local.h : $(PC16550_DIR)\pc16550hal_local.h
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_local.h $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_create.c : $(PC16550_DIR)\pc16550drv_create.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_delete.c : $(PC16550_DIR)\pc16550drv_delete.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_constructor.c : $(PC16550_DIR)\pc16550drv_constructor.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_destructor.c : $(PC16550_DIR)\pc16550drv_destructor.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_open.c : $(PC16550_DIR)\pc16550drv_open.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_close.c : $(PC16550_DIR)\pc16550drv_close.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_iocontrol.c : $(PC16550_DIR)\pc16550drv_iocontrol.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_seek.c : $(PC16550_DIR)\pc16550drv_seek.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_read.c : $(PC16550_DIR)\pc16550drv_read.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_write.c : $(PC16550_DIR)\pc16550drv_write.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_flush.c : $(PC16550_DIR)\pc16550drv_flush.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550drv_isr.c : $(PC16550_DIR)\pc16550drv_isr.c
	$(CMD_CP) $(PC16550_DIR)\pc16550drv_isr.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_create.c : $(PC16550_DIR)\pc16550hal_create.c
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_create.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_delete.c : $(PC16550_DIR)\pc16550hal_delete.c
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_setup.c : $(PC16550_DIR)\pc16550hal_setup.c
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_setup.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_stop.c : $(PC16550_DIR)\pc16550hal_stop.c
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_stop.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_setspeed.c : $(PC16550_DIR)\pc16550hal_setspeed.c
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_setspeed.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_recvchar.c : $(PC16550_DIR)\pc16550hal_recvchar.c
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_recvchar.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_sendchar.c : $(PC16550_DIR)\pc16550hal_sendchar.c
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_sendchar.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_enableinterrupt.c : $(PC16550_DIR)\pc16550hal_enableinterrupt.c
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_enableinterrupt.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_getinterruptstatus.c : $(PC16550_DIR)\pc16550hal_getinterruptstatus.c
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_getinterruptstatus.c $(OBJS_DIR)\

$(OBJS_DIR)\pc16550hal_getstatus.c : $(PC16550_DIR)\pc16550hal_getstatus.c
	$(CMD_CP) $(PC16550_DIR)\pc16550hal_getstatus.c $(OBJS_DIR)\


$(OBJS_DIR)\at91usartdrv.h : $(AT91USART_DIR)\at91usartdrv.h
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_local.h : $(AT91USART_DIR)\at91usartdrv_local.h
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_create.c : $(AT91USART_DIR)\at91usartdrv_create.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_delete.c : $(AT91USART_DIR)\at91usartdrv_delete.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_constructor.c : $(AT91USART_DIR)\at91usartdrv_constructor.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_destructor.c : $(AT91USART_DIR)\at91usartdrv_destructor.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_open.c : $(AT91USART_DIR)\at91usartdrv_open.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_close.c : $(AT91USART_DIR)\at91usartdrv_close.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_iocontrol.c : $(AT91USART_DIR)\at91usartdrv_iocontrol.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_seek.c : $(AT91USART_DIR)\at91usartdrv_seek.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_read.c : $(AT91USART_DIR)\at91usartdrv_read.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_write.c : $(AT91USART_DIR)\at91usartdrv_write.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_flush.c : $(AT91USART_DIR)\at91usartdrv_flush.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\at91usartdrv_isr.c : $(AT91USART_DIR)\at91usartdrv_isr.c
	$(CMD_CP) $(AT91USART_DIR)\at91usartdrv_isr.c $(OBJS_DIR)\


$(OBJS_DIR)\scidrv.h : $(RENESASSCI_DIR)\scidrv.h
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv.h $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_local.h : $(RENESASSCI_DIR)\scidrv_local.h
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\scihal.h : $(RENESASSCI_DIR)\scihal.h
	$(CMD_CP) $(RENESASSCI_DIR)\scihal.h $(OBJS_DIR)\

$(OBJS_DIR)\scihal_local.h : $(RENESASSCI_DIR)\scihal_local.h
	$(CMD_CP) $(RENESASSCI_DIR)\scihal_local.h $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_create.c : $(RENESASSCI_DIR)\scidrv_create.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_delete.c : $(RENESASSCI_DIR)\scidrv_delete.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_constructor.c : $(RENESASSCI_DIR)\scidrv_constructor.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_destructor.c : $(RENESASSCI_DIR)\scidrv_destructor.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_open.c : $(RENESASSCI_DIR)\scidrv_open.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_close.c : $(RENESASSCI_DIR)\scidrv_close.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_iocontrol.c : $(RENESASSCI_DIR)\scidrv_iocontrol.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_seek.c : $(RENESASSCI_DIR)\scidrv_seek.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_read.c : $(RENESASSCI_DIR)\scidrv_read.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_write.c : $(RENESASSCI_DIR)\scidrv_write.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_flush.c : $(RENESASSCI_DIR)\scidrv_flush.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_isrrxerr.c : $(RENESASSCI_DIR)\scidrv_isrrxerr.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_isrrxerr.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_isrrx.c : $(RENESASSCI_DIR)\scidrv_isrrx.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_isrrx.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_isrtx.c : $(RENESASSCI_DIR)\scidrv_isrtx.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_isrtx.c $(OBJS_DIR)\

$(OBJS_DIR)\scidrv_isrtxend.c : $(RENESASSCI_DIR)\scidrv_isrtxend.c
	$(CMD_CP) $(RENESASSCI_DIR)\scidrv_isrtxend.c $(OBJS_DIR)\

$(OBJS_DIR)\scihal_create.c : $(RENESASSCI_DIR)\scihal_create.c
	$(CMD_CP) $(RENESASSCI_DIR)\scihal_create.c $(OBJS_DIR)\

$(OBJS_DIR)\scihal_delete.c : $(RENESASSCI_DIR)\scihal_delete.c
	$(CMD_CP) $(RENESASSCI_DIR)\scihal_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\scihal_enableinterrupt.c : $(RENESASSCI_DIR)\scihal_enableinterrupt.c
	$(CMD_CP) $(RENESASSCI_DIR)\scihal_enableinterrupt.c $(OBJS_DIR)\

$(OBJS_DIR)\scihal_recvchar.c : $(RENESASSCI_DIR)\scihal_recvchar.c
	$(CMD_CP) $(RENESASSCI_DIR)\scihal_recvchar.c $(OBJS_DIR)\

$(OBJS_DIR)\scihal_sendchar.c : $(RENESASSCI_DIR)\scihal_sendchar.c
	$(CMD_CP) $(RENESASSCI_DIR)\scihal_sendchar.c $(OBJS_DIR)\

$(OBJS_DIR)\scihal_setspeed.c : $(RENESASSCI_DIR)\scihal_setspeed.c
	$(CMD_CP) $(RENESASSCI_DIR)\scihal_setspeed.c $(OBJS_DIR)\

$(OBJS_DIR)\scihal_setup.c : $(RENESASSCI_DIR)\scihal_setup.c
	$(CMD_CP) $(RENESASSCI_DIR)\scihal_setup.c $(OBJS_DIR)\

$(OBJS_DIR)\scihal_stop.c : $(RENESASSCI_DIR)\scihal_stop.c
	$(CMD_CP) $(RENESASSCI_DIR)\scihal_stop.c $(OBJS_DIR)\


$(OBJS_DIR)\mx1uartdrv.h : $(MX1UART_DIR)\mx1uartdrv.h
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_local.h : $(MX1UART_DIR)\mx1uartdrv_local.h
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_create.c : $(MX1UART_DIR)\mx1uartdrv_create.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_delete.c : $(MX1UART_DIR)\mx1uartdrv_delete.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_constructor.c : $(MX1UART_DIR)\mx1uartdrv_constructor.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_destructor.c : $(MX1UART_DIR)\mx1uartdrv_destructor.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_open.c : $(MX1UART_DIR)\mx1uartdrv_open.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_close.c : $(MX1UART_DIR)\mx1uartdrv_close.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_iocontrol.c : $(MX1UART_DIR)\mx1uartdrv_iocontrol.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_seek.c : $(MX1UART_DIR)\mx1uartdrv_seek.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_read.c : $(MX1UART_DIR)\mx1uartdrv_read.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_write.c : $(MX1UART_DIR)\mx1uartdrv_write.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_flush.c : $(MX1UART_DIR)\mx1uartdrv_flush.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\mx1uartdrv_isr.c : $(MX1UART_DIR)\mx1uartdrv_isr.c
	$(CMD_CP) $(MX1UART_DIR)\mx1uartdrv_isr.c $(OBJS_DIR)\


$(OBJS_DIR)\mn103scdrv.h : $(MN103SC_DIR)\mn103scdrv.h
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_local.h : $(MN103SC_DIR)\mn103scdrv_local.h
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_create.c : $(MN103SC_DIR)\mn103scdrv_create.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_delete.c : $(MN103SC_DIR)\mn103scdrv_delete.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_constructor.c : $(MN103SC_DIR)\mn103scdrv_constructor.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_destructor.c : $(MN103SC_DIR)\mn103scdrv_destructor.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_open.c : $(MN103SC_DIR)\mn103scdrv_open.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_close.c : $(MN103SC_DIR)\mn103scdrv_close.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_iocontrol.c : $(MN103SC_DIR)\mn103scdrv_iocontrol.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_seek.c : $(MN103SC_DIR)\mn103scdrv_seek.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_read.c : $(MN103SC_DIR)\mn103scdrv_read.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_write.c : $(MN103SC_DIR)\mn103scdrv_write.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_flush.c : $(MN103SC_DIR)\mn103scdrv_flush.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_isrtx.c : $(MN103SC_DIR)\mn103scdrv_isrtx.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_isrtx.c $(OBJS_DIR)\

$(OBJS_DIR)\mn103scdrv_isrrx.c : $(MN103SC_DIR)\mn103scdrv_isrrx.c
	$(CMD_CP) $(MN103SC_DIR)\mn103scdrv_isrrx.c $(OBJS_DIR)\


$(OBJS_DIR)\xilinxuartdrv.h : $(XILINXUARTDRV_DIR)\xilinxuartdrv.h
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_local.h : $(XILINXUARTDRV_DIR)\xilinxuartdrv_local.h
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_create.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_create.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_delete.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_delete.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_constructor.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_constructor.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_destructor.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_destructor.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_open.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_open.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_close.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_close.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_write.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_write.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_read.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_read.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_seek.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_seek.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_flush.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_flush.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_iocontrol.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_iocontrol.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\xilinxuartdrv_isr.c : $(XILINXUARTDRV_DIR)\xilinxuartdrv_isr.c
	$(CMD_CP) $(XILINXUARTDRV_DIR)\xilinxuartdrv_isr.c $(OBJS_DIR)\


$(OBJS_DIR)\winsockdrv.h : $(WINSOCK_DIR)\winsockdrv.h
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_local.h : $(WINSOCK_DIR)\winsockdrv_local.h
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_close.c : $(WINSOCK_DIR)\winsockdrv_close.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_constructor.c : $(WINSOCK_DIR)\winsockdrv_constructor.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_create.c : $(WINSOCK_DIR)\winsockdrv_create.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_delete.c : $(WINSOCK_DIR)\winsockdrv_delete.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_destructor.c : $(WINSOCK_DIR)\winsockdrv_destructor.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_flush.c : $(WINSOCK_DIR)\winsockdrv_flush.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_iocontrol.c : $(WINSOCK_DIR)\winsockdrv_iocontrol.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_isr.c : $(WINSOCK_DIR)\winsockdrv_isr.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_isr.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_open.c : $(WINSOCK_DIR)\winsockdrv_open.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_read.c : $(WINSOCK_DIR)\winsockdrv_read.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_recv.c : $(WINSOCK_DIR)\winsockdrv_recv.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_recv.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_seek.c : $(WINSOCK_DIR)\winsockdrv_seek.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_send.c : $(WINSOCK_DIR)\winsockdrv_send.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_send.c $(OBJS_DIR)\

$(OBJS_DIR)\winsockdrv_write.c : $(WINSOCK_DIR)\winsockdrv_write.c
	$(CMD_CP) $(WINSOCK_DIR)\winsockdrv_write.c $(OBJS_DIR)\


$(OBJS_DIR)\jellyuartdrv.h : $(JELLYUART_DIR)\jellyuartdrv.h
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_local.h : $(JELLYUART_DIR)\jellyuartdrv_local.h
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_create.c : $(JELLYUART_DIR)\jellyuartdrv_create.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_delete.c : $(JELLYUART_DIR)\jellyuartdrv_delete.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_constructor.c : $(JELLYUART_DIR)\jellyuartdrv_constructor.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_destructor.c : $(JELLYUART_DIR)\jellyuartdrv_destructor.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_open.c : $(JELLYUART_DIR)\jellyuartdrv_open.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_close.c : $(JELLYUART_DIR)\jellyuartdrv_close.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_iocontrol.c : $(JELLYUART_DIR)\jellyuartdrv_iocontrol.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_seek.c : $(JELLYUART_DIR)\jellyuartdrv_seek.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_read.c : $(JELLYUART_DIR)\jellyuartdrv_read.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_write.c : $(JELLYUART_DIR)\jellyuartdrv_write.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_flush.c : $(JELLYUART_DIR)\jellyuartdrv_flush.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyuartdrv_isr.c : $(JELLYUART_DIR)\jellyuartdrv_isr.c
	$(CMD_CP) $(JELLYUART_DIR)\jellyuartdrv_isr.c $(OBJS_DIR)\


$(OBJS_DIR)\i2cdrv.h : $(I2CDRV_DIR)\i2cdrv.h
	$(CMD_CP) $(I2CDRV_DIR)\i2cdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\i2cdrv_local.h : $(I2CDRV_DIR)\i2cdrv_local.h
	$(CMD_CP) $(I2CDRV_DIR)\i2cdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\i2cdrv_bytewrite.c : $(I2CDRV_DIR)\i2cdrv_bytewrite.c
	$(CMD_CP) $(I2CDRV_DIR)\i2cdrv_bytewrite.c $(OBJS_DIR)\

$(OBJS_DIR)\i2cdrv_byteread.c : $(I2CDRV_DIR)\i2cdrv_byteread.c
	$(CMD_CP) $(I2CDRV_DIR)\i2cdrv_byteread.c $(OBJS_DIR)\

$(OBJS_DIR)\i2cdrv_burstwrite.c : $(I2CDRV_DIR)\i2cdrv_burstwrite.c
	$(CMD_CP) $(I2CDRV_DIR)\i2cdrv_burstwrite.c $(OBJS_DIR)\

$(OBJS_DIR)\i2cdrv_burstread.c : $(I2CDRV_DIR)\i2cdrv_burstread.c
	$(CMD_CP) $(I2CDRV_DIR)\i2cdrv_burstread.c $(OBJS_DIR)\


$(OBJS_DIR)\jellyi2cdrv.h : $(JELLYI2C_DIR)\jellyi2cdrv.h
	$(CMD_CP) $(JELLYI2C_DIR)\jellyi2cdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\jellyi2cdrv_local.h : $(JELLYI2C_DIR)\jellyi2cdrv_local.h
	$(CMD_CP) $(JELLYI2C_DIR)\jellyi2cdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\jellyi2cdrv_create.c : $(JELLYI2C_DIR)\jellyi2cdrv_create.c
	$(CMD_CP) $(JELLYI2C_DIR)\jellyi2cdrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyi2cdrv_delete.c : $(JELLYI2C_DIR)\jellyi2cdrv_delete.c
	$(CMD_CP) $(JELLYI2C_DIR)\jellyi2cdrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyi2cdrv_constructor.c : $(JELLYI2C_DIR)\jellyi2cdrv_constructor.c
	$(CMD_CP) $(JELLYI2C_DIR)\jellyi2cdrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyi2cdrv_destructor.c : $(JELLYI2C_DIR)\jellyi2cdrv_destructor.c
	$(CMD_CP) $(JELLYI2C_DIR)\jellyi2cdrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyi2cdrv_open.c : $(JELLYI2C_DIR)\jellyi2cdrv_open.c
	$(CMD_CP) $(JELLYI2C_DIR)\jellyi2cdrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyi2cdrv_close.c : $(JELLYI2C_DIR)\jellyi2cdrv_close.c
	$(CMD_CP) $(JELLYI2C_DIR)\jellyi2cdrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyi2cdrv_iocontrol.c : $(JELLYI2C_DIR)\jellyi2cdrv_iocontrol.c
	$(CMD_CP) $(JELLYI2C_DIR)\jellyi2cdrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\jellyi2cdrv_access.c : $(JELLYI2C_DIR)\jellyi2cdrv_access.c
	$(CMD_CP) $(JELLYI2C_DIR)\jellyi2cdrv_access.c $(OBJS_DIR)\


$(OBJS_DIR)\fatvol.h : $(FATVOL_DIR)\fatvol.h
	$(CMD_CP) $(FATVOL_DIR)\fatvol.h $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_local.h : $(FATVOL_DIR)\fatvol_local.h
	$(CMD_CP) $(FATVOL_DIR)\fatvol_local.h $(OBJS_DIR)\

$(OBJS_DIR)\fatfile.h : $(FATVOL_DIR)\fatfile.h
	$(CMD_CP) $(FATVOL_DIR)\fatfile.h $(OBJS_DIR)\

$(OBJS_DIR)\fatfile_local.h : $(FATVOL_DIR)\fatfile_local.h
	$(CMD_CP) $(FATVOL_DIR)\fatfile_local.h $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_create.c : $(FATVOL_DIR)\fatvol_create.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_create.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_delete.c : $(FATVOL_DIR)\fatvol_delete.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_constructor.c : $(FATVOL_DIR)\fatvol_constructor.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_destructor.c : $(FATVOL_DIR)\fatvol_destructor.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_open.c : $(FATVOL_DIR)\fatvol_open.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_open.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_close.c : $(FATVOL_DIR)\fatvol_close.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_close.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_iocontrol.c : $(FATVOL_DIR)\fatvol_iocontrol.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_seek.c : $(FATVOL_DIR)\fatvol_seek.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_read.c : $(FATVOL_DIR)\fatvol_read.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_read.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_write.c : $(FATVOL_DIR)\fatvol_write.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_write.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_flush.c : $(FATVOL_DIR)\fatvol_flush.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_shutdown.c : $(FATVOL_DIR)\fatvol_shutdown.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_shutdown.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_makedir.c : $(FATVOL_DIR)\fatvol_makedir.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_makedir.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_remove.c : $(FATVOL_DIR)\fatvol_remove.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_remove.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_clusterread.c : $(FATVOL_DIR)\fatvol_clusterread.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_clusterread.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_clusterwrite.c : $(FATVOL_DIR)\fatvol_clusterwrite.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_clusterwrite.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_flushclusterbuf.c : $(FATVOL_DIR)\fatvol_flushclusterbuf.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_flushclusterbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_flushfat.c : $(FATVOL_DIR)\fatvol_flushfat.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_flushfat.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_getclusterbuf.c : $(FATVOL_DIR)\fatvol_getclusterbuf.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_getclusterbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_relclusterbuf.c : $(FATVOL_DIR)\fatvol_relclusterbuf.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_relclusterbuf.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_alloccluster.c : $(FATVOL_DIR)\fatvol_alloccluster.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_alloccluster.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_freecluster.c : $(FATVOL_DIR)\fatvol_freecluster.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_freecluster.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_getnextcluster.c : $(FATVOL_DIR)\fatvol_getnextcluster.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_getnextcluster.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_setnextcluster.c : $(FATVOL_DIR)\fatvol_setnextcluster.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_setnextcluster.c $(OBJS_DIR)\

$(OBJS_DIR)\fatvol_syncfilesize.c : $(FATVOL_DIR)\fatvol_syncfilesize.c
	$(CMD_CP) $(FATVOL_DIR)\fatvol_syncfilesize.c $(OBJS_DIR)\

$(OBJS_DIR)\fatfile_create.c : $(FATVOL_DIR)\fatfile_create.c
	$(CMD_CP) $(FATVOL_DIR)\fatfile_create.c $(OBJS_DIR)\

$(OBJS_DIR)\fatfile_delete.c : $(FATVOL_DIR)\fatfile_delete.c
	$(CMD_CP) $(FATVOL_DIR)\fatfile_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\fatfile_constructor.c : $(FATVOL_DIR)\fatfile_constructor.c
	$(CMD_CP) $(FATVOL_DIR)\fatfile_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\fatfile_destructor.c : $(FATVOL_DIR)\fatfile_destructor.c
	$(CMD_CP) $(FATVOL_DIR)\fatfile_destructor.c $(OBJS_DIR)\


$(OBJS_DIR)\memdrv.h : $(MEMDRV_DIR)\memdrv.h
	$(CMD_CP) $(MEMDRV_DIR)\memdrv.h $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_local.h : $(MEMDRV_DIR)\memdrv_local.h
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_local.h $(OBJS_DIR)\

$(OBJS_DIR)\memfile.h : $(MEMDRV_DIR)\memfile.h
	$(CMD_CP) $(MEMDRV_DIR)\memfile.h $(OBJS_DIR)\

$(OBJS_DIR)\memfile_local.h : $(MEMDRV_DIR)\memfile_local.h
	$(CMD_CP) $(MEMDRV_DIR)\memfile_local.h $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_create.c : $(MEMDRV_DIR)\memdrv_create.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_create.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_delete.c : $(MEMDRV_DIR)\memdrv_delete.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_constructor.c : $(MEMDRV_DIR)\memdrv_constructor.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_destructor.c : $(MEMDRV_DIR)\memdrv_destructor.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_destructor.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_open.c : $(MEMDRV_DIR)\memdrv_open.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_open.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_close.c : $(MEMDRV_DIR)\memdrv_close.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_close.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_iocontrol.c : $(MEMDRV_DIR)\memdrv_iocontrol.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_iocontrol.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_flush.c : $(MEMDRV_DIR)\memdrv_flush.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_flush.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_read.c : $(MEMDRV_DIR)\memdrv_read.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_read.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_seek.c : $(MEMDRV_DIR)\memdrv_seek.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_seek.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_write.c : $(MEMDRV_DIR)\memdrv_write.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_write.c $(OBJS_DIR)\

$(OBJS_DIR)\memdrv_getinformation.c : $(MEMDRV_DIR)\memdrv_getinformation.c
	$(CMD_CP) $(MEMDRV_DIR)\memdrv_getinformation.c $(OBJS_DIR)\

$(OBJS_DIR)\memfile_create.c : $(MEMDRV_DIR)\memfile_create.c
	$(CMD_CP) $(MEMDRV_DIR)\memfile_create.c $(OBJS_DIR)\

$(OBJS_DIR)\memfile_delete.c : $(MEMDRV_DIR)\memfile_delete.c
	$(CMD_CP) $(MEMDRV_DIR)\memfile_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\memfile_constructor.c : $(MEMDRV_DIR)\memfile_constructor.c
	$(CMD_CP) $(MEMDRV_DIR)\memfile_constructor.c $(OBJS_DIR)\

$(OBJS_DIR)\memfile_destructor.c : $(MEMDRV_DIR)\memfile_destructor.c
	$(CMD_CP) $(MEMDRV_DIR)\memfile_destructor.c $(OBJS_DIR)\


$(OBJS_DIR)\shell.h : $(SHELL_DIR)\shell.h
	$(CMD_CP) $(SHELL_DIR)\shell.h $(OBJS_DIR)\

$(OBJS_DIR)\shell_local.h : $(SHELL_DIR)\shell_local.h
	$(CMD_CP) $(SHELL_DIR)\shell_local.h $(OBJS_DIR)\

$(OBJS_DIR)\shell_main.c : $(SHELL_DIR)\shell_main.c
	$(CMD_CP) $(SHELL_DIR)\shell_main.c $(OBJS_DIR)\

$(OBJS_DIR)\shell_create.c : $(SHELL_DIR)\shell_create.c
	$(CMD_CP) $(SHELL_DIR)\shell_create.c $(OBJS_DIR)\

$(OBJS_DIR)\shell_delete.c : $(SHELL_DIR)\shell_delete.c
	$(CMD_CP) $(SHELL_DIR)\shell_delete.c $(OBJS_DIR)\

$(OBJS_DIR)\shell_executecommand.c : $(SHELL_DIR)\shell_executecommand.c
	$(CMD_CP) $(SHELL_DIR)\shell_executecommand.c $(OBJS_DIR)\

$(OBJS_DIR)\shell_executescript.c : $(SHELL_DIR)\shell_executescript.c
	$(CMD_CP) $(SHELL_DIR)\shell_executescript.c $(OBJS_DIR)\

$(OBJS_DIR)\shell_inputline.c : $(SHELL_DIR)\shell_inputline.c
	$(CMD_CP) $(SHELL_DIR)\shell_inputline.c $(OBJS_DIR)\

$(OBJS_DIR)\shell_interactive.c : $(SHELL_DIR)\shell_interactive.c
	$(CMD_CP) $(SHELL_DIR)\shell_interactive.c $(OBJS_DIR)\

$(OBJS_DIR)\shell_putchar.c : $(SHELL_DIR)\shell_putchar.c
	$(CMD_CP) $(SHELL_DIR)\shell_putchar.c $(OBJS_DIR)\

$(OBJS_DIR)\shell_curright.c : $(SHELL_DIR)\shell_curright.c
	$(CMD_CP) $(SHELL_DIR)\shell_curright.c $(OBJS_DIR)\

$(OBJS_DIR)\shell_curleft.c : $(SHELL_DIR)\shell_curleft.c
	$(CMD_CP) $(SHELL_DIR)\shell_curleft.c $(OBJS_DIR)\

$(OBJS_DIR)\shell_replaceline.c : $(SHELL_DIR)\shell_replaceline.c
	$(CMD_CP) $(SHELL_DIR)\shell_replaceline.c $(OBJS_DIR)\


$(OBJS_DIR)\whiteboardcmd.h : $(WHITEBOARDCMD_DIR)\whiteboardcmd.h
	$(CMD_CP) $(WHITEBOARDCMD_DIR)\whiteboardcmd.h $(OBJS_DIR)\

$(OBJS_DIR)\whiteboardcmd_main.c : $(WHITEBOARDCMD_DIR)\whiteboardcmd_main.c
	$(CMD_CP) $(WHITEBOARDCMD_DIR)\whiteboardcmd_main.c $(OBJS_DIR)\


$(OBJS_DIR)\processlist.h : $(PROCESSLIST_DIR)\processlist.h
	$(CMD_CP) $(PROCESSLIST_DIR)\processlist.h $(OBJS_DIR)\

$(OBJS_DIR)\processlist_main.c : $(PROCESSLIST_DIR)\processlist_main.c
	$(CMD_CP) $(PROCESSLIST_DIR)\processlist_main.c $(OBJS_DIR)\


$(OBJS_DIR)\processsignal.h : $(PROCESSSIGNAL_DIR)\processsignal.h
	$(CMD_CP) $(PROCESSSIGNAL_DIR)\processsignal.h $(OBJS_DIR)\

$(OBJS_DIR)\processsignal_main.c : $(PROCESSSIGNAL_DIR)\processsignal_main.c
	$(CMD_CP) $(PROCESSSIGNAL_DIR)\processsignal_main.c $(OBJS_DIR)\


$(OBJS_DIR)\commandlist.h : $(COMMANDLIST_DIR)\commandlist.h
	$(CMD_CP) $(COMMANDLIST_DIR)\commandlist.h $(OBJS_DIR)\

$(OBJS_DIR)\commandlist_main.c : $(COMMANDLIST_DIR)\commandlist_main.c
	$(CMD_CP) $(COMMANDLIST_DIR)\commandlist_main.c $(OBJS_DIR)\


$(OBJS_DIR)\memdump.h : $(MEMDUMP_DIR)\memdump.h
	$(CMD_CP) $(MEMDUMP_DIR)\memdump.h $(OBJS_DIR)\

$(OBJS_DIR)\memdump_main.c : $(MEMDUMP_DIR)\memdump_main.c
	$(CMD_CP) $(MEMDUMP_DIR)\memdump_main.c $(OBJS_DIR)\


$(OBJS_DIR)\memwrite.h : $(MEMWRITE_DIR)\memwrite.h
	$(CMD_CP) $(MEMWRITE_DIR)\memwrite.h $(OBJS_DIR)\

$(OBJS_DIR)\memwrite_main.c : $(MEMWRITE_DIR)\memwrite_main.c
	$(CMD_CP) $(MEMWRITE_DIR)\memwrite_main.c $(OBJS_DIR)\


$(OBJS_DIR)\memfill.h : $(MEMFILL_DIR)\memfill.h
	$(CMD_CP) $(MEMFILL_DIR)\memfill.h $(OBJS_DIR)\

$(OBJS_DIR)\memfill_main.c : $(MEMFILL_DIR)\memfill_main.c
	$(CMD_CP) $(MEMFILL_DIR)\memfill_main.c $(OBJS_DIR)\


$(OBJS_DIR)\memcopy.h : $(MEMCOPY_DIR)\memcopy.h
	$(CMD_CP) $(MEMCOPY_DIR)\memcopy.h $(OBJS_DIR)\

$(OBJS_DIR)\memcopy_main.c : $(MEMCOPY_DIR)\memcopy_main.c
	$(CMD_CP) $(MEMCOPY_DIR)\memcopy_main.c $(OBJS_DIR)\


$(OBJS_DIR)\memsave.h : $(MEMSAVE_DIR)\memsave.h
	$(CMD_CP) $(MEMSAVE_DIR)\memsave.h $(OBJS_DIR)\

$(OBJS_DIR)\memsave_main.c : $(MEMSAVE_DIR)\memsave_main.c
	$(CMD_CP) $(MEMSAVE_DIR)\memsave_main.c $(OBJS_DIR)\


$(OBJS_DIR)\memload.h : $(MEMLOAD_DIR)\memload.h
	$(CMD_CP) $(MEMLOAD_DIR)\memload.h $(OBJS_DIR)\

$(OBJS_DIR)\memload_main.c : $(MEMLOAD_DIR)\memload_main.c
	$(CMD_CP) $(MEMLOAD_DIR)\memload_main.c $(OBJS_DIR)\


$(OBJS_DIR)\memtest.h : $(MEMTEST_DIR)\memtest.h
	$(CMD_CP) $(MEMTEST_DIR)\memtest.h $(OBJS_DIR)\

$(OBJS_DIR)\memtest_main.c : $(MEMTEST_DIR)\memtest_main.c
	$(CMD_CP) $(MEMTEST_DIR)\memtest_main.c $(OBJS_DIR)\


$(OBJS_DIR)\keytest.h : $(KEYTEST_DIR)\keytest.h
	$(CMD_CP) $(KEYTEST_DIR)\keytest.h $(OBJS_DIR)\

$(OBJS_DIR)\keytest_main.c : $(KEYTEST_DIR)\keytest_main.c
	$(CMD_CP) $(KEYTEST_DIR)\keytest_main.c $(OBJS_DIR)\


$(OBJS_DIR)\timecmd.h : $(TIMECMD_DIR)\timecmd.h
	$(CMD_CP) $(TIMECMD_DIR)\timecmd.h $(OBJS_DIR)\

$(OBJS_DIR)\timecmd_main.c : $(TIMECMD_DIR)\timecmd_main.c
	$(CMD_CP) $(TIMECMD_DIR)\timecmd_main.c $(OBJS_DIR)\


$(OBJS_DIR)\i2ccmd.h : $(I2CCMD_DIR)\i2ccmd.h
	$(CMD_CP) $(I2CCMD_DIR)\i2ccmd.h $(OBJS_DIR)\

$(OBJS_DIR)\i2ccmd_main.c : $(I2CCMD_DIR)\i2ccmd_main.c
	$(CMD_CP) $(I2CCMD_DIR)\i2ccmd_main.c $(OBJS_DIR)\


$(OBJS_DIR)\filelist.h : $(FILELIST_DIR)\filelist.h
	$(CMD_CP) $(FILELIST_DIR)\filelist.h $(OBJS_DIR)\

$(OBJS_DIR)\filelist_main.c : $(FILELIST_DIR)\filelist_main.c
	$(CMD_CP) $(FILELIST_DIR)\filelist_main.c $(OBJS_DIR)\


$(OBJS_DIR)\filecat.h : $(FILECAT_DIR)\filecat.h
	$(CMD_CP) $(FILECAT_DIR)\filecat.h $(OBJS_DIR)\

$(OBJS_DIR)\filecat_main.c : $(FILECAT_DIR)\filecat_main.c
	$(CMD_CP) $(FILECAT_DIR)\filecat_main.c $(OBJS_DIR)\


$(OBJS_DIR)\filecopy.h : $(FILECOPY_DIR)\filecopy.h
	$(CMD_CP) $(FILECOPY_DIR)\filecopy.h $(OBJS_DIR)\

$(OBJS_DIR)\filecopy_main.c : $(FILECOPY_DIR)\filecopy_main.c
	$(CMD_CP) $(FILECOPY_DIR)\filecopy_main.c $(OBJS_DIR)\


$(OBJS_DIR)\filedump.h : $(FILEDUMP_DIR)\filedump.h
	$(CMD_CP) $(FILEDUMP_DIR)\filedump.h $(OBJS_DIR)\

$(OBJS_DIR)\filedump_main.c : $(FILEDUMP_DIR)\filedump_main.c
	$(CMD_CP) $(FILEDUMP_DIR)\filedump_main.c $(OBJS_DIR)\


$(OBJS_DIR)\fatmount.h : $(FATMOUNT_DIR)\fatmount.h
	$(CMD_CP) $(FATMOUNT_DIR)\fatmount.h $(OBJS_DIR)\

$(OBJS_DIR)\fatmount_main.c : $(FATMOUNT_DIR)\fatmount_main.c
	$(CMD_CP) $(FATMOUNT_DIR)\fatmount_main.c $(OBJS_DIR)\


$(OBJS_DIR)\norflashcmd.h : $(FLASHCMD_DIR)\norflashcmd.h
	$(CMD_CP) $(FLASHCMD_DIR)\norflashcmd.h $(OBJS_DIR)\

$(OBJS_DIR)\norflashcmd_main.c : $(FLASHCMD_DIR)\norflashcmd_main.c
	$(CMD_CP) $(FLASHCMD_DIR)\norflashcmd_main.c $(OBJS_DIR)\


$(OBJS_DIR)\ethersnoop.h : $(ETHERSNOOP_DIR)\ethersnoop.h
	$(CMD_CP) $(ETHERSNOOP_DIR)\ethersnoop.h $(OBJS_DIR)\

$(OBJS_DIR)\ethersnoop_main.c : $(ETHERSNOOP_DIR)\ethersnoop_main.c
	$(CMD_CP) $(ETHERSNOOP_DIR)\ethersnoop_main.c $(OBJS_DIR)\


$(OBJS_DIR)\hello.h : $(HELLO_DIR)\hello.h
	$(CMD_CP) $(HELLO_DIR)\hello.h $(OBJS_DIR)\

$(OBJS_DIR)\hello_main.c : $(HELLO_DIR)\hello_main.c
	$(CMD_CP) $(HELLO_DIR)\hello_main.c $(OBJS_DIR)\




# ----------------------------------
#  depend
# ----------------------------------

$(OBJS_DIR)\system_initialize.$(EXT_OBJ):	$(OBJS_DIR)\system_initialize.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\system_requestproc.$(EXT_OBJ):	$(OBJS_DIR)\system_requestproc.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\system_process.$(EXT_OBJ):	$(OBJS_DIR)\system_process.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\system_getnextprocess.$(EXT_OBJ):	$(OBJS_DIR)\system_getnextprocess.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\system_getsystemprocess.$(EXT_OBJ):	$(OBJS_DIR)\system_getsystemprocess.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\system_lock.$(EXT_OBJ):	$(OBJS_DIR)\system_lock.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\system_unlock.$(EXT_OBJ):	$(OBJS_DIR)\system_unlock.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\whiteboard_setstring.$(EXT_OBJ):	$(OBJS_DIR)\whiteboard_setstring.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\whiteboard_getstring.$(EXT_OBJ):	$(OBJS_DIR)\whiteboard_getstring.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\whiteboard_setinteger.$(EXT_OBJ):	$(OBJS_DIR)\whiteboard_setinteger.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\whiteboard_getinteger.$(EXT_OBJ):	$(OBJS_DIR)\whiteboard_getinteger.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\whiteboard_getnextkey.$(EXT_OBJ):	$(OBJS_DIR)\whiteboard_getnextkey.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\sysapi_initialize.$(EXT_OBJ):	$(OBJS_DIR)\sysapi_initialize.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysctx_isisr.$(EXT_OBJ):	$(OBJS_DIR)\sysctx_isisr.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysloc_lock.$(EXT_OBJ):	$(OBJS_DIR)\sysloc_lock.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysloc_unlock.$(EXT_OBJ):	$(OBJS_DIR)\sysloc_unlock.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysevt_clear.$(EXT_OBJ):	$(OBJS_DIR)\sysevt_clear.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysevt_create.$(EXT_OBJ):	$(OBJS_DIR)\sysevt_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysevt_delete.$(EXT_OBJ):	$(OBJS_DIR)\sysevt_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysevt_set.$(EXT_OBJ):	$(OBJS_DIR)\sysevt_set.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysevt_wait.$(EXT_OBJ):	$(OBJS_DIR)\sysevt_wait.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysint_clear.$(EXT_OBJ):	$(OBJS_DIR)\sysint_clear.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysint_disable.$(EXT_OBJ):	$(OBJS_DIR)\sysint_disable.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysint_enable.$(EXT_OBJ):	$(OBJS_DIR)\sysint_enable.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysisr_create.$(EXT_OBJ):	$(OBJS_DIR)\sysisr_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysisr_delete.$(EXT_OBJ):	$(OBJS_DIR)\sysisr_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmem_alloc.$(EXT_OBJ):	$(OBJS_DIR)\sysmem_alloc.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmem_free.$(EXT_OBJ):	$(OBJS_DIR)\sysmem_free.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmem_getmemheap.$(EXT_OBJ):	$(OBJS_DIR)\sysmem_getmemheap.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmem_getsize.$(EXT_OBJ):	$(OBJS_DIR)\sysmem_getsize.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmem_realloc.$(EXT_OBJ):	$(OBJS_DIR)\sysmem_realloc.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmtx_create.$(EXT_OBJ):	$(OBJS_DIR)\sysmtx_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmtx_delete.$(EXT_OBJ):	$(OBJS_DIR)\sysmtx_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmtx_lock.$(EXT_OBJ):	$(OBJS_DIR)\sysmtx_lock.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmtx_unlock.$(EXT_OBJ):	$(OBJS_DIR)\sysmtx_unlock.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysprc_create.$(EXT_OBJ):	$(OBJS_DIR)\sysprc_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysprc_delete.$(EXT_OBJ):	$(OBJS_DIR)\sysprc_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysprc_start.$(EXT_OBJ):	$(OBJS_DIR)\sysprc_start.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysprc_terminate.$(EXT_OBJ):	$(OBJS_DIR)\sysprc_terminate.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysprc_suspend.$(EXT_OBJ):	$(OBJS_DIR)\sysprc_suspend.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysprc_resume.$(EXT_OBJ):	$(OBJS_DIR)\sysprc_resume.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysprc_getparam.$(EXT_OBJ):	$(OBJS_DIR)\sysprc_getparam.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysprc_getcurrenthandle.$(EXT_OBJ):	$(OBJS_DIR)\sysprc_getcurrenthandle.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysprc_setsignalhandler.$(EXT_OBJ):	$(OBJS_DIR)\sysprc_setsignalhandler.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysprc_sendsignal.$(EXT_OBJ):	$(OBJS_DIR)\sysprc_sendsignal.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\systim_signal.$(EXT_OBJ):	$(OBJS_DIR)\systim_signal.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\systim_wait.$(EXT_OBJ):	$(OBJS_DIR)\systim_wait.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\systim_getsystemtime.$(EXT_OBJ):	$(OBJS_DIR)\systim_getsystemtime.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\systim_systimetosecond.$(EXT_OBJ):	$(OBJS_DIR)\systim_systimetosecond.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\systim_systimetonanosecond.$(EXT_OBJ):	$(OBJS_DIR)\systim_systimetonanosecond.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\systim_getcputime.$(EXT_OBJ):	$(OBJS_DIR)\systim_getcputime.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\systim_cputimetosecond.$(EXT_OBJ):	$(OBJS_DIR)\systim_cputimetosecond.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\systim_cputimetonanosecond.$(EXT_OBJ):	$(OBJS_DIR)\systim_cputimetonanosecond.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysio_allociomem.$(EXT_OBJ):	$(OBJS_DIR)\sysio_allociomem.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysio_freeiomem.$(EXT_OBJ):	$(OBJS_DIR)\sysio_freeiomem.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syshos_hook.$(EXT_OBJ):	$(OBJS_DIR)\syshos_hook.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\sysmemheap_alignsize.$(EXT_OBJ):	$(OBJS_DIR)\sysmemheap_alignsize.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmemheap_alloc.$(EXT_OBJ):	$(OBJS_DIR)\sysmemheap_alloc.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmemheap_constructor.$(EXT_OBJ):	$(OBJS_DIR)\sysmemheap_constructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmemheap_destructor.$(EXT_OBJ):	$(OBJS_DIR)\sysmemheap_destructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmemheap_free.$(EXT_OBJ):	$(OBJS_DIR)\sysmemheap_free.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmemheap_getalign.$(EXT_OBJ):	$(OBJS_DIR)\sysmemheap_getalign.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmemheap_getsize.$(EXT_OBJ):	$(OBJS_DIR)\sysmemheap_getsize.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysmemheap_realloc.$(EXT_OBJ):	$(OBJS_DIR)\sysmemheap_realloc.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\handle_close.$(EXT_OBJ):	$(OBJS_DIR)\handle_close.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\handleobj_create.$(EXT_OBJ):	$(OBJS_DIR)\handleobj_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\handleobj_delete.$(EXT_OBJ):	$(OBJS_DIR)\handleobj_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\handleobj_constructor.$(EXT_OBJ):	$(OBJS_DIR)\handleobj_constructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\handleobj_destructor.$(EXT_OBJ):	$(OBJS_DIR)\handleobj_destructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\memory.$(EXT_OBJ):	$(OBJS_DIR)\memory.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\time_getsystemtime.$(EXT_OBJ):	$(OBJS_DIR)\time_getsystemtime.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\time_wait.$(EXT_OBJ):	$(OBJS_DIR)\time_wait.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\process_create.$(EXT_OBJ):	$(OBJS_DIR)\process_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_createex.$(EXT_OBJ):	$(OBJS_DIR)\process_createex.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_delete.$(EXT_OBJ):	$(OBJS_DIR)\process_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_constructor.$(EXT_OBJ):	$(OBJS_DIR)\process_constructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_destructor.$(EXT_OBJ):	$(OBJS_DIR)\process_destructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getcurrenthandle.$(EXT_OBJ):	$(OBJS_DIR)\process_getcurrenthandle.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_exit.$(EXT_OBJ):	$(OBJS_DIR)\process_exit.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_waitexit.$(EXT_OBJ):	$(OBJS_DIR)\process_waitexit.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_setsignalproc.$(EXT_OBJ):	$(OBJS_DIR)\process_setsignalproc.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_sendsignal.$(EXT_OBJ):	$(OBJS_DIR)\process_sendsignal.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getexitcode.$(EXT_OBJ):	$(OBJS_DIR)\process_getexitcode.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getparam.$(EXT_OBJ):	$(OBJS_DIR)\process_getparam.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_setparam.$(EXT_OBJ):	$(OBJS_DIR)\process_setparam.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_entersystemmode.$(EXT_OBJ):	$(OBJS_DIR)\process_entersystemmode.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_leavesystemmode.$(EXT_OBJ):	$(OBJS_DIR)\process_leavesystemmode.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_issystemmode.$(EXT_OBJ):	$(OBJS_DIR)\process_issystemmode.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_setcurrentdir.$(EXT_OBJ):	$(OBJS_DIR)\process_setcurrentdir.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getcurrentdir.$(EXT_OBJ):	$(OBJS_DIR)\process_getcurrentdir.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getparentprocess.$(EXT_OBJ):	$(OBJS_DIR)\process_getparentprocess.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getexecutiontime.$(EXT_OBJ):	$(OBJS_DIR)\process_getexecutiontime.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getcommandline.$(EXT_OBJ):	$(OBJS_DIR)\process_getcommandline.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_setterminal.$(EXT_OBJ):	$(OBJS_DIR)\process_setterminal.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getterminal.$(EXT_OBJ):	$(OBJS_DIR)\process_getterminal.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_setconin.$(EXT_OBJ):	$(OBJS_DIR)\process_setconin.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getconin.$(EXT_OBJ):	$(OBJS_DIR)\process_getconin.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_setconout.$(EXT_OBJ):	$(OBJS_DIR)\process_setconout.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getconout.$(EXT_OBJ):	$(OBJS_DIR)\process_getconout.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_setstdin.$(EXT_OBJ):	$(OBJS_DIR)\process_setstdin.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getstdin.$(EXT_OBJ):	$(OBJS_DIR)\process_getstdin.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_setstdout.$(EXT_OBJ):	$(OBJS_DIR)\process_setstdout.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getstdout.$(EXT_OBJ):	$(OBJS_DIR)\process_getstdout.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_setstderr.$(EXT_OBJ):	$(OBJS_DIR)\process_setstderr.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\process_getstderr.$(EXT_OBJ):	$(OBJS_DIR)\process_getstderr.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\event_create.$(EXT_OBJ):	$(OBJS_DIR)\event_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\event_delete.$(EXT_OBJ):	$(OBJS_DIR)\event_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\event_set.$(EXT_OBJ):	$(OBJS_DIR)\event_set.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\event_clear.$(EXT_OBJ):	$(OBJS_DIR)\event_clear.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\event_wait.$(EXT_OBJ):	$(OBJS_DIR)\event_wait.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\console_getch.$(EXT_OBJ):	$(OBJS_DIR)\console_getch.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\drvobj_close.$(EXT_OBJ):	$(OBJS_DIR)\drvobj_close.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\drvobj_constructor.$(EXT_OBJ):	$(OBJS_DIR)\drvobj_constructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\drvobj_destructor.$(EXT_OBJ):	$(OBJS_DIR)\drvobj_destructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\drvobj_flush.$(EXT_OBJ):	$(OBJS_DIR)\drvobj_flush.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\drvobj_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\drvobj_iocontrol.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\drvobj_open.$(EXT_OBJ):	$(OBJS_DIR)\drvobj_open.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\drvobj_read.$(EXT_OBJ):	$(OBJS_DIR)\drvobj_read.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\drvobj_seek.$(EXT_OBJ):	$(OBJS_DIR)\drvobj_seek.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\drvobj_write.$(EXT_OBJ):	$(OBJS_DIR)\drvobj_write.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\fileobj_constructor.$(EXT_OBJ):	$(OBJS_DIR)\fileobj_constructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\fileobj_create.$(EXT_OBJ):	$(OBJS_DIR)\fileobj_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\fileobj_delete.$(EXT_OBJ):	$(OBJS_DIR)\fileobj_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\fileobj_destructor.$(EXT_OBJ):	$(OBJS_DIR)\fileobj_destructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_adddevice.$(EXT_OBJ):	$(OBJS_DIR)\file_adddevice.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_addvolume.$(EXT_OBJ):	$(OBJS_DIR)\file_addvolume.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_removevolume.$(EXT_OBJ):	$(OBJS_DIR)\file_removevolume.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_getvolume.$(EXT_OBJ):	$(OBJS_DIR)\file_getvolume.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_close.$(EXT_OBJ):	$(OBJS_DIR)\file_close.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_getchar.$(EXT_OBJ):	$(OBJS_DIR)\file_getchar.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_getstring.$(EXT_OBJ):	$(OBJS_DIR)\file_getstring.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_initialize.$(EXT_OBJ):	$(OBJS_DIR)\file_initialize.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\file_iocontrol.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_open.$(EXT_OBJ):	$(OBJS_DIR)\file_open.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_putchar.$(EXT_OBJ):	$(OBJS_DIR)\file_putchar.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_putstring.$(EXT_OBJ):	$(OBJS_DIR)\file_putstring.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_read.$(EXT_OBJ):	$(OBJS_DIR)\file_read.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_readdir.$(EXT_OBJ):	$(OBJS_DIR)\file_readdir.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_seek.$(EXT_OBJ):	$(OBJS_DIR)\file_seek.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_write.$(EXT_OBJ):	$(OBJS_DIR)\file_write.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_driveropen.$(EXT_OBJ):	$(OBJS_DIR)\file_driveropen.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_relpathtoabspath.$(EXT_OBJ):	$(OBJS_DIR)\file_relpathtoabspath.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_getdriverinformation.$(EXT_OBJ):	$(OBJS_DIR)\file_getdriverinformation.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_printformat.$(EXT_OBJ):	$(OBJS_DIR)\file_printformat.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\file_printformatv.$(EXT_OBJ):	$(OBJS_DIR)\file_printformatv.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\stdio_printformat.$(EXT_OBJ):	$(OBJS_DIR)\stdio_printformat.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncdrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\syncdrv_constructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncdrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\syncdrv_destructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncdrv_endprocess.$(EXT_OBJ):	$(OBJS_DIR)\syncdrv_endprocess.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncdrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\syncdrv_iocontrol.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncdrv_sendsignal.$(EXT_OBJ):	$(OBJS_DIR)\syncdrv_sendsignal.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncdrv_startprocess.$(EXT_OBJ):	$(OBJS_DIR)\syncdrv_startprocess.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncfile_constructor.$(EXT_OBJ):	$(OBJS_DIR)\syncfile_constructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncfile_create.$(EXT_OBJ):	$(OBJS_DIR)\syncfile_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncfile_delete.$(EXT_OBJ):	$(OBJS_DIR)\syncfile_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncfile_destructor.$(EXT_OBJ):	$(OBJS_DIR)\syncfile_destructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\syncfile_setsignal.$(EXT_OBJ):	$(OBJS_DIR)\syncfile_setsignal.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvolfile_constructor.$(EXT_OBJ):	$(OBJS_DIR)\sysvolfile_constructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvolfile_create.$(EXT_OBJ):	$(OBJS_DIR)\sysvolfile_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvolfile_delete.$(EXT_OBJ):	$(OBJS_DIR)\sysvolfile_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvolfile_destructor.$(EXT_OBJ):	$(OBJS_DIR)\sysvolfile_destructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvol_constructor.$(EXT_OBJ):	$(OBJS_DIR)\sysvol_constructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvol_open.$(EXT_OBJ):	$(OBJS_DIR)\sysvol_open.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvol_close.$(EXT_OBJ):	$(OBJS_DIR)\sysvol_close.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvol_create.$(EXT_OBJ):	$(OBJS_DIR)\sysvol_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvol_delete.$(EXT_OBJ):	$(OBJS_DIR)\sysvol_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvol_destructor.$(EXT_OBJ):	$(OBJS_DIR)\sysvol_destructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvol_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\sysvol_iocontrol.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvol_adddevice.$(EXT_OBJ):	$(OBJS_DIR)\sysvol_adddevice.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvol_removedevice.$(EXT_OBJ):	$(OBJS_DIR)\sysvol_removedevice.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\sysvol_getdevice.$(EXT_OBJ):	$(OBJS_DIR)\sysvol_getdevice.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\volume_shutdown.$(EXT_OBJ):	$(OBJS_DIR)\volume_shutdown.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\volumeobj_constructor.$(EXT_OBJ):	$(OBJS_DIR)\volumeobj_constructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\volumeobj_create.$(EXT_OBJ):	$(OBJS_DIR)\volumeobj_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\volumeobj_delete.$(EXT_OBJ):	$(OBJS_DIR)\volumeobj_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\volumeobj_destructor.$(EXT_OBJ):	$(OBJS_DIR)\volumeobj_destructor.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\volumeobj_shutdown.$(EXT_OBJ):	$(OBJS_DIR)\volumeobj_shutdown.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\volumeobj_makedir.$(EXT_OBJ):	$(OBJS_DIR)\volumeobj_makedir.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\volumeobj_remove.$(EXT_OBJ):	$(OBJS_DIR)\volumeobj_remove.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\command.$(EXT_OBJ):	$(OBJS_DIR)\command.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\valmemheap_constructor.$(EXT_OBJ):	$(OBJS_DIR)\valmemheap_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\valmemheap_alloc.$(EXT_OBJ):	$(OBJS_DIR)\valmemheap_alloc.c	$(COMMON_HEADERS)
$(OBJS_DIR)\valmemheap_realloc.$(EXT_OBJ):	$(OBJS_DIR)\valmemheap_realloc.c	$(COMMON_HEADERS)
$(OBJS_DIR)\valmemheap_free.$(EXT_OBJ):	$(OBJS_DIR)\valmemheap_free.c	$(COMMON_HEADERS)
$(OBJS_DIR)\valmemheap_getalign.$(EXT_OBJ):	$(OBJS_DIR)\valmemheap_getalign.c	$(COMMON_HEADERS)
$(OBJS_DIR)\valmemheap_getsize.$(EXT_OBJ):	$(OBJS_DIR)\valmemheap_getsize.c	$(COMMON_HEADERS)
$(OBJS_DIR)\valmemheap_alignsize.$(EXT_OBJ):	$(OBJS_DIR)\valmemheap_alignsize.c	$(COMMON_HEADERS)
$(OBJS_DIR)\valmemheap_ismember.$(EXT_OBJ):	$(OBJS_DIR)\valmemheap_ismember.c	$(COMMON_HEADERS)

$(OBJS_DIR)\fixmemheap_create.$(EXT_OBJ):	$(OBJS_DIR)\fixmemheap_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fixmemheap_delete.$(EXT_OBJ):	$(OBJS_DIR)\fixmemheap_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fixmemheap_constructor.$(EXT_OBJ):	$(OBJS_DIR)\fixmemheap_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fixmemheap_alloc.$(EXT_OBJ):	$(OBJS_DIR)\fixmemheap_alloc.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fixmemheap_realloc.$(EXT_OBJ):	$(OBJS_DIR)\fixmemheap_realloc.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fixmemheap_free.$(EXT_OBJ):	$(OBJS_DIR)\fixmemheap_free.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fixmemheap_getalign.$(EXT_OBJ):	$(OBJS_DIR)\fixmemheap_getalign.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fixmemheap_getsize.$(EXT_OBJ):	$(OBJS_DIR)\fixmemheap_getsize.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fixmemheap_alignsize.$(EXT_OBJ):	$(OBJS_DIR)\fixmemheap_alignsize.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fixmemheap_ismember.$(EXT_OBJ):	$(OBJS_DIR)\fixmemheap_ismember.c	$(COMMON_HEADERS)

$(OBJS_DIR)\automemheap_alignsize.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_alignsize.c	$(COMMON_HEADERS)
$(OBJS_DIR)\automemheap_alloc.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_alloc.c	$(COMMON_HEADERS)
$(OBJS_DIR)\automemheap_constructor.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\automemheap_create.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\automemheap_delete.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\automemheap_destructor.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\automemheap_free.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_free.c	$(COMMON_HEADERS)
$(OBJS_DIR)\automemheap_getalign.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_getalign.c	$(COMMON_HEADERS)
$(OBJS_DIR)\automemheap_getsize.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_getsize.c	$(COMMON_HEADERS)
$(OBJS_DIR)\automemheap_realloc.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_realloc.c	$(COMMON_HEADERS)
$(OBJS_DIR)\automemheap_searchheap.$(EXT_OBJ):	$(OBJS_DIR)\automemheap_searchheap.c	$(COMMON_HEADERS)

$(OBJS_DIR)\assoc_create.$(EXT_OBJ):	$(OBJS_DIR)\assoc_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_createex.$(EXT_OBJ):	$(OBJS_DIR)\assoc_createex.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_delete.$(EXT_OBJ):	$(OBJS_DIR)\assoc_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_constructor.$(EXT_OBJ):	$(OBJS_DIR)\assoc_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_destructor.$(EXT_OBJ):	$(OBJS_DIR)\assoc_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_add.$(EXT_OBJ):	$(OBJS_DIR)\assoc_add.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_set.$(EXT_OBJ):	$(OBJS_DIR)\assoc_set.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_get.$(EXT_OBJ):	$(OBJS_DIR)\assoc_get.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_getat.$(EXT_OBJ):	$(OBJS_DIR)\assoc_getat.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_getfirst.$(EXT_OBJ):	$(OBJS_DIR)\assoc_getfirst.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_getpos.$(EXT_OBJ):	$(OBJS_DIR)\assoc_getpos.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_getnext.$(EXT_OBJ):	$(OBJS_DIR)\assoc_getnext.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_remove.$(EXT_OBJ):	$(OBJS_DIR)\assoc_remove.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_addnode.$(EXT_OBJ):	$(OBJS_DIR)\assoc_addnode.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_getnode.$(EXT_OBJ):	$(OBJS_DIR)\assoc_getnode.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_removenode.$(EXT_OBJ):	$(OBJS_DIR)\assoc_removenode.c	$(COMMON_HEADERS)
$(OBJS_DIR)\assoc_getminnode.$(EXT_OBJ):	$(OBJS_DIR)\assoc_getminnode.c	$(COMMON_HEADERS)

$(OBJS_DIR)\hashtable_create.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_createex.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_createex.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_delete.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_constructor.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_destructor.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_get.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_get.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_set.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_set.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_remove.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_remove.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_removeall.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_removeall.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_findclose.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_findclose.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_findnext.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_findnext.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_findopen.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_findopen.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_searchnode.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_searchnode.c	$(COMMON_HEADERS)
$(OBJS_DIR)\hashtable_createnode.$(EXT_OBJ):	$(OBJS_DIR)\hashtable_createnode.c	$(COMMON_HEADERS)

$(OBJS_DIR)\list_create.$(EXT_OBJ):	$(OBJS_DIR)\list_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\list_createex.$(EXT_OBJ):	$(OBJS_DIR)\list_createex.c	$(COMMON_HEADERS)
$(OBJS_DIR)\list_addtail.$(EXT_OBJ):	$(OBJS_DIR)\list_addtail.c	$(COMMON_HEADERS)
$(OBJS_DIR)\list_getat.$(EXT_OBJ):	$(OBJS_DIR)\list_getat.c	$(COMMON_HEADERS)
$(OBJS_DIR)\list_getheadpos.$(EXT_OBJ):	$(OBJS_DIR)\list_getheadpos.c	$(COMMON_HEADERS)
$(OBJS_DIR)\list_getnextpos.$(EXT_OBJ):	$(OBJS_DIR)\list_getnextpos.c	$(COMMON_HEADERS)
$(OBJS_DIR)\list_getprevpos.$(EXT_OBJ):	$(OBJS_DIR)\list_getprevpos.c	$(COMMON_HEADERS)
$(OBJS_DIR)\list_gettailpos.$(EXT_OBJ):	$(OBJS_DIR)\list_gettailpos.c	$(COMMON_HEADERS)
$(OBJS_DIR)\list_remove.$(EXT_OBJ):	$(OBJS_DIR)\list_remove.c	$(COMMON_HEADERS)

$(OBJS_DIR)\streambuf_create.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_getbuf.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_getbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_sendbuf.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_sendbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_senddata.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_senddata.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_sendchar.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_sendchar.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_recvbuf.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_recvbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_relbuf.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_relbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_recvdata.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_recvdata.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_recvchar.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_recvchar.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_clear.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_clear.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_refdatasize.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_refdatasize.c	$(COMMON_HEADERS)
$(OBJS_DIR)\streambuf_reffreesize.$(EXT_OBJ):	$(OBJS_DIR)\streambuf_reffreesize.c	$(COMMON_HEADERS)

$(OBJS_DIR)\packetbuf_create.$(EXT_OBJ):	$(OBJS_DIR)\packetbuf_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\packetbuf_getbuf.$(EXT_OBJ):	$(OBJS_DIR)\packetbuf_getbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\packetbuf_sendbuf.$(EXT_OBJ):	$(OBJS_DIR)\packetbuf_sendbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\packetbuf_senddata.$(EXT_OBJ):	$(OBJS_DIR)\packetbuf_senddata.c	$(COMMON_HEADERS)
$(OBJS_DIR)\packetbuf_recvbuf.$(EXT_OBJ):	$(OBJS_DIR)\packetbuf_recvbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\packetbuf_relbuf.$(EXT_OBJ):	$(OBJS_DIR)\packetbuf_relbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\packetbuf_recvdata.$(EXT_OBJ):	$(OBJS_DIR)\packetbuf_recvdata.c	$(COMMON_HEADERS)
$(OBJS_DIR)\packetbuf_clear.$(EXT_OBJ):	$(OBJS_DIR)\packetbuf_clear.c	$(COMMON_HEADERS)

$(OBJS_DIR)\ipchecksum_getdigest.$(EXT_OBJ):	$(OBJS_DIR)\ipchecksum_getdigest.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipchecksum_update.$(EXT_OBJ):	$(OBJS_DIR)\ipchecksum_update.c	$(COMMON_HEADERS)

$(OBJS_DIR)\crc16_getdigest.$(EXT_OBJ):	$(OBJS_DIR)\crc16_getdigest.c	$(COMMON_HEADERS)
$(OBJS_DIR)\crc16_update.$(EXT_OBJ):	$(OBJS_DIR)\crc16_update.c	$(COMMON_HEADERS)
$(OBJS_DIR)\crc16_reset.$(EXT_OBJ):	$(OBJS_DIR)\crc16_reset.c	$(COMMON_HEADERS)
$(OBJS_DIR)\crc16_table.$(EXT_OBJ):	$(OBJS_DIR)\crc16_table.c	$(COMMON_HEADERS)

$(OBJS_DIR)\stringformat_formatstring.$(EXT_OBJ):	$(OBJS_DIR)\stringformat_formatstring.c	$(COMMON_HEADERS)
$(OBJS_DIR)\stringformat_formatstringv.$(EXT_OBJ):	$(OBJS_DIR)\stringformat_formatstringv.c	$(COMMON_HEADERS)
$(OBJS_DIR)\stringformat_format.$(EXT_OBJ):	$(OBJS_DIR)\stringformat_format.c	$(COMMON_HEADERS)
$(OBJS_DIR)\stringformat_formatv.$(EXT_OBJ):	$(OBJS_DIR)\stringformat_formatv.c	$(COMMON_HEADERS)
$(OBJS_DIR)\stringformat_string.$(EXT_OBJ):	$(OBJS_DIR)\stringformat_string.c	$(COMMON_HEADERS)
$(OBJS_DIR)\stringformat_decimal.$(EXT_OBJ):	$(OBJS_DIR)\stringformat_decimal.c	$(COMMON_HEADERS)
$(OBJS_DIR)\stringformat_hexadecimal.$(EXT_OBJ):	$(OBJS_DIR)\stringformat_hexadecimal.c	$(COMMON_HEADERS)
$(OBJS_DIR)\stringformat_nibble.$(EXT_OBJ):	$(OBJS_DIR)\stringformat_nibble.c	$(COMMON_HEADERS)

$(OBJS_DIR)\memutil_memcopyb.$(EXT_OBJ):	$(OBJS_DIR)\memutil_memcopyb.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memutil_memcopyh.$(EXT_OBJ):	$(OBJS_DIR)\memutil_memcopyh.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memutil_memcopyw.$(EXT_OBJ):	$(OBJS_DIR)\memutil_memcopyw.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memutil_memsetb.$(EXT_OBJ):	$(OBJS_DIR)\memutil_memsetb.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memutil_memseth.$(EXT_OBJ):	$(OBJS_DIR)\memutil_memseth.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memutil_memsetw.$(EXT_OBJ):	$(OBJS_DIR)\memutil_memsetw.c	$(COMMON_HEADERS)

$(OBJS_DIR)\vt100drv_create.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_delete.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_open.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_close.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_seek.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_read.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_write.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_flush.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\vt100drv_getch.$(EXT_OBJ):	$(OBJS_DIR)\vt100drv_getch.c	$(COMMON_HEADERS)

$(OBJS_DIR)\pcattextdrv_create.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcattextdrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcattextdrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcattextdrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcattextdrv_open.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcattextdrv_close.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcattextdrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcattextdrv_write.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcattextdrv_putchar.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_putchar.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcattextdrv_setcursor.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_setcursor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcattextdrv_clearscreen.$(EXT_OBJ):	$(OBJS_DIR)\pcattextdrv_clearscreen.c	$(COMMON_HEADERS)

$(OBJS_DIR)\pcatkeydrv_create.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcatkeydrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcatkeydrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcatkeydrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcatkeydrv_open.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcatkeydrv_close.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcatkeydrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcatkeydrv_seek.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcatkeydrv_read.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcatkeydrv_write.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pcatkeydrv_flush.$(EXT_OBJ):	$(OBJS_DIR)\pcatkeydrv_flush.c	$(COMMON_HEADERS)

$(OBJS_DIR)\tcpip_create.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_delete.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_constructor.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_destructor.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_open.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_close.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_seek.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_read.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_write.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_flush.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_recv.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_recv.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpip_stringtoaddr.$(EXT_OBJ):	$(OBJS_DIR)\tcpip_stringtoaddr.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpipfile_create.$(EXT_OBJ):	$(OBJS_DIR)\tcpipfile_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpipfile_delete.$(EXT_OBJ):	$(OBJS_DIR)\tcpipfile_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpipfile_constructor.$(EXT_OBJ):	$(OBJS_DIR)\tcpipfile_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\tcpipfile_destructor.$(EXT_OBJ):	$(OBJS_DIR)\tcpipfile_destructor.c	$(COMMON_HEADERS)

$(OBJS_DIR)\ipether_create.$(EXT_OBJ):	$(OBJS_DIR)\ipether_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_delete.$(EXT_OBJ):	$(OBJS_DIR)\ipether_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_constructor.$(EXT_OBJ):	$(OBJS_DIR)\ipether_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_destructor.$(EXT_OBJ):	$(OBJS_DIR)\ipether_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_open.$(EXT_OBJ):	$(OBJS_DIR)\ipether_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_close.$(EXT_OBJ):	$(OBJS_DIR)\ipether_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\ipether_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_seek.$(EXT_OBJ):	$(OBJS_DIR)\ipether_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_read.$(EXT_OBJ):	$(OBJS_DIR)\ipether_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_write.$(EXT_OBJ):	$(OBJS_DIR)\ipether_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_recv.$(EXT_OBJ):	$(OBJS_DIR)\ipether_recv.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_flush.$(EXT_OBJ):	$(OBJS_DIR)\ipether_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ipether_getmacaddr.$(EXT_OBJ):	$(OBJS_DIR)\ipether_getmacaddr.c	$(COMMON_HEADERS)

$(OBJS_DIR)\ne2000drv.$(EXT_OBJ):	$(OBJS_DIR)\ne2000drv.c	$(COMMON_HEADERS)
$(OBJS_DIR)\ne2000hal.$(EXT_OBJ):	$(OBJS_DIR)\ne2000hal.c	$(COMMON_HEADERS)

$(OBJS_DIR)\lan9000drv_close.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_create.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_delete.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_flush.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_isr.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_isr.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_open.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_read.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_seek.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000drv_write.$(EXT_OBJ):	$(OBJS_DIR)\lan9000drv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_create.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_delete.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_getinterruptstatus.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_getinterruptstatus.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_getphysicaladdr.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_getphysicaladdr.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_mii.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_mii.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_phyregread.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_phyregread.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_phyregwrite.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_phyregwrite.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_recv.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_recv.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_send.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_send.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_setinterruptmask.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_setinterruptmask.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_setup.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_setup.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9000hal_stop.$(EXT_OBJ):	$(OBJS_DIR)\lan9000hal_stop.c	$(COMMON_HEADERS)

$(OBJS_DIR)\lan9118drv_create.$(EXT_OBJ):	$(OBJS_DIR)\lan9118drv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9118drv_delete.$(EXT_OBJ):	$(OBJS_DIR)\lan9118drv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9118drv_open.$(EXT_OBJ):	$(OBJS_DIR)\lan9118drv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9118drv_close.$(EXT_OBJ):	$(OBJS_DIR)\lan9118drv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9118drv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\lan9118drv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9118drv_seek.$(EXT_OBJ):	$(OBJS_DIR)\lan9118drv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9118drv_read.$(EXT_OBJ):	$(OBJS_DIR)\lan9118drv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9118drv_write.$(EXT_OBJ):	$(OBJS_DIR)\lan9118drv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9118drv_flush.$(EXT_OBJ):	$(OBJS_DIR)\lan9118drv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\lan9118drv_isr.$(EXT_OBJ):	$(OBJS_DIR)\lan9118drv_isr.c	$(COMMON_HEADERS)

$(OBJS_DIR)\pc16550drv_create.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_delete.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_open.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_close.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_seek.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_read.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_write.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_flush.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550drv_isr.$(EXT_OBJ):	$(OBJS_DIR)\pc16550drv_isr.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550hal_create.$(EXT_OBJ):	$(OBJS_DIR)\pc16550hal_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550hal_delete.$(EXT_OBJ):	$(OBJS_DIR)\pc16550hal_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550hal_setup.$(EXT_OBJ):	$(OBJS_DIR)\pc16550hal_setup.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550hal_stop.$(EXT_OBJ):	$(OBJS_DIR)\pc16550hal_stop.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550hal_setspeed.$(EXT_OBJ):	$(OBJS_DIR)\pc16550hal_setspeed.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550hal_recvchar.$(EXT_OBJ):	$(OBJS_DIR)\pc16550hal_recvchar.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550hal_sendchar.$(EXT_OBJ):	$(OBJS_DIR)\pc16550hal_sendchar.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550hal_enableinterrupt.$(EXT_OBJ):	$(OBJS_DIR)\pc16550hal_enableinterrupt.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550hal_getinterruptstatus.$(EXT_OBJ):	$(OBJS_DIR)\pc16550hal_getinterruptstatus.c	$(COMMON_HEADERS)
$(OBJS_DIR)\pc16550hal_getstatus.$(EXT_OBJ):	$(OBJS_DIR)\pc16550hal_getstatus.c	$(COMMON_HEADERS)

$(OBJS_DIR)\at91usartdrv_create.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_open.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_close.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_seek.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_read.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_write.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_flush.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\at91usartdrv_isr.$(EXT_OBJ):	$(OBJS_DIR)\at91usartdrv_isr.c	$(COMMON_HEADERS)

$(OBJS_DIR)\scidrv_create.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_open.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_close.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_seek.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_read.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_write.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_flush.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_isrrxerr.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_isrrxerr.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_isrrx.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_isrrx.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_isrtx.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_isrtx.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scidrv_isrtxend.$(EXT_OBJ):	$(OBJS_DIR)\scidrv_isrtxend.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scihal_create.$(EXT_OBJ):	$(OBJS_DIR)\scihal_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scihal_delete.$(EXT_OBJ):	$(OBJS_DIR)\scihal_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scihal_enableinterrupt.$(EXT_OBJ):	$(OBJS_DIR)\scihal_enableinterrupt.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scihal_recvchar.$(EXT_OBJ):	$(OBJS_DIR)\scihal_recvchar.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scihal_sendchar.$(EXT_OBJ):	$(OBJS_DIR)\scihal_sendchar.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scihal_setspeed.$(EXT_OBJ):	$(OBJS_DIR)\scihal_setspeed.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scihal_setup.$(EXT_OBJ):	$(OBJS_DIR)\scihal_setup.c	$(COMMON_HEADERS)
$(OBJS_DIR)\scihal_stop.$(EXT_OBJ):	$(OBJS_DIR)\scihal_stop.c	$(COMMON_HEADERS)

$(OBJS_DIR)\mx1uartdrv_create.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_open.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_close.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_seek.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_read.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_write.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_flush.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mx1uartdrv_isr.$(EXT_OBJ):	$(OBJS_DIR)\mx1uartdrv_isr.c	$(COMMON_HEADERS)

$(OBJS_DIR)\mn103scdrv_create.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_open.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_close.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_seek.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_read.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_write.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_flush.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_isrtx.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_isrtx.c	$(COMMON_HEADERS)
$(OBJS_DIR)\mn103scdrv_isrrx.$(EXT_OBJ):	$(OBJS_DIR)\mn103scdrv_isrrx.c	$(COMMON_HEADERS)

$(OBJS_DIR)\xilinxuartdrv_create.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_open.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_close.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_write.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_read.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_seek.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_flush.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\xilinxuartdrv_isr.$(EXT_OBJ):	$(OBJS_DIR)\xilinxuartdrv_isr.c	$(COMMON_HEADERS)

$(OBJS_DIR)\winsockdrv_close.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_create.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_flush.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_isr.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_isr.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_open.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_read.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_recv.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_recv.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_seek.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_send.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_send.c	$(COMMON_HEADERS)
$(OBJS_DIR)\winsockdrv_write.$(EXT_OBJ):	$(OBJS_DIR)\winsockdrv_write.c	$(COMMON_HEADERS)

$(OBJS_DIR)\jellyuartdrv_create.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_open.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_close.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_seek.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_read.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_write.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_flush.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyuartdrv_isr.$(EXT_OBJ):	$(OBJS_DIR)\jellyuartdrv_isr.c	$(COMMON_HEADERS)

$(OBJS_DIR)\i2cdrv_bytewrite.$(EXT_OBJ):	$(OBJS_DIR)\i2cdrv_bytewrite.c	$(COMMON_HEADERS)
$(OBJS_DIR)\i2cdrv_byteread.$(EXT_OBJ):	$(OBJS_DIR)\i2cdrv_byteread.c	$(COMMON_HEADERS)
$(OBJS_DIR)\i2cdrv_burstwrite.$(EXT_OBJ):	$(OBJS_DIR)\i2cdrv_burstwrite.c	$(COMMON_HEADERS)
$(OBJS_DIR)\i2cdrv_burstread.$(EXT_OBJ):	$(OBJS_DIR)\i2cdrv_burstread.c	$(COMMON_HEADERS)

$(OBJS_DIR)\jellyi2cdrv_create.$(EXT_OBJ):	$(OBJS_DIR)\jellyi2cdrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyi2cdrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\jellyi2cdrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyi2cdrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\jellyi2cdrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyi2cdrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\jellyi2cdrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyi2cdrv_open.$(EXT_OBJ):	$(OBJS_DIR)\jellyi2cdrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyi2cdrv_close.$(EXT_OBJ):	$(OBJS_DIR)\jellyi2cdrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyi2cdrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\jellyi2cdrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\jellyi2cdrv_access.$(EXT_OBJ):	$(OBJS_DIR)\jellyi2cdrv_access.c	$(COMMON_HEADERS)

$(OBJS_DIR)\fatvol_create.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_delete.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_constructor.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_destructor.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_open.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_close.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_seek.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_read.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_write.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_flush.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_shutdown.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_shutdown.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_makedir.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_makedir.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_remove.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_remove.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_clusterread.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_clusterread.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_clusterwrite.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_clusterwrite.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_flushclusterbuf.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_flushclusterbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_flushfat.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_flushfat.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_getclusterbuf.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_getclusterbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_relclusterbuf.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_relclusterbuf.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_alloccluster.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_alloccluster.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_freecluster.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_freecluster.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_getnextcluster.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_getnextcluster.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_setnextcluster.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_setnextcluster.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatvol_syncfilesize.$(EXT_OBJ):	$(OBJS_DIR)\fatvol_syncfilesize.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatfile_create.$(EXT_OBJ):	$(OBJS_DIR)\fatfile_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatfile_delete.$(EXT_OBJ):	$(OBJS_DIR)\fatfile_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatfile_constructor.$(EXT_OBJ):	$(OBJS_DIR)\fatfile_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\fatfile_destructor.$(EXT_OBJ):	$(OBJS_DIR)\fatfile_destructor.c	$(COMMON_HEADERS)

$(OBJS_DIR)\memdrv_create.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_delete.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_constructor.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_destructor.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_destructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_open.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_open.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_close.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_close.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_iocontrol.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_iocontrol.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_flush.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_flush.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_read.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_read.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_seek.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_seek.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_write.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_write.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memdrv_getinformation.$(EXT_OBJ):	$(OBJS_DIR)\memdrv_getinformation.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memfile_create.$(EXT_OBJ):	$(OBJS_DIR)\memfile_create.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memfile_delete.$(EXT_OBJ):	$(OBJS_DIR)\memfile_delete.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memfile_constructor.$(EXT_OBJ):	$(OBJS_DIR)\memfile_constructor.c	$(COMMON_HEADERS)
$(OBJS_DIR)\memfile_destructor.$(EXT_OBJ):	$(OBJS_DIR)\memfile_destructor.c	$(COMMON_HEADERS)

$(OBJS_DIR)\shell_main.$(EXT_OBJ):	$(OBJS_DIR)\shell_main.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\shell_create.$(EXT_OBJ):	$(OBJS_DIR)\shell_create.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\shell_delete.$(EXT_OBJ):	$(OBJS_DIR)\shell_delete.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\shell_executecommand.$(EXT_OBJ):	$(OBJS_DIR)\shell_executecommand.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\shell_executescript.$(EXT_OBJ):	$(OBJS_DIR)\shell_executescript.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\shell_inputline.$(EXT_OBJ):	$(OBJS_DIR)\shell_inputline.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\shell_interactive.$(EXT_OBJ):	$(OBJS_DIR)\shell_interactive.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\shell_putchar.$(EXT_OBJ):	$(OBJS_DIR)\shell_putchar.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\shell_curright.$(EXT_OBJ):	$(OBJS_DIR)\shell_curright.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\shell_curleft.$(EXT_OBJ):	$(OBJS_DIR)\shell_curleft.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)
$(OBJS_DIR)\shell_replaceline.$(EXT_OBJ):	$(OBJS_DIR)\shell_replaceline.c	$(COMMON_HEADERS) $(SYSTEM_HEADERS)

$(OBJS_DIR)\whiteboardcmd_main.$(EXT_OBJ):	$(OBJS_DIR)\whiteboardcmd_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\processlist_main.$(EXT_OBJ):	$(OBJS_DIR)\processlist_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\processsignal_main.$(EXT_OBJ):	$(OBJS_DIR)\processsignal_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\commandlist_main.$(EXT_OBJ):	$(OBJS_DIR)\commandlist_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\memdump_main.$(EXT_OBJ):	$(OBJS_DIR)\memdump_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\memwrite_main.$(EXT_OBJ):	$(OBJS_DIR)\memwrite_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\memfill_main.$(EXT_OBJ):	$(OBJS_DIR)\memfill_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\memcopy_main.$(EXT_OBJ):	$(OBJS_DIR)\memcopy_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\memsave_main.$(EXT_OBJ):	$(OBJS_DIR)\memsave_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\memload_main.$(EXT_OBJ):	$(OBJS_DIR)\memload_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\memtest_main.$(EXT_OBJ):	$(OBJS_DIR)\memtest_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\keytest_main.$(EXT_OBJ):	$(OBJS_DIR)\keytest_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\timecmd_main.$(EXT_OBJ):	$(OBJS_DIR)\timecmd_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\i2ccmd_main.$(EXT_OBJ):	$(OBJS_DIR)\i2ccmd_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\filelist_main.$(EXT_OBJ):	$(OBJS_DIR)\filelist_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\filecat_main.$(EXT_OBJ):	$(OBJS_DIR)\filecat_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\filecopy_main.$(EXT_OBJ):	$(OBJS_DIR)\filecopy_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\filedump_main.$(EXT_OBJ):	$(OBJS_DIR)\filedump_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\fatmount_main.$(EXT_OBJ):	$(OBJS_DIR)\fatmount_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\norflashcmd_main.$(EXT_OBJ):	$(OBJS_DIR)\norflashcmd_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\ethersnoop_main.$(EXT_OBJ):	$(OBJS_DIR)\ethersnoop_main.c	$(COMMON_HEADERS)

$(OBJS_DIR)\hello_main.$(EXT_OBJ):	$(OBJS_DIR)\hello_main.c	$(COMMON_HEADERS)



# end of file
