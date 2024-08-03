/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:26:59 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/29 11:56:09 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t						i;
	const unsigned char			*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *)&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const void	*ptr;
	printf("%s\n", (char *)ft_memchr(ptr, 458, 35));
	printf("%s", (char *)memchr(ptr, 458, 35));
}*/