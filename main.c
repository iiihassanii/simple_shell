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
	ssize_t read;
	struct Node* head;

	(void)argc;
	(void)argv;

	head = NULL;
	while (1)
	{
		if (interactive_mode)
			printf("$ ");
		read = getline(&line, &n, stdin);
		head = add_node(NULL,line);
		if (read == -1)
		{
			/* Free allocated memory*/
			free(line);
			exit(0);
		}
		/* Remove comments and newlines*/
		rm_comment(line);
		new_line = malloc(_strlen(line) + 1);
		add_node(&head, new_line);
		new_line = line;
		rm_newline(new_line);

		if (line[0] != '\0')
			execute(new_line, head);
	}
	free(head);
	return (0);
}
