#include "io_led.h"
#include "light.h"
#include <stdio.h>

int io_led_on(struct io_led *self);
int io_led_off(struct io_led *self);
int io_led_get_state(struct io_led *self, int *state);

struct light_i io_led_interface = {
        .on = (light_on_fn_t)io_led_on,
        .off = (light_off_fn_t)io_led_off,
        .get_state = (light_get_state_fn_t)io_led_get_state,
};

int io_led_on(struct io_led *self)
{
        ///...
        printf("io_led is on\n");
        self->state = 1;

        return 0;
}

int io_led_off(struct io_led *self)
{
        ///...
        printf("io_led is off\n");
        self->state = 0;

        return 0;
}

int io_led_get_state(struct io_led *self, int *state)
{
        *state = self->state;
        return 0;
}

int io_led_init(struct io_led *self)
{
        self->interface = &io_led_interface;
        self->state = 0;
        return 0;
}
