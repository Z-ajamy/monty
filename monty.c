#include"monty.h"

int main(int __attribute__((unused)) argv, char *argc[])
{
    unsigned int linenum = 1;
    ssize_t n;
    size_t i = 0;
    char *path, *line = NULL;
    command_l *command_ptr;

    FILE *fp;
    if (argv != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit (EXIT_FAILURE);
    }
    
    path = argc[1];
    fp = fopen(path, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file <file>\n");
        exit (EXIT_FAILURE);
    }
    
    while (1)
    {
        n = getline(&line, &i, fp);
        if (n == -1)
            break;
        
        command_ptr = parsing(line, linenum);
        if (!command_ptr)
            exit (EXIT_FAILURE);
        printf("%d %s %s\n",command_ptr->line_number, command_ptr->command, command_ptr->arg);
        linenum++;
    }
    
    free(line);
    free(command_ptr->command);
    free(command_ptr->arg);
    free(command_ptr);
    fclose(fp);
    return 0;
}
