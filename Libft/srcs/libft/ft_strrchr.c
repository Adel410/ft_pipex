/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:27:58 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/23 15:20:20 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//TEST CHECK
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

char	*ft_strrchr(const char *str, int searched)
{
	int	i;

	i = ft_strlen_stat(str);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)searched)
		{
			return ((char *)&str[i]);
		}
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_strrchr("one piecne", 'n'));
	printf("%s\n", strrchr("one piecne", 'n'));
}*/