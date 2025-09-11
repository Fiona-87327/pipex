#include "pipex.h"

static void exec_command(const char *cmd_str, char **envp)
{
    char    **args = NULL;
    char    *path = NULL;

    args = ft_split(cmd_str, ' ');
    if (!args || !args[0] || ft_strlen(args[0]) == 0)
    {
        putstr_fd("pipex: invalid command\n", 2);
        free_strarray(args);
        _exit(127);
    }
    if (has_slash(args[0]))
        path = ft_strdup(args[0]);
    else
        path = find_cmd_in_path(args[0], envp);

    if (!path)
    {
        print_cmd_not_found(args[0]);
        free_strarray(args);
        _exit(127);
    }
    execve(path, args, envp);
    /* execve failed */
    perror("pipex");
    free(path);
    free_strarray(args);
    _exit(126);
}

void exec_child1(char **argv, char **envp, int pipefd[2])
{
    int infile = open(argv[1], O_RDONLY);

    if (infile < 0)
    {
        perror(argv[1]);
        /* Still must close fds and exit; pipeline continues for child2 */
        close(pipefd[0]);
        close(pipefd[1]);
        _exit(1);
    }
    if (dup2(infile, STDIN_FILENO) == -1)
    {
        perror("dup2");
        close(infile);
        close(pipefd[0]); close(pipefd[1]);
        _exit(1);
    }
    if (dup2(pipefd[1], STDOUT_FILENO) == -1)
    {
        perror("dup2");
        close(infile);
        close(pipefd[0]); close(pipefd[1]);
        _exit(1);
    }
    close(infile);
    close(pipefd[0]); /* not used */
    close(pipefd[1]); /* now dup'ed */

    exec_command(argv[2], envp);
}

void exec_child2(char **argv, char **envp, int pipefd[2])
{
    int outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (outfile < 0)
    {
        perror(argv[4]);
        close(pipefd[0]); close(pipefd[1]);
        _exit(1);
    }
    if (dup2(pipefd[0], STDIN_FILENO) == -1)
    {
        perror("dup2");
        close(outfile);
        close(pipefd[0]); close(pipefd[1]);
        _exit(1);
    }
    if (dup2(outfile, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        close(outfile);
        close(pipefd[0]); close(pipefd[1]);
        _exit(1);
    }
    close(outfile);
    close(pipefd[0]); /* now dup'ed */
    close(pipefd[1]); /* not used */

    exec_command(argv[3], envp);
}