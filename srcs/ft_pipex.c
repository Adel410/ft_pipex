/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/29 15:45:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/29 15:45:37 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_close(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
}

void	ft_wait(int pid1, int pid2)
{
	wait(&pid1);
	wait(&pid2);
}

void	ft_execute_cmds(t_pipex *pipex, char **envp, char **av)
{
	int	pid1;
	int	pid2;

	if (pipe(pipex->pipefd) != 0)
		ft_cleanup(pipex, "pipe()");
	pid1 = fork();
	if (pid1 == 0)
	{
		if (pipex->size_env == 30 || pipex->size_env == 0 || access(av[2],
				X_OK) == 0)
			ft_absolute_exec(pipex, av, envp, 0);
		else
			ft_exec(pipex, envp, 0);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		if (pipex->size_env == 30 || pipex->size_env == 0 || access(av[3],
				X_OK) == 0)
			ft_absolute_exec(pipex, av, envp, 1);
		else
			ft_exec(pipex, envp, 1);
	}
	ft_close(pipex);
	ft_wait(pid1, pid2);
}

void	ft_pipex(t_pipex *pipex, char **envp, char **av)
{
	if (ft_check_all(pipex, av) == 0)
		ft_cleanup(pipex, "Failed to execute commands\n");
	else
		ft_execute_cmds(pipex, envp, av);
}
