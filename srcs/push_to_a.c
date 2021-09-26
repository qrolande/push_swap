/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:43:52 by qrolande          #+#    #+#             */
/*   Updated: 2021/08/13 20:18:55 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_a(t_swap *start)
{
	int	next_index;

	next_index = start->temp->nextindex;
	start->temp = start->a;
	while (start->temp->index != next_index)
		start->temp = start->temp->next;
	if (start->temp->flag == 1)
	{
		while (start->a->index != next_index)
			ra(start, 1);
	}
	else
	{
		while (start->a->index != next_index)
			rra(start, 1);
	}
}
