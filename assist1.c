#include "main.h"

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
 * pwd - Current working directory
 * Return: void
 */

void pwd(void)
{
	char path[256];

	if (getcwd(path, sizeof(path)) != NULL)
	{
		printf("%s\n", path);
	}
	else
	{
		perror("getcwd");
	}
}
