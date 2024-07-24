/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:50:52 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/24 16:09:53 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_first_cmd(t_pipex *pipex, char *envp[])
{
	int		i;
	char	*cmd;

	i = -1;
	while (pipex->cmds_paths[++i])
	{
		cmd = ft_strjoin(pipex->cmds_paths[i], pipex->my_cmds[0][0]);
		if (access(cmd, X_OK) == 0)
		{
			dup2(pipex->infile, STDIN_FILENO);
			dup2(pipex->pipefd[1], STDOUT_FILENO);
			close(pipex->outfile);
			close(pipex->pipefd[0]);
			close(pipex->pipefd[1]);
			execve(cmd, pipex->my_cmds[0], envp);
		}
		free(cmd);
	}
}

void	ft_second_cmd(t_pipex *pipex, char *envp[])
{
	int		i;
	char	*cmd;

	i = -1;
	while (pipex->cmds_paths[++i])
	{
		cmd = ft_strjoin(pipex->cmds_paths[i], pipex->my_cmds[1][0]);
		if (access(cmd, X_OK) == 0)
		{
			dup2(pipex->pipefd[0], STDIN_FILENO);
			dup2(pipex->outfile, STDOUT_FILENO);
			close(pipex->infile);
			close(pipex->pipefd[1]);
			close(pipex->pipefd[0]);
			execve(cmd, pipex->my_cmds[1], envp);
		}
		free(cmd);
	}
}

void	ft_pipex(t_pipex *pipex, char *envp[], char *argv[])
{
	int	pid1;
	int	pid2;

	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->infile == -1 || pipex->outfile == -1)
		ft_cleanup(pipex);
	if (pipe(pipex->pipefd) == -1)
		ft_cleanup(pipex);
	pid1 = fork();
	if (pid1 < 0)
		ft_cleanup(pipex);
	if (pid1 == 0)
		ft_first_cmd(pipex, envp);
	pid2 = fork();
	if (pid2 < 0)
		ft_cleanup(pipex);
	if (pid2 == 0)
		ft_second_cmd(pipex, envp);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
