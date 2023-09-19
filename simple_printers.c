#include "main.h"

/**
 * print_from_to - prints from start char to end
 * @start: address to start at
 * @stop: address to stop at
 * @except: except address
 * Return: number of bytes
 */

int print_from_to(char *start, char *stop, char *except)
{
	int s = 0;

	while (start <= stop)
	{
		if (start != except)
			s += _putchar(*start);
		start++;
	}
	return (s);
}

/**
 * print_rev - prints string reversly
 * @ap: pointer
 * @params: parameters struct
 * Return: number of bytes
 */

int print_rev(va_list ap, params_t *params)
{
	int length, s = 0;
	char *str = va_arg(ap, char *);
	(void) params;

	if (str)
	{
		for (length = 0; *str; str++)
			length++;
		str--;

		for (; length > 0; length--, str--)
			s += _putchar(*str);
	}
	return (s);
}

/**
 * print_rot13 - prints rot13 format
 * @ap: pointer
 * @params: parameters struct
 * Return: number of bytes
 */

int print_rot13(va_list ap, params_t *params)
{
	int j, i;
	int c = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM     nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	j = 0;
	i = 0;
	while (a[j])
	{
		if ((a[j] >= 'A' && a[j] <= 'Z') || (a[j] >= 'a' && a[j] <= 'z'))
		{
			i = a[j] - 65;
			c += _putchar(array[i]);
		}
		else
		{
			c += _putchar(a[j]);
		}
		i++;
	}
	return (c);
}
