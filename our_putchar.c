#include "main.h"
/**
 * our_putchar - print a character
 * @c: char input
 * Return: 1
 */

int our_putchar(char c)
{
	return (write(1, &c, 1));
}
