/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:56:08 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/07 14:35:58 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_error(int i)
{
	if (i == 1)
	{
		ft_printf("Error: Wrong number of arguments.\n");
		exit(1);
	}
	else if (i == 2)
	{
		perror("Error opening input/output file.\n");
		exit(2);
	}
}

void	ft_exit_absolute_failed(t_pipex *pipex, int cmd_index, int *pipefd)
{
	dup2(pipex->save_outfilefd, STDOUT_FILENO);
	ft_close_pipe(pipex, pipefd);
	ft_printf("%s : ", pipex->my_cmds[cmd_index][0]);
	ft_cleanup(pipex, "command not found\n");
}

void	ft_cleanup(t_pipex *pipex, char *str)
{
	int	j;

	ft_printf(str);
	pipex->i = 0;
	if (pipex->my_cmds)
	{
		while (pipex->my_cmds[pipex->i])
		{
			j = 0;
			while (pipex->my_cmds[pipex->i][j])
			{
				free(pipex->my_cmds[pipex->i][j++]);
			}
			free(pipex->my_cmds[pipex->i++]);
		}
		free(pipex->my_cmds);
	}
	if (pipex->cmds_paths)
		ft_free_split(pipex->cmds_paths);
	close(pipex->save_outfilefd);
	exit(0);
}

char	*ft_free(char *str)
{
	if (str)
		free(str);
	return (NULL);
}
