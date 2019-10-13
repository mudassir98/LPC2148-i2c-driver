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

/*!@file lpc2148_i2c_drv.c
 * @brief Driver functions.
 */

#include "lpc2148_i2c_yheader.h"
#include "lpc2148_i2c_yregacc.h"
#include "env.h"

int lpc2148_i2c_gstatus;



/*!
 * \brief Configures the I2C
* \param[in] master_freq
* \param[in] pclk
 * \return Success or Failure
 * \retval  0 Success
 * \retval -1 Failure
 */

static int i2c_config(unsigned int master_freq,
			unsigned int pclk,
			struct lpc2148_i2c_prv_data *pdata)
{
	int x;

	REGW8(LPC2148_I2C_CONCLR, (1 << LPC2148_I2C_CONCLR_I2C_AAC_LPOS));
	REGW8(LPC2148_I2C_CONCLR, (1 << LPC2148_I2C_CONCLR_I2C_SIC_LPOS));
	REGW8(LPC2148_I2C_CONCLR, (1 << LPC2148_I2C_CONCLR_I2C_STAC_LPOS));
	REGW8_FIELD(LPC2148_I2C_CONSET, I2C_ENA, 1);
	x = (int) (pclk / (2 * master_freq));
	REGW16(LPC2148_I2C_I2CSCLHIGH, x);
	REGW16(LPC2148_I2C_I2CSCLLOW, x);

	return Y_SUCCESS;
}




/*!
 * \brief  start the I2C interface
 * \return Success or Failure
 * \retval  0 Success
 * \retval -1 Failure
 */

static int i2c_start(struct lpc2148_i2c_prv_data *pdata)
{

	REGW8_FIELD(LPC2148_I2C_CONSET, I2C_STA, 1);

	/* Poll */
	while (1) {
		if (REGR8_FIELD(LPC2148_I2C_CONSET, I2C_SI) == 1)
			break;
	}
	REGW8(LPC2148_I2C_CONCLR, (1 << LPC2148_I2C_CONCLR_I2C_STAC_LPOS));

	return Y_SUCCESS;
}




/*!
 * \brief transmits the data 
* \param[in] data
* \param[in] slave_addr
 * \return Success or Failure
 * \retval  0 Success
 * \retval -1 Failure
 */

static int device_write(char data,
				char slave_addr,
				struct lpc2148_i2c_prv_data *pdata)
{

	REGW8(LPC2148_I2C_I2CDAT, (slave_addr << 1));
	REGW8(LPC2148_I2C_CONCLR, (1 << LPC2148_I2C_CONCLR_I2C_SIC_LPOS));

	/* Poll */
	while (1) {
		if (REGR8_FIELD(LPC2148_I2C_CONSET, I2C_SI) == 1)
			break;
	}
	REGW8(LPC2148_I2C_I2CDAT, data);
	REGW8(LPC2148_I2C_CONCLR, (1 << LPC2148_I2C_CONCLR_I2C_SIC_LPOS));
	/* Poll */
	while (1) {
		if (REGR8_FIELD(LPC2148_I2C_CONSET, I2C_SI) == 1)
			break;
	}

	return Y_SUCCESS;
}




/*!
 * \brief  receives  data 
* \param[in] islast
* \param[out] data_r
* \param[in] slave_addr
 * \return Success or Failure
 * \retval  0 Success
 * \retval -1 Failure
 */

static int device_read(unsigned int islast,
				unsigned char *data_r,
				char slave_addr,
				struct lpc2148_i2c_prv_data *pdata)
{

	REGW8(LPC2148_I2C_I2CDAT, slave_addr);
	REGW8(LPC2148_I2C_I2CDAT, (REGR8(LPC2148_I2C_I2CDAT) << 1));
	REGW8(LPC2148_I2C_I2CDAT, (REGR8(LPC2148_I2C_I2CDAT) | 1));
	REGW8(LPC2148_I2C_CONCLR, (1 << LPC2148_I2C_CONCLR_I2C_SIC_LPOS));

	/* Poll */
	while (1) {
		if (REGR8_FIELD(LPC2148_I2C_CONSET, I2C_SI) == 1)
			break;
	}
	if (islast == 1)
		REGW8(LPC2148_I2C_CONCLR, (1 << LPC2148_I2C_CONCLR_I2C_AAC_LPOS));
	else
		REGW8_FIELD(LPC2148_I2C_CONSET, I2C_AA, 1);


	/* Poll */
	while (1) {
		if (REGR8_FIELD(LPC2148_I2C_CONSET, I2C_SI) == 1)
			break;
	}
	REGW8(LPC2148_I2C_CONCLR, (1 << LPC2148_I2C_CONCLR_I2C_SIC_LPOS));
	REGW8(LPC2148_I2C_CONCLR, (1 << LPC2148_I2C_CONCLR_I2C_AAC_LPOS));
	*data_r = REGR8(LPC2148_I2C_I2CDAT);

	return Y_SUCCESS;
}




/*!
 * \brief Stops the transmission 
 * \return Success or Failure
 * \retval  0 Success
 * \retval -1 Failure
 */

static int i2c_stop(struct lpc2148_i2c_prv_data *pdata)
{

	REGW8_FIELD(LPC2148_I2C_CONSET, I2C_STO, 1);

	return Y_SUCCESS;
}




static struct lpc2148_i2c_device_apis lpc2148_i2c_drv_apis = {
	.i2c_stop = i2c_stop,
	.device_read = device_read,
	.device_write = device_write,
	.i2c_start = i2c_start,
	.i2c_config = i2c_config
};




/*!
* \brief Initialization routine
* \details init routine of the driver that handles device initialization,
 	  and driver variables required for the driver to operate.
*
* \param[in] None
* \return Returns successful execution of the routine
* \retval Y_SUCCESS Function executed successfully
*/


int lpc2148_i2c_init(struct lpc2148_i2c_prv_data *pdata,void *context)
{
	pdata->base_addr = (void *)0xe001c000;
	pdata->context = context;


	return Y_SUCCESS ;
}

void *lpc2148_i2c_alloc_pdata()
{
  void *ret = NULL;

  ret = mem_alloc(sizeof (struct lpc2148_i2c_prv_data), NO_DMA_ALLOC, NULL, NO_ALIGN);
	return ret;
}

void lpc2148_i2c_free_pdata(struct lpc2148_i2c_prv_data *pdata)
{
   mem_free(pdata, NO_DMA_ALLOC, 0);
}

struct lpc2148_i2c_device_apis *lpc2148_i2c_device_open()
{
	return &lpc2148_i2c_drv_apis;
}



