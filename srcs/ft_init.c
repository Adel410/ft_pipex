/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/29 14:30:12 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/29 14:30:12 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_init(t_pipex *pipex)
{
	pipex->cmds_paths = NULL;
	pipex->my_cmds = NULL;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->pipefd[0] = -1;
	pipex->pipefd[1] = -1;
	pipex->save_outfilefd = dup(STDOUT_FILENO);
}

void	ft_alloc_mycmds(t_pipex *pipex, char **argv)
{
	pipex->my_cmds = malloc(sizeof(char **) * 3);
	if (!pipex->my_cmds)
		ft_cleanup(pipex, "");
	pipex->my_cmds[0] = ft_split(argv[2], ' ');
	pipex->my_cmds[1] = ft_split(argv[3], ' ');
	pipex->my_cmds[2] = NULL;
}
