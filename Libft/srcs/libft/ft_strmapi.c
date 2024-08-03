/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:48:54 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/27 17:07:53 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (s == NULL || f == NULL)
		return (NULL);
	if (ptr == NULL)
		return (NULL);
	while (s[i])
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int	main(void)
{
	char	*str = "Hello, world!";
	char	*result = ft_strmapi(str, &test_function);

	if (result)
	{
		printf("Resultat de ft_strmapi : %s\n", result);
		free(result);
	}
	else
	{
		printf("Erreur : ft_strmapi a renvoyé NULL\n");
	}
}*/
