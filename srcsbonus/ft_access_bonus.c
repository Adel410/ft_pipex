/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:27:12 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/07 15:11:55 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	ft_check_absolute_access(t_pipex *pipex)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 2;
	res = 0;
	while (i < pipex->count_cmds)
	{
		if (access(pipex->my_cmds[i][0], X_OK) == 0)
		{
			res++;
		}
		i++;
		j++;
	}
	return (res);
}

int	ft_check_absolute_access_here_doc(t_pipex *pipex)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 3;
	res = 0;
	while (i < pipex->count_cmds)
	{
		if (access(pipex->my_cmds[i][0], X_OK) == 0)
		{
			res++;
		}
		i++;
		j++;
	}
	return (res);
}

int	ft_check_access(t_pipex *pipex, int index)
{
	char	*test;
	int		i;

	i = -1;
	while (pipex->cmds_paths[++i])
	{
		test = ft_strjoin(pipex->cmds_paths[i], pipex->my_cmds[index][0]);
		if (!test)
		{
			ft_cleanup(pipex, "Malloc error(ft_check_access)\n");
		}
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
	while (i < pipex->count_cmds)
	{
		if (ft_check_access(pipex, i) == 0 || access(av[j], X_OK) == 0)
		{
			res++;
		}
		j++;
		i++;
	}
	return (res);
}

int	ft_check_all_here_doc(t_pipex *pipex, char **av)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 3;
	res = 0;
	while (i < pipex->count_cmds)
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
