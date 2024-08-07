/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:07:06 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/07 15:04:20 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int ac, char **av, char *envp[])
{
	t_pipex	pipex;

	pipex.size_env = 0;
	pipex.size_env = ft_strlen(envp[0]);
	pipex.arc = ac;
	if (ac < 5)
		ft_error(1);
	else
	{
		ft_init(&pipex, av);
		ft_fd(&pipex, av, ac);
		pipex.count_cmds = ac - 3 - pipex.here_doc;
		ft_alloc_mycmds(&pipex, av, ac);
		ft_parsing(av, envp, &pipex);
		ft_pipex(&pipex, envp, av);
		ft_cleanup(&pipex, "");
	}
}
