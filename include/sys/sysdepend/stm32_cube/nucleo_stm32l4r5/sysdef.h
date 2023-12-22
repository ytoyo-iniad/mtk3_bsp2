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
 *	sysdef.h
 *
 *	System dependencies definition (STM32Cule NUCLEO STM32L476)
 *	Included also from assembler program.
 */

#ifndef _MTKBSP_SYS_SYSDEF_DEPEND_H_
#define _MTKBSP_SYS_SYSDEF_DEPEND_H_

/* ------------------------------------------------------------------------ */
/*
 * Internal Memorie (Main RAM)
 */
#define INTERNAL_RAM_START      0x20000000
#define INTERNAL_RAM_SIZE       0x000A0000	/* SRAM Size 640KB */
#define INTERNAL_RAM_END        (INTERNAL_RAM_START+INTERNAL_RAM_SIZE)

/* ------------------------------------------------------------------------ */
/*
 * Interruptrs
 */
#define N_INTVEC		95	/* Number of Interrupt vectors */
#define	N_EXTIEVT		39	/*  Number of EXTI event input */

/* ------------------------------------------------------------------------ */
/* STM32L4 CPU-dependent definition
 */
#include <sys/sysdepend/stm32_cube/cpu/stm32l4/sysdef.h>

#endif /* _MTKBSP_TK_SYSDEF_DEPEND_H_ */
