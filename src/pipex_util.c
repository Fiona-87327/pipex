/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 22:13:45 by jiyawang          #+#    #+#             */
/*   Updated: 2025/09/22 22:13:51 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static char	*try_cmd_direct(char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
	}
	return (NULL);
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

static void	command_not_found_error(char **args, char *cmd_name)
{
	ft_putstr_fd("command not found: ", 2);
	if (cmd_name)
		ft_putstr_fd(cmd_name, 2);
	ft_putstr_fd("\n", 2);
	if (args)
		ft_free_split(args);
	exit(127);
}

void	pip_exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || !*cmd)
		command_not_found_error(NULL, "");
	args = ft_split(cmd, ' ');
	if (!args || !args[0] || !*args[0])
		command_not_found_error(args, "");
	path = pip_get_path(args[0], envp);
	if (!path)
		command_not_found_error(args, args[0]);
	if (execve(path, args, envp) == -1)
	{
		free(path);
		ft_free_split(args);
		p_error();
	}
}
