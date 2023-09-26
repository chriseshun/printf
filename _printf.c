#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints to standard output text
 *
 * @format: format specifier
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
unsigned int i, count = 0;
va_list args;
if (!format)
return (-1);
va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
our_putchar(format[i]);
}
else
{
i++;
if (format[i] == 'c')
{
our_putchar(va_arg(args, int));
}
else if (format[i] == 's')
{
char *str = va_arg(args, char *);
if (str)
{
int stringcount = my_puts(str);
count += (stringcount - 1);
}
}
else if (format[i] == '%')
{
our_putchar('%');
}
else
{
our_putchar('%');
our_putchar(format[i]);
}
}
count++;
}
va_end(args);
return (count);
}
