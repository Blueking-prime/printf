#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int no_of_digits(int num);

int _printf(const char *format, ...);

int print_c(va_list arg);
int print_i(va_list arg);
int print_s(va_list arg);

/**
* struct typ - structure definition of a typ
*
* @type_name: type
* @print_func: function to print
*/

typedef struct typ
{
char *type_name;
int (*print_func)(va_list);
}type;

#endif /* MAIN_H */
