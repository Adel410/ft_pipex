/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:56:08 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/02 17:03:08 by ahadj-ar         ###   ########.fr       */
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

void	ft_perror(char *str)
{
	ft_putstr(str);
	perror(" ");
	exit(0);
}

void	ft_cleanup(t_pipex *pipex)
{
	int	i;

	// if (pipex->my_cmds[0] != NULL)
	// 	ft_free_split(pipex->my_cmds[0]);
	// if (pipex->my_cmds[1] != NULL)
	// 	ft_free_split(pipex->my_cmds[1]);
	i = 0;
	if (pipex->my_cmds != NULL)
	{
		while (pipex->my_cmds[i])
		{
			ft_free_split(pipex->my_cmds[i]);
		}
		free(pipex->my_cmds);
	}
	if (pipex->cmds_paths != NULL)
		ft_free_split(pipex->cmds_paths);
	exit(1);
}
