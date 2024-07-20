/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:27:32 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/23 18:36:02 by ahadj-ar         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter_src;
	size_t	len_dest;
	size_t	len_src;

	counter_src = 0;
	len_src = ft_strlen_stat(src);
	if (!size)
		return (len_src);
	len_dest = ft_strlen_stat(dst);
	if (size <= len_dest)
	{
		return (len_src + size);
	}
	while (src[counter_src] != '\0' && (len_dest + counter_src) < size - 1)
	{
		dst[len_dest + counter_src] = src[counter_src];
		counter_src++;
	}
	dst[len_dest + counter_src] = '\0';
	return (len_dest + len_src);
}
