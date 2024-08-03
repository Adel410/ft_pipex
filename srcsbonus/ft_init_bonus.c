/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/08/02 14:07:27 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/02 14:07:27 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"


void	ft_init(t_pipex *pipex)
{
	pipex->cmds_paths = NULL;
	pipex->my_cmds = NULL;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->pipefd[0] = -1;
	pipex->pipefd[1] = -1;
}
