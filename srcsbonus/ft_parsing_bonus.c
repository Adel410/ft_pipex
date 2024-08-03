/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:07:22 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/02 17:03:21 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_fix(t_pipex *pipex)
{
	if (pipex->my_cmds[0][0][0] == '/' && pipex->my_cmds[1][0][0] == '/')
	{
		printf("ici\n");
		exit(1);
	}
	else
	{
		ft_printf("Env path not found.\n");
		ft_cleanup(pipex);
	}
}

void	ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_add_slash_to_paths(char **paths)
{
	int		i;
	char	*new_path;
	int		len;

	i = 0;
	while (paths[i])
	{
		len = strlen(paths[i]);
		if (paths[i][len - 1] != '/')
		{
			new_path = ft_calloc(len + 2, sizeof(char));
			if (!new_path)
				return ;
			ft_strcpy(new_path, paths[i]);
			new_path[len] = '/';
			new_path[len + 1] = '\0';
			free(paths[i]);
			paths[i] = new_path;
		}
		i++;
	}
}

void	ft_get_my_cmds(t_pipex *pipex, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	pipex->my_cmds = malloc(sizeof(char **) * pipex->count_cmds);
	if (!pipex->my_cmds)
	{
		ft_cleanup(pipex);
	}
	while (i < pipex->count_cmds)
	{
		pipex->my_cmds[i] = ft_split(av[j], ' ');
		{
			if (!pipex->my_cmds[i])
			{
				ft_cleanup(pipex);
			}
		}
		i++;
		j++;
	}
}

void	ft_parsing(char *argv[], char **envp, t_pipex *pipex)
{
	char	*path_to_cmds;
	// int		j;
	// int		k;

	pipex->i = 0;
	path_to_cmds = NULL;
	if (pipex->size_env == 0 || pipex->size_env == 30)
		ft_fix(pipex);
	while (envp[pipex->i])
	{
		if (strncmp(envp[pipex->i], "PATH", 4) == 0)
		{
			path_to_cmds = ft_strdup(envp[pipex->i] + 5);
			if (!path_to_cmds)
				exit(1);
			break ;
		}
		pipex->i++;
	}
	pipex->cmds_paths = ft_split(path_to_cmds, ':');
	ft_add_slash_to_paths(pipex->cmds_paths);
	free(path_to_cmds);
	ft_get_my_cmds(pipex, argv);
	if (!pipex->my_cmds)
		ft_cleanup(pipex);
	// j = 0;
	// k = 0;
	// while (pipex->my_cmds[j])
	// {
	// 	k = 0;
	// 	while (pipex->my_cmds[j][k])
	// 	{
	// 		printf("%s\n", pipex->my_cmds[j][k]);
	// 		k++;
	// 	}
	// 	j++;
	// }
}
