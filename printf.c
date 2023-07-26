#include "main.h"

/**
 * _printf - checks anything
 * @format: jyyyyyyyyyyyyyyrg
 *
 * Return: print nbr 
 */
int _printf(const char *format, ...)
{
	int sm = 0;
	va_list ap;
	char *z, *start;
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
<<<<<<< HEAD
		start = x;
		x++;
		while (get_flag(x, &params)) /* while characters is precision */
		{
			x++; /* char after */
=======
		start = z;
		z++;
		while (get_flag(z, &params)) /* while char at p is flag char */
		{
			z++; /* next char */
>>>>>>> e019d0d2a88eaf799fb53a59ac72dedc12a3c08d
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
