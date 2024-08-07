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

void	ft_init(t_pipex *pipex, char **av)
{
	pipex->cmds_paths = NULL;
	pipex->my_cmds = NULL;
	pipex->infile = -1;
	pipex->outfile = -1;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		pipex->here_doc = 1;
	else
		pipex->here_doc = 0;
}

void	ft_fd(t_pipex *pipex, char **av, int ac)
{
	pipex->save_outfilefd = dup(STDOUT_FILENO);
	if (pipex->here_doc == 0)
	{
		pipex->infile = open(av[1], O_RDONLY);
		if (pipex->infile == -1)
			ft_cleanup(pipex, "infile open() failed\n");
		pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (pipex->outfile == -1)
			ft_cleanup(pipex, "outfile open() failed\n");
	}
	if (pipex->here_doc == 1)
	{
		ft_heredoc(pipex, av);
		pipex->infile = open("here_doc", O_RDONLY);
		if (pipex->infile == -1)
			ft_cleanup(pipex, "infile open() failed\n");
		pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (pipex->outfile == -1)
			ft_cleanup(pipex, "outfile open() failed\n");
	}
}

void	ft_alloc_mycmds(t_pipex *pipex, char **argv, int argc)
{
	int	i;

	i = -1;
	if (pipex->here_doc == 0)
	{
		pipex->my_cmds = malloc(sizeof(char **) * (argc - 1));
		if (!pipex->my_cmds)
			ft_cleanup(pipex, "Malloc() failed in ft_alloc_mycmds()\n");
		while (++i < pipex->count_cmds)
		{
			pipex->my_cmds[i] = ft_split(argv[i + 2], ' ');
		}
		pipex->my_cmds[i] = NULL;
	}
	else if (pipex->here_doc == 1)
	{
		pipex->my_cmds = malloc(sizeof(char **) * (argc - 2));
		if (!pipex->my_cmds)
			ft_cleanup(pipex, "Malloc() failed in ft_alloc_mycmds()\n");
		while (++i < pipex->count_cmds)
		{
			pipex->my_cmds[i] = ft_split(argv[i + 3], ' ');
		}
		pipex->my_cmds[i] = NULL;
	}
}
