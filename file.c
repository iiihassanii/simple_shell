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
	int status = 0;
	char ofile[] = "./hsh: 0: cannot open ";
	char ofile1[] = ": No such file\n";

	if (file == NULL)
	{
		write(STDERR_FILENO, ofile, _strlen(ofile));
		write(STDERR_FILENO, fname, _strlen(fname));
		write(STDERR_FILENO, ofile1, _strlen(ofile1));
		exit(2);
	}
	while ((getline(&line, &n, file)) != -1)
	{
		rm_comment(line);
		rm_newline(line);
		is_exit(line, status);
		/*is_env(line, status);*/

		new_line = malloc(_strlen(line) + 1);
		_strcpy(new_line, line);
		if (!is_empty(new_line))
		{
			status = gettoken(new_line);
		}
		free(new_line);
	}
	fclose(file);
	/*free(new_line);*/
	free(line);
}
