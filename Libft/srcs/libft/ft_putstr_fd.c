/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:32:31 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/21 16:54:30 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_stat(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen_stat((const char *)s);
	write(fd, &s[i], size);
}
/*
int	main(int argc, char *argv[])
{
	int	fd = open(argv[1], O_RDWR);
	if (argc > 0)
	{
		ft_putstr_fd("hello", fd);
	}
}*/