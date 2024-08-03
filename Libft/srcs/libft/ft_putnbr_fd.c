/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:54:17 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/21 16:39:40 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_stat(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_stat('-', fd);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
	else
		ft_putchar_stat((nb + '0'), fd);
}
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	int	fd = open(argv[1], O_RDWR);

	ft_putnbr_fd(9898544, fd);
}*/