#ifndef __IIC_LED_H__
#define __IIC_LED_H__

#include "light.h"

typedef int (*iic_led_read_fn_t)(void *self, char address, int *data);
typedef int (*iic_led_write_fn_t)(void *self, char address, int data);

struct iic_led_i {
        iic_led_read_fn_t read;
        iic_led_write_fn_t write;
};

static inline int iic_led_read(void *self, char address, int *data)
{
        return (*(struct iic_led_i **)self)->read(self, address, data);
}

static inline int iic_led_write(void *self, char address, int data)
{
        return (*(struct iic_led_i **)self)->write(self, address, data);
}

struct iic_led {
        struct light_i *interface;
        struct iic_led_i **iic_dev;
        char address;
};

int iic_led_init(struct iic_led *self, struct iic_led_i **iic_dev);

#endif

