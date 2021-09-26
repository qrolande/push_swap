/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 22:07:50 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/10 22:59:16 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*new;

	if (lst != 0)
	{
		while (*lst != 0)
		{
			new = (*lst)->next;
			ft_lstdelone(*lst);
			*lst = new;
		}
		*lst = NULL;
	}
}
