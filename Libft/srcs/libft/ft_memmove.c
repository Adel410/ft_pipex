/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:27:15 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/12 11:26:33 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//TEST CHECK
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_char;
	const char	*src_char;

	i = 0;
	src_char = (const char *)src;
	dest_char = (char *)dest;
	if (dest_char < src_char)
	{
		while (i < n)
		{
			dest_char[i] = src_char[i];
			i++;
		}
	}
	else if (dest_char > src_char)
	{
		i = n;
		while (i > 0)
		{
			dest_char[i - 1] = src_char[i - 1];
			i--;
		}
	}
	return (dest);
}