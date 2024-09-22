#include "iic_led.h"
#include "light.h"
#include <stdio.h>

int iic_led_on(struct iic_led *self);
int iic_led_off(struct iic_led *self);
int iic_led_get_state(struct iic_led *self, int *state);

struct light_i iic_led_interface = {
        .on = (light_on_fn_t)iic_led_on,
        .off = (light_off_fn_t)iic_led_off,
        .get_state = (light_get_state_fn_t)iic_led_get_state,
};

int iic_led_on(struct iic_led *self)
{
        iic_led_write(self->iic_dev, self->address, 0xAA);
        iic_led_write(self->iic_dev, self->address, 0xBB);
        //...

        printf("iic_led is on\n");

        return 0;
}

int iic_led_off(struct iic_led *self)
{
        iic_led_write(self->iic_dev, self->address, 0xCC);
        iic_led_write(self->iic_dev, self->address, 0xDD);
        //...

        printf("iic_led is off\n");

        return 0;
}

int iic_led_get_state(struct iic_led *self, int *state)
{
        return iic_led_read(self->iic_dev, self->address, state);
}

int iic_led_init(struct iic_led *self, struct iic_led_i **iic_dev)
{
        self->interface = &iic_led_interface;
        self->iic_dev = iic_dev;
        /// initialize self->iic_dev
        return 0;
}
