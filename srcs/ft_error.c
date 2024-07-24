/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:56:08 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/24 15:08:07 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

void	ft_cleanup(t_pipex *pipex)
{
	ft_free_split(pipex->my_cmds[0]);
	ft_free_split(pipex->my_cmds[1]);
	free(pipex->my_cmds);
	ft_free_split(pipex->cmds_paths);
	exit(1);
}
