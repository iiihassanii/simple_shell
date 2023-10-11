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
 * @cp_line: copy of command line
 * Return: pointer to the tokens
 */


char **gettoken(char *line, char *cp_line, list_t *head)
{
	char **argv; /*arrey of pointer to tokens*/
	char *token;
	int tokens_counter = 0;
	unsigned int i;
	const char *delim = " ";

	/*make tokens and count it */
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
		add_node(&head,argv[i]);
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	/*last one is NULL why?execve need last one to be null*/
	return (argv);
}

/**
 * handle_path - find the correct bath
 * @command: the command
 * @path: all env path
 * Retuirn: void
 */

void handle_path(char *command, char *path, list_t *head)
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
		add_node(&head, full_path);

		_strcpy(full_path, token);
		full_path[token_len] = '/';
		_strcpy(full_path + token_len + 1, command);

		if (access(full_path, X_OK) == 0)
		{
			_strcpy(command, full_path);
			/*free(full_path);*/
			return;
		}

		/*free(full_path);*/
		token = strtok(NULL, delim);
	}
}


/**
 * execute - command ->
 * @line: the command
 * Return: void
 */

void execute(char *line, list_t *head)
{
	int status;
	char **argv;
	pid_t pid = fork();
	char *cp_line = malloc(strlen(line) + 1);
	add_node(&head, cp_line);

	_strcpy(cp_line, line);
	argv = gettoken(line, cp_line, head);

	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{

		if (_strchr(argv[0], '/') == NULL)
		{

			char *path = _getenv("PATH");
			handle_path(argv[0], path, head);
		}
		execve(argv[0], argv, NULL);
		free(cp_line);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
