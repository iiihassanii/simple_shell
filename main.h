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

void gettoken(char *line);
void rm_comment(char *command1);
void rm_newline(char *line);
void execute(char **arr);
char *_getenv(char *name);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
void handle_path(char *command, char *path);
void interactive(void);

#endif
