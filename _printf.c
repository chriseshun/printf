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

    va_list args;
    va_start(args, format);

    int ch_print = 0;
    int i;
    int found = 0;

    specifier_t f_list[] = {
        {"c", print_char},
        {"s", print_string},
        {"%", print_percent},
        {"d", print_integer},
        {"i", print_integer},
        {"b", print_binary},
        {"u", unsigned_integer},
        {"o", print_octal},
        {"x", print_hexlower},
        {"X", print_heXupper},
        {"r", print_reverser},
        {"R", rot13},
        {NULL, NULL}
    };

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

            found = 0;

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
