#include "main.h"

/**
 * is_exit - handle exit cases
 * @line: the command line
 * @status: status to exit
 * Return: void
 */

void is_exit(char *line, int status)
{
	int state = 0, i = 5, sign = 1;

	if (_strncmp(line, "exit", 4) == 0)
	{
		if (status > 0)
		{
			free(line);
			exit(status);
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
 * is_env - check if command line is env
 * @line: command line
 * Return: 1 if is env
 */
int is_env(char *line)
{
	int i = 0;

	if (_strncmp(line, "env", 3) == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		return (1);
	}
	return (0);
}
