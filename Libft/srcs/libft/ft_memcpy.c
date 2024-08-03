/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:27:11 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/27 17:10:51 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
//TEST CHECK
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t						i;
	unsigned char				*dest_char;
	unsigned char				*src_char;

	if (!dest && !src)
	{
		return (NULL);
	}
	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[6] = "hello";
	char	txt[6] = "naruto";

	printf("%s\n", (char *)ft_memcpy(dest, txt, 6));
	printf("%s", (char *)memcpy(dest, txt, 6));
}*/