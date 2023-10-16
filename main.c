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
	int status = 0;
	ssize_t read_line;

	if (argc == 2)
		read_file(argv[1]);
	else
		while (1)
		{
			if (interactive_mode)
				write(1, "$ ", 2);
			read_line = getline(&line, &n, stdin);
			if (read_line == -1 || is_empty(line))
			{
				/* Free allocated memory*/
				free(line);
				exit(status);
			}
			rm_comment(line);
			rm_newline(line);
			is_exit(line, status);
			if (is_env(line) != 1)
			{
				new_line = malloc(_strlen(line) + 1);
				_strcpy(new_line, line);
				if (is_empty(new_line))
				{
					free(line);
					free(new_line);
					exit(status);
				}
				status = gettoken(new_line);
			}
			free(new_line);
		}
	return (0);
}
