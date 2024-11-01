/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:27:12 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/06 21:46:40 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_check_access(t_pipex *pipex, int index)
{
	char	*test;
	int		i;

	i = -1;
	while (pipex->cmds_paths[++i])
	{
		test = ft_strjoin(pipex->cmds_paths[i], pipex->my_cmds[index][0]);
		if (access(test, X_OK) == 0)
		{
			free(test);
			return (0);
		}
		free(test);
	}
	return (1);
}

int	ft_check_all(t_pipex *pipex, char **av)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 2;
	res = 0;
	while (i < 2)
	{
		if (ft_check_access(pipex, i) == 0 || access(av[j], X_OK) == 0)
		{
			res++;
		}
		i++;
		j++;
	}
	return (res);
}
