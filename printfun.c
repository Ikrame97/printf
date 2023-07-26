#include "main.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: print nbr
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pd = 1, sm = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sm += _putchar(ch);
	while (pd++ < params->width)
		sm += _putchar(pad_char);
	if (!params->minus_flag)
		sm += _putchar(ch);
	return (sm);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: priny nbr
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: print char
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pd = 0, sm = 0, y = 0, x;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	x = pd = _strlen(str);
	if (params->precision < pd)
		x = pd = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (y = 0; y < pd; y++)
				sm += _putchar(*str++);
		else
			sm += _puts(str);
	}
	while (x++ < params->width)
		sm += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (y = 0; y < pd; y++)
				sm += _putchar(*str++);
		else
			sm += _puts(str);
	}
	return (sm);
}

/**
 * print_percent - prints string
 * @ap: had argument pointer
 * @params: get the parameters struct
 *
 * Return: print char
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: had argument pointer
 * @params: get the parameters struct
 *
 * Return: print nbr
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hx;
	int sm = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sm += _putchar('\\');
			sm += _putchar('x');
			hx = convert(*str, 16, 0, params);
			if (!hx[1])
				sm += _putchar('0');
			sm += _puts(hx);
		}
		else
		{
			sm += _putchar(*str);
		}
	}
	return (sm);
}
