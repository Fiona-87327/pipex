/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-13 11:43:59 by jiyawang          #+#    #+#             */
/*   Updated: 2025-09-13 11:43:59 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (1);
	}
	pp_pipex(argv, envp);
	return (0);
}

void	pp_pipex(char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(pipe_fd) == -1)
		p_error();
	pid1 = fork();
	if (pid1 < 0)
		p_error();
	if (pid1 == 0)
		pp_child1(pipe_fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		p_error();
	if (pid2 == 0)
		pp_child2(pipe_fd, argv, envp);
	close(pipe_fd[READ_FD]);
	close(pipe_fd[WRITE_FD]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}

void	pp_child1(int *pipe_fd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		p_error();
	if (dup2(infile, STDIN_FILENO) == -1)
		p_error();
	if (dup2(pipe_fd[WRITE_FD], STDOUT_FILENO) == -1)
		p_error();
	close(infile);
	close(pipe_fd[READ_FD]);
	close(pipe_fd[WRITE_FD]);
	pip_exec_cmd(argv[2], envp);
}

void	pp_child2(int *pipe_fd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		p_error();
	if (dup2(outfile, STDOUT_FILENO) == -1)
		p_error();
	if (dup2(pipe_fd[READ_FD], STDIN_FILENO) == -1)
		p_error();
	close(outfile);
	close(pipe_fd[READ_FD]);
	close(pipe_fd[WRITE_FD]);
	pip_exec_cmd(argv[3], envp);
}
