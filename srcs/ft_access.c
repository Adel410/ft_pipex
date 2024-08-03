/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:27:12 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/02 17:37:54 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_check_access_1(t_pipex *pipex)
{
	char	*test;

	pipex->i = -1;
	test = NULL;
	while (pipex->cmds_paths[++pipex->i])
	{
		test = ft_strjoin(pipex->cmds_paths[pipex->i], pipex->my_cmds[0][0]);
		if (access(test, X_OK) == 0)
		{
			free(test);
			return (0);
		}
		free(test);
	}
	return (1);
}

int	ft_check_access_2(t_pipex *pipex)
{
	char	*test;

	pipex->i = -1;
	test = NULL;
	while (pipex->cmds_paths[++pipex->i])
	{
		test = ft_strjoin(pipex->cmds_paths[pipex->i], pipex->my_cmds[1][0]);
		if (access(test, X_OK) == 0)
		{
			free(test);
			return (0);
		}
		free(test);
	}
	return (1);
}
