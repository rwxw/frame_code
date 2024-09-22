#ifndef __io_led_H__
#define __io_led_H__

#include "light.h"

struct io_led_i {
        int (*io_set)(void *self, char io_level);
};

static inline int io_led_set(void *self, char io_level)
{
        return (*(struct io_led_i **)self)->io_set(self, io_level);
}

struct io_led {
        struct light_i *interface;
        struct io_led_i **io_dev;
        char state;
};

int io_led_init(struct io_led *self);

#endif

