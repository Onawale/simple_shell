#include "shell.h"

/**
 *_eputs - It prints an input string
 * @str: the string that will printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int u = 0;

	if (!str)
		return;
	while (str[u] != '\0')
	{
		_eputchar(str[u]);
		u++;
	}
}

/**
 * _eputchar - It writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int u;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || u >= WRITE_BUF_SIZE)
	{
		write(2, buf, u);
		u = 0;
	}
	if (c != BUF_FLUSH)
		buf[u++] = c;
	return (1);
}

/**
 * _putfd - it writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int u;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || u >= WRITE_BUF_SIZE)
	{
		write(fd, buf, u);
		u = 0;
	}
	if (c != BUF_FLUSH)
		buf[u++] = c;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int u = 0;

	if (!str)
		return (0);
	while (*str)
	{
		u += _putfd(*str++, fd);
	}
	return (u);
}
