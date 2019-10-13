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

#ifndef __lpc2148_i2c__REGACC__H__

#define __lpc2148_i2c__REGACC__H__


#define BASE_ADDRESS pdata->base_addr

/* Register offset macros */
#define LPC2148_I2C_I2CDAT (BASE_ADDRESS + 0x8)
#define LPC2148_I2C_I2CSCLLOW (BASE_ADDRESS + 0x14)
#define LPC2148_I2C_I2CSCLHIGH (BASE_ADDRESS + 0x10)
#define LPC2148_I2C_CONCLR (BASE_ADDRESS + 0x18)
#define LPC2148_I2C_CONSET (BASE_ADDRESS + 0)


/* Register field MASK macros */
#define LPC2148_I2C_CONSET_I2C_ENA_MASK 0x40
#define LPC2148_I2C_CONSET_I2C_STA_MASK 0x20
#define LPC2148_I2C_CONSET_I2C_STO_MASK 0x10
#define LPC2148_I2C_CONSET_I2C_SI_MASK 0x8
#define LPC2148_I2C_CONSET_I2C_AA_MASK 0x4


/* Register field LPOS macros */
#define LPC2148_I2C_CONCLR_I2C_STAC_LPOS 5
#define LPC2148_I2C_CONCLR_I2C_SIC_LPOS 3
#define LPC2148_I2C_CONCLR_I2C_AAC_LPOS 2
#define LPC2148_I2C_CONSET_I2C_ENA_LPOS 6
#define LPC2148_I2C_CONSET_I2C_STA_LPOS 5
#define LPC2148_I2C_CONSET_I2C_STO_LPOS 4
#define LPC2148_I2C_CONSET_I2C_SI_LPOS 3
#define LPC2148_I2C_CONSET_I2C_AA_LPOS 2

#define REGR8(reg) read8((const volatile void *)reg, pdata->context)

#define REGW8(reg, value) write8(value, (volatile void *)reg, pdata->context)

#define REGR16(reg) read16((const volatile void *)reg, pdata->context)

#define REGW16(reg, value) write16(value, (volatile void *)reg, pdata->context)

#define REGR8_FIELD(offset, field) ((REGR8(offset) &\
	(offset##_##field##_MASK)) >> (offset##_##field##_LPOS))

#define REGW8_FIELD(offset, field, value)\
	(REGW8(offset, ((REGR8(offset) &\
	(~(offset##_##field##_MASK))) |\
	((value) << (offset##_##field##_LPOS)))))


#define GET_VALUE(data, lbit, hbit) ((data >> lbit) & (~(~0 << (hbit - lbit+1))))

#endif
