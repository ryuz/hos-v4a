

				IMPORT	Reset_Handler
				IMPORT	Undefined_Handler
				IMPORT	Swi_Handler
				IMPORT	Prefetch_Handler
				IMPORT	Abort_Handler
				IMPORT	_kernel_irq_hdr
				IMPORT	_kernel_fiq_hdr


				CODE32

				PRESERVE8
				AREA	Init, CODE, READONLY

				ENTRY

				ldr     pc, Reset_Addr
				ldr     pc, Undefined_Addr
				ldr     pc, Swi_Addr
				ldr     pc, Prefetch_Addr
				ldr     pc, Abort_Addr
				nop
				ldr     pc, IRQ_Addr
				ldr     pc, FIQ_Addr


Reset_Addr		dcd		Reset_Handler
Undefined_Addr	dcd		Undefined_Handler
Swi_Addr		dcd		Swi_Handler
Prefetch_Addr	dcd		Prefetch_Handler
Abort_Addr		dcd		Abort_Handler
IRQ_Addr		dcd		_kernel_irq_hdr
FIQ_Addr		dcd		_kernel_fiq_hdr


				END



; end of file
