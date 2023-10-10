#include "main.h"

/**
 * main - the main shell code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *line;
	char *new_line;
	size_t n = 0;
	int interactive_mode = isatty(STDIN_FILENO);

	(void)argc;
	(void)argv;

	while (1)
	{
		if (interactive_mode)
		{
			/*printf */
			printf("$ ");
			/*get line int arg line */
			if (getline(&line, &n, stdin) == -1)
			{
				/* free up allocated memory */
				free(line);
				exit(0);
			}
			/* Remove nl and # */
			rm_comment(line);
			/* make fixed command without any comments*/
			new_line = malloc(_strlen(line) + 1);
			new_line = line;
			rm_newline(new_line);
			if (line[0] != '\0')
				execute(new_line);
		}
		else
			break;
	}
	return (0);
}
