/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:46:08 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/22 14:14:49 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//TEST CHECK
static int	ft_strlen_stat(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	size_t		size_str;
	int			i;
	char		*ptr;

	i = 0;
	size_str = ft_strlen_stat(src);
	ptr = (char *)malloc((size_str + 1) * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int		main(void)
{
	char	txt[6] = "abcde";

	printf("%s\n", ft_strdup(txt));
	printf("%s", strdup(txt));
}*/