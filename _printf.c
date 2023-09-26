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
	unsigned int i, stringcount, count = 0;

	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{

		if (format[i] != '%')
		{
			our_putchar(format[i]);

		}
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			our_putchar(va_arg(args, int));
			i++;
		}

		if (format[i] == '%' && format[i + 1] == 's')
		{
			stringcount = my_puts(va_arg(args, char *));
			i++;
			count += (stringcount - 1);
		}

		if (format[i] == '%' && format[i + 1] == '%')
		{
			our_putchar('%');
		}

		count++;
	}

	va_end(args);

	return (count);
}
