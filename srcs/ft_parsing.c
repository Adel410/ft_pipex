/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:37:24 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/20 19:16:33 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
				exit(1);
			ft_strcpy(new_path, paths[i]);
			new_path[len] = '/';
			new_path[len + 1] = '\0';
			free(paths[i]);
			paths[i] = new_path;
		}
		i++;
	}
}

void	ft_parsing(char *argv[], char **envp, t_pipex *pipex)
{
	int		i;
	char	*path_to_cmds;

	i = 0;
	path_to_cmds = NULL;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH", 4) == 0)
		{
			path_to_cmds = strdup(envp[i] + 5);
			if (!path_to_cmds)
				exit(1);
			break ;
		}
		i++;
	}
	pipex->cmds_paths = ft_split(path_to_cmds, ':');
	free(path_to_cmds);
	ft_add_slash_to_paths(pipex->cmds_paths);
	pipex->my_cmds = malloc(sizeof(char **) * 3);
	pipex->my_cmds[0] = ft_split(argv[2], ' ');
	pipex->my_cmds[1] = ft_split(argv[3], ' ');
}
