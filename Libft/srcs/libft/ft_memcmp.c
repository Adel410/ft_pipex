/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:27:06 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/19 15:36:49 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//TEST CHECK
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	i = 0;
	p1 = s1;
	p2 = s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return ((int)(p1[i]) - (int)(p2[i]));
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	txt[8] = "ABCDEFGH";
	char	txt1[8] = "abcdefgh";

	printf("%d\n", ft_memcmp(txt, txt1, 5));
	printf("%d\n", memcmp(txt, txt1, 8));
}*/