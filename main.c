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
	size_t n = 0;

	(void)argc;
	(void)argv;/* declaring void variables */

	while (1)
	{
		/*print prompt*/
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
		rm_newline(line);
		execute(line);
		/*char* argv[] = {line, NULL};*/
		/*execve(line,argv,NULL);*/
		
	}
	return (0);
}
