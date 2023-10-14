#include "main.h"



void is_exit(char *line)
{
	int state = 0, i = 5, sign = 1;
	if(strncmp(line, "exit", 4) == 0)
	{
		while (line[i] != '\0')
		{
			if (line[i] == '-')
				sign *= -1;
			else if (line[i] >= '0' && line[i] <= '9')
				state = state * 10 + line[i] - 48;
			i++;

		}
		free(line);
		exit (state * sign);
	}
	/*
	   if(_strcmp(line, "exit") == 0)
	   {
	   free(line);
	   exit (0);
	   }
	   */
}
/**
 * _getenv - get env
 * @name: path name
 * Return: void
 */

char *_getenv(char *name)
{
	size_t name_len = _strlen(name);
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0
				&& environ[i][name_len] == '=')
		{
			/* Return a pointer to the value part of the environment variable*/
			return (environ[i] + name_len + 1);
		}
	}

	return (NULL);
}

/**
 * is_empty - check if string is empty or space
 * @str: the string
 * Return: 1 if not empty
 */

int is_empty(const char *str)
{
	if (str == NULL)
		return (1);

	while (*str)
	{
		if (!_isspace(*str))
			return (0);
		str++;
	}

	return (1);
}

/*
 * _isspace - check if char is space
 * @c: char
 * Return: 1 if c is space
 */

int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}
