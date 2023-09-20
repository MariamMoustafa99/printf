#include "main.h"

/**
 * print_char - prints char
 * @ap: pointer
 * @params: parameters struct
 * Return: number of characters
 */

int print_char(va_list ap, params_t *params)
{
	char padding_char = ' ';
	unsigned int padding = 1, s = 0, c = va_arg(ap, int);

	if (params->minus_flag)
		s += _putchar(c);
	while (padding++ < params->width)
		s += _putchar(padding_char);
	if (!params->minus_flag)
		s += _putchar(c);
	return (s);
}

/**
 * print_int - prints int
 * @ap: pointer
 * @params: parameters struct
 * Return: number of characters
 */

int print_int(va_list ap, params_t *params)
{
	long i;

	if (params->l_modifier)
		i = va_arg(ap, long);
	else if (!params->h_modifier)
		i = (short int)va_arg(ap, int);
	else
		i = (int)va_arg(ap, int);
	return (print_number(convert(i, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @ap: pointer
 * @params: parameters struct
 * Return: number of characters
 */

int print_string(va_list ap, params_t *params)
{
	char *c = va_arg(ap, char *), padding_char = ' ';
	unsigned int padding = 0, s = 0, j = 0, x;

	(void)params;
	switch ((int)(!c))
		case 1:
			c = NULL_STRING;

	x = padding = _strlen(c);
	if (params->precision < padding)
		x = padding = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (j = 0; j < padding; j++)
				s += _putchar(*c++);
		else
			s += _puts(c);
	}
	while (x++ < params->width)
		s += _putchar(padding_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (j = 0; j < padding; j++)
				s += _putchar(*c++);
		else
			s += _puts(c);
	}
	return (s);
}

/**
 * print_percent - prints percent
 * @ap: pointer
 * @params: parameters struct
 * Return: number of characters
 */

int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - prints custom specifier
 * @ap: pointer
 * @params: parameters struct
 * Return: number of characters
 */

int print_S(va_list ap, params_t *params)
{
	char *c = va_arg(ap, char *);
	char *hex;
	int s = 0;

	if ((int)(!c))
		return (_puts(NULL_STRING));
	for (; *c; c++)
	{
		if ((*c > 0 && *c < 32) || *c >= 127)
		{
			s += _putchar('\\');
			s += _putchar('x');
			hex = convert(*c, 16, 0, params);
			if (!hex[1])
				s += _puts(hex);
		}
		else
			s += _putchar(*c);
	}
	return (s);
}
