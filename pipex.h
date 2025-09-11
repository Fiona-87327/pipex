#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/* split.c */
char    **ft_split(const char *s, char delim);
void    free_strarray(char **arr);

/* utils.c */
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s);
char    *ft_strjoin(const char *a, const char *b);
char    *join_path(const char *dir, const char *cmd);
int     has_slash(const char *s);
void    putstr_fd(const char *s, int fd);

/* path.c */
char    *get_env_value(const char *name, char **envp);
char    *find_cmd_in_path(const char *cmd, char **envp);

/* exec.c */
void    exec_child1(char **argv, char **envp, int pipefd[2]);
void    exec_child2(char **argv, char **envp, int pipefd[2]);

/* error.c */
void    fatal(const char *msg);
void    print_cmd_not_found(const char *cmd);

#endif