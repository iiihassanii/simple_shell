#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void rm_comment(char *command1);
void rm_newline(char *line);
void execute(char *line);

#endif
