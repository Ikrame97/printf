#include "main.h"

/**
 * print_from_to - checker a characters of rang
 * @start: get start chars
 * @stop: get stop chars
 * @except: get except chars
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sm = 0;

	while (start <= stop)
	{
		if (start != except)
			sm += _putchar(*start);
		start++;
	}
	return (sm);
}

/**
 * print_rev - checks a string numbers in reverse
 * @ap: a string numbers
 * @params: get the params struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
	int ln, sm = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (ln = 0; *str; str++)
			ln++;
		str--;
		for (; ln > 0; ln--, str--)
			sm += _putchar(*str);
	}
	return (sm);
}

/**
 * print_rot13 - checks a string numbers in rot13
 * @ap: a string number
 * @params: get the params struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
	int i, ind;
	int cnt = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	ind = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			ind = a[i] - 65;
			count += _putchar(arr[ind]);
		}
		else
			cnt += _putchar(a[i]);
		i++;
	}
	return (cnt);
}
