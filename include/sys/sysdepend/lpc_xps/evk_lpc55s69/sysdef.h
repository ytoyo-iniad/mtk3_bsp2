/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.0 BSP 2.0
 *
 *    Copyright (C) 2023 by Ken Sakamura.
 *    This software is distributed under the T-License 2.1.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2024/01.
 *
 *----------------------------------------------------------------------
 */

/*
 *	sysdef.h
 *
 *	System dependencies definition (MCUXpresso LPC55S69-EVK)
 *	Included also from assembler program.
 */

#ifndef _MTKBSP_SYS_SYSDEF_DEPEND_H_
#define _MTKBSP_SYS_SYSDEF_DEPEND_H_

/* CPU-dependent definition */
#include <sys/sysdepend/lpc_xps/cpu/lpc59s69/sysdef.h>

/* ------------------------------------------------------------------------ */
/* Clock frequency
 */
#define ICLK_MHz	(150)

#define	SYSCLK		(ICLK_MHz*1000000)	// System clock (Hz)
#define TMCLK_KHz	(ICLK_MHz*1000)		// System timer clock input (kHz)
#define TMCLK		(ICLK_MHz)		// System timer clock input (MHz)

#endif /* _MTKBSP_TK_SYSDEF_DEPEND_H_ */
