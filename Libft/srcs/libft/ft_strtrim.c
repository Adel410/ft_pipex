/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:55:57 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/29 14:03:58 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

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

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ptr;
	int			start;
	int			end;
	int			i;

	start = 0;
	i = 0;
	while (s1[start] && ft_check_char(s1[start], (char *)set))
		start++;
	end = ft_strlen_stat(s1);
	while (end > start && ft_check_char(s1[end - 1], (char *)set))
		end--;
	ptr = (char *)malloc(end - start + 1);
	if (ptr == NULL)
		return (NULL);
	while (start < end)
	{
		ptr[i] = s1[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	printf("%s", ft_strtrim("baggyba", "ba"));
}*/