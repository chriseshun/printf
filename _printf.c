#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	va_list arg_list;

	va_start(arg_list, format);

	int ch_print = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			int found = 0;

			format_entry format_list[] = {
				{"%c", print_char},
				{"%s", print_string},
				{"%%", print_percent},
				{"%d", print_integer},
				{"%i", print_integer},
				{"%b", print_binary},
				{"%u", unsigned_integer},
				{"%o", print_octal},
				{"%x", print_hexlower},
				{"%X", print_heXupper},
				{"%r", print_reverser},
				{"%R", rot13},
				{NULL, NULL}
			};

			for (int i = 0; format_list[i].format != NULL; i++)
			{
				if (strcmp(format, format_list[i].format) == 0)
				{
					ch_print += format_list[i].func(arg_list);
					found = 1;
					break;
				}
			}

			if (!found)
			{
				putchar('%');
				putchar(*format);
				ch_print += 2;
			}
		}
		else
		{
			putchar(*format);
			ch_print++;
		}
		format++;
	}

	va_end(arg_list);
	return (ch_print);
}
