#include "main.h"

/**
 * print_hex - prints hexadecimal numbers
 * @ap: pointer
 * @params: parameters struct
 * Return: number of bytes
 */

int print_hex(va_list ap, params_t *params)
{
	unsigned long i;
	int v = 0;
	char *s;

	if (params->l_modifier)
		i = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		i = (unsigned short int)va_arg(ap, unsigned int);
	else
		i = (unsigned int)va_arg(ap, unsigned int);

	s = convert(i, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && i)
	{
		*--s = 'x';
		*--s = '0';
	}
	params->unsign = 1;
	return (v += print_number(s, params));
}

/**
 * print_HEX - prints hexadecimal numbers
 * @ap: pointer
 * @params: parameters struct
 * Return: number of bytes
 */

int print_HEX(va_list ap, params_t *params)
{
	unsigned long i;
	int v = 0;
	char *s;

	if (params->l_modifier)
		i = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		i = (unsigned short int)va_arg(ap, unsigned int);
	else
		i = (unsigned int)va_arg(ap, unsigned int);

	s = convert(i, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && i)
	{
		*--s = 'X';
		*--s = '0';
	}
	params->unsign = 1;
	return (v += print_number(s, params));
}

/**
 * print_binary - prints binary numbers
 * @ap: pointer
 * @params: parameters struct
 * Return: number of bytes
 */

int print_binary(va_list ap, params_t *params)
{
	unsigned int v = va_arg(ap, unsigned int);
	char *m = convert(v, 2, CONVERT_UNSIGNED, params);
	int s = 0;

	if (params->hashtag_flag && v)
		*--m = '0';
	params->unsign = 1;
	return (s += print_number(m, params));
}

/**
 * print_octal - prints octal numbers
 * @ap: pointer
 * @params: parameters struct
 * Return: number of bytes
 */

int print_octal(va_list ap, params_t *params)
{
	unsigned int j;
	char *c;
	int s = 0;

	if (params->l_modifier)
		j = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		j = (unsigned short int)va_arg(ap, unsigned int);
	else
		j = (unsigned int)va_arg(ap, unsigned int);

	c = convert(j, 8, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && j)
	{
		*--c = '0';
	}
	params->unsign = 1;
	return (s += print_number(c, params));
}
