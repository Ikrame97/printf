#include "main.h"

/**
 * convert - èiyjoiopyhjpotkôkj
 * @num: nbr
 * @base: bbgju
 * @flags: jèkjpokytjk
 * @params: uyrfuhyhtgrf
 *
 * Return: the str
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long x = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		x = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[x % base];
		x /= base;
	} while (x != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - hkgthogkhhhhhhhhhhkgn
 * @ap: ajhugkfhyyyyyyyyyyyy
 * @param: ujmùjuytg
 *
 * Return: bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * print_address - uyujuntyujtd
 * @ap: klnhjoln
 * @params: htpoktjthe parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int x = va_arg(ap, unsigned long int);
	char *str;

	if (!x)
		return (_puts("(nil)"));

	str = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
