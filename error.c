#include "pipex.h"

void fatal(const char *msg)
{
    perror(msg);
    _exit(1);
}

void print_cmd_not_found(const char *cmd)
{
    putstr_fd("pipex: command not found: ", 2);
    putstr_fd(cmd, 2);
    putstr_fd("\n", 2);
}