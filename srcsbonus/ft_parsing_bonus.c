/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:07:22 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/07 15:08:41 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_fix(t_pipex *pipex, char **envp)
{
	if (pipex->here_doc == 0)
	{
		if (ft_check_absolute_access(pipex) != 0)
		{
			ft_execute_cmds(pipex, envp);
			ft_cleanup(pipex, "");
		}
	}
	if (pipex->here_doc == 1)
	{
		if (ft_check_absolute_access_here_doc(pipex) != 0)
		{
			ft_execute_cmds(pipex, envp);
			ft_cleanup(pipex, "");
		}
	}
	else
		ft_cleanup(pipex, "Env path not found.\n");
}

void	ft_add_slash_to_paths(char **paths)
{
	int		i;
	char	*new_path;
	size_t	len;

	i = -1;
	while (paths[++i])
	{
		len = ft_strlen(paths[i]);
		if (paths[i][len - 1] != '/')
		{
			new_path = ft_calloc(len + 2, sizeof(char));
			if (!new_path)
				return ;
			ft_strlcpy(new_path, paths[i], len + 1);
			new_path[len] = '/';
			new_path[len + 1] = '\0';
			free(paths[i]);
			paths[i] = new_path;
		}
	}
}

void	ft_parsing(char *argv[], char **envp, t_pipex *pipex)
{
	char	*path_to_cmds;
	int		i;

	path_to_cmds = NULL;
	i = -1;
	if (pipex->size_env == 30 || pipex->size_env == 0)
		ft_fix(pipex, envp);
	else
	{
		while (envp[++i])
		{
			if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			{
				path_to_cmds = ft_strdup(envp[i] + 5);
				if (!path_to_cmds)
					ft_cleanup(pipex, "PATH in envp not found\n");
				break ;
			}
		}
		if (!path_to_cmds)
			ft_pipex(pipex, envp, argv);
		pipex->cmds_paths = ft_split(path_to_cmds, ':');
		ft_add_slash_to_paths(pipex->cmds_paths);
		free(path_to_cmds);
	}
}
