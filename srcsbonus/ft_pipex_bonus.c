/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/08/02 14:07:15 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/02 14:07:15 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_close_pipe(t_pipex *pipex, int *pipefd)
{
	close(pipex->infile);
	close(pipex->outfile);
	pipex->i = 0;
	while (pipex->i < (pipex->count_cmds - 1) * 2)
	{
		close(pipefd[pipex->i]);
		pipex->i++;
	}
	free(pipefd);
}

void	ft_setup_redirection(t_pipex *pipex, int cmd_index, int *pipefd)
{
	pipex->i = -1;
	if (cmd_index == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipex->outfile);
	}
	else if (cmd_index == pipex->count_cmds - 1)
	{
		dup2(pipefd[(cmd_index - 1) * 2], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->infile);
	}
	else
	{
		dup2(pipefd[(cmd_index - 1) * 2], STDIN_FILENO);
		dup2(pipefd[cmd_index * 2 + 1], STDOUT_FILENO);
		close(pipex->infile);
		close(pipex->outfile);
	}
	while (++pipex->i < (pipex->count_cmds - 1) * 2)
	{
		if (pipex->i != (cmd_index - 1) * 2 && pipex->i != cmd_index * 2 + 1)
			close(pipefd[pipex->i]);
	}
}

void	ft_execute_cmd(t_pipex *pipex, char **envp, int cmd_index, int *pipefd)
{
	char	*test;

	ft_setup_redirection(pipex, cmd_index, pipefd);
	if (access(pipex->my_cmds[cmd_index][0], X_OK) == 0)
		execve(pipex->my_cmds[cmd_index][0], pipex->my_cmds[cmd_index], envp);
	else if (access(pipex->my_cmds[cmd_index][0], X_OK) != 0
		&& (pipex->size_env == 30 || pipex->size_env == 0))
		ft_exit_absolute_failed(pipex, cmd_index, pipefd);
	else
	{
		pipex->i = -1;
		while (pipex->cmds_paths[++pipex->i])
		{
			test = ft_strjoin(pipex->cmds_paths[pipex->i],
					pipex->my_cmds[cmd_index][0]);
			if (access(test, X_OK) == 0)
				execve(test, pipex->my_cmds[cmd_index], envp);
			free(test);
		}
	}
	dup2(pipex->save_outfilefd, STDOUT_FILENO);
	ft_close_pipe(pipex, pipefd);
	ft_printf("%s : ", pipex->my_cmds[cmd_index][0]);
	ft_cleanup(pipex, "command not found\n");
}

void	ft_execute_cmds(t_pipex *pipex, char **envp)
{
	int	*pipefd;
	int	pid;

	pipefd = malloc((pipex->count_cmds - 1) * 2 * sizeof(int));
	if (!pipefd)
		ft_cleanup(pipex, "Malloc error at ft_execute_cmds()");
	pipex->i = -1;
	while (++pipex->i < pipex->count_cmds - 1)
	{
		if (pipe(pipefd + pipex->i * 2) == -1)
			ft_cleanup(pipex, "Pipe() failed\n");
	}
	pipex->i = -1;
	while (++pipex->i < pipex->count_cmds)
	{
		pid = fork();
		if (pid == -1)
			ft_cleanup(pipex, "Fork() failed\n");
		if (pid == 0)
			ft_execute_cmd(pipex, envp, pipex->i, pipefd);
	}
	ft_close_pipe(pipex, pipefd);
	while (wait(NULL) > 0)
	{
	}
}

void	ft_pipex(t_pipex *pipex, char **envp, char **av)
{
	if (pipex->here_doc == 0)
	{
		if (ft_check_all(pipex, av) != 0)
			ft_execute_cmds(pipex, envp);
	}
	else if (pipex->here_doc == 1)
	{
		if (ft_check_all_here_doc(pipex, av) != 0)
			ft_execute_cmds(pipex, envp);
	}
	else
		ft_cleanup(pipex, "Failed to execute command.\n");
}
