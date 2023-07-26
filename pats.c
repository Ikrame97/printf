#include "main.h"

/**
 * _puts - checks a string gtgnhhy
 * @str: thy rjrhytgeyt
 *
 * Return: thgnn
 */
int _puts(char *str)
{
	char *z = str;

	while (*str)
		_putchar(*str++);
	return (str - z);
}

/**
 * _putchar - wriuutjuyb jh(-jè-yj
 * @c: tyhjujhgytgr
 *
 *
 *
 * Return: On success print 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int x;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || x >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}
