/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:01:43 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/12 11:25:23 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	go;
	unsigned int	size;
	char			*ptr;

	go = 0;
	size = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= size)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (ptr);
	i = (int)start;
	while (s[i] && go < len)
	{
		ptr[go] = s[i];
		i++;
		go++;
	}
	ptr[go] = '\0';
	return (ptr);
}
