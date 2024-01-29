/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.0 BSP 2.0
 *
 *    Copyright (C) 2023-2024 by Ken Sakamura.
 *    This software is distributed under the T-License 2.1.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2024/02.
 *
 *----------------------------------------------------------------------
 */

/*
 *	i3c_cnf.h 
 *	I3C device driver (RA FSP)
 *		Device configuration file
 */
#ifndef	_DEV_HAL_I3C_CNF_H_
#define	_DEV_HAL_I3C_CNF_H_

#define DEVNAME_HAL_I3C		"hlitc"
#define DEV_HAL_I3C_TMOUT	(500)

#define DEV_HAL_I3C_UNITNM	(3)	// Number of I3C units (max 26)

#endif	/* _DEV_HAL_I3C_CNF_H_ */
