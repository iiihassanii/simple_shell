#include "main.h"

/**
 * read_file - when the input is file
 * @fname: file name
 * Return: void
 */

void read_file(char *fname)
{
	char *line = NULL, *new_line = NULL;
	size_t n = 0;
	FILE *file = fopen(fname, "r");
	int status;

	if (file == NULL)
	{
		perror("./hsh");
		return;
	}
	while ((getline(&line, &n, file)) != -1)
	{
		rm_comment(line);
		rm_newline(line);
		is_exit(line, status);

		new_line = malloc(_strlen(line) + 1);
		_strcpy(new_line, line);
		status = gettoken(new_line);
	}
	fclose(file);
	free(new_line);
	free(line);
}

/**
 * is_exit - handle exit cases
 * @line: the command line
 * Return: void
 */

void is_exit(char *line, int status)
{
	int state = 0, i = 5, sign = 1;

	if (strncmp(line, "exit", 4) == 0)
	{
		if (status >= 0)
		{
			free (line);
			exit (status);
		}
		while (line[i] != '\0')
		{
			if (line[i] == '-')
				sign *= -1;
			else /*if (line[i] >= '0' && line[i] <= '9')*/
				state = state * 10 + line[i] - 48;
			i++;

		}
		free(line);
		if (sign < 0)
			perror("./hsh");
		exit(state * sign);
	}
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

/**
 * _isspace - check if char is space
 * @c: char
 * Return: 1 if c is space
 */

int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}
