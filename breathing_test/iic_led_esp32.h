#ifndef __IIC_LED_ESP32_H
#define __IIC_LED_ESP32_H

#include "iic_led.h"

struct iic_led_esp32 {
        struct iic_led_i *interface;
        char address;
};

int iic_led_esp32_init(struct iic_led_esp32 *self);

#endif
