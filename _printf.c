#include "main.h"

/**
* no_of_digits - counts the number of digits in the number passed to it
*
* @num: number to be checked
*
* Return: (Always/Success)
*/

int no_of_digits(int num)
{
if (num == 0)
{
return (0);
}

return (1 + no_of_digits(num / 10));
}

/**
* print_c - Prints chars
*
* @arg: argument
*
* Return: (Always/Success)
*/

int print_c(va_list arg)
{
char c = va_arg(arg, int);
write(1, &c, sizeof(char));
return (1);
}

/**
* print_i - Prints int
*
* @arg: argument
*
* Return: (Always/Success)
*/

int print_i(va_list arg)
{
int d = va_arg(arg, int);
write(1, &d, sizeof(int));

return (no_of_digits(d));
}

/**
* print_s - Prints strings
*
* @arg: argument
*
* Return: (Always/Success)
*/

int print_s(va_list arg)
{
int i;
char *s = va_arg(arg, char*);
for (i = 0; s[i] != '\0'; i++)
{
write(1, &s[i], sizeof(char));
}
return (i);
}


/**
* _printf - Entry point
*
* @format: type of argument+
*
* Return: (Always/Success)
*/

int _printf(const char *format, ...)
{
va_list args;
int j, k = 0, i = 0;
type format_type[] = {
{'c', print_c},
{'i', print_i},
{'d', print_i},
{'s', print_s},
{NULL, NULL}
};
va_start(args, format);
while (format && format[i])
{
j = 0;
if (format[i] == '%')
{
if (format[i + 1] == '%')
{
i++;
continue;
}
while (j < 4)
{
if (format[i + 1] == format_type[j].type_name)
{
k += format_type[j].print_func(args);
i++;
i++;
break;
}
j++;
}
}
write(1, &format[i], sizeof(char));
i++;
k++;
}
va_end(args);
return (k);
}
