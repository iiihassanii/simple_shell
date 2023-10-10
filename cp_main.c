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
	FILE *file;

	if (argc == 2)
		file = open(argv[1], O_RDONLY);
	if (file == NULL)
		exit(1);
	while (1)
	{

			/*printf */
			printf("$ ");

			if (getline(&line, &n, file) == -1)
                        {
                                /* free up allocated memory */
                                free(line);
                                exit(0);
                        }
			/*get line int arg line */
			/* Remove nl and # */
			rm_comment(line);
			/* make fixed command without any comments*/
			new_line = malloc(_strlen(line) + 1);
			new_line = line;
			rm_newline(new_line);
			if (line[0] != '\0')
				execute(new_line);
	}
	return (0);
}
