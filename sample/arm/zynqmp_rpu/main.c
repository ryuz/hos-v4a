/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  main.c
 * @brief %jp{メイン関数}%en{main}
 *
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"
#include "arch/proc/arm/arm_v7r/proc.h"
#include "arch/irc/arm/pl390/irc.h"


/** %jp{メイン関数} */
int main()
{
	int i;
	int n;
	int region_num;

	/* MPU設定 */
	n = vmpu_get_number_of_regions();
	for ( i = 0; i < n; ++i ) {
		vmpu_set_region_size(_KERNEL_MPU_DISABLE);
	}
	region_num = 0;

	/* DDR4-SDRAM */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0x00000000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_2G);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_WRITE_BACK_ALLOC);

	/* PL(FPD0) */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0xa0000000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_256M);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_NO_CACHEABLE);

	/* PL(FPD1) */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0xb0000000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_256M);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_NO_CACHEABLE);

	/* PL(FPD0) */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0xc0000000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_512M);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_NO_CACHEABLE);

	/* 256M of device memory from 0xE0000000 to 0xEFFFFFFF for PCIe Low */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0xe0000000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_256M);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_NON_SHAREABLE_DEVICE);

	/* 16M of device memory from 0xF8000000 to 0xF8FFFFFF for STM_CORESIGHT */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0xf8000000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_16M);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_NON_SHAREABLE_DEVICE);

	/* 1M of device memory from 0xF9000000 to 0xF90FFFFF for RPU_A53_GIC */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0xf9000000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_1M);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_NON_SHAREABLE_DEVICE);

	/* 16M of device memory from 0xFD000000 to 0xFDFFFFFF for FPS slaves */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0xfd000000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_16M);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_NON_SHAREABLE_DEVICE);

	/* 16M of device memory from 0xFE000000 to 0xFEFFFFFF for Upper LPS slaves */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0xfe000000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_16M);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_NON_SHAREABLE_DEVICE);

	/* 16M of device memory from 0xFF000000 to 0xFFFFFFFF for Lower LPS slaves, CSU, PMU, TCM, OCM */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0xff000000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_16M);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_NON_SHAREABLE_DEVICE);

	/* 256K of OCM RAM from 0xFFFC0000 to 0xFFFFFFFF marked as normal memory */
	vmpu_set_region_number(region_num); region_num++;
	vmpu_set_region_base_address(0xfffc0000);
	vmpu_set_region_size(_KERNEL_MPU_SIZE_256K);
	vmpu_set_region_access_control(_KERNEL_MPU_AP_FULL | _KERNEL_MPU_WRITE_BACK_ALLOC);



	/* ICD(Distributor) setup */
	UB targetcpu = 0x01;
	vdis_icd();
	
	/* set TTC0-1 */
	vchg_icdiptr(74, targetcpu);   /* set ICDIPTR */

	/* PL */
	for ( i = 0; i < 8; ++i ) {
		vchg_icdiptr(121 + i, targetcpu);  						/* set ICDIPTR */
		vchg_icdicfr(121 + i, _KERNEL_ARM_PL390_ICDICFR_EDGE);  /* set ICDICFR */
	}
	for ( i = 0; i < 8; ++i ) {
		vchg_icdiptr(136 + i, targetcpu);  						/* set ICDIPTR */
		vchg_icdicfr(136 + i, _KERNEL_ARM_PL390_ICDICFR_EDGE);  /* set ICDICFR */
	}

	vena_icd();	/* enable IDC */

	/* %jp{カーネルの動作開始} */
	vsta_knl();
	
	return 0;
}


/* end of file */
