#include "main.h"

/**
 * _printf - Prints formatted output according to a format string.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	int ch_print = 0;

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			ch_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			int i;

			int found = 0;

			for (i = 0; f_list[i].specifier != NULL; i++)
			{
				if (*format == *(f_list[i].specifier))
				{
					ch_print += f_list[i].printer(args);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				_putchar('%');
				_putchar(*format);
				ch_print += 2;
			}
		}
		format++;
	}
	va_end(args);
	return (ch_print);
}
