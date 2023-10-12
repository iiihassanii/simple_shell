#include "main.h"

/**
 * main - the main shell code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 * Return: 0 on success
 */


int main(int argc, char **argv)
{
	char *line = NULL;
	size_t n = 0;
	int interactive_mode = isatty(STDIN_FILENO);
	char *new_line;
	/*ssize_t read;*/

	(void)argc;
	(void)argv;

	while (1)
	{
		if (interactive_mode)
			printf("$ ");
		if (getline(&line, &n, stdin) != -1)
		{
			
			free(line);
			exit(0);
		}
		/* Remove comments and newlines*/
		rm_comment(line);
		new_line = malloc(_strlen(line) + 1);
		_strcpy(new_line, line);
		rm_newline(new_line);

		if (line[0] != '\0')
			execute(new_line);
	}
	free(line);
	free(new_line);
	return (0);
}
