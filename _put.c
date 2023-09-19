#include "main.h"

/**
 * _puts - prints string with newline
 * @str: string
 * Return: void
 */

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - print char c
 * @c: character
 * Return: 1 (success)
 */

int _putchar(int c)
{
	static int i;
	static char buf(OUTPUT_BUF_SIZE);

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
