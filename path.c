#include "pipex.h"

static int starts_with_name_eq(const char *entry, const char *name)
{
    size_t i = 0;

    while (name[i] && entry[i] && entry[i] == name[i])
        i++;
    return (name[i] == '\0' && entry[i] == '=');
}

char *get_env_value(const char *name, char **envp)
{
    size_t i = 0;

    if (!name || !envp)
        return NULL;
    while (envp[i])
    {
        if (starts_with_name_eq(envp[i], name))
            return (envp[i] + ft_strlen(name) + 1);
        i++;
    }
    return NULL;
}

char *find_cmd_in_path(const char *cmd, char **envp)
{
    char    *path_env;
    char    **paths;
    char    *candidate;
    size_t  i;

    if (!cmd || !*cmd)
        return NULL;
    path_env = get_env_value("PATH", envp);
    if (!path_env)
        return NULL;
    paths = ft_split(path_env, ':');
    if (!paths)
        return NULL;
    for (i = 0; paths[i]; i++)
    {
        candidate = join_path(paths[i], cmd);
        if (!candidate)
            continue;
        if (access(candidate, X_OK) == 0)
        {
            free_strarray(paths);
            return candidate;
        }
        free(candidate);
    }
    free_strarray(paths);
    return NULL;
}