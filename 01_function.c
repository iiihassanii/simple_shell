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
 * gettoken - delimiter and stores the tokens
 * @line: command line
 * Return: pointer to the tokens
 */

void gettoken(char *line)
{
	char **argv = NULL, *token = NULL, *cp_line = NULL;
	int tokens_counter = 0;
	unsigned int i;
	const char *delim = " \t\n";

	/*make tokens and count it */
	cp_line = malloc(_strlen(line) + 1);
	_strcpy(cp_line, line);

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens_counter++;
		token = strtok(NULL, delim);
	}
	tokens_counter++;

	/*make array of pointer to tokens*/
	argv = malloc(sizeof(char *) * tokens_counter);
	token = strtok(cp_line, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token) + 1);
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	free(cp_line);
	argv[i] = NULL;

	execute(argv);
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	/*last one is NULL why?execve need last one to be null*/
}

/**
 * handle_path - find the correct bath
 * @command: the command
 * @path: all env path
 * Retuirn: void
 */

void handle_path(char *command, char *path)
{
	char *token;
	char *full_path = NULL;
	const char *delim = ":";
	size_t command_len;
	size_t token_len;

	token = strtok(path, delim);
	while (token != NULL)
	{
		token_len = _strlen(token);
		command_len = _strlen(command);
		full_path = malloc(token_len + command_len + 2);

		_strcpy(full_path, token);
		full_path[token_len] = '/';
		_strcpy(full_path + token_len + 1, command);

		if (access(full_path, X_OK) == 0)
		{
			_strcpy(command, full_path);
			free(full_path);
			return;
		}

		token = strtok(NULL, delim);
	}
	free(full_path);
}


/**
 * execute - command ->
 * @arr: array of spilt commands
 * Return: void
 */

void execute(char **arr)
{
	int status;
	char *path;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

		if (_strchr(arr[0], '/') == NULL)
		{

			path = _getenv("PATH");
			handle_path(arr[0], path);
		}
		execve(arr[0], arr, NULL);
		perror("execve");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
