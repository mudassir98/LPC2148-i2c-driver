/**********************************************************************
 *
 * Copyright (c) Vayavya Labs Pvt. Ltd.  2019
 *
 * THIS IS A DEVICE DRIVER GENERATED USING VAYAVYA LABS' DDGen TOOL.
 * THIS DRIVER WAS GENERATED FOR THE FOLLOWING SPECS:
 *
 * Device: lpc2148_i2c
 * Device Manufacturer: NXP_semiconductor
 * Operating System: None
 *
 * DPS Reference ID: 397163:715:784:1748
 * RTS Reference ID: 47572:14:4294967295:21
 *
 * THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND. TO
 * THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, VAYAVYA LABS Pvt Ltd.
 * DISCLAIMS ALL WARRANTIES, EXPRESSED OR IMPLIED, INCLUDING, BUT NOT
 * LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT, WITH REGARD
 * TO THE SOFTWARE.
 *
 * VAYAVYA LABS Pvt.Ltd. SHALL BE RELIEVED OF ANY AND ALL OBLIGATIONS
 * WITH RESPECT TO THIS SECTION FOR ANY PORTIONS OF THE SOFTWARE THAT
 * ARE REVISED, CHANGED, MODIFIED, OR MAINTAINED BY ANYONE OTHER THAN
 * VAYAVYA LABS Pvt.Ltd.
 *
 ***********************************************************************/

#ifndef __lpc2148_i2c__YHEADER__

#define __lpc2148_i2c__YHEADER__

/* Macro definitions*/

#define Y_TRUE 1
#define Y_FALSE 0
#define Y_SUCCESS 0
#define Y_FAILURE 1
#define Y_INV_WR 1
#define Y_INV_RD 2
#define Y_INV_ARG 3
#define Y_MAX_THRD_XEEDED 4
#ifndef _STDIO_H
#define NULL ((void *)0)
#define UINT_MAX (~0U)
#endif

/* TODO: Proto-type of the functions */
void *lpc2148_i2c_alloc_pdata(void);
static void *mem_alloc (unsigned int, int, unsigned int *, unsigned int);
static void mem_free (void *, int, int);

/* TODO: macros used in wrapper structure for allcoation */
#define DMA_ALLOC    0
#define NO_DMA_ALLOC 1

/* TODO: Error macros used when function returns error */
#define ENOMEM   12
#define EIO      13

/* Macros for descriptor align and buffer align*/
#define  NO_ALIGN 0





/* C data types typedefs */





struct lpc2148_i2c_prv_data {
	unsigned *cmd_complete; /* TODO: Variable to indicate  completion of operation, 
				Data type must be set according to interrupt spec */
	int stateval;
	char * buffer;
	unsigned length;
	char transfer_dir;
	unsigned int fifo_width;
        unsigned int mem_start_addr;
	unsigned int mem_size;
	unsigned int irq_number;
	unsigned char  *base_addr;
	  


	void *context;
};


struct lpc2148_i2c_device_apis {
	int (*i2c_stop)(struct lpc2148_i2c_prv_data *);
	int (*device_read)(unsigned int, unsigned char *, char, struct lpc2148_i2c_prv_data *);
	int (*device_write)(char, char, struct lpc2148_i2c_prv_data *);
	int (*i2c_start)(struct lpc2148_i2c_prv_data *);
	int (*i2c_config)(unsigned int, unsigned int, struct lpc2148_i2c_prv_data *);
};



/* <<< 10 EXPFEAT */

/* <<< 40 INIFINI */


#endif
