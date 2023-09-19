#include "main.h"

/**
 * get_specifier - gets specifier from format function
 * @s: string
 * Return: number of bytes
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"C", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*S == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - gets format function
 * @s: string
 * @ap: pointer
 * @params: paramters struct
 * Return: number of bytes
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (F)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - gets flag function
 * @s: string
 * @params: parameters struct
 * Return: flag if valid
 */

int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - gets modifier function
 * @s: string
 * @params: parameters struct
 * Return: modifier if valid
 */

int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets width from format string
 * @s: string
 * @params: parameters struct
 * @ap: pointer
 * Return: new pointer
 */

char *get_width(char *s, params_t *params, va_list ap)
{
	int g = 0;

	if (*s == '*')
	{
		g = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			g = g * 10 + (*s++ - '0');
	}
	params->width = g;
	return (s);
}
