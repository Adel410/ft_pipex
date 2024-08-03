/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:51:08 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/02 18:13:08 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exec1(t_pipex *pipex, char **envp)
{
	char	*test;

	pipex->i = 0;
	test = NULL;
	while (pipex->cmds_paths[pipex->i++])
	{
		test = ft_strjoin(pipex->cmds_paths[pipex->i], pipex->my_cmds[0][0]);
		if (access(test, X_OK) == 0)
		{
			dup2(pipex->infile, STDIN_FILENO);
			dup2(pipex->pipefd[1], STDOUT_FILENO);
			close(pipex->outfile);
			close(pipex->pipefd[0]);
			execve(test, pipex->my_cmds[0], envp);
		}
		free(test);
	}
	ft_cleanup(pipex);
}

void	ft_exec2(t_pipex *pipex, char **envp)
{
	char	*test;

	pipex->i = 0;
	test = NULL;
	while (pipex->cmds_paths[pipex->i++])
	{
		test = ft_strjoin(pipex->cmds_paths[pipex->i], pipex->my_cmds[1][0]);
		if (access(test, X_OK) == 0)
		{
			dup2(pipex->outfile, STDOUT_FILENO);
			dup2(pipex->pipefd[0], STDIN_FILENO);
			close(pipex->infile);
			close(pipex->pipefd[1]);
			execve(test, pipex->my_cmds[1], envp);
		}
		free(test);
	}
	ft_cleanup(pipex);
}

void	ft_absolute_exec1(t_pipex *pipex, char **av, char *envp[])
{
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->pipefd[1], STDOUT_FILENO);
	close(pipex->outfile);
	close(pipex->pipefd[0]);
	execve(av[2], pipex->my_cmds[0], envp);
}

void	ft_absolute_exec2(t_pipex *pipex, char **av, char *envp[])
{
	dup2(pipex->outfile, STDOUT_FILENO);
	dup2(pipex->pipefd[0], STDIN_FILENO);
	close(pipex->infile);
	close(pipex->pipefd[1]);
	execve(av[3], pipex->my_cmds[1], envp);
}
