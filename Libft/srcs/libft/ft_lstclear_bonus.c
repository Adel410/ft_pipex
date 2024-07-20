/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:22:18 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/23 14:47:19 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*get_next;

	ptr = *lst;
	if (!lst || !del || !ptr)
		return ;
	while (ptr->next != NULL)
	{
		get_next = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = get_next;
	}
	ft_lstdelone(ptr, del);
	*lst = NULL;
}
