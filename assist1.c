#include "main.h"

/**
 * _getenv - get env
 * @name: path name
 * Return: void
 */

char *_getenv(char *name)
{
	size_t name_length = _strlen(name);
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_length) == 0
				&& environ[i][name_length] == '=')
		{
			/* Return a pointer to the value part of the environment variable*/
			return (environ[i] + name_length + 1);
		}
	}

	return (NULL);
}

/**
 * _strlen - returns the length of a string.
 * @s: the string
 * Return: len
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

/**
 * _strcpy - copies the string pointed to by src
 *@dest : buffer pointed to
 * @src : string pointed
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');
	return (dest);
}

/**
 * _strchr - locates a character in a string.
 * @s:string
 * @c:first occurrence of the character
 * Return: c
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != c; i++)
	{
		if (s[i] == '\0')
			return (NULL);
	}
	return (s + i);
}


