#include "main.h"

/**
 * my_strncmp - Compare two specified number of characters
 * @str1: first string
 * @str2: second string
 * @n: maximum number of characters to compare
 * Return: Negative if str1 < str2, positive if str1 > str2
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
    while (n > 0 && (*str1 || *str2))
    {
        if (*str1 != *str2)
            return (*str1 - *str2);

        str1++;
        str2++;
        n--;
    }

    return 0;
}


/**
 * _strcmp - function that compares two strings.
 *@s1: pointer for the number
 *@s2: idk
 * Return: s1
 */

int _strcmp(char *s1, char *s2)
{
	int eq;

	eq = 0;
	while (*s1)
	{
		if (*s1 != *s2)
		{
			eq = ((int)*s1 - 48) - ((int)*s2 - 48);
			break;
		}
		s1++;
		s2++;
	}
	return (eq);
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


