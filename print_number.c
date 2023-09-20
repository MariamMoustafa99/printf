#include "main.h"

/**
 * _isdigit - check char if is digit
 * @c: char
 * Return: 1 if digit and 0 otherwise
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - return length
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
	int m = 0;

	while (*s++)
		m++;
	return (m);
}

/**
 * print_number - prints number
 * @str: string
 * @params: parameters struct
 * Return: char
 */

int print_number(char *str, params_t *params)
{
	unsigned int l = _strlen(str);
	int negative = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (negative)
	{
		str++;
		l--;
	}

	if (params->precision != UINT_MAX)
		while (l++ < params->precision)
			*--str = '0';
	if (negative)
		*--str = '-';
	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints number with options
 * @str: string
 * @params: paramters struct
 * Return: chars
 */

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int v = 0, negative, negative2, l = _strlen(str);
	char padding_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		padding_char = '0';
	negative = negative2 = (!params->unsign && *str == '-');
	if (negative && l < params->width && padding_char == '0' &&
			!params->minus_flag)
		str++;
	else
		negative = 0;
	if ((params->plus_flag && !negative2) ||
			(!params->plus_flag && params->space_flag && !negative2))
		l++;
	if (negative && padding_char == '0')
		v += _putchar('-');
	if (params->plus_flag && !negative2 && padding_char == '0' && !params->unsign)
		v += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !negative2 &&
			!params->unsign && params->zero_flag)
		v += _putchar(' ');
	while (l++ < params->width)
		v += _putchar(padding_char);
	if (negative && padding_char == ' ')
		v += _putchar('-');
	if (params->plus_flag && !negative2 && padding_char == ' ' && !params->unsign)
		v += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !negative2 &&
			!params->unsign && !params->zero_flag)
		v += _putchar(' ');
	v += _puts(str);
	return (v);
}


/**
 * print_number_left_shift - prints number with options
 * @str: string
 * @params: paramters struct
 * Return: chars
 */

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int v = 0, negative, negative2, l = _strlen(str);
	char padding_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		padding_char = '0';
	negative = negative2 = (!params->unsign && *str == '-');
	if (negative && l < params->width && padding_char == '0' &&
			!params->minus_flag)
		str++;
	else
		negative = 0;
	if (params->plus_flag && !negative2 && !params->unsign)
		v += _putchar('+'), l++;
	else if (params->space_flag && !negative2 && !params->unsign)
		v += _putchar(' '), l++;
	v += _puts(str);
	while (l++ < params->width)
		v += _putchar(padding_char);
	return (v);
}
