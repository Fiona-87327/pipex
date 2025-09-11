#include "pipex.h"

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    if (!s) return 0;
    while (s[i]) i++;
    return i;
}

char *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *p = (char *)malloc(len + 1);
    size_t i;

    if (!p) return NULL;
    for (i = 0; i < len; i++)
        p[i] = s[i];
    p[len] = '\0';
    return p;
}

char *ft_strjoin(const char *a, const char *b)
{
    size_t la = ft_strlen(a), lb = ft_strlen(b);
    char *p = (char *)malloc(la + lb + 1);
    size_t i = 0, j = 0;

    if (!p) return NULL;
    while (i < la) { p[i] = a[i]; i++; }
    while (j < lb) { p[i + j] = b[j]; j++; }
    p[i + j] = '\0';
    return p;
}

char *join_path(const char *dir, const char *cmd)
{
    char *tmp;
    char *res;

    tmp = ft_strjoin(dir, "/");
    if (!tmp) return NULL;
    res = ft_strjoin(tmp, cmd);
    free(tmp);
    return res;
}

int has_slash(const char *s)
{
    size_t i = 0;
    if (!s) return 0;
    while (s[i])
    {
        if (s[i] == '/')
            return 1;
        i++;
    }
    return 0;
}

void putstr_fd(const char *s, int fd)
{
    if (s)
        write(fd, s, ft_strlen(s));
}