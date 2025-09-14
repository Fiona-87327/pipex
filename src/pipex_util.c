/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:13:25 by jiyawang          #+#    #+#             */
/*   Updated: 2025/09/14 10:55:53 by jiyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	*try_cmd_direct(char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
	}
	return (NULL);
}

static char	*search_in_paths(char *cmd, char *path_env)
{
	char	**route;
	char	*path;
	char	*part_path;
	int		i;

	route = ft_split(path_env, ':');
	path = NULL;
	i = 0;
	while (route && route[i])
	{
		part_path = ft_strjoin(route[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	ft_free_split(route);
	return (path);
}

char	*pip_get_path(char *cmd, char **envp)
{
	char	*path;
	int		i;

	i = 0;
	path = try_cmd_direct(cmd);
	if (path)
		return (path);
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	if (!envp[i])
		return (NULL);
	return (search_in_paths(cmd, envp[i] + 5));
}

void	pip_exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args)
		p_error();
	path = pip_get_path(args[0], envp);
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
		exit(127);
	}
}
