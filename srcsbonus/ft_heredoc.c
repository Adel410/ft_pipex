/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:29:07 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/06 21:17:24 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_heredoc(t_pipex *pipex, char **av)
{
	char	*line;
	int		fd;

	fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		ft_cleanup(pipex, "");
	while (1)
	{
		ft_printf("here_doc> ");
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0
			&& line[ft_strlen(av[2])] == '\n')
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
}
