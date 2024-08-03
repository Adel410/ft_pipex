/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:27:22 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/20 15:30:54 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//TEST CHECK
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	src[5];
	int		c;
	size_t	n;

	c = 'a';
	n = 4;

	printf("%s\n", (char *)ft_memset(src, c, n));
	printf("%s", (char *)memset(src, c ,n));
}*/