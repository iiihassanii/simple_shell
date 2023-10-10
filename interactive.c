#include "main.h"


void interactive(void)
{
	char *line;
        char *new_line;
        size_t n = 0;

        while (1)
        {
       
                        /*printf */
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
                        /* make fixed command without any comments*/
                        new_line = malloc(_strlen(line) + 1);
                        new_line = line;
                        rm_newline(new_line);
                        if (line[0] != '\0')
                                execute(new_line);
                


        }
 
}
