#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

extern char **environ;

/*01_functions */
void rm_comment(char *command);
void rm_newline(char *command);
int gettoken(char *line);
void handle_path(char *command, char *path);
int execute(char **arr);

/*02_functions */
char *_getenv(char *name);
int is_empty(const char *str);
int _isspace(char c);

/*assist functions*/
int _strncmp(const char *str1, const char *str2, size_t n);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);

/*builtin*/
void is_exit(char *line, int status);
int is_env(char *line);

/*file*/
void read_file(char *fname);

#endif
