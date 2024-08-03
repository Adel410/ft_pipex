/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:50:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/29 12:23:19 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	size_t			i;
	unsigned char	*tab;

	total_size = nmemb * size;
	tab = malloc(total_size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
/*
int	main(void)
{
	printf("%p\n", ft_calloc(0, 0));
	printf("%p", calloc(0, 0));
}*/
