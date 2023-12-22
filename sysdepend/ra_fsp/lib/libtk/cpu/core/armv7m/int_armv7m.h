﻿/*
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

#ifndef _MTKBSP_LIBTK_INT_ARMV7M_H_
#define _MTKBSP_LIBTK_INT_ARMV7M_H_

/*
 *	int_armv7m.h
 *
 *	Interrupt controller (ARMv7-M)
 */

/*----------------------------------------------------------------------*/
/*
 * Interrupt controller (NVIC) Control
 */

/*
 * Enable interrupt for NVIC
 */
EXPORT void EnableInt_nvic( UINT intno, INT level );

/*
 * Disable interrupt for NVIC
 */
Inline void DisableInt_nvic( UINT intno )
{
	*(_UW*)(NVIC_ICER(intno)) = (0x01U << (intno % 32));
}

/*
 * Clear interrupt for NVIC
 */
Inline void ClearInt_nvic( UINT intno )
{
	*(_UW*)(NVIC_ICPR(intno)) = (0x01U << (intno % 32));
}

/*
 * Check active state for NVIC
 */
Inline BOOL CheckInt_nvic( UINT intno )
{
	return (*(_UW*)(NVIC_ICPR(intno)) & (0x01U << (intno % 32)));
}

#endif /* _MTKBSP_LIBTK_INT_ARMV7M_H_ */
