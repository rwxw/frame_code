#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

enum key_state_machine_state {
        KEY_STATE_MACHINE_KEY_NORMAL = 1,
        KEY_STATE_MACHINE_KEY_PRESSED,
};

struct key_time_i;
struct key_i;

typedef size_t (*key_time_get_time_fn_t)(struct key_time_i **self);
typedef int (*key_is_pressed_fn_t)(struct key_i **self);

struct key_time_i {
        key_time_get_time_fn_t get_time;
};

struct key_i {
        key_is_pressed_fn_t is_pressed;
};

struct my_key_time {
        struct key_time_i *interface;
};

struct my_key {
        struct key_i *interface;
};

size_t my_key_time_get_time(struct my_key_time **self)
{
        static size_t fake_time  = 1024;
        return fake_time +=10;
}

struct key_time_i my_key_time_interface = {
        .get_time = (key_time_get_time_fn_t)my_key_time_get_time,
};

int my_key_time_init(struct my_key_time *self)
{
        printf("\tmy key time has successfully initted.\n");
        self->interface = &my_key_time_interface;
        return 0;
}

static inline size_t key_time_get_time(struct key_time_i **self)
{
        return (*self)->get_time(self);
}

static inline int key_is_pressed(struct key_i **self)
{
        return (*self)->is_pressed(self);
}

int my_key_time_is_pressed(struct my_key *self)
{
        static int count = 0;
        if (count++ < 10) {
                return 0;
        } else if (count++ < 20) {
                return 1;
        } else {
                count = 0;
                return 0;
        }
} 

struct key_i my_key_interface = {
        .is_pressed = (key_is_pressed_fn_t)my_key_time_is_pressed,
};

int my_key_init(struct my_key *self)
{
        printf("\tmy key has successfully initted.\n");
        self->interface = &my_key_interface;
        return 0;
}

typedef int (*key_state_machine_on_event_fn_t)(int key, size_t pressed_time);

struct key_state_machine {
        enum key_state_machine_state state;
        struct key_time_i **key_time;
        struct key_i **key;
        size_t pressed_time;
        key_state_machine_on_event_fn_t on_event;
};

int key_state_machine_pressed(struct key_state_machine *self)
{
        size_t current_time;
        
        if (!key_is_pressed(self->key)) {
                self->state = KEY_STATE_MACHINE_KEY_NORMAL;
                current_time = key_time_get_time(self->key_time);
                return self->on_event(0, current_time - self->pressed_time);
        }
        return 0;
}

int key_state_machine_normal(struct key_state_machine *self)
{
        /// TODO：按键防抖

        if (key_is_pressed(self->key)) {
                self->state = KEY_STATE_MACHINE_KEY_PRESSED;
                self->pressed_time = key_time_get_time(self->key_time);    // 这里的pressed_time是指在哪一刻按下的时间 
        }
        return 0;
}

int key_state_machine_step(struct key_state_machine *self)
{
        printf("\t>>> current state: %d (pressed time: %lu)\n", self->state, self->pressed_time);
        switch (self->state) {
        case KEY_STATE_MACHINE_KEY_NORMAL:
                return key_state_machine_normal(self);
        case KEY_STATE_MACHINE_KEY_PRESSED:
                return key_state_machine_pressed(self);
        }
} 


int key_state_machine_init(struct key_state_machine *self, 
                           struct key_i **key,
                           struct key_time_i **key_time,
                           key_state_machine_on_event_fn_t on_event)
{
        self->state = KEY_STATE_MACHINE_KEY_NORMAL;
        self->pressed_time = 0;
        self->key = key;
        self->key_time = key_time;
        self->on_event = on_event;
        return 0;
}

int my_on_event(int key, size_t time_pressed)
{
        printf("key %d has been pressed for %d mircoseconds\n", key, time_pressed);
        return 0;
}

int main(void)
{
        struct key_state_machine fsm;
        struct my_key_time key_time;
        struct my_key key;
        int i;

        if (my_key_time_init(&key_time)) {
                return 1;
        }

        if (my_key_init(&key)) {
                return 1;
        }

        if (key_state_machine_init(&fsm, (struct key_i **)&key, (struct key_time_i **)&key_time, my_on_event)) {
                return 1;
        }

        for (i = 0; i < 100; i++) {
                if (key_state_machine_step(&fsm)) {
                        printf("this loop was executed for %d times.\n", i);
                        return 1;
                }
        }

        return 0;
}