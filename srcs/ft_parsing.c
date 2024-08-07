/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:37:24 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/07 15:01:37 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_fix(t_pipex *pipex, char **envp, char **argv)
{
	int	pid1;
	int	pid2;

	if (access(argv[2], X_OK) == 0 || access(argv[3], X_OK) == 0)
	{
		if (pipe(pipex->pipefd) != 0)
			ft_cleanup(pipex, "pipe");
		pid1 = fork();
		if (pid1 < 0)
			ft_cleanup(pipex, "fork");
		if (pid1 == 0)
			ft_absolute_exec(pipex, argv, envp, 0);
		pid2 = fork();
		if (pid2 < 0)
			ft_cleanup(pipex, "fork");
		if (pid2 == 0)
			ft_absolute_exec(pipex, argv, envp, 1);
		ft_close(pipex);
		wait(&pid1);
		wait(&pid2);
		ft_cleanup(pipex, "");
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
	if (pipex->size_env == 0 || pipex->size_env == 30)
		ft_fix(pipex, envp, argv);
	else
	{
		while (envp[++i])
		{
			if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			{
				path_to_cmds = ft_strdup(envp[i] + 5);
				if (!path_to_cmds)
					ft_cleanup(pipex, "Env path not found.\n");
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
