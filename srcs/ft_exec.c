/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:51:08 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/07 14:23:24 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_setup_redirection(t_pipex *pipex, int cmd_index)
{
	if (cmd_index == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		close(pipex->outfile);
		close(pipex->pipefd[0]);
	}
	else
	{
		dup2(pipex->pipefd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->infile);
		close(pipex->pipefd[1]);
	}
}

void	ft_exec(t_pipex *pipex, char **envp, int cmd_index)
{
	char	*test;
	int		i;

	i = -1;
	while (pipex->cmds_paths[++i])
	{
		test = ft_strjoin(pipex->cmds_paths[i], pipex->my_cmds[cmd_index][0]);
		if (access(test, X_OK) == 0)
		{
			ft_setup_redirection(pipex, cmd_index);
			execve(test, pipex->my_cmds[cmd_index], envp);
		}
		free(test);
	}
	ft_close(pipex);
	ft_printf("%s : ", pipex->my_cmds[cmd_index][0]);
	ft_cleanup(pipex, "command not found\n");
}

void	ft_absolute_exec(t_pipex *pipex, char **av, char *envp[], int cmd_index)
{
	if (cmd_index == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		close(pipex->outfile);
		close(pipex->pipefd[0]);
	}
	else
	{
		dup2(pipex->pipefd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->infile);
		close(pipex->pipefd[1]);
	}
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	if (execve(av[cmd_index + 2], pipex->my_cmds[cmd_index], envp) == -1)
	{
		dup2(pipex->save_outfilefd, STDOUT_FILENO);
		ft_printf("%s : ", pipex->my_cmds[cmd_index][0]);
		ft_cleanup(pipex, "command not found\n");
	}
}
