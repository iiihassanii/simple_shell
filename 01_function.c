#include "main.h"

/**
 * rm_comment - remove #
 * @command: the line command
 * Return: void
 */

void rm_comment(char *command)
{

	int i = 0;

	if (command[i] == '#')
		(command[i]) = '\0';
	while (command[i] != '\0')
	{
		if (command[i] == '#' && command[i - 1] == ' ')
			break;
		i++;
	}
	command[i] = '\0';
}

/**
 * rm_newline - remove \n
 * @line: the command line
 * Return: void
 */
void rm_newline(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}

/**
 * execute - command ->
 * @line: the command
 * Return: void
 */

void execute(char *line)
{
	int status;
	char *args[2];
	pid_t pid = fork();

	args[0] = line;
	args[1] = NULL;

	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		/* Child process */
		execve(line, args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
