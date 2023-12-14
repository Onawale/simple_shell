#include "shell.h"

/**
 **_strncpy - it copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int u, j;
	char *s = dest;

	u = 0;
	while (src[u] != '\0' && u < n - 1)
	{
		dest[u] = src[u];
		u++;
	}
	if (u < n)
	{
		j = u;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int u, j;
	char *s = dest;

	u = 0;
	j = 0;
	while (dest[u] != '\0')
		u++;
	while (src[j] != '\0' && j < n)
	{
		dest[u] = src[j];
		u++;
		j++;
	}
	if (j < n)
		dest[u] = '\0';
	return (s);
}

/**
 **_strchr - it locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
