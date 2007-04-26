/* ------------------------------------------------------------------------ */
/*  HOS-V4a  kernel configuration                                           */
/*    kernel object ID definition                                           */
/*                                                                          */
/* ------------------------------------------------------------------------ */


#ifndef __KERNEL__kernel_id_h__
#define __KERNEL__kernel_id_h__



/* Task object ID definetion */

#define TSKID_SAMPLE		1

#ifdef  TMAX_TSKID
#undef  TMAX_TSKID
#endif

#define TMAX_TSKID		32



/* Semaphore object ID definetion */


#ifdef  TMAX_SEMID
#undef  TMAX_SEMID
#endif

#define TMAX_SEMID		32



/* event flag ID definetion */

#ifdef  TMAX_FLGID
#undef  TMAX_FLGID
#endif

#define TMAX_FLGID		32



/* time tic */
#define TIC_NUME		(1)
#define TIC_DENO		(1)


/* Semaphore object ID definetion */


#ifdef  TMAX_CYCID
#undef  TMAX_CYCID
#endif

#define TMAX_CYCID		0




#endif	/* __KERNEL__kernel_id_h__ */


/* ------------------------------------------------------------------------ */
/*  End of file                                                             */
/* ------------------------------------------------------------------------ */
