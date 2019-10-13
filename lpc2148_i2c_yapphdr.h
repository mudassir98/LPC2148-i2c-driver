#ifndef __lpc2148_i2c__APPHDR__H__

#define __lpc2148_i2c__APPHDR__H__



/* General status and error macros */
#define Y_TRUE 1
#define Y_FALSE 0
#define Y_SUCCESS 0
#define Y_FAILURE 1
#define Y_INV_WR 1
#define Y_INV_RD 2
#define Y_INV_ARG 3
#define Y_MAX_THRD_XEEDED 4


struct lpc2148_i2c_prv_data;
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

int lpc2148_i2c_init(struct lpc2148_i2c_prv_data *, void *);



void *lpc2148_i2c_alloc_pdata(void);
void *lpc2148_i2c_free_pdata(struct lpc2148_i2c_prv_data *);
struct lpc2148_i2c_device_apis;
struct lpc2148_i2c_device_apis *lpc2148_i2c_device_open(void);
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
