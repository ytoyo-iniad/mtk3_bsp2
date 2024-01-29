#include <tk/tkernel.h>
#include <tm/tmonitor.h>

LOCAL void task_1(INT stacd, void *exinf);	// task execution function
LOCAL ID	tskid_1;			// Task ID number
LOCAL T_CTSK ctsk_1 = {				// Task creation information
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_1,
	.tskatr		= TA_HLNG | TA_RNG3,
};

LOCAL void task_2(INT stacd, void *exinf);	// task execution function
LOCAL ID	tskid_2;			// Task ID number
LOCAL T_CTSK ctsk_2 = {				// Task creation information
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_2,
	.tskatr		= TA_HLNG | TA_RNG3,
};

LOCAL void task_3(INT stacd, void *exinf);	// task execution function
LOCAL ID	tskid_3;			// Task ID number
LOCAL T_CTSK ctsk_3 = {				// Task creation information
	.itskpri	= 10,
	.stksz		= 1024,
	.task		= task_3,
	.tskatr		= TA_HLNG | TA_RNG3,
};

LOCAL void task_1(INT stacd, void *exinf)
{
	UW	data[2];
	ID	dd;
	ER	err;

	tm_printf((UB*)"task 1\n");
	dd = tk_opn_dev((UB*)"hladca", TD_READ);

	while(1) {
		err = tk_srea_dev(dd, 0, &data[0], 1, NULL);
		tk_dly_tsk(100);
		tm_printf((UB*)"AN000 = %d  ", data[0]);

		err = tk_srea_dev(dd, 4, &data[1], 1, NULL);
		tk_dly_tsk(100);
		tm_printf((UB*)"AN004 = %d\n", data[1]);
		tk_dly_tsk(500);
	}
}

LOCAL void task_2(INT stacd, void *exinf)
{

	UW	tmp0, hum0;
	UB	cmd[] = {0x2C, 0x06};
	UB	rcv[6];
	ID	dd;
	ER	err;

	tm_printf((UB*)"task 2\n");
	dd = tk_opn_dev((UB*)"hliica", TD_UPDATE);

	while(1) {
		err = tk_swri_dev(dd, 0x45, cmd, 2, NULL);
		if(err != E_OK) tm_printf((UB*)"ERR-1\n");
		tk_dly_tsk(1);
		err = tk_srea_dev(dd, 0x45, rcv, 6, NULL);
		if(err != E_OK) tm_printf((UB*)"ERR-2\n");

		tmp0 = rcv[0]<<8 | rcv[1];
		hum0 = rcv[3]<<8 | rcv[4];

		tm_printf((UB*)"tmp = %d  hum = %d\n", tmp0, hum0);

		tmp0 = (tmp0*175)/65535 - 45;
		hum0 = (hum0*100)/65535;

		tm_printf((UB*)"tmp = %d  hum = %d\n\n", tmp0, hum0);

		tk_dly_tsk(1000);
	}
}

LOCAL void task_3(INT stacd, void *exinf)
{

	UW	tmp0, hum0;
	UB	cmd[] = {0x2C, 0x06};
	UB	rcv[6];
	ID	dd;
	ER	err;

	tm_printf((UB*)"task 3\n");
	dd = tk_opn_dev((UB*)"hlitca", TD_UPDATE);
	if(dd <= E_OK) tm_printf((UB*)"ERR-0  %d\n", dd);

	while(1) {
		err = tk_swri_dev(dd, 0x45, cmd, 2, NULL);
		if(err != E_OK) tm_printf((UB*)"ERR-1 %d\n", err);
		tk_dly_tsk(1);
		err = tk_srea_dev(dd, 0x45, rcv, 6, NULL);
		if(err != E_OK) tm_printf((UB*)"ERR-2 %d\n", err);

		tmp0 = rcv[0]<<8 | rcv[1];
		hum0 = rcv[3]<<8 | rcv[4];

		tm_printf((UB*)"tmp = %d  hum = %d\n", tmp0, hum0);

		tmp0 = (tmp0*175)/65535 - 45;
		hum0 = (hum0*100)/65535;

		tm_printf((UB*)"tmp = %d  hum = %d\n\n", tmp0, hum0);

		tk_dly_tsk(1000);
	}
}


/* usermain関数 */
EXPORT INT usermain(void)
{
	tm_putstring((UB*)"Start User-main program.\n");

	/* Create & Start Tasks */
	tskid_1 = tk_cre_tsk(&ctsk_1);
//	tk_sta_tsk(tskid_1, 0);

	tskid_2 = tk_cre_tsk(&ctsk_2);
//	tk_sta_tsk(tskid_2, 0);

	tskid_3 = tk_cre_tsk(&ctsk_3);
	tk_sta_tsk(tskid_3, 0);

	tk_slp_tsk(TMO_FEVR);

	return 0;
}
