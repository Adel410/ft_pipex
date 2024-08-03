/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:50:08 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/21 15:53:34 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_stat(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen_stat(s);
	write(fd, &s[i], size);
	write(fd, "\n", 1);
}
/*
int	main(int argc, char *argv[])
{
	int	fd = open(argv[1], O_RDWR);
	if (argc > 0)
	{
		ft_putendl_fd("hello", fd);
	}
}*/