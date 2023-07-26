#include "main.h"

/**
 * _isdigit - prints if the character isdigit
 * @c: the char to prints
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - check the string number
 * @s: the string whose to print and check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int z = 0;

	while (*s++)
		z++;
	return (z);
}

/**
 * print_number - checkers a string number
 * @str: the number string whose check
 * @params: calculates the params struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int in = _strlen(str);
	int ng = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (ng)
	{
		str++;
		in--;
	}
	if (params->precision != UINT_MAX)
		while (in++ < params->precision)
			*--str = '0';
	if (ng)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - checks a number right shift
 * @str: the number string whose print
 * @params: get the params struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int z = 0, ng, ng2, y = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	ng = ng2 = (!params->unsign && *str == '-');
	if (ng && x < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		ng = 0;
	if ((params->plus_flag && !ng2) ||
		(!params->plus_flag && params->space_flag && !ng2))
		y++;
	if (ng && pad_char == '0')
		z += _putchar('-');
	if (params->plus_flag && !ng2 && pad_char == '0' && !params->unsign)
		z += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !ng2 &&
		!params->unsign && params->zero_flag)
		z += _putchar(' ');
	while (y++ < params->width)
		z += _putchar(pad_char);
	if (ng && pad_char == ' ')
		z += _putchar('-');
	if (params->plus_flag && !ng2 && pad_char == ' ' && !params->unsign)
		z += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !ng2 &&
		!params->unsign && !params->zero_flag)
		z += _putchar(' ');
	z += _puts(str);
	return (z);
}

/**
 * print_number_left_shift - prints a numb left shift
 * @str: the numb string whose print
 * @params: get the params struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int x = 0, neg, neg2, y = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && x < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		x += _putchar('+'), y++;
	else if (params->space_flag && !neg2 && !params->unsign)
		x += _putchar(' '), y++;
	x += _puts(str);
	while (y++ < params->width)
		x += _putchar(pad_char);
	return (x);
}
