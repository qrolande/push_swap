/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:43:24 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/10 22:59:07 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stacks(t_swap *start)
{
	t_list	*temp2;
	int		res;

	start->temp = start->b;
	while (start->temp->index != start->init.first_ind)
		start->temp = start->temp->next;
	temp2 = start->a;
	while (temp2->index != start->temp->nextindex)
		temp2 = temp2->next;
	if (temp2->flag == start->temp->flag)
	{
		if (temp2->steps > start->temp->steps)
			res = start->temp->steps;
		else
			res = temp2->steps;
		while (res--)
		{
			if (temp2->flag == 1)
				rr(start, 1);
			else
				rrr(start, 1);
		}
	}
}
