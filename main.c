#include "main.h"

/**
 * main - the main shell code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 * Return: 0 on success
 */


int main(int argc, char **argv)
{
	char *line = NULL, *new_line = NULL;
	size_t n = 0;
	int interactive_mode = isatty(STDIN_FILENO);
	ssize_t read;

	(void)argc;
	(void)argv;

	while (1)
	{
		if (interactive_mode)
			printf("$ ");
		read = getline(&line, &n, stdin);
		if (read == -1 || is_empty(line))
		{
			/* Free allocated memory*/
			free(line);
			exit(0);
		}
		/* Remove comments and newlines*/
		rm_comment(line);
		rm_newline(line);
		is_exit(line);

		new_line = malloc(_strlen(line) + 1);
		_strcpy(new_line, line);
		gettoken(new_line);
		free(new_line);
	}
	return (0);
}
