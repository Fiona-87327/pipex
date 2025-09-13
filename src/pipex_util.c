/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-13 14:13:25 by jiyawang          #+#    #+#             */
/*   Updated: 2025-09-13 14:13:25 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

char    *pip_get_path(char *cmd, char **envp)
{
    char	**paths;
    char	*full_path;
    int		i;

    i = 0;
    while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
        i++;
    if (!envp[i])
        return (NULL);
    paths = ft_split(envp[i] + 5, ':');
    if (!paths)
        p_error();
    i = 0;
    while (paths[i])
    {
        full_path = ft_strjoin(paths[i], "/");
        if (!full_path)
            p_error();
        full_path = ft_strjoin(full_path, cmd);
        if (!full_path)
            p_error();
        if (access(full_path, X_OK) == 0)
        {
            ft_free_split(paths);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    ft_free_split(paths);
    return (NULL);
}

void    pip_exec_cmd(char *cmd, char **envp)
{
    char	**args;
    char	*path;

    args = ft_split(cmd, ' ');
    if (!args)
        p_error();
    path = p_get_path(args[0], envp);
    if (!path)
    {
        ft_putstr_fd("Error: Command not found: ", 2);
        ft_putstr_fd(args[0], 2);
        ft_putstr_fd("\n", 2);
        ft_free_split(args);
        exit(EXIT_FAILURE);
    }
    if (execve(path, args, envp) == -1)
    {
        free(path);
        ft_free_split(args);
        p_error();
    }
}
