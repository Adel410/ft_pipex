/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:51:54 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/06/10 15:37:17 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_get_next_percent(va_list ap, char c)
{
	int				count;

	count = 0;
	if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x')
		count += ft_putnbr_hexa(va_arg(ap, unsigned int));
	else if (c == 'X')
		count += ft_putnbr_hexa_maj(va_arg(ap, unsigned int));
	else if (c == 'p')
		count += ft_print_ptr(va_arg(ap, void *));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_get_next_percent(ap, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
