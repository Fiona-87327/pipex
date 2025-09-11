#include "pipex.h"

static int wait_children(pid_t c1, pid_t c2)
{
    int status1 = 0;
    int status2 = 0;

    if (c1 > 0)
        waitpid(c1, &status1, 0);
    if (c2 > 0)
        waitpid(c2, &status2, 0);
    if (WIFEXITED(status2))
        return WEXITSTATUS(status2);
    if (WIFSIGNALED(status2))
        return 128 + WTERMSIG(status2);
    return 1;
}

static void usage(void)
{
    putstr_fd("Usage: ./pipex file1 \"cmd1 args\" \"cmd2 args\" file2\n", 2);
}

int main(int argc, char **argv, char **envp)
{
    int     pipefd[2];
    pid_t   c1, c2;

    if (argc != 5)
    {
        usage();
        return 1;
    }
    if (pipe(pipefd) == -1)
        fatal("pipe");

    c1 = fork();
    if (c1 < 0)
    {
        close(pipefd[0]); close(pipefd[1]);
        fatal("fork");
    }
    if (c1 == 0)
        exec_child1(argv, envp, pipefd);

    c2 = fork();
    if (c2 < 0)
    {
        /* Parent error: close and kill first child context */
        close(pipefd[0]); close(pipefd[1]);
        fatal("fork");
    }
    if (c2 == 0)
        exec_child2(argv, envp, pipefd);

    /* Parent: close both ends and wait */
    close(pipefd[0]);
    close(pipefd[1]);
    return wait_children(c1, c2);
}