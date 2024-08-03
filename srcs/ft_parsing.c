/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:37:24 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/02 17:34:53 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_fix(t_pipex *pipex, char **envp, char **argv)
{
	if (access(argv[2], X_OK) == 0 && access(argv[3], X_OK) == 0)
	{
		ft_flag3(pipex, envp, argv);
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

void	ft_alloc_mycmds(t_pipex *pipex, char **argv)
{
	pipex->my_cmds = malloc(sizeof(char **) * 3);
	pipex->my_cmds[0] = ft_split(argv[2], ' ');
	pipex->my_cmds[1] = ft_split(argv[3], ' ');
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

void	ft_parsing(char *argv[], char **envp, t_pipex *pipex)
{
	char	*path_to_cmds;

	path_to_cmds = NULL;
	ft_alloc_mycmds(pipex, argv);
	if (pipex->size_env == 0 || pipex->size_env == 30)
		ft_fix(pipex, envp, argv);
	else
	{
		while (envp[++pipex->i])
		{
			if (strncmp(envp[pipex->i], "PATH", 4) == 0)
			{
				path_to_cmds = ft_strdup(envp[pipex->i] + 5);
				if (!path_to_cmds)
					ft_cleanup(pipex);
				break ;
			}
		}
		if (path_to_cmds == NULL)
			ft_pipex(pipex, envp, argv);
		pipex->cmds_paths = ft_split(path_to_cmds, ':');
		ft_add_slash_to_paths(pipex->cmds_paths);
		free(path_to_cmds);
	}
}
