/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 22:08:15 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/10 22:58:51 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_down(t_swap *start)
{
	while (start->temp->index != 0)
	{
		ra(start, 1);
		start->temp = start->a;
	}
}

void	final_sort(t_swap *start)
{
	int	len;
	int	res;

	len = 0;
	res = ft_lstsize(start->a);
	start->temp = start->a;
	while (start->temp->index != 0)
	{
		start->temp = start->temp->next;
		++len;
	}
	start->temp = start->a;
	while (len > res / 2 + res % 2)
	{
		while (start->temp->index != 0)
		{
			rra(start, 1);
			start->temp = start->a;
		}
		return ;
	}
	ft_down(start);
}
