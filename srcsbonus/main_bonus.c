/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:07:06 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/02 17:04:18 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_fd(t_pipex *pipex, char *av1, char *av4)
{
	pipex->infile = open(av1, O_RDONLY);
	pipex->outfile = open(av4, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex->infile == -1)
		ft_perror(av1);
	else if (pipex->outfile == -1)
		ft_perror(av4);
}

int	main(int ac, char **av, char *envp[])
{
	(void)av;
	t_pipex	pipex;
	pipex.size_env = 0;
	pipex.size_env = ft_strlen(envp[0]);
	pipex.count_cmds = ac - 3;
	printf("%d\n", pipex.count_cmds);
	// if (ac < 5)
	// 	ft_error(1);
	// else
	// {
	// 	ft_init(&pipex);
	// 	ft_fd(&pipex, av[1], av[4]);
	// 	ft_parsing(av, envp, &pipex);
	// 	ft_pipex(&pipex, envp, av);
	// 	ft_cleanup(&pipex);
	// }
}
