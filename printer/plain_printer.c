#include "printer.h"
#include <stdlib.h>
/* 继承于printer父类，plain_printer是一个子类 */
struct plain_printer {
    const struct printer_i *interface;
    const char *preifx;
};

void plain_printer_print(struct plain_printer *self, const char *str);

static const struct printer_i printer_interface = {
    .print = (printer_print_fn)plain_printer_print;
};

/* plain_printer对象初始化函数 */
struct plain_printer *plain_printer_new(const char *prefix) {
    struct plain_printer *self;
    self = malloc(sizeof(struct plain_printer));
    assert(slef != NULL);

    self->interface = &printer_interface;
    self->preifx = prefix;

    return self;
}

void plain_printer_cleanup(struct plain_printer *self, const char *prefix) {
    free(self);
}

void plain_printer_print(struct plain_printer *self, const char *str) {
     printf("%s%s". self->prefix, str);
}
