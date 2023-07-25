#include "main.h"

/**
 * print_hex - had fonction katbadel lina hxc
 * @ap: had argumment pointer
 * @params: had argament struct
 *
 * Return: maso9akch fya
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long g;
	int z = 0;
	char *str;

	if (params->l_modifier)
		g = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		g = (unsigned short int)va_arg(ap, unsigned int);
	else
		g = (unsigned int)va_arg(ap, unsigned int);

	str = convert(g, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && g)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (z += print_number(str, params));
}

/**
 * print_HEX - jilali yyyyyyyyyyyyyyy hhhhhhhh hhh
 * @ap: zzzzzzzzzz zzzzzz
 * @params: bbbbbbbbbbbbbbbb
 *
 * Return: maso9akch fya
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long g;
	int z = 0;
	char *str;

	if (params->l_modifier)
		g = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		g = (unsigned short int)va_arg(ap, unsigned int);
	else
		g = (unsigned int)va_arg(ap, unsigned int);

	str = convert(g, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && g)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (z += print_number(str, params));
}
/**
 * print_binary - BBBBBBBBBBBB BBBBBBB BBBB BBBBBB
 * @ap: ggdgdgdh hdhddh hdhdr
 * @params: mmm m mmmm mmmm sssst
 *
 * Return: maso9akch fya
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int b = va_arg(ap, unsigned int);
	char *str = convert(b, 2, CONVERT_UNSIGNED, params);
	int z = 0;

	if (params->hashtag_flag && b)
		*--str = '0';
	params->unsign = 1;
	return (z += print_number(str, params));
}

/**
 * print_octal - hdghdv dgdvhdhvd jhdvdh nvgdh
 * @ap: hjdhvdvdvhv hdjvdjvd
 * @params: ujdbjbjdjbjdb jjbdjct
 *
 * Return: maso9akch fya
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long g;
	char *str;
	int z = 0;

	if (params->l_modifier)
		g = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		g = (unsigned short int)va_arg(ap, unsigned int);
	else
		g = (unsigned int)va_arg(ap, unsigned int);
	str = convert(g, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && g)
		*--str = '0';
	params->unsign = 1;
	return (z += print_number(str, params));
}
