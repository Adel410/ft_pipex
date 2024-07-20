/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:20:25 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/20 21:41:22 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:20:25 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/20 19:14:15 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_execute_cmd(t_pipex *pipex, char *envp[], int cmd_index, int *fd)
{
	int		i;
	char	*cmd;

	i = -1;
	while (pipex->cmds_paths[++i])
	{
		cmd = ft_strjoin(pipex->cmds_paths[i], pipex->my_cmds[cmd_index][0]);
		if (access(cmd, R_OK) == 0)
		{
			if (cmd_index == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			else
			{
				dup2(fd[0], STDIN_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			execve(cmd, pipex->my_cmds[cmd_index], envp);
		}
		free(cmd);
	}
}

void	ft_exec_pipex(t_pipex *pipex, char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		exit(1);
	pid1 = fork();
	if (pid1 < 0)
		exit(2);
	if (pid1 == 0)
		ft_execute_cmd(pipex, envp, 0, fd);
	pid2 = fork();
	if (pid2 < 0)
		exit(3);
	if (pid2 == 0)
		ft_execute_cmd(pipex, envp, 1, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
