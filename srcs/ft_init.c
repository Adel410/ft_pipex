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
	pipex->i = 0;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->pipefd[0] = -1;
	pipex->pipefd[1] = -1;
}
