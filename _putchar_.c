#include "main.h"

/**
 * _putchar_ - writes a single character to stdout
 * @c: The character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar_(char c)
{
    return (write(1, &c, 1));
}
