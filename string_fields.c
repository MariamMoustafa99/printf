#include "main.h"

/**
 * get_precision - gets precision from format
 * @p: string
 * @params: parameters struct
 * @ap: pointer
 * Return: pointer
 */

char *get_precision(char *p, params_t *params, va_list ap)
{
	int f = 0;

	if (*p != '.')
		return (p);
	p++;

	if (*p == '*')
	{
		f = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			f = f * 10 + (*p++ - '0');
	}
	params->precision = f;
	return (p);
}
