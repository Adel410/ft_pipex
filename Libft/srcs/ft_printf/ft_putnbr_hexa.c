/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:19:17 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/06/11 13:24:08 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putnbr_hexa(unsigned long long int n)
{
	unsigned long long int	nb;
	char					*base;
	int						count;

	base = "0123456789abcdef";
	count = 0;
	nb = n;
	if (nb >= 16)
		count += ft_putnbr_hexa(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_putnbr_hexa_maj(unsigned long long int n)
{
	unsigned long long int	nb;
	char					*base;
	int						count;

	base = "0123456789ABCDEF";
	count = 0;
	nb = n;
	if (nb >= 16)
		count += ft_putnbr_hexa_maj(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_putnbr_hexa((unsigned long long)ptr);
	return (count);
}
