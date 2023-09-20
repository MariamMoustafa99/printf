#include "main.h"

/**
 * convert - convert from integre to string
 * @num: number given
 * @base: base
 * @flags: flags
 * @params: parameter struct
 * Return: string
 */

char *convert(long int num, int base, int flags, params_t *params)
{
	static char *arr;
	static char buff[50];
	char sign = 0;
	char *ptr;
	unsigned long x = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		x = -num;
		sign = '-';
	}

	arr = flags & CONVERT_UNSIGNED ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do {
		*--ptr = arr[x % base];
		x /= base;
	} while (x != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned int
 * @ap: pointer
 * @params: parameters struct
 * Return: number of bytes
 */

int print_unsigned(va_list ap, params_t *params)
{
	unsigned long m;

	if (params->l_modifier)
		m = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		m = (unsigned short int)va_arg(ap, unsigned int);
	else
		m = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(m, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints the address
 * @ap: pointer
 * @params: parameters struct
 * Return: number of bytes
 */

int print_address(va_list ap, params_t *params)
{
	unsigned long int x = va_arg(ap, unsigned long int);
	char *s;

	if (!x)
		return (_puts("nill"));

	s = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, params));
}
