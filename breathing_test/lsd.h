#ifndef __lsd_H__
#define __lsd_H__

#include "light.h"

struct lsd {
        struct light_i *interface;
        char state;
};

int lsd_init(struct lsd *self);

#endif

