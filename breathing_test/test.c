#include "light.h"
#include "lsd.h"
#include "iic_led.h"
#include "iic_led_esp32.h"
#include "io_led.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
        struct iic_led light0;
        struct io_led light1;
        struct lsd light2;

        struct iic_led_esp32 esp32_driver;
        int tmp;

        assert(!iic_led_esp32_init(&esp32_driver));

        assert(!iic_led_init(&light0, (struct iic_led_i **)&esp32_driver));
        assert(!io_led_init(&light1));
        assert(!lsd_init(&light2));
        


        assert(!light_get_state(&light0, &tmp));
        printf("state of light0:%d\n", tmp);

        // assert(!light_get_state(&light1, &tmp));
        // printf("state of light1:%d\n", tmp);

        // assert(!light_get_state(&light2, &tmp));
        // printf("state of light2:%d\n", tmp);

        light_on(&light0);
        // light_on(&light1);
        // light_on(&light2);

        light_off(&light0);

        assert(!light_get_state(&light0, &tmp));
        printf("state of light0:%d\n", tmp);

        // assert(!light_get_state(&light1, &tmp));
        // printf("state of light1:%d\n", tmp);
        
        // assert(!light_get_state(&light2, &tmp));
        // printf("state of light2:%d\n", tmp);

        return 0;
}
