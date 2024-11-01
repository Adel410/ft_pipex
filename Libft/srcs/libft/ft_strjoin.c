/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:33:14 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/06 19:22:10 by ahadj-ar         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		index;
	size_t		j;
	char		*ptr;

	j = 0;
	index = ft_strlen_stat(s1) + ft_strlen_stat(s2) + 1;
	ptr = (char *)malloc(index);
	index = 0;
	if (ptr == NULL)
		return (NULL);
	while (s1[index])
	{
		ptr[j] = s1[index];
		index++;
		j++;
	}
	index = 0;
	while (s2[index])
	{
		ptr[j] = s2[index];
		index++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
/*
int	main (void)
{
	printf("%s\n", ft_strjoin("one", " piece"));
}*/