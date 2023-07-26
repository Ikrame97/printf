#include "main.h"

/**
 * get_precision - prints the precision string function
 * @p: the string function
 * @params: calculates the params struct
 * @ap: get the argument pointer
 *
 * Return: jgfj
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int i = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		i = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			i = i * 10 + (*p++ - '0');
	}
	params->precision = i;
	return (p);
}
