#include "main.h"

/**
 * print_char - prints a chars number
 * @ap: get a argument pointer
 * @params: calculates the parameters
 *
 * Return: number chars printed
 */
int print_char(va_list ap, params_t *params)
{
	char padchar = ' ';
	unsigned int pd = 1, sm = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sm += _putchar(ch);
	while (pd++ < params->width)
		sm += _putchar(padchar);
	if (!params->minus_flag)
		sm += _putchar(ch);
	return (sm);
}

/**
 * print_int - prints a integer number
 * @ap: get the argument pointer
 * @params: calculates the parameters
 *
 * Return: number chars printed
 */
int print_int(va_list ap, params_t *params)
{
	long g;

	if (params->g_modifier)
		g = va_arg(ap, long);
	else if (params->h_modifier)
		g = (short int)va_arg(ap, int);
	else
		g = (int)va_arg(ap, int);
	return (print_number(convert(g, 10, 0, params), params));
}

/**
 * print_string - prints a unsigned numb
 * @ap: get the argument pointer
 * @params: calculates the parameters
 *
 * Return: number chars printed
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
				sum += _putchar(*str++);
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
 * print_percent - prints a string number
 * @ap: get the argument pointer
 * @params: calculates the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - prints a size specifier
 * @ap: get the argument pointer
 * @params: calculates the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list ap, params_t *params)
{
	char *st = va_arg(ap, char *);
	char *hx;
	int sm = 0;

	if ((int)(!st))
		return (_puts(NULL_STRING));
	for (; *st; st++)
	{
		if ((*st > 0 && *st < 32) || *st >= 127)
		{
			sm += _putchar('\\');
			sm += _putchar('x');
			hx = convert(*st, 16, 0, params);
			if (!hx[1])
				sm += _putchar('0');
			sm += _puts(hx);
		}
		else
		{
			sm += _putchar(*st);
		}
	}
	return (sm);
}
