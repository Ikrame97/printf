#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sm = 0;
	va_list ap;
	char *z, *strt;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (z = (char *)format; *z; z++)
	{
		init_params(&params, ap);
		if (*z != '%')
		{
			sm += _putchar(*z);
			continue;
		}
		strt = z;
		z++;
		while (get_flag(z, &params)) /* while char at p is flag char */
		{
			z++; /* next char */
		}
		z = get_width(z, &params, ap);
		z = get_precision(z, &params, ap);
		if (get_modifier(z, &params))
			z++;
		if (!get_specifier(z))
			sm += print_from_to(start, z,
				params.l_modifier || params.h_modifier ? z - 1 : 0);
		else
			sm += get_print_func(z, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sm);
}
