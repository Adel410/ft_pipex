/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:25:05 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/23 14:53:11 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//TEST CHECK
int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	printf("%d\n", ft_atoi("\t\v\f\r\n \f-06050"));
	printf("%d\n", atoi ("\t\v\f\r\n \f-06050"));
}*/
