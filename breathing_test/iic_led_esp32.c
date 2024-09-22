#include "iic_led_esp32.h"
#include <stdio.h>

int iic_led_esp32_read(struct iic_led_esp32 *self, char address, int *data);
int iic_led_esp32_write(struct iic_led_esp32 *self, char address, int data);

struct iic_led_i iic_led_esp32_interface = {
        .write = (iic_led_write_fn_t)iic_led_esp32_write,
        .read = (iic_led_read_fn_t)iic_led_esp32_read,
};

int iic_led_esp32_init(struct iic_led_esp32 *self)
{
        printf("Initializing IIC 1 device of ESP32\n");
        self->interface = &iic_led_esp32_interface;
        return 0;
}


int iic_led_esp32_read(struct iic_led_esp32 *self, char address, int *data)
{
        *data = 0xFF;
        printf("ESP32 IIC 1 reading byte\n");
        return 0;
}

int iic_led_esp32_write(struct iic_led_esp32 *self, char address, int data)
{
        printf("ESP32 IIC 1 writing byte %x\n", data);
        return 0;
}