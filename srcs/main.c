/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:40:00 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/20 19:03:08 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	struct s_pipex	pipex;

	(void)argv;
	if (argc != 5)
		ft_error(1);
	else
	{
		ft_parsing(argv, envp, &pipex);
		ft_exec_pipex(&pipex, envp);
		ft_free_split(pipex.my_cmds[0]);
		ft_free_split(pipex.my_cmds[1]);
		ft_free_split(pipex.cmds_paths);
	}
}
