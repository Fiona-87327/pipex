/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 22:14:12 by jiyawang          #+#    #+#             */
/*   Updated: 2025/09/22 22:14:18 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define READ_FD 0
# define WRITE_FD 1

void	p_error(void);
void	ft_free_split(char **strs);
void	pip_exec_cmd(char *cmd, char **envp);
void	pp_pipex(char **argv, char **envp);
char	*pip_get_path(char *cmd, char **envp);
int		main(int argc, char **argv, char **envp);
void	pp_child(int *pipe_fd, char **argv, char **envp);
void	pp_parent(int *pipe_fd, char **argv, char **envp);

#endif