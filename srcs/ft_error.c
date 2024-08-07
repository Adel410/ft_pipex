/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:56:08 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/07 14:24:08 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
		ft_printf("Error: Wrong number of arguments.\n");
	else if (i == 2)
		perror("Error opening input/output file.\n");
	exit(i);
}

void	ft_cleanup(t_pipex *pipex, char *str)
{
	ft_printf(str);
	if (pipex->my_cmds)
	{
		ft_free_split(pipex->my_cmds[0]);
		ft_free_split(pipex->my_cmds[1]);
		free(pipex->my_cmds);
	}
	if (pipex->cmds_paths)
		ft_free_split(pipex->cmds_paths);
	close(pipex->outfile);
	close(pipex->infile);
	close(pipex->save_outfilefd);
	exit(1);
}
