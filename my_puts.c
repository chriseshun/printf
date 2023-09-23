#include "main.h"

/**
 * my_puts - print string
 *
 * @c: string
 * Return: number of bytes
 */

int my_puts(char *c)
{
	int count = 0;

	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			our_putchar(c[count]);
		}
	}
	return (count);
}
