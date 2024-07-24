/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:40:00 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/24 15:47:50 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	struct s_pipex	pipex;

	if (argc != 5)
		ft_error(1);
	else
	{
		pipex.infile = -1;
		pipex.outfile = -1;
		pipex.pipefd[0] = -1;
		pipex.pipefd[1] = -1;
		ft_parsing(argv, envp, &pipex);
		ft_pipex(&pipex, envp, argv);
		ft_cleanup(&pipex);
	}
}
