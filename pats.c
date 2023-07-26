#include "main.h"

/**
 * _puts - checks a string gtgnhhy
 * @str: thy rjrhytgeyt
 *
 * Return: void
 */
int _puts(char *str)
{
	char *x = str;

	while (*str)
		_putchar(*str++);
	return (str - x);
}

/**
 * _putchar - wriuutjuyb jh(-jè-yj
 * @c: tyhjujhgytgr
 *
 *
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int y;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || y >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, y);
		y = 0;
	}
	if (c != BUF_FLUSH)
		buf[y++] = c;
	return (1);
}
