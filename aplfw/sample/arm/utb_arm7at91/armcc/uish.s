
HEAP_SIZE		EQU		256


				EXPORT	__user_initial_stackheap
				IMPORT	__use_two_region_memory
				
				IMPORT	_kernel_int_stkblk
				IMPORT	_kernel_int_isp


				PRESERVE8
				AREA	UISH, CODE, READONLY
				CODE32

__user_initial_stackheap	FUNCTION
				
				ldr		r0, =User_Heap				; Heap Base
				ldr		r2, =HEAP_SIZE
				add		r2, r2, r0					; Heap Limit
				
				ldr		r1, =_kernel_int_isp
				ldr		r1, [r1]					; Stack Base
				ldr		r3, =_kernel_int_stkblk		; Stack Limit

				bx		lr

				ENDFUNC



				AREA	||.bss||, NOINIT, ALIGN=2
User_Heap
				%	HEAP_SIZE



				END
