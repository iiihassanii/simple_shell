#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

char **gettoken(char *line, char *cp_line, list_t *head);
list_t *add_node(list_t **head, char *str);
void free_list(list_t *head);
void rm_comment(char *command1);
void rm_newline(char *line);
void execute(char *line, list_t *head);
char *_getenv(char *name);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
void handle_path(char *command, char *path, list_t *head);
void interactive(void);

#endif
