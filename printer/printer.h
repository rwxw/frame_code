#ifndef __PRINTER_H__
#define __PRINTER_H__

typedef void (*printer_print_fn)(void *printer, const char *str);

struct printer_i  {
    printer_print_fn print;
};

#endif