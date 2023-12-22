/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.0 BSP 2.0
 *
 *    Copyright (C) 2023 by Ken Sakamura.
 *    This software is distributed under the T-License 2.1.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2023/12.
 *
 *----------------------------------------------------------------------
 */

/*
 *	machine.h
 *
 *	Machine type definition (NUCLEO STM32F411)
 */

#ifndef _MTKBSP_SYS_SYSDEPEND_MACHINE_H_
#define _MTKBSP_SYS_SYSDEPEND_MACHINE_H_

/*
 * [TYPE]_[CPU]		TARGET SYSTEM
 * CPU_xxxx		CPU type
 * CPU_CORE_xxx		CPU core type
 */

/* ----- MUCLEO STM32F4 (CPU: STM32F411RE) definition ----- */
#define MTKBSP_STM32CUBE		1	/* Target system   : STM32Cube */
#define MTKBSP_NUCLEO_STM32F411		1	/* Target Board    : NUCLEO STM32F411 */

#define MTKBSP_CPU_STM32		1	/* Target CPU type : STM32 group */
#define MTKBSP_CPU_STM32F4		1	/* Target CPU type : STM32F4 series */
#define MTKBSP_CPU_STM32F411		1	/* Target CPU      : STM32F411 */

#define MTKBSP_CPU_CORE_ARMV7M		1	/* Target CPU-Core type : ARMv7-M */
#define MTKBSP_CPU_CORE_ACM4F		1	/* Target CPU-Core      : ARM Cortex-M4F */

#define KNL_SYSDEP_PATH	sysdepend/stm32_cube			/* Kernel sysdepend path */

#define TARGET_DIR	stm32_cube/nucleo_stm32f411	/* Sysdepend-Directory name */
#define TARGET_GRP_DIR	stm32_cube 			/* Sysdepend-Group-Directory name */
#define	TARGET_CPU_DIR	stm32f4				/* Sysdepend-CPU-Directory name */

/*
 **** CPU Core depeneded profile (ARMv7M)
 */
#include <sys/sysdepend/stm32_cube/cpu/core/armv7m/machine.h>

#endif /* _MTKBSP_SYS_SYSDEPEND_MACHINE_H_ */
